module colliderPipelined (
    input  wire clk,
    input  wire rst,

    input  wire signed [15:0] omega,

    input  wire signed [15:0] f_null, f_n, f_ne, f_e, f_se, f_s, f_sw, f_w, f_nw,

    output reg [15:0] f_new_null, f_new_n, f_new_ne, f_new_e, f_new_se,
                       f_new_s, f_new_sw, f_new_w, f_new_nw,

    output wire collider_busy,
    output wire newval_ready,
    output wire axi_ready,

    output reg [15:0] u_x, u_y, rho
);

// ----------------------------------------------------------------------------------
// Constants (Q3.13 Fixed-Point)
// ----------------------------------------------------------------------------------

wire signed [15:0] w_null        = 16'h0e39; // 4/9
wire signed [15:0] w_side        = 16'h038e; // 1/9
wire signed [15:0] w_diag        = 16'h00e4; // 1/36

wire signed [15:0] one           = 16'h2000; // 1.0
wire signed [15:0] three         = 16'h6000; // 3.0
wire signed [15:0] three_halves  = 16'h3000; // 3/2
wire signed [15:0] nine_quarters = 16'h4800; // 9/4

assign collider_busy = 1'b0;
assign newval_ready  = 1'b1;
assign axi_ready     = 1'b1;

// ------------------------
// Stage 0: Input Latch
// ------------------------
reg signed [15:0] omega_s0;
reg signed [15:0] f_null_s0, f_n_s0, f_ne_s0, f_e_s0, f_se_s0;
reg signed [15:0] f_s_s0, f_sw_s0, f_w_s0, f_nw_s0;

always @(posedge clk or posedge rst) begin
    if (rst) begin
        omega_s0 <= 0;
        f_null_s0 <= 0; f_n_s0 <= 0; f_ne_s0 <= 0; f_e_s0 <= 0;
        f_se_s0   <= 0; f_s_s0 <= 0; f_sw_s0 <= 0; f_w_s0 <= 0; f_nw_s0 <= 0;
    end else begin
        omega_s0 <= omega;
        f_null_s0 <= f_null; f_n_s0 <= f_n; f_ne_s0 <= f_ne; f_e_s0 <= f_e;
        f_se_s0   <= f_se;   f_s_s0 <= f_s; f_sw_s0 <= f_sw; f_w_s0 <= f_w; f_nw_s0 <= f_nw;
    end
end

// ------------------------
// Stage 1: Compute rho, rho*u
// ------------------------
reg signed [15:0] omega_s1;
reg signed [15:0] f_null_s1, f_n_s1, f_ne_s1, f_e_s1, f_se_s1;
reg signed [15:0] f_s_s1, f_sw_s1, f_w_s1, f_nw_s1;
reg signed [15:0] rho_s1;

reg signed [31:0] rho_u_x_s1, rho_u_y_s1;

always @(posedge clk or posedge rst) begin
    if (rst) begin
        rho_s1 <= 0;
        rho_u_x_s1 <= 0;
        rho_u_y_s1 <= 0;
    end else begin
        omega_s1 <= omega_s0;

        // Propagate input f_i values to stage 1
        f_null_s1 <= f_null_s0; f_n_s1 <= f_n_s0; f_ne_s1 <= f_ne_s0; f_e_s1 <= f_e_s0;
        f_se_s1   <= f_se_s0;   f_s_s1 <= f_s_s0; f_sw_s1 <= f_sw_s0; f_w_s1 <= f_w_s0; f_nw_s1 <= f_nw_s0;

        // Compute rho
        rho_s1 <= f_null_s0 + f_n_s0 + f_ne_s0 + f_e_s0 + f_se_s0 +
                  f_s_s0   + f_sw_s0 + f_w_s0  + f_nw_s0;

        // Compute rho * u
        rho_u_x_s1 <= (f_e_s0 - f_w_s0 + f_ne_s0 - f_sw_s0 - f_nw_s0 + f_se_s0) <<< 13;
        rho_u_y_s1 <= (f_n_s0 - f_s_s0 + f_ne_s0 - f_sw_s0 + f_nw_s0 - f_se_s0) <<< 13;
    end
end

