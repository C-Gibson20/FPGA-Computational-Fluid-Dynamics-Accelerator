`timescale 1ns / 1ps
`include "def.vh"

module top (
    input  wire clk,
    input  wire rst,
    input  wire en,
    input  wire [31:0] step,
    input  wire [`DEPTH-1:0] barriers,
    input  wire signed [15:0] omega,

    input wire [`DATA_WIDTH-1:0]        init_c0,
    input wire [`DATA_WIDTH-1:0]        init_cn,
    input wire [`DATA_WIDTH-1:0]        init_cne,
    input wire [`DATA_WIDTH-1:0]        init_ce,
    input wire [`DATA_WIDTH-1:0]        init_cse,
    input wire [`DATA_WIDTH-1:0]        init_cs,
    input wire [`DATA_WIDTH-1:0]        init_csw,
    input wire [`DATA_WIDTH-1:0]        init_cw,
    input wire [`DATA_WIDTH-1:0]        init_cnw,

    output wire signed [15:0] testing_cs_n_data_in, //for unit tests allowing me to test values for signals not exposed to the top layer
    output wire signed [15:0] testing_c0_data_in,
    output wire [`DATA_WIDTH-1:0] u_x,
    output wire [`DATA_WIDTH-1:0] u_y,
    output wire [`DATA_WIDTH-1:0] rho,
    output wire [`DATA_WIDTH-1:0] u_squared,
    output wire collider_ready,
    output wire in_collision_state
);

    // Declare all RAM wires
    wire [`ADDRESS_WIDTH-1:0] c0_addr, c0_n_addr, cn_addr, cn_n_addr, cne_addr, cne_n_addr;
    wire [`ADDRESS_WIDTH-1:0] ce_addr, ce_n_addr, cse_addr, cse_n_addr;
    wire [`ADDRESS_WIDTH-1:0] cs_addr, cs_n_addr, csw_addr, csw_n_addr;
    wire [`ADDRESS_WIDTH-1:0] cw_addr, cw_n_addr, cnw_addr, cnw_n_addr;

    wire [`DATA_WIDTH-1:0] c0_data_in, c0_n_data_in, cn_data_in, cn_n_data_in, cne_data_in, cne_n_data_in;
    wire [`DATA_WIDTH-1:0] ce_data_in, ce_n_data_in, cse_data_in, cse_n_data_in;
    wire [`DATA_WIDTH-1:0] cs_data_in, cs_n_data_in, csw_data_in, csw_n_data_in;
    wire [`DATA_WIDTH-1:0] cw_data_in, cw_n_data_in, cnw_data_in, cnw_n_data_in;

    wire [`DATA_WIDTH-1:0] c0_data_out, c0_n_data_out, cn_data_out, cn_n_data_out, cne_data_out, cne_n_data_out;
    wire [`DATA_WIDTH-1:0] ce_data_out, ce_n_data_out, cse_data_out, cse_n_data_out;
    wire [`DATA_WIDTH-1:0] cs_data_out, cs_n_data_out, csw_data_out, csw_n_data_out;
    wire [`DATA_WIDTH-1:0] cw_data_out, cw_n_data_out, cnw_data_out, cnw_n_data_out;

    wire c0_write_en, c0_n_write_en, cn_write_en, cn_n_write_en, cne_write_en, cne_n_write_en;
    wire ce_write_en, ce_n_write_en, cse_write_en, cse_n_write_en;
    wire cs_write_en, cs_n_write_en, csw_write_en, csw_n_write_en;
    wire cw_write_en, cw_n_write_en, cnw_write_en, cnw_n_write_en;

    // Instantiate all 18 RAMs
    RAM_2500 #(.INIT_FILE("ram0E02.mem")) c0     (.clk(clk), .addr(c0_addr),   .data_in(c0_data_in),   .write_en(c0_write_en),   .data_out(c0_data_out));
    RAM_2500 #(.INIT_FILE("ram0E02.mem")) c0_n   (.clk(clk), .addr(c0_n_addr), .data_in(c0_n_data_in), .write_en(c0_n_write_en), .data_out(c0_n_data_out));

    RAM_2500 #(.INIT_FILE("ram0381.mem")) cn ( .clk(clk), .addr(cn_addr   ), .data_in(cn_data_in   ), .write_en(cn_write_en   ), .data_out(cn_data_out   ) );
    RAM_2500 #(.INIT_FILE("ram0381.mem")) cn_n   (.clk(clk), .addr(cn_n_addr), .data_in(cn_n_data_in), .write_en(cn_n_write_en), .data_out(cn_n_data_out));

    RAM_2500 #(.INIT_FILE("ram012F.mem")) cne    (.clk(clk), .addr(cne_addr),  .data_in(cne_data_in),  .write_en(cne_write_en),  .data_out(cne_data_out));
    RAM_2500 #(.INIT_FILE("ram012F.mem")) cne_n  (.clk(clk), .addr(cne_n_addr),.data_in(cne_n_data_in),.write_en(cne_n_write_en),.data_out(cne_n_data_out));

    RAM_2500 #(.INIT_FILE("ram04BB.mem")) ce     (.clk(clk), .addr(ce_addr),   .data_in(ce_data_in),   .write_en(ce_write_en),   .data_out(ce_data_out));
    RAM_2500 #(.INIT_FILE("ram04BB.mem")) ce_n   (.clk(clk), .addr(ce_n_addr), .data_in(ce_n_data_in), .write_en(ce_n_write_en), .data_out(ce_n_data_out));

    RAM_2500 #(.INIT_FILE("ram012F.mem")) cse    (.clk(clk), .addr(cse_addr),  .data_in(cse_data_in),  .write_en(cse_write_en),  .data_out(cse_data_out));
    RAM_2500 #(.INIT_FILE("ram012F.mem")) cse_n  (.clk(clk), .addr(cse_n_addr),.data_in(cse_n_data_in),.write_en(cse_n_write_en),.data_out(cse_n_data_out));

    RAM_2500 #(.INIT_FILE("ram0381.mem")) cs     (.clk(clk), .addr(cs_addr),   .data_in(cs_data_in),   .write_en(cs_write_en),   .data_out(cs_data_out));
    RAM_2500 #(.INIT_FILE("ram0381.mem")) cs_n   (.clk(clk), .addr(cs_n_addr), .data_in(cs_n_data_in), .write_en(cs_n_write_en), .data_out(cs_n_data_out));

    RAM_2500 #(.INIT_FILE("ram00A6.mem")) csw    (.clk(clk), .addr(csw_addr),  .data_in(csw_data_in),  .write_en(csw_write_en),  .data_out(csw_data_out));
    RAM_2500 #(.INIT_FILE("ram00A6.mem")) csw_n  (.clk(clk), .addr(csw_n_addr),.data_in(csw_n_data_in),.write_en(csw_n_write_en),.data_out(csw_n_data_out));

    RAM_2500 #(.INIT_FILE("ram0298.mem")) cw     (.clk(clk), .addr(cw_addr),   .data_in(cw_data_in),   .write_en(cw_write_en),   .data_out(cw_data_out));
    RAM_2500 #(.INIT_FILE("ram0298.mem")) cw_n   (.clk(clk), .addr(cw_n_addr), .data_in(cw_n_data_in), .write_en(cw_n_write_en), .data_out(cw_n_data_out));

    RAM_2500 #(.INIT_FILE("ram00A6.mem")) cnw    (.clk(clk), .addr(cnw_addr),  .data_in(cnw_data_in),  .write_en(cnw_write_en),  .data_out(cnw_data_out));
    RAM_2500 #(.INIT_FILE("ram00A6.mem")) cnw_n  (.clk(clk), .addr(cnw_n_addr),.data_in(cnw_n_data_in),.write_en(cnw_n_write_en),.data_out(cnw_n_data_out));

    assign testing_c0_data_in = c0_data_in;
    // Instantiate LBMSolver and connect RAM
    LBMSolver lbm (
        .clk(clk),
        .rst(rst),
        .en(en),
        .step(step),
        .barriers(barriers),
        .omega(omega),
        .testing_cs_n_data_in(testing_cs_n_data_in),
        
        // RAM ports (repeat for all RAMs)
        .c0_addr(c0_addr), .c0_data_in(c0_data_in), .c0_write_en(c0_write_en), .c0_data_out(c0_data_out),
        .c0_n_addr(c0_n_addr), .c0_n_data_in(c0_n_data_in), .c0_n_write_en(c0_n_write_en), .c0_n_data_out(c0_n_data_out),
        .cn_addr(cn_addr), .cn_data_in(cn_data_in), .cn_write_en(cn_write_en), .cn_data_out(cn_data_out),
        .cn_n_addr(cn_n_addr), .cn_n_data_in(cn_n_data_in), .cn_n_write_en(cn_n_write_en), .cn_n_data_out(cn_n_data_out),
        .cne_addr(cne_addr), .cne_data_in(cne_data_in), .cne_write_en(cne_write_en), .cne_data_out(cne_data_out),
        .cne_n_addr(cne_n_addr), .cne_n_data_in(cne_n_data_in), .cne_n_write_en(cne_n_write_en), .cne_n_data_out(cne_n_data_out),
        .ce_addr(ce_addr), .ce_data_in(ce_data_in), .ce_write_en(ce_write_en), .ce_data_out(ce_data_out),
        .ce_n_addr(ce_n_addr), .ce_n_data_in(ce_n_data_in), .ce_n_write_en(ce_n_write_en), .ce_n_data_out(ce_n_data_out),
        .cse_addr(cse_addr), .cse_data_in(cse_data_in), .cse_write_en(cse_write_en), .cse_data_out(cse_data_out),
        .cse_n_addr(cse_n_addr), .cse_n_data_in(cse_n_data_in), .cse_n_write_en(cse_n_write_en), .cse_n_data_out(cse_n_data_out),
        .cs_addr(cs_addr), .cs_data_in(cs_data_in), .cs_write_en(cs_write_en), .cs_data_out(cs_data_out),
        .cs_n_addr(cs_n_addr), .cs_n_data_in(cs_n_data_in), .cs_n_write_en(cs_n_write_en), .cs_n_data_out(cs_n_data_out),
        .csw_addr(csw_addr), .csw_data_in(csw_data_in), .csw_write_en(csw_write_en), .csw_data_out(csw_data_out),
        .csw_n_addr(csw_n_addr), .csw_n_data_in(csw_n_data_in), .csw_n_write_en(csw_n_write_en), .csw_n_data_out(csw_n_data_out),
        .cw_addr(cw_addr), .cw_data_in(cw_data_in), .cw_write_en(cw_write_en), .cw_data_out(cw_data_out),
        .cw_n_addr(cw_n_addr), .cw_n_data_in(cw_n_data_in), .cw_n_write_en(cw_n_write_en), .cw_n_data_out(cw_n_data_out),
        .cnw_addr(cnw_addr), .cnw_data_in(cnw_data_in), .cnw_write_en(cnw_write_en), .cnw_data_out(cnw_data_out),
        .cnw_n_addr(cnw_n_addr), .cnw_n_data_in(cnw_n_data_in), .cnw_n_write_en(cnw_n_write_en), .cnw_n_data_out(cnw_n_data_out),

        .init_c0(init_c0),
        .init_cn(init_cn),
        .init_cne(init_cne),
        .init_ce(init_ce),
        .init_cse(init_cse),
        .init_cs(init_cs),
        .init_csw(init_csw),
        .init_cw(init_cw),
        .init_cnw(init_cnw),
        
        .u_x(u_x),
        .u_y(u_y),
        .rho(rho),
        .u_squared(u_squared),
        .collider_ready(collider_ready),
        .in_collision_state(in_collision_state)
    );

endmodule
