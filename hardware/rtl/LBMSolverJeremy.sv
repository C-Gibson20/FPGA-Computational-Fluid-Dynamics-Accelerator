`include "def.sv"

module LBMSolver (
    input logic clk,
    input logic rst,
    input logic barriers [0:`DEPTH-1],
    input logic en
);

    //States
    // localparam IDLE = 3'd0;
    // localparam READ_STREAM = 3'd1;
    // localparam WRITE_STREAM = 3'd2;
    // localparam READ_BOUNCE = 3'd3;
    // localparam WRITE_BOUNCE = 3'd4;
    // localparam ZERO_BOUNCE = 3'd5;

    typedef enum logic [2:0] {
        IDLE = 3'd0;
        READ_STREAM = 3'd1;
        WRITE_STREAM = 3'd2;
        READ_BOUNCE = 3'd3;
        WRITE_BOUNCE = 3'd4;
        ZERO_BOUNCE = 3'd5;
    } state_t;

    state_t sim_state, next_sim_state

    reg signed [`DATA_WIDTH-1:0] rho;
    reg signed [`DATA_WIDTH-1:0] rho_m_1;
    reg signed [`DATA_WIDTH-1:0] one_9th_rho;
    reg signed [`DATA_WIDTH-1:0] one_36th_rho;
    reg signed [`DATA_WIDTH-1:0] rho_inv;

    reg signed [`DATA_WIDTH-1:0] ux;
    reg signed [`DATA_WIDTH-1:0] uy;
    reg signed [`DATA_WIDTH-1:0] vx3;
    reg signed [`DATA_WIDTH-1:0] vy3;
    reg signed [`DATA_WIDTH-1:0] vxvy2;

    //reg [1:0] sim_state, next_sim_state;
    reg [`ADDRESS_WIDTH-1:0] index;
    reg [`ADDRESS_WIDTH-1:0] next_index;

    logic [`DATA_WIDTH-1:0] c0_data_in = 0, c0_data_out;
    logic c0_write_en = 0;
    logic [`ADDRESS_WIDTH-1:0] c0_write_address = 0;

    logic [`DATA_WIDTH-1:0] cn_data_in , cn_data_out;
    reg cn_write_en, cn_next_write_en;
    // logic [`ADDRESS_WIDTH-1:0] cn_read_address;
    reg [`ADDRESS_WIDTH-1:0] cn_write_address; 
    reg [`ADDRESS_WIDTH-1:0] cn_next_write_address;

    logic [`DATA_WIDTH-1:0] cne_data_in, cne_data_out;
    reg cne_write_en, cne_next_write_en;
    // logic [`ADDRESS_WIDTH-1:0] cne_read_address;
    reg [`ADDRESS_WIDTH-1:0] cne_write_address; 
    reg [`ADDRESS_WIDTH-1:0] cne_next_write_address;

    logic [`DATA_WIDTH-1:0] ce_data_in ,ce_data_out;
    reg ce_write_en, ce_next_write_en;
    // logic [`ADDRESS_WIDTH-1:0] ce_read_address;
    reg [`ADDRESS_WIDTH-1:0] ce_write_address; 
    reg [`ADDRESS_WIDTH-1:0] ce_next_write_address;

    logic [`DATA_WIDTH-1:0] cse_data_in , cse_data_out;
    reg cse_write_en, cse_next_write_en;
    // logic [`ADDRESS_WIDTH-1:0] cse_read_address;
    reg [`ADDRESS_WIDTH-1:0] cse_write_address; 
    reg [`ADDRESS_WIDTH-1:0] cse_next_write_address;

    logic [`DATA_WIDTH-1:0] cs_data_in, cs_data_out;
    reg cs_write_en, cs_next_write_en;
    // logic [`ADDRESS_WIDTH-1:0] cs_read_address;
    reg [`ADDRESS_WIDTH-1:0] cs_write_address; 
    reg [`ADDRESS_WIDTH-1:0] cs_next_write_address;

    logic [`DATA_WIDTH-1:0] csw_data_in, csw_data_out;
    reg csw_write_en, csw_next_write_en;
    // logic [`ADDRESS_WIDTH-1:0] csw_read_address;
    reg [`ADDRESS_WIDTH-1:0] csw_write_address; 
    reg [`ADDRESS_WIDTH-1:0] csw_next_write_address;

    logic [`DATA_WIDTH-1:0] cw_data_in, cw_data_out;
    reg cw_write_en, cw_next_write_en;
    // logic [`ADDRESS_WIDTH-1:0] cw_write_address, cw_read_address;
    reg [`ADDRESS_WIDTH-1:0] cw_write_address; 
    reg [`ADDRESS_WIDTH-1:0] cw_next_write_address;

    logic [`DATA_WIDTH-1:0] cnw_data_in, cnw_data_out;
    reg cnw_write_en, cnw_next_write_en;
    // logic [`ADDRESS_WIDTH-1:0] cnw_read_address;
    reg [`ADDRESS_WIDTH-1:0] cnw_write_address; 
    reg [`ADDRESS_WIDTH-1:0] cnw_next_write_address;

    //Stores the 9 directions in their own RAM, I can't make each cell it's own block of memory, so instead I've decided to split the memory by direction
    RAM C0(
        .read_address(index),
        .write_address(c0_write_address),
        .data_in(c0_data_in),
        .clk(clk),
        .write_en(c0_write_en),
        .data_out(c0_data_out)
    );

    RAM CN(
        .read_address(index),
        .write_address(cn_write_address),
        .data_in(cn_data_in),
        .clk(clk),
        .write_en(cn_write_en),
        .data_out(cn_data_out)
    );

    RAM CNE(
        .read_address(index),
        .write_address(cne_write_address),
        .data_in(cne_data_in),
        .clk(clk),
        .write_en(cne_write_en),
        .data_out(cne_data_out)
    );

    RAM CE(
        .read_address(index),
        .write_address(ce_write_address),
        .data_in(ce_data_in),
        .clk(clk),
        .write_en(ce_write_en),
        .data_out(ce_data_out)
    );

    RAM CSE(
        .read_address(index),
        .write_address(cse_write_address),
        .data_in(cse_data_in),
        .clk(clk),
        .write_en(cse_write_en),
        .data_out(cse_data_out)
    );

    RAM CS(
        .read_address(index),
        .write_address(cs_write_address),
        .data_in(cs_data_in),
        .clk(clk),
        .write_en(cs_write_en),
        .data_out(cs_data_out)
    );

    RAM CSW(
        .read_address(index),
        .write_address(csw_write_address),
        .data_in(csw_data_in),
        .clk(clk),
        .write_en(csw_write_en),
        .data_out(csw_data_out)
    );

    RAM CW(
        .read_address(index),
        .write_address(cw_write_address),
        .data_in(cw_data_in),
        .clk(clk),
        .write_en(cw_write_en),
        .data_out(cw_data_out)
    );

    RAM CNW(
        .read_address(index),
        .write_address(cnw_write_address),
        .data_in(cnw_data_in),
        .clk(clk),
        .write_en(cnw_write_en),
        .data_out(cnw_data_out)
    );

    //Update stream state
    always @(posedge clk or posedge rst)
    begin
        if(rst) 
        begin
            sim_state <= IDLE;
            index <= 0;
        end
        else 
        begin
            sim_state <= next_sim_state;
            index <= next_index;
            cn_write_address <= cn_next_write_address;
            cn_write_en <= cn_next_write_en;
            cne_write_address <= cne_next_write_address;
            cne_write_en <= cne_next_write_en;
            ce_write_address <= ce_next_write_address;
            ce_write_en <= ce_next_write_en;
            cse_write_address <= cse_next_write_address;
            cse_write_en <= cse_next_write_en;
            cs_write_address <= cs_next_write_address;
            cs_write_en <= cs_next_write_en;
            csw_write_address <= csw_next_write_address;
            csw_write_en <= csw_next_write_en;
            cw_write_address <= cw_next_write_address;
            cw_write_en <= cw_next_write_en;
            cnw_write_address <= cnw_next_write_address;
            cnw_write_en <= cnw_next_write_en;
            if(sim_state == WRITE_BOUNCE && barriers[index] == 1'b1)
            begin
                cn_data_in  <= cs_data_out;
                cne_data_in <= csw_data_out;
                ce_data_in  <= cw_data_out;
                cse_data_in <= cnw_data_out;
                cs_data_in  <= cn_data_out;
                csw_data_in <= cne_data_out;
                cw_data_in  <= ce_data_out;
                cnw_data_in <= cse_data_out;
            end
            else if(sim_state == ZERO_BOUNCE && barriers[index] == 1'b1)
            begin
                cn_data_in  <= 0;
                cne_data_in <= 0;
                ce_data_in  <= 0;
                cse_data_in <= 0;
                cs_data_in  <= 0;
                csw_data_in <= 0;
                cw_data_in  <= 0;
                cnw_data_in <= 0;
            end
            else
            begin
                cn_data_in  <= cn_data_out;
                cne_data_in  <= cne_data_out;
                ce_data_in  <= ce_data_out;
                cse_data_in  <= cse_data_out;
                cs_data_in  <= cs_data_out;
                csw_data_in  <= csw_data_out;
                cw_data_in  <= cw_data_out;
                cnw_data_in  <= cnw_data_out;
            end
        end
    end


    //Stream state
    always_comb begin
        cn_next_write_address = 0;
        cn_next_write_en = 0;
        cne_next_write_address = 0;
        cne_next_write_en = 0;
        ce_next_write_address = 0;
        ce_next_write_en = 0;
        cse_next_write_address = 0;
        cse_next_write_en = 0;
        cs_next_write_address = 0;
        cs_next_write_en = 0;
        csw_next_write_address = 0;
        csw_next_write_en = 0;
        cw_next_write_address = 0;
        cw_next_write_en = 0;
        cnw_next_write_address = 0;
        cnw_next_write_en = 0;
        next_index = 0;
        case(sim_state)
            IDLE: next_sim_state = READ_STREAM;
            READ_STREAM:
            begin
                //all modulo signs are placeholders as modulo operations are expensive, once I properly implement a counter I will make a column count from there 
                next_sim_state = WRITE_STREAM;
                cn_next_write_address = (index >= `WIDTH) ? index-`WIDTH: 0;
                cn_next_write_en = (index>= `WIDTH);
                cne_next_write_address = (index >= `WIDTH && ((index%`WIDTH) != `WIDTH-1)) ? index-`WIDTH+1 : 0;
                cne_next_write_en = (index >= `WIDTH && ((index%`WIDTH) != `WIDTH-1));
                ce_next_write_address = ((index%`WIDTH) != `WIDTH-1) ? index+1: 0;
                ce_next_write_en = ((index%`WIDTH) != `WIDTH-1);
                cse_next_write_address = (index <= `DEPTH-`WIDTH-1 && ((index%`WIDTH) != `WIDTH-1)) ? index+`WIDTH+1: 0;
                cse_next_write_en = (index <= `DEPTH-`WIDTH-1  && ((index%`WIDTH) != `WIDTH-1));
                cs_next_write_address = (index <= `DEPTH-`WIDTH-1) ? index+`WIDTH : 0;
                cs_next_write_en = (index <= `DEPTH-`WIDTH-1);
                csw_next_write_address = (index <= `DEPTH-`WIDTH-1 && (index%`WIDTH != 0)) ? index+`WIDTH-1 : 0;
                csw_next_write_en = (index <= `DEPTH-`WIDTH-1 && (index%`WIDTH != 0));
                cw_next_write_address = (index%`WIDTH != 0) ? index - 1 : 0;
                cw_next_write_en = (index%`WIDTH != 0);
                cnw_next_write_address = (index >= `WIDTH && (index%`WIDTH != 0)) ? index - 1 - `WIDTH : 0;
                cnw_next_write_en = (index >= `WIDTH && (index%`WIDTH != 0));
            end
            WRITE_STREAM:
            begin
                next_index++;
                if(next_index > `DEPTH-1)
                begin
                    next_index = 0;
                    next_sim_state = READ_BOUNCE;
                end
                else
                    next_sim_state = READ_STREAM;
            end
            READ_BOUNCE:
            begin
                next_sim_state = WRITE_BOUNCE;
                if(barriers[index] == 1'b1)
                begin
                    cn_next_write_address = (index >= `WIDTH) ? index-`WIDTH: 0;
                    cn_next_write_en = (index>= `WIDTH);
                    cne_next_write_address = (index >= `WIDTH && ((index%`WIDTH) != `WIDTH-1)) ? index-`WIDTH+1 : 0;
                    cne_next_write_en = (index >= `WIDTH && ((index%`WIDTH) != `WIDTH-1));
                    ce_next_write_address = ((index%`WIDTH) != `WIDTH-1) ? index+1: 0;
                    ce_next_write_en = ((index%`WIDTH) != `WIDTH-1);
                    cse_next_write_address = (index <= `DEPTH-`WIDTH-1 && ((index%`WIDTH) != `WIDTH-1)) ? index+`WIDTH+1: 0;
                    cse_next_write_en = (index <= `DEPTH-`WIDTH-1  && ((index%`WIDTH) != `WIDTH-1));
                    cs_next_write_address = (index <= `DEPTH-`WIDTH-1) ? index+`WIDTH : 0;
                    cs_next_write_en = (index <= `DEPTH-`WIDTH-1);
                    csw_next_write_address = (index <= `DEPTH-`WIDTH-1 && (index%`WIDTH != 0)) ? index+`WIDTH-1 : 0;
                    csw_next_write_en = (index <= `DEPTH-`WIDTH-1 && (index%`WIDTH != 0));
                    cw_next_write_address = (index%`WIDTH != 0) ? index - 1 : 0;
                    cw_next_write_en = (index%`WIDTH != 0);
                    cnw_next_write_address = (index >= `WIDTH && (index%`WIDTH != 0)) ? index - 1 - `WIDTH : 0;
                    cnw_next_write_en = (index >= `WIDTH && (index%`WIDTH != 0));
                end
            end
            WRITE_BOUNCE:
            begin
                next_index++;
                if(next_index > `DEPTH-1)
                begin
                    next_index = 0;
                    next_sim_state = ZERO_BOUNCE;
                end
                else
                    next_sim_state = READ_BOUNCE;
            end
            ZERO_BOUNCE:
            begin
                next_index++;
                cn_next_write_address = index;
                cn_next_write_en = 1'b1;
                cne_next_write_address = index;
                cne_next_write_en = 1'b1;
                ce_next_write_address = index;
                ce_next_write_en = 1'b1;
                cse_next_write_address = index;
                cse_next_write_en = 1'b1;
                cs_next_write_address = index;
                cs_next_write_en = 1'b1;
                csw_next_write_address = index;
                csw_next_write_en = 1'b1;
                cw_next_write_address = index;
                cw_next_write_en = 1'b1;
                cnw_next_write_address = index;
                cnw_next_write_en = 1'b1;
                if(next_index > `DEPTH-1)
                begin
                    next_index = 0;
                    next_sim_state = IDLE; //WRONG
                end
                else
                    next_sim_state = ZERO_BOUNCE;
            end
            //COLLISION_READ: //needs to be multiple stages or else this won't be clocked very fast
            // begin
            //     rho = c0_data_out + cn_data_out + cne_data_out + ce_data_out + cse_data_out + cs_data_out + csw_data_out + cw_data_out + cnw_data_out;
            // end
            default:
                next_sim_state = IDLE;
        endcase
    end

endmodule