// ------------------------
// Stage 2: Compute u_x, u_y
// ------------------------
reg signed [15:0] omega_s2, rho_s2;
reg signed [15:0] f_null_s2, f_n_s2, f_ne_s2, f_e_s2, f_se_s2;
reg signed [15:0] f_s_s2, f_sw_s2, f_w_s2, f_nw_s2;


reg signed [15:0] u_x_s2, u_y_s2;
always @(posedge clk or posedge rst) begin
    if (rst) begin
        u_x_s2 <= 0;
        u_y_s2 <= 0;
    end else begin
        omega_s2 <= omega_s1;
        f_null_s2 <= f_null_s1; f_n_s2 <= f_n_s1; f_ne_s2 <= f_ne_s1; f_e_s2 <= f_e_s1;
        f_se_s2   <= f_se_s1;   f_s_s2 <= f_s_s1; f_sw_s2 <= f_sw_s1; f_w_s2 <= f_w_s1; f_nw_s2 <= f_nw_s1;

        rho_s2 <= rho_s1;

        // Use Newton-Raphson or approx divider for better pipelining in real design
        u_x_s2 <= rho_u_x_s1 / rho_s1;
        u_y_s2 <= rho_u_y_s1 / rho_s1;
    end
end

// ------------------------
// Stage 3: Compute u^2_x_intermediate, u^2_y_intermediate
// ------------------------
reg signed [15:0] omega_s3, rho_s3, u_x_s3, u_y_s3;
reg signed [15:0] f_null_s3, f_n_s3, f_ne_s3, f_e_s3, f_se_s3;
reg signed [15:0] f_s_s3, f_sw_s3, f_w_s3, f_nw_s3;

reg signed [31:0] u_x_squared_intermediate_s3;
reg signed [31:0] u_y_squared_intermediate_s3;

always @(posedge clk or posedge rst) begin
    if (rst) begin
        u_x_squared_intermediate_s3 <= 0;
        u_y_squared_intermediate_s3 <= 0;
    end else begin
        omega_s3 <= omega_s2;
        f_null_s3 <= f_null_s2; f_n_s3 <= f_n_s2; f_ne_s3 <= f_ne_s2; f_e_s3 <= f_e_s2;
        f_se_s3   <= f_se_s2;   f_s_s3 <= f_s_s2; f_sw_s3 <= f_sw_s2; f_w_s3 <= f_w_s2; f_nw_s3 <= f_nw_s2;
        rho_s3 <= rho_s2;
        u_x_s3 <= u_x_s2;
        u_y_s3 <= u_y_s2;

        u_x_squared_intermediate_s3 <= u_x_s2 * u_x_s2;
        u_y_squared_intermediate_s3 <= u_y_s2 * u_y_s2;
    end
end

// ------------------------
// Stage 4: Compute u^2, u^2_x, u^2_y
// ------------------------
reg signed [15:0] omega_s4, rho_s4, u_x_s4, u_y_s4;
reg signed [15:0] f_null_s4, f_n_s4, f_ne_s4, f_e_s4, f_se_s4;
reg signed [15:0] f_s_s4, f_sw_s4, f_w_s4, f_nw_s4;

reg signed [15:0] u_squared_s4, u_x_squared_s4, u_y_squared_s4;

always @(posedge clk or posedge rst) begin
    if (rst) begin
        u_x_squared_s4 <= 0;
        u_y_squared_s4 <= 0;
        u_squared_s4 <= 0;
    end else begin
        omega_s4 <= omega_s3;
        f_null_s4 <= f_null_s3; f_n_s4 <= f_n_s3; f_ne_s4 <= f_ne_s3; f_e_s4 <= f_e_s3;
        f_se_s4   <= f_se_s3;   f_s_s4 <= f_s_s3; f_sw_s4 <= f_sw_s3; f_w_s4 <= f_w_s3; f_nw_s4 <= f_nw_s3;
        rho_s4 <= rho_s3;
        u_x_s4 <= u_x_s3;
        u_y_s4 <= u_y_s3;

        u_x_squared_s4 <= u_x_squared_intermediate_s3 >>> 13;
        u_y_squared_s4 <= u_y_squared_intermediate_s3 >>> 13;
        u_squared_s4 <= (u_x_squared_intermediate_s3 + u_y_squared_intermediate_s3) >>> 13;
    end
