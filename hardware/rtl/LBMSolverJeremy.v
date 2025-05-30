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

module LBMSolverJeremy (

    // TEMPORARILY MAKING THE STEP CONTROLLED VIA GPIO SO EASIER TO TEST
    input wire clk,
    input wire rst,
    input wire [`DEPTH-1:0] barriers,
    input wire en,
    input wire [31:0] step, // will step until sim value
    input wire signed [15:0] omega, // 1/tau

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
    

    // collider results
    output wire [`DATA_WIDTH-1:0] u_x, 
    output wire [`DATA_WIDTH-1:0] u_y, 
    output wire [`DATA_WIDTH-1:0] rho


);

    //States
    localparam IDLE = 3'd0;
    localparam STREAM = 3'd1;
    localparam BOUNCE = 3'd2;
    localparam BOUNCE_WAIT = 3'd3;
    localparam ZERO_BOUNCE = 3'd4;
    localparam COLLIDE = 3'd5;

    reg [15:0] width_count, next_width_count;
    reg [2:0] sim_state, next_sim_state;
    reg [`ADDRESS_WIDTH-1:0] index;
    reg [`ADDRESS_WIDTH-1:0] next_index;
    
    // collider flags
    wire c_busy;
    wire nv_ready;
    wire v_d_ready;
        

    reg [`DATA_WIDTH-1:0] c0_next_data_in;
    reg c0_next_write_en, c0_n_next_write_en;
    reg [`ADDRESS_WIDTH-1:0] c0_next_write_addr;

    reg [`DATA_WIDTH-1:0]    cn_next_data_in, cn_n_next_data_in;
    reg                      cn_next_write_en, cn_n_next_write_en;
    reg [`ADDRESS_WIDTH-1:0] cn_next_write_addr, cn_n_next_write_addr;

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
    
    reg [15:0] step_count, next_step_count;

    wire [`DATA_WIDTH-1:0] c_cn;
    //Stores the 9 directions in their own RAM, I can't make each cell it's own block of memory, so instead I've decided to split the memory by direction
    //need two rams one for the current time step and one for the next time step

    // The actual RAM doesn't have 2 seperate addresses for reads and writes. so use single address lines - Nishant
    // Add 1 cycle delay for RAM reads - Nishant
    // note to self: cx and cx_n are driven by the same ADDR, DIN ports. just called cx

    //Instantiate Nishant's collider
    collider collider(
        .omega(omega),
        // .f_null(c0_n_data_out),
        .f_n(cn_n_data_out),
        .f_ne(cne_n_data_out),
        .f_e(ce_n_data_out),
        .f_se(cse_n_data_out),
        .f_s(cs_n_data_out),
        .f_sw(csw_n_data_out),
        .f_w(cw_n_data_out),
        .f_nw(cnw_n_data_out),
        .new_f_null(c_c0),
        .new_f_n(c_cn),
        .new_f_ne(c_cne),
        .new_f_e(c_ce),
        .new_f_se(c_cse),
        .new_f_s(c_cs),
        .new_f_sw(c_csw),
        .new_f_w(c_cw),
        .new_f_nw(c_cnw),
        .collider_busy(c_busy),
        .newval_ready(nv_ready),
        .axi_ready(v_d_ready),
        .u_x(u_x),
        .u_y(u_y),
        .rho(rho)
    );

    //Update stream state
    always @(posedge clk or posedge rst)
    begin
        if(rst) 
        begin
            sim_state <= IDLE;
            index <= 0;
            width_count <= 0;
            ram_wait_count <= `RAM_READ_WAIT;
        end
        else 
        begin
            sim_state <= next_sim_state;
            index <= next_index;
            width_count <= next_width_count;
            step_count <= next_step_count;

            cn_addr <= cn_write_en ? cn_next_write_addr : index;
            cn_n_addr <= cn_n_next_write_en ? cn_next_write_addr : index;
            cn_write_en <= cn_next_write_en;
            cn_n_write_en <= cn_n_next_write_en;
            cn_data_in <= cn_next_data_in;
            cn_n_data_in <= cn_n_next_data_in;

        end
    end


    //Stream state
    always @* begin
        cn_next_write_addr = 0;
        cn_next_write_en = 0;
        cn_n_next_write_en = 0;
        cn_next_data_in = 0;
        cn_n_next_data_in = 0;

        next_index = 0;
        next_width_count = 0;

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
                end
                else begin
                    if(index == `DEPTH-1) // if streamed all cells, go to bounce stage
                    begin
                        next_step_count = step_count + 1;
                        next_index = 0;
                        next_width_count = 0;
                        next_sim_state = BOUNCE;
                        // can go into bounce state without having to reset RAM wait, since we don't always read from RAM
                    end
                    else // if not, increment index and continue streaming
                    begin
                        next_index = index + 2;
                        next_width_count = (width_count == `WIDTH-1) ? 0 : (width_count + 1);
                        next_sim_state = STREAM;
                        next_ram_wait_count = `RAM_READ_WAIT;
                    end
                    // @Kayvan are the ternary expressions on next_addr needed? can't just have them as the target address?
                    // note to self: streaming step reads from cx and writes to cx_n. 
                    cn_next_write_addr = 2*(index-`WIDTH); // write to cell above
                    cn_n_next_write_en = (index >= `WIDTH); // only write if past first row
                    cn_n_next_data_in = cn_data_out;
                end
            end

            BOUNCE:
            begin
                // note to self: this stage reads from cx_n and writes to cx_n
                if(index == `DEPTH-1) 
                begin
                    next_index = 0;
                    next_width_count = 0;
                    next_sim_state = ZERO_BOUNCE;
                end
                else begin
                    if(barriers[index] == 1'b1) // RAM read, so need to wait for RAM...
                    begin
                        next_ram_wait_count = `RAM_READ_WAIT - 1; // minus one because state transistion takes 1 clock cycle
                        next_sim_state = BOUNCE_WAIT;
                    end
                    else // not a barrier, skip over
                    begin
                        next_index = index + 2;
                        next_width_count = (width_count == `WIDTH-1) ? 0 : (width_count + 1);
                        next_sim_state = BOUNCE;
                    end
                end
            end

            BOUNCE_WAIT:
            begin
                if(ram_wait_count > 0) begin
                    next_ram_wait_count = ram_wait_count - 1; 
                    next_sim_state = BOUNCE_WAIT;
                end 
                else begin
                    cn_next_write_addr = 2*(index-`WIDTH);
                    cn_n_next_write_en = (index>= `WIDTH);
                    cn_next_data_in = cs_n_data_out;

                    // go back to bounce state
                    next_index = index + 2;
                    next_width_count = (width_count == `WIDTH-1) ? 0 : width_count + 1;
                    next_sim_state = BOUNCE; 
                end
            end

            ZERO_BOUNCE:
            begin
                if(index == `DEPTH-1) 
                begin
                    next_index = 0;
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
                    cn_next_write_addr = index;
                    cn_n_next_write_en = 1'b1;
                    cn_next_data_in = 16'b0;
                end
            end
            COLLIDE: //needs to be multiple stages or else this won't be clocked very fast
            begin
                if(nv_ready) 
                begin
                    if(index == `DEPTH-1) 
                    begin
                        next_index = 0;
                        next_width_count = 0;
                        next_sim_state = STREAM;
                    end
                    else
                    begin
                        next_index = index + 2;
                        next_width_count = (width_count == `WIDTH-1) ? 0 : width_count + 1;
                        next_sim_state = COLLIDE;
                    end

                    cn_next_write_addr = index;
                    cn_next_write_en = 1'b1;
                    cn_next_data_in = c_cn;
                end
                else
                begin
                    next_sim_state = COLLIDE;
                end
            end
            default: 
            begin
                next_sim_state = IDLE;
                next_ram_wait_count = 0;
            end 
        endcase
    end

endmodule
