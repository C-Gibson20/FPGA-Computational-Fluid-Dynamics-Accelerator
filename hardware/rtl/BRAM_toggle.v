module BRAM_toggle(
    input  wire m00_axis_aclk,
    input  wire m00_axis_aresetn,

    input  wire chunk_transfer_ready,
    input  wire chunk_compute_ready,

    // LBM solver input addresses
    input  wire [11:0] null1, n1, ne1, e1, se1, s1, sw1, w1, nw1,

    // LBM solver write enables
    input  wire LBM_null_w, LBM_n_w, LBM_ne_w, LBM_e_w, LBM_se_w,
                 LBM_s_w, LBM_sw_w, LBM_w_w, LBM_nw_w,

    // LBM solver data_in    
    input  wire [15:0] LBM_null_in, LBM_n_in, LBM_ne_in, LBM_e_in, LBM_se_in,
                 LBM_s_in, LBM_sw_in, LBM_w_in, LBM_nw_in,

    // LBM solver data_out
    output wire [15:0] LBM_null_out, LBM_n_out, LBM_ne_out, LBM_e_out, LBM_se_out,
                LBM_s_out, LBM_sw_out, LBM_w_out, LBM_nw_out,

    // Cache data_in    
    input  wire [15:0] cache_null_in, cache_n_in, cache_ne_in, cache_e_in, cache_se_in,
                 cache_s_in, cache_sw_in, cache_w_in, cache_nw_in,

    // Cache data_out
    output wire [15:0] cache_null_out, cache_n_out, cache_ne_out, cache_e_out, cache_se_out,
                cache_s_out, cache_sw_out, cache_w_out, cache_nw_out,

    // Cache address
    input  wire [11:0] DDR_addr,
    
    //cache write enable
    input wire cache_wen,

    // Data input into BRAM
    output reg [15:0] null1_data_in, n1_data_in, ne1_data_in, e1_data_in, se1_data_in,
               s1_data_in, sw1_data_in, w1_data_in, nw1_data_in,

    // Data output from BRAM
    input  wire [15:0] null1_data_out, n1_data_out, ne1_data_out, e1_data_out, se1_data_out,
                 s1_data_out, sw1_data_out, w1_data_out, nw1_data_out,

    // Write enables to BRAM
    output reg null1_wen, n1_wen, ne1_wen, e1_wen, se1_wen,
               s1_wen, sw1_wen, w1_wen, nw1_wen,

    // BRAM addresses
    output reg [11:0] null1_out, n1_out, ne1_out, e1_out, se1_out,
                      s1_out, sw1_out, w1_out, nw1_out
);

    // Combinational control block
    always @(*) begin
        // Default outputs
        null1_out = 0;  n1_out = 0;  ne1_out = 0;  e1_out = 0;
        se1_out   = 0;  s1_out = 0;  sw1_out = 0;  w1_out = 0;  nw1_out = 0;

        null1_wen = 0;  n1_wen = 0;  ne1_wen = 0;  e1_wen = 0;
        se1_wen   = 0;  s1_wen = 0;  sw1_wen = 0;  w1_wen = 0;  nw1_wen = 0;

        null1_data_in = 0;  n1_data_in = 0;  ne1_data_in = 0;  e1_data_in = 0;
        se1_data_in   = 0;  s1_data_in = 0;  sw1_data_in = 0;  w1_data_in = 0;  nw1_data_in = 0;

        if (!m00_axis_aresetn) begin
            // If reset, do nothing (everything is already defaulted to zero)
        end else if (chunk_transfer_ready) begin
            null1_out = DDR_addr;  n1_out = DDR_addr;  ne1_out = DDR_addr;  e1_out = DDR_addr;
            se1_out   = DDR_addr;  s1_out = DDR_addr;  sw1_out = DDR_addr;  w1_out = DDR_addr;  nw1_out = DDR_addr;

            null1_wen = cache_wen;  n1_wen = cache_wen;  ne1_wen = cache_wen;  e1_wen = cache_wen;
            se1_wen   = cache_wen;  s1_wen = cache_wen;  sw1_wen = cache_wen;  w1_wen = cache_wen;  nw1_wen = cache_wen;

            null1_data_in = cache_null_in;  n1_data_in = cache_n_in;
            ne1_data_in   = cache_ne_in;    e1_data_in = cache_e_in;
            se1_data_in   = cache_se_in;    s1_data_in = cache_s_in;
            sw1_data_in   = cache_sw_in;    w1_data_in = cache_w_in;
            nw1_data_in   = cache_nw_in;
        end else if (chunk_compute_ready) begin
            null1_out = null1;  n1_out = n1;  ne1_out = ne1;  e1_out = e1;
            se1_out   = se1;    s1_out = s1;  sw1_out = sw1;  w1_out = w1;  nw1_out = nw1;

            null1_wen = LBM_null_w;  n1_wen = LBM_n_w;  ne1_wen = LBM_ne_w;
            e1_wen    = LBM_e_w;     se1_wen = LBM_se_w;  s1_wen = LBM_s_w;
            sw1_wen   = LBM_sw_w;    w1_wen = LBM_w_w;    nw1_wen = LBM_nw_w;

            null1_data_in = LBM_null_in;  n1_data_in = LBM_n_in;
            ne1_data_in   = LBM_ne_in;    e1_data_in = LBM_e_in;
            se1_data_in   = LBM_se_in;    s1_data_in = LBM_s_in;
            sw1_data_in   = LBM_sw_in;    w1_data_in = LBM_w_in;
            nw1_data_in   = LBM_nw_in;
        end
    end

    // Continuous assignments for outputs
    assign cache_null_out = null1_data_out;
    assign cache_n_out    = n1_data_out;
    assign cache_ne_out   = ne1_data_out;
    assign cache_e_out    = e1_data_out;
    assign cache_se_out   = se1_data_out;
    assign cache_s_out    = s1_data_out;
    assign cache_sw_out   = sw1_data_out;
    assign cache_w_out    = w1_data_out;
    assign cache_nw_out   = nw1_data_out;

    assign LBM_null_out = null1_data_out;
    assign LBM_n_out    = n1_data_out;
    assign LBM_ne_out   = ne1_data_out;
    assign LBM_e_out    = e1_data_out;
    assign LBM_se_out   = se1_data_out;
    assign LBM_s_out    = s1_data_out;
    assign LBM_sw_out   = sw1_data_out;
    assign LBM_w_out    = w1_data_out;
    assign LBM_nw_out   = nw1_data_out;

endmodule
