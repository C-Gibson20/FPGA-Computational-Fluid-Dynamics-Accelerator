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

    output wire signed [15:0] f_new_null, f_new_n, f_new_ne, f_new_e, f_new_se,
                       f_new_s, f_new_sw, f_new_w, f_new_nw,

    output wire collider_busy,
    output wire newval_ready,
    output wire axi_ready,

    output wire signed [15:0] u_x, u_y, rho, u_squared
);

assign collider_busy = 1'b0;
assign newval_ready  = 1'b1;
assign axi_ready     = 1'b1;

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

wire signed [15:0] round = 1 <<< 12;

function automatic signed [15:0] multiply(input signed [15:0] a, b);
    reg signed [31:0] product; 
    reg signed [15:0] shifted;
    begin
        product = (a * b) + round;
        shifted = product >>> 13;

        multiply = (product > 32'sh10000000) ? 16'sh7FFF :
                   (product < 32'shf0000000) ? 16'sh8000 :
                   shifted;
    end
endfunction

// ----------------------------------------------------------------------------------
// Step 1: Compute macroscopic variables (rho, u)
// ----------------------------------------------------------------------------------

assign rho = f_null + f_n + f_ne + f_e + f_se + f_s + f_sw + f_w + f_nw;

wire signed [15:0] rho_ux = (f_e - f_w + f_ne - f_sw - f_nw + f_se);
wire signed [15:0] rho_uy = (f_n - f_s + f_ne - f_sw + f_nw - f_se);

// Newton-Raphson Reciprocal Approximation (3 iteration) 
// assuming 0.85 << rho << 1.15
// x0 = 1
// x1 = x0 * (2 - rho * x0)
// wher x0 ≈ 1 / rho

// Initial guess: x0 = 1.0 in Q3.13
//x1 iteration
// wire signed [15:0] x1 = two - rho;

//x2 iteration
wire signed [15:0] rho_x1 = multiply(rho, two - rho);
wire signed [15:0] x2 = multiply(two - rho, two - rho_x1);

//x3 iteration
wire signed [15:0] rho_x2 = multiply(rho, x2);
wire signed [15:0] x3 = multiply(x2, two - rho_x2);

assign u_x = multiply(rho_ux, x3);
assign u_y = multiply(rho_uy, x3);

// ----------------------------------------------------------------------------------
// Step 2: u^2 and related terms
// ----------------------------------------------------------------------------------

wire signed [15:0] u_x_squared = multiply(u_x,u_x);
wire signed [15:0] u_y_squared = multiply(u_y,u_y);
assign u_squared = u_x_squared + u_y_squared;

wire signed [15:0] three_halves_u_squared = multiply(three_halves,u_squared);

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
wire signed [15:0] three_u_x = multiply(three,u_x);
wire signed [15:0] three_u_y = multiply(three,u_y);

// 9/2 * u_x^2 and u_y^2
wire signed [15:0] nine_half_u_x_squared = multiply(nine_quarters,u_x_squared <<< 1);
wire signed [15:0] nine_half_u_y_squared = multiply(nine_quarters,u_y_squared <<< 1);

wire signed [15:0] polynomial_n = one + three_u_y + nine_half_u_y_squared - three_halves_u_squared;
wire signed [15:0] polynomial_s = one - three_u_y + nine_half_u_y_squared - three_halves_u_squared;
wire signed [15:0] polynomial_e = one + three_u_x + nine_half_u_x_squared - three_halves_u_squared;
wire signed [15:0] polynomial_w = one - three_u_x + nine_half_u_x_squared - three_halves_u_squared;

wire signed [15:0] f_eq_n_intermediate = multiply(w_side, polynomial_n);
wire signed [15:0] f_eq_s_intermediate = multiply(w_side, polynomial_s);
wire signed [15:0] f_eq_e_intermediate = multiply(w_side, polynomial_e);
wire signed [15:0] f_eq_w_intermediate = multiply(w_side, polynomial_w);

wire signed [15:0] f_eq_n = multiply(rho, f_eq_n_intermediate);
wire signed [15:0] f_eq_s = multiply(rho, f_eq_s_intermediate);
wire signed [15:0] f_eq_e = multiply(rho, f_eq_e_intermediate);
wire signed [15:0] f_eq_w = multiply(rho, f_eq_w_intermediate);
// Diagonals
wire signed [15:0] x_plus_y    = u_x + u_y;
wire signed [15:0] x_minus_y   = u_x - u_y;
wire signed [15:0] neg_x_plus_y = -x_plus_y;
wire signed [15:0] neg_x_minus_y = -x_minus_y;

wire signed [15:0] x_plus_y_squared               = multiply(x_plus_y, x_plus_y);
wire signed [15:0] x_minus_y_squared              = multiply(x_minus_y, x_minus_y);
wire signed [15:0] three_x_plus_y                  = multiply(three, x_plus_y);
wire signed [15:0] three_neg_x_plus_y              = multiply(three, neg_x_plus_y);
wire signed [15:0] three_x_minus_y                  = multiply(three, x_minus_y);
wire signed [15:0] three_neg_x_minus_y              = multiply(three, neg_x_minus_y);
wire signed [15:0] nine_half_x_plus_y_squared              = multiply(nine_quarters, x_plus_y_squared <<< 1);
wire signed [15:0] nine_half_x_minus_y_squared              = multiply(nine_quarters, x_minus_y_squared <<< 1);

wire signed [15:0] polynomial_ne = one + three_x_plus_y + nine_half_x_plus_y_squared - three_halves_u_squared;
wire signed [15:0] polynomial_sw = one + three_neg_x_plus_y + nine_half_x_plus_y_squared - three_halves_u_squared;
wire signed [15:0] polynomial_nw = one + three_neg_x_minus_y + nine_half_x_minus_y_squared - three_halves_u_squared;
wire signed [15:0] polynomial_se = one + three_x_minus_y + nine_half_x_minus_y_squared - three_halves_u_squared;

wire signed [15:0] f_eq_ne_intermediate = multiply(w_diag, polynomial_ne);
wire signed [15:0] f_eq_sw_intermediate = multiply(w_diag, polynomial_sw);
wire signed [15:0] f_eq_nw_intermediate = multiply(w_diag, polynomial_nw);
wire signed [15:0] f_eq_se_intermediate = multiply(w_diag, polynomial_se);

wire signed [15:0] f_eq_ne = multiply(rho, f_eq_ne_intermediate);
wire signed [15:0] f_eq_sw = multiply(rho, f_eq_sw_intermediate);
wire signed [15:0] f_eq_nw = multiply(rho, f_eq_nw_intermediate);
wire signed [15:0] f_eq_se = multiply(rho, f_eq_se_intermediate);


// ----------------------------------------------------------------------------------
// Step 4: Final update f_i^new = f_i + omega * (f_eq_i - f_i)
// ----------------------------------------------------------------------------------

// Intermediate deltas
// wire signed [31:0] delta_f_null = omega * (f_eq_null - f_null);
wire signed [15:0] delta_f_n    = multiply(omega, f_eq_n - f_n);
wire signed [15:0] delta_f_ne   = multiply(omega, f_eq_ne - f_ne);
wire signed [15:0] delta_f_e    = multiply(omega, f_eq_e - f_e);
wire signed [15:0] delta_f_se   = multiply(omega, f_eq_se - f_se);
wire signed [15:0] delta_f_s    = multiply(omega, f_eq_s - f_s);
wire signed [15:0] delta_f_sw   = multiply(omega, f_eq_sw - f_sw);
wire signed [15:0] delta_f_w    = multiply(omega, f_eq_w - f_w);
wire signed [15:0] delta_f_nw   = multiply(omega, f_eq_nw - f_nw);

// Final updated values (Q3.13 -> Q3.13)
assign f_new_n    = f_n    + delta_f_n;
assign f_new_ne   = f_ne   + delta_f_ne;
assign f_new_e    = f_e    + delta_f_e;
assign f_new_se   = f_se   + delta_f_se;
assign f_new_s    = f_s    + delta_f_s;
assign f_new_sw   = f_sw   + delta_f_sw;
assign f_new_w    = f_w    + delta_f_w;
assign f_new_nw   = f_nw   + delta_f_nw;
assign f_new_null = rho - (f_new_n  + f_new_ne + f_new_e + f_new_se + f_new_s + f_new_sw + f_new_w + f_new_nw);

endmodule
