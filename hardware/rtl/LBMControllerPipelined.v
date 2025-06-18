`timescale 1ps / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 28.05.2025 18:44:59
// Design Name: 
// Module Name: LBMController
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


`include "def.vh" 

module LBMControllerPipelined (

    // TEMPORARILY MAKING THE STEP CONTROLLED VIA GPIO SO EASIER TO TEST
    input wire clk,
    input wire rst,
    input wire [`DEPTH-1:0] barriers,
    input wire en,
    input wire [31:0] step, // will step until sim value
    input wire signed [15:0] omega, // 1/tau
    
    // BRAM c0
    output reg  [`ADDRESS_WIDTH-1:0]    c0_addr,
    output reg  [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0]       c0_data_in, 
    output reg                          c0_write_en,
    input  wire [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0]       c0_data_out,

    // BRAM c0_n
    output reg  [`ADDRESS_WIDTH-1:0]    c0_n_addr,
    output reg  [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0]       c0_n_data_in, 
    output reg                          c0_n_write_en,
    input  wire [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0]       c0_n_data_out,
    

    // BRAM cn
    output reg  [`ADDRESS_WIDTH-1:0]    cn_addr,
    output reg  [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0]       cn_data_in, 
    output reg                          cn_write_en,
    input  wire [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0]       cn_data_out,

    // BRAM cn_n
    output reg  [`ADDRESS_WIDTH-1:0]    cn_n_addr,
    output reg  [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0]       cn_n_data_in, 
    output reg                          cn_n_write_en,
    input  wire [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0]       cn_n_data_out,
    

    // BRAM cne
    output reg  [`ADDRESS_WIDTH-1:0]    cne_addr,
    output reg  [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0]       cne_data_in, 
    output reg                          cne_write_en,
    input  wire [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0]       cne_data_out,

    // BRAM cne_n
    output reg  [`ADDRESS_WIDTH-1:0]    cne_n_addr,
    output reg  [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0]       cne_n_data_in, 
    output reg                          cne_n_write_en,
    input  wire [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0]       cne_n_data_out,
    

    // BRAM ce
    output reg  [`ADDRESS_WIDTH-1:0]    ce_addr,
    output reg  [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0]       ce_data_in, 
    output reg                          ce_write_en,
    input  wire [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0]       ce_data_out,

    // BRAM ce_n
    output reg  [`ADDRESS_WIDTH-1:0]    ce_n_addr,
    output reg  [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0]       ce_n_data_in, 
    output reg                          ce_n_write_en,
    input  wire [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0]       ce_n_data_out,
    

    // BRAM cse
    output reg  [`ADDRESS_WIDTH-1:0]    cse_addr,
    output reg  [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0]       cse_data_in, 
    output reg                          cse_write_en,
    input  wire [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0]       cse_data_out,

    // BRAM cse_n
    output reg  [`ADDRESS_WIDTH-1:0]    cse_n_addr,
    output reg  [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0]       cse_n_data_in, 
    output reg                          cse_n_write_en,
    input  wire [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0]       cse_n_data_out,
    

    // BRAM cs
    output reg  [`ADDRESS_WIDTH-1:0]    cs_addr,
    output reg  [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0]       cs_data_in, 
    output reg                          cs_write_en,
    input  wire [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0]       cs_data_out,

    // BRAM cs_n
    output reg  [`ADDRESS_WIDTH-1:0]    cs_n_addr,
    output reg  [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0]       cs_n_data_in, 
    output reg                          cs_n_write_en,
    input  wire [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0]       cs_n_data_out,
    

    // BRAM csw
    output reg  [`ADDRESS_WIDTH-1:0]    csw_addr,
    output reg  [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0]       csw_data_in, 
    output reg                          csw_write_en,
    input  wire [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0]       csw_data_out,

    // BRAM csw_n
    output reg  [`ADDRESS_WIDTH-1:0]    csw_n_addr,
    output reg  [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0]       csw_n_data_in, 
    output reg                          csw_n_write_en,
    input  wire [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0]       csw_n_data_out,
    

    // BRAM cw
    output reg  [`ADDRESS_WIDTH-1:0]    cw_addr,
    output reg  [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0]       cw_data_in, 
    output reg                          cw_write_en,
    input  wire [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0]       cw_data_out,

    // BRAM cw_n
    output reg  [`ADDRESS_WIDTH-1:0]    cw_n_addr,
    output reg  [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0]       cw_n_data_in, 
    output reg                          cw_n_write_en,
    input  wire [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0]       cw_n_data_out,
    

    // BRAM cnw
    output reg  [`ADDRESS_WIDTH-1:0]    cnw_addr,
    output reg  [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0]       cnw_data_in, 
    output reg                          cnw_write_en,
    input  wire [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0]       cnw_data_out,

    // BRAM cnw_n
    output reg  [`ADDRESS_WIDTH-1:0]    cnw_n_addr,
    output reg  [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0]       cnw_n_data_in, 
    output reg                          cnw_n_write_en,
    input  wire [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0]       cnw_n_data_out,
    
    input wire [`DATA_WIDTH-1:0]        init_c0,
    input wire [`DATA_WIDTH-1:0]        init_cn,
    input wire [`DATA_WIDTH-1:0]        init_cne,
    input wire [`DATA_WIDTH-1:0]        init_ce,
    input wire [`DATA_WIDTH-1:0]        init_cse,
    input wire [`DATA_WIDTH-1:0]        init_cs,
    input wire [`DATA_WIDTH-1:0]        init_csw,
    input wire [`DATA_WIDTH-1:0]        init_cw,
    input wire [`DATA_WIDTH-1:0]        init_cnw,

    // collider results
    output reg [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0] u_x, 
    output reg [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0] u_y,
    output reg [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0] u_squared, 
    output reg [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0] rho,
    
    output wire collider_ready,
    output wire in_collision_state

);

    //States
    localparam IDLE             = 4'd0;
    localparam STREAM           = 4'd1;
    localparam STREAM_READ      = 4'd2;
    localparam STREAM_WAIT      = 4'd3;      
    localparam BOUNDARY         = 4'd4;
    localparam BOUNCE           = 4'd5;
    localparam BOUNCE_READ      = 4'd6;
    localparam BOUNCE_WAIT      = 4'd7;
    localparam ZERO_BOUNCE      = 4'd8;
    localparam ZERO_BOUNCE_WAIT = 4'd9;
    localparam COLLIDE          = 4'd10;
    localparam MEM_RESET        = 4'd11;

    // Data-in buses
    wire [`DATA_WIDTH-1:0] c0_array_data_in     [0:`RAMS_TO_ACCESS-1];
    // wire [`DATA_WIDTH-1:0] c0_array_n_data_in   [0:`RAMS_TO_ACCESS-1];
    wire [`DATA_WIDTH-1:0] cn_array_data_in     [0:`RAMS_TO_ACCESS-1];
    // wire [`DATA_WIDTH-1:0] cn_array_n_data_in   [0:`RAMS_TO_ACCESS-1];
    wire [`DATA_WIDTH-1:0] cne_array_data_in    [0:`RAMS_TO_ACCESS-1];
    // wire [`DATA_WIDTH-1:0] cne_array_n_data_in  [0:`RAMS_TO_ACCESS-1];
    wire [`DATA_WIDTH-1:0] ce_array_data_in     [0:`RAMS_TO_ACCESS-1];
    // wire [`DATA_WIDTH-1:0] ce_array_n_data_in   [0:`RAMS_TO_ACCESS-1];
    wire [`DATA_WIDTH-1:0] cse_array_data_in    [0:`RAMS_TO_ACCESS-1];
    // wire [`DATA_WIDTH-1:0] cse_array_n_data_in  [0:`RAMS_TO_ACCESS-1];
    wire [`DATA_WIDTH-1:0] cs_array_data_in     [0:`RAMS_TO_ACCESS-1];
    // wire [`DATA_WIDTH-1:0] cs_array_n_data_in   [0:`RAMS_TO_ACCESS-1];
    wire [`DATA_WIDTH-1:0] csw_array_data_in    [0:`RAMS_TO_ACCESS-1];
    // wire [`DATA_WIDTH-1:0] csw_array_n_data_in  [0:`RAMS_TO_ACCESS-1];
    wire [`DATA_WIDTH-1:0] cw_array_data_in     [0:`RAMS_TO_ACCESS-1];
    // wire [`DATA_WIDTH-1:0] cw_array_n_data_in   [0:`RAMS_TO_ACCESS-1];
    wire [`DATA_WIDTH-1:0] cnw_array_data_in    [0:`RAMS_TO_ACCESS-1];
    // wire [`DATA_WIDTH-1:0] cnw_array_n_data_in  [0:`RAMS_TO_ACCESS-1];

    // Data-out from collider
    wire [`DATA_WIDTH-1:0] u_x_array        [0:`RAMS_TO_ACCESS-1];
    wire [`DATA_WIDTH-1:0] u_y_array        [0:`RAMS_TO_ACCESS-1];
    wire [`DATA_WIDTH-1:0] u_squared_array  [0:`RAMS_TO_ACCESS-1];
    wire [`DATA_WIDTH-1:0] rho_array        [0:`RAMS_TO_ACCESS-1];
    wire [`ADDRESS_WIDTH-1:0] newval_index_array        [0:`RAMS_TO_ACCESS-1];
    wire [`DATA_WIDTH-1:0] newval_width_count_array        [0:`RAMS_TO_ACCESS-1];


    // Write-enable and status bits
    wire [`RAMS_TO_ACCESS-1:0]  c0_array_write_en;
    wire [`RAMS_TO_ACCESS-1:0]  c0_array_n_write_en;

    wire [`RAMS_TO_ACCESS-1:0]  cn_array_write_en;
    wire [`RAMS_TO_ACCESS-1:0]  cn_array_n_write_en;

    wire [`RAMS_TO_ACCESS-1:0]  cne_array_write_en;
    wire [`RAMS_TO_ACCESS-1:0]  cne_array_n_write_en;

    wire [`RAMS_TO_ACCESS-1:0]  ce_array_write_en;
    wire [`RAMS_TO_ACCESS-1:0]  ce_array_n_write_en;

    wire [`RAMS_TO_ACCESS-1:0]  cse_array_write_en;
    wire [`RAMS_TO_ACCESS-1:0]  cse_array_n_write_en;

    wire [`RAMS_TO_ACCESS-1:0]  cs_array_write_en;
    wire [`RAMS_TO_ACCESS-1:0]  cs_array_n_write_en;

    wire [`RAMS_TO_ACCESS-1:0]  csw_array_write_en;
    wire [`RAMS_TO_ACCESS-1:0]  csw_array_n_write_en;

    wire [`RAMS_TO_ACCESS-1:0]  cw_array_write_en;
    wire [`RAMS_TO_ACCESS-1:0]  cw_array_n_write_en;

    wire [`RAMS_TO_ACCESS-1:0]  cnw_array_write_en;
    wire [`RAMS_TO_ACCESS-1:0]  cnw_array_n_write_en;

    wire collider_ready_array     [0:`RAMS_TO_ACCESS-1];
    wire in_collision_state_array  [0:`RAMS_TO_ACCESS-1];
    wire read_wait_array          [0:`RAMS_TO_ACCESS-1];
    wire zero_barrier_array [0:`RAMS_TO_ACCESS-1];
    wire newval_ready_array [0:`RAMS_TO_ACCESS-1];

    wire [2:0] next_sim_state_array [0:`RAMS_TO_ACCESS-1];
    wire [`RAMS_TO_ACCESS-1:0] is_bw;
    wire [`RAMS_TO_ACCESS-1:0] is_rw;
    wire [`RAMS_TO_ACCESS-1:0] is_zb;
    wire [`RAMS_TO_ACCESS-1:0] is_nv;
    wire [`RAMS_TO_ACCESS-1:0] is_cs;
    wire [`RAMS_TO_ACCESS-1:0] is_cr;
    reg [15:0] width_count, next_width_count;
    reg [3:0] sim_state, next_sim_state;
    reg [`ADDRESS_WIDTH-1:0] index;
    reg [`ADDRESS_WIDTH-1:0] next_index;
    
    // collider flags
    // wire c_busy;
    // wire newval_ready;
    // wire v_d_ready;
        
    reg [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0] c0_next_data_in, c0_n_stored_data, c0_n_next_stored_data;
    wire c0_next_write_en, c0_n_next_write_en;
    reg c0_n_read_from_write_address;
    reg [`ADDRESS_WIDTH-1:0] c0_next_write_addr;

    reg [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0] cn_next_data_in, cn_n_stored_data, cn_n_next_stored_data;
    wire cn_next_write_en, cn_n_next_write_en;
    reg cn_n_read_from_write_address;
    reg [`ADDRESS_WIDTH-1:0] cn_next_write_addr;

    reg [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0] cne_next_data_in, cne_n_stored_data, cne_n_next_stored_data;
    wire cne_next_write_en, cne_n_next_write_en;
    reg cne_n_read_from_write_address;
    reg [`ADDRESS_WIDTH-1:0] cne_next_write_addr;

    reg [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0] ce_next_data_in, ce_n_stored_data, ce_n_next_stored_data;
    wire ce_next_write_en, ce_n_next_write_en;
    reg ce_n_read_from_write_address;
    reg [`ADDRESS_WIDTH-1:0] ce_next_write_addr;

    reg [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0] cse_next_data_in, cse_n_stored_data, cse_n_next_stored_data;
    wire cse_next_write_en, cse_n_next_write_en;
    reg cse_n_read_from_write_address;
    reg [`ADDRESS_WIDTH-1:0] cse_next_write_addr;

    reg [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0] cs_next_data_in, cs_n_stored_data, cs_n_next_stored_data;
    wire cs_next_write_en, cs_n_next_write_en;
    reg cs_n_read_from_write_address;
    reg [`ADDRESS_WIDTH-1:0] cs_next_write_addr;

    reg [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0] csw_next_data_in, csw_n_stored_data, csw_n_next_stored_data;
    wire csw_next_write_en, csw_n_next_write_en;
    reg csw_n_read_from_write_address;
    reg [`ADDRESS_WIDTH-1:0] csw_next_write_addr;

    reg [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0] cw_next_data_in, cw_n_stored_data, cw_n_next_stored_data;
    wire cw_next_write_en, cw_n_next_write_en;
    reg cw_n_read_from_write_address;
    reg [`ADDRESS_WIDTH-1:0] cw_next_write_addr;

    reg [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0] cnw_next_data_in, cnw_n_stored_data, cnw_n_next_stored_data;
    wire cnw_next_write_en, cnw_n_next_write_en;
    reg cnw_n_read_from_write_address;
    reg [`ADDRESS_WIDTH-1:0] cnw_next_write_addr;


    reg [2:0] ram_wait_count, next_ram_wait_count;
    
    reg [15:0] step_count, next_step_count;

    reg incr_step;

    // wire [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0] c_c0,c_cn,c_cne,c_ce,c_cse,c_cs,c_csw,c_cw,c_cnw;
    
    // assign collider_ready = newval_ready && (sim_state == COLLIDE) && (ram_wait_count == 0); // ensure not waiting more on RAM
    // assign in_collision_state = (sim_state == COLLIDE);

    genvar i;
    generate
    for (i = 0; i < `RAMS_TO_ACCESS; i = i + 1) begin : g_solver
        wire [`ADDRESS_WIDTH-1:0] width_mod = (width_count + i) % `WIDTH;

        LBMSolverParallelPipelined LBMSolverParallelPipelined ( //potentially need to change the array data ins
            .clk            (clk),
            .rst            (rst),
            .barriers       (barriers),
            .en             (en),
            .step           (step),
            .omega          (omega),
            .sim_state      (sim_state),
            .index          (index + i),
            .width_count    (width_mod),
            .ram_wait_count (ram_wait_count),
            // ───────── c0 ─────────
            .c0_data_in    (c0_array_data_in   [i]),
            .c0_data_out   (c0_data_out        [(i*`DATA_WIDTH)+:`DATA_WIDTH]),
            .c0_write_en   (c0_array_write_en  [i]),
            .init_c0       (init_c0),

            // ───────── c0_n ───────
            // .c0_n_data_in  (c0_array_n_data_in [i]),
            .c0_n_data_out (c0_n_data_out      [(i*`DATA_WIDTH)+:`DATA_WIDTH]),
            .c0_n_write_en (c0_array_n_write_en[i]),

            // ───────── cn ─────────
            .cn_data_in    (cn_array_data_in   [i]),
            .cn_data_out   (cn_data_out        [(i*`DATA_WIDTH)+:`DATA_WIDTH]),
            .cn_write_en   (cn_array_write_en  [i]),
            .init_cn       (init_cn),

            // ───────── cn_n ───────
            // .cn_n_data_in  (cn_array_n_data_in [i]),
            .cn_n_data_out (cn_n_data_out      [(i*`DATA_WIDTH)+:`DATA_WIDTH]),
            .cn_n_write_en (cn_array_n_write_en[i]),

            // ───────── cne ────────
            .cne_data_in   (cne_array_data_in  [i]),
            .cne_data_out  (cne_data_out       [(i*`DATA_WIDTH)+:`DATA_WIDTH]),
            .cne_write_en  (cne_array_write_en [i]),
            .init_cne       (init_cne),

            // ───────── cne_n ──────
            // .cne_n_data_in (cne_array_n_data_in[i]),
            .cne_n_data_out(cne_n_data_out     [(i*`DATA_WIDTH)+:`DATA_WIDTH]),
            .cne_n_write_en(cne_array_n_write_en[i]),

            // ───────── ce ─────────
            .ce_data_in    (ce_array_data_in   [i]),
            .ce_data_out   (ce_data_out        [(i*`DATA_WIDTH)+:`DATA_WIDTH]),
            .ce_write_en   (ce_array_write_en  [i]),
            .init_ce       (init_ce),

            // ───────── ce_n ───────
            // .ce_n_data_in  (ce_array_n_data_in [i]),
            .ce_n_data_out (ce_n_data_out      [(i*`DATA_WIDTH)+:`DATA_WIDTH]),
            .ce_n_write_en (ce_array_n_write_en[i]),

            // ───────── cse ────────
            .cse_data_in   (cse_array_data_in  [i]),
            .cse_data_out  (cse_data_out       [(i*`DATA_WIDTH)+:`DATA_WIDTH]),
            .cse_write_en  (cse_array_write_en [i]),
            .init_cse       (init_cse),

            // ───────── cse_n ──────
            // .cse_n_data_in (cse_array_n_data_in[i]),
            .cse_n_data_out(cse_n_data_out     [(i*`DATA_WIDTH)+:`DATA_WIDTH]),
            .cse_n_write_en(cse_array_n_write_en[i]),

            // ───────── cs ─────────
            .cs_data_in    (cs_array_data_in   [i]),
            .cs_data_out   (cs_data_out        [(i*`DATA_WIDTH)+:`DATA_WIDTH]),
            .cs_write_en   (cs_array_write_en  [i]),
            .init_cs       (init_cs),

            // ───────── cs_n ───────
            // .cs_n_data_in  (cs_array_n_data_in [i]),
            .cs_n_data_out (cs_n_data_out      [(i*`DATA_WIDTH)+:`DATA_WIDTH]),
            .cs_n_write_en (cs_array_n_write_en[i]),

            // ───────── csw ────────
            .csw_data_in   (csw_array_data_in  [i]),
            .csw_data_out  (csw_data_out       [(i*`DATA_WIDTH)+:`DATA_WIDTH]),
            .csw_write_en  (csw_array_write_en [i]),
            .init_csw       (init_csw),

            // ───────── csw_n ──────
            // .csw_n_data_in (csw_array_n_data_in[i]),
            .csw_n_data_out(csw_n_data_out     [(i*`DATA_WIDTH)+:`DATA_WIDTH]),
            .csw_n_write_en(csw_array_n_write_en[i]),

            // ───────── cw ─────────
            .cw_data_in    (cw_array_data_in   [i]),
            .cw_data_out   (cw_data_out        [(i*`DATA_WIDTH)+:`DATA_WIDTH]),
            .cw_write_en   (cw_array_write_en  [i]),
            .init_cw       (init_cw),

            // ───────── cw_n ───────
            // .cw_n_data_in  (cw_array_n_data_in [i]),
            .cw_n_data_out (cw_n_data_out      [(i*`DATA_WIDTH)+:`DATA_WIDTH]),
            .cw_n_write_en (cw_array_n_write_en[i]),

            // ───────── cnw ────────
            .cnw_data_in   (cnw_array_data_in  [i]),
            .cnw_data_out  (cnw_data_out       [(i*`DATA_WIDTH)+:`DATA_WIDTH]),
            .cnw_write_en  (cnw_array_write_en [i]),
            .init_cnw       (init_cnw),

            // ───────── cnw_n ──────
            // .cnw_n_data_in (cnw_array_n_data_in[i]),
            .cnw_n_data_out(cnw_n_data_out     [(i*`DATA_WIDTH)+:`DATA_WIDTH]),
            .cnw_n_write_en(cnw_array_n_write_en[i]),

            // ───────── collider results (unchanged) ─────────
            .u_x                (u_x_array                [i]),
            .u_y                (u_y_array                [i]),
            .u_squared          (u_squared_array          [i]),
            .rho                (rho_array                [i]),
            .collider_ready     (collider_ready_array     [i]),
            .in_collision_state (in_collision_state_array [i]),
            .next_sim_state     (next_sim_state_array     [i]),
            .zero_barrier       (zero_barrier_array       [i]),
            .newval_ready       (newval_ready_array       [i]),
            .read_wait          (read_wait_array          [i]),
            .newval_index       (newval_index_array       [i]),
            .newval_width_count (newval_width_count_array [i])
        );


    end
    endgenerate

    genvar j;
    generate
    for (j = 0; j < `RAMS_TO_ACCESS; j = j + 1) begin : g_variable_assign
        // one procedural block per iteration
        always @* begin
        // rest
        u_x[(j*`DATA_WIDTH)+:`DATA_WIDTH] = u_x_array[j];
        u_y[(j*`DATA_WIDTH)+:`DATA_WIDTH] = u_y_array[j];
        u_squared[(j*`DATA_WIDTH)+:`DATA_WIDTH] = u_squared_array[j];
        rho[(j*`DATA_WIDTH)+:`DATA_WIDTH] = rho_array[j];
        c0_next_data_in[(j*`DATA_WIDTH)+:`DATA_WIDTH]
            = (c0_array_n_write_en[j] || c0_array_write_en[j])
            ? c0_array_data_in[j]
            : c0_n_stored_data[(j*`DATA_WIDTH)+:`DATA_WIDTH];

        // north
        cn_next_data_in[(j*`DATA_WIDTH)+:`DATA_WIDTH]
            = (cn_array_n_write_en[j]|| cn_array_write_en[j])
            ? cn_array_data_in[j]
            : cn_n_stored_data[(j*`DATA_WIDTH)+:`DATA_WIDTH];

        // north-east
        cne_next_data_in[(j*`DATA_WIDTH)+:`DATA_WIDTH]
            = (cne_array_n_write_en[j] || cne_array_write_en[j])
            ? cne_array_data_in[j]
            : cne_n_stored_data[(j*`DATA_WIDTH)+:`DATA_WIDTH];

        // east
        ce_next_data_in[(j*`DATA_WIDTH)+:`DATA_WIDTH]
            = (ce_array_n_write_en[j] || ce_array_write_en[j])
            ? ce_array_data_in[j]
            : ce_n_stored_data[(j*`DATA_WIDTH)+:`DATA_WIDTH];

        // south-east
        cse_next_data_in[(j*`DATA_WIDTH)+:`DATA_WIDTH]
            = (cse_array_n_write_en[j] || cse_array_write_en[j])
            ? cse_array_data_in[j]
            : cse_n_stored_data[(j*`DATA_WIDTH)+:`DATA_WIDTH];

        // south
        cs_next_data_in[(j*`DATA_WIDTH)+:`DATA_WIDTH]
            = (cs_array_n_write_en[j] || cs_array_write_en[j])
            ? cs_array_data_in[j]
            : cs_n_stored_data[(j*`DATA_WIDTH)+:`DATA_WIDTH];

        // south-west
        csw_next_data_in[(j*`DATA_WIDTH)+:`DATA_WIDTH]
            = (csw_array_n_write_en[j] || csw_array_write_en[j])
            ? csw_array_data_in[j]
            : csw_n_stored_data[(j*`DATA_WIDTH)+:`DATA_WIDTH];
        // west
        cw_next_data_in[(j*`DATA_WIDTH)+:`DATA_WIDTH]
            = (cw_array_n_write_en[j] || cw_array_write_en[j])
            ? cw_array_data_in[j]
            : cw_n_stored_data[(j*`DATA_WIDTH)+:`DATA_WIDTH];

        // north-west
        cnw_next_data_in[(j*`DATA_WIDTH)+:`DATA_WIDTH]
            = (cnw_array_n_write_en[j] || cnw_array_write_en[j])
            ? cnw_array_data_in[j]
            : cnw_n_stored_data[(j*`DATA_WIDTH)+:`DATA_WIDTH];
        end
    end
    endgenerate

    //reductions
    genvar k;
    generate
    for (k = 0; k < `RAMS_TO_ACCESS; k = k + 1) begin : g_bw
        assign is_bw[k] = (next_sim_state_array[k] == BOUNCE_WAIT);
        assign is_rw[k] = (read_wait_array[k]);
        assign is_zb[k] = (zero_barrier_array[k]);
        assign is_nv[k] = (newval_ready_array[k]);
        assign is_cs[k] = (in_collision_state_array[k]);
        assign is_cr[k] = (collider_ready_array[k]);
    end
    endgenerate

    assign in_collision_state = |is_cs;
    assign collider_ready = |is_cr;
    wire any_bounce_wait = |is_bw;
    wire all_bounce_wait = &is_bw;
    wire any_read_wait = |is_rw;
    wire any_zero_barrier = |is_zb;
    wire all_newval_ready = &is_nv;

    assign c0_next_write_en    = |c0_array_write_en;
    assign c0_n_next_write_en  = |c0_array_n_write_en;

    assign cn_next_write_en    = |cn_array_write_en;
    assign cn_n_next_write_en  = |cn_array_n_write_en;

    assign cne_next_write_en   = |cne_array_write_en;
    assign cne_n_next_write_en = |cne_array_n_write_en;

    assign ce_next_write_en    = |ce_array_write_en;
    assign ce_n_next_write_en  = |ce_array_n_write_en;

    assign cse_next_write_en   = |cse_array_write_en;
    assign cse_n_next_write_en = |cse_array_n_write_en;

    assign cs_next_write_en    = |cs_array_write_en;
    assign cs_n_next_write_en  = |cs_array_n_write_en;

    assign csw_next_write_en   = |csw_array_write_en;
    assign csw_n_next_write_en = |csw_array_n_write_en;

    assign cw_next_write_en    = |cw_array_write_en;
    assign cw_n_next_write_en  = |cw_array_n_write_en;

    assign cnw_next_write_en   = |cnw_array_write_en;
    assign cnw_n_next_write_en = |cnw_array_n_write_en;
    //Stores the 9 directions in their own RAM, I can't make each cell it's own block of memory, so instead I've decided to split the memory by direction
    //need two rams one for the current time step and one for the next time step

    // The actual RAM doesn't have 2 seperate addresses for reads and writes. so use single address lines - Nishant
    // Add 1 cycle delay for RAM reads - Nishant
    // note to self: cx and cx_n are driven by the same ADDR, DIN ports. just called cx
    // note: changed rst to be active low.

    //Stores the 9 directions in their own RAM, I can't make each cell it's own block of memory, so instead I've decided to split the memory by direction
    //need two rams one for the current time step and one for the next time step

    // The actual RAM doesn't have 2 seperate addresses for reads and writes. so use single address lines - Nishant
    // Add 1 cycle delay for RAM reads - Nishant
    // note to self: cx and cx_n are driven by the same ADDR, DIN ports. just called cx

    //Instantiate Nishant's collider

    //Update state
    always @(posedge clk or negedge rst)
    begin
        if(!rst) 
        begin
            sim_state <= MEM_RESET;
            index <= 0;
            width_count <= 0;
            ram_wait_count <= `RAM_READ_WAIT;
            step_count <= 0;

            c0_n_stored_data <= 0;
            cn_n_stored_data <= 0;
            cne_n_stored_data <= 0;
            ce_n_stored_data <= 0;
            cse_n_stored_data <= 0;
            cs_n_stored_data <= 0;
            csw_n_stored_data <= 0;
            cw_n_stored_data <= 0;
            cnw_n_stored_data <= 0;
        end
        else 
        begin
            sim_state <= next_sim_state;
            index <= next_index;
            width_count <= next_width_count;
            step_count <= incr_step ? step_count + 1 : step_count;
            ram_wait_count <= next_ram_wait_count;
            
            c0_addr <= c0_next_write_en ? c0_next_write_addr : index;
            c0_n_addr <= c0_n_read_from_write_address ? c0_next_write_addr : index;
            c0_write_en <= c0_next_write_en;
            c0_n_write_en <= c0_n_next_write_en;
            c0_data_in <= c0_next_data_in;
            c0_n_data_in <= c0_next_data_in;
            c0_n_stored_data <= c0_n_next_stored_data;

            cn_addr <= cn_next_write_en ? cn_next_write_addr : index;
            cn_n_addr <= cn_n_read_from_write_address ? cn_next_write_addr : index;
            cn_write_en <= cn_next_write_en;
            cn_n_write_en <= cn_n_next_write_en;
            cn_data_in <= cn_next_data_in;
            cn_n_data_in <= cn_next_data_in;
            cn_n_stored_data <= cn_n_next_stored_data;

            cne_addr <= cne_next_write_en ? cne_next_write_addr : index;
            cne_n_addr <= cne_n_read_from_write_address ? cne_next_write_addr : index;
            cne_write_en <= cne_next_write_en;
            cne_n_write_en <= cne_n_next_write_en;
            cne_data_in <= cne_next_data_in;
            cne_n_data_in <= cne_next_data_in;
            cne_n_stored_data <= cne_n_next_stored_data;

            ce_addr <= ce_next_write_en ? ce_next_write_addr : index;
            ce_n_addr <= ce_n_read_from_write_address ? ce_next_write_addr : index;
            ce_write_en <= ce_next_write_en;
            ce_n_write_en <= ce_n_next_write_en;
            ce_data_in <= ce_next_data_in;
            ce_n_data_in <= ce_next_data_in;
            ce_n_stored_data <= ce_n_next_stored_data;

            cse_addr <= cse_next_write_en ? cse_next_write_addr : index;
            cse_n_addr <= cse_n_read_from_write_address ? cse_next_write_addr : index;
            cse_write_en <= cse_next_write_en;
            cse_n_write_en <= cse_n_next_write_en;
            cse_data_in <= cse_next_data_in;
            cse_n_data_in <= cse_next_data_in;
            cse_n_stored_data <= cse_n_next_stored_data;

            cs_addr <= cs_next_write_en ? cs_next_write_addr : index;
            cs_n_addr <= cs_n_read_from_write_address ? cs_next_write_addr : index;
            cs_write_en <= cs_next_write_en;
            cs_n_write_en <= cs_n_next_write_en;
            cs_data_in <= cs_next_data_in;
            cs_n_data_in <= cs_next_data_in;
            cs_n_stored_data <= cs_n_next_stored_data;

            csw_addr <= csw_next_write_en ? csw_next_write_addr : index;
            csw_n_addr <= csw_n_read_from_write_address ? csw_next_write_addr : index;
            csw_write_en <= csw_next_write_en;
            csw_n_write_en <= csw_n_next_write_en;
            csw_data_in <= csw_next_data_in;
            csw_n_data_in <= csw_next_data_in;
            csw_n_stored_data <= csw_n_next_stored_data;

            cw_addr <= cw_next_write_en ? cw_next_write_addr : index;
            cw_n_addr <= cw_n_read_from_write_address ? cw_next_write_addr : index;
            cw_write_en <= cw_next_write_en;
            cw_n_write_en <= cw_n_next_write_en;
            cw_data_in <= cw_next_data_in;
            cw_n_data_in <= cw_next_data_in;
            cw_n_stored_data <= cw_n_next_stored_data;

            cnw_addr <= cnw_next_write_en ? cnw_next_write_addr : index;
            cnw_n_addr <= cnw_n_read_from_write_address ? cnw_next_write_addr : index;
            cnw_write_en <= cnw_next_write_en;
            cnw_n_write_en <= cnw_n_next_write_en;
            cnw_data_in <= cnw_next_data_in;
            cnw_n_data_in <= cnw_next_data_in;
            cnw_n_stored_data <= cnw_n_next_stored_data;
        end
    end


    //State Logic
    always @* begin
        c0_next_write_addr = 0;
        // c0_next_write_en = 0;
        // c0_n_next_write_en = 0;
        c0_n_next_stored_data = 0;
        c0_n_read_from_write_address = 0;

        cn_next_write_addr = 0;
        cn_n_next_stored_data = 0;
        cn_n_read_from_write_address = 0;

        cne_next_write_addr = 0;
        cne_n_next_stored_data = 0;
        cne_n_read_from_write_address = 0;

        ce_next_write_addr = 0;
        ce_n_next_stored_data = 0;
        ce_n_read_from_write_address = 0;

        cse_next_write_addr = 0;
        cse_n_next_stored_data = 0;
        cse_n_read_from_write_address = 0;

        cs_next_write_addr = 0;
        cs_n_next_stored_data = 0;
        cs_n_read_from_write_address = 0;

        csw_next_write_addr = 0;
        csw_n_next_stored_data = 0;
        csw_n_read_from_write_address = 0;

        cw_next_write_addr = 0;
        cw_n_next_stored_data = 0;
        cw_n_read_from_write_address = 0;

        cnw_next_write_addr = 0;
        cnw_n_next_stored_data = 0;
        cnw_n_read_from_write_address = 0;

        next_index = index;
        next_width_count = width_count;

        incr_step = 0;
        next_ram_wait_count = ram_wait_count;

        case(sim_state)
            IDLE: begin
                if(step >= step_count) begin
                    next_sim_state = STREAM;
                    next_ram_wait_count = `RAM_READ_WAIT;
                    next_index = 0;
                    next_width_count = 0;
                end
                else
                    next_sim_state = IDLE;
            end
            STREAM:
            begin
                if(any_read_wait) 
                begin
                    next_ram_wait_count = `RAM_READ_WAIT;
                    next_sim_state = STREAM_READ;

                    c0_next_write_addr = index;
                    c0_n_read_from_write_address = 1'b1;

                    cn_next_write_addr = index-`WIDTH;
                    cn_n_read_from_write_address = 1'b1;

                    cne_next_write_addr = index-`WIDTH+1;
                    cne_n_read_from_write_address = 1'b1;
                    
                    ce_next_write_addr = index+1;
                    ce_n_read_from_write_address = 1'b1;

                    cse_next_write_addr = index+`WIDTH+1;
                    cse_n_read_from_write_address = 1'b1;   

                    cs_next_write_addr = index+`WIDTH;
                    cs_n_read_from_write_address = 1'b1;

                    csw_next_write_addr = index+`WIDTH-1;
                    csw_n_read_from_write_address = 1'b1;

                    cw_next_write_addr = index - 1;
                    cw_n_read_from_write_address = 1'b1;

                    cnw_next_write_addr = index - 1 - `WIDTH;
                    cnw_n_read_from_write_address = 1'b1;
                end  
                else if(index+`RAMS_TO_ACCESS >= `DEPTH-1) 
                begin
                    next_sim_state = BOUNCE;
                    next_index = 0;
                    next_width_count = 0;
                end
                else
                begin
                    next_sim_state = STREAM;
                    next_index = index + `RAMS_TO_ACCESS;
                    next_width_count = (width_count+`RAMS_TO_ACCESS >= `WIDTH-1) ? (`RAMS_TO_ACCESS+width_count)%(`WIDTH) : (width_count + `RAMS_TO_ACCESS);
                end  
            end
            STREAM_READ:
            begin
                if(ram_wait_count > 0) begin
                    next_ram_wait_count = ram_wait_count - 1;
                    next_sim_state = STREAM_READ;
                    next_index = index;
                    next_width_count = width_count;
                end
                else
                begin
                    c0_n_next_stored_data = c0_n_data_out;

                    cn_n_next_stored_data = cn_n_data_out;

                    cne_n_next_stored_data = cne_n_data_out;

                    ce_n_next_stored_data = ce_n_data_out;

                    cse_n_next_stored_data = cse_n_data_out;

                    cs_n_next_stored_data = cs_n_data_out;

                    csw_n_next_stored_data = csw_n_data_out;

                    cw_n_next_stored_data = cw_n_data_out;

                    cnw_n_next_stored_data = cnw_n_data_out;

                    next_sim_state = STREAM_WAIT;
                    next_ram_wait_count = `RAM_READ_WAIT;
                    next_index = index;
                    next_width_count = width_count;
                end
            end
            STREAM_WAIT : // do the outside too
            begin
                if(ram_wait_count > 0) begin
                    next_ram_wait_count = ram_wait_count - 1; 
                    next_sim_state = STREAM_WAIT;
                    next_index = index;
                    next_width_count = width_count;

                    c0_n_next_stored_data = c0_n_stored_data;

                    cn_n_next_stored_data = cn_n_stored_data;

                    cne_n_next_stored_data = cne_n_stored_data;

                    ce_n_next_stored_data = ce_n_stored_data;

                    cse_n_next_stored_data = cse_n_stored_data;

                    cs_n_next_stored_data = cs_n_stored_data;

                    csw_n_next_stored_data = csw_n_stored_data;

                    cw_n_next_stored_data = cw_n_stored_data;

                    cnw_n_next_stored_data = cnw_n_stored_data;
                end 
                else begin
                    
                    c0_next_write_addr = index;
                    c0_n_read_from_write_address = 1'b1;

                    cn_next_write_addr = index-`WIDTH; // write to cell above
                    cn_n_read_from_write_address = 1'b1;

                    cne_next_write_addr = index-`WIDTH+1;
                    cne_n_read_from_write_address = 1'b1;

                    ce_next_write_addr = index+1;
                    ce_n_read_from_write_address = 1'b1;

                    cse_next_write_addr = index+`WIDTH+1;
                    cse_n_read_from_write_address = 1'b1;

                    cs_next_write_addr = index+`WIDTH;
                    cs_n_read_from_write_address = 1'b1;

                    csw_next_write_addr = index+`WIDTH-1;
                    csw_n_read_from_write_address = 1'b1;

                    cw_next_write_addr = index - 1;
                    cw_n_read_from_write_address = 1'b1;

                    cnw_next_write_addr = index - 1 - `WIDTH;
                    cnw_n_read_from_write_address = 1'b1;

                    if(index + `RAMS_TO_ACCESS >= `DEPTH-1) 
                    begin
                        next_index = 0;
                        next_width_count = 0;
                        next_sim_state = BOUNCE;
                        
                    end
                    else
                    begin
                        next_index = index + `RAMS_TO_ACCESS;
                        next_width_count = (width_count+`RAMS_TO_ACCESS >= `WIDTH-1) ? (`RAMS_TO_ACCESS+width_count)%(`WIDTH) : (width_count + `RAMS_TO_ACCESS);
                        next_sim_state = STREAM;
                    end
                end
            end
            // BOUNDARY:
            // begin
            //     if(ram_wait_count > 0) begin
            //         next_ram_wait_count = ram_wait_count - 1;
            //         next_sim_state = BOUNDARY;
            //         next_index = index;
            //         next_width_count = width_count;

            //         c0_n_next_stored_data = c0_n_data_out;

            //         cn_n_next_stored_data = cn_n_data_out;

            //         cne_n_next_stored_data = cne_n_data_out;

            //         ce_n_next_stored_data = ce_n_data_out;

            //         cse_n_next_stored_data = cse_n_data_out;

            //         cs_n_next_stored_data = cs_n_data_out;

            //         csw_n_next_stored_data = csw_n_data_out;

            //         cw_n_next_stored_data = cw_n_data_out;

            //         cnw_n_next_stored_data = cnw_n_data_out;
            //     end
            //     else 
            //     begin
            //         if((index <= 2*`WIDTH - 2) && (index + `RAM_READ_WAIT >= 2*`WIDTH -2)) begin // NE corner
            //             csw_next_write_addr = `WIDTH - 1; 
            //             // csw_n_next_write_en = 1;
            //             cs_next_write_addr = `WIDTH - 2;
            //             // cs_n_next_write_en = 1;
            //             cw_next_write_addr = 2*`WIDTH - 1;
            //             // cw_n_next_write_en = 1;

            //             csw_n_read_from_write_address = 1'b1;
            //             cs_n_read_from_write_address = 1'b1;
            //             cw_n_read_from_write_address = 1'b1;
            //             // csw_next_data_in = csw_data_out;
            //             // cs_next_data_in = cs_data_out;
            //             // cw_next_data_in = cw_data_out;
            //         end
            //         if(`WIDTH + 1 < index && index < 2*`WIDTH -2) begin // top edge
            //             cs_next_write_addr = index - `WIDTH;
            //             cs_n_read_from_write_address = 1'b1;
            //             // cs_n_next_write_en = 1;
            //             // cs_next_data_in = cs_data_out;
            //         end
            //         if((index <= `WIDTH + 1) && (index + `RAMS_TO_ACCESS >= `WIDTH + 1)) begin // NW corner
            //             cse_next_write_addr = 0;
            //             // cse_n_next_write_en = 1;
            //             cs_next_write_addr = 1;
            //             // cs_n_next_write_en = 1;
            //             ce_next_write_addr = `WIDTH;
            //             // ce_n_next_write_en = 1;
            //             cse_n_read_from_write_address = 1'b1;
            //             cs_n_read_from_write_address = 1'b1;
            //             ce_n_read_from_write_address = 1'b1;
            //             // cse_next_data_in = cse_data_out;
            //             // cs_next_data_in = cs_data_out;
            //             // ce_next_data_in = ce_data_out;
                        
            //         end
            //         if ((index <= `DEPTH - `WIDTH - 2) && (index + `RAM_READ_WAIT >= `DEPTH - `WIDTH - 2)) begin // SE corner
            //             cnw_next_write_addr = `DEPTH - 1; 
            //             // cnw_n_next_write_en = 1;
            //             cn_next_write_addr = `DEPTH - 2; 
            //             // cn_n_next_write_en = 1;
            //             cw_next_write_addr = `DEPTH - `WIDTH - 1; 
            //             // cw_n_next_write_en = 1;

            //             cnw_n_read_from_write_address = 1'b1;
            //             cn_n_read_from_write_address = 1'b1;
            //             cw_n_read_from_write_address = 1'b1;
            //             // cnw_next_data_in = cnw_data_out;
            //             // cn_next_data_in = cn_data_out;
            //             // cw_next_data_in = cw_data_out;
                        
            //         end
            //         if(`DEPTH - 2*`WIDTH + 1 < index && index < `DEPTH - `WIDTH - 2) begin // bottom edge
            //             cn_next_write_addr = index - `WIDTH;
            //             cn_n_read_from_write_address = 1'b1;
            //             // cn_n_next_write_en = 1;
            //             // cn_next_data_in = cn_data_out;
            //         end
            //         if ((index <= `DEPTH - 2*`WIDTH + 1) && (index + `RAMS_TO_ACCESS >= `DEPTH - 2*`WIDTH + 1)) begin // SW corner
            //             cne_next_write_addr = `DEPTH - `WIDTH; 
            //             // cne_n_next_write_en = 1;
            //             cn_next_write_addr = `DEPTH - `WIDTH+1; 
            //             // cn_n_next_write_en = 1;
            //             ce_next_write_addr = `DEPTH - 2*`WIDTH; 
            //             // ce_n_next_write_en = 1;
            //             cne_n_read_from_write_address = 1'b1;
            //             cn_n_read_from_write_address = 1'b1;
            //             ce_n_read_from_write_address = 1'b1;
            //             // cne_next_data_in = cne_data_out;
            //             // cn_next_data_in = cn_data_out;
            //             // ce_next_data_in = ce_data_out;

            //         end
            //         if(width_count == 1) begin // left edge
            //             ce_next_write_addr = index - 1;
            //             ce_n_read_from_write_address = 1'b1;
            //             // ce_n_next_write_en = 1;
            //             // ce_next_data_in = ce_data_out;
            //         end
            //         if(width_count == `WIDTH - 2) begin // right edge 
            //             cw_next_write_addr = index + 1;
            //             cw_n_read_from_write_address = 1'b1;
            //             // cw_n_next_write_en = 1;
            //             // cw_next_data_in = cw_data_out;
            //         end
                    
            //         if(`WIDTH + 1 <= index && index <= 2*`WIDTH - 2) begin // top edge
            //             next_index = (width_count+`RAMS_TO_ACCESS >= `WIDTH - 2) ? index + : index + `RAMS_TO_ACCESS;
            //             next_width_count = (width_count+`RAMS_TO_ACCESS >= `WIDTH - 2) ? 1 : width_count + `RAMS_TO_ACCESS;
            //             next_sim_state = BOUNDARY;
            //             next_ram_wait_count = `RAM_READ_WAIT;
            //         end
            //         else if(`DEPTH - 2*`WIDTH + 1 <= index && index <= `DEPTH - `WIDTH - 2) begin // bottom edge 
            //             next_index = (width_count+`RAMS_TO_ACCESS >= `WIDTH - 2) ? 0 : index + `RAMS_TO_ACCESS;
            //             next_width_count = (width_count+`RAMS_TO_ACCESS >= `WIDTH - 2) ? 2 : width_count + `RAMS_TO_ACCESS;
            //             next_sim_state = (width_count+`RAMS_TO_ACCESS >= `WIDTH - 2) ? BOUNCE : BOUNDARY;
            //             next_ram_wait_count = (width_count+`RAMS_TO_ACCESS >= `WIDTH - 2) ? `RAM_READ_WAIT : 0;
            //         end
            //         else begin // everything else
            //             next_index = (width_count+`RAMS_TO_ACCESS >= `WIDTH - 2) ? index + 3: index + `WIDTH -3;
            //             next_width_count = (width_count+`RAMS_TO_ACCESS >= `WIDTH - 2) ? 1 : `WIDTH - 2;
            //             next_sim_state = BOUNDARY;
            //             next_ram_wait_count = `RAM_READ_WAIT;
            //         end
            //     end
            // end
            BOUNCE:
            begin
                if(all_bounce_wait) 
                begin
                    next_sim_state = BOUNCE_WAIT;
                    next_ram_wait_count = `RAM_READ_WAIT;
                end
                else if(any_bounce_wait)
                begin
                    next_sim_state = BOUNCE_READ;
                    next_ram_wait_count = `RAM_READ_WAIT;

                    c0_next_write_addr = index;
                    c0_n_read_from_write_address = 1'b1;

                    cn_next_write_addr = index-`WIDTH;
                    cn_n_read_from_write_address = 1'b1;

                    cne_next_write_addr = index-`WIDTH+1;
                    cne_n_read_from_write_address = 1'b1;
                    
                    ce_next_write_addr = index+1;
                    ce_n_read_from_write_address = 1'b1;

                    cse_next_write_addr = index+`WIDTH+1;
                    cse_n_read_from_write_address = 1'b1;   

                    cs_next_write_addr = index+`WIDTH;
                    cs_n_read_from_write_address = 1'b1;

                    csw_next_write_addr = index+`WIDTH-1;
                    csw_n_read_from_write_address = 1'b1;

                    cw_next_write_addr = index - 1;
                    cw_n_read_from_write_address = 1'b1;

                    cnw_next_write_addr = index - 1 - `WIDTH;
                    cnw_n_read_from_write_address = 1'b1;
                end
                else if(index + `RAMS_TO_ACCESS >= `DEPTH-1) 
                begin
                    next_sim_state = ZERO_BOUNCE;
                    next_index = 0;
                    next_width_count = 0;
                end
                else
                begin
                    next_sim_state = BOUNCE;
                    next_index = index + `RAMS_TO_ACCESS;
                    next_width_count = (width_count+`RAMS_TO_ACCESS > `WIDTH-1) ? (`RAMS_TO_ACCESS+width_count)%(`WIDTH) : (width_count + `RAMS_TO_ACCESS);
                end
            end

            BOUNCE_READ:
            begin
                if(ram_wait_count > 0) begin
                    next_ram_wait_count = ram_wait_count - 1;
                    next_sim_state = BOUNCE_READ;
                    next_index = index;
                    next_width_count = width_count;
                end
                else
                begin
                    c0_n_next_stored_data = c0_n_data_out;

                    cn_n_next_stored_data = cn_n_data_out;

                    cne_n_next_stored_data = cne_n_data_out;

                    ce_n_next_stored_data = ce_n_data_out;

                    cse_n_next_stored_data = cse_n_data_out;

                    cs_n_next_stored_data = cs_n_data_out;

                    csw_n_next_stored_data = csw_n_data_out;

                    cw_n_next_stored_data = cw_n_data_out;

                    cnw_n_next_stored_data = cnw_n_data_out;

                    next_sim_state = BOUNCE_WAIT;
                    next_ram_wait_count = `RAM_READ_WAIT;
                    next_index = index;
                    next_width_count = width_count;
                end
            end

            BOUNCE_WAIT:
            begin
                if(ram_wait_count > 0) begin
                    next_ram_wait_count = ram_wait_count - 1;
                    next_sim_state = BOUNCE_WAIT;
                    next_index = index;
                    next_width_count = width_count;

                    c0_n_next_stored_data = c0_n_stored_data;

                    cn_n_next_stored_data = cn_n_stored_data;

                    cne_n_next_stored_data = cne_n_stored_data;

                    ce_n_next_stored_data = ce_n_stored_data;

                    cse_n_next_stored_data = cse_n_stored_data;

                    cs_n_next_stored_data = cs_n_stored_data;

                    csw_n_next_stored_data = csw_n_stored_data;

                    cw_n_next_stored_data = cw_n_stored_data;

                    cnw_n_next_stored_data = cnw_n_stored_data;
                end
                else
                begin
                    c0_next_write_addr = index;
                    c0_n_read_from_write_address = 1'b1;

                    cn_next_write_addr = index-`WIDTH;
                    cn_n_read_from_write_address = 1'b1;

                    cne_next_write_addr = index-`WIDTH+1;
                    cne_n_read_from_write_address = 1'b1;
                    
                    ce_next_write_addr = index+1;
                    ce_n_read_from_write_address = 1'b1;

                    cse_next_write_addr = index+`WIDTH+1;
                    cse_n_read_from_write_address = 1'b1;   

                    cs_next_write_addr = index+`WIDTH;
                    cs_n_read_from_write_address = 1'b1;

                    csw_next_write_addr = index+`WIDTH-1;
                    csw_n_read_from_write_address = 1'b1;

                    cw_next_write_addr = index - 1;
                    cw_n_read_from_write_address = 1'b1;

                    cnw_next_write_addr = index - 1 - `WIDTH;
                    cnw_n_read_from_write_address = 1'b1;

                    if(index + `RAMS_TO_ACCESS >= `DEPTH-1)
                    begin
                        next_sim_state = ZERO_BOUNCE;
                        next_index = 0;
                        next_width_count = 0;
                    end
                    else
                    begin
                        next_sim_state = BOUNCE;
                        next_index = index + `RAMS_TO_ACCESS;
                        next_width_count = (width_count+`RAMS_TO_ACCESS >= `WIDTH-1) ? (`RAMS_TO_ACCESS+width_count)%(`WIDTH) : (width_count + `RAMS_TO_ACCESS);
                    end
                end
            end

            ZERO_BOUNCE:
            begin
                if(index + `RAMS_TO_ACCESS >= `DEPTH-1)
                begin
                    next_sim_state = COLLIDE;
                    next_index = 0;
                    next_width_count = 0;
                end
                else if(any_zero_barrier)
                begin
                    next_ram_wait_count = `RAM_READ_WAIT;
                    next_sim_state = ZERO_BOUNCE_WAIT;
                end
                else
                begin
                    next_sim_state = ZERO_BOUNCE;
                    next_index = index + `RAMS_TO_ACCESS;
                    next_width_count = (width_count+`RAMS_TO_ACCESS >= `WIDTH-1) ? (`RAMS_TO_ACCESS+width_count)%(`WIDTH) : (width_count + `RAMS_TO_ACCESS);
                end
 
            end
            ZERO_BOUNCE_WAIT:
            begin
                if(ram_wait_count > 0) begin
                    next_ram_wait_count = ram_wait_count - 1;
                    next_sim_state = ZERO_BOUNCE_WAIT;
                    next_index = index;
                    next_width_count = width_count;

                    c0_n_next_stored_data = c0_n_data_out;

                    cn_n_next_stored_data = cn_n_data_out;

                    cne_n_next_stored_data = cne_n_data_out;

                    ce_n_next_stored_data = ce_n_data_out;

                    cse_n_next_stored_data = cse_n_data_out;

                    cs_n_next_stored_data = cs_n_data_out;

                    csw_n_next_stored_data = csw_n_data_out;

                    cw_n_next_stored_data = cw_n_data_out;

                    cnw_n_next_stored_data = cnw_n_data_out;
                    
                end
                else
                begin
                    
                    c0_next_write_addr = index;
                    c0_n_read_from_write_address = 1'b1;

                    cn_next_write_addr = index;
                    cn_n_read_from_write_address = 1'b1;

                    cne_next_write_addr = index;
                    cne_n_read_from_write_address = 1'b1;
                    
                    ce_next_write_addr = index;
                    ce_n_read_from_write_address = 1'b1;

                    cse_next_write_addr = index;
                    cse_n_read_from_write_address = 1'b1;   

                    cs_next_write_addr = index;
                    cs_n_read_from_write_address = 1'b1;

                    csw_next_write_addr = index;
                    csw_n_read_from_write_address = 1'b1;

                    cw_next_write_addr = index;
                    cw_n_read_from_write_address = 1'b1;

                    cnw_next_write_addr = index;
                    cnw_n_read_from_write_address = 1'b1;

                    if(index + `RAMS_TO_ACCESS >= `DEPTH-1)
                    begin
                        next_sim_state = COLLIDE;
                        next_index = 0;
                        next_width_count = 0;
                    end
                    else
                    begin
                        next_sim_state = ZERO_BOUNCE;
                        next_index = index + `RAMS_TO_ACCESS;
                        next_width_count = (width_count+`RAMS_TO_ACCESS >= `WIDTH-1) ? (`RAMS_TO_ACCESS+width_count)%(`WIDTH) : (width_count + `RAMS_TO_ACCESS);
                    end
                end
            end
            COLLIDE: begin
                if (ram_wait_count > 0) begin
                    next_ram_wait_count = ram_wait_count - 1;
                    next_sim_state = COLLIDE;
                    next_index = index;
                    next_width_count = width_count;  
                end
                else begin
                    next_sim_state = COLLIDE;
                    next_index = index + `RAMS_TO_ACCESS;
                    next_ram_wait_count = `RAM_READ_WAIT;
                    next_width_count = width_count;  
                end

                if(all_newval_ready) begin
                    if(newval_index_array[0] + `RAMS_TO_ACCESS >= `DEPTH-1)
                    begin
                        next_sim_state = IDLE;
                        next_index = 0;
                        next_width_count = 0;
                        incr_step = 1;
                    end
                    c0_next_write_addr = newval_index_array[0];
                    cn_next_write_addr = newval_index_array[0];
                    cne_next_write_addr = newval_index_array[0];
                    ce_next_write_addr = newval_index_array[0];
                    cse_next_write_addr = newval_index_array[0];
                    cs_next_write_addr = newval_index_array[0];
                    csw_next_write_addr = newval_index_array[0];
                    cw_next_write_addr = newval_index_array[0];
                    cnw_next_write_addr = newval_index_array[0];   
                    next_width_count = (newval_width_count_array[0]+`RAMS_TO_ACCESS >= `WIDTH-1) ? (`RAMS_TO_ACCESS+width_count)%(`WIDTH) : (width_count + `RAMS_TO_ACCESS);                  
                end
            end

            MEM_RESET : begin
                if(index + `RAMS_TO_ACCESS >= `DEPTH - 1) 
                begin
                    next_index = 0;
                    next_width_count = 0;
                    next_sim_state = IDLE;
                    // next_step_count = step_count + 1;
                end
                else
                begin
                    next_index = index + `RAMS_TO_ACCESS;
                    next_width_count = (width_count+`RAMS_TO_ACCESS >= `WIDTH-1) ? (`RAMS_TO_ACCESS+width_count)%(`WIDTH) : (width_count + `RAMS_TO_ACCESS);
                    next_sim_state = MEM_RESET;
                end
                
                //initial eastward direction             
                // c0_next_write_en = 1;
                // c0_n_next_write_en = 1;
                c0_next_write_addr = index;
                // c0_next_data_in = (barriers[index] == 0) ? init_c0 : 0;

                // cn_next_write_en = 1;
                // cn_n_next_write_en = 1;
                cn_next_write_addr = index;
                // cn_next_data_in = (barriers[index] == 0) ? init_cn : 0;

                // cne_next_write_en = 1;
                // cne_n_next_write_en = 1;
                cne_next_write_addr = index;
                // cne_next_data_in = (barriers[index] == 0) ? init_cne : 0;

                // ce_next_write_en = 1;
                // ce_n_next_write_en = 1;
                ce_next_write_addr = index;
                // ce_next_data_in = (barriers[index] == 0) ? init_ce : 0;

                // cse_next_write_en = 1;
                // cse_n_next_write_en = 1;
                cse_next_write_addr = index;
                // cse_next_data_in = (barriers[index] == 0) ? init_cse : 0;

                // cs_next_write_en = 1;
                // cs_n_next_write_en = 1;
                cs_next_write_addr = index;
                // cs_next_data_in = (barriers[index] == 0) ? init_cs : 0;

                // csw_next_write_en = 1;
                // csw_n_next_write_en = 1;
                csw_next_write_addr = index;
                // csw_next_data_in = (barriers[index] == 0) ? init_csw : 0;

                // cw_next_write_en = 1;
                // cw_n_next_write_en = 1;
                cw_next_write_addr = index;
                // cw_next_data_in = (barriers[index] == 0) ? init_cw : 0;

                // cnw_next_write_en = 1;
                // cnw_n_next_write_en = 1;
                cnw_next_write_addr = index;
                // cnw_next_data_in = (barriers[index] == 0) ? init_cnw : 0;

            end

            default: 
            begin
                next_sim_state = IDLE;
                next_ram_wait_count = 0;
            end 
        endcase
    end

endmodule
