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

module collider(
input  wire signed [15:0] omega, // 1/tau
input  wire signed [15:0] f_null,
input  wire signed [15:0] f_n,
input  wire signed [15:0] f_ne,
input  wire signed [15:0] f_e,
input  wire signed [15:0] f_se,
input  wire signed [15:0] f_s,
input  wire signed [15:0] f_sw,
input  wire signed [15:0] f_w,
input  wire signed [15:0] f_nw,

output wire [15:0] f_new_null,
output wire [15:0] f_new_n,
output wire [15:0] f_new_ne,
output wire [15:0] f_new_e,
output wire [15:0] f_new_se,
output wire [15:0] f_new_s,
output wire [15:0] f_new_sw,
output wire [15:0] f_new_w,
output wire [15:0] f_new_nw,

output wire collider_busy,
output wire newval_ready,
output wire axi_ready,

output wire [15:0] u_x,
output wire [15:0] u_y,
output wire [15:0] rho
);

assign collider_busy = 1'b0;
assign newval_ready = 1'b1;
assign axi_ready = 1'b1;

wire signed [15:0] w_null        = 16'h0e39;       // 4/9 in Q3.13
wire signed [15:0] w_side        = 16'h038e;       // 1/9 in Q3.13
wire signed [15:0] w_diag        = 16'h00e4;       // 1/36 in Q3.13

wire signed [15:0] three_halfs   = 16'h3000;       // 3/2
wire signed [15:0] nine_quarters = 16'h4800;       // 9/4 NOTE: 9/2 can't be represented in Q3.13. So we have to Lshift after
wire signed [15:0] three         = 16'h6000;       // 3.0
wire signed [15:0] one           = 16'h2000;       // 1.0

// implement fixed coeff. multiplier later

assign rho = f_null + f_ne + f_se + f_sw + f_nw + f_n + f_e + f_s + f_w;

wire signed [15:0] rho_times_u_x = f_e - f_w + (f_ne - f_sw) - (f_nw - f_se);
wire signed [15:0] rho_times_u_y = f_n - f_s + (f_ne - f_sw) + (f_nw - f_se);

//TODO: Dont use division
wire signed [31:0] scaled_rho_times_u_x = rho_times_u_x <<< 13;
wire signed [31:0] scaled_rho_times_u_y = rho_times_u_y <<< 13;
assign u_x = scaled_rho_times_u_x / rho;
assign u_y = scaled_rho_times_u_y / rho;

wire signed [31:0] u_x_squared_intermediate = u_x * u_x;          
wire signed [15:0] u_x_squared = u_x_squared_intermediate >>> 13;

wire signed [31:0] u_y_squared_intermediate = u_y * u_y; 
wire signed [15:0] u_y_squared = u_y_squared_intermediate >>> 13;

wire signed [31:0] three_halfs_u_squared_intermediate = (three_halfs * (u_x_squared + u_y_squared));
wire signed [15:0] three_halfs_u_squared = three_halfs_u_squared_intermediate >>> 13;
 // TODO: fixed coeff

// Feq (equilibrium) values
wire signed [15:0] one_minus_three_halfs_u_squared = one - three_halfs_u_squared;
wire signed [31:0] f_eq_null_intermediate = w_null * one_minus_three_halfs_u_squared;
wire signed [15:0] f_eq_null = f_eq_null_intermediate >>> 13;

wire signed [31:0] three_u_y_intermediate = three * u_y;
wire signed [15:0] three_u_y = three_u_y_intermediate >>> 13;
wire signed [31:0] nine_halves_u_y_squared_intermediate = nine_quarters * (u_y_squared <<< 1);
wire signed [15:0] nine_halves_u_y_squared = nine_halves_u_y_squared_intermediate >>> 13;
wire signed [15:0] f_eq_n_polynomial = one + three_u_y + nine_halves_u_y_squared - three_halfs_u_squared;
wire signed [31:0] f_eq_n_intermediate = w_side * f_eq_n_polynomial;
wire signed [15:0] f_eq_n = f_eq_n_intermediate >>> 13;

