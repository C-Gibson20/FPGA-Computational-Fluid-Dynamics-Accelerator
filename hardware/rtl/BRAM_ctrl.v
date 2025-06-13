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
    parameter  ADDRESS_WIDTH             = 12,
)(
    input wire clk,
    input wire frame_ready,
    input wire rst,
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
    output wire [143:0] pixel_data,
    // AXI flags
    input wire tready,
    output reg [11:0] read_addr;
    output reg tvalid, tlast,
    output reg [31:0] tkeep
);
    
    //iterate through all 2500 pixels
    reg [143:0] output_data;
    reg [1:0] current_state;
    reg [5:0] count;

    //states
    localparam FILL_DATA    = 2'd0;
    localparam IDLE         = 2'd1;
    localparam SEND         = 2'd2;

    always @(posedge clk) begin
        if(rst or frame_ready) begin
            read_addr <= 0;
            output_data <= 0;
            tvalid <= 0;
            tlast <= 0;
            tkeep <= 0;
            count <= 0;

            if (frame_ready) begin
                current_state <= FILL_DATA;
            end else begin
                current_state <= IDLE;
        end 
        else begin
            current_state <= next_state;
        end
    end
////////////////////////////////////////////////////////////////////////////

    //set flags etc here
    always @* begin
       case(current_state)
        IDLE: begin
            tvalid = 0;
            tlast = 0;
        end
       
        FILL_DATA: begin
            // fill one pixel
            output_data = {n1, null1, ne1, e1, se1, s1, sw1, w1, nw1};
            tvalid = 0;
            tlast = 1;
            tkeep = 32h'FFFFFFFF;
        end
        
        SEND: begin
            tvalid = 1;
            pixel_data = output_data;
            tvalid = 0;
            if (read_addr == DEPTH - 1) {
                read_addr == 0;
            }
            else {
                read_addr += 1;
            }
        end
    end


//////////////////////////////////////////////////////////////////////////////

    //states
    always @* begin
        case(current_state)
        IDLE: begin
            if(tready)
                next_state = SEND;
            else if (frame_ready)
                next_state = FILL_DATA;
                read_addr = 12'b0;
        end
        FILL_DATA: begin
            next_state = IDLE;
            // if(count = 5'b1)
            //     next_state = IDLE;
            // else
            //     next_state = FILL_DATA;
        end
        SEND: begin
            //someone check what tlast is again pls
            next_state = (tlast) ? FILL_DATA : SEND;
            // if (tlast)
            //     next_state = FILL_DATA;
            // else
            //     next_state = SEND;
        end
        
    end

endmodule