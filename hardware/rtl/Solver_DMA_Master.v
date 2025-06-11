
`timescale 1 ns / 1 ps

	module Solver_DMA_Master #
	(
		// Users to add parameters here
        parameter  DATA_WIDTH                = 16,
        parameter  DEPTH                     = 2500,
        parameter  ADDRESS_WIDTH             = 12,
		// User parameters ends
		// Do not modify the parameters beyond this line


		// Parameters of Axi Master Bus Interface M00_AXIS
		parameter integer C_M00_AXIS_TDATA_WIDTH	= 32,
		parameter integer C_M00_AXIS_START_COUNT	= 32
	)
	(
		// Users to add ports here
        input wire [DATA_WIDTH-1:0] u_x,
        input wire [DATA_WIDTH-1:0] u_y,
        input wire [DATA_WIDTH-1:0] rho, 
        input wire [DATA_WIDTH-1:0] u_squared,
        input wire                  in_collision_state,
        input wire                  collider_ready,
		// User ports ends
		// Do not modify the ports beyond this line


		// Ports of Axi Master Bus Interface M00_AXIS
		input wire  m00_axis_aclk,
		input wire  m00_axis_aresetn,
		output wire  m00_axis_tvalid,
		output wire [C_M00_AXIS_TDATA_WIDTH-1 : 0] m00_axis_tdata,
		output wire [(C_M00_AXIS_TDATA_WIDTH/8)-1 : 0] m00_axis_tstrb,
		output wire  m00_axis_tlast,
		input wire  m00_axis_tready
	);

	// Add user logic here
    reg [DATA_WIDTH-1:0] uxs [DEPTH-1:0];
    reg [DATA_WIDTH-1:0] uys [DEPTH-1:0];
    reg [DATA_WIDTH-1:0] rhos [DEPTH-1:0];
    reg [DATA_WIDTH-1:0] u2s [DEPTH-1:0];
    reg [ADDRESS_WIDTH-1:0] read_count;

    localparam FILL_DATA    = 2'd0;
    localparam WAIT_READY   = 2'd1;
    localparam SEND         = 2'd2;
    
    reg [1:0] current_state,next_state;
    reg [ADDRESS_WIDTH-1 + 1: 0] write_count; // extra bit bc times 2
    reg     tvalid, next_tvalid, tlast;
    reg     write_incr;
    reg [31:0] sender_out, dout;
    reg init_write_count;


    assign m00_axis_tvalid = tvalid;
    assign m00_axis_tdata  = dout;
    assign m00_axis_tlast = tlast;
    assign m00_axis_tstrb = 4'hF;


    always @(posedge m00_axis_aclk or negedge m00_axis_aresetn or posedge m00_axis_tready) begin
        if(!m00_axis_aresetn) begin
            current_state <= FILL_DATA;
            read_count <= 0;
            write_count <= 0;
        end
        else begin
            current_state <= next_state;

            if(current_state == FILL_DATA) begin
                if(in_collision_state && collider_ready) begin
                    uxs[read_count] <= u_x;
                    uys[read_count] <= u_y;
                    rhos[read_count] <= rho;
                    u2s[read_count] <= u_squared;
                    read_count <= read_count + 1;
                end
                else if(in_collision_state) begin
                    read_count <= read_count;
                end
                else begin 
                    read_count <= 0;
                end
            end

            if(current_state == SEND) begin
                // if(write_count <= DEPTH*2 && init_write_count) begin
                //     sender_out <= {uxs[0],uys[0]};
                //     write_count <= 2;
                // end
                if(write_count <= DEPTH*2) begin
                    sender_out <= (write_count[0]) ? {uxs[(write_count-1)/2],uys[(write_count-1)/2]} : {rhos[write_count/2],u2s[write_count/2]};
                    write_count <= write_count + 1;
                end
                else begin
                    write_count <= 0;
                end
            end

            if(current_state == WAIT_READY && in_collision_state && !m00_axis_tready) begin // preempt next transition
                uxs[read_count] <= u_x;
                uys[read_count] <= u_y;
                rhos[read_count] <= rho;
                u2s[read_count] <= u_squared;
                read_count <= read_count + 1;
            end
            
            if(current_state == WAIT_READY && m00_axis_tready) begin // preempt another transition
                write_count <= 2;
                sender_out <= {uxs[0],uys[0]};
            end
        end

    end
    // next state
    always @* begin
        case (current_state)
           FILL_DATA : begin
                if(!in_collision_state) 
                    next_state = WAIT_READY;                
                else 
                    next_state = FILL_DATA;
           end 

            WAIT_READY : begin
                if(in_collision_state && !m00_axis_tready)
                    next_state = FILL_DATA;
                else if(m00_axis_tready)
                    next_state = SEND;
                else 
                    next_state = WAIT_READY;
            end

            SEND : begin
                if(write_count == DEPTH*2) 
                    next_state = FILL_DATA;
                else
                    next_state = SEND;
            end

            default: 
                next_state = FILL_DATA;
        endcase
    end

    // output logic
    always @* begin
        dout = sender_out;
        tvalid = 0;
        tlast = 0;
        init_write_count = 0;
        if(current_state == WAIT_READY ||(current_state == FILL_DATA && !in_collision_state)) begin
            tvalid = 1;
            init_write_count = 1;
            dout = {rhos[0],u2s[0]}; // for correct timing
        end

        if(current_state == SEND && write_count == DEPTH*2)
            tlast = 1;

        if(current_state == WAIT_READY && in_collision_state)
            tvalid = 0;

        if(current_state == WAIT_READY && m00_axis_tready) begin
            init_write_count = 1;
            dout = {rhos[0],u2s[0]}; // for correct timing
        end

    end
	// User logic ends

	endmodule