end

// ------------------------
// Stage 5: (3/2)u^2, 3u_x, 3u_y, (9/2)u^2_x, (9/2)u^2_y
// ------------------------
reg signed [15:0] omega_s5, rho_s5, u_x_s5, u_y_s5;
reg signed [15:0] f_null_s5, f_n_s5, f_ne_s5, f_e_s5, f_se_s5;
reg signed [15:0] f_s_s5, f_sw_s5, f_w_s5, f_nw_s5;

reg signed [31:0] three_halves_u_squared_intermediate_s5;
reg signed [31:0] three_u_x_intermediate_s5, three_u_y_intermediate_s5;
reg signed [31:0] nine_half_u_x_squared_intermediate_s5, nine_half_u_y_squared_intermediate_s5;
reg signed [15:0] x_plus_y_s5, x_minus_y_s5, neg_x_plus_y_s5, neg_x_minus_y_s5;

always @(posedge clk or posedge rst) begin
    if (rst) begin
        three_halves_u_squared_intermediate_s5 <= 0;
        three_u_x_intermediate_s5 <= 0;
        three_u_y_intermediate_s5 <= 0;
        nine_half_u_x_squared_intermediate_s5 <= 0;
        nine_half_u_y_squared_intermediate_s5 <= 0;

        x_plus_y_s5            <= 0;
        x_minus_y_s5           <= 0;
        neg_x_plus_y_s5        <= 0;
        neg_x_minus_y_s5       <= 0;
    end else begin
        omega_s5 <= omega_s4;
        f_null_s5 <= f_null_s4; f_n_s5 <= f_n_s4; f_ne_s5 <= f_ne_s4; f_e_s5 <= f_e_s4;
        f_se_s5   <= f_se_s4;   f_s_s5 <= f_s_s4; f_sw_s5 <= f_sw_s4; f_w_s5 <= f_w_s4; f_nw_s5 <= f_nw_s4;
        rho_s5   <= rho_s4;
        u_x_s5   <= u_x_s4;
        u_y_s5   <= u_y_s4;

        three_halves_u_squared_intermediate_s5 <= three_halves * u_squared_s4;
        three_u_x_intermediate_s5 <= three * u_x_s4;
        three_u_y_intermediate_s5 <= three * u_y_s4;
        nine_half_u_x_squared_intermediate_s5 <= nine_quarters * (u_x_squared_s4 <<< 1);
        nine_half_u_y_squared_intermediate_s5 <= nine_quarters * (u_y_squared_s4 <<< 1);

        x_plus_y_s5 <= (u_x_s4 + u_y_s4);
        x_minus_y_s5 <= (u_x_s4 - u_y_s4);
        neg_x_plus_y_s5 <= -(u_x_s4 + u_y_s4);
        neg_x_minus_y_s5 <= -(u_x_s4 - u_y_s4);
    end
end

// ------------------------
// Stage 6: Calculate Polynomial for null, n, s, e, w
// ------------------------
reg signed [15:0] omega_s6, rho_s6, u_x_s6, u_y_s6;
reg signed [15:0] f_null_s6, f_n_s6, f_ne_s6, f_e_s6, f_se_s6;
reg signed [15:0] f_s_s6, f_sw_s6, f_w_s6, f_nw_s6;
reg signed [31:0] three_halves_u_squared_intermediate_s6;

reg signed [15:0] polynomial_null_s6, polynomial_n_s6, polynomial_s_s6, polynomial_e_s6, polynomial_w_s6;
reg signed [31:0] three_x_plus_y_intermediate_s6, three_neg_x_plus_y_intermediate_s6, three_x_minus_y_intermediate_s6, three_neg_x_minus_y_intermediate_s6;
reg signed [31:0] x_plus_y_squared_intermediate_s6, x_minus_y_squared_intermediate_s6;