wire signed [31:0] three_u_x_intermediate = three * u_x;
wire signed [15:0] three_u_x = three_u_x_intermediate >>> 13;
wire signed [31:0] nine_halves_u_x_squared_intermediate = nine_quarters * (u_x_squared <<< 1);
wire signed [15:0] nine_halves_u_x_squared = nine_halves_u_x_squared_intermediate >>> 13;
wire signed [15:0] f_eq_e_polynomial = one + three_u_x + nine_halves_u_x_squared - three_halfs_u_squared;
wire signed [31:0] f_eq_e_intermediate = w_side * f_eq_e_polynomial;
wire signed [15:0] f_eq_e = f_eq_e_intermediate >>> 13;


wire signed [31:0] three_u_y_intermediate_s = three * u_y;
wire signed [15:0] three_u_y_s = three_u_y_intermediate_s >>> 13;
wire signed [31:0] nine_halves_u_y_squared_intermediate_s = nine_quarters * (u_y_squared <<< 1);
wire signed [15:0] nine_halves_u_y_squared_s = nine_halves_u_y_squared_intermediate_s >>> 13;
wire signed [15:0] f_eq_s_polynomial = one - three_u_y_s + nine_halves_u_y_squared_s - three_halfs_u_squared;
wire signed [31:0] f_eq_s_intermediate = w_side * f_eq_s_polynomial;
wire signed [15:0] f_eq_s = f_eq_s_intermediate >>> 13;


wire signed [31:0] three_u_x_intermediate_w = three * u_x;
wire signed [15:0] three_u_x_w = three_u_x_intermediate_w >>> 13;
wire signed [31:0] nine_halves_u_x_squared_intermediate_w = nine_quarters * (u_x_squared <<< 1);
wire signed [15:0] nine_halves_u_x_squared_w = nine_halves_u_x_squared_intermediate_w >>> 13;
wire signed [15:0] f_eq_w_polynomial = one - three_u_x_w + nine_halves_u_x_squared_w - three_halfs_u_squared;
wire signed [31:0] f_eq_w_intermediate = w_side * f_eq_w_polynomial;
wire signed [15:0] f_eq_w = f_eq_w_intermediate >>> 13;


// Diagonal terms
wire signed [15:0] x_plus_y    = u_x + u_y;
wire signed [15:0] x_minus_y   = u_x - u_y;
wire signed [31:0] x_plus_y_squared_intermediate = x_plus_y * x_plus_y;
wire signed [15:0] x_plus_y_squared = x_plus_y_squared_intermediate >>> 13;
wire signed [31:0] x_minus_y_squared_intermediate = x_minus_y * x_minus_y;
wire signed [15:0] x_minus_y_squared = x_minus_y_squared_intermediate >>> 13;


wire signed [31:0] three_x_plus_y_intermediate = three * x_plus_y;
wire signed [15:0] three_x_plus_y = three_x_plus_y_intermediate >>> 13;
wire signed [31:0] nine_halves_x_plus_y_squared_intermediate = nine_quarters * (x_plus_y_squared <<< 1);
wire signed [15:0] nine_halves_x_plus_y_squared = nine_halves_x_plus_y_squared_intermediate >>> 13;
wire signed [15:0] f_eq_ne_polynomial = one + three_x_plus_y + nine_halves_x_plus_y_squared - three_halfs_u_squared;
wire signed [31:0] f_eq_ne_intermediate = w_diag * f_eq_ne_polynomial;
wire signed [15:0] f_eq_ne = f_eq_ne_intermediate >>> 13;


