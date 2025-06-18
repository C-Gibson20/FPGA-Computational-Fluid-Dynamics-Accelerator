`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 16.06.2025 01:56:25
// Design Name: 
// Module Name: cache_top
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


module BRAM_toggle(
    input wire chunk_transfer_ready,
    input wire chunk_compute_ready,
    
    //from DDR_pixel if currently writing
    input wire wen,
    
    input wire [11:0] LBM_addr,
    input wire [11:0] DDR_addr,
    output reg [11:0] addr
    );
    
    always @* begin
        if (chunk_transfer_ready) begin
            addr <= DDR_addr;
        end
        else if (chunk_compute_ready) begin 
            addr <= LBM_addr;
        end
   end
    
endmodule
