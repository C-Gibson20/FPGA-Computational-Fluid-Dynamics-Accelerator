module Solver_DMA_Top #
(
    // Parameters from Solver_DMA_Master
    parameter DATA_WIDTH                = 16,
    parameter DEPTH                     = 2500,
    parameter ADDRESS_WIDTH             = 12,
    parameter C_M00_AXIS_TDATA_WIDTH    = 64,
    parameter C_M00_AXIS_START_COUNT    = 32,
    
    // Parameters from RAM_2500
    parameter INIT_FILE = "ram0.mem"
)
(
    // Inputs to Solver_DMA_Master
    input wire [DATA_WIDTH-1:0] u_x,
    input wire [DATA_WIDTH-1:0] u_y,
    input wire [DATA_WIDTH-1:0] rho, 
    input wire [DATA_WIDTH-1:0] u_squared,
    input wire                  in_collision_state,
    input wire                  collider_ready,
    
    // AXI Stream Interface
    input wire  m00_axis_aclk,
    input wire  m00_axis_aresetn,
    output wire m00_axis_tvalid,
    output wire [C_M00_AXIS_TDATA_WIDTH-1 : 0] m00_axis_tdata,
    output wire [(C_M00_AXIS_TDATA_WIDTH/8)-1 : 0] m00_axis_tstrb,
    output wire m00_axis_tlast,
    input wire  m00_axis_tready
);

    // Internal connections between Solver_DMA_Master and RAM_2500
    wire [C_M00_AXIS_TDATA_WIDTH-1:0] ram_dout;
    wire [C_M00_AXIS_TDATA_WIDTH-1:0] ram_din;
    wire ram_wen;
    wire [ADDRESS_WIDTH-1:0] ram_addr;

    // Instantiate Solver_DMA_Master
    Solver_DMA_Master #(
        .DATA_WIDTH(DATA_WIDTH),
        .DEPTH(DEPTH),
        .ADDRESS_WIDTH(ADDRESS_WIDTH),
        .C_M00_AXIS_TDATA_WIDTH(C_M00_AXIS_TDATA_WIDTH),
        .C_M00_AXIS_START_COUNT(C_M00_AXIS_START_COUNT)
    ) solver_dma_master_inst (
        .u_x(u_x),
        .u_y(u_y),
        .rho(rho),
        .u_squared(u_squared),
        .in_collision_state(in_collision_state),
        .collider_ready(collider_ready),
        .ram_dout(ram_dout),
        .ram_din(ram_din),
        .ram_wen(ram_wen),
        .ram_addr(ram_addr),
        .m00_axis_aclk(m00_axis_aclk),
        .m00_axis_aresetn(m00_axis_aresetn),
        .m00_axis_tvalid(m00_axis_tvalid),
        .m00_axis_tdata(m00_axis_tdata),
        .m00_axis_tstrb(m00_axis_tstrb),
        .m00_axis_tlast(m00_axis_tlast),
        .m00_axis_tready(m00_axis_tready)
    );

    // Instantiate RAM_2500
    RAM_2500 #(
        .DATA_WIDTH(C_M00_AXIS_TDATA_WIDTH),  // Using same width as AXI stream
        .ADDRESS_WIDTH(ADDRESS_WIDTH),
        .INIT_FILE(INIT_FILE)
    ) ram_inst (
        .clk(m00_axis_aclk),                 // Using same clock as AXI interface
        .addr(ram_addr),
        .data_in(ram_din),
        .write_en(ram_wen),
        .data_out(ram_dout)
    );

endmodule