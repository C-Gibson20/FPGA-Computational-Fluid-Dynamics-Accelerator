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
    output reg tvalid, tlast,
    output reg [31:0] tkeep
);
    
    //iterate through all 2500 pixels
    reg [11:0] read_addr;
    reg [143:0] output_data;
    reg [1:0] current_state;

    //states
    localparam FILL_DATA    = 2'd0;
    localparam WAIT_READY   = 2'd1;
    localparam SEND         = 2'd2;

    always @(posedge clk) begin
        if(rst or frame_ready) begin
            read_addr <= 0;
            output_data <= 0;
            tvalid <= 0;
            tlast <= 0;
            tkeep <= 0;
        end 
        else begin
            current_state <= next_state;

            
    end

    //shift data into the register one BRAM at a time
    always *@ begin
        case (current_state)
    end

    //same as always comb apparently
    always @* begin
        case(current_state)
    end

endmodule