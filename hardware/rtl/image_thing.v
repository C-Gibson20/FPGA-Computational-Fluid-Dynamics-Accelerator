`timescale 1ps / 1ps
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
`include "def.vh"

module image_thing(
    input wire clk,
    input wire in_collision_state,
    input wire axi_ready, //axi has written the next 32 bits
    input wire [31:0] data_in, //complete img ready
    output reg [`DEPTH-1:0] data_out
);
    localparam input_width = 32;
    localparam max_count = $floor(`DEPTH/32);

    
    reg [15:0] count;
    reg [`DEPTH -1:0] curr_bits;
    reg reg_full;  
    reg next_img;

    
    always @(posedge clk or posedge next_img) begin
        if (next_img) begin
            curr_bits <= 0;
            count <= 0;
            next_img <= 0;
        end
        else begin
            next_img <= 0;  
            if (axi_ready) begin
                curr_bits <= {curr_bits[`DEPTH-input_width-1:0], data_in};
                if (count == max_count && !in_collision_state) begin
                    data_out <= curr_bits;
                    next_img <= 1;  
                    count <= 0;     
                end
                else if (!next_img) begin
                    count <= count + 1;
                end
            end
        end
    end
endmodule