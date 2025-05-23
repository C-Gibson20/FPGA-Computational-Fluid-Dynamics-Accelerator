`include "def.sv"

module LBMSolver (
    input logic clk,
    input logic rst, 
    input logic en
);

    localparam IDLE = 2'd0;
    localparam READ = 2'd1;
    localparam WRITE = 2'd2;

    reg [1:0] stream_state, next_stream_state;
    reg [ADDRESS_WIDTH-1:0] index;

    logic [`DATA_WIDTH-1:0] c0_data_in, c0_data_out;
    logic c0_mem_write;
    logic [`ADDRESS_WIDTH-1:0] c0_write_address,c0_read_address;

    logic [`DATA_WIDTH-1:0] cn_data_in , cn_data_out;
    reg cn_mem_write, cn_next_mem_write;
    logic [`ADDRESS_WIDTH-1:0] cn_read_address;
    reg [`ADDRESS_WIDTH-1:0] cn_write_address; 
    reg [`ADDRESS_WIDTH-1:0] cn_next_write_address;

    logic [`DATA_WIDTH-1:0] cne_data_in, cne_data_out;
    reg cne_mem_write, cne_next_mem_write;
    logic [`ADDRESS_WIDTH-1:0] cne_read_address;
    reg [`ADDRESS_WIDTH-1:0] cne_write_address; 
    reg [`ADDRESS_WIDTH-1:0] cne_next_write_address;

    logic [`DATA_WIDTH-1:0] ce_data_in ,ce_data_out;
    reg ce_mem_write, ce_next_mem_write;
    logic [`ADDRESS_WIDTH-1:0] ce_read_address;
    reg [`ADDRESS_WIDTH-1:0] ce_write_address; 
    reg [`ADDRESS_WIDTH-1:0] ce_next_write_address;

    logic [`DATA_WIDTH-1:0] cse_data_in , cse_data_out;
    reg cse_mem_write, , cse_next_mem_write;
    logic [`ADDRESS_WIDTH-1:0] cse_read_address;
    reg [`ADDRESS_WIDTH-1:0] cse_write_address; 
    reg [`ADDRESS_WIDTH-1:0] cse_next_write_address;

    logic [`DATA_WIDTH-1:0] cs_data_in, cs_data_out;
    reg cs_mem_write, , cs_next_mem_write;
    logic [`ADDRESS_WIDTH-1:0] cs_read_address;
    reg [`ADDRESS_WIDTH-1:0] cs_write_address; 
    reg [`ADDRESS_WIDTH-1:0] cs_next_write_address;

    logic [`DATA_WIDTH-1:0] csw_data_in, csw_data_out;
    reg csw_mem_write, csw_next_mem_write;
    logic [`ADDRESS_WIDTH-1:0] csw_read_address;
    reg [`ADDRESS_WIDTH-1:0] csw_write_address; 
    reg [`ADDRESS_WIDTH-1:0] csw_next_write_address;

    logic [`DATA_WIDTH-1:0] cw_data_in, cw_data_out;
    reg cw_mem_write, cw_next_mem_write;
    logic [`ADDRESS_WIDTH-1:0] cw_write_address, cw_read_address;
    reg [`ADDRESS_WIDTH-1:0] cw_write_address; 
    reg [`ADDRESS_WIDTH-1:0] cw_next_write_address;

    logic [`DATA_WIDTH-1:0] cnw_data_in, cnw_data_out;
    reg cnw_mem_write, cnw_next_mem_write;
    logic [`ADDRESS_WIDTH-1:0] cnw_read_address;
    reg [`ADDRESS_WIDTH-1:0] cnw_write_address; 
    reg [`ADDRESS_WIDTH-1:0] cnw_next_write_address;

    //Stores the 9 directions in their own RAM, I can't make each cell it's own block of memory, so instead I've decided to split the memory by direction
    RAM C0(
        .read_address(c0_read_address),
        .write_address(c0_write_address),
        .data_in(c0_data_in),
        .clk(clk),
        .mem_write(c0_mem_write),
        .data_out(c0_data_out)
    );

    RAM CN(
        .read_address(cn_read_address),
        .write_address(cn_write_address),
        .data_in(cn_data_in),
        .clk(clk),
        .mem_write(cn_mem_write),
        .data_out(cn_data_out)
    );

    RAM CNE(
        .read_address(cne_read_address),
        .write_address(cne_write_address),
        .data_in(cne_data_in),
        .clk(clk),
        .mem_write(cne_mem_write),
        .data_out(cne_data_out)
    );

    RAM CE(
        .read_address(ce_read_address),
        .write_address(ce_write_address),
        .data_in(ce_data_in),
        .clk(clk),
        .mem_write(ce_mem_write),
        .data_out(ce_data_out)
    );

    RAM CSE(
        .read_address(cse_read_address),
        .write_address(cse_write_address),
        .data_in(cse_data_in),
        .clk(clk),
        .mem_write(cse_mem_write),
        .data_out(cse_data_out)
    );

    RAM CS(
        .read_address(cs_read_address),
        .write_address(cs_write_address),
        .data_in(cs_data_in),
        .clk(clk),
        .mem_write(cs_mem_write),
        .data_out(cs_data_out)
    );

    RAM CSW(
        .read_address(csw_read_address),
        .write_address(csw_write_address),
        .data_in(csw_data_in),
        .clk(clk),
        .mem_write(csw_mem_write),
        .data_out(csw_data_out)
    );

    RAM CW(
        .read_address(cw_read_address),
        .write_address(cw_write_address),
        .data_in(cw_data_in),
        .clk(clk),
        .mem_write(cw_mem_write),
        .data_out(cw_data_out)
    );

    RAM CNW(
        .read_address(cnw_read_address),
        .write_address(cnw_write_address),
        .data_in(cnw_data_in),
        .clk(clk),
        .mem_write(cnw_mem_write),
        .data_out(cnw_data_out)
    );

    //Update stream state
    alway @(posedge clk or posedge rst)
    begin
        if(rst) 
        begin
            stream_state <= IDLE;
            index <= 0;
            cn_write_address <= 0;
        end
        else 
        begin
            stream_state <= next_stream_state;
            cn_write_address <= cn_next_write_address;
            cne_write_address <= cne_next_write_address;
            ce_write_address <= ce_next_write_address;
            cse_write_address <= cse_next_write_address;
            cs_write_address <= cs_next_write_address;
            csw_write_address <= csw_next_write_address;
            cw_write_address <= cw_next_write_address;
            cnw_write_address <= cnw_next_write_address;
        end
    end

    //Stream state
    always @(*) begin
        cn_next_write_address = 0;
        cn_next_mem_write = 0;
        cne_next_write_address = 0;
        cne_next_mem_write = 0;
        ce_next_write_address = 0;
        ce_next_mem_write = 0;
        cse_next_write_address = 0;
        cse_next_mem_write = 0;
        cs_next_write_address = 0;
        cs_next_mem_write = 0;
        csw_next_write_address = 0;
        csw_next_mem_write = 0;
        cw_next_write_address = 0;
        cw_next_mem_write = 0;
        cnw_next_write_address = 0;
        cnw_next_mem_write = 0;
        case(stream_state)
            IDLE: next_stream_state = READ;
            READ:
            begin
                //all modulo signs are placeholders as modulo operations are expensive, once I properly implement a counter I will make a column count from there 
                next_stream_state = WRITE;
                cn_next_write_address = (index >= `WIDTH) ? index-`WIDTH: 0;
                cn_next_mem_write = (index>= `WIDTH);
                cne_next_write_address = (index >= `WIDTH && ((index%`WIDTH) != `WIDTH-1)) ? index-`WIDTH+1 : 0;
                cne_next_mem_write = (index >= `WIDTH && ((index%`WIDTH) != `WIDTH-1));
                ce_next_write_address = ((index%`WIDTH) != `WIDTH-1) ? index+1: 0;
                ce_next_mem_write = ((index%`WIDTH) != `WIDTH-1);
                cse_next_write_address = (index <= `DEPTH-`WIDTH-1 && ((index%`WIDTH) != `WIDTH-1)) ? index+`WIDTH+1: 0;
                cse_next_mem_write = (index <= `DEPTH-`WIDTH-1  && ((index%`WIDTH) != `WIDTH-1));
                cs_next_write_address = (index <= `DEPTH-`WIDTH-1) ? index+`WIDTH : 0;
                cs_next_mem_write = (index <= `DEPTH-`WIDTH-1);
                csw_next_write_address = (index <= `DEPTH-`WIDTH-1 && (index%`WIDTH != 0)) ? index+`WIDTH-1 : 0;
                csw_next_mem_write = (index <= `DEPTH-`WIDTH-1 && (index%`WIDTH != 0));
                cw_next_write_address = (index%`WIDTH != 0) ? index - 1 : 0;
                cw_next_mem_write = (index%`WIDTH != 0);
                cnw_next_write_address = (index >= `WIDTH && (index%`WIDTH != 0)) ? index - 1 - `WIDTH : 0;
                cnw_next_mem_write = (index >= `WIDTH && (index%`WIDTH != 0));
            end
            WRITE:
            begin
                next_stream_state = IDLE;
            end
        endcase
    end

endmodule
