`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 27.05.2025
// Design Name: LBM Collider
// Module Name: collider
// Description: Computes Feq and relaxation step: f_i^new = f_i + omega * (Feq_i - f_i)
//////////////////////////////////////////////////////////////////////////////////

module collider(
    input  wire signed [15:0] omega, // 1/tau

    input  wire signed [15:0] f_null, f_n, f_ne, f_e, f_se, f_s, f_sw, f_w, f_nw,

    output wire [15:0] f_new_null, f_new_n, f_new_ne, f_new_e, f_new_se,
                       f_new_s, f_new_sw, f_new_w, f_new_nw,

    output wire collider_busy,
    output wire newval_ready,
    output wire axi_ready,

    output wire [15:0] u_x, u_y, rho
);

// ----------------------------------------------------------------------------------
// Constants (Q3.13 Fixed-Point)
// ----------------------------------------------------------------------------------

wire signed [15:0] w_null        = 16'h0e39; // 4/9
wire signed [15:0] w_side        = 16'h038e; // 1/9
wire signed [15:0] w_diag        = 16'h00e4; // 1/36

wire signed [15:0] one           = 16'h2000; // 1.0
wire signed [15:0] two           = 16'h4000; // 2.0
wire signed [15:0] three         = 16'h6000; // 3.0
wire signed [15:0] three_halves  = 16'h3000; // 3/2
wire signed [15:0] nine_quarters = 16'h4800; // 9/4

assign collider_busy = 1'b0;
assign newval_ready  = 1'b1;
assign axi_ready     = 1'b1;

// ----------------------------------------------------------------------------------
// Step 1: Compute macroscopic variables (rho, u)
// ----------------------------------------------------------------------------------

assign rho = f_null + f_n + f_ne + f_e + f_se + f_s + f_sw + f_w + f_nw;

// wire signed [31:0] scaled_rho_ux = (f_e - f_w + f_ne - f_sw - f_nw + f_se) <<< 13;
// wire signed [31:0] scaled_rho_uy = (f_n - f_s + f_ne - f_sw + f_nw - f_se) <<< 13;

wire signed [15:0] rho_ux = (f_e - f_w + f_ne - f_sw - f_nw + f_se);
wire signed [15:0] rho_uy = (f_n - f_s + f_ne - f_sw + f_nw - f_se);

// assign u_x = scaled_rho_ux / rho;
// assign u_y = scaled_rho_uy / rho;

// Newton-Raphson Reciprocal Approximation (3 iteration) 
// assuming 0.85 << rho << 1.15
// x0 = 1
// x1 = x0 * (2 - rho * x0)
// wher x0 ≈ 1 / rho

// Initial guess: x0 = 1.0 in Q3.13
//x1 iteration
// wire signed [15:0] x1 = two - rho;

//x2 iteration
wire signed [31:0] rho_x1 = rho * (two - rho);
wire signed [31:0] x2 = (two - rho) * (two - (rho_x1 >>> 13));

//x3 iteration
wire signed [31:0] rho_x2 = rho * (x2 >>> 13);
wire signed [31:0] x3 = (x2 >>> 13) * (two - (rho_x2 >>> 13));

wire signed [31:0] u_x_intermediate = rho_ux * (x3 >>> 13); 
wire signed [31:0] u_y_intermediate = rho_uy * (x3 >>> 13);

assign u_x = u_x_intermediate >>> 13;
assign u_y = u_y_intermediate >>> 13;



// ----------------------------------------------------------------------------------
// Step 2: u^2 and related terms
// ----------------------------------------------------------------------------------

wire signed [31:0] u_x_squared_intermediate = u_x * u_x;
wire signed [31:0] u_y_squared_intermediate = u_y * u_y;
wire signed [15:0] u_x_squared = u_x_squared_intermediate >>> 13;
wire signed [15:0] u_y_squared = u_y_squared_intermediate >>> 13;

wire signed [15:0] u_squared = u_x_squared + u_y_squared;
wire signed [31:0] three_halves_u_squared_intermediate = three_halves * u_squared;
wire signed [15:0] three_halves_u_squared = three_halves_u_squared_intermediate >>> 13;

// ----------------------------------------------------------------------------------
// Step 3: Compute Feq values
// ----------------------------------------------------------------------------------

// Center
// wire signed [15:0] polynomial_null = one - three_halves_u_squared;
// wire signed [31:0] f_eq_null_intermediate = w_null * polynomial_null;
// wire signed [31:0] f_eq_null_intermediate_2 = rho * (f_eq_null_intermediate >>> 13);
// wire signed [15:0] f_eq_null = f_eq_null_intermediate_2 >>> 13;

// Cardinal directions
// 3 * u_x and 3 * u_y
wire signed [31:0] three_u_x_intermediate = three * u_x;
wire signed [31:0] three_u_y_intermediate = three * u_y;
wire signed [15:0] three_u_x = three_u_x_intermediate >>> 13;
wire signed [15:0] three_u_y = three_u_y_intermediate >>> 13;

// 9/2 * u_x^2 and u_y^2
wire signed [31:0] nine_half_u_x_squared_intermediate = nine_quarters * (u_x_squared <<< 1);
wire signed [31:0] nine_half_u_y_squared_intermediate = nine_quarters * (u_y_squared <<< 1);
wire signed [15:0] nine_half_u_x_squared = nine_half_u_x_squared_intermediate >>> 13;
wire signed [15:0] nine_half_u_y_squared = nine_half_u_y_squared_intermediate >>> 13;

wire signed [15:0] polynomial_n = one + three_u_y + nine_half_u_y_squared - three_halves_u_squared;
wire signed [15:0] polynomial_s = one - three_u_y + nine_half_u_y_squared - three_halves_u_squared;
wire signed [15:0] polynomial_e = one + three_u_x + nine_half_u_x_squared - three_halves_u_squared;
wire signed [15:0] polynomial_w = one - three_u_x + nine_half_u_x_squared - three_halves_u_squared;

wire signed [31:0] f_eq_n_intermediate = w_side * polynomial_n;
wire signed [31:0] f_eq_s_intermediate = w_side * polynomial_s;
wire signed [31:0] f_eq_e_intermediate = w_side * polynomial_e;
wire signed [31:0] f_eq_w_intermediate = w_side * polynomial_w;

wire signed [31:0] f_eq_n_intermediate_2 = rho * (f_eq_n_intermediate >>> 13);
wire signed [31:0] f_eq_s_intermediate_2 = rho * (f_eq_s_intermediate >>> 13);
wire signed [31:0] f_eq_e_intermediate_2 = rho * (f_eq_e_intermediate >>> 13);
wire signed [31:0] f_eq_w_intermediate_2 = rho * (f_eq_w_intermediate >>> 13);

wire signed [15:0] f_eq_n = f_eq_n_intermediate_2 >>> 13;
wire signed [15:0] f_eq_s = f_eq_s_intermediate_2 >>> 13;
wire signed [15:0] f_eq_e = f_eq_e_intermediate_2 >>> 13;
wire signed [15:0] f_eq_w = f_eq_w_intermediate_2 >>> 13;

// Diagonals
wire signed [15:0] x_plus_y    = u_x + u_y;
wire signed [15:0] x_minus_y   = u_x - u_y;
wire signed [15:0] neg_x_plus_y = -x_plus_y;
wire signed [15:0] neg_x_minus_y = -x_minus_y;

wire signed [31:0] x_plus_y_squared_intermediate  = x_plus_y * x_plus_y;
wire signed [15:0] x_plus_y_squared               = x_plus_y_squared_intermediate >>> 13;

wire signed [31:0] x_minus_y_squared_intermediate = x_minus_y * x_minus_y;
wire signed [15:0] x_minus_y_squared              = x_minus_y_squared_intermediate >>> 13;

wire signed [31:0] three_x_plus_y_intermediate     = three * x_plus_y;
wire signed [15:0] three_x_plus_y                  = three_x_plus_y_intermediate >>> 13;

wire signed [31:0] three_neg_x_plus_y_intermediate = three * neg_x_plus_y;
wire signed [15:0] three_neg_x_plus_y              = three_neg_x_plus_y_intermediate >>> 13;

wire signed [31:0] three_x_minus_y_intermediate     = three * x_minus_y;
wire signed [15:0] three_x_minus_y                  = three_x_minus_y_intermediate >>> 13;

wire signed [31:0] three_neg_x_minus_y_intermediate = three * neg_x_minus_y;
wire signed [15:0] three_neg_x_minus_y              = three_neg_x_minus_y_intermediate >>> 13;

wire signed [31:0] nine_half_x_plus_y_squared_intermediate = nine_quarters * (x_plus_y_squared <<< 1);
wire signed [15:0] nine_half_x_plus_y_squared              = nine_half_x_plus_y_squared_intermediate >>> 13;

wire signed [31:0] nine_half_x_minus_y_squared_intermediate = nine_quarters * (x_minus_y_squared <<< 1);
wire signed [15:0] nine_half_x_minus_y_squared              = nine_half_x_minus_y_squared_intermediate >>> 13;

wire signed [15:0] polynomial_ne = one + three_x_plus_y + nine_half_x_plus_y_squared - three_halves_u_squared;
wire signed [15:0] polynomial_sw = one + three_neg_x_plus_y + nine_half_x_plus_y_squared - three_halves_u_squared;
wire signed [15:0] polynomial_nw = one + three_neg_x_minus_y + nine_half_x_minus_y_squared - three_halves_u_squared;
wire signed [15:0] polynomial_se = one + three_x_minus_y + nine_half_x_minus_y_squared - three_halves_u_squared;

wire signed [31:0] f_eq_ne_intermediate = w_diag * polynomial_ne;
wire signed [31:0] f_eq_sw_intermediate = w_diag * polynomial_sw;
wire signed [31:0] f_eq_nw_intermediate = w_diag * polynomial_nw;
wire signed [31:0] f_eq_se_intermediate = w_diag * polynomial_se;

wire signed [31:0] f_eq_ne_intermediate_2 = rho * (f_eq_ne_intermediate >>> 13);
wire signed [31:0] f_eq_sw_intermediate_2 = rho * (f_eq_sw_intermediate >>> 13);
wire signed [31:0] f_eq_nw_intermediate_2 = rho * (f_eq_nw_intermediate >>> 13);
wire signed [31:0] f_eq_se_intermediate_2 = rho * (f_eq_se_intermediate >>> 13);

wire signed [15:0] f_eq_ne = f_eq_ne_intermediate_2 >>> 13;
wire signed [15:0] f_eq_sw = f_eq_sw_intermediate_2 >>> 13;
wire signed [15:0] f_eq_nw = f_eq_nw_intermediate_2 >>> 13;
wire signed [15:0] f_eq_se = f_eq_se_intermediate_2 >>> 13;


// ----------------------------------------------------------------------------------
// Step 4: Final update f_i^new = f_i + omega * (f_eq_i - f_i)
// ----------------------------------------------------------------------------------

// Intermediate deltas
// wire signed [31:0] delta_f_null = omega * (f_eq_null - f_null);
wire signed [31:0] delta_f_n    = omega * (f_eq_n    - f_n);
wire signed [31:0] delta_f_ne   = omega * (f_eq_ne   - f_ne);
wire signed [31:0] delta_f_e    = omega * (f_eq_e    - f_e);
wire signed [31:0] delta_f_se   = omega * (f_eq_se   - f_se);
wire signed [31:0] delta_f_s    = omega * (f_eq_s    - f_s);
wire signed [31:0] delta_f_sw   = omega * (f_eq_sw   - f_sw);
wire signed [31:0] delta_f_w    = omega * (f_eq_w    - f_w);
wire signed [31:0] delta_f_nw   = omega * (f_eq_nw   - f_nw);

// Final updated values (Q3.13 -> Q3.13)
assign f_new_n    = f_n    + (delta_f_n    >>> 13);
assign f_new_ne   = f_ne   + (delta_f_ne   >>> 13);
assign f_new_e    = f_e    + (delta_f_e    >>> 13);
assign f_new_se   = f_se   + (delta_f_se   >>> 13);
assign f_new_s    = f_s    + (delta_f_s    >>> 13);
assign f_new_sw   = f_sw   + (delta_f_sw   >>> 13);
assign f_new_w    = f_w    + (delta_f_w    >>> 13);
assign f_new_nw   = f_nw   + (delta_f_nw   >>> 13);
assign f_new_null = rho - (f_new_n  + f_new_ne + f_new_e + f_new_se + f_new_s + f_new_sw + f_new_w + f_new_nw);

endmodule