wire signed [15:0] neg_x_minus_y = -x_minus_y;
wire signed [31:0] three_neg_x_minus_y_intermediate = three * neg_x_minus_y;
wire signed [15:0] three_neg_x_minus_y = three_neg_x_minus_y_intermediate >>> 13;
wire signed [31:0] nine_halves_x_minus_y_squared_intermediate = nine_quarters * (x_minus_y_squared <<< 1);
wire signed [15:0] nine_halves_x_minus_y_squared = nine_halves_x_minus_y_squared_intermediate >>> 13;
wire signed [15:0] f_eq_nw_polynomial = one + three_neg_x_minus_y + nine_halves_x_minus_y_squared - three_halfs_u_squared;
wire signed [31:0] f_eq_nw_intermediate = w_diag * f_eq_nw_polynomial;
wire signed [15:0] f_eq_nw = f_eq_nw_intermediate >>> 13;


wire signed [31:0] three_x_minus_y_intermediate = three * x_minus_y;
wire signed [15:0] three_x_minus_y = three_x_minus_y_intermediate >>> 13;
wire signed [31:0] nine_halves_x_minus_y_squared_intermediate = nine_quarters * (x_minus_y_squared <<< 1);
wire signed [15:0] nine_halves_x_minus_y_squared = nine_halves_x_minus_y_squared_intermediate >>> 13;
wire signed [15:0] f_eq_se_polynomial = one - three_x_minus_y + nine_halves_x_minus_y_squared - three_halfs_u_squared;
wire signed [31:0] f_eq_se_intermediate = w_diag * f_eq_se_polynomial;
wire signed [15:0] f_eq_se = f_eq_se_intermediate >>> 13;


wire signed [15:0] neg_x_plus_y = -x_plus_y;
wire signed [31:0] three_neg_x_plus_y_intermediate = three * neg_x_plus_y;
wire signed [15:0] three_neg_x_plus_y = three_neg_x_plus_y_intermediate >>> 13;
wire signed [31:0] nine_halves_x_plus_y_squared_intermediate = nine_quarters * (x_plus_y_squared <<< 1);
wire signed [15:0] nine_halves_x_plus_y_squared = nine_halves_x_plus_y_squared_intermediate >>> 13;
wire signed [15:0] f_eq_sw_polynomial = one + three_neg_x_plus_y + nine_halves_x_plus_y_squared - three_halfs_u_squared;
wire signed [31:0] f_eq_sw_intermediate = w_diag * f_eq_sw_polynomial;
wire signed [15:0] f_eq_sw = f_eq_sw_intermediate >>> 13;


// Final update rule: f_i^new = f_i + omega * (f_eq_i - f_i)
wire signed [31:0] delta_f_null = omega * (f_eq_null - f_null);
assign f_new_null = f_null + (delta_f_null >>> 13);
wire signed [31:0] delta_f_n = omega * (f_eq_n - f_n);
assign f_new_n = f_n + (delta_f_n >>> 13);
wire signed [31:0] delta_f_ne = omega * (f_eq_ne - f_ne);
assign f_new_ne = f_ne + (delta_f_ne >>> 13);
wire signed [31:0] delta_f_e = omega * (f_eq_e - f_e);
assign f_new_e = f_e + (delta_f_e >>> 13);
wire signed [31:0] delta_f_se = omega * (f_eq_se - f_se);
assign f_new_se = f_se + (delta_f_se >>> 13);
wire signed [31:0] delta_f_s = omega * (f_eq_s - f_s);
assign f_new_s = f_s + (delta_f_s >>> 13);
wire signed [31:0] delta_f_sw = omega * (f_eq_sw - f_sw);
assign f_new_sw = f_sw + (delta_f_sw >>> 13);
wire signed [31:0] delta_f_w = omega * (f_eq_w - f_w);
assign f_new_w = f_w + (delta_f_w >>> 13);
wire signed [31:0] delta_f_nw = omega * (f_eq_nw - f_nw);
assign f_new_nw = f_nw + (delta_f_nw >>> 13);


// write address (assuming byte) = current_address + 2*direction_offset + (9*2* x_offset) + (LATTICE_WIDTH*9*2*y_offset)
// boundary (Zou-He): if write_address mod LATTICE_WIDTH == 0, 1 or LATTICE_WIDTH - 2, LATTICE_WIDTH - 1, don't change.
endmodule
