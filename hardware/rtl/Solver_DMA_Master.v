
`timescale 1 ns / 1 ps

	module Solver_DMA_Master #
	(
		// Users to add parameters here
        parameter  DATA_WIDTH                = 16,
        parameter  DEPTH                     = 2500,
        parameter  NUM_CHUNKS                = (DEPTH-1)/N_PARALLEL_SOLVERS + 1,
        parameter  ADDRESS_WIDTH             = 12,
        parameter  N_PARALLEL_SOLVERS        = 8,
        parameter  N_SEND_BITS               = 2, //log2 N_PARALLEL_SOLVERS
        parameter integer RAM_DATA_WIDTH	= N_PARALLEL_SOLVERS * 4 * DATA_WIDTH,
		// User parameters ends
		// Do not modify the parameters beyond this line


		// Parameters of Axi Master Bus Interface M00_AXIS
		// parameter integer C_M00_AXIS_TDATA_WIDTH	= 64,
        parameter integer C_M00_AXIS_TDATA_WIDTH	= 64,
		parameter integer C_M00_AXIS_START_COUNT	= 32
	)
	(
		// Users to add ports here
        input wire [(N_PARALLEL_SOLVERS * DATA_WIDTH)-1:0] u_x,
        input wire [(N_PARALLEL_SOLVERS * DATA_WIDTH)-1:0] u_y,
        input wire [(N_PARALLEL_SOLVERS * DATA_WIDTH)-1:0] rho, 
        input wire [(N_PARALLEL_SOLVERS * DATA_WIDTH)-1:0] u_squared,
        input wire                  in_collision_state,
        input wire                  collider_ready,
        input wire [RAM_DATA_WIDTH-1:0]     ram_dout,
        output reg [RAM_DATA_WIDTH-1:0]     ram_din,
        output reg                                  ram_wen,
        output reg [ADDRESS_WIDTH-1:0]              ram_addr, // because 2 times
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
    // RAM format: rho u2 ux uy from MSB to LSB
    reg [ADDRESS_WIDTH-1:0] read_count;

    reg transfer_in_progress;
    reg transfer_complete;

    localparam FILL_DATA    = 2'd0;
    localparam WAIT_READY   = 2'd1;

    reg [ADDRESS_WIDTH-1:0] send_count; 
    
    reg [1:0] current_state,next_state;
    reg [ADDRESS_WIDTH-1 + 1: 0] write_count; // extra bit bc times 2
    reg     tvalid, tlast;
    reg [C_M00_AXIS_TDATA_WIDTH-1:0] dout;

    assign m00_axis_tvalid = tvalid;
    assign m00_axis_tdata  = dout;
    assign m00_axis_tlast = tlast;
    assign m00_axis_tstrb = 8'hFF;

    //ASSUMES NEW COLLIDER VALUE EVERY CYC. NOT THE CASE..

    always @(posedge m00_axis_aclk or negedge m00_axis_aresetn) begin
        if(!m00_axis_aresetn) begin
            current_state <= FILL_DATA;
            read_count <= 0;
            write_count <= 0;
            send_count <= 0;
        end
        else begin
            current_state <= next_state;

            if(current_state == FILL_DATA) begin
                transfer_in_progress <= 0;
                
                if(in_collision_state) begin
                    read_count <= read_count;
                    transfer_complete <= 0;
                    // ram_wen <= 0;
                end
                else begin 
                    read_count <= 0;
                    // ram_wen <= 0;
                end
            end

            if(current_state == WAIT_READY) begin
                if(write_count <= NUM_CHUNKS && m00_axis_tready) begin
                    send_count <= send_count + 1;
                    if(send_count == N_PARALLEL_SOLVERS-1) begin
                        write_count <= write_count + 1;
                        send_count <= 0;
                    end
                    transfer_in_progress <= 1;
                end
                else if(write_count <= NUM_CHUNKS && !m00_axis_tready) begin
                    write_count <= write_count;
                    send_count <= send_count;

                end
                else if(!m00_axis_tready && in_collision_state && !transfer_in_progress) begin
                    read_count <= 1;
                    write_count <= 0;
                    send_count <= 0;

                end
                else begin // reached end
                    write_count <= 0;
                    send_count <= 0;
                    transfer_in_progress <= 0;
                    transfer_complete <= 1;
                end
            end

            if(in_collision_state && collider_ready) begin
                read_count <= read_count + 1; // increment once all parallel blocks have been sent 
                
            end 

        end

    end
    // next state
    // try set tvalid low after transfer over
    always @* begin
        case (current_state)
           FILL_DATA : begin
                if(!in_collision_state && !transfer_complete) 
                    next_state = WAIT_READY;                
                else 
                    next_state = FILL_DATA;
           end 

            WAIT_READY : begin
                if(write_count == NUM_CHUNKS + 1 || (in_collision_state && !m00_axis_tready && !transfer_in_progress)) begin
                // allow transition back if a transmission hasn't been started 
                    next_state = FILL_DATA;
                end
                else
                    next_state = WAIT_READY;
            end
            default : 
                next_state = FILL_DATA;
        endcase
    end

    integer i;
    // output logic
    always @* begin
        // dout = ram_dout;
        dout = ram_dout[(4*DATA_WIDTH)*send_count +: 4*(DATA_WIDTH)];

        tvalid = 0;
        tlast = 0;
        ram_wen = 0;
        ram_addr = 0;
        ram_din = 0;
        if(current_state == FILL_DATA && !in_collision_state) begin
            tvalid = 0; // not ready until we transistion and the RAM data comes out
            ram_addr = read_count;
            ram_wen = 0;
        end
        if(current_state == FILL_DATA && in_collision_state && collider_ready) begin
            // ram_din = {rho,u_squared,u_x,u_y};
            for (i = 0; i < N_PARALLEL_SOLVERS; i = i + 1) begin
                ram_din[ (i*4+0)*DATA_WIDTH +: DATA_WIDTH ] = u_y[ (i*DATA_WIDTH) +: DATA_WIDTH ];
                ram_din[ (i*4+1)*DATA_WIDTH +: DATA_WIDTH ] = u_x[ (i*DATA_WIDTH) +: DATA_WIDTH ];
                ram_din[ (i*4+2)*DATA_WIDTH +: DATA_WIDTH ] = u_squared[ (i*DATA_WIDTH) +: DATA_WIDTH ];
                ram_din[ (i*4+3)*DATA_WIDTH +: DATA_WIDTH ] = rho[ (i*DATA_WIDTH) +: DATA_WIDTH ];
            end
            ram_addr = read_count;
            ram_wen = 1;
        end

        if(current_state == WAIT_READY) begin // by now the value will be available from RAM
            tvalid = transfer_complete ? 0 : 1;
            ram_addr = write_count;
        end

        if(current_state == WAIT_READY && m00_axis_tready && !in_collision_state) begin
            ram_addr = write_count;
            ram_wen = 0;
        end

        if(current_state == WAIT_READY && (write_count==0 && in_collision_state)) begin
            tvalid = 0;
            ram_wen = 1;
            ram_addr = 0;
            // ram_din = {rho,u_squared,u_x,u_y};
            for (i = 0; i < N_PARALLEL_SOLVERS; i = i + 1) begin
                ram_din[ (i*4+0)*DATA_WIDTH +: DATA_WIDTH ] = u_y[ (i*DATA_WIDTH) +: DATA_WIDTH ];
                ram_din[ (i*4+1)*DATA_WIDTH +: DATA_WIDTH ] = u_x[ (i*DATA_WIDTH) +: DATA_WIDTH ];
                ram_din[ (i*4+2)*DATA_WIDTH +: DATA_WIDTH ] = u_squared[ (i*DATA_WIDTH) +: DATA_WIDTH ];
                ram_din[ (i*4+3)*DATA_WIDTH +: DATA_WIDTH ] = rho[ (i*DATA_WIDTH) +: DATA_WIDTH ];
            end
        end

        if(current_state == WAIT_READY && write_count == NUM_CHUNKS+1)
            tlast = 1;
        

    end
	// User logic ends

	endmodule
