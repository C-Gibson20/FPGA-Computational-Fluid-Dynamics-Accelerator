`define DECLARE(stage) \
    reg signed [15:0] omega_``stage``, rho_``stage``, u_x_``stage``, u_y_``stage``, u_squared_``stage``; \
    reg signed [15:0] f_null_``stage``, f_n_``stage``, f_ne_``stage``, f_e_``stage``, f_se_``stage``; \
    reg signed [15:0] f_s_``stage``, f_sw_``stage``, f_w_``stage``, f_nw_``stage``;


`define PIPE(src, dst) \
    omega_``dst`` <= omega_``src``; \
    rho_``dst`` <= rho_``src``;     \
    u_x_``dst`` <= u_x_``src``;     \
    u_y_``dst`` <= u_y_``src``;     \
    u_squared_``dst`` <= u_squared_``src``; \
    f_null_``dst`` <= f_null_``src``; \
    f_n_``dst``    <= f_n_``src``;    \
    f_ne_``dst``   <= f_ne_``src``;   \
    f_e_``dst``    <= f_e_``src``;    \
    f_se_``dst``   <= f_se_``src``;   \
    f_s_``dst``    <= f_s_``src``;    \
    f_sw_``dst``   <= f_sw_``src``;   \
    f_w_``dst``    <= f_w_``src``;    \
    f_nw_``dst``   <= f_nw_``src``;

`define RESET(stage) \
    omega_``stage`` <= 0; \
    rho_``stage`` <= 0; \
    u_x_``stage`` <= 0; \
    u_y_``stage`` <= 0; \
    u_squared_``stage`` <= 0; \
    f_null_``stage`` <= 0; \
    f_n_``stage`` <= 0; \
    f_ne_``stage`` <= 0; \
    f_e_``stage`` <= 0; \
    f_se_``stage`` <= 0; \
    f_s_``stage`` <= 0; \
    f_sw_``stage`` <= 0; \
    f_w_``stage`` <= 0; \
    f_nw_``stage`` <= 0;

module collider(
    input  wire clk,
    input  wire rst,

    input  wire signed [15:0] omega, // 1/tau
    input  wire signed [15:0] f_null, f_n, f_ne, f_e, f_se, f_s, f_sw, f_w, f_nw,

    output reg signed [15:0] f_new_null, f_new_n, f_new_ne, f_new_e, f_new_se, f_new_s, f_new_sw, f_new_w, f_new_nw,
    output reg signed [15:0] u_x, u_y, rho, u_squared,
    output wire collider_busy,
    output wire newval_ready
);

assign collider_busy = 1'b0;
assign newval_ready  = 1'b1;

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

// ------------------------
// Stage 0: Input Latch
// ------------------------
`DECLARE(s0)

always @(posedge clk or negedge rst) begin
    if (!rst) begin
        `RESET(s0)
    end else begin
        omega_s0 <= omega; rho_s0 <=0; u_x_s0 <=0; u_y_s0 <=0; u_squared_s0 <=0;
        f_null_s0 <= f_null; f_n_s0 <= f_n; f_ne_s0 <= f_ne; f_e_s0 <= f_e;
        f_se_s0   <= f_se;   f_s_s0 <= f_s; f_sw_s0 <= f_sw; f_w_s0 <= f_w; f_nw_s0 <= f_nw;
    end
end

// ------------------------
// Stage 1: Compute rho, rho*u
// ------------------------
`DECLARE(s1)

reg signed [15:0] rho_u_x_s1, rho_u_y_s1;

always @(posedge clk or negedge rst) begin
    if (!rst) begin
        `RESET(s1)
    end else begin
        `PIPE(s0, s1)

        // Compute rho
        rho_s1 <= f_null_s0 + f_n_s0 + f_ne_s0 + f_e_s0 + f_se_s0 +
                  f_s_s0   + f_sw_s0 + f_w_s0  + f_nw_s0;

        // Compute rho * u
        rho_u_x_s1 <= f_e_s0 - f_w_s0 + f_ne_s0 - f_sw_s0 - f_nw_s0 + f_se_s0;
        rho_u_y_s1 <= f_n_s0 - f_s_s0 + f_ne_s0 - f_sw_s0 + f_nw_s0 - f_se_s0;
    end
end

// ------------------------
// Stage 2:
// ------------------------
`DECLARE(s2)
reg signed [15:0] rho_u_x_s2, rho_u_y_s2;

reg signed [31:0] rho_x1_product_s2;
always @(posedge clk or negedge rst) begin
    if (!rst) begin
        `RESET(s2)
    end else begin
        `PIPE(s1, s2)

        rho_u_x_s2 <= rho_u_x_s1;
        rho_u_y_s2 <= rho_u_y_s1;

        rho_x1_product_s2 <= rho_s1 * (two - rho_s1) + round;
    end
end

// ------------------------
// Stage 3:
// ------------------------
`DECLARE(s3)
reg signed [15:0] rho_u_x_s3, rho_u_y_s3;
reg signed [31:0] rho_x1_product_s3;

reg signed [15:0] rho_x1_shifted_s3;

always @(posedge clk or negedge rst) begin
    if (!rst) begin
        `RESET(s3)
        rho_x1_product_s3 <= 0;
    end else begin
        `PIPE(s2, s3)
        rho_x1_product_s3 <= rho_x1_product_s2;
        rho_u_x_s3 <= rho_u_x_s2;
        rho_u_y_s3 <= rho_u_y_s2;

        rho_x1_shifted_s3 <= rho_x1_product_s2 >>> 13;
    end
end

// ------------------------
// Stage 4:
// ------------------------
`DECLARE(s4)
reg signed [15:0] rho_u_x_s4, rho_u_y_s4;
reg signed [15:0] rho_x1_s4;

always @(posedge clk or negedge rst) begin
    if (!rst) begin
        `RESET(s4)
    end else begin
        `PIPE(s3, s4)
        rho_u_x_s4 <= rho_u_x_s3;
        rho_u_y_s4 <= rho_u_y_s3;

        rho_x1_s4 <= (rho_x1_product_s3 > 32'sh10000000) ? 16'sh7FFF :
                     (rho_x1_product_s3 < 32'shf0000000) ? 16'sh8000 :
                     rho_x1_shifted_s3;
    end
end

// ------------------------
// Stage 5:
// ------------------------
`DECLARE(s5)
reg signed [15:0] rho_u_x_s5, rho_u_y_s5;
reg signed [31:0] x2_product_s5;

