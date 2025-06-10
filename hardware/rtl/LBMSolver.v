`timescale 1ns / 1ps
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

module LBMSolver (

    // TEMPORARILY MAKING THE STEP CONTROLLED VIA GPIO SO EASIER TO TEST
    input wire clk,
    input wire rst,
    input wire [`DEPTH-1:0] barriers,
    input wire en,
    input wire [15:0] step, // will step until sim value
    input wire signed [15:0] omega, // 1/tau
    
    output wire signed [15:0] testing_cs_n_data_in, //for unit tests allowing me to test values for signals not exposed to the top layer
    // BRAM c0
    output reg  [`ADDRESS_WIDTH-1:0]    c0_addr,
    output reg  [`DATA_WIDTH-1:0]       c0_data_in, 
    output reg                          c0_write_en,
    input  wire [`DATA_WIDTH-1:0]       c0_data_out,

    // BRAM c0_n
    output reg  [`ADDRESS_WIDTH-1:0]    c0_n_addr,
    output reg  [`DATA_WIDTH-1:0]       c0_n_data_in, 
    output reg                          c0_n_write_en,
    input  wire [`DATA_WIDTH-1:0]       c0_n_data_out,
    

    // BRAM cn
    output reg  [`ADDRESS_WIDTH-1:0]    cn_addr,
    output reg  [`DATA_WIDTH-1:0]       cn_data_in, 
    output reg                          cn_write_en,
    input  wire [`DATA_WIDTH-1:0]       cn_data_out,

    // BRAM cn_n
    output reg  [`ADDRESS_WIDTH-1:0]    cn_n_addr,
    output reg  [`DATA_WIDTH-1:0]       cn_n_data_in, 
    output reg                          cn_n_write_en,
    input  wire [`DATA_WIDTH-1:0]       cn_n_data_out,
    

    // BRAM cne
    output reg  [`ADDRESS_WIDTH-1:0]    cne_addr,
    output reg  [`DATA_WIDTH-1:0]       cne_data_in, 
    output reg                          cne_write_en,
    input  wire [`DATA_WIDTH-1:0]       cne_data_out,

    // BRAM cne_n
    output reg  [`ADDRESS_WIDTH-1:0]    cne_n_addr,
    output reg  [`DATA_WIDTH-1:0]       cne_n_data_in, 
    output reg                          cne_n_write_en,
    input  wire [`DATA_WIDTH-1:0]       cne_n_data_out,
    

    // BRAM ce
    output reg  [`ADDRESS_WIDTH-1:0]    ce_addr,
    output reg  [`DATA_WIDTH-1:0]       ce_data_in, 
    output reg                          ce_write_en,
    input  wire [`DATA_WIDTH-1:0]       ce_data_out,

    // BRAM ce_n
    output reg  [`ADDRESS_WIDTH-1:0]    ce_n_addr,
    output reg  [`DATA_WIDTH-1:0]       ce_n_data_in, 
    output reg                          ce_n_write_en,
    input  wire [`DATA_WIDTH-1:0]       ce_n_data_out,
    

    // BRAM cse
    output reg  [`ADDRESS_WIDTH-1:0]    cse_addr,
    output reg  [`DATA_WIDTH-1:0]       cse_data_in, 
    output reg                          cse_write_en,
    input  wire [`DATA_WIDTH-1:0]       cse_data_out,

    // BRAM cse_n
    output reg  [`ADDRESS_WIDTH-1:0]    cse_n_addr,
    output reg  [`DATA_WIDTH-1:0]       cse_n_data_in, 
    output reg                          cse_n_write_en,
    input  wire [`DATA_WIDTH-1:0]       cse_n_data_out,
    

    // BRAM cs
    output reg  [`ADDRESS_WIDTH-1:0]    cs_addr,
    output reg  [`DATA_WIDTH-1:0]       cs_data_in, 
    output reg                          cs_write_en,
    input  wire [`DATA_WIDTH-1:0]       cs_data_out,

    // BRAM cs_n
    output reg  [`ADDRESS_WIDTH-1:0]    cs_n_addr,
    output reg  [`DATA_WIDTH-1:0]       cs_n_data_in, 
    output reg                          cs_n_write_en,
    input  wire [`DATA_WIDTH-1:0]       cs_n_data_out,
    

    // BRAM csw
    output reg  [`ADDRESS_WIDTH-1:0]    csw_addr,
    output reg  [`DATA_WIDTH-1:0]       csw_data_in, 
    output reg                          csw_write_en,
    input  wire [`DATA_WIDTH-1:0]       csw_data_out,

    // BRAM csw_n
    output reg  [`ADDRESS_WIDTH-1:0]    csw_n_addr,
    output reg  [`DATA_WIDTH-1:0]       csw_n_data_in, 
    output reg                          csw_n_write_en,
    input  wire [`DATA_WIDTH-1:0]       csw_n_data_out,
    

    // BRAM cw
    output reg  [`ADDRESS_WIDTH-1:0]    cw_addr,
    output reg  [`DATA_WIDTH-1:0]       cw_data_in, 
    output reg                          cw_write_en,
    input  wire [`DATA_WIDTH-1:0]       cw_data_out,

    // BRAM cw_n
    output reg  [`ADDRESS_WIDTH-1:0]    cw_n_addr,
    output reg  [`DATA_WIDTH-1:0]       cw_n_data_in, 
    output reg                          cw_n_write_en,
    input  wire [`DATA_WIDTH-1:0]       cw_n_data_out,
    

    // BRAM cnw
    output reg  [`ADDRESS_WIDTH-1:0]    cnw_addr,
    output reg  [`DATA_WIDTH-1:0]       cnw_data_in, 
    output reg                          cnw_write_en,
    input  wire [`DATA_WIDTH-1:0]       cnw_data_out,

    // BRAM cnw_n
    output reg  [`ADDRESS_WIDTH-1:0]    cnw_n_addr,
    output reg  [`DATA_WIDTH-1:0]       cnw_n_data_in, 
    output reg                          cnw_n_write_en,
    input  wire [`DATA_WIDTH-1:0]       cnw_n_data_out,

    // initial conditions
    
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
    output wire [`DATA_WIDTH-1:0] u_x, 
    output wire [`DATA_WIDTH-1:0] u_y, 
    output wire [`DATA_WIDTH-1:0] rho,
    output wire [`DATA_WIDTH-1:0] u_squared,

    output wire collider_ready,
    output wire in_collision_state,
    output wire [15:0] step_countn


);

    assign testing_cs_n_data_in = cs_n_data_in;
    //States
    localparam IDLE             = 4'd0;
    localparam STREAM           = 4'd1;
    localparam STREAM_WAIT      = 4'd2;
    localparam BOUNDARY         = 4'd3;
    localparam BOUNDARY_WAIT    = 4'd4;
    localparam BOUNCE           = 4'd5;
    localparam BOUNCE_WAIT      = 4'd6;
    localparam ZERO_BOUNCE      = 4'd7;
    localparam COLLIDE          = 4'd8;
    localparam MEM_RESET        = 4'd9;
    
    reg [15:0] width_count, next_width_count;
    reg [3:0] sim_state, next_sim_state;
    reg [`ADDRESS_WIDTH-1:0] index, next_index;
    
    // collider flags
    wire c_busy;
    wire nv_ready;
    wire v_d_ready;
        
    reg [`DATA_WIDTH-1:0] c0_next_data_in;
    reg c0_next_write_en, c0_n_next_write_en;
    reg [`ADDRESS_WIDTH-1:0] c0_next_write_addr;

    reg [`DATA_WIDTH-1:0] cn_next_data_in;
    reg cn_next_write_en, cn_n_next_write_en;
    reg [`ADDRESS_WIDTH-1:0] cn_next_write_addr;

    reg [`DATA_WIDTH-1:0] cne_next_data_in;
    reg cne_next_write_en, cne_n_next_write_en;
    reg [`ADDRESS_WIDTH-1:0] cne_next_write_addr;

    reg [`DATA_WIDTH-1:0] ce_next_data_in;
    reg ce_next_write_en, ce_n_next_write_en;
    reg [`ADDRESS_WIDTH-1:0] ce_next_write_addr;

    reg [`DATA_WIDTH-1:0] cse_next_data_in;
    reg cse_next_write_en, cse_n_next_write_en;
    reg [`ADDRESS_WIDTH-1:0] cse_next_write_addr;

    reg [`DATA_WIDTH-1:0] cs_next_data_in;
    reg cs_next_write_en, cs_n_next_write_en;
    reg [`ADDRESS_WIDTH-1:0] cs_next_write_addr;

    reg [`DATA_WIDTH-1:0] csw_next_data_in;
    reg csw_next_write_en, csw_n_next_write_en;
    reg [`ADDRESS_WIDTH-1:0] csw_next_write_addr;

    reg [`DATA_WIDTH-1:0] cw_next_data_in;
    reg cw_next_write_en, cw_n_next_write_en;
    reg [`ADDRESS_WIDTH-1:0] cw_next_write_addr;

    reg [`DATA_WIDTH-1:0] cnw_next_data_in;
    reg cnw_next_write_en, cnw_n_next_write_en;
    reg [`ADDRESS_WIDTH-1:0] cnw_next_write_addr;

    reg [2:0] ram_wait_count, next_ram_wait_count;
    
    reg [15:0] step_count;
    reg incr_step;

    wire [`DATA_WIDTH-1:0] c_c0,c_cn,c_cne,c_ce,c_cse,c_cs,c_csw,c_cw,c_cnw;
    //Stores the 9 directions in their own RAM, I can't make each cell it's own block of memory, so instead I've decided to split the memory by direction
    //need two rams one for the current time step and one for the next time step

    // The actual RAM doesn't have 2 seperate addresses for reads and writes. so use single address lines - Nishant
    // Add 1 cycle delay for RAM reads - Nishant
    // note to self: cx and cx_n are driven by the same ADDR, DIN ports. just called cx

    assign collider_ready = nv_ready && (sim_state == COLLIDE) && (ram_wait_count == 0);
    assign in_collision_state = (sim_state == COLLIDE);
    assign step_countn = step_count;

    //Instantiate Nishant's collider
    collider collider(
        .omega(omega),
        .f_null(c0_n_data_out),
        .f_n(cn_n_data_out),
        .f_ne(cne_n_data_out),
        .f_e(ce_n_data_out),
        .f_se(cse_n_data_out),
        .f_s(cs_n_data_out),
        .f_sw(csw_n_data_out),
        .f_w(cw_n_data_out),
        .f_nw(cnw_n_data_out),
        .f_new_null(c_c0),
        .f_new_n(c_cn),
        .f_new_ne(c_cne),
        .f_new_e(c_ce),
        .f_new_se(c_cse),
        .f_new_s(c_cs),
        .f_new_sw(c_csw),
        .f_new_w(c_cw),
        .f_new_nw(c_cnw),
        .collider_busy(c_busy),
        .newval_ready(nv_ready),
        .axi_ready(v_d_ready),
        .u_x(u_x),
        .u_y(u_y),
        .rho(rho),
        .u_squared(u_squared)
    );

    //Update stream state
    always @(posedge clk or negedge rst)
    begin
        if(!rst) 
        begin
            sim_state <= MEM_RESET;
            index <= 0;
            width_count <= 0;
            ram_wait_count <= `RAM_READ_WAIT;
            step_count <= 0;
        end
        else 
        begin
            sim_state <= next_sim_state;
            index <= next_index;
            width_count <= next_width_count;
            step_count <= incr_step ? step_count + 1 : step_count;
            ram_wait_count <= next_ram_wait_count;
            
            c0_addr <= c0_next_write_en ? c0_next_write_addr : index;
            c0_n_addr <= c0_n_next_write_en ? c0_next_write_addr : index;
            c0_write_en <= c0_next_write_en;
            c0_n_write_en <= c0_n_next_write_en;
            c0_data_in <= c0_next_data_in;
            c0_n_data_in <= c0_next_data_in;

            cn_addr <= cn_next_write_en ? cn_next_write_addr : index;
            cn_n_addr <= cn_n_next_write_en ? cn_next_write_addr : index;
            cn_write_en <= cn_next_write_en;
            cn_n_write_en <= cn_n_next_write_en;
            cn_data_in <= cn_next_data_in;
            cn_n_data_in <= cn_next_data_in;

            cne_addr <= cne_next_write_en ? cne_next_write_addr : index;
            cne_n_addr <= cne_n_next_write_en ? cne_next_write_addr : index;
            cne_write_en <= cne_next_write_en;
            cne_n_write_en <= cne_n_next_write_en;
            cne_data_in <= cne_next_data_in;
            cne_n_data_in <= cne_next_data_in;

            ce_addr <= ce_next_write_en ? ce_next_write_addr : index;
            ce_n_addr <= ce_n_next_write_en ? ce_next_write_addr : index;
            ce_write_en <= ce_next_write_en;
            ce_n_write_en <= ce_n_next_write_en;
            ce_data_in <= ce_next_data_in;
            ce_n_data_in <= ce_next_data_in;

            cse_addr <= cse_next_write_en ? cse_next_write_addr : index;
            cse_n_addr <= cse_n_next_write_en ? cse_next_write_addr : index;
            cse_write_en <= cse_next_write_en;
            cse_n_write_en <= cse_n_next_write_en;
            cse_data_in <= cse_next_data_in;
            cse_n_data_in <= cse_next_data_in;

            cs_addr <= cs_next_write_en ? cs_next_write_addr : index;
            cs_n_addr <= cs_n_next_write_en ? cs_next_write_addr : index;
            cs_write_en <= cs_next_write_en;
            cs_n_write_en <= cs_n_next_write_en;
            cs_data_in <= cs_next_data_in;
            cs_n_data_in <= cs_next_data_in;

            csw_addr <= csw_next_write_en ? csw_next_write_addr : index;
            csw_n_addr <= csw_n_next_write_en ? csw_next_write_addr : index;
            csw_write_en <= csw_next_write_en;
            csw_n_write_en <= csw_n_next_write_en;
            csw_data_in <= csw_next_data_in;
            csw_n_data_in <= csw_next_data_in;

            cw_addr <= cw_next_write_en ? cw_next_write_addr : index;
            cw_n_addr <= cw_n_next_write_en ? cw_next_write_addr : index;
            cw_write_en <= cw_next_write_en;
            cw_n_write_en <= cw_n_next_write_en;
            cw_data_in <= cw_next_data_in;
            cw_n_data_in <= cw_next_data_in;

            cnw_addr <= cnw_next_write_en ? cnw_next_write_addr : index;
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

        next_index = index;
        next_width_count = width_count;

        incr_step = 0;
        next_ram_wait_count = ram_wait_count;

        case(sim_state)
            IDLE: begin
                if(step_count < step) begin
                    next_sim_state = STREAM;
                    next_ram_wait_count = 0;
                    next_index = `WIDTH+1;
                    next_width_count = 1;
                end
                else
                    next_sim_state = IDLE;
            end
            STREAM:
            begin
                if(barriers[index] == 1'b0) //stream if not barrier
                begin
                    next_ram_wait_count = `RAM_READ_WAIT;
                    next_sim_state = STREAM_WAIT;
                    next_index = index;
                end
                else // don't stream
                begin
                    next_index = (width_count == `WIDTH-2) ? index + 3 : index + 1;
                    next_width_count = (width_count == `WIDTH-2) ? 1 : width_count + 1;
                    next_sim_state = STREAM;
                end

                if(index == `DEPTH-1-`WIDTH-1) // if streamed all cells, go to bounce stage
                begin
                    next_index = `WIDTH+1;
                    next_width_count = 1;
                    next_sim_state = BOUNDARY;
                end 
            end

            STREAM_WAIT : // do the outside too
            begin
                if(ram_wait_count > 0) begin
                    next_ram_wait_count = ram_wait_count - 1; 
                    next_sim_state = STREAM_WAIT;
                    next_index = index;
                    next_width_count = width_count;
                end 
                else begin
                    
                    c0_next_write_addr = index;
                    c0_n_next_write_en = 1'b1;
                    c0_next_data_in = c0_data_out;

                    cn_next_write_addr = index-`WIDTH; // write to cell above
                    cn_n_next_write_en = 1;
                    cn_next_data_in = cn_data_out;

                    cne_next_write_addr = index-`WIDTH+1;
                    cne_n_next_write_en = 1;
                    cne_next_data_in = cne_data_out;

                    ce_next_write_addr = index+1;
                    ce_n_next_write_en = 1;
                    ce_next_data_in = ce_data_out;

                    cse_next_write_addr = index+`WIDTH+1;
                    cse_n_next_write_en = 1;
                    cse_next_data_in = cse_data_out;

                    cs_next_write_addr = index+`WIDTH;
                    cs_n_next_write_en = 1;
                    cs_next_data_in = cs_data_out;

                    csw_next_write_addr = index+`WIDTH-1;
                    csw_n_next_write_en = 1;
                    csw_next_data_in = csw_data_out;

                    cw_next_write_addr = index - 1;
                    cw_n_next_write_en = 1;
                    cw_next_data_in = cw_data_out;

                    cnw_next_write_addr = index - 1 - `WIDTH;
                    cnw_n_next_write_en = 1;
                    cnw_next_data_in = cnw_data_out;

                    if(index == `DEPTH-1-`WIDTH-1) 
                    begin
                        next_index = `WIDTH + 1;
                        next_width_count = 1;
                        next_sim_state = BOUNDARY;
                        
                    end
                    else
                    begin
                        next_index = (width_count == `WIDTH-2) ? index + 3 : index + 1;
                        next_width_count = (width_count == `WIDTH-2) ? 1 : width_count + 1;
                        next_sim_state = STREAM;
                    end
                end
            end

            // Assert zero gradient (copy inner edge for values facing inward on outer edge) or absorbing (zeroes)
            BOUNDARY : // iterates across second outermost edge
            begin
                if(ram_wait_count > 0) begin
                    next_ram_wait_count = ram_wait_count - 1; 
                    next_sim_state = BOUNDARY;
                    next_index = index; 
                    next_width_count = width_count;
                end
                else begin
                    if(index == 2*`WIDTH -2) begin // NE corner
                        csw_next_write_addr = `WIDTH - 1; 
                        csw_n_next_write_en = 1;
                        cs_next_write_addr = `WIDTH - 2;
                        cs_n_next_write_en = 1;
                        cw_next_write_addr = 2*`WIDTH - 1;
                        cw_n_next_write_en = 1;

                        csw_next_data_in = csw_data_out;
                        cs_next_data_in = cs_data_out;
                        cw_next_data_in = cw_data_out;
                    end
                    else if (index == `DEPTH - `WIDTH - 2) begin // SE corner
                        cnw_next_write_addr = `DEPTH - 1; 
                        cnw_n_next_write_en = 1;
                        cn_next_write_addr = `DEPTH - 2; 
                        cn_n_next_write_en = 1;
                        cw_next_write_addr = `DEPTH - `WIDTH - 1; 
                        cw_n_next_write_en = 1;

                        cnw_next_data_in = cnw_data_out;
                        cn_next_data_in = cn_data_out;
                        cw_next_data_in = cw_data_out;
                        
                    end
                    else if (index == `DEPTH - 2*`WIDTH + 1) begin // SW corner
                        cne_next_write_addr = `DEPTH - `WIDTH; 
                        cne_n_next_write_en = 1;
                        cn_next_write_addr = `DEPTH - `WIDTH+1; 
                        cn_n_next_write_en = 1;
                        ce_next_write_addr = `DEPTH - 2*`WIDTH; 
                        ce_n_next_write_en = 1;

                        cne_next_data_in = cne_data_out;
                        cn_next_data_in = cn_data_out;
                        ce_next_data_in = ce_data_out;

                    end
                    else if(index == `WIDTH + 1) begin // NW corner
                        cse_next_write_addr = 0;
                        cse_n_next_write_en = 1;
                        cs_next_write_addr = 1;
                        cs_n_next_write_en = 1;
                        ce_next_write_addr = `WIDTH;
                        ce_n_next_write_en = 1;

                        cse_next_data_in = cse_data_out;
                        cs_next_data_in = cs_data_out;
                        ce_next_data_in = ce_data_out;
                        
                    end
                    else if(`WIDTH + 1 < index && index < 2*`WIDTH -2) begin // top edge
                        cs_next_write_addr = index - `WIDTH;
                        cs_n_next_write_en = 1;
                        cs_next_data_in = cs_data_out;
                    end
                    else if(`DEPTH - 2*`WIDTH + 1 < index && index < `DEPTH - `WIDTH - 2) begin // bottom edge
                        cn_next_write_addr = index - `WIDTH;
                        cn_n_next_write_en = 1;
                        cn_next_data_in = cn_data_out;
                    end
                    else if(width_count == 1) begin // left edge
                        ce_next_write_addr = index - 1;
                        ce_n_next_write_en = 1;
                        ce_next_data_in = ce_data_out;
                    end
                    else if(width_count == `WIDTH - 2) begin // right edge 
                        cw_next_write_addr = index + 1;
                        cw_n_next_write_en = 1;
                        cw_next_data_in = cw_data_out;
                    end
                    
                    next_ram_wait_count = `RAM_READ_WAIT;
                    // next index logic
                    if(`WIDTH + 1 <= index && index <= 2*`WIDTH - 2) begin // top edge
                        next_index = (width_count == `WIDTH - 2) ? index + 3 : index + 1;
                        next_width_count = (width_count == `WIDTH - 2) ? 1 : width_count + 1;
                        next_sim_state = BOUNDARY;
                    end
                    else if(`DEPTH - 2*`WIDTH + 1 <= index && index <= `DEPTH - `WIDTH - 2) begin // bottom edge 
                        next_index = (width_count == `WIDTH - 2) ? 2*`WIDTH+2 : index + 1;
                        next_width_count = (width_count == `WIDTH - 2) ? 2 : width_count + 1;
                        next_sim_state = (width_count == `WIDTH - 2) ? BOUNCE : BOUNDARY;
                        next_ram_wait_count = (width_count == `WIDTH - 2) ? `RAM_READ_WAIT : 0;
                    end
                    else begin // everything else
                        next_index = (width_count == `WIDTH - 2) ? index + 3: index + `WIDTH -3;
                        next_width_count = (width_count == `WIDTH - 2) ? 1 : `WIDTH - 2;
                        next_sim_state = BOUNDARY;
                    end
  
                end

            end

            BOUNCE:
            begin
                // note to self: this stage reads from cx_n and writes to cx_n
                // NOTE: we only bounce the interior cells, ie: x: [2,...,WIDTH-3], y: [2,...,HEIGHT-3]
                // basically we leave a margin of 2 layers on teh outside that we don't bounce
                
                if(barriers[index] == 1'b1) // RAM read, so need to wait for RAM...
                begin
                    next_ram_wait_count = `RAM_READ_WAIT;
                    next_sim_state = BOUNCE_WAIT;
                    next_index = index;
                end
                else if(index == `DEPTH-1-2*`WIDTH-2) 
                begin
                    next_index = 0;
                    next_width_count = 0;
                    next_sim_state = ZERO_BOUNCE; // don't bother only zeroeing inside the margins 
                end
                else // not a barrier, skip over
                begin
                    next_sim_state = BOUNCE;
                    next_index = (width_count==`WIDTH-3) ? index + 5 : index + 1;
                    next_width_count = (width_count == `WIDTH-3) ? 2 : (width_count + 1);
                end

            end

            BOUNCE_WAIT:
            begin
                if(ram_wait_count > 0) begin
                    next_ram_wait_count = ram_wait_count - 1; 
                    next_sim_state = BOUNCE_WAIT;
                    next_index = index;
                    next_width_count = width_count;

                end 
                else begin
                    cn_next_write_addr = index-`WIDTH;
                    cn_n_next_write_en = (index>= `WIDTH);
                    cn_next_data_in = cs_n_data_out;

                    cne_next_write_addr = index-`WIDTH+1;
                    cne_n_next_write_en = (index >= `WIDTH && (width_count != `WIDTH - 1));
                    cne_next_data_in = csw_n_data_out;

                    ce_next_write_addr = index+1;
                    ce_n_next_write_en = (width_count != `WIDTH - 1);
                    ce_next_data_in = cw_n_data_out; 

                    cse_next_write_addr = index+`WIDTH+1;
                    cse_n_next_write_en = (index <= `DEPTH-`WIDTH-1  && (width_count != `WIDTH - 1));
                    cse_next_data_in = cnw_n_data_out; 

                    cs_next_write_addr = index+`WIDTH;
                    cs_n_next_write_en = (index <= `DEPTH-`WIDTH-1);
                    cs_next_data_in = cn_n_data_out; 

                    csw_next_write_addr = index+`WIDTH-1;
                    csw_n_next_write_en = (index <= `DEPTH-`WIDTH-1 && (width_count != 0));
                    csw_next_data_in = cne_n_data_out; 

                    cw_next_write_addr = index - 1;
                    cw_n_next_write_en = (width_count != 0);
                    cw_next_data_in = ce_n_data_out; 

                    cnw_next_write_addr = index - `WIDTH - 1;
                    cnw_n_next_write_en = (index >= `WIDTH && (width_count != 0));
                    cnw_next_data_in = cse_n_data_out;


                    // go back to bounce state
                    if(index != `DEPTH-1-2*`WIDTH-2) 
                    begin
                        next_index = (width_count==`WIDTH-3) ? index + 5 : index + 1;
                        next_width_count = (width_count == `WIDTH-3) ? 2 : (width_count + 1);
                        next_sim_state = BOUNCE;
                    end 
                    else
                    begin
                        next_index = 0; // don't really care about zeroing only the inner cells, so just treat it as normal
                        next_width_count = 0;
                        next_sim_state = ZERO_BOUNCE; 
                    end
                end
            end

            ZERO_BOUNCE: // don't really care about zeroing only the inner cells, so 
            begin
                if(index == `DEPTH-1) 
                begin
                    next_index = 0; // collide with a margin of 1 layer on the outside
                    next_width_count = 0;
                    next_sim_state = COLLIDE;
                    
                end
                else
                begin
                    next_index = index + 1;
                    next_width_count = (width_count == `WIDTH-1) ? 0 : width_count + 1;
                    next_sim_state = ZERO_BOUNCE;
                end

                if(barriers[index] == 1'b1) //this is where you left off 
                begin
                    // write zeroes to all barrier cells in cx_n
                    c0_next_write_addr = index;
                    c0_n_next_write_en = 1'b1;
                    c0_next_data_in = 16'b0;

                    cn_next_write_addr = index;
                    cn_n_next_write_en = 1'b1;
                    cn_next_data_in = 16'b0;

                    cne_next_write_addr = index;
                    cne_n_next_write_en = 1'b1;
                    cne_next_data_in = 16'b0;

                    ce_next_write_addr = index;
                    ce_n_next_write_en = 1'b1;
                    ce_next_data_in = 16'b0;

                    cse_next_write_addr = index;
                    cse_n_next_write_en = 1'b1;
                    cse_next_data_in = 16'b0;

                    cs_next_write_addr = index;
                    cs_n_next_write_en = 1'b1;
                    cs_next_data_in = 16'b0;

                    csw_next_write_addr = index;
                    csw_n_next_write_en = 1'b1;
                    csw_next_data_in = 16'b0;

                    cw_next_write_addr = index;
                    cw_n_next_write_en = 1'b1;
                    cw_next_data_in = 16'b0;

                    cnw_next_write_addr = index;
                    cnw_n_next_write_en = 1'b1;
                    cnw_next_data_in = 16'b0;
                end
            end
        COLLIDE: //needs to be multiple stages or else this won't be clocked very fast
            // wait for ram read
            // NOTE: we only collide interior cells (leave margin of 1 layer where we don't collide)
            begin
                if(ram_wait_count > 0) begin
                    next_ram_wait_count = ram_wait_count - 1; 
                    next_sim_state = COLLIDE;
                    next_index = index;
                    next_width_count = width_count;

                end
                else if(nv_ready) 
                    begin
                        if(index == `DEPTH-1) 
                        begin
                            next_index = 0;
                            next_width_count = 0;
                            next_sim_state = IDLE;
                            incr_step = 1;
                            // next_ram_wait_count = 2;
                            // next_step_count = step_count + 1;
                        end
                        else
                        begin
                            next_index = index + 1;
                            next_width_count = (width_count == `WIDTH-1) ? 0 : width_count + 1;
                            next_sim_state = COLLIDE;
                            next_ram_wait_count = `RAM_READ_WAIT;
                        end

                        if(index >= `WIDTH && index <= `DEPTH-`WIDTH-1 && width_count != 0 && width_count != `WIDTH-1) begin // only do for inside the margin
                            c0_next_write_addr = index;
                            c0_next_write_en = 1'b1;
                            c0_next_data_in = (barriers[index] == 1) ? 0 : c_c0;

                            cn_next_write_addr = index;
                            cn_next_write_en = 1'b1;
                            cn_next_data_in = (barriers[index] == 1) ? 0 : c_cn;

                            cne_next_write_addr = index;
                            cne_next_write_en = 1'b1;
                            cne_next_data_in = (barriers[index] == 1) ? 0 : c_cne;

                            ce_next_write_addr = index;
                            ce_next_write_en = 1'b1;
                            ce_next_data_in = (barriers[index] == 1) ? 0 : c_ce;

                            cse_next_write_addr = index;
                            cse_next_write_en = 1'b1;
                            cse_next_data_in = (barriers[index] == 1) ? 0 : c_cse;

                            cs_next_write_addr = index;
                            cs_next_write_en = 1'b1;
                            cs_next_data_in = (barriers[index] == 1) ? 0 : c_cs;

                            csw_next_write_addr = index;
                            csw_next_write_en = 1'b1;
                            csw_next_data_in = (barriers[index] == 1) ? 0 : c_csw;

                            cw_next_write_addr = index;
                            cw_next_write_en = 1'b1;
                            cw_next_data_in = (barriers[index] == 1) ? 0 : c_cw;

                            cnw_next_write_addr = index;
                            cnw_next_write_en = 1'b1;
                            cnw_next_data_in = (barriers[index] == 1) ? 0 : c_cnw;
                        end
                    end
                else begin
                    next_sim_state = COLLIDE;
                    next_index = index;
                    next_width_count = width_count;
                end
            end

            MEM_RESET : begin
                if(index == (`DEPTH-1)) 
                begin
                    next_index = 0;
                    next_width_count = 0;
                    next_sim_state = IDLE;
                    // next_step_count = step_count + 1;
                end
                else
                begin
                    next_index = index + 1;
                    next_width_count = (width_count == `WIDTH-1) ? 0 : width_count + 1;
                    next_sim_state = MEM_RESET;
                end
                
                //initial eastward direction             
                c0_next_write_en = 1;
                c0_n_next_write_en = 1;
                c0_next_write_addr = index;
                c0_next_data_in = (barriers[index] == 0) ? init_c0 : 0;

                cn_next_write_en = 1;
                cn_n_next_write_en = 1;
                cn_next_write_addr = index;
                cn_next_data_in = (barriers[index] == 0) ? init_cn : 0;

                cne_next_write_en = 1;
                cne_n_next_write_en = 1;
                cne_next_write_addr = index;
                cne_next_data_in = (barriers[index] == 0) ? init_cne : 0;

                ce_next_write_en = 1;
                ce_n_next_write_en = 1;
                ce_next_write_addr = index;
                ce_next_data_in = (barriers[index] == 0) ? init_ce : 0;

                cse_next_write_en = 1;
                cse_n_next_write_en = 1;
                cse_next_write_addr = index;
                cse_next_data_in = (barriers[index] == 0) ? init_cse : 0;

                cs_next_write_en = 1;
                cs_n_next_write_en = 1;
                cs_next_write_addr = index;
                cs_next_data_in = (barriers[index] == 0) ? init_cs : 0;

                csw_next_write_en = 1;
                csw_n_next_write_en = 1;
                csw_next_write_addr = index;
                csw_next_data_in = (barriers[index] == 0) ? init_csw : 0;

                cw_next_write_en = 1;
                cw_n_next_write_en = 1;
                cw_next_write_addr = index;
                cw_next_data_in = (barriers[index] == 0) ? init_cw : 0;

                cnw_next_write_en = 1;
                cnw_n_next_write_en = 1;
                cnw_next_write_addr = index;
                cnw_next_data_in = (barriers[index] == 0) ? init_cnw : 0;

            end

            default: 
            begin
                next_sim_state = IDLE;
                next_ram_wait_count = 0;
            end 
        endcase
    end

endmodule
