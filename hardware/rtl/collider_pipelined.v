module collider_pipelined (
    input  wire clk,
    input  wire rst,

    input  wire signed [15:0] omega,
    input  wire signed [15:0] f_null,
    input  wire signed [15:0] f_n,
    input  wire signed [15:0] f_ne,
    input  wire signed [15:0] f_e,
    input  wire signed [15:0] f_se,
    input  wire signed [15:0] f_s,
    input  wire signed [15:0] f_sw,
    input  wire signed [15:0] f_w,
    input  wire signed [15:0] f_nw,

    output wire signed [15:0] f_new_null,
    output wire signed [15:0] f_new_n,
    output wire signed [15:0] f_new_ne,
    output wire signed [15:0] f_new_e,
    output wire signed [15:0] f_new_se,
    output wire signed [15:0] f_new_s,
    output wire signed [15:0] f_new_sw,
    output wire signed [15:0] f_new_w,
    output wire signed [15:0] f_new_nw
);

// ------------------------
// Stage 0: Input Latch
// ------------------------
reg signed [15:0] omega_s0;
reg signed [15:0] f_i_s0 [0:8];
always @(posedge clk or posedge rst) begin
    if (rst) begin
        omega_s0 <= 0;
        f_i_s0[0] <= 0; f_i_s0[1] <= 0; f_i_s0[2] <= 0; f_i_s0[3] <= 0;
        f_i_s0[4] <= 0; f_i_s0[5] <= 0; f_i_s0[6] <= 0; f_i_s0[7] <= 0; f_i_s0[8] <= 0;
    end else begin
        omega_s0 <= omega;
        f_i_s0[0] <= f_null; f_i_s0[1] <= f_n;  f_i_s0[2] <= f_ne;
        f_i_s0[3] <= f_e;    f_i_s0[4] <= f_se; f_i_s0[5] <= f_s;
        f_i_s0[6] <= f_sw;   f_i_s0[7] <= f_w;  f_i_s0[8] <= f_nw;
    end
end

// ------------------------
// Stage 1: Compute rho, rho*u
// ------------------------
reg signed [15:0] rho_s1;
reg signed [31:0] rho_ux_s1, rho_uy_s1;
reg signed [15:0] omega_s1;
reg signed [15:0] f_i_s1 [0:8];
always @(posedge clk or posedge rst) begin
    if (rst) begin
        rho_s1 <= 0;
        rho_ux_s1 <= 0;
        rho_uy_s1 <= 0;
    end else begin
        omega_s1 <= omega_s0;
        f_i_s1 <= f_i_s0;
        rho_s1 <= f_i_s0[0] + f_i_s0[1] + f_i_s0[2] + f_i_s0[3] +
                  f_i_s0[4] + f_i_s0[5] + f_i_s0[6] + f_i_s0[7] + f_i_s0[8];

        rho_ux_s1 <= (f_i_s0[3] - f_i_s0[7] + f_i_s0[2] - f_i_s0[6] - f_i_s0[8] + f_i_s0[4]) <<< 13;
        rho_uy_s1 <= (f_i_s0[1] - f_i_s0[5] + f_i_s0[2] - f_i_s0[6] + f_i_s0[8] - f_i_s0[4]) <<< 13;
    end
end

// ------------------------
// Stage 2: Compute u, u^2
// ------------------------
reg signed [15:0] u_x_s2, u_y_s2, u2_x_s2, u2_y_s2;
reg signed [15:0] omega_s2;
reg signed [15:0] f_i_s2 [0:8];
always @(posedge clk or posedge rst) begin
    if (rst) begin
        u_x_s2 <= 0;
        u_y_s2 <= 0;
    end else begin
        omega_s2 <= omega_s1;
        f_i_s2 <= f_i_s1;

        // Use Newton-Raphson or approx divider for better pipelining in real design
        u_x_s2 <= rho_ux_s1 / rho_s1;
        u_y_s2 <= rho_uy_s1 / rho_s1;

        u2_x_s2 <= (u_x_s2 * u_x_s2) >>> 13;
        u2_y_s2 <= (u_y_s2 * u_y_s2) >>> 13;
    end
end

// ------------------------
// Stage 3: Compute f_eq_i
// ------------------------
reg signed [15:0] f_eq_i_s3 [0:8];
reg signed [15:0] omega_s3;
reg signed [15:0] f_i_s3 [0:8];
always @(posedge clk or posedge rst) begin
    if (rst) begin
        f_eq_i_s3[0] <= 0;
        // ...
    end else begin
        omega_s3 <= omega_s2;
        f_i_s3 <= f_i_s2;

        // TODO: Add polynomial + weight logic here for f_eq_i_s3[0 to 8]
    end
end

// ------------------------
// Stage 4: Final update: f_i_new = f_i + omega*(f_eq_i - f_i)
// ------------------------
reg signed [15:0] f_new_i_s4 [0:8];
always @(posedge clk or posedge rst) begin
    if (rst) begin
        f_new_i_s4[0] <= 0;
        // ...
    end else begin
        for (int i = 0; i < 9; i++) begin
            f_new_i_s4[i] <= f_i_s3[i] + ((omega_s3 * (f_eq_i_s3[i] - f_i_s3[i])) >>> 13);
        end
    end
end

// ------------------------
// Output Assignments
// ------------------------
assign f_new_null = f_new_i_s4[0];
assign f_new_n    = f_new_i_s4[1];
assign f_new_ne   = f_new_i_s4[2];
assign f_new_e    = f_new_i_s4[3];
assign f_new_se   = f_new_i_s4[4];
assign f_new_s    = f_new_i_s4[5];
assign f_new_sw   = f_new_i_s4[6];
assign f_new_w    = f_new_i_s4[7];
assign f_new_nw   = f_new_i_s4[8];

endmodule
