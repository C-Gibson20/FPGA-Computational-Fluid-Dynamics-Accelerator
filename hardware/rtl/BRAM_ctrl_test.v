// once fill data is high keep reading zero
// then when m00_axis_tready is high send the zero data bit
// begin read request cycle

`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: me
// Engineer: me
// 
// Create Date: 27.05.2025 16:26:15
// Design Name: 
// Module Name: BRAM_addr_gen
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module BRAM_ctrl#(
    parameter  DATA_WIDTH                = 16,
    parameter  DEPTH                     = 2500,
    parameter  ADDRESS_WIDTH             = 12
    //parameter  C_m00_axis_tdata_WIDTH    = 144
)(
    input wire frame_ready,
    //take data of all 9 directions for each pixel at a time
    input wire [15:0] n1,
    input wire [15:0] null1,
    input wire [15:0] ne1,
    input wire [15:0] e1,
    input wire [15:0] se1,
    input wire [15:0] s1,
    input wire [15:0] sw1,
    input wire [15:0] w1,
    input wire [15:0] nw1,
    
    output reg [11:0] read_addr,

    // Ports of Axi Master Bus Interface M00_AXIS
    input wire  m00_axis_aclk,
    input wire  m00_axis_aresetn,
    input wire  m00_axis_tready,
    output reg  m00_axis_tvalid,
    output wire [144-1 : 0] m00_axis_tdata,
    output wire [(144/8)-1 : 0] m00_axis_tstrb,
    output reg  m00_axis_tlast,
    
);
    
    //iterate through all 2500 pixels
    reg [143:0] output_data;
    reg [1:0] current_state, next_state;

    //states
    localparam FILL_DATA    = 2'd0;
    localparam IDLE         = 2'd1;
    localparam SEND         = 2'd2;
    localparam READ_WAIT    = 2'd3;

    assign m00_axis_tstrb = {18{1'b1}};

    always @(posedge m00_axis_aclk or negedge m00_axis_aresetn) begin
        if (!m00_axis_aresetn) begin
            current_state <= IDLE;
        end
        else begin
            current_state <= next_state;
        end

    end
////////////////////////////////////////////////////////////////////////////

    //set flags etc here
    always @* begin
        m00_axis_tvalid = 1'b0;
        m00_axis_tlast = 1'b0;
    
        if (current_state == SEND) begin
            m00_axis_tvalid = 1'b1;
            if (read_addr == DEPTH - 1) m00_axis_tlast = 1'b1;
        end
    end

//////////////////////////////////////////////////////////////////////////////

    //states
    always @* begin
        next_state = current_state;

        case(current_state)
            IDLE: if (frame_ready) next_state = READ_WAIT;

            READ_WAIT: next_state = FILL_DATA;

            FILL_DATA: next_state = SEND;
            
            SEND: begin
                if(m00_axis_tready) begin
                    if (read_addr == DEPTH-1) next_state = IDLE;
                    else next_state = READ_WAIT;
                end
            end
        endcase
    end

/////////////////////////////////////////////////////////////////

    // state logic
    always @(posedge m00_axis_aclk or negedge m00_axis_aresetn) begin
        if (!m00_axis_aresetn) begin
            read_addr    <= 0;
            output_data  <= 0;
        end 
        else begin 
            case(current_state)
                IDLE: if (frame_ready) ready_addr <= 0;

                READ_WAIT: ;

                FILL_DATA: output_data <= {n1, null1, ne1, e1, se1, s1, sw1, w1, nw1};
                
                SEND: begin
                    if (m00_axis_tready) begin
                        if (read_addr < DEPTH - 1) read_addr <= read_addr + 1;
                    end
                end
            endcase
        end
    end

    assign m00_axis_tdata = output_data;

endmodule
