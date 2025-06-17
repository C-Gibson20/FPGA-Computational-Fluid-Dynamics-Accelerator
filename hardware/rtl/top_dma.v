`timescale 1ns / 1ps
`include "def.vh"

module top_dma (
    input  wire clk,
    input  wire rst_n, 
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

    // AXI Stream Master Interface
    output wire  m00_axis_tvalid,
    output wire [63 : 0] m00_axis_tdata,
    output wire [7 : 0] m00_axis_tstrb,
    output wire  m00_axis_tlast,
    input wire  m00_axis_tready,

    // Debug outputs
    output wire signed [15:0] testing_cs_n_data_in,
    output wire signed [15:0] testing_c0_data_in
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

    // LBMSolver outputs
    wire [`DATA_WIDTH-1:0] u_x;
    wire [`DATA_WIDTH-1:0] u_y;
    wire [`DATA_WIDTH-1:0] rho;
    wire [`DATA_WIDTH-1:0] u_squared;
    wire collider_ready;
    wire in_collision_state;

    // DMA RAM interface signals
    wire [256:0] ram_dout;
    wire [256:0] ram_din;
    wire ram_wen;
    wire [31:0] step_countn;
    wire [`ADDRESS_WIDTH-1:0] ram_addr;

    // Instantiate all 18 RAMs
    RAM_2500 #(.INIT_FILE("ram0E02.mem"), .DATA_WIDTH(128), .ADDRESS_WIDTH(8)) c0     (.clk(clk), .addr(c0_addr),   .data_in(c0_data_in),   .write_en(c0_write_en),   .data_out(c0_data_out));
    RAM_2500 #(.INIT_FILE("ram0E02.mem"), .DATA_WIDTH(128), .ADDRESS_WIDTH(8)) c0_n   (.clk(clk), .addr(c0_n_addr), .data_in(c0_n_data_in), .write_en(c0_n_write_en), .data_out(c0_n_data_out));
    RAM_2500 #(.INIT_FILE("ram0381.mem"), .DATA_WIDTH(128), .ADDRESS_WIDTH(8)) cn ( .clk(clk), .addr(cn_addr   ), .data_in(cn_data_in   ), .write_en(cn_write_en   ), .data_out(cn_data_out   ) );
    RAM_2500 #(.INIT_FILE("ram0381.mem"), .DATA_WIDTH(128), .ADDRESS_WIDTH(8)) cn_n   (.clk(clk), .addr(cn_n_addr), .data_in(cn_n_data_in), .write_en(cn_n_write_en), .data_out(cn_n_data_out));
    RAM_2500 #(.INIT_FILE("ram012F.mem"), .DATA_WIDTH(128), .ADDRESS_WIDTH(8)) cne    (.clk(clk), .addr(cne_addr),  .data_in(cne_data_in),  .write_en(cne_write_en),  .data_out(cne_data_out));
    RAM_2500 #(.INIT_FILE("ram012F.mem"), .DATA_WIDTH(128), .ADDRESS_WIDTH(8)) cne_n  (.clk(clk), .addr(cne_n_addr),.data_in(cne_n_data_in),.write_en(cne_n_write_en),.data_out(cne_n_data_out));
    RAM_2500 #(.INIT_FILE("ram04BB.mem"), .DATA_WIDTH(128), .ADDRESS_WIDTH(8)) ce     (.clk(clk), .addr(ce_addr),   .data_in(ce_data_in),   .write_en(ce_write_en),   .data_out(ce_data_out));
    RAM_2500 #(.INIT_FILE("ram04BB.mem"), .DATA_WIDTH(128), .ADDRESS_WIDTH(8)) ce_n   (.clk(clk), .addr(ce_n_addr), .data_in(ce_n_data_in), .write_en(ce_n_write_en), .data_out(ce_n_data_out));
    RAM_2500 #(.INIT_FILE("ram012F.mem"), .DATA_WIDTH(128), .ADDRESS_WIDTH(8)) cse    (.clk(clk), .addr(cse_addr),  .data_in(cse_data_in),  .write_en(cse_write_en),  .data_out(cse_data_out));
    RAM_2500 #(.INIT_FILE("ram012F.mem"), .DATA_WIDTH(128), .ADDRESS_WIDTH(8)) cse_n  (.clk(clk), .addr(cse_n_addr),.data_in(cse_n_data_in),.write_en(cse_n_write_en),.data_out(cse_n_data_out));
    RAM_2500 #(.INIT_FILE("ram0381.mem"), .DATA_WIDTH(128), .ADDRESS_WIDTH(8)) cs     (.clk(clk), .addr(cs_addr),   .data_in(cs_data_in),   .write_en(cs_write_en),   .data_out(cs_data_out));
    RAM_2500 #(.INIT_FILE("ram0381.mem"), .DATA_WIDTH(128), .ADDRESS_WIDTH(8)) cs_n   (.clk(clk), .addr(cs_n_addr), .data_in(cs_n_data_in), .write_en(cs_n_write_en), .data_out(cs_n_data_out));
    RAM_2500 #(.INIT_FILE("ram00A6.mem"), .DATA_WIDTH(128), .ADDRESS_WIDTH(8)) csw    (.clk(clk), .addr(csw_addr),  .data_in(csw_data_in),  .write_en(csw_write_en),  .data_out(csw_data_out));
    RAM_2500 #(.INIT_FILE("ram00A6.mem"), .DATA_WIDTH(128), .ADDRESS_WIDTH(8)) csw_n  (.clk(clk), .addr(csw_n_addr),.data_in(csw_n_data_in),.write_en(csw_n_write_en),.data_out(csw_n_data_out));
    RAM_2500 #(.INIT_FILE("ram0298.mem"), .DATA_WIDTH(128), .ADDRESS_WIDTH(8)) cw     (.clk(clk), .addr(cw_addr),   .data_in(cw_data_in),   .write_en(cw_write_en),   .data_out(cw_data_out));
    RAM_2500 #(.INIT_FILE("ram0298.mem"), .DATA_WIDTH(128), .ADDRESS_WIDTH(8)) cw_n   (.clk(clk), .addr(cw_n_addr), .data_in(cw_n_data_in), .write_en(cw_n_write_en), .data_out(cw_n_data_out));
    RAM_2500 #(.INIT_FILE("ram00A6.mem"), .DATA_WIDTH(128), .ADDRESS_WIDTH(8)) cnw    (.clk(clk), .addr(cnw_addr),  .data_in(cnw_data_in),  .write_en(cnw_write_en),  .data_out(cnw_data_out));
    RAM_2500 #(.INIT_FILE("ram00A6.mem"), .DATA_WIDTH(128), .ADDRESS_WIDTH(8)) cnw_n  (.clk(clk), .addr(cnw_n_addr),.data_in(cnw_n_data_in),.write_en(cnw_n_write_en),.data_out(cnw_n_data_out));

    // Additional RAM for DMA output
    RAM_2500 #(.DATA_WIDTH(64*8)) dma_ram (
        .clk(clk),
        .addr(ram_addr),
        .data_in(ram_din),
        .write_en(ram_wen),
        .data_out(ram_dout)
    );

    assign testing_c0_data_in = c0_data_in;

    // Instantiate LBMSolver and connect RAM
    LBMSolver lbm (
        .clk(clk),
        .rst(rst_n),
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
        .in_collision_state(in_collision_state),
        .step_countn(step_countn)
    );

    // Instantiate DMA module
    Solver_DMA_Master #(
        .DATA_WIDTH(`DATA_WIDTH),
        .DEPTH(`DEPTH),
        .ADDRESS_WIDTH(`ADDRESS_WIDTH)
    ) dma (
        // LBM outputs
        .u_x(u_x),
        .u_y(u_y),
        .rho(rho),
        .u_squared(u_squared),
        .in_collision_state(in_collision_state),
        .collider_ready(collider_ready),
        
        // RAM interface
        .ram_dout(ram_dout),
        .ram_din(ram_din),
        .ram_wen(ram_wen),
        .ram_addr(ram_addr),
        
        // AXI Stream interface
        .m00_axis_aclk(clk),
        .m00_axis_aresetn(rst_n),
        .m00_axis_tvalid(m00_axis_tvalid),
        .m00_axis_tdata(m00_axis_tdata),
        .m00_axis_tstrb(m00_axis_tstrb),
        .m00_axis_tlast(m00_axis_tlast),
        .m00_axis_tready(m00_axis_tready)
    );

endmodule