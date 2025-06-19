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
    wire                   chunk_compute_ready;
    wire                   chunk_transfer_ready;
    wire                   wen;
    wire                   DDR_wen;

    // AXI‑Stream wires
    wire                   axis_tvalid;
    wire                   axis_tready;
    wire                   axis_tlast;
    wire [AXIS_DATA_WIDTH-1:0] axis_tdata;
    wire [(AXIS_DATA_WIDTH/8)-1:0] axis_tstrb;

    // Shared addresses
    wire [ADDRESS_WIDTH-1:0] bram_read_addr;
    wire [ADDRESS_WIDTH-1:0] DDR_write_addr;
    wire [ADDRESS_WIDTH-1:0] lbm_addr;
    wire [ADDRESS_WIDTH-1:0] cache_addr;   // (unused in this dummy RAM setup)

    // Nine direction buses (current step read by BRAM_ctrl; new data written
    // by DDR_pixel_out) – rest,  N, NE,  E, SE,  S, SW,  W, NW
    wire [DATA_WIDTH-1:0] DDR_null1, DDR_n1, DDR_ne1, DDR_e1, DDR_se1, DDR_s1, DDR_sw1, DDR_w1, DDR_nw1;
    wire [DATA_WIDTH-1:0] BRAM_ctrl_null1, BRAM_ctrl_n1, BRAM_ctrl_ne1, BRAM_ctrl_e1, BRAM_ctrl_se1, BRAM_ctrl_s1, BRAM_ctrl_sw1, BRAM_ctrl_w1, BRAM_ctrl_nw1;

    wire [ADDRESS_WIDTH-1:0] BRAM_c0_addr, BRAM_cn_addr, BRAM_cne_addr, BRAM_ce_addr, BRAM_cse_addr, BRAM_cs_addr, BRAM_csw_addr, BRAM_cw_addr, BRAM_cnw_addr;
    wire [`DATA_WIDTH-1:0]   BRAM_c0_data_in, BRAM_cn_data_in, BRAM_cne_data_in, BRAM_ce_data_in, BRAM_cse_data_in, BRAM_cs_data_in, BRAM_csw_data_in, BRAM_cw_data_in, BRAM_cnw_data_in;
    wire                     BRAM_c0_write_en, BRAM_cn_write_en, BRAM_cne_write_en, BRAM_ce_write_en, BRAM_cse_write_en, BRAM_cs_write_en, BRAM_csw_write_en, BRAM_cw_write_en, BRAM_cnw_write_en;
    wire [`DATA_WIDTH-1:0]   BRAM_c0_data_out, BRAM_cn_data_out, BRAM_cne_data_out, BRAM_ce_data_out, BRAM_cse_data_out, BRAM_cs_data_out, BRAM_csw_data_out, BRAM_cw_data_out, BRAM_cnw_data_out;

    RAM_2500 #(.INIT_FILE("ram.mem")) c0     (.clk(clk), .addr(BRAM_c0_addr),  .data_in(BRAM_c0_data_in),   .write_en(BRAM_c0_write_en),   .data_out(BRAM_c0_data_out));
    RAM_2500 #(.INIT_FILE("ram.mem")) cn     (.clk(clk), .addr(BRAM_cn_addr),  .data_in(BRAM_cn_data_in),   .write_en(BRAM_cn_write_en),   .data_out(BRAM_cn_data_out));
    RAM_2500 #(.INIT_FILE("ram.mem")) cne    (.clk(clk), .addr(BRAM_cne_addr), .data_in(BRAM_cne_data_in),  .write_en(BRAM_cne_write_en),  .data_out(BRAM_cne_data_out));
    RAM_2500 #(.INIT_FILE("ram.mem")) ce     (.clk(clk), .addr(BRAM_ce_addr),  .data_in(BRAM_ce_data_in),   .write_en(BRAM_ce_write_en),   .data_out(BRAM_ce_data_out));
    RAM_2500 #(.INIT_FILE("ram.mem")) cse    (.clk(clk), .addr(BRAM_cse_addr), .data_in(BRAM_cse_data_in),  .write_en(BRAM_cse_write_en),  .data_out(BRAM_cse_data_out));
    RAM_2500 #(.INIT_FILE("ram.mem")) cs     (.clk(clk), .addr(BRAM_cs_addr),  .data_in(BRAM_cs_data_in),   .write_en(BRAM_cs_write_en),   .data_out(BRAM_cs_data_out));
    RAM_2500 #(.INIT_FILE("ram.mem")) csw    (.clk(clk), .addr(BRAM_csw_addr), .data_in(BRAM_csw_data_in),  .write_en(BRAM_csw_write_en),  .data_out(BRAM_csw_data_out));
    RAM_2500 #(.INIT_FILE("ram.mem")) cw     (.clk(clk), .addr(BRAM_cw_addr),  .data_in(BRAM_cw_data_in),   .write_en(BRAM_cw_write_en),   .data_out(BRAM_cw_data_out));
    RAM_2500 #(.INIT_FILE("ram.mem")) cnw    (.clk(clk), .addr(BRAM_cnw_addr), .data_in(BRAM_cnw_data_in),  .write_en(BRAM_cnw_write_en),  .data_out(BRAM_cnw_data_out));



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
                    mem_cur[DDR_write_addr] <= axis_tdata[dir*DATA_WIDTH +: DATA_WIDTH];

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
        .null1   (BRAM_ctrl_null1),
        .n1      (BRAM_ctrl_n1),
        .ne1     (BRAM_ctrl_ne1),
        .e1      (BRAM_ctrl_e1),
        .se1     (BRAM_ctrl_se1),
        .s1      (BRAM_ctrl_s1),
        .sw1     (BRAM_ctrl_sw1),
        .w1      (BRAM_ctrl_w1),
        .nw1     (BRAM_ctrl_nw1),
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
        .null1              (DDR_null1),
        .n1                 (DDR_n1),
        .ne1                (DDR_ne1),
        .e1                 (DDR_e1),
        .se1                (DDR_se1),
        .s1                 (DDR_s1),
        .sw1                (DDR_sw1),
        .w1                 (DDR_w1),
        .nw1                (DDR_nw1),
        .wen                (DDR_wen),
        .chunk_transfer_ready(chunk_transfer_ready),
        .chunk_compute_ready (chunk_compute_ready),
        .write_addr         (DDR_write_addr),
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
        .m00_axis_aclk        (clk),
        .m00_axis_aresetn     (rstn),
        .chunk_transfer_ready (chunk_transfer_ready),
        .chunk_compute_ready  (chunk_compute_ready),

        .null1       (LBM_c0_addr), .n1       (LBM_cn_addr),   .ne1      (LBM_cne_addr), .e1      (LBM_ce_addr),
        .se1         (LBM_cse_addr), .s1      (LBM_cs_addr),   .sw1      (LBM_csw_addr), .w1      (LBM_cw_addr), .nw1      (LBM_cnw_addr),

        .LBM_null_w  (LBM_c0_we),    .LBM_n_w (LBM_cn_we),     .LBM_ne_w (LBM_cne_we),   .LBM_e_w (LBM_ce_we),
        .LBM_se_w    (LBM_cse_we),   .LBM_s_w (LBM_cs_we),     .LBM_sw_w (LBM_csw_we),   .LBM_w_w (LBM_cw_we),   .LBM_nw_w (LBM_cnw_we),

        .LBM_null_in (LBM_c0_din),   .LBM_n_in (LBM_cn_din),   .LBM_ne_in (LBM_cne_din), .LBM_e_in (LBM_ce_din),
        .LBM_se_in   (LBM_cse_din),  .LBM_s_in (LBM_cs_din),   .LBM_sw_in (LBM_csw_din), .LBM_w_in (LBM_cw_din), .LBM_nw_in (LBM_cnw_din),

        .LBM_null_out(LBM_c0_dout),  .LBM_n_out (LBM_cn_dout), .LBM_ne_out (LBM_cne_dout), .LBM_e_out (LBM_ce_dout), .LBM_se_out (LBM_cse_dout),
        .LBM_s_out   (LBM_cs_dout),  .LBM_sw_out (LBM_csw_dout), .LBM_w_out (LBM_cw_dout), .LBM_nw_out (LBM_cnw_dout),

        .cache_null_in (DDR_null1), .cache_n_in (DDR_n1), .cache_ne_in (DDR_ne1), .cache_e_in (DDR_e1), 
        .cache_se_in (DDR_se1), .cache_s_in (DDR_s1), .cache_sw_in (DDR_sw1), .cache_w_in (DDR_w1), .cache_nw_in (DDR_nw1),

        .cache_null_out (BRAM_ctrl_null1), .cache_n_out (BRAM_ctrl_n1), .cache_ne_out (BRAM_ctrl_ne1), .cache_e_out (BRAM_ctrl_e1), .cache_se_out (BRAM_ctrl_se1),
        .cache_s_out (BRAM_ctrl_s1), .cache_sw_out (BRAM_ctrl_sw1), .cache_w_out (BRAM_ctrl_w1), .cache_nw_out (BRAM_ctrl_nw1),

        .DDR_addr (DDR_write_addr),
        .cache_wen (DDR_wen),

        .null1_data_in (BRAM_c0_data_in), .n1_data_in    (BRAM_cn_data_in),  .ne1_data_in (BRAM_cne_data_in), .e1_data_in  (BRAM_ce_data_in), 
        .se1_data_in   (BRAM_cse_data_in), .s1_data_in   (BRAM_cs_data_in),  .sw1_data_in (BRAM_csw_data_in), .w1_data_in  (BRAM_cw_data_in), .nw1_data_in   (BRAM_cnw_data_in),

        .null1_data_out (BRAM_c0_data_out), .n1_data_out  (BRAM_cn_data_out),  .ne1_data_out (BRAM_cne_data_out), .e1_data_out  (BRAM_ce_data_out), 
        .se1_data_out   (BRAM_cse_data_out), .s1_data_out (BRAM_cs_data_out),  .sw1_data_out (BRAM_csw_data_out), .w1_data_out  (BRAM_cw_data_out), .nw1_data_out   (BRAM_cnw_data_out),

        .null1_wen (BRAM_c0_write_en), .n1_wen  (BRAM_cn_write_en),  .ne1_wen (BRAM_cne_write_en), .e1_wen  (BRAM_ce_write_en), 
        .se1_wen   (BRAM_cse_write_en), .s1_wen (BRAM_cs_write_en),  .sw1_wen (BRAM_csw_write_en), .w1_wen  (BRAM_cw_write_en), .nw1_wen   (BRAM_cnw_write_en),


        .null1_out (BRAM_c0_addr), .n1_out  (BRAM_cn_addr),  .ne1_out (BRAM_cne_addr), .e1_out  (BRAM_ce_addr), 
        .se1_out   (BRAM_cse_addr), .s1_out (BRAM_cs_addr),  .sw1_out (BRAM_csw_addr), .w1_out  (BRAM_cw_addr), .nw1_out   (BRAM_cnw_addr)
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
    wire [ADDRESS_WIDTH-1:0] 
    LBM_c0_addr,   LBM_c0_n_addr,
    LBM_cn_addr,   LBM_cn_n_addr,
    LBM_cne_addr,  LBM_cne_n_addr,
    LBM_ce_addr,   LBM_ce_n_addr,
    LBM_cse_addr,  LBM_cse_n_addr,
    LBM_cs_addr,   LBM_cs_n_addr,
    LBM_csw_addr,  LBM_csw_n_addr,
    LBM_cw_addr,   LBM_cw_n_addr,
    LBM_cnw_addr,  LBM_cnw_n_addr;


    //  Write‑enables
    wire 
    LBM_c0_we,   LBM_c0_n_we,
    LBM_cn_we,   LBM_cn_n_we,
    LBM_cne_we,  LBM_cne_n_we,
    LBM_ce_we,   LBM_ce_n_we,
    LBM_cse_we,  LBM_cse_n_we,
    LBM_cs_we,   LBM_cs_n_we,
    LBM_csw_we,  LBM_csw_n_we,
    LBM_cw_we,   LBM_cw_n_we,
    LBM_cnw_we,  LBM_cnw_n_we;


    //  Data buses in/out (solver ⇄ RAM)
    wire [DATA_WIDTH-1:0] 
    LBM_c0_din,   LBM_c0_n_din,
    LBM_cn_din,   LBM_cn_n_din,
    LBM_cne_din,  LBM_cne_n_din,
    LBM_ce_din,   LBM_ce_n_din,
    LBM_cse_din,  LBM_cse_n_din,
    LBM_cs_din,   LBM_cs_n_din,
    LBM_csw_din,  LBM_csw_n_din,
    LBM_cw_din,   LBM_cw_n_din,
    LBM_cnw_din,  LBM_cnw_n_din;


    wire [DATA_WIDTH-1:0] 
    LBM_c0_dout     = {DATA_WIDTH{1'b0}}, LBM_c0_n_dout  = {DATA_WIDTH{1'b0}},
    LBM_cn_dout     = {DATA_WIDTH{1'b0}}, LBM_cn_n_dout  = {DATA_WIDTH{1'b0}},
    LBM_cne_dout    = {DATA_WIDTH{1'b0}}, LBM_cne_n_dout = {DATA_WIDTH{1'b0}},
    LBM_ce_dout     = {DATA_WIDTH{1'b0}}, LBM_ce_n_dout  = {DATA_WIDTH{1'b0}},
    LBM_cse_dout    = {DATA_WIDTH{1'b0}}, LBM_cse_n_dout = {DATA_WIDTH{1'b0}},
    LBM_cs_dout     = {DATA_WIDTH{1'b0}}, LBM_cs_n_dout  = {DATA_WIDTH{1'b0}},
    LBM_csw_dout    = {DATA_WIDTH{1'b0}}, LBM_csw_n_dout = {DATA_WIDTH{1'b0}},
    LBM_cw_dout     = {DATA_WIDTH{1'b0}}, LBM_cw_n_dout  = {DATA_WIDTH{1'b0}},
    LBM_cnw_dout    = {DATA_WIDTH{1'b0}}, LBM_cnw_n_dout = {DATA_WIDTH{1'b0}};


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
        .c0_addr      (LBM_c0_addr),    .c0_data_in   (LBM_c0_din),    .c0_write_en   (LBM_c0_we),
        .c0_data_out  (LBM_c0_dout),
        .c0_n_addr    (LBM_c0_n_addr),  .c0_n_data_in (LBM_c0_n_din),  .c0_n_write_en (LBM_c0_n_we),
        .c0_n_data_out(LBM_c0_n_dout),

        // ── cn ───────────────────────────────────────────
        .cn_addr      (LBM_cn_addr),    .cn_data_in   (LBM_cn_din),    .cn_write_en   (LBM_cn_we),
        .cn_data_out  (LBM_cn_dout),
        .cn_n_addr    (LBM_cn_n_addr),  .cn_n_data_in (LBM_cn_n_din),  .cn_n_write_en (LBM_cn_n_we),
        .cn_n_data_out(LBM_cn_n_dout),

        // ── cne ──────────────────────────────────────────
        .cne_addr     (LBM_cne_addr),   .cne_data_in  (LBM_cne_din),   .cne_write_en  (LBM_cne_we),
        .cne_data_out (LBM_cne_dout),
        .cne_n_addr   (LBM_cne_n_addr), .cne_n_data_in(LBM_cne_n_din), .cne_n_write_en(LBM_cne_n_we),
        .cne_n_data_out(LBM_cne_n_dout),

        // ── ce ───────────────────────────────────────────
        .ce_addr      (LBM_ce_addr),    .ce_data_in   (LBM_ce_din),    .ce_write_en   (LBM_ce_we),
        .ce_data_out  (LBM_ce_dout),
        .ce_n_addr    (LBM_ce_n_addr),  .ce_n_data_in (LBM_ce_n_din),  .ce_n_write_en (LBM_ce_n_we),
        .ce_n_data_out(LBM_ce_n_dout),

        // ── cse ──────────────────────────────────────────
        .cse_addr     (LBM_cse_addr),   .cse_data_in  (LBM_cse_din),   .cse_write_en  (LBM_cse_we),
        .cse_data_out (LBM_cse_dout),
        .cse_n_addr   (LBM_cse_n_addr), .cse_n_data_in(LBM_cse_n_din), .cse_n_write_en(LBM_cse_n_we),
        .cse_n_data_out(LBM_cse_n_dout),

        // ── cs ───────────────────────────────────────────
        .cs_addr      (LBM_cs_addr),    .cs_data_in   (LBM_cs_din),    .cs_write_en   (LBM_cs_we),
        .cs_data_out  (LBM_cs_dout),
        .cs_n_addr    (LBM_cs_n_addr),  .cs_n_data_in (LBM_cs_n_din),  .cs_n_write_en (LBM_cs_n_we),
        .cs_n_data_out(LBM_cs_n_dout),

        // ── csw ──────────────────────────────────────────
        .csw_addr     (LBM_csw_addr),   .csw_data_in  (LBM_csw_din),   .csw_write_en  (LBM_csw_we),
        .csw_data_out (LBM_csw_dout),
        .csw_n_addr   (LBM_csw_n_addr), .csw_n_data_in(LBM_csw_n_din), .csw_n_write_en(LBM_csw_n_we),
        .csw_n_data_out(LBM_csw_n_dout),

        // ── cw ───────────────────────────────────────────
        .cw_addr      (LBM_cw_addr),    .cw_data_in   (LBM_cw_din),    .cw_write_en   (LBM_cw_we),
        .cw_data_out  (LBM_cw_dout),
        .cw_n_addr    (LBM_cw_n_addr),  .cw_n_data_in (LBM_cw_n_din),  .cw_n_write_en (LBM_cw_n_we),
        .cw_n_data_out(LBM_cw_n_dout),

        // ── cnw ──────────────────────────────────────────
        .cnw_addr     (LBM_cnw_addr),   .cnw_data_in  (LBM_cnw_din),   .cnw_write_en  (LBM_cnw_we),
        .cnw_data_out (LBM_cnw_dout),
        .cnw_n_addr   (LBM_cnw_n_addr), .cnw_n_data_in(LBM_cnw_n_din), .cnw_n_write_en(LBM_cnw_n_we),
        .cnw_n_data_out(LBM_cnw_n_dout),

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
    assign lbm_addr = LBM_c0_addr;

endmodule
