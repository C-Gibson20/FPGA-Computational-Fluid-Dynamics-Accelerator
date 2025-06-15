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
    output reg  m00_axis_tvalid,
    output reg [144-1 : 0] m00_axis_tdata,
    output wire [(144/8)-1 : 0] m00_axis_tstrb,
    output wire  m00_axis_tlast,
    input wire  m00_axis_tready
);
    
    //iterate through all 2500 pixels
    reg [143:0] output_data;
    reg [1:0] current_state;
    reg [1:0] next_state;
    reg [5:0] count;
    reg was_reset;

    //states
    localparam IDLE    = 2'd0;
    localparam FILL_DATA         = 2'd1;
    localparam SEND         = 2'd2;

    assign m00_axis_tstrb = {18{1'b1}};

    always @(posedge m00_axis_aclk or negedge m00_axis_aresetn) begin
        if (!m00_axis_aresetn) begin
            current_state <= IDLE;
            was_reset <= 1;
            read_addr <= 0;
        end
        else begin
            current_state <= next_state;
            was_reset <= 0;
        end

    end
////////////////////////////////////////////////////////////////////////////

    //set flags etc here
    always @* begin
       case(current_state)
        IDLE: begin
            // // read_addr = (was_reset) ? 0 : read_addr;
            m00_axis_tlast = (was_reset) ? 0 : read_addr;
            m00_axis_tvalid = (was_reset) ? 0 : read_addr;
        end
       
        FILL_DATA: begin
            m00_axis_tvalid = 0;
        end
        
        SEND: begin
            m00_axis_tlast = (read_addr == DEPTH - 1);
        end

        default: begin
        end
       endcase
    end


//////////////////////////////////////////////////////////////////////////////

    //states
    always @* begin
        case(current_state)
        IDLE: begin
            if (m00_axis_tready && read_addr > 0) next_state = SEND;
            else if (frame_ready && read_addr == 0) next_state = FILL_DATA;
            else next_state = IDLE;
        end

        FILL_DATA: begin
            next_state = IDLE;
        end
        
        SEND: begin
            next_state = (m00_axis_tlast) ? IDLE : FILL_DATA;
        end
        
        default: begin
            next_state = IDLE;
        end
    endcase
    end

/////////////////////////////////////////////////////////////////

    // state logic
    always @(posedge m00_axis_aclk) begin
        case(current_state)
        FILL_DATA: begin
            read_addr <= read_addr + 1;
            output_data <= {n1, null1, ne1, e1, se1, s1, sw1, w1, nw1};
        end
        
        SEND: begin
            // read_addr += 1;
            m00_axis_tdata <= output_data;
        end
        
        default: ;
    endcase
    end



endmodule
