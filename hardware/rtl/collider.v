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

assign u_x = (rho_times_u_x <<< 13) / rho; // TODO divde
assign u_y = (rho_times_u_y <<< 13) / rho;

wire signed [15:0] u_x_squared = (u_x * u_x) >>> 13;
wire signed [15:0] u_y_squared = (u_y * u_y) >>> 13;
wire signed [15:0] three_halfs_u2 = (three_halfs * (u_x_squared + u_y_squared)) >>> 13;
 // TODO: fixed coeff

// Feq (equilibrium) values
wire signed [15:0] f_eq_null = (w_null * (one - three_halfs_u2)) >>> 13;

wire signed [15:0] f_eq_n = (w_side *
    (one + (three * u_y >>> 13) + (nine_quarters * (u_y_squared <<< 1) >>> 13) - three_halfs_u2)) >>> 13;

wire signed [15:0] f_eq_e = (w_side *
    (one + (three * u_x >>> 13) + (nine_quarters * (u_x_squared <<< 1) >>> 13) - three_halfs_u2)) >>> 13;

wire signed [15:0] f_eq_s = (w_side *
    (one - (three * u_y >>> 13) + (nine_quarters * (u_y_squared <<< 1) >>> 13) - three_halfs_u2)) >>> 13;

wire signed [15:0] f_eq_w = (w_side *
    (one - (three * u_x >>> 13) + (nine_quarters * (u_x_squared <<< 1) >>> 13) - three_halfs_u2)) >>> 13;

// Diagonal terms
wire signed [15:0] x_plus_y    = u_x + u_y;
wire signed [15:0] x_minus_y   = u_x - u_y;
wire signed [15:0] x_plus_y2   = (x_plus_y * x_plus_y) >>> 13;
wire signed [15:0] x_minus_y2  = (x_minus_y * x_minus_y) >>> 13;

wire signed [15:0] f_eq_ne = (w_diag *
    (one + (three * x_plus_y >>> 13) + (nine_quarters * (x_plus_y2 <<< 1) >>> 13) - three_halfs_u2)) >>> 13;

wire signed [15:0] f_eq_nw = (w_diag *
    (one + (three * (-x_minus_y) >>> 13) + (nine_quarters * (x_minus_y2 <<< 1) >>> 13) - three_halfs_u2)) >>> 13;

wire signed [15:0] f_eq_se = (w_diag *
    (one - (three * x_minus_y >>> 13) + (nine_quarters * (x_minus_y2 <<< 1) >>> 13) - three_halfs_u2)) >>> 13;

wire signed [15:0] f_eq_sw = (w_diag *
    (one - (three * (-x_plus_y) >>> 13) + (nine_quarters * (x_plus_y2 <<< 1) >>> 13) - three_halfs_u2)) >>> 13;

// Final update rule: f_i^new = f_i + omega * (f_eq_i - f_i)
assign new_f_null = f_null + ((omega * (f_eq_null - f_null)) >>> 13);
assign new_f_n    = f_n    + ((omega * (f_eq_n    - f_n))    >>> 13);
assign new_f_ne   = f_ne   + ((omega * (f_eq_ne   - f_ne))   >>> 13);
assign new_f_e    = f_e    + ((omega * (f_eq_e    - f_e))    >>> 13);
assign new_f_se   = f_se   + ((omega * (f_eq_se   - f_se))   >>> 13);
assign new_f_s    = f_s    + ((omega * (f_eq_s    - f_s))    >>> 13);
assign new_f_sw   = f_sw   + ((omega * (f_eq_sw   - f_sw))   >>> 13);
assign new_f_w    = f_w    + ((omega * (f_eq_w    - f_w))    >>> 13);
assign new_f_nw   = f_nw   + ((omega * (f_eq_nw   - f_nw))   >>> 13);

// write address (assuming byte) = current_address + 2*direction_offset + (9*2* x_offset) + (LATTICE_WIDTH*9*2*y_offset)
// boundary (Zou-He): if write_address mod LATTICE_WIDTH == 0, 1 or LATTICE_WIDTH - 2, LATTICE_WIDTH - 1, don't change.


endmodule
