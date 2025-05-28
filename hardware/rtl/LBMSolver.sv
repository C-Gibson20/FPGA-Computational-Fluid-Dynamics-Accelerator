`include "def.sv"

module LBMSolver (
    input logic clk,
    input logic rst,
    input logic barriers [0:`DEPTH-1],
    input logic en
);

    //States
    localparam IDLE = 3'd0;
    localparam STREAM = 3'd1;
    localparam BOUNCE = 3'd2;
    localparam ZERO_BOUNCE = 3'd3;
    localparam COLLIDE = 3'd4;

    reg [`WIDTH-1:0] width_count, next_width_count;
    reg [2:0] sim_state, next_sim_state;
    reg [`ADDRESS_WIDTH-1:0] index;
    reg [`ADDRESS_WIDTH-1:0] next_index;

    logic [`DATA_WIDTH-1:0] c0_data_in, c0_next_data_in, c0_data_out, c0_n_data_out;
    reg c0_write_en, c0_next_write_en, c0_n_next_write_en, c0_n_write_en;
    reg [`ADDRESS_WIDTH-1:0] c0_write_address, c0_next_write_address;

    logic [`DATA_WIDTH-1:0] cn_data_in , cn_next_data_in, cn_data_out, cn_n_data_out;
    reg cn_write_en, cn_next_write_en, cn_n_next_write_en, cn_n_write_en;
    // logic [`ADDRESS_WIDTH-1:0] cn_read_address;
    reg [`ADDRESS_WIDTH-1:0] cn_write_address; 
    reg [`ADDRESS_WIDTH-1:0] cn_next_write_address;

    logic [`DATA_WIDTH-1:0] cne_data_in, cne_next_data_in, cne_data_out, cne_n_data_out;
    reg cne_write_en, cne_next_write_en, cne_n_next_write_en, cne_n_write_en;
    // logic [`ADDRESS_WIDTH-1:0] cne_read_address;
    reg [`ADDRESS_WIDTH-1:0] cne_write_address; 
    reg [`ADDRESS_WIDTH-1:0] cne_next_write_address;

    logic [`DATA_WIDTH-1:0] ce_data_in, ce_next_data_in, ce_data_out, ce_n_data_out;
    reg ce_write_en, ce_next_write_en, ce_n_next_write_en, ce_n_write_en;
    // logic [`ADDRESS_WIDTH-1:0] ce_read_address;
    reg [`ADDRESS_WIDTH-1:0] ce_write_address; 
    reg [`ADDRESS_WIDTH-1:0] ce_next_write_address;

    logic [`DATA_WIDTH-1:0] cse_data_in ,cse_next_data_in, cse_data_out, cse_n_data_out;
    reg cse_write_en, cse_next_write_en, cse_n_next_write_en, cse_n_write_en;
    // logic [`ADDRESS_WIDTH-1:0] cse_read_address;
    reg [`ADDRESS_WIDTH-1:0] cse_write_address; 
    reg [`ADDRESS_WIDTH-1:0] cse_next_write_address;

    logic [`DATA_WIDTH-1:0] cs_data_in, cs_next_data_in, cs_data_out, cs_n_data_out;
    reg cs_write_en, cs_next_write_en, cs_n_next_write_en, cs_n_write_en;
    // logic [`ADDRESS_WIDTH-1:0] cs_read_address;
    reg [`ADDRESS_WIDTH-1:0] cs_write_address; 
    reg [`ADDRESS_WIDTH-1:0] cs_next_write_address;

    logic [`DATA_WIDTH-1:0] csw_data_in, csw_next_data_in, csw_data_out, csw_n_data_out;
    reg csw_write_en, csw_next_write_en, csw_n_next_write_en, csw_n_write_en;
    // logic [`ADDRESS_WIDTH-1:0] csw_read_address;
    reg [`ADDRESS_WIDTH-1:0] csw_write_address; 
    reg [`ADDRESS_WIDTH-1:0] csw_next_write_address;

    logic [`DATA_WIDTH-1:0] cw_data_in, cw_next_data_in, cw_data_out, cw_n_data_out;
    reg cw_write_en, cw_next_write_en, cw_n_next_write_en, cw_n_write_en;
    // logic [`ADDRESS_WIDTH-1:0] cw_write_address, cw_read_address;
    reg [`ADDRESS_WIDTH-1:0] cw_write_address; 
    reg [`ADDRESS_WIDTH-1:0] cw_next_write_address;

    logic [`DATA_WIDTH-1:0] cnw_data_in, cnw_next_data_in, cnw_data_out, cnw_n_data_out;
    reg cnw_write_en, cnw_next_write_en, cnw_n_next_write_en, cnw_n_write_en;
    // logic [`ADDRESS_WIDTH-1:0] cnw_read_address;
    reg [`ADDRESS_WIDTH-1:0] cnw_write_address; 
    reg [`ADDRESS_WIDTH-1:0] cnw_next_write_address;

    wire [`DATA_WIDTH-1:0] c_c0,c_cn,c_cne,c_ce,c_cse,c_cs,c_csw,c_cw,c_cnw;
    wire c_busy,nv_ready,v_d_ready;
    wire [`DATA_WIDTH-1:0] u_x, u_y, rho;
    //Stores the 9 directions in their own RAM, I can't make each cell it's own block of memory, so instead I've decided to split the memory by direction
    //need two rams one for the current time step and one for the next time step

    RAM C0(
        .read_address(index),
        .write_address(c0_write_address),
        .data_in(c0_data_in),
        .clk(clk),
        .write_en(c0_write_en),
        .data_out(c0_data_out)
    );

    RAM C0_n(
        .read_address(index),
        .write_address(c0_write_address),
        .data_in(c0_data_in),
        .clk(clk),
        .write_en(c0_n_write_en),
        .data_out(c0_n_data_out)
    );

    RAM CN(
        .read_address(index),
        .write_address(cn_write_address),
        .data_in(cn_data_in),
        .clk(clk),
        .write_en(cn_write_en),
        .data_out(cn_data_out)
    );

    RAM CN_n(
        .read_address(index),
        .write_address(cn_write_address),
        .data_in(cn_data_in),
        .clk(clk),
        .write_en(cn_n_write_en),
        .data_out(cn_n_data_out)
    );

    RAM CNE(
        .read_address(index),
        .write_address(cne_write_address),
        .data_in(cne_data_in),
        .clk(clk),
        .write_en(cne_write_en),
        .data_out(cne_data_out)
    );

    RAM CNE_n(
        .read_address(index),
        .write_address(cne_write_address),
        .data_in(cne_data_in),
        .clk(clk),
        .write_en(cne_n_write_en),
        .data_out(cne_n_data_out)
    );

    RAM CE(
        .read_address(index),
        .write_address(ce_write_address),
        .data_in(ce_data_in),
        .clk(clk),
        .write_en(ce_write_en),
        .data_out(ce_data_out)
    );

    RAM CE_n(
        .read_address(index),
        .write_address(ce_write_address),
        .data_in(ce_data_in),
        .clk(clk),
        .write_en(ce_n_write_en),
        .data_out(ce_n_data_out)
    );

    RAM CSE(
        .read_address(index),
        .write_address(cse_write_address),
        .data_in(cse_data_in),
        .clk(clk),
        .write_en(cse_write_en),
        .data_out(cse_data_out)
    );

    RAM CSE_n(
        .read_address(index),
        .write_address(cse_write_address),
        .data_in(cse_data_in),
        .clk(clk),
        .write_en(cse_n_write_en),
        .data_out(cse_n_data_out)
    );

    RAM CS(
        .read_address(index),
        .write_address(cs_write_address),
        .data_in(cs_data_in),
        .clk(clk),
        .write_en(cs_write_en),
        .data_out(cs_data_out)
    );

    RAM CS_n(
        .read_address(index),
        .write_address(cs_write_address),
        .data_in(cs_data_in),
        .clk(clk),
        .write_en(cs_n_write_en),
        .data_out(cs_n_data_out)
    );

    RAM CSW(
        .read_address(index),
        .write_address(csw_write_address),
        .data_in(csw_data_in),
        .clk(clk),
        .write_en(csw_write_en),
        .data_out(csw_data_out)
    );

    RAM CSW_n(
        .read_address(index),
        .write_address(csw_write_address),
        .data_in(csw_data_in),
        .clk(clk),
        .write_en(csw_n_write_en),
        .data_out(csw_n_data_out)
    );

    RAM CW(
        .read_address(index),
        .write_address(cw_write_address),
        .data_in(cw_data_in),
        .clk(clk),
        .write_en(cw_write_en),
        .data_out(cw_data_out)
    );

    RAM CW_n(
        .read_address(index),
        .write_address(cw_write_address),
        .data_in(cw_data_in),
        .clk(clk),
        .write_en(cw_n_write_en),
        .data_out(cw_n_data_out)
    );

    RAM CNW(
        .read_address(index),
        .write_address(cnw_write_address),
        .data_in(cnw_data_in),
        .clk(clk),
        .write_en(cnw_write_en),
        .data_out(cnw_data_out)
    );

    RAM CNW_n(
        .read_address(index),
        .write_address(cnw_write_address),
        .data_in(cnw_data_in),
        .clk(clk),
        .write_en(cnw_n_write_en),
        .data_out(cnw_n_data_out)
    );

    //Instantiate Nishant's collider
    collider collider(
        .f_null(c0_n_data_out),
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
        .velocity_density_ready(v_d_ready),
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
        end
        else 
        begin
            sim_state <= next_sim_state;
            index <= next_index;

            c0_write_address <= c0_next_write_address;
            c0_n_write_en <= c0_n_next_write_en;
            c0_data_in <= c0_next_data_in;
            c0_write_en <= c0_next_write_en;

            cn_write_address <= cn_next_write_address;
            cn_n_write_en <= cn_n_next_write_en;
            cn_data_in <= cn_next_data_in;
            cn_write_en <= cn_next_write_en;

            cne_write_address <= cne_next_write_address;
            cne_n_write_en <= cne_n_next_write_en;
            cne_data_in <= cne_next_data_in;
            cne_write_en <= cne_next_write_en;

            ce_write_address <= ce_next_write_address;
            ce_n_write_en <= ce_n_next_write_en;
            ce_data_in <= ce_next_data_in;
            ce_write_en <= ce_next_write_en;

            cse_write_address <= cse_next_write_address;
            cse_n_write_en <= cse_n_next_write_en;
            cse_data_in <= cse_next_data_in;
            cse_write_en <= cse_next_write_en;

            cs_write_address <= cs_next_write_address;
            cs_n_write_en <= cs_n_next_write_en;
            cs_data_in <= cs_next_data_in;
            cs_write_en <= cs_next_write_en;

            csw_write_address <= csw_next_write_address;
            csw_n_write_en <= csw_n_next_write_en;
            csw_data_in <= csw_next_data_in;
            csw_write_en <= csw_next_write_en;

            cw_write_address <= cw_next_write_address;
            cw_n_write_en <= cw_n_next_write_en;
            cw_data_in <= cw_next_data_in;
            cw_write_en <= cw_next_write_en;

            cnw_write_address <= cnw_next_write_address;
            cnw_n_write_en <= cnw_n_next_write_en;
            cnw_data_in <= cnw_next_data_in;
            cnw_write_en <= cnw_next_write_en;

            // if(sim_state == WRITE_BOUNCE && barriers[index] == 1'b1)
            // begin
            //     cn_data_in  <= cs_data_out;
            //     cne_data_in <= csw_data_out;
            //     ce_data_in  <= cw_data_out;
            //     cse_data_in <= cnw_data_out;
            //     cs_data_in  <= cn_data_out;
            //     csw_data_in <= cne_data_out;
            //     cw_data_in  <= ce_data_out;
            //     cnw_data_in <= cse_data_out;
            // end
            // else if(sim_state == ZERO_BOUNCE && barriers[index] == 1'b1)
            // begin
            //     cn_data_in  <= 0;
            //     cne_data_in <= 0;
            //     ce_data_in  <= 0;
            //     cse_data_in <= 0;
            //     cs_data_in  <= 0;
            //     csw_data_in <= 0;
            //     cw_data_in  <= 0;
            //     cnw_data_in <= 0;
            // end
            // else
            // begin
            //     cn_data_in  <= cn_data_out;
            //     cne_data_in  <= cne_data_out;
            //     ce_data_in  <= ce_data_out;
            //     cse_data_in  <= cse_data_out;
            //     cs_data_in  <= cs_data_out;
            //     csw_data_in  <= csw_data_out;
            //     cw_data_in  <= cw_data_out;
            //     cnw_data_in  <= cnw_data_out;
            // end
        end
    end


    //Stream state
    always_comb begin
        c0_next_write_address = 0;
        c0_next_write_en = 0;
        c0_n_next_write_en = 0;
        c0_next_data_in = 0;

        cn_next_write_address = 0;
        cn_next_write_en = 0;
        cn_n_next_write_en = 0;
        cn_next_data_in = 0;

        cne_next_write_address = 0;
        cne_next_write_en = 0;
        cne_n_next_write_en = 0;
        cne_next_data_in = 0;

        ce_next_write_address = 0;
        ce_next_write_en = 0;
        ce_n_next_write_en = 0;
        ce_next_data_in = 0;

        cse_next_write_address = 0;
        cse_next_write_en = 0;
        cse_n_next_write_en = 0;
        cse_next_data_in = 0;

        cs_next_write_address = 0;
        cs_next_write_en = 0;
        cs_n_next_write_en = 0;
        cs_next_data_in = 0;

        csw_next_write_address = 0;
        csw_next_write_en = 0;
        csw_n_next_write_en = 0;
        csw_next_data_in = 0;

        cw_next_write_address = 0;
        cw_next_write_en = 0;
        cw_n_next_write_en = 0;
        cw_next_data_in = 0;

        cnw_next_write_address = 0;
        cnw_next_write_en = 0;
        cnw_n_next_write_en = 0;
        cnw_next_data_in = 0;

        next_index = 0;
        next_width_count = 0;

        case(sim_state)
            IDLE: next_sim_state = STREAM;
            STREAM:
            begin
                //all modulo signs are placeholders as modulo operations are expensive, once I properly implement a counter I will make a column count from there 
                if(index == `DEPTH-1) 
                begin
                    next_index = 0;
                    next_width_count = 0;
                    next_sim_state = BOUNCE;
                end
                else
                begin
                    next_index = index + 1;
                    next_width_count = width_count + 1;
                    next_sim_state = STREAM;
                end

                cn_next_write_address = (index >= `WIDTH) ? index-`WIDTH: 0;
                cn_n_next_write_en = (index>= `WIDTH);
                cn_next_data_in = cn_data_out;

                cne_next_write_address = (index >= `WIDTH && (width_count == `WIDTH - 1)) ? index-`WIDTH+1 : 0;
                cne_n_next_write_en = (index >= `WIDTH && (width_count == `WIDTH - 1));
                cne_next_data_in = cne_data_out;

                ce_next_write_address = (width_count == `WIDTH - 1) ? index+1: 0;
                ce_n_next_write_en = (width_count == `WIDTH - 1);
                ce_next_data_in = ce_data_out;

                cse_next_write_address = (index <= `DEPTH-`WIDTH-1 && (width_count == `WIDTH - 1)) ? index+`WIDTH+1: 0;
                cse_n_next_write_en = (index <= `DEPTH-`WIDTH-1  && (width_count == `WIDTH - 1));
                cse_next_data_in = cse_data_out;

                cs_next_write_address = (index <= `DEPTH-`WIDTH-1) ? index+`WIDTH : 0;
                cs_n_next_write_en = (index <= `DEPTH-`WIDTH-1);
                cs_next_data_in = cs_data_out;

                csw_next_write_address = (index <= `DEPTH-`WIDTH-1 && (width_count == 0)) ? index+`WIDTH-1 : 0;
                csw_n_next_write_en = (index <= `DEPTH-`WIDTH-1 && (width_count == 0));
                csw_next_data_in = csw_data_out;

                cw_next_write_address = (width_count == 0) ? index - 1 : 0;
                cw_n_next_write_en = (width_count == 0);
                cw_next_data_in = cw_data_out;

                cnw_next_write_address = (index >= `WIDTH && (width_count == 0)) ? index - 1 - `WIDTH : 0;
                cnw_n_next_write_en = (index >= `WIDTH && (width_count == 0));
                cnw_next_data_in = cnw_data_out;
            end
            // WRITE_STREAM:
            // begin
            //     next_index = index + 1;
            //     next_width_count = next_width_count + 1;
            //     if(next_index > `DEPTH-1)
            //     begin
            //         next_index = 0;
            //         next_width_count = 0;
            //         next_sim_state = READ_BOUNCE;
            //     end
            //     else
            //         next_sim_state = READ_STREAM;
            // end
            BOUNCE:
            begin
                if(index == `DEPTH-1) 
                begin
                    next_index = 0;
                    next_width_count = 0;
                    next_sim_state = ZERO_BOUNCE;
                end
                else
                begin
                    next_index = index + 1;
                    next_width_count = width_count + 1;
                    next_sim_state = BOUNCE;
                end
                if(barriers[index] == 1'b1)
                begin
                    cn_next_write_address = (index >= `WIDTH) ? index-`WIDTH: 0;
                    cn_n_next_write_en = (index>= `WIDTH);
                    cn_next_data_in = cs_n_data_out;

                    cne_next_write_address = (index >= `WIDTH && (width_count == `WIDTH - 1)) ? index-`WIDTH+1 : 0;
                    cne_n_next_write_en = (index >= `WIDTH && (width_count == `WIDTH - 1));
                    cne_next_data_in = csw_n_data_out;

                    ce_next_write_address = (width_count == `WIDTH - 1) ? index+1: 0;
                    ce_n_next_write_en = (width_count == `WIDTH - 1);
                    ce_next_data_in = cw_n_data_out; 

                    cse_next_write_address = (index <= `DEPTH-`WIDTH-1 && (width_count == `WIDTH - 1)) ? index+`WIDTH+1: 0;
                    cse_n_next_write_en = (index <= `DEPTH-`WIDTH-1  && (width_count == `WIDTH - 1));
                    cse_next_data_in = cnw_n_data_out; 

                    cs_next_write_address = (index <= `DEPTH-`WIDTH-1) ? index+`WIDTH : 0;
                    cs_n_next_write_en = (index <= `DEPTH-`WIDTH-1);
                    cs_next_data_in = cn_n_data_out; 

                    csw_next_write_address = (index <= `DEPTH-`WIDTH-1 && (width_count == 0)) ? index+`WIDTH-1 : 0;
                    csw_n_next_write_en = (index <= `DEPTH-`WIDTH-1 && (width_count == 0));
                    csw_next_data_in = cne_n_data_out; 

                    cw_next_write_address = (width_count == 0) ? index - 1 : 0;
                    cw_n_next_write_en = (width_count == 0);
                    cw_next_data_in = ce_n_data_out; 

                    cnw_next_write_address = (index >= `WIDTH && (width_count == 0)) ? index - 1 - `WIDTH : 0;
                    cnw_n_next_write_en = (index >= `WIDTH && (width_count == 0));
                    cnw_next_data_in = cse_n_data_out; 
                end
            end
            // WRITE_BOUNCE:
            // begin
            //     next_index = index + 1;
            //     next_width_count = next_width_count + 1;
            //     if(next_index > `DEPTH-1)
            //     begin
            //         next_index = 0;
            //         next_width_count = 0;
            //         next_sim_state = ZERO_BOUNCE;
            //     end
            //     else
            //         next_sim_state = READ_BOUNCE;
            // end
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
                    next_width_count = width_count + 1;
                    next_sim_state = BOUNCE;
                end
                if(barriers[index] == 1'b1) //this is where you left off 
                begin
                    cn_next_write_address = index;
                    cn_n_next_write_en = 1'b1;
                    cn_next_data_in = 16'b0;

                    cne_next_write_address = index;
                    cne_n_next_write_en = 1'b1;
                    cne_next_data_in = 16'b0;

                    ce_next_write_address = index;
                    ce_n_next_write_en = 1'b1;
                    ce_next_data_in = 16'b0;

                    cse_next_write_address = index;
                    cse_n_next_write_en = 1'b1;
                    cse_next_data_in = 16'b0;

                    cs_next_write_address = index;
                    cs_n_next_write_en = 1'b1;
                    cs_next_data_in = 16'b0;

                    csw_next_write_address = index;
                    csw_n_next_write_en = 1'b1;
                    csw_next_data_in = 16'b0;

                    cw_next_write_address = index;
                    cw_n_next_write_en = 1'b1;
                    cw_next_data_in = 16'b0;

                    cnw_next_write_address = index;
                    cnw_n_next_write_en = 1'b1;
                    cnw_next_data_in = 16'b0;
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
                        next_index = index + 1;
                        next_width_count = width_count + 1;
                        next_sim_state = COLLIDE;
                    end
                    c0_next_write_address = index;
                    c0_next_write_en = 1'b1;
                    c0_next_data_in = c_c0;

                    cn_next_write_address = index;
                    cn_next_write_en = 1'b1;
                    cn_next_data_in = c_cn;

                    cne_next_write_address = index;
                    cne_next_write_en = 1'b1;
                    cne_next_data_in = c_cne;

                    ce_next_write_address = index;
                    ce_next_write_en = 1'b1;
                    ce_next_data_in = c_ce;

                    cse_next_write_address = index;
                    cse_next_write_en = 1'b1;
                    cse_next_data_in = c_cse;

                    cs_next_write_address = index;
                    cs_next_write_en = 1'b1;
                    cs_next_data_in = c_cs;

                    csw_next_write_address = index;
                    csw_next_write_en = 1'b1;
                    csw_next_data_in = c_csw;

                    cw_next_write_address = index;
                    cw_next_write_en = 1'b1;
                    cw_next_data_in = c_cw;

                    cnw_next_write_address = index;
                    cnw_next_write_en = 1'b1;
                    cnw_next_data_in = c_cnw;
                end
                else
                begin
                    next_sim_state = COLLIDE;
                end
            end
            default:
                next_sim_state = IDLE;
        endcase
    end

endmodule