always @(posedge clk or negedge rst) begin
    if (!rst) begin
        `RESET(s5)
    end else begin
        `PIPE(s4, s5)
        rho_u_x_s5 <= rho_u_x_s4;
        rho_u_y_s5 <= rho_u_y_s4;

        x2_product_s5 <= ((two - rho_s4) * (two - rho_x1_s4)) + round;
    end
end

// ------------------------
// Stage 6:
// ------------------------
`DECLARE(s6)
reg signed [31:0] x2_product_s6;
reg signed [15:0] rho_u_x_s6, rho_u_y_s6;

reg signed [15:0] x2_shifted_s6;

always @(posedge clk or negedge rst) begin
    if (!rst) begin
        `RESET(s6)
    end else begin
        `PIPE(s5, s6)
        x2_product_s6 <= x2_product_s5;
        rho_u_x_s6 <= rho_u_x_s5;
        rho_u_y_s6 <= rho_u_y_s5;

        x2_shifted_s6 <= x2_product_s5 >>> 13;
    end
end

// ------------------------
// Stage 7:
// ------------------------
`DECLARE(s7)
reg signed [15:0] x2_s7;
reg signed [15:0] rho_u_x_s7, rho_u_y_s7;

always @(posedge clk or negedge rst) begin
    if (!rst) begin
        `RESET(s7)
    end else begin
        `PIPE(s6, s7)
        rho_u_x_s7 <= rho_u_x_s6;
        rho_u_y_s7 <= rho_u_y_s6;

        x2_s7 <= (x2_product_s6 > 32'sh10000000) ? 16'sh7FFF :
                 (x2_product_s6 < 32'shf0000000) ? 16'sh8000 :
                 x2_shifted_s6;
    end
end

// ------------------------
// Stage 8:
// ------------------------
`DECLARE(s8)
reg signed [15:0] x2_s8;
reg signed [15:0] rho_u_x_s8, rho_u_y_s8;

reg signed [31:0] rho_x2_product_s8;

always @(posedge clk or negedge rst) begin
    if (!rst) begin
        `RESET(s8)
    end else begin
        `PIPE(s7, s8)
        x2_s8 <= x2_s7;
        rho_u_x_s8 <= rho_u_x_s7;
        rho_u_y_s8 <= rho_u_y_s7;

        rho_x2_product_s8 <= (rho_s7 * x2_s7) + round;
    end
end

// ------------------------
// Stage 9:
// ------------------------
`DECLARE(s9)
reg signed [31:0] rho_x2_product_s9;
reg signed [15:0] x2_s9;
reg signed [15:0] rho_u_x_s9, rho_u_y_s9;

reg signed [15:0] rho_x2_shifted_s9;

always @(posedge clk or negedge rst) begin
    if (!rst) begin
        `RESET(s9)
    end else begin
        `PIPE(s8, s9)
        rho_x2_product_s9 <= rho_x2_product_s8;
        x2_s9 <= x2_s8;
        rho_u_x_s9 <= rho_u_x_s8;
        rho_u_y_s9 <= rho_u_y_s8;

        rho_x2_shifted_s9 <= rho_x2_product_s8 >>> 13;
    end
end

// ------------------------
// Stage 10:
// ------------------------
`DECLARE(s10)
reg signed [15:0] rho_x2_s10;
reg signed [15:0] x2_s10;
reg signed [15:0] rho_u_x_s10, rho_u_y_s10;

always @(posedge clk or negedge rst) begin
    if (!rst) begin
        `RESET(s10)
    end else begin
        `PIPE(s9, s10)
        x2_s10 <= x2_s9;
        rho_u_x_s10 <= rho_u_x_s9;
        rho_u_y_s10 <= rho_u_y_s9;

        rho_x2_s10 <= (rho_x2_product_s9 > 32'sh10000000) ? 16'sh7FFF :
                      (rho_x2_product_s9 < 32'shf0000000) ? 16'sh8000 :
                      rho_x2_shifted_s9;
    end
end


// ------------------------
// Stage 11:
// ------------------------
`DECLARE(s11)
reg signed [15:0] rho_u_x_s11, rho_u_y_s11;

reg signed [31:0] x3_product_s11;

always @(posedge clk or negedge rst) begin
    if (!rst) begin
        `RESET(s11)
    end else begin
        `PIPE(s10, s11)
        rho_u_x_s11 <= rho_u_x_s10;
        rho_u_y_s11 <= rho_u_y_s10;

        x3_product_s11 <= (x2_s10 * (two - rho_x2_s10)) + round;
    end
end

// ------------------------
// Stage 12:
// ------------------------
`DECLARE(s12)
reg signed [31:0] x3_product_s12;
reg signed [15:0] rho_u_x_s12, rho_u_y_s12;

reg signed [15:0] x3_shifted_s12;

always @(posedge clk or negedge rst) begin
    if (!rst) begin
        `RESET(s12)
    end else begin
        `PIPE(s11, s12)
        x3_product_s12 <= x3_product_s11;
        rho_u_x_s12 <= rho_u_x_s11;
        rho_u_y_s12 <= rho_u_y_s11;

        x3_shifted_s12 <= x3_product_s11 >>> 13;
    end
end

// ------------------------
// Stage 13:
// ------------------------
`DECLARE(s13)
reg signed [15:0] rho_u_x_s13, rho_u_y_s13;

reg signed [15:0] x3_s13;

always @(posedge clk or negedge rst) begin
    if (!rst) begin
        `RESET(s13)
    end else begin
        `PIPE(s12, s13)
        rho_u_x_s13 <= rho_u_x_s12;
        rho_u_y_s13 <= rho_u_y_s12;

        x3_s13 <= (x3_product_s12 > 32'sh10000000) ? 16'sh7FFF :
             (x3_product_s12 < 32'shf0000000) ? 16'sh8000 :
             x3_shifted_s12;
    end
end

// ------------------------
// Stage 14:
// ------------------------
`DECLARE(s14)

reg signed [31:0] u_x_product_s14, u_y_product_s14;

always @(posedge clk or negedge rst) begin
    if (!rst) begin
        `RESET(s14)
    end else begin
        `PIPE(s13, s14)

        u_x_product_s14 <= (rho_u_x_s13 * x3_s13) + round;
        u_y_product_s14 <= (rho_u_y_s13 * x3_s13) + round;
    end
end

// ------------------------
// Stage 15:
// ------------------------
`DECLARE(s15)
reg signed [31:0] u_x_product_s15, u_y_product_s15;

reg signed [15:0] u_x_shifted_s15, u_y_shifted_s15;

always @(posedge clk or negedge rst) begin
    if (!rst) begin
        `RESET(s15)
    end else begin
        `PIPE(s14, s15)
        u_x_product_s15 <= u_x_product_s14;
        u_y_product_s15 <= u_y_product_s14;

        u_x_shifted_s15 <= u_x_product_s14 >>> 13;
        u_y_shifted_s15 <= u_y_product_s14 >>> 13;
    end
end

// ------------------------
// Stage 16:
// ------------------------
`DECLARE(s16)

always @(posedge clk or negedge rst) begin
    if (!rst) begin
        `RESET(s16)
    end else begin
        `PIPE(s15, s16)
        u_x_s16 <= (u_x_product_s15 > 32'sh10000000) ? 16'sh7FFF :
                   (u_x_product_s15 < 32'shf0000000) ? 16'sh8000 :
                   u_x_shifted_s15;
        u_y_s16 <= (u_y_product_s15 > 32'sh10000000) ? 16'sh7FFF :
                   (u_y_product_s15 < 32'shf0000000) ? 16'sh8000 :
                   u_y_shifted_s15;
    end
end

// ------------------------
// Stage 17:
// ------------------------
`DECLARE(s17)

reg signed [31:0] u_x_squared_product_s17, u_y_squared_product_s17, x_plus_y_squared_product_s17, x_minus_y_squared_product_s17;

always @(posedge clk or negedge rst) begin
    if (!rst) begin
        `RESET(s17)
    end else begin
        `PIPE(s16, s17)

        u_x_squared_product_s17 <= (u_x_s16 * u_x_s16) + round;
        u_y_squared_product_s17 <= (u_y_s16 * u_y_s16) + round;
        x_plus_y_squared_product_s17 <= ((u_x_s16 + u_y_s16) * (u_x_s16 + u_y_s16)) + round;
        x_minus_y_squared_product_s17 <= ((u_x_s16 - u_y_s16) * (u_x_s16 - u_y_s16)) + round;
    end
end

// ------------------------
// Stage 18:
// ------------------------
`DECLARE(s18)

reg signed [31:0] u_x_squared_product_s18, u_y_squared_product_s18, x_plus_y_squared_product_s18, x_minus_y_squared_product_s18;
reg signed [15:0] u_x_squared_shifted_s18, u_y_squared_shifted_s18, x_plus_y_squared_shifted_s18, x_minus_y_squared_shifted_s18;

always @(posedge clk or negedge rst) begin
    if (!rst) begin
        `RESET(s18)
    end else begin
        `PIPE(s17, s18)

        u_x_squared_product_s18        <= u_x_squared_product_s17;
        u_y_squared_product_s18        <= u_y_squared_product_s17;
        x_plus_y_squared_product_s18   <= x_plus_y_squared_product_s17;
        x_minus_y_squared_product_s18  <= x_minus_y_squared_product_s17;

        u_x_squared_shifted_s18        <= u_x_squared_product_s17 >>> 13;
        u_y_squared_shifted_s18        <= u_y_squared_product_s17 >>> 13;
        x_plus_y_squared_shifted_s18   <= x_plus_y_squared_product_s17 >>> 13;
        x_minus_y_squared_shifted_s18  <= x_minus_y_squared_product_s17 >>> 13;
    end
end

// ------------------------
// Stage 19:
// ------------------------
`DECLARE(s19)

reg signed [15:0] u_x_squared_s19, u_y_squared_s19, x_plus_y_squared_s19, x_minus_y_squared_s19;

always @(posedge clk or negedge rst) begin
    if (!rst) begin
        `RESET(s19)
    end else begin
        `PIPE(s18, s19)

        u_x_squared_s19 <= (u_x_squared_product_s18 > 32'sh10000000) ? 16'sh7FFF :
                        (u_x_squared_product_s18 < 32'shf0000000) ? 16'sh8000 :
                        u_x_squared_shifted_s18;

        u_y_squared_s19 <= (u_y_squared_product_s18 > 32'sh10000000) ? 16'sh7FFF :
                        (u_y_squared_product_s18 < 32'shf0000000) ? 16'sh8000 :
                        u_y_squared_shifted_s18;

        x_plus_y_squared_s19 <= (x_plus_y_squared_product_s18 > 32'sh10000000) ? 16'sh7FFF :
                                (x_plus_y_squared_product_s18 < 32'shf0000000) ? 16'sh8000 :
                                x_plus_y_squared_shifted_s18;

        x_minus_y_squared_s19 <= (x_minus_y_squared_product_s18 > 32'sh10000000) ? 16'sh7FFF :
                                (x_minus_y_squared_product_s18 < 32'shf0000000) ? 16'sh8000 :
                                x_minus_y_squared_shifted_s18;

    end
end

// ------------------------
// Stage 20:
// ------------------------
`DECLARE(s20)

reg signed [15:0] x_plus_y_s20, x_minus_y_s20, neg_x_plus_y_s20, neg_x_minus_y_s20;
reg signed [15:0] x_plus_y_squared_s20, x_minus_y_squared_s20, u_x_squared_s20, u_y_squared_s20;

always @(posedge clk or negedge rst) begin
    if (!rst) begin
        `RESET(s20)
    end else begin
        `PIPE(s19, s20)

        u_x_squared_s20        <= u_x_squared_s19;
        u_y_squared_s20        <= u_y_squared_s19;
        x_plus_y_squared_s20   <= x_plus_y_squared_s19;
        x_minus_y_squared_s20  <= x_minus_y_squared_s19;
        u_squared_s20          <= u_x_squared_s19 + u_y_squared_s19;

        x_plus_y_s20           <= u_x_s19 + u_y_s19;
        x_minus_y_s20          <= u_x_s19 - u_y_s19;
        neg_x_plus_y_s20       <= -(u_x_s19 + u_y_s19);
        neg_x_minus_y_s20      <= -(u_x_s19 - u_y_s19);
    end
end

// ------------------------
// Stage 21:
// ------------------------
`DECLARE(s21)

reg signed [31:0] three_halves_u_squared_product_s21, three_u_x_product_s21, three_u_y_product_s21, nine_half_u_x_squared_product_s21, nine_half_u_y_squared_product_s21, three_x_plus_y_product_s21, three_neg_x_plus_y_product_s21, three_x_minus_y_product_s21, three_neg_x_minus_y_product_s21, nine_half_x_plus_y_squared_product_s21, nine_half_x_minus_y_squared_product_s21;

always @(posedge clk or negedge rst) begin
    if (!rst) begin
        `RESET(s21)
    end else begin
        `PIPE(s20, s21)

        three_halves_u_squared_product_s21     <= (three_halves * u_squared_s20) + round;
        three_u_x_product_s21                  <= (three * u_x_s20) + round;
        three_u_y_product_s21                  <= (three * u_y_s20) + round;
        nine_half_u_x_squared_product_s21      <= (nine_quarters * (u_x_squared_s20 <<< 1)) + round;
        nine_half_u_y_squared_product_s21      <= (nine_quarters * (u_y_squared_s20 <<< 1)) + round;
        three_x_plus_y_product_s21             <= (three * x_plus_y_s20) + round;
        three_neg_x_plus_y_product_s21         <= (three * neg_x_plus_y_s20) + round;
        three_x_minus_y_product_s21            <= (three * x_minus_y_s20) + round;
        three_neg_x_minus_y_product_s21        <= (three * neg_x_minus_y_s20) + round;
        nine_half_x_plus_y_squared_product_s21 <= (nine_quarters * (x_plus_y_squared_s20 <<< 1)) + round;
        nine_half_x_minus_y_squared_product_s21<= (nine_quarters * (x_minus_y_squared_s20 <<< 1)) + round;
    end
end

// ------------------------
// Stage 22:
// ------------------------
`DECLARE(s22)

reg signed [31:0] three_halves_u_squared_product_s22, three_u_x_product_s22, three_u_y_product_s22, nine_half_u_x_squared_product_s22, nine_half_u_y_squared_product_s22, three_x_plus_y_product_s22, three_neg_x_plus_y_product_s22, three_x_minus_y_product_s22, three_neg_x_minus_y_product_s22, nine_half_x_plus_y_squared_product_s22, nine_half_x_minus_y_squared_product_s22;

reg signed [15:0] three_halves_u_squared_shifted_s22, three_u_x_shifted_s22, three_u_y_shifted_s22, nine_half_u_x_squared_shifted_s22, nine_half_u_y_squared_shifted_s22, three_x_plus_y_shifted_s22, three_neg_x_plus_y_shifted_s22, three_x_minus_y_shifted_s22, three_neg_x_minus_y_shifted_s22, nine_half_x_plus_y_squared_shifted_s22, nine_half_x_minus_y_squared_shifted_s22;

always @(posedge clk or negedge rst) begin
    if (!rst) begin
        `RESET(s22)
    end else begin
        `PIPE(s21, s22)

        // Pipeline products
        three_halves_u_squared_product_s22     <= three_halves_u_squared_product_s21;
        three_u_x_product_s22                  <= three_u_x_product_s21;
        three_u_y_product_s22                  <= three_u_y_product_s21;
        nine_half_u_x_squared_product_s22      <= nine_half_u_x_squared_product_s21;
        nine_half_u_y_squared_product_s22      <= nine_half_u_y_squared_product_s21;
        three_x_plus_y_product_s22             <= three_x_plus_y_product_s21;
        three_neg_x_plus_y_product_s22         <= three_neg_x_plus_y_product_s21;
        three_x_minus_y_product_s22            <= three_x_minus_y_product_s21;
        three_neg_x_minus_y_product_s22        <= three_neg_x_minus_y_product_s21;
        nine_half_x_plus_y_squared_product_s22 <= nine_half_x_plus_y_squared_product_s21;
        nine_half_x_minus_y_squared_product_s22<= nine_half_x_minus_y_squared_product_s21;

        // Shifted versions
        three_halves_u_squared_shifted_s22     <= three_halves_u_squared_product_s21 >>> 13;
        three_u_x_shifted_s22                  <= three_u_x_product_s21 >>> 13;
        three_u_y_shifted_s22                  <= three_u_y_product_s21 >>> 13;
        nine_half_u_x_squared_shifted_s22      <= nine_half_u_x_squared_product_s21 >>> 13;
        nine_half_u_y_squared_shifted_s22      <= nine_half_u_y_squared_product_s21 >>> 13;
        three_x_plus_y_shifted_s22             <= three_x_plus_y_product_s21 >>> 13;
        three_neg_x_plus_y_shifted_s22         <= three_neg_x_plus_y_product_s21 >>> 13;
        three_x_minus_y_shifted_s22            <= three_x_minus_y_product_s21 >>> 13;
        three_neg_x_minus_y_shifted_s22        <= three_neg_x_minus_y_product_s21 >>> 13;
        nine_half_x_plus_y_squared_shifted_s22 <= nine_half_x_plus_y_squared_product_s21 >>> 13;
        nine_half_x_minus_y_squared_shifted_s22<= nine_half_x_minus_y_squared_product_s21 >>> 13;

    end
end


// ------------------------
// Stage 23:
// ------------------------
`DECLARE(s23)

reg signed [15:0] three_halves_u_squared_s23, three_u_x_s23, three_u_y_s23, nine_half_u_x_squared_s23, nine_half_u_y_squared_s23, three_x_plus_y_s23, three_neg_x_plus_y_s23, three_x_minus_y_s23, three_neg_x_minus_y_s23, nine_half_x_plus_y_squared_s23, nine_half_x_minus_y_squared_s23;

always @(posedge clk or negedge rst) begin
    if (!rst) begin
        `RESET(s23)
    end else begin
        `PIPE(s22, s23)

        three_halves_u_squared_s23 <= (three_halves_u_squared_product_s22 > 32'sh10000000) ? 16'sh7FFF :
                                      (three_halves_u_squared_product_s22 < 32'shf0000000) ? 16'sh8000 :
                                      three_halves_u_squared_shifted_s22;

        three_u_x_s23 <= (three_u_x_product_s22 > 32'sh10000000) ? 16'sh7FFF :
                         (three_u_x_product_s22 < 32'shf0000000) ? 16'sh8000 :
                         three_u_x_shifted_s22;

        three_u_y_s23 <= (three_u_y_product_s22 > 32'sh10000000) ? 16'sh7FFF :
                         (three_u_y_product_s22 < 32'shf0000000) ? 16'sh8000 :
                         three_u_y_shifted_s22;

        nine_half_u_x_squared_s23 <= (nine_half_u_x_squared_product_s22 > 32'sh10000000) ? 16'sh7FFF :
                                     (nine_half_u_x_squared_product_s22 < 32'shf0000000) ? 16'sh8000 :
                                     nine_half_u_x_squared_shifted_s22;

        nine_half_u_y_squared_s23 <= (nine_half_u_y_squared_product_s22 > 32'sh10000000) ? 16'sh7FFF :
                                     (nine_half_u_y_squared_product_s22 < 32'shf0000000) ? 16'sh8000 :
                                     nine_half_u_y_squared_shifted_s22;

        three_x_plus_y_s23 <= (three_x_plus_y_product_s22 > 32'sh10000000) ? 16'sh7FFF :
                              (three_x_plus_y_product_s22 < 32'shf0000000) ? 16'sh8000 :
                              three_x_plus_y_shifted_s22;

        three_neg_x_plus_y_s23 <= (three_neg_x_plus_y_product_s22 > 32'sh10000000) ? 16'sh7FFF :
                                  (three_neg_x_plus_y_product_s22 < 32'shf0000000) ? 16'sh8000 :
                                  three_neg_x_plus_y_shifted_s22;

        three_x_minus_y_s23 <= (three_x_minus_y_product_s22 > 32'sh10000000) ? 16'sh7FFF :
                               (three_x_minus_y_product_s22 < 32'shf0000000) ? 16'sh8000 :
                               three_x_minus_y_shifted_s22;

        three_neg_x_minus_y_s23 <= (three_neg_x_minus_y_product_s22 > 32'sh10000000) ? 16'sh7FFF :
                                   (three_neg_x_minus_y_product_s22 < 32'shf0000000) ? 16'sh8000 :
                                   three_neg_x_minus_y_shifted_s22;

        nine_half_x_plus_y_squared_s23 <= (nine_half_x_plus_y_squared_product_s22 > 32'sh10000000) ? 16'sh7FFF :
                                          (nine_half_x_plus_y_squared_product_s22 < 32'shf0000000) ? 16'sh8000 :
                                          nine_half_x_plus_y_squared_shifted_s22;

        nine_half_x_minus_y_squared_s23 <= (nine_half_x_minus_y_squared_product_s22 > 32'sh10000000) ? 16'sh7FFF :
                                           (nine_half_x_minus_y_squared_product_s22 < 32'shf0000000) ? 16'sh8000 :
                                           nine_half_x_minus_y_squared_shifted_s22;

    end
end

// ------------------------
// Stage 24:
// ------------------------
`DECLARE(s24)

reg signed [15:0] polynomial_n_s24, polynomial_s_s24, polynomial_e_s24, polynomial_w_s24;
reg signed [15:0] polynomial_ne_s24, polynomial_sw_s24, polynomial_nw_s24, polynomial_se_s24;

always @(posedge clk or negedge rst) begin
    if (!rst) begin
        `RESET(s24)
    end else begin
        `PIPE(s23, s24)

        polynomial_n_s24  <= one + three_u_y_s23         + nine_half_u_y_squared_s23         - three_halves_u_squared_s23;
        polynomial_s_s24  <= one - three_u_y_s23         + nine_half_u_y_squared_s23         - three_halves_u_squared_s23;
        polynomial_e_s24  <= one + three_u_x_s23         + nine_half_u_x_squared_s23         - three_halves_u_squared_s23;
        polynomial_w_s24  <= one - three_u_x_s23         + nine_half_u_x_squared_s23         - three_halves_u_squared_s23;
        polynomial_ne_s24 <= one + three_x_plus_y_s23    + nine_half_x_plus_y_squared_s23    - three_halves_u_squared_s23;
        polynomial_sw_s24 <= one + three_neg_x_plus_y_s23+ nine_half_x_plus_y_squared_s23    - three_halves_u_squared_s23;
        polynomial_nw_s24 <= one + three_neg_x_minus_y_s23+ nine_half_x_minus_y_squared_s23  - three_halves_u_squared_s23;
        polynomial_se_s24 <= one + three_x_minus_y_s23   + nine_half_x_minus_y_squared_s23   - three_halves_u_squared_s23;
    end
end

// ------------------------
// Stage 25:
// ------------------------
`DECLARE(s25)

reg signed [31:0] f_eq_n_intermediate_product_s25, f_eq_s_intermediate_product_s25, f_eq_e_intermediate_product_s25, f_eq_w_intermediate_product_s25;
reg signed [31:0] f_eq_ne_intermediate_product_s25, f_eq_sw_intermediate_product_s25, f_eq_nw_intermediate_product_s25, f_eq_se_intermediate_product_s25;

always @(posedge clk or negedge rst) begin
    if (!rst) begin
        `RESET(s25)
    end else begin
        `PIPE(s24, s25)

        f_eq_n_intermediate_product_s25  <= (w_side * polynomial_n_s24)  + round;
        f_eq_s_intermediate_product_s25  <= (w_side * polynomial_s_s24)  + round;
        f_eq_e_intermediate_product_s25  <= (w_side * polynomial_e_s24)  + round;
        f_eq_w_intermediate_product_s25  <= (w_side * polynomial_w_s24)  + round;

        f_eq_ne_intermediate_product_s25 <= (w_diag * polynomial_ne_s24) + round;
        f_eq_sw_intermediate_product_s25 <= (w_diag * polynomial_sw_s24) + round;
        f_eq_nw_intermediate_product_s25 <= (w_diag * polynomial_nw_s24) + round;
        f_eq_se_intermediate_product_s25 <= (w_diag * polynomial_se_s24) + round;
    end
end

// ------------------------
// Stage 26:
// ------------------------
`DECLARE(s26)

reg signed [31:0] f_eq_n_intermediate_product_s26, f_eq_s_intermediate_product_s26, f_eq_e_intermediate_product_s26, f_eq_w_intermediate_product_s26;
reg signed [31:0] f_eq_ne_intermediate_product_s26, f_eq_sw_intermediate_product_s26, f_eq_nw_intermediate_product_s26, f_eq_se_intermediate_product_s26;

reg signed [15:0] f_eq_n_shifted_s26, f_eq_s_shifted_s26, f_eq_e_shifted_s26, f_eq_w_shifted_s26;
reg signed [15:0] f_eq_ne_shifted_s26, f_eq_sw_shifted_s26, f_eq_nw_shifted_s26, f_eq_se_shifted_s26;

always @(posedge clk or negedge rst) begin
    if (!rst) begin
        `RESET(s26)
    end else begin
        `PIPE(s25, s26)

        // Pipeline product values
        f_eq_n_intermediate_product_s26  <= f_eq_n_intermediate_product_s25;
        f_eq_s_intermediate_product_s26  <= f_eq_s_intermediate_product_s25;
        f_eq_e_intermediate_product_s26  <= f_eq_e_intermediate_product_s25;
        f_eq_w_intermediate_product_s26  <= f_eq_w_intermediate_product_s25;
        f_eq_ne_intermediate_product_s26 <= f_eq_ne_intermediate_product_s25;
        f_eq_sw_intermediate_product_s26 <= f_eq_sw_intermediate_product_s25;
        f_eq_nw_intermediate_product_s26 <= f_eq_nw_intermediate_product_s25;
        f_eq_se_intermediate_product_s26 <= f_eq_se_intermediate_product_s25;

        // Shifted versions
        f_eq_n_shifted_s26  <= f_eq_n_intermediate_product_s25  >>> 13;
        f_eq_s_shifted_s26  <= f_eq_s_intermediate_product_s25  >>> 13;
        f_eq_e_shifted_s26  <= f_eq_e_intermediate_product_s25  >>> 13;
        f_eq_w_shifted_s26  <= f_eq_w_intermediate_product_s25  >>> 13;
        f_eq_ne_shifted_s26 <= f_eq_ne_intermediate_product_s25 >>> 13;
        f_eq_sw_shifted_s26 <= f_eq_sw_intermediate_product_s25 >>> 13;
        f_eq_nw_shifted_s26 <= f_eq_nw_intermediate_product_s25 >>> 13;
        f_eq_se_shifted_s26 <= f_eq_se_intermediate_product_s25 >>> 13;

    end
end

// ------------------------
// Stage 27:
// ------------------------
`DECLARE(s27)

reg signed [15:0] f_eq_n_intermediate_s27, f_eq_s_intermediate_s27, f_eq_e_intermediate_s27, f_eq_w_intermediate_s27;
reg signed [15:0] f_eq_ne_intermediate_s27, f_eq_sw_intermediate_s27, f_eq_nw_intermediate_s27, f_eq_se_intermediate_s27;

always @(posedge clk or negedge rst) begin
    if (!rst) begin
        `RESET(s27)
    end else begin
        `PIPE(s26, s27)

        f_eq_n_intermediate_s27  <= (f_eq_n_intermediate_product_s26  > 32'sh10000000) ? 16'sh7FFF :
                                    (f_eq_n_intermediate_product_s26  < 32'shf0000000) ? 16'sh8000 :
                                    f_eq_n_shifted_s26;

        f_eq_s_intermediate_s27  <= (f_eq_s_intermediate_product_s26  > 32'sh10000000) ? 16'sh7FFF :
                                    (f_eq_s_intermediate_product_s26  < 32'shf0000000) ? 16'sh8000 :
                                    f_eq_s_shifted_s26;

        f_eq_e_intermediate_s27  <= (f_eq_e_intermediate_product_s26  > 32'sh10000000) ? 16'sh7FFF :
                                    (f_eq_e_intermediate_product_s26  < 32'shf0000000) ? 16'sh8000 :
                                    f_eq_e_shifted_s26;

        f_eq_w_intermediate_s27  <= (f_eq_w_intermediate_product_s26  > 32'sh10000000) ? 16'sh7FFF :
                                    (f_eq_w_intermediate_product_s26  < 32'shf0000000) ? 16'sh8000 :
                                    f_eq_w_shifted_s26;

        f_eq_ne_intermediate_s27 <= (f_eq_ne_intermediate_product_s26 > 32'sh10000000) ? 16'sh7FFF :
                                    (f_eq_ne_intermediate_product_s26 < 32'shf0000000) ? 16'sh8000 :
                                    f_eq_ne_shifted_s26;

        f_eq_sw_intermediate_s27 <= (f_eq_sw_intermediate_product_s26 > 32'sh10000000) ? 16'sh7FFF :
                                    (f_eq_sw_intermediate_product_s26 < 32'shf0000000) ? 16'sh8000 :
                                    f_eq_sw_shifted_s26;

        f_eq_nw_intermediate_s27 <= (f_eq_nw_intermediate_product_s26 > 32'sh10000000) ? 16'sh7FFF :
                                    (f_eq_nw_intermediate_product_s26 < 32'shf0000000) ? 16'sh8000 :
                                    f_eq_nw_shifted_s26;

        f_eq_se_intermediate_s27 <= (f_eq_se_intermediate_product_s26 > 32'sh10000000) ? 16'sh7FFF :
                                    (f_eq_se_intermediate_product_s26 < 32'shf0000000) ? 16'sh8000 :
                                    f_eq_se_shifted_s26;
    end
end

// ------------------------
// Stage 28:
// ------------------------
`DECLARE(s28)

reg signed [31:0] f_eq_n_product_s28, f_eq_s_product_s28, f_eq_e_product_s28, f_eq_w_product_s28;
reg signed [31:0] f_eq_ne_product_s28, f_eq_sw_product_s28, f_eq_nw_product_s28, f_eq_se_product_s28;

always @(posedge clk or negedge rst) begin
    if (!rst) begin
        `RESET(s28)
    end else begin
        `PIPE(s27, s28)

        f_eq_n_product_s28  <= (rho_s27 * f_eq_n_intermediate_s27)  + round;
        f_eq_s_product_s28  <= (rho_s27 * f_eq_s_intermediate_s27)  + round;
        f_eq_e_product_s28  <= (rho_s27 * f_eq_e_intermediate_s27)  + round;
        f_eq_w_product_s28  <= (rho_s27 * f_eq_w_intermediate_s27)  + round;

        f_eq_ne_product_s28 <= (rho_s27 * f_eq_ne_intermediate_s27) + round;
        f_eq_sw_product_s28 <= (rho_s27 * f_eq_sw_intermediate_s27) + round;
        f_eq_nw_product_s28 <= (rho_s27 * f_eq_nw_intermediate_s27) + round;
        f_eq_se_product_s28 <= (rho_s27 * f_eq_se_intermediate_s27) + round;
    end
end

// ------------------------
// Stage 29:
// ------------------------
`DECLARE(s29)

reg signed [31:0] f_eq_n_product_s29, f_eq_s_product_s29, f_eq_e_product_s29, f_eq_w_product_s29;
reg signed [31:0] f_eq_ne_product_s29, f_eq_sw_product_s29, f_eq_nw_product_s29, f_eq_se_product_s29;

reg signed [15:0] f_eq_n_shifted_s29, f_eq_s_shifted_s29, f_eq_e_shifted_s29, f_eq_w_shifted_s29;
reg signed [15:0] f_eq_ne_shifted_s29, f_eq_sw_shifted_s29, f_eq_nw_shifted_s29, f_eq_se_shifted_s29;

always @(posedge clk or negedge rst) begin
    if (!rst) begin
        `RESET(s29)
    end else begin
        `PIPE(s28, s29)

        // Pipeline product values
        f_eq_n_product_s29  <= f_eq_n_product_s28;
        f_eq_s_product_s29  <= f_eq_s_product_s28;
        f_eq_e_product_s29  <= f_eq_e_product_s28;
        f_eq_w_product_s29  <= f_eq_w_product_s28;
        f_eq_ne_product_s29 <= f_eq_ne_product_s28;
        f_eq_sw_product_s29 <= f_eq_sw_product_s28;
        f_eq_nw_product_s29 <= f_eq_nw_product_s28;
        f_eq_se_product_s29 <= f_eq_se_product_s28;

        // Shifted versions
        f_eq_n_shifted_s29  <= f_eq_n_product_s28  >>> 13;
        f_eq_s_shifted_s29  <= f_eq_s_product_s28  >>> 13;
        f_eq_e_shifted_s29  <= f_eq_e_product_s28  >>> 13;
        f_eq_w_shifted_s29  <= f_eq_w_product_s28  >>> 13;
        f_eq_ne_shifted_s29 <= f_eq_ne_product_s28 >>> 13;
        f_eq_sw_shifted_s29 <= f_eq_sw_product_s28 >>> 13;
        f_eq_nw_shifted_s29 <= f_eq_nw_product_s28 >>> 13;
        f_eq_se_shifted_s29 <= f_eq_se_product_s28 >>> 13;
    end
end

// ------------------------
// Stage 30:
// ------------------------
`DECLARE(s30)

reg signed [15:0] f_eq_n_s30, f_eq_s_s30, f_eq_e_s30, f_eq_w_s30;
reg signed [15:0] f_eq_ne_s30, f_eq_sw_s30, f_eq_nw_s30, f_eq_se_s30;

always @(posedge clk or negedge rst) begin
    if (!rst) begin
        `RESET(s30)
    end else begin
        `PIPE(s29, s30)

        f_eq_n_s30  <= (f_eq_n_product_s29  > 32'sh10000000) ? 16'sh7FFF :
                       (f_eq_n_product_s29  < 32'shf0000000) ? 16'sh8000 :
                       f_eq_n_shifted_s29;

        f_eq_s_s30  <= (f_eq_s_product_s29  > 32'sh10000000) ? 16'sh7FFF :
                       (f_eq_s_product_s29  < 32'shf0000000) ? 16'sh8000 :
                       f_eq_s_shifted_s29;

        f_eq_e_s30  <= (f_eq_e_product_s29  > 32'sh10000000) ? 16'sh7FFF :
                       (f_eq_e_product_s29  < 32'shf0000000) ? 16'sh8000 :
                       f_eq_e_shifted_s29;

        f_eq_w_s30  <= (f_eq_w_product_s29  > 32'sh10000000) ? 16'sh7FFF :
                       (f_eq_w_product_s29  < 32'shf0000000) ? 16'sh8000 :
                       f_eq_w_shifted_s29;

        f_eq_ne_s30 <= (f_eq_ne_product_s29 > 32'sh10000000) ? 16'sh7FFF :
                       (f_eq_ne_product_s29 < 32'shf0000000) ? 16'sh8000 :
                       f_eq_ne_shifted_s29;

        f_eq_sw_s30 <= (f_eq_sw_product_s29 > 32'sh10000000) ? 16'sh7FFF :
                       (f_eq_sw_product_s29 < 32'shf0000000) ? 16'sh8000 :
                       f_eq_sw_shifted_s29;

        f_eq_nw_s30 <= (f_eq_nw_product_s29 > 32'sh10000000) ? 16'sh7FFF :
                       (f_eq_nw_product_s29 < 32'shf0000000) ? 16'sh8000 :
                       f_eq_nw_shifted_s29;

        f_eq_se_s30 <= (f_eq_se_product_s29 > 32'sh10000000) ? 16'sh7FFF :
                       (f_eq_se_product_s29 < 32'shf0000000) ? 16'sh8000 :
                       f_eq_se_shifted_s29;
    end
end

// ------------------------
// Stage 31:
// ------------------------
`DECLARE(s31)

reg signed [31:0] delta_f_n_product_s31, delta_f_ne_product_s31, delta_f_e_product_s31, delta_f_se_product_s31;
reg signed [31:0] delta_f_s_product_s31, delta_f_sw_product_s31, delta_f_w_product_s31, delta_f_nw_product_s31;

always @(posedge clk or negedge rst) begin
    if (!rst) begin
        `RESET(s31)
    end else begin
        `PIPE(s30, s31)

        delta_f_n_product_s31  <= (omega * (f_eq_n_s30  - f_n_s30))  + round;
        delta_f_ne_product_s31 <= (omega * (f_eq_ne_s30 - f_ne_s30)) + round;
        delta_f_e_product_s31  <= (omega * (f_eq_e_s30  - f_e_s30))  + round;
        delta_f_se_product_s31 <= (omega * (f_eq_se_s30 - f_se_s30)) + round;
        delta_f_s_product_s31  <= (omega * (f_eq_s_s30  - f_s_s30))  + round;
        delta_f_sw_product_s31 <= (omega * (f_eq_sw_s30 - f_sw_s30)) + round;
        delta_f_w_product_s31  <= (omega * (f_eq_w_s30  - f_w_s30))  + round;
        delta_f_nw_product_s31 <= (omega * (f_eq_nw_s30 - f_nw_s30)) + round;
    end
end
// ------------------------
// Stage 32:
// ------------------------
`DECLARE(s32)

reg signed [31:0] delta_f_n_product_s32, delta_f_ne_product_s32, delta_f_e_product_s32, delta_f_se_product_s32;
reg signed [31:0] delta_f_s_product_s32, delta_f_sw_product_s32, delta_f_w_product_s32, delta_f_nw_product_s32;

reg signed [15:0] delta_f_n_shifted_s32, delta_f_ne_shifted_s32, delta_f_e_shifted_s32, delta_f_se_shifted_s32;
reg signed [15:0] delta_f_s_shifted_s32, delta_f_sw_shifted_s32, delta_f_w_shifted_s32, delta_f_nw_shifted_s32;

always @(posedge clk or negedge rst) begin
    if (!rst) begin
        `RESET(s32)
    end else begin
        `PIPE(s31, s32)

        // Pipeline product values
        delta_f_n_product_s32  <= delta_f_n_product_s31;
        delta_f_ne_product_s32 <= delta_f_ne_product_s31;
        delta_f_e_product_s32  <= delta_f_e_product_s31;
        delta_f_se_product_s32 <= delta_f_se_product_s31;
        delta_f_s_product_s32  <= delta_f_s_product_s31;
        delta_f_sw_product_s32 <= delta_f_sw_product_s31;
        delta_f_w_product_s32  <= delta_f_w_product_s31;
        delta_f_nw_product_s32 <= delta_f_nw_product_s31;

        // Shifted versions
        delta_f_n_shifted_s32  <= delta_f_n_product_s31  >>> 13;
        delta_f_ne_shifted_s32 <= delta_f_ne_product_s31 >>> 13;
        delta_f_e_shifted_s32  <= delta_f_e_product_s31  >>> 13;
        delta_f_se_shifted_s32 <= delta_f_se_product_s31 >>> 13;
        delta_f_s_shifted_s32  <= delta_f_s_product_s31  >>> 13;
        delta_f_sw_shifted_s32 <= delta_f_sw_product_s31 >>> 13;
        delta_f_w_shifted_s32  <= delta_f_w_product_s31  >>> 13;
        delta_f_nw_shifted_s32 <= delta_f_nw_product_s31 >>> 13;
    end
end

// ------------------------
// Stage 33:
// ------------------------
`DECLARE(s33)

reg signed [15:0] delta_f_n_s33, delta_f_ne_s33, delta_f_e_s33, delta_f_se_s33;
reg signed [15:0] delta_f_s_s33, delta_f_sw_s33, delta_f_w_s33, delta_f_nw_s33;

always @(posedge clk or negedge rst) begin
    if (!rst) begin
        `RESET(s33)
    end else begin
        `PIPE(s32, s33)

        delta_f_n_s33  <= (delta_f_n_product_s32  > 32'sh10000000) ? 16'sh7FFF :
                          (delta_f_n_product_s32  < 32'shf0000000) ? 16'sh8000 :
                          delta_f_n_shifted_s32;

        delta_f_ne_s33 <= (delta_f_ne_product_s32 > 32'sh10000000) ? 16'sh7FFF :
                          (delta_f_ne_product_s32 < 32'shf0000000) ? 16'sh8000 :
                          delta_f_ne_shifted_s32;

        delta_f_e_s33  <= (delta_f_e_product_s32  > 32'sh10000000) ? 16'sh7FFF :
                          (delta_f_e_product_s32  < 32'shf0000000) ? 16'sh8000 :
                          delta_f_e_shifted_s32;

        delta_f_se_s33 <= (delta_f_se_product_s32 > 32'sh10000000) ? 16'sh7FFF :
                          (delta_f_se_product_s32 < 32'shf0000000) ? 16'sh8000 :
                          delta_f_se_shifted_s32;

        delta_f_s_s33  <= (delta_f_s_product_s32  > 32'sh10000000) ? 16'sh7FFF :
                          (delta_f_s_product_s32  < 32'shf0000000) ? 16'sh8000 :
                          delta_f_s_shifted_s32;

        delta_f_sw_s33 <= (delta_f_sw_product_s32 > 32'sh10000000) ? 16'sh7FFF :
                          (delta_f_sw_product_s32 < 32'shf0000000) ? 16'sh8000 :
                          delta_f_sw_shifted_s32;

        delta_f_w_s33  <= (delta_f_w_product_s32  > 32'sh10000000) ? 16'sh7FFF :
                          (delta_f_w_product_s32  < 32'shf0000000) ? 16'sh8000 :
                          delta_f_w_shifted_s32;

        delta_f_nw_s33 <= (delta_f_nw_product_s32 > 32'sh10000000) ? 16'sh7FFF :
                          (delta_f_nw_product_s32 < 32'shf0000000) ? 16'sh8000 :
                          delta_f_nw_shifted_s32;
    end
end

// ------------------------
// Stage 34:
// ------------------------
always @(posedge clk or negedge rst) begin
    if (!rst) begin
        u_x        <= 0;
        u_y        <= 0;
        rho        <= 0;
        u_squared  <= 0;
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
        u_x        <= u_x_s33;
        u_y        <= u_y_s33;
        rho        <= rho_s33;
        u_squared  <= u_squared_s33;
        f_new_n    <= f_n_s33    + delta_f_n_s33;
        f_new_ne   <= f_ne_s33   + delta_f_ne_s33;
        f_new_e    <= f_e_s33    + delta_f_e_s33;
        f_new_se   <= f_se_s33   + delta_f_se_s33;
        f_new_s    <= f_s_s33    + delta_f_s_s33;
        f_new_sw   <= f_sw_s33   + delta_f_sw_s33;
        f_new_w    <= f_w_s33    + delta_f_w_s33;
        f_new_nw   <= f_nw_s33   + delta_f_nw_s33;

        f_new_null <= rho_s33 - (f_n_s33  + delta_f_n_s33  +
                                     f_ne_s33 + delta_f_ne_s33 +
                                     f_e_s33  + delta_f_e_s33  +
                                     f_se_s33 + delta_f_se_s33 +
                                     f_s_s33  + delta_f_s_s33  +
                                     f_sw_s33 + delta_f_sw_s33 +
                                     f_w_s33  + delta_f_w_s33  +
                                     f_nw_s33 + delta_f_nw_s33);
    end
end

endmodule
