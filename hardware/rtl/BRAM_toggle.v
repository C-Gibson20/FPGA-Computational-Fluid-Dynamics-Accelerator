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
    input wire m00_axis_aclk,
    input wire m00_axis_aresetn,

    input wire chunk_transfer_ready,
    input wire chunk_compute_ready,
    
    //write enable BRAMs
    output reg wen,
    
    input wire [11:0] LBM_addr,
    input wire [11:0] DDR_addr,
    output reg [11:0] addr
    );

    always @(posedge m00_axis_aclk or negedge m00_axis_aresetn) begin
        if (!m00_axis_aresetn) begin
            addr <= 0;
            wen  <= 0;
        end 
        else begin
            wen <= 1;
            if (chunk_transfer_ready) begin
                addr <= DDR_addr;
            end 
            else if (chunk_compute_ready) begin
                addr <= LBM_addr;
            end 
            else begin
                wen <= 0;
            end
        end
    end
    
endmodule
