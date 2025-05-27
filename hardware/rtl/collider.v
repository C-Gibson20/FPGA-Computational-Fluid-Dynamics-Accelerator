`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 27.05.2025 15:25:41
// Design Name: 
// Module Name: collider
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

// This should calculate the update rule Feq = weight_i * rho * (1 + 3*c_i*u + 9/2*(c_i * u)**2 - 3/2(u*u))
// Fnew = 2Feq - F

module collider(
input wire [15:0] f_null,
input wire [15:0] f_n,
input wire [15:0] f_ne,
input wire [15:0] f_e,
input wire [15:0] f_se,
input wire [15:0] f_s,
input wire [15:0] f_sw,
input wire [15:0] f_w,
input wire [15:0] f_nw,

output wire [15:0] new_f_null,
output wire [15:0] new_f_n,
output wire [15:0] new_f_ne,
output wire [15:0] new_f_e,
output wire [15:0] new_f_se,
output wire [15:0] new_f_s,
output wire [15:0] new_f_sw,
output wire [15:0] new_f_w,
output wire [15:0] new_f_nw,

output wire collider_busy,
output wire newval_ready,
output wire velocity_density_ready,

output wire [15:0] u_x,
output wire [15:0] u_y,
output wire [15:0] rho
);

assign collider_busy = 1'b1;
assign newval_ready = 1'b1;
assign velocity_density_ready = 1'b1;

reg [15:0] w_side = 16'h038e; // 1/9 in Q3.13
reg [15:0] w_diag = 16'h00e4; // 1/36 in Q3.13
reg [15:0] w_null = 16'h0e39; // 4/9 in Q3.13

reg [15:0] three_halfs = 16'h3000;
reg [15:0] nine_quarters = 16'h4800; //NOTE: 9/2 can't be represented in Q3.13. So we have to Lshift after  
reg [15:0] three = 16'h6000;

// implement fixed coeff. multiplier later

wire [15:0] sum_diags = f_ne + f_se + f_sw + f_nw;
wire [15:0] sum_side = f_n + f_e + f_s + f_w;

assign rho = f_null + sum_diags + sum_side;

wire [15:0] _nesw = f_ne - f_sw;
wire [15:0] _nwse = f_nw - f_se;

wire [15:0] rho_times_u_x = (f_e - f_w) + 
                            (_nesw - _nwse);

wire [15:0] rho_times_u_y = (f_n - f_s) + 
                            (_nesw + _nwse);

assign u_x = rho_times_u_x/rho; // TODO divde
assign u_y = rho_times_u_y/rho;

wire [15:0] u_x2 = u_x*u_x; // TODO: mult
wire [15:0] u_y2 = u_y*u_y;

wire [15:0] three_halfs_u2 = three_halfs * (u_x2 + u_y2); // TODO: fixed coeff

wire [15:0] f_eq_null = w_null * (1 - three_halfs_u2);
wire [15:0] f_eq_n = w_side * (1 + three*u_y + nine_quarters * (u_y2<<1) - three_halfs_u2);
wire [15:0] f_eq_e = w_side * (1 + three*u_x + nine_quarters * (u_x2<<1) - three_halfs_u2);
wire [15:0] f_eq_s = w_side * (1 - three*u_y + nine_quarters * (u_y2<<1) - three_halfs_u2);
wire [15:0] f_eq_w = w_side * (1 - three*u_x + nine_quarters * (u_x2<<1) - three_halfs_u2);

wire [15:0] x_plus_y2 = (u_x+u_y)**2;
wire [15:0] x_minus_y2 = (u_x-u_y)**2;

wire [15:0] f_eq_ne = w_diag * (1 + three*(u_x+u_y) + nine_quarters * (x_plus_y2<<1) - three_halfs_u2);
wire [15:0] f_eq_nw = w_diag * (1 + three*(-u_x+u_y) + nine_quarters * (x_minus_y2<<1) - three_halfs_u2);
wire [15:0] f_eq_se = w_diag * (1 - three*(u_x-u_y) + nine_quarters * (x_minus_y2<<1) - three_halfs_u2);
wire [15:0] f_eq_sw = w_side * (1 - three*(-u_x-u_y) + nine_quarters * (x_plus_y2<<1) - three_halfs_u2);

assign new_f_null = f_eq_null << 1 - f_null;
assign new_f_n =    f_eq_n    << 1 - f_n ;
assign new_f_ne =   f_eq_ne   << 1 - f_ne;
assign new_f_e =    f_eq_e    << 1 - f_e ;
assign new_f_se =   f_eq_se   << 1 - f_se;
assign new_f_s =    f_eq_s    << 1 - f_s ;
assign new_f_sw =   f_eq_sw   << 1 - f_sw;
assign new_f_w =    f_eq_w    << 1 - f_w ;
assign new_f_nw =   f_eq_nw   << 1 - f_nw;

// write address (assuming byte) = current_address + 2*direction_offset + (9*2* x_offset) + (LATTICE_WIDTH*9*2*y_offset)
// boundary (Zou-He): if write_address mod LATTICE_WIDTH == 0, 1 or LATTICE_WIDTH - 2, LATTICE_WIDTH - 1, don't change.

// assume tau=0.5 so that we can just multiply by two for the update rule: F - 2(F-Feq) = 2Feq - F


endmodule