always @(posedge clk or posedge rst) begin
    if (rst) begin
        polynomial_null_s6                  <= 0;
        polynomial_n_s6                     <= 0;
        polynomial_s_s6                     <= 0;
        polynomial_e_s6                     <= 0;
        polynomial_w_s6                     <= 0;

        three_x_plus_y_intermediate_s6      <= 0;
        three_neg_x_plus_y_intermediate_s6  <= 0;
        three_x_minus_y_intermediate_s6     <= 0;
        three_neg_x_minus_y_intermediate_s6 <= 0;

        x_plus_y_squared_intermediate_s6    <= 0;
        x_minus_y_squared_intermediate_s6   <= 0;
    end else begin
        omega_s6 <= omega_s5;
        f_null_s6 <= f_null_s5; f_n_s6 <= f_n_s5; f_ne_s6 <= f_ne_s5; f_e_s6 <= f_e_s5;
        f_se_s6   <= f_se_s5;   f_s_s6 <= f_s_s5; f_sw_s6 <= f_sw_s5; f_w_s6 <= f_w_s5; f_nw_s6 <= f_nw_s5;
        rho_s6   <= rho_s5;
        u_x_s6   <= u_x_s5;
        u_y_s6   <= u_y_s5;
        three_halves_u_squared_intermediate_s6 <= three_halves_u_squared_intermediate_s5;

        polynomial_null_s6 <= one - (three_halves_u_squared_intermediate_s5 >>> 13);
        polynomial_n_s6 <= one + (three_u_y_intermediate_s5 >>> 13) + (nine_half_u_y_squared_intermediate_s5 >>> 13) - (three_halves_u_squared_intermediate_s5 >>> 13);
        polynomial_s_s6 <= one - (three_u_y_intermediate_s5 >>> 13) + (nine_half_u_y_squared_intermediate_s5 >>> 13) - (three_halves_u_squared_intermediate_s5 >>> 13);
        polynomial_e_s6 <= one + (three_u_x_intermediate_s5 >>> 13) + (nine_half_u_x_squared_intermediate_s5 >>> 13) - (three_halves_u_squared_intermediate_s5 >>> 13);
        polynomial_w_s6 <= one - (three_u_x_intermediate_s5 >>> 13) + (nine_half_u_x_squared_intermediate_s5 >>> 13) - (three_halves_u_squared_intermediate_s5 >>> 13);

        three_x_plus_y_intermediate_s6 <= three * x_plus_y_s5;
        three_neg_x_plus_y_intermediate_s6 <= three * neg_x_plus_y_s5;
        three_x_minus_y_intermediate_s6 <= three * x_minus_y_s5;
        three_neg_x_minus_y_intermediate_s6 <= three * neg_x_minus_y_s5;

        x_plus_y_squared_intermediate_s6 <= x_plus_y_s5 * x_plus_y_s5;
        x_minus_y_squared_intermediate_s6 <= x_minus_y_s5 * x_minus_y_s5;
    end
end

// ------------------------
// Stage 7: 
// ------------------------
reg signed [15:0] omega_s7, rho_s7, u_x_s7, u_y_s7;
reg signed [15:0] f_null_s7, f_n_s7, f_ne_s7, f_e_s7, f_se_s7;
reg signed [15:0] f_s_s7, f_sw_s7, f_w_s7, f_nw_s7;
reg signed [31:0] three_x_plus_y_intermediate_s7, three_halves_u_squared_intermediate_s7, three_neg_x_plus_y_intermediate_s7, three_neg_x_minus_y_intermediate_s7, three_x_minus_y_intermediate_s7;

reg signed [31:0] f_eq_null_intermediate_s7, f_eq_n_intermediate_s7, f_eq_s_intermediate_s7, f_eq_e_intermediate_s7, f_eq_w_intermediate_s7;
reg signed [31:0] nine_half_x_plus_y_squared_intermediate_s7, nine_half_x_minus_y_squared_intermediate_s7;
// reg signed [15:0] polynomial_null_s6, polynomial_n_s6, polynomial_s_s6, polynomial_e_s6, polynomial_w_s6;
// reg signed [31:0] three_x_plus_y_intermediate_s6, three_neg_x_plus_y_intermediate_s6, three_x_minus_y_intermediate_s6, three_neg_x_minus_y_intermediate_s6;
// reg signed [31:0] x_plus_y_squared_intermediate_s6, x_minus_y_squared_intermediate_s6;

