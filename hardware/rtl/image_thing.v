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


module image_thing(
    input wire clk,
    input wire in_collision_state,
    input wire [31:0] data_in,
    output reg [2499:0] data_out
);
    localparam total = 2500;
    localparam input_width = 32;
    
    reg [5:0] count;
    reg [2499:0] curr_bits;
    reg reg_full;  
    reg next_img;
    
    always @(posedge clk or posedge next_img) begin 
        if(next_img) begin
            data_out <= 2500'b0;
            curr_bits <= 2500'b0;
            count <= 0;
            reg_full <= 0;
            next_img <= 0;
        end
        else if (!reg_full) begin 
            curr_bits <= {curr_bits[total-input_width-1:0], data_in};  
            if(count == 77 && in_collision_state == 0) begin  
                reg_full <= 1;  
                data_out <= curr_bits;
                next_img <= 1;
            end
            else begin             
                count <= count + 1;
            end
        end
    end
endmodule