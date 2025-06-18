`timescale 1ns / 1ps
`include "def.vh"
// ════════════════════════════════════════════════════════════════════════════
//  LBM SYSTEM – COMPLETE TOP‑LEVEL WRAPPER
//      * Integrates:  BRAM_ctrl  (AXI‑Stream producer)
//                     DDR_pixel_out (AXI‑Stream consumer)
//                     cache_top      (address mux)
//                     LBMSolverCache (physics core)
//
//  NOTE:  Dummy behavioural RAMs are instantiated here so the whole design can
//         be simulated without any vendor IP.  Replace them with true block‑
//         RAM primitives (or your own wrappers) as soon as you move to a
//         device‑specific flow.
// ════════════════════════════════════════════════════════════════════════════
module LBMCacheTop
#(
    parameter DATA_WIDTH      = `DATA_WIDTH,
    parameter ADDRESS_WIDTH   = `ADDRESS_WIDTH,
    parameter DEPTH           = `DEPTH,
    parameter AXIS_DATA_WIDTH = 144                // 9 × 16‑bit directions
)
(
    //---------------------------------------------------------------------
    //  Global
    //---------------------------------------------------------------------
    input  wire                       clk,
    input  wire                       rstn,          // active‑low reset

    //---------------------------------------------------------------------
    //  Solver‑side high‑level control
    //---------------------------------------------------------------------
    input  wire                       en,
    input  wire [15:0]                step,
    input  wire  signed [15:0]        omega,
    input  wire [DEPTH-1:0]           barriers,

    input  wire [DATA_WIDTH-1:0]      init_c0,
    input  wire [DATA_WIDTH-1:0]      init_cn,
    input  wire [DATA_WIDTH-1:0]      init_cne,
    input  wire [DATA_WIDTH-1:0]      init_ce,
    input  wire [DATA_WIDTH-1:0]      init_cse,
    input  wire [DATA_WIDTH-1:0]      init_cs,
    input  wire [DATA_WIDTH-1:0]      init_csw,
    input  wire [DATA_WIDTH-1:0]      init_cw,
    input  wire [DATA_WIDTH-1:0]      init_cnw,
    //---------------------------------------------------------------------
    //  Status / debug back to MCU or testbench
    //---------------------------------------------------------------------
    output wire                       collider_ready,
    output wire                       in_collision_state,
    output wire [15:0]                step_count,
    output wire  signed [15:0]        u_x,
    output wire  signed [15:0]        u_y,
    output wire  signed [15:0]        rho,
    output wire  signed [15:0]        u_squared,
    output wire  signed [15:0]        test_cs_n_data  // probe from solver
);

    //──────────────────────────────────────────────────────────────────────
    //  Internal nets
    //──────────────────────────────────────────────────────────────────────
    // Handshake between BRAM_ctrl ⇋ DDR_pixel_out
    wire                   chunk_transfer_ready;
    wire                   chunk_compute_ready;
    wire                   wen;

    // AXI‑Stream wires
    wire                   axis_tvalid;
    wire                   axis_tready;
    wire                   axis_tlast;
    wire [AXIS_DATA_WIDTH-1:0] axis_tdata;
    wire [(AXIS_DATA_WIDTH/8)-1:0] axis_tstrb;

    // Shared addresses
    wire [ADDRESS_WIDTH-1:0] bram_read_addr;
    wire [ADDRESS_WIDTH-1:0] ddr_write_addr;
    wire [ADDRESS_WIDTH-1:0] lbm_addr;
    wire [ADDRESS_WIDTH-1:0] cache_addr;   // (unused in this dummy RAM setup)

    // Nine direction buses (current step read by BRAM_ctrl; new data written
    // by DDR_pixel_out) – rest,  N, NE,  E, SE,  S, SW,  W, NW
    wire [DATA_WIDTH-1:0] null1, n1, ne1, e1, se1, s1, sw1, w1, nw1;

    //---------------------------------------------------------------------
    // 1.  Behavioural dual‑port RAMs per direction
    //---------------------------------------------------------------------
    //     * mem_cur  – present‑step distribution (read‑only for BRAM_ctrl)
    //     * mem_nxt  – next‑step distribution (written by solver)
    //
    //     18 memories in total (9 directions × 2 time slots).
    //---------------------------------------------------------------------
    generate
        genvar dir;
        for(dir = 0; dir < 9; dir = dir + 1) begin : g_dir_mem
            // Two separate memories so that *_data_out and *_n_data_out can be
            // driven independently exactly like true dual‑buffering.
            reg [DATA_WIDTH-1:0] mem_cur [0:DEPTH-1];
            reg [DATA_WIDTH-1:0] mem_nxt [0:DEPTH-1];

            //-------------------------------------------------------------
            //  Write‑port from DDR loader  ➔  mem_cur
            //-------------------------------------------------------------
            always @(posedge clk)
                if(wen)
                    mem_cur[ddr_write_addr] <= axis_tdata[dir*DATA_WIDTH +: DATA_WIDTH];

            //-------------------------------------------------------------
            //  Write‑port from solver      ➔  mem_nxt
            //-------------------------------------------------------------
            // Signals declared later (with generate‑indexed names)
        end
    endgenerate

    //---------------------------------------------------------------------
    // (a) Helper macro to slice AXI tdata by direction index
    //---------------------------------------------------------------------
    `define SLICE_TDATA(DIR) axis_tdata[((DIR)*DATA_WIDTH) +: DATA_WIDTH]

    //---------------------------------------------------------------------
    // 2.  Stream producer – BRAM_ctrl
    //---------------------------------------------------------------------
    BRAM_ctrl #(
        .DATA_WIDTH    (DATA_WIDTH),
        .DEPTH         (DEPTH),
        .ADDRESS_WIDTH (ADDRESS_WIDTH)
    ) u_bram_ctrl (
        .chunk_transfer_ready (chunk_transfer_ready),
        .n1      (n1),
        .null1   (null1),
        .ne1     (ne1),
        .e1      (e1),
        .se1     (se1),
        .s1      (s1),
        .sw1     (sw1),
        .w1      (w1),
        .nw1     (nw1),
        .read_addr          (bram_read_addr),
        .m00_axis_aclk      (clk),
        .m00_axis_aresetn   (rstn),
        .m00_axis_tready    (axis_tready),
        .m00_axis_tvalid    (axis_tvalid),
        .m00_axis_tdata     (axis_tdata),
        .m00_axis_tstrb     (axis_tstrb),
        .m00_axis_tlast     (axis_tlast)
    );

    //---------------------------------------------------------------------
    // 3.  Stream consumer – DDR_pixel_out
    //---------------------------------------------------------------------
    DDR_pixel_out #(
        .DATA_WIDTH                 (DATA_WIDTH),
        .DEPTH                      (DEPTH),
        .ADDRESS_WIDTH              (ADDRESS_WIDTH),
        .C_M00_AXIS_TDATA_WIDTH     (AXIS_DATA_WIDTH)
    ) u_ddr_pixel_out (
        .n1                 (n1),
        .null1              (null1),
        .ne1                (ne1),
        .e1                 (e1),
        .se1                (se1),
        .s1                 (s1),
        .sw1                (sw1),
        .w1                 (w1),
        .nw1                (nw1),
        .wen                (wen),
        .chunk_transfer_ready(chunk_transfer_ready),
        .chunk_compute_ready (chunk_compute_ready),
        .write_addr         (ddr_write_addr),
        .read_addr          (bram_read_addr),
        .m00_axis_aclk      (clk),
        .m00_axis_aresetn   (rstn),
        .m00_axis_tvalid    (axis_tvalid),
        .m00_axis_tdata     (axis_tdata),
        .m00_axis_tstrb     (axis_tstrb),
        .m00_axis_tlast     (axis_tlast),
        .m00_axis_tready    (axis_tready)
    );

    //---------------------------------------------------------------------
    // 4.  Optional address multiplexer – cache_top
    //---------------------------------------------------------------------
    BRAM_toggle u_BRAM_toggle (
        .chunk_transfer_ready (chunk_transfer_ready),
        .chunk_compute_ready  (chunk_compute_ready),
        .wen                  (wen),
        .LBM_addr             (lbm_addr),
        .DDR_addr             (ddr_write_addr),
        .addr                 (cache_addr)
    );

    //---------------------------------------------------------------------
    // 5.  LBMSolverCache – Physics core
    //     (Full port list wired.  Dummy RAM outputs are tied to zero for now;
    //      swap‑in real memories or feed back dummy mem_nxt[] as needed.)
    //---------------------------------------------------------------------

    //------------------------------------------------------------------
    //  Direction arrays – declare wires for every solver port
    //------------------------------------------------------------------
    //  Addresses
    wire [ADDRESS_WIDTH-1:0] c0_addr,   c0_n_addr,
                             cn_addr,   cn_n_addr,
                             cne_addr,  cne_n_addr,
                             ce_addr,   ce_n_addr,
                             cse_addr,  cse_n_addr,
                             cs_addr,   cs_n_addr,
                             csw_addr,  csw_n_addr,
                             cw_addr,   cw_n_addr,
                             cnw_addr,  cnw_n_addr;

    //  Write‑enables
    wire c0_we,   c0_n_we,
         cn_we,   cn_n_we,
         cne_we,  cne_n_we,
         ce_we,   ce_n_we,
         cse_we,  cse_n_we,
         cs_we,   cs_n_we,
         csw_we,  csw_n_we,
         cw_we,   cw_n_we,
         cnw_we,  cnw_n_we;

    //  Data buses in/out (solver ⇄ RAM)
    wire [DATA_WIDTH-1:0] c0_din,   c0_n_din,
                          cn_din,   cn_n_din,
                          cne_din,  cne_n_din,
                          ce_din,   ce_n_din,
                          cse_din,  cse_n_din,
                          cs_din,   cs_n_din,
                          csw_din,  csw_n_din,
                          cw_din,   cw_n_din,
                          cnw_din,  cnw_n_din;

    wire [DATA_WIDTH-1:0] c0_dout   = {DATA_WIDTH{1'b0}},
                          c0_n_dout = {DATA_WIDTH{1'b0}},
                          cn_dout   = {DATA_WIDTH{1'b0}},
                          cn_n_dout = {DATA_WIDTH{1'b0}},
                          cne_dout  = {DATA_WIDTH{1'b0}},
                          cne_n_dout= {DATA_WIDTH{1'b0}},
                          ce_dout   = {DATA_WIDTH{1'b0}},
                          ce_n_dout = {DATA_WIDTH{1'b0}},
                          cse_dout  = {DATA_WIDTH{1'b0}},
                          cse_n_dout= {DATA_WIDTH{1'b0}},
                          cs_dout   = {DATA_WIDTH{1'b0}},
                          cs_n_dout = {DATA_WIDTH{1'b0}},
                          csw_dout  = {DATA_WIDTH{1'b0}},
                          csw_n_dout= {DATA_WIDTH{1'b0}},
                          cw_dout   = {DATA_WIDTH{1'b0}},
                          cw_n_dout = {DATA_WIDTH{1'b0}},
                          cnw_dout  = {DATA_WIDTH{1'b0}},
                          cnw_n_dout= {DATA_WIDTH{1'b0}};

    //------------------------------------------------------------------
    //  Instantiate solver
    //------------------------------------------------------------------
    LBMSolverCache u_solver (
        .clk                   (clk),
        .rst                   (rstn),
        .barriers              (barriers),
        .en                    (en),
        .step                  (step),
        .omega                 (omega),

        // Handshake to loader
        .chunk_compute_ready   (chunk_compute_ready),
        .chunk_transfer_ready  (chunk_transfer_ready),

        // Debug probe
        .testing_cs_n_data_in  (test_cs_n_data),

        .init_c0  (init_c0 ), .init_cn (init_cn ), .init_cne(init_cne),
        .init_ce  (init_ce ), .init_cse(init_cse), .init_cs (init_cs ),
        .init_csw (init_csw), .init_cw (init_cw ), .init_cnw(init_cnw),

        // ── c0 ───────────────────────────────────────────
        .c0_addr      (c0_addr),    .c0_data_in   (c0_din),    .c0_write_en   (c0_we),
        .c0_data_out  (c0_dout),
        .c0_n_addr    (c0_n_addr),  .c0_n_data_in (c0_n_din),  .c0_n_write_en (c0_n_we),
        .c0_n_data_out(c0_n_dout),

        // ── cn ───────────────────────────────────────────
        .cn_addr      (cn_addr),    .cn_data_in   (cn_din),    .cn_write_en   (cn_we),
        .cn_data_out  (cn_dout),
        .cn_n_addr    (cn_n_addr),  .cn_n_data_in (cn_n_din),  .cn_n_write_en (cn_n_we),
        .cn_n_data_out(cn_n_dout),

        // ── cne ──────────────────────────────────────────
        .cne_addr     (cne_addr),   .cne_data_in  (cne_din),   .cne_write_en  (cne_we),
        .cne_data_out (cne_dout),
        .cne_n_addr   (cne_n_addr), .cne_n_data_in(cne_n_din), .cne_n_write_en(cne_n_we),
        .cne_n_data_out(cne_n_dout),

        // ── ce ───────────────────────────────────────────
        .ce_addr      (ce_addr),    .ce_data_in   (ce_din),    .ce_write_en   (ce_we),
        .ce_data_out  (ce_dout),
        .ce_n_addr    (ce_n_addr),  .ce_n_data_in (ce_n_din),  .ce_n_write_en (ce_n_we),
        .ce_n_data_out(ce_n_dout),

        // ── cse ──────────────────────────────────────────
        .cse_addr     (cse_addr),   .cse_data_in  (cse_din),   .cse_write_en  (cse_we),
        .cse_data_out (cse_dout),
        .cse_n_addr   (cse_n_addr), .cse_n_data_in(cse_n_din), .cse_n_write_en(cse_n_we),
        .cse_n_data_out(cse_n_dout),

        // ── cs ───────────────────────────────────────────
        .cs_addr      (cs_addr),    .cs_data_in   (cs_din),    .cs_write_en   (cs_we),
        .cs_data_out  (cs_dout),
        .cs_n_addr    (cs_n_addr),  .cs_n_data_in (cs_n_din),  .cs_n_write_en (cs_n_we),
        .cs_n_data_out(cs_n_dout),

        // ── csw ──────────────────────────────────────────
        .csw_addr     (csw_addr),   .csw_data_in  (csw_din),   .csw_write_en  (csw_we),
        .csw_data_out (csw_dout),
        .csw_n_addr   (csw_n_addr), .csw_n_data_in(csw_n_din), .csw_n_write_en(csw_n_we),
        .csw_n_data_out(csw_n_dout),

        // ── cw ───────────────────────────────────────────
        .cw_addr      (cw_addr),    .cw_data_in   (cw_din),    .cw_write_en   (cw_we),
        .cw_data_out  (cw_dout),
        .cw_n_addr    (cw_n_addr),  .cw_n_data_in (cw_n_din),  .cw_n_write_en (cw_n_we),
        .cw_n_data_out(cw_n_dout),

        // ── cnw ──────────────────────────────────────────
        .cnw_addr     (cnw_addr),   .cnw_data_in  (cnw_din),   .cnw_write_en  (cnw_we),
        .cnw_data_out (cnw_dout),
        .cnw_n_addr   (cnw_n_addr), .cnw_n_data_in(cnw_n_din), .cnw_n_write_en(cnw_n_we),
        .cnw_n_data_out(cnw_n_dout),

        // ── results / status ─────────────────────────────
        .u_x                 (u_x),
        .u_y                 (u_y),
        .rho                 (rho),
        .u_squared           (u_squared),
        .collider_ready      (collider_ready),
        .in_collision_state  (in_collision_state),
        .step_countn         (step_count)
    );

    // Hook a representative address for cache mux demo
    assign lbm_addr = c0_addr;

endmodule