always @(posedge clk or posedge rst) begin
    if (rst) begin
        f_eq_null_intermediate_s7 <= 0;
        f_eq_n_intermediate_s7    <= 0;
        f_eq_s_intermediate_s7    <= 0;
        f_eq_e_intermediate_s7    <= 0;
        f_eq_w_intermediate_s7    <= 0;

        nine_half_x_plus_y_squared_intermediate_s7  <= 0;
        nine_half_x_minus_y_squared_intermediate_s7 <= 0;
    end else begin
        omega_s7 <= omega_s6;
        f_null_s7 <= f_null_s6; f_n_s7 <= f_n_s6; f_ne_s7 <= f_ne_s6; f_e_s7 <= f_e_s6;
        f_se_s7   <= f_se_s6;   f_s_s7 <= f_s_s6; f_sw_s7 <= f_sw_s6; f_w_s7 <= f_w_s6; f_nw_s7 <= f_nw_s6;
        rho_s7   <= rho_s6;
        u_x_s7   <= u_x_s6;
        u_y_s7   <= u_y_s6;
        three_x_plus_y_intermediate_s7 <= three_x_plus_y_intermediate_s6;
        three_halves_u_squared_intermediate_s7 <= three_halves_u_squared_intermediate_s6;
        three_neg_x_plus_y_intermediate_s7 <= three_neg_x_plus_y_intermediate_s6;
        three_neg_x_minus_y_intermediate_s7 <= three_neg_x_minus_y_intermediate_s6;
        three_x_minus_y_intermediate_s7 <= three_x_minus_y_intermediate_s6;

        f_eq_null_intermediate_s7 <= w_null * polynomial_null_s6;
        f_eq_n_intermediate_s7 <= w_side * polynomial_n_s6;
        f_eq_s_intermediate_s7 <= w_side * polynomial_s_s6;
        f_eq_e_intermediate_s7 <= w_side * polynomial_e_s6;
        f_eq_w_intermediate_s7 <= w_side * polynomial_w_s6;

        nine_half_x_plus_y_squared_intermediate_s7 <= nine_quarters * (x_plus_y_squared_intermediate_s6 >>> 12);
        nine_half_x_minus_y_squared_intermediate_s7 <= nine_quarters * (x_minus_y_squared_intermediate_s6 >>> 12);

    end
end

// ------------------------
// Stage 8: 
// ------------------------
reg signed [15:0] omega_s8, rho_s8, u_x_s8, u_y_s8;
reg signed [15:0] f_null_s8, f_n_s8, f_ne_s8, f_e_s8, f_se_s8;
reg signed [15:0] f_s_s8, f_sw_s8, f_w_s8, f_nw_s8;
reg signed [31:0] f_eq_null_intermediate_s8, f_eq_n_intermediate_s8, f_eq_s_intermediate_s8, f_eq_e_intermediate_s8, f_eq_w_intermediate_s8;

reg signed [15:0] polynomial_ne_s8, polynomial_sw_s8, polynomial_nw_s8, polynomial_se_s8;

// reg signed [31:0] f_eq_null_intermediate_s7, f_eq_n_intermediate_s7, f_eq_s_intermediate_s7, f_eq_e_intermediate_s7, f_eq_w_intermediate_s7;
// reg signed [31:0] nine_half_x_plus_y_squared_intermediate_s7, nine_half_x_minus_y_squared_intermediate_s7;

