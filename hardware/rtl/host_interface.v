`timescale 1ps / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 30.05.2025 19:04:21
// Design Name: 
// Module Name: host_interface
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

// host interface is controlled by GPIO. one of the GPIO input pins specifies the
// pixel to be sent via the 48 bit GPIO output bus. 
// GPIOi => 0x3
// SET MSB of GPIOi to 1 if currenty querying data, else set to zero - to avoid concurrency issues.
// check if collider_ready was off for at least `WIDTH time before rewriting to registers. 
// done so that registers are not written in the middle of collision stage. 

`include "def.vh"

module host_interface(
    input wire clk,
    input wire rst,
    input wire [`DATA_WIDTH-1:0]   GPIOi,
    input wire          collider_ready,
    input wire [`DATA_WIDTH-1:0]   u_x,
    input wire [`DATA_WIDTH-1:0]   u_y,
    input wire [`DATA_WIDTH-1:0]   rho,
    input wire [`DATA_WIDTH-1:0]   u_squared,
    input wire in_collision_state,
    
    output reg [`DATA_WIDTH-1:0] GPIOux, // send data one at a time first
    output reg [`DATA_WIDTH-1:0] GPIOuy, // send data one at a time first
    output reg [`DATA_WIDTH-1:0] GPIOrho, // send data one at a time first
    output reg [`DATA_WIDTH-1:0] GPIOu2 // send data one at a time first
    
    );
    
    reg [`DATA_WIDTH-1:0] uxs [`DEPTH-1:0];
    reg [`DATA_WIDTH-1:0] uys [`DEPTH-1:0];
    reg [`DATA_WIDTH-1:0] rhos [`DEPTH-1:0];
    reg [`DATA_WIDTH-1:0] u2s [`DEPTH-1:0];
    reg [`ADDRESS_WIDTH-1:0] count;
    
    wire host_transmission;
    assign host_transmission = GPIOi[`DATA_WIDTH-1]; // MSB is host_active
//    reg accept_new_data;
    // IGNORE THESE COMMENTS:
    //// new data is accepted if:
    ////  not talking with host
    ////  not in the same collision_state as before (if talked to host during a collision state)
    ////  so: in_collision_state = 0 => accept_new_data = 1
    ////  but: in_collision_state = 1 && host_transmission => accept_new_data = 0
    
    // simple one: add to ux, uy, rho if collider ready and in collidion state
    // if not in collision state reset count to zero
    
    always @(posedge clk) begin
        if(in_collision_state && collider_ready) begin
            uxs[count] <= u_x;
            uys[count] <= u_y;
            rhos[count] <= rho;
            u2s[count] <= u_squared;
            count <= count + 1;
        end
        else if(in_collision_state) begin
            count <= count;
        end
        else begin
            count <= 0;
        end

        if(host_transmission) begin
            GPIOux <= uxs[GPIOi[`ADDRESS_WIDTH-1:0]];
            GPIOuy <= uys[GPIOi[`ADDRESS_WIDTH-1:0]];
            GPIOrho <= rhos[GPIOi[`ADDRESS_WIDTH-1:0]];
            GPIOu2 <= u2s[GPIOi[`ADDRESS_WIDTH-1:0]];
        end

        if(!rst) begin
            count <= 0;
        end
    end
    
     
endmodule

