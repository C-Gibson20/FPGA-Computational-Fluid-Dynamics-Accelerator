`timescale 1ps / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 28.05.2025 18:44:59
// Design Name: 
// Module Name: LBMSolver
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

module LBMController (

    // TEMPORARILY MAKING THE STEP CONTROLLED VIA GPIO SO EASIER TO TEST
    // input wire clk,
    // input wire rst,
    // input wire [`DEPTH-1:0] barriers,
    // input wire en,
    // input wire [31:0] step, // will step until sim value
    // input wire signed [15:0] omega, // 1/tau
    // input reg [`ADDRESS_WIDTH-1:0] index,
    // input reg [`ADDRESS_WIDTH-1:0] width_count,
    
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
    

    // // collider results
    // output wire [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0] u_x, 
    // output wire [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0] u_y, 
    // output wire [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0] rho,
    
    // output wire collider_ready,
    // output wire in_collision_state,
    // output wire next_index,
    // output wire [2:0] sim_state

);

    //States
    localparam IDLE = 3'd0;
    localparam STREAM = 3'd1;
    localparam BOUNCE = 3'd2;
    localparam BOUNCE_WAIT = 3'd3;
    localparam ZERO_BOUNCE = 3'd4;
    localparam COLLIDE = 3'd5;


    // wire [`ADDRESS_WIDTH-1:0] c0_array_addr     [0:`RAMS_TO_ACCESS-1];
    // wire [`ADDRESS_WIDTH-1:0] c0_array_n_addr   [0:`RAMS_TO_ACCESS-1];
    // wire [`ADDRESS_WIDTH-1:0] cn_array_addr     [0:`RAMS_TO_ACCESS-1];
    // wire [`ADDRESS_WIDTH-1:0] cn_array_n_addr   [0:`RAMS_TO_ACCESS-1];
    // wire [`ADDRESS_WIDTH-1:0] cne_array_addr    [0:`RAMS_TO_ACCESS-1];
    // wire [`ADDRESS_WIDTH-1:0] cne_array_n_addr  [0:`RAMS_TO_ACCESS-1];
    // wire [`ADDRESS_WIDTH-1:0] ce_array_addr     [0:`RAMS_TO_ACCESS-1];
    // wire [`ADDRESS_WIDTH-1:0] ce_array_n_addr   [0:`RAMS_TO_ACCESS-1];
    // wire [`ADDRESS_WIDTH-1:0] cse_array_addr    [0:`RAMS_TO_ACCESS-1];
    // wire [`ADDRESS_WIDTH-1:0] cse_array_n_addr  [0:`RAMS_TO_ACCESS-1];
    // wire [`ADDRESS_WIDTH-1:0] cs_array_addr     [0:`RAMS_TO_ACCESS-1];
    // wire [`ADDRESS_WIDTH-1:0] cs_array_n_addr   [0:`RAMS_TO_ACCESS-1];
    // wire [`ADDRESS_WIDTH-1:0] csw_array_addr    [0:`RAMS_TO_ACCESS-1];
    // wire [`ADDRESS_WIDTH-1:0] csw_array_n_addr  [0:`RAMS_TO_ACCESS-1];
    // wire [`ADDRESS_WIDTH-1:0] cw_array_addr     [0:`RAMS_TO_ACCESS-1];
    // wire [`ADDRESS_WIDTH-1:0] cw_array_n_addr   [0:`RAMS_TO_ACCESS-1];
    // wire [`ADDRESS_WIDTH-1:0] cnw_array_addr    [0:`RAMS_TO_ACCESS-1];
    // wire [`ADDRESS_WIDTH-1:0] cnw_array_n_addr  [0:`RAMS_TO_ACCESS-1];

    // Data-in buses
    wire [`DATA_WIDTH-1:0] c0_array_data_in     [0:`RAMS_TO_ACCESS-1];
    wire [`DATA_WIDTH-1:0] c0_array_n_data_in   [0:`RAMS_TO_ACCESS-1];
    wire [`DATA_WIDTH-1:0] cn_array_data_in     [0:`RAMS_TO_ACCESS-1];
    wire [`DATA_WIDTH-1:0] cn_array_n_data_in   [0:`RAMS_TO_ACCESS-1];
    wire [`DATA_WIDTH-1:0] cne_array_data_in    [0:`RAMS_TO_ACCESS-1];
    wire [`DATA_WIDTH-1:0] cne_array_n_data_in  [0:`RAMS_TO_ACCESS-1];
    wire [`DATA_WIDTH-1:0] ce_array_data_in     [0:`RAMS_TO_ACCESS-1];
    wire [`DATA_WIDTH-1:0] ce_array_n_data_in   [0:`RAMS_TO_ACCESS-1];
    wire [`DATA_WIDTH-1:0] cse_array_data_in    [0:`RAMS_TO_ACCESS-1];
    wire [`DATA_WIDTH-1:0] cse_array_n_data_in  [0:`RAMS_TO_ACCESS-1];
    wire [`DATA_WIDTH-1:0] cs_array_data_in     [0:`RAMS_TO_ACCESS-1];
    wire [`DATA_WIDTH-1:0] cs_array_n_data_in   [0:`RAMS_TO_ACCESS-1];
    wire [`DATA_WIDTH-1:0] csw_array_data_in    [0:`RAMS_TO_ACCESS-1];
    wire [`DATA_WIDTH-1:0] csw_array_n_data_in  [0:`RAMS_TO_ACCESS-1];
    wire [`DATA_WIDTH-1:0] cw_array_data_in     [0:`RAMS_TO_ACCESS-1];
    wire [`DATA_WIDTH-1:0] cw_array_n_data_in   [0:`RAMS_TO_ACCESS-1];
    wire [`DATA_WIDTH-1:0] cnw_array_data_in    [0:`RAMS_TO_ACCESS-1];
    wire [`DATA_WIDTH-1:0] cnw_array_n_data_in  [0:`RAMS_TO_ACCESS-1];

    // Data-out from collider
    wire [`DATA_WIDTH-1:0] u_x_array  [0:`RAMS_TO_ACCESS-1];
    wire [`DATA_WIDTH-1:0] u_y_array  [0:`RAMS_TO_ACCESS-1];
    wire [`DATA_WIDTH-1:0] rho_array  [0:`RAMS_TO_ACCESS-1];

    // Write-enable and status bits
    wire c0_array_write_en     [0:`RAMS_TO_ACCESS-1], c0_array_n_write_en   [0:`RAMS_TO_ACCESS-1],
        cn_array_write_en     [0:`RAMS_TO_ACCESS-1], cn_array_n_write_en   [0:`RAMS_TO_ACCESS-1],
        cne_array_write_en    [0:`RAMS_TO_ACCESS-1], cne_array_n_write_en  [0:`RAMS_TO_ACCESS-1],
        ce_array_write_en     [0:`RAMS_TO_ACCESS-1], ce_array_n_write_en   [0:`RAMS_TO_ACCESS-1],
        cse_array_write_en    [0:`RAMS_TO_ACCESS-1], cse_array_n_write_en  [0:`RAMS_TO_ACCESS-1],
        cs_array_write_en     [0:`RAMS_TO_ACCESS-1], cs_array_n_write_en   [0:`RAMS_TO_ACCESS-1],
        csw_array_write_en    [0:`RAMS_TO_ACCESS-1], csw_array_n_write_en  [0:`RAMS_TO_ACCESS-1],
        cw_array_write_en     [0:`RAMS_TO_ACCESS-1], cw_array_n_write_en   [0:`RAMS_TO_ACCESS-1],
        cnw_array_write_en    [0:`RAMS_TO_ACCESS-1];

    wire collider_ready_array     [0:`RAMS_TO_ACCESS-1];
    wire in_collision_state_array  [0:`RAMS_TO_ACCESS-1];
    wire read_wait_array          [0:`RAMS_TO_ACCESS-1];
    wire [2:0] next_sim_state_array [0:`RAMS_TO_ACCESS-1];
    wire [`RAMS_TO_ACCESS-1:0] is_bw;
    wire [`RAMS_TO_ACCESS-1:0] is_rw;
    // reg [15:0] width_count, next_width_count;
    // reg [2:0] sim_state, next_sim_state;
    // reg [`ADDRESS_WIDTH-1:0] index;
    // reg [`ADDRESS_WIDTH-1:0] next_index;
    
    // collider flags
    // wire c_busy;
    // wire nv_ready;
    // wire v_d_ready;
        
    // reg [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0] c0_next_data_in;
    // reg c0_next_write_en, c0_n_next_write_en;
    // reg [`ADDRESS_WIDTH-1:0] c0_next_write_addr;

    // reg [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0] cn_next_data_in;
    // reg cn_next_write_en, cn_n_next_write_en;
    // reg [`ADDRESS_WIDTH-1:0] cn_next_write_addr;

    // reg [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0] cne_next_data_in;
    // reg cne_next_write_en, cne_n_next_write_en;
    // reg [`ADDRESS_WIDTH-1:0] cne_next_write_addr;

    // reg [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0] ce_next_data_in;
    // reg ce_next_write_en, ce_n_next_write_en;
    // reg [`ADDRESS_WIDTH-1:0] ce_next_write_addr;

    // reg [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0] cse_next_data_in;
    // reg cse_next_write_en, cse_n_next_write_en;
    // reg [`ADDRESS_WIDTH-1:0] cse_next_write_addr;

    // reg [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0] cs_next_data_in;
    // reg cs_next_write_en, cs_n_next_write_en;
    // reg [`ADDRESS_WIDTH-1:0] cs_next_write_addr;

    // reg [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0] csw_next_data_in;
    // reg csw_next_write_en, csw_n_next_write_en;
    // reg [`ADDRESS_WIDTH-1:0] csw_next_write_addr;

    // reg [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0] cw_next_data_in;
    // reg cw_next_write_en, cw_n_next_write_en;
    // reg [`ADDRESS_WIDTH-1:0] cw_next_write_addr;

    // reg [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0] cnw_next_data_in;
    // reg cnw_next_write_en, cnw_n_next_write_en;
    // reg [`ADDRESS_WIDTH-1:0] cnw_next_write_addr;


    // reg [2:0] ram_wait_count, next_ram_wait_count;
    
    // reg [15:0] step_count, next_step_count;

    // wire [`DATA_WIDTH*`RAMS_TO_ACCESS-1:0] c_c0,c_cn,c_cne,c_ce,c_cse,c_cs,c_csw,c_cw,c_cnw;
    
    // assign collider_ready = nv_ready && (sim_state == COLLIDE) && (ram_wait_count == 0); // ensure not waiting more on RAM
    // assign in_collision_state = (sim_state == COLLIDE);

    genvar i;
    generate
    for (i = 0; i < `RAMS_TO_ACCESS; i = i + 1) begin : g_solver
        wire [`ADDRESS_WIDTH-1:0] width_mod = (width_count + i) % `WIDTH;

        LBMSolver LBMSolverArray (
        .clk         (clk),
        .rst         (rst),
        .barriers    (barriers),
        .en          (en),
        .step        (step),
        .omega       (omega),
        .sim_state   (sim_state),
        .index       (index+i),
        .width_count (width_mod),

        // .c0_addr       (c0_array_addr     [i]),
        .c0_data_in    (c0_array_data_in  [i]),
        .c0_write_en   (c0_array_write_en [i]),

        // .c0_n_addr     (c0_array_n_addr     [i]),
        .c0_n_data_in  (c0_array_n_data_in  [i]),
        .c0_n_write_en (c0_array_n_write_en [i]),

        // .cn_addr       (cn_array_addr     [i]),
        .cn_data_in    (cn_array_data_in  [i]),
        .cn_write_en   (cn_array_write_en [i]),

        // .cn_n_addr     (cn_array_n_addr     [i]),
        .cn_n_data_in  (cn_array_n_data_in  [i]),
        .cn_n_write_en (cn_array_n_write_en [i]),

        // .cne_addr       (cne_array_addr     [i]),
        .cne_data_in    (cne_array_data_in  [i]),
        .cne_write_en   (cne_array_write_en [i]),

        // .cne_n_addr     (cne_array_n_addr     [i]),
        .cne_n_data_in  (cne_array_n_data_in  [i]),
        .cne_n_write_en (cne_array_n_write_en [i]),

        // .ce_addr       (ce_array_addr     [i]),
        .ce_data_in    (ce_array_data_in  [i]),
        .ce_write_en   (ce_array_write_en [i]),

        // .ce_n_addr     (ce_array_n_addr     [i]),
        .ce_n_data_in  (ce_array_n_data_in  [i]),
        .ce_n_write_en (ce_array_n_write_en [i]),

        // .cse_addr       (cse_array_addr     [i]),
        .cse_data_in    (cse_array_data_in  [i]),
        .cse_write_en   (cse_array_write_en [i]),

        // .cse_n_addr     (cse_array_n_addr     [i]),
        .cse_n_data_in  (cse_array_n_data_in  [i]),
        .cse_n_write_en (cse_array_n_write_en [i]),

        // .cs_addr       (cs_array_addr     [i]),
        .cs_data_in    (cs_array_data_in  [i]),
        .cs_write_en   (cs_array_write_en [i]),

        // .cs_n_addr     (cs_array_n_addr     [i]),
        .cs_n_data_in  (cs_array_n_data_in  [i]),
        .cs_n_write_en (cs_array_n_write_en [i]),

        // .csw_addr       (csw_array_addr     [i]),
        .csw_data_in    (csw_array_data_in  [i]),
        .csw_write_en   (csw_array_write_en [i]),

        // .csw_n_addr     (csw_array_n_addr     [i]),
        .csw_n_data_in  (csw_array_n_data_in  [i]),
        .csw_n_write_en (csw_array_n_write_en [i]),

        // .cw_addr       (cw_array_addr     [i]),
        .cw_data_in    (cw_array_data_in  [i]),
        .cw_write_en   (cw_array_write_en [i]),

        // .cw_n_addr     (cw_array_n_addr     [i]),
        .cw_n_data_in  (cw_array_n_data_in  [i]),
        .cw_n_write_en (cw_array_n_write_en [i]),

        // .cnw_addr       (cnw_array_addr     [i]),
        .cnw_data_in    (cnw_array_data_in  [i]),
        .cnw_write_en   (cnw_array_write_en [i]),

        // .cnw_n_addr     (cnw_array_n_addr     [i]),
        .cnw_n_data_in  (cnw_array_n_data_in  [i]),
        .cnw_n_write_en (cnw_array_n_write_en [i]),

        .u_x                (u_x_array                [i]),
        .u_y                (u_y_array                [i]),
        .rho                (rho_array                [i]),
        .collider_ready     (collider_ready_array     [i]),
        .in_collision_state (in_collision_state_array [i]),
        .read_wait          (read_wait_array          [i]),
        .next_sim_state     (next_sim_state_array     [i])
        );
    end
    endgenerate


    genvar i;
    generate
    for (i = 0; i < `RAMS_TO_ACCESS; i = i + 1) begin : g_bw
        assign is_bw[i] = (next_sim_state_array[i] == BOUNCE_WAIT);
    end
    endgenerate
    genvar i;
    generate
    for (i = 0; i < `RAMS_TO_ACCESS; i = i + 1) begin : g_bw
        assign is_rw[i] = (read_wait_array[i]);
    end
    endgenerate
    wire any_bounce_wait = |is_bw;
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

    //Update stream state
    always @(posedge clk or negedge rst)
    begin
        if(!rst) 
        begin
            sim_state <= IDLE;
            index <= initial_index;
            width_count <= initial_index;
            ram_wait_count <= `RAM_READ_WAIT;
            step_count <= 0;
        end
        else 
        begin
            step_count <= next_step_count;
            ram_wait_count <= next_ram_wait_count;

            c0_addr <= (c0_write_en && sim_state != STREAM) ? c0_next_write_addr : index;
            c0_n_addr <= c0_n_next_write_en ? c0_next_write_addr : index;
            c0_write_en <= c0_next_write_en;
            c0_n_write_en <= c0_n_next_write_en;
            c0_data_in <= c0_next_data_in;
            c0_n_data_in <= c0_next_data_in;

            cn_addr <= (cn_write_en && sim_state != STREAM) ? cn_next_write_addr : index;
            cn_n_addr <= cn_n_next_write_en ? cn_next_write_addr : index;
            cn_write_en <= cn_next_write_en;
            cn_n_write_en <= cn_n_next_write_en;
            cn_data_in <= cn_next_data_in;
            cn_n_data_in <= cn_next_data_in;

            cne_addr <= (cne_write_en && sim_state != STREAM) ? cne_next_write_addr : index;
            cne_n_addr <= cne_n_next_write_en ? cne_next_write_addr : index;
            cne_write_en <= cne_next_write_en;
            cne_n_write_en <= cne_n_next_write_en;
            cne_data_in <= cne_next_data_in;
            cne_n_data_in <= cne_next_data_in;

            ce_addr <= (ce_write_en && sim_state != STREAM) ? ce_next_write_addr : index;
            ce_n_addr <= ce_n_next_write_en ? ce_next_write_addr : index;
            ce_write_en <= ce_next_write_en;
            ce_n_write_en <= ce_n_next_write_en;
            ce_data_in <= ce_next_data_in;
            ce_n_data_in <= ce_next_data_in;

            cse_addr <= (cse_write_en && sim_state != STREAM) ? cse_next_write_addr : index;
            cse_n_addr <= cse_n_next_write_en ? cse_next_write_addr : index;
            cse_write_en <= cse_next_write_en;
            cse_n_write_en <= cse_n_next_write_en;
            cse_data_in <= cse_next_data_in;
            cse_n_data_in <= cse_next_data_in;

            cs_addr <= (cs_write_en && sim_state != STREAM) ? cs_next_write_addr : index;
            cs_n_addr <= cs_n_next_write_en ? cs_next_write_addr : index;
            cs_write_en <= cs_next_write_en;
            cs_n_write_en <= cs_n_next_write_en;
            cs_data_in <= cs_next_data_in;
            cs_n_data_in <= cs_next_data_in;

            csw_addr <= (csw_write_en && sim_state != STREAM) ? csw_next_write_addr : index;
            csw_n_addr <= csw_n_next_write_en ? csw_next_write_addr : index;
            csw_write_en <= csw_next_write_en;
            csw_n_write_en <= csw_n_next_write_en;
            csw_data_in <= csw_next_data_in;
            csw_n_data_in <= csw_next_data_in;

            cw_addr <= (cw_write_en && sim_state != STREAM) ? cw_next_write_addr : index;
            cw_n_addr <= cw_n_next_write_en ? cw_next_write_addr : index;
            cw_write_en <= cw_next_write_en;
            cw_n_write_en <= cw_n_next_write_en;
            cw_data_in <= cw_next_data_in;
            cw_n_data_in <= cw_next_data_in;

            cnw_addr <= (cnw_write_en && sim_state != STREAM) ? cnw_next_write_addr : index;
            cnw_n_addr <= cnw_n_next_write_en ? cnw_next_write_addr : index;
            cnw_write_en <= cnw_next_write_en;
            cnw_n_write_en <= cnw_n_next_write_en;
            cnw_data_in <= cnw_next_data_in;
            cnw_n_data_in <= cnw_next_data_in;
        end
    end


    //Stream state
    always @* begin
        c0_next_write_addr = 0;
        c0_next_write_en = 0;
        c0_n_next_write_en = 0;
        c0_next_data_in = 0;

        cn_next_write_addr = 0;
        cn_next_write_en = 0;
        cn_n_next_write_en = 0;
        cn_next_data_in = 0;

        cne_next_write_addr = 0;
        cne_next_write_en = 0;
        cne_n_next_write_en = 0;
        cne_next_data_in = 0;

        ce_next_write_addr = 0;
        ce_next_write_en = 0;
        ce_n_next_write_en = 0;
        ce_next_data_in = 0;

        cse_next_write_addr = 0;
        cse_next_write_en = 0;
        cse_n_next_write_en = 0;
        cse_next_data_in = 0;

        cs_next_write_addr = 0;
        cs_next_write_en = 0;
        cs_n_next_write_en = 0;
        cs_next_data_in = 0;

        csw_next_write_addr = 0;
        csw_next_write_en = 0;
        csw_n_next_write_en = 0;
        csw_next_data_in = 0;

        cw_next_write_addr = 0;
        cw_next_write_en = 0;
        cw_n_next_write_en = 0;
        cw_next_data_in = 0;

        cnw_next_write_addr = 0;
        cnw_next_write_en = 0;
        cnw_n_next_write_en = 0;
        cnw_next_data_in = 0;

        next_index = 0;

        next_step_count = step_count;
        next_ram_wait_count = ram_wait_count;

        case(sim_state)
            IDLE: begin
                if(step >= step_count) begin
                    next_sim_state = STREAM;
                    next_ram_wait_count = `RAM_READ_WAIT;
                end
                else
                    next_sim_state = IDLE;
            end
            STREAM:
            begin
                if(ram_wait_count > 0) begin
                    next_ram_wait_count = ram_wait_count - 1;
                    next_sim_state = STREAM;
                    next_index = index;
                    next_width_count = width_count;

                    c0_next_write_addr = c0_n_addr;
                    c0_n_next_write_en = c0_n_write_en;

                    cn_next_write_addr = cn_n_addr;
                    cn_n_next_write_en = cn_n_write_en;

                    cne_next_write_addr = cne_n_addr;
                    cne_n_next_write_en = cne_n_write_en;

                    ce_next_write_addr = ce_n_addr;
                    ce_n_next_write_en = ce_n_write_en;

                    cse_next_write_addr = cse_n_addr;
                    cse_n_next_write_en = cse_n_write_en;

                    cs_next_write_addr = cs_n_addr;
                    cs_n_next_write_en = cs_n_write_en;

                    csw_next_write_addr = csw_n_addr;
                    csw_n_next_write_en = csw_n_write_en;

                    cw_next_write_addr = cw_n_addr;
                    cw_n_next_write_en = cw_n_write_en;

                    cnw_next_write_addr = cnw_n_addr;
                    cnw_n_next_write_en = cnw_n_write_en;
                end
                else
                begin 
                    if(index+`RAMS_TO_ACCESS > `DEPTH-1) 
                    begin
                        next_sim_state = BOUNCE;
                    end
                    else
                        index = index + `RAMS_TO_ACCESS;
                        next_sim_state = STREAM;
                        if(is_rw) 
                        begin
                            ram_wait_count = `RAM_READ_WAIT;

                            c0_n_addr = index;

                            cn_n_addr = index-`WIDTH;

                            cne_n_addr = index-`WIDTH+1;

                            ce_n_addr = index+1;
                            
                            cse_n_addr = index+`WIDTH+1;
                            
                            cs_n_addr = index+`WIDTH;
                            
                            csw_n_addr = index+`WIDTH-1;
                            
                            cw_n_addr = index - 1;
                            
                            cnw_n_addr = index - 1 - `WIDTH;
                        end
                end
            end

            BOUNCE:
            begin


            end

            BOUNCE_WAIT:
            begin
              
            end

            ZERO_BOUNCE:
            begin
                
            end
            COLLIDE: //needs to be multiple stages or else this won't be clocked very fast
            // wait for ram read
            begin
                
            end

            default: 
            begin
                
            end 
        endcase
    end

endmodule