always @(posedge clk or posedge rst) begin
    if (rst) begin
        polynomial_ne_s8 <= 0;
        polynomial_sw_s8 <= 0;
        polynomial_nw_s8 <= 0;
        polynomial_se_s8 <= 0;
    end else begin
        omega_s8 <= omega_s7;
        f_null_s8 <= f_null_s7; f_n_s8 <= f_n_s7; f_ne_s8 <= f_ne_s7; f_e_s8 <= f_e_s7;
        f_se_s8   <= f_se_s7;   f_s_s8 <= f_s_s7; f_sw_s8 <= f_sw_s7; f_w_s8 <= f_w_s7; f_nw_s8 <= f_nw_s7;
        rho_s8   <= rho_s7;
        u_x_s8   <= u_x_s7;
        u_y_s8   <= u_y_s7;
        f_eq_null_intermediate_s8 <= f_eq_null_intermediate_s7;
        f_eq_n_intermediate_s8 <= f_eq_n_intermediate_s7;
        f_eq_s_intermediate_s8 <= f_eq_s_intermediate_s7;
        f_eq_e_intermediate_s8 <= f_eq_e_intermediate_s7;
        f_eq_w_intermediate_s8 <= f_eq_w_intermediate_s7;

        polynomial_ne_s8 <= one + (three_x_plus_y_intermediate_s7 >>> 13) + (nine_half_x_plus_y_squared_intermediate_s7 >>> 13) - (three_halves_u_squared_intermediate_s7 >>> 13);
        polynomial_sw_s8 <= one + (three_neg_x_plus_y_intermediate_s7 >>> 13) + (nine_half_x_plus_y_squared_intermediate_s7 >>> 13) - (three_halves_u_squared_intermediate_s7 >>> 13);
        polynomial_nw_s8 <= one + (three_neg_x_minus_y_intermediate_s7 >>> 13) + (nine_half_x_minus_y_squared_intermediate_s7 >>> 13) - (three_halves_u_squared_intermediate_s7 >>> 13);
        polynomial_se_s8 <= one - (three_x_minus_y_intermediate_s7 >>> 13) + (nine_half_x_minus_y_squared_intermediate_s7 >>> 13) - (three_halves_u_squared_intermediate_s7 >>> 13);
    end
end

// ------------------------
// Stage 9: 
// ------------------------
reg signed [15:0] omega_s9, rho_s9, u_x_s9, u_y_s9;
reg signed [15:0] f_null_s9, f_n_s9, f_ne_s9, f_e_s9, f_se_s9;
reg signed [15:0] f_s_s9, f_sw_s9, f_w_s9, f_nw_s9;
reg signed [31:0] f_eq_null_intermediate_s9, f_eq_n_intermediate_s9, f_eq_s_intermediate_s9, f_eq_e_intermediate_s9, f_eq_w_intermediate_s9;

reg signed [31:0] f_eq_ne_intermediate_s9, f_eq_sw_intermediate_s9, f_eq_nw_intermediate_s9, f_eq_se_intermediate_s9;
// reg signed [15:0] polynomial_ne_s8, polynomial_sw_s8, polynomial_nw_s8, polynomial_se_s8;

always @(posedge clk or posedge rst) begin
    if (rst) begin
        f_eq_ne_intermediate_s9 <= 0;
        f_eq_sw_intermediate_s9 <= 0;
        f_eq_nw_intermediate_s9 <= 0;
        f_eq_se_intermediate_s9 <= 0;
    end else begin
        omega_s9 <= omega_s8;
        f_null_s9 <= f_null_s8; f_n_s9 <= f_n_s8; f_ne_s9 <= f_ne_s8; f_e_s9 <= f_e_s8;
        f_se_s9   <= f_se_s8;   f_s_s9 <= f_s_s8; f_sw_s9 <= f_sw_s8; f_w_s9 <= f_w_s8; f_nw_s9 <= f_nw_s8;
        rho_s9   <= rho_s8;
        u_x_s9   <= u_x_s8;
        u_y_s9   <= u_y_s8;
        f_eq_null_intermediate_s9 <= f_eq_null_intermediate_s8;
        f_eq_n_intermediate_s9    <= f_eq_n_intermediate_s8;
        f_eq_s_intermediate_s9    <= f_eq_s_intermediate_s8;
        f_eq_e_intermediate_s9    <= f_eq_e_intermediate_s8;
        f_eq_w_intermediate_s9    <= f_eq_w_intermediate_s8;


        f_eq_ne_intermediate_s9 <= w_diag * polynomial_ne_s8;
        f_eq_sw_intermediate_s9 <= w_diag * polynomial_sw_s8;
        f_eq_nw_intermediate_s9 <= w_diag * polynomial_nw_s8;
        f_eq_se_intermediate_s9 <= w_diag * polynomial_se_s8;
    end
end

