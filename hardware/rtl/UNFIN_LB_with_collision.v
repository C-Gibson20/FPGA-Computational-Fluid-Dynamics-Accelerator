    `timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 26.05.2025 18:21:32
// Design Name: 
// Module Name: lattice_boltzmann
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

// notes:
// read latency 2 cycles from RAM
// 14 bit FI

module lattice_boltzmann #(
    parameter LATTICE_HEIGHT = 10,
              LATTICE_WIDTH = 16 // small for now
    )(

    input wire clk,
    input wire resetn,
    // RAM A ports:
    output wire [14:0] rama_addr,
    output wire [15:0] rama_dout,
    output wire rama_en,
    output wire rama_wen,
    input wire [127:0] rama_din,
    
    // RAM B ports:
    output wire [14:0] ramb_addr,
    output wire [15:0] ramb_dout,
    output wire ramb_en,
    output wire ramb_wen,
    input wire [127:0] ramb_din
    );
   
reg active_ram = 1'b0; // Indicates which RAM is being read from to get F for current iteration

// these approx are so bad lol. in the future consider 
// having all of these as fully fractional and just 
// shift the mulitplication result apprppriately
reg [13:0] w_side = 14'h000e; // 1/9 in Q7.6
reg [13:0] w_diag = 14'h0004; // 1/36 in Q7.6
reg [13:0] w_null = 14'h0039;

reg [13:0] three_halfs = 14'h00c0;
reg [13:0] nine_halfs = 14'h0240;
reg [13:0] three = 14'h0180;

wire [127:0] din;
assign din = active_ram ? ramb_din : rama_din;
assign active_addr = active_ram ? ramb_addr : rama_addr;

// two cycle delay before reads are ready 
wire [13:0] ram_f_null =   din[0+:14];
wire [13:0] ram_f_n =      din[14+:14];
wire [13:0] ram_f_ne =     din[28+:14];
wire [13:0] ram_f_e =      din[42+:14];
wire [13:0] ram_f_se =     din[56+:14];
wire [13:0] ram_f_s =      din[70+:14];
wire [13:0] ram_f_sw =     din[84+:14];
wire [13:0] ram_f_w =      din[96+:14];
wire [13:0] ram_f_nw =     din[110+:14];

// implement fixed coeff. multiplier later

wire [13:0] sum_diags = ram_f_ne + ram_f_se + ram_f_sw + ram_f_nw;
wire [13:0] sum_side = ram_f_n + ram_f_e + ram_f_s + ram_f_w;

wire [13:0] rho = ram_f_null + sum_diags + sum_side;

wire [13:0] rho_times_u_x = (ram_f_e - ram_f_w) + 
                            (ram_f_ne + ram_f_se - ram_f_nw - ram_f_sw);

wire [13:0] rho_times_u_y = (ram_f_n - ram_f_s) + 
                            (ram_f_ne + ram_f_nw - ram_f_se - ram_f_sw);

wire [13:0] u_x = rho_times_u_x/rho;
wire [13:0] u_y = rho_times_u_y/rho;
wire [13:0] u_x2 = u_x*u_x;
wire [13:0] u_y2 = u_y*u_y;

wire [13:0] three_halfs_u2 = three_halfs * (u_x2 + u_y2);

wire [13:0] f_eq_null = w_null * (1 - three_halfs_u2);
wire [13:0] f_eq_n = w_side * (1 + three*u_y + nine_halfs * u_y2 - three_halfs_u2);
wire [13:0] f_eq_e = w_side * (1 + three*u_x + nine_halfs * u_x2 - three_halfs_u2);
wire [13:0] f_eq_s = w_side * (1 - three*u_y + nine_halfs * u_y2 - three_halfs_u2);
wire [13:0] f_eq_w = w_side * (1 - three*u_x + nine_halfs * u_x2 - three_halfs_u2);

wire [13:0] x_plus_y2 = (u_x+u_y)**2;
wire [13:0] x_minus_y2 = (u_x-u_y)**2;

wire [13:0] f_eq_ne = w_diag * (1 + three*(u_x+u_y) + nine_halfs * x_plus_y2 - three_halfs_u2);
wire [13:0] f_eq_nw = w_diag * (1 + three*(-u_x+u_y) + nine_halfs * x_minus_y2 - three_halfs_u2);
wire [13:0] f_eq_se = w_diag * (1 - three*(u_x-u_y) + nine_halfs * x_minus_y2 - three_halfs_u2);
wire [13:0] f_eq_sw = w_side * (1 - three*(-u_x-u_y) + nine_halfs * x_plus_y2 - three_halfs_u2);

// write address (assuming byte) = current_address + 2*direction_offset + (9*2* x_offset) + (LATTICE_WIDTH*9*2*y_offset)
// boundary (Zou-He): if write_address mod LATTICE_WIDTH == 0, 1 or LATTICE_WIDTH - 2, LATTICE_WIDTH - 1, don't change.

// assume tau=0.5 so that we can just multiply by two for the update rule: F - 2(F-Feq) = 2Feq - F

wire [14:0] waddr_null =    active_addr;
wire [14:0] waddr_n  =      active_addr + 2*1 + 18*0 + LATTICE_WIDTH*9*2*1;
wire [14:0] waddr_ne =      active_addr + 2*2 + 18*1 + LATTICE_WIDTH*9*2*1;
wire [14:0] waddr_e  =      active_addr + 2*3 + 18*1 + LATTICE_WIDTH*9*2*0;
wire [14:0] waddr_se =      active_addr + 2*4 + 18*1 + LATTICE_WIDTH*9*2*-1;
wire [14:0] waddr_s  =      active_addr + 2*5 + 18*0 + LATTICE_WIDTH*9*2*-1;
wire [14:0] waddr_sw =      active_addr + 2*6 + 18*-1 + LATTICE_WIDTH*9*2*-1;
wire [14:0] waddr_w  =      active_addr + 2*7 + 18*-1 + LATTICE_WIDTH*9*2*0;
wire [14:0] waddr_nw =      active_addr + 2*8 + 18*-1 + LATTICE_WIDTH*9*2*1;



// now to make an FSM to handle the writing to RAM
localparam [2:0] 
    IDLE = 3'b000,
    WIRTE = 3'b001;

localparam [2:0] 
    READ = 3'b010,
    WAIT_READ = 3'b011,

   
 





endmodule
