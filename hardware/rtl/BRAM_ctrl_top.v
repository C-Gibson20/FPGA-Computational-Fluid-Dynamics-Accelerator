`timescale 1ns / 1ps

module BRAM_ctrl_top #(
    parameter DATA_WIDTH    = 16,
    parameter DEPTH         = 2500,
    parameter ADDRESS_WIDTH = 12
)(
    input  wire              frame_ready,
    input  wire              m00_axis_aclk,
    input  wire              m00_axis_aresetn,
    input  wire              m00_axis_tready,
    output wire              m00_axis_tvalid,
    output wire [(144/8)-1:0] m00_axis_tstrb,
    output wire              m00_axis_tlast,
    output wire [143:0]      m00_axis_tdata
);

wire [15:0]       n1, null1, ne1, e1, se1, s1, sw1, w1, nw1;
wire [ADDRESS_WIDTH-1:0] read_addr;

    BRAM_ctrl_test #(
        .DATA_WIDTH(DATA_WIDTH),
        .DEPTH(DEPTH),
        .ADDRESS_WIDTH(ADDRESS_WIDTH)
    ) inst_bram_ctrl (
        .frame_ready(frame_ready),
        .n1(n1), .null1(null1), .ne1(ne1), .e1(e1),
        .se1(se1), .s1(s1), .sw1(sw1), .w1(w1), .nw1(nw1),
        .m00_axis_aclk(m00_axis_aclk),
        .m00_axis_aresetn(m00_axis_aresetn),
        .m00_axis_tvalid(m00_axis_tvalid),
        .m00_axis_tdata(m00_axis_tdata),
        .m00_axis_tstrb(m00_axis_tstrb),
        .m00_axis_tlast(m00_axis_tlast),
        .m00_axis_tready(m00_axis_tready),
        .read_addr(read_addr)
    );

    // Instantiate RAMs
    RAM_2500 #(.INIT_FILE("ram.mem")) c0  (.clk(m00_axis_aclk), .addr(read_addr), .data_in(16'd0), .write_en(1'b0), .data_out(null1));
    RAM_2500 #(.INIT_FILE("ram.mem")) cn  (.clk(m00_axis_aclk), .addr(read_addr), .data_in(16'd0), .write_en(1'b0), .data_out(n1));
    RAM_2500 #(.INIT_FILE("ram.mem")) cne (.clk(m00_axis_aclk), .addr(read_addr), .data_in(16'd0), .write_en(1'b0), .data_out(ne1));
    RAM_2500 #(.INIT_FILE("ram.mem")) ce  (.clk(m00_axis_aclk), .addr(read_addr), .data_in(16'd0), .write_en(1'b0), .data_out(e1));
    RAM_2500 #(.INIT_FILE("ram.mem")) cse (.clk(m00_axis_aclk), .addr(read_addr), .data_in(16'd0), .write_en(1'b0), .data_out(se1));
    RAM_2500 #(.INIT_FILE("ram.mem")) cs  (.clk(m00_axis_aclk), .addr(read_addr), .data_in(16'd0), .write_en(1'b0), .data_out(s1));
    RAM_2500 #(.INIT_FILE("ram.mem")) csw (.clk(m00_axis_aclk), .addr(read_addr), .data_in(16'd0), .write_en(1'b0), .data_out(sw1));
    RAM_2500 #(.INIT_FILE("ram.mem")) cw  (.clk(m00_axis_aclk), .addr(read_addr), .data_in(16'd0), .write_en(1'b0), .data_out(w1));
    RAM_2500 #(.INIT_FILE("ram.mem")) cnw (.clk(m00_axis_aclk), .addr(read_addr), .data_in(16'd0), .write_en(1'b0), .data_out(nw1));

endmodule