// ------------------------
// Stage 10: 
// ------------------------
reg signed [15:0] omega_s10, rho_s10, u_x_s10, u_y_s10;
reg signed [15:0] f_null_s10, f_n_s10, f_ne_s10, f_e_s10, f_se_s10;
reg signed [15:0] f_s_s10, f_sw_s10, f_w_s10, f_nw_s10;
reg signed [31:0] delta_f_null_s10, delta_f_n_s10, delta_f_ne_s10, delta_f_e_s10, delta_f_se_s10, delta_f_s_s10, delta_f_sw_s10, delta_f_w_s10, delta_f_nw_s10;

//reg signed [31:0] f_eq_ne_intermediate_s9, f_eq_sw_intermediate_s9, f_eq_nw_intermediate_s9, f_eq_se_intermediate_s9;

always @(posedge clk or posedge rst) begin
    if (rst) begin
        delta_f_null_s10 <= 0;
        delta_f_n_s10    <= 0;
        delta_f_ne_s10   <= 0;
        delta_f_e_s10    <= 0;
        delta_f_se_s10   <= 0;
        delta_f_s_s10    <= 0;
        delta_f_sw_s10   <= 0;
        delta_f_w_s10    <= 0;
        delta_f_nw_s10   <= 0;

    end else begin
        f_null_s10 <= f_null_s9; f_n_s10 <= f_n_s9; f_ne_s10 <= f_ne_s9; f_e_s10 <= f_e_s9;
        f_se_s10   <= f_se_s9;   f_s_s10 <= f_s_s9; f_sw_s10 <= f_sw_s9; f_w_s10 <= f_w_s9; f_nw_s10 <= f_nw_s9;
        rho_s10   <= rho_s9;
        u_x_s10   <= u_x_s9;
        u_y_s10   <= u_y_s9;

        delta_f_null_s10 <= omega_s9 * (f_eq_null_intermediate_s9 - (f_null_s9 <<< 13));
        delta_f_n_s10    <= omega_s9 * (f_eq_n_intermediate_s9    - (f_n_s9    <<< 13));
        delta_f_ne_s10   <= omega_s9 * (f_eq_ne_intermediate_s9   - (f_ne_s9   <<< 13));
        delta_f_e_s10    <= omega_s9 * (f_eq_e_intermediate_s9    - (f_e_s9    <<< 13));
        delta_f_se_s10   <= omega_s9 * (f_eq_se_intermediate_s9   - (f_se_s9   <<< 13));
        delta_f_s_s10    <= omega_s9 * (f_eq_s_intermediate_s9    - (f_s_s9    <<< 13));
        delta_f_sw_s10   <= omega_s9 * (f_eq_sw_intermediate_s9   - (f_sw_s9   <<< 13));
        delta_f_w_s10    <= omega_s9 * (f_eq_w_intermediate_s9    - (f_w_s9    <<< 13));
        delta_f_nw_s10   <= omega_s9 * (f_eq_nw_intermediate_s9   - (f_nw_s9   <<< 13));

    end
end

// ------------------------
// Stage 11: 
// ------------------------
always @(posedge clk or posedge rst) begin
    if (rst) begin
        f_new_null <= 0;
        f_new_n    <= 0;
        f_new_ne   <= 0;
        f_new_e    <= 0;
        f_new_se   <= 0;
        f_new_s    <= 0;
        f_new_sw   <= 0;
        f_new_w    <= 0;
        f_new_nw   <= 0;
    end else begin
        u_x <= u_x_s10;
        u_y   <= u_y_s10;
        rho <= rho_s10;
        f_new_null <= f_null_s10 + (delta_f_null_s10 >>> 13);
        f_new_n    <= f_n_s10    + (delta_f_n_s10    >>> 13);
        f_new_ne   <= f_ne_s10   + (delta_f_ne_s10   >>> 13);
        f_new_e    <= f_e_s10    + (delta_f_e_s10    >>> 13);
        f_new_se   <= f_se_s10   + (delta_f_se_s10   >>> 13);
        f_new_s    <= f_s_s10    + (delta_f_s_s10    >>> 13);
        f_new_sw   <= f_sw_s10   + (delta_f_sw_s10   >>> 13);
        f_new_w    <= f_w_s10    + (delta_f_w_s10    >>> 13);
        f_new_nw   <= f_nw_s10   + (delta_f_nw_s10   >>> 13);

    end
end

endmodule
