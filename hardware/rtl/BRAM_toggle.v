// `timescale 1ns / 1ps
// //////////////////////////////////////////////////////////////////////////////////
// // Company: 
// // Engineer: 
// // 
// // Create Date: 16.06.2025 01:56:25
// // Design Name: 
// // Module Name: cache_top
// // Project Name: 
// // Target Devices: 
// // Tool Versions: 
// // Description: 
// // 
// // Dependencies: 
// // 
// // Revision:
// // Revision 0.01 - File Created
// // Additional Comments:
// // 
// //////////////////////////////////////////////////////////////////////////////////

// //data_out goes out from BRAM into LBMsolver or cache system
// //data_in receives data from LBMsolver or cache system and inputs into BRAM
// module cache_toggle(
//     input wire m00_axis_aclk,
//     input wire m00_axis_aresetn,
    
//     input wire chunk_transfer_ready,
//     input wire chunk_compute_ready,


//     //LBM solver input addresses
//     input wire [11:0] null1,
//     input wire [11:0] n1,
//     input wire [11:0] ne1,
//     input wire [11:0] e1,
//     input wire [11:0] se1,
//     input wire [11:0] s1,
//     input wire [11:0] sw1,
//     input wire [11:0] w1,
//     input wire [11:0] nw1,
    
//     //LBM solver write enables
//     input wire LBM_null_w,
//     input wire LBM_n_w,
//     input wire LBM_ne_w,
//     input wire LBM_e_w,
//     input wire LBM_se_w,
//     input wire LBM_s_w,
//     input wire LBM_sw_w,
//     input wire LBM_w_w,
//     input wire LBM_nw_w,
    
//     //LBM solver data_in    
//     input wire LBM_null_in,
//     input wire LBM_n_in,
//     input wire LBM_ne_in,
//     input wire LBM_e_in,
//     input wire LBM_se_in,
//     input wire LBM_s_in,
//     input wire LBM_sw_in,
//     input wire LBM_w_in,
//     input wire LBM_nw_in,
    
//     //LBM solver data_out
//     output reg LBM_null_out,
//     output reg LBM_n_out,
//     output reg LBM_ne_out,
//     output reg LBM_e_out,
//     output reg LBM_se_out,
//     output reg LBM_s_out,
//     output reg LBM_sw_out,
//     output reg LBM_w_out,
//     output reg LBM_nw_out,
    
    
//     //cache data_in    
//     input wire cache_null_in,
//     input wire cache_n_in,
//     input wire cache_ne_in,
//     input wire cache_e_in,
//     input wire cache_se_in,
//     input wire cache_s_in,
//     input wire cache_sw_in,
//     input wire cache_w_in,
//     input wire cache_nw_in,
    
//     //cache data_out
//     output reg cache_null_out,
//     output reg cache_n_out,
//     output reg cache_ne_out,
//     output reg cache_e_out,
//     output reg cache_se_out,
//     output reg cache_s_out,
//     output reg cache_sw_out,
//     output reg cache_w_out,
//     output reg cache_nw_out,
    
//     //cache address
//     input wire [11:0] DDR_addr,
    
    
    
//     //input data into BRAM
//     output reg null1_data_in,
//     output reg n1_data_in,
//     output reg ne1_data_in,
//     output reg e1_data_in,
//     output reg se1_data_in,
//     output reg s1_data_in,  
//     output reg sw1_data_in,
//     output reg w1_data_in,
//     output reg nw1_data_in,
    
//     //output data into BRAM
//     input wire null1_data_out,
//     input wire n1_data_out,
//     input wire ne1_data_out,    
//     input wire e1_data_out,
//     input wire se1_data_out,    
//     input wire s1_data_out,    
//     input wire sw1_data_out,    
//     input wire w1_data_out,   
//     input wire nw1_data_out,  
    
//     //output write enables
//     output reg null1_wen,
//     output reg n1_wen,
//     output reg ne1_wen,
//     output reg e1_wen,
//     output reg se1_wen,
//     output reg s1_wen,
//     output reg sw1_wen,
//     output reg w1_wen,
//     output reg nw1_wen,
    
    
//     //output addresses
//     output reg [11:0] null1_out,
//     output reg [11:0] n1_out,
//     output reg [11:0] ne1_out,
//     output reg [11:0] e1_out,
//     output reg [11:0] se1_out,
//     output reg [11:0] s1_out,
//     output reg [11:0] sw1_out,
//     output reg [11:0] w1_out,
//     output reg [11:0] nw1_out         
//     );

//     always @(posedge m00_axis_aclk or negedge m00_axis_aresetn) begin
//         if (!m00_axis_aresetn) begin
//             {null1_out, n1_out, ne1_out, e1_out, se1_out, s1_out, sw1_out, w1_out, nw1_out} <= 0;
//             wen  <= 0;
//         end 
//         else begin
//             if (chunk_transfer_ready) begin
//                 //cache address
//                 null1_out <= DDR_addr;
//                 n1_out    <= DDR_addr;
//                 ne1_out   <= DDR_addr;
//                 e1_out    <= DDR_addr;
//                 se1_out   <= DDR_addr;
//                 s1_out    <= DDR_addr;
//                 sw1_out   <= DDR_addr;
//                 w1_out    <= DDR_addr;
//                 nw1_out   <= DDR_addr;
                
//                 //cache write enable
//                 null1_wen <= 1;
//                 n1_wen    <= 1;
//                 ne1_wen   <= 1;
//                 e1_wen    <= 1;
//                 se1_wen   <= 1;
//                 s1_wen    <= 1;
//                 sw1_wen   <= 1;
//                 w1_wen    <= 1;
//                 nw1_wen   <= 1;
                
//                 //cache data in
//                 cache_null_in
//                 cache_n_in
//                 cache_ne_in
//                 cache_e_in
//                 cache_se_in
//                 cache_s_in
//                 cache_sw_in
//                 cache_w_in
//                 cache_nw_in
                
//                 //cache data_out
//                n1_out <= cache_null_out 
//                ne1_out <= cache_n_out
//                e1_out <= cache_ne_out
//                se1_out <= cache_e_out
//                s1_out <= cache_se_out
//                sw1_out <= cache_s_out
//                w1_out <= cache_sw_out
//                nw1_out <= cache_w_out
//                nw1_out <= cache_nw_out
            
//             end 
//             else if (chunk_compute_ready) begin
//                 //LBM solver addresses
//                 null1_out <= null1;
//                 n1_out <= n1;
//                 ne1_out <= ne1;
//                 e1_out <= e1;
//                 se1_out <= se1;
//                 s1_out <= s1;
//                 sw1_out <= sw1;
//                 w1_out <= w1;
//                 nw1_out <= nw1;   
                
//                 //LBM solver data out       
//                  null1_data_out<= LBM_null_out;
//                  n1_data_out <= LBM_n_out;
//                  ne1_data_out <= LBM_ne_out;
//                 e1_data_out <= LBM_e_out;
//                  se1_data_out, <= LBM_se_out;
//                 <s1_data_out,  = LBM_s_out;
//                  sw1_data_out, <= LBM_sw_out;
//                 <w1_data_out,  = LBM_w_out;
//                  nw1_data_out, <= LBM_nw_out;
                
//                //LBM solver write enable
//                 null1_wen <= LBM_null_w;
//                 n1_wen <= LBM_n_w;
//                 ne1_wen <= LBM_ne_w;
//                 e1_wen <= LBM_e_w;
//                 se1_wen <= LBM_se_w;
//                 s1_wen <= LBM_s_w;
//                 sw1_wen <= LBM_sw_w;
//                 w1_wen <= LBM_w_w;
//                 nw1_wen <= LBM_nw_w;
                
//                 //LBM solver data in
                
                
//             end 
//         end
//     end
    
// endmodule

`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 16.06.2025 01:56:25
// Design Name: 
// Module Name: cache_toggle
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
//   Fully combinational version: routes addresses, data-in, data-out and write enables
//   either for DDR ↔ BRAM transfer or for LBM compute, based solely on the two
//   “ready” inputs. No flops, no reset.
// 
//////////////////////////////////////////////////////////////////////////////////

module cache_toggle (
    // system
    input  wire         m00_axis_aresetn,   // still available if you want to gate off all outputs
    input  wire         chunk_transfer_ready,
    input  wire         chunk_compute_ready,

    // LBM solver interface
    input  wire [11:0]  null1, n1, ne1, e1, se1, s1, sw1, w1, nw1,
    input  wire         LBM_null_w, LBM_n_w, LBM_ne_w, LBM_e_w,
                       LBM_se_w,  LBM_s_w,  LBM_sw_w, LBM_w_w, LBM_nw_w,
    input  wire         LBM_null_in, LBM_n_in,  LBM_ne_in, LBM_e_in,
                       LBM_se_in,   LBM_s_in,   LBM_sw_in, LBM_w_in, LBM_nw_in,
    input  wire         null1_data_out, n1_data_out, ne1_data_out,
                       e1_data_out,   se1_data_out, s1_data_out,
                       sw1_data_out,  w1_data_out,   nw1_data_out,

    // Cache (DDR) interface
    input  wire [11:0]  DDR_addr,
    input  wire         cache_null_in, cache_n_in,  cache_ne_in, cache_e_in,
                       cache_se_in,   cache_s_in,   cache_sw_in, cache_w_in, cache_nw_in,

    // BRAM side
    output reg  [11:0]  null1_out, n1_out, ne1_out, e1_out, se1_out, s1_out, sw1_out, w1_out, nw1_out,
    output reg          null1_wen,  n1_wen,    ne1_wen,   e1_wen,   se1_wen,
                       s1_wen,    sw1_wen,   w1_wen,    nw1_wen,
    output reg          null1_data_in, n1_data_in, ne1_data_in,
                       e1_data_in,   se1_data_in, s1_data_in,
                       sw1_data_in,  w1_data_in,   nw1_data_in,

    // Outputs to LBM solver & DDR respectively
    output reg          LBM_null_out, LBM_n_out,  LBM_ne_out, LBM_e_out,
                       LBM_se_out,   LBM_s_out,   LBM_sw_out, LBM_w_out,  LBM_nw_out,
    output reg          cache_null_out, cache_n_out,  cache_ne_out, cache_e_out,
                       cache_se_out,   cache_s_out,   cache_sw_out, cache_w_out, cache_nw_out
);

    // Combinational routing
    always @(*) begin
        // 1) set all outputs to safe defaults (zeros)
        null1_out      = 12'b0;  n1_out      = 12'b0;  ne1_out   = 12'b0;
        e1_out         = 12'b0;  se1_out     = 12'b0;  s1_out    = 12'b0;
        sw1_out        = 12'b0;  w1_out      = 12'b0;  nw1_out   = 12'b0;

        null1_wen      = 1'b0;   n1_wen       = 1'b0;   ne1_wen    = 1'b0;
        e1_wen         = 1'b0;   se1_wen      = 1'b0;   s1_wen     = 1'b0;
        sw1_wen        = 1'b0;   w1_wen       = 1'b0;   nw1_wen    = 1'b0;

        null1_data_in  = 1'b0;   n1_data_in   = 1'b0;   ne1_data_in= 1'b0;
        e1_data_in     = 1'b0;   se1_data_in  = 1'b0;   s1_data_in = 1'b0;
        sw1_data_in    = 1'b0;   w1_data_in   = 1'b0;   nw1_data_in= 1'b0;

        LBM_null_out   = 1'b0;   LBM_n_out    = 1'b0;   LBM_ne_out = 1'b0;
        LBM_e_out      = 1'b0;   LBM_se_out   = 1'b0;   LBM_s_out  = 1'b0;
        LBM_sw_out     = 1'b0;   LBM_w_out    = 1'b0;   LBM_nw_out = 1'b0;

        cache_null_out = 1'b0;   cache_n_out  = 1'b0;   cache_ne_out =1'b0;
        cache_e_out    = 1'b0;   cache_se_out = 1'b0;   cache_s_out =1'b0;
        cache_sw_out   = 1'b0;   cache_w_out  = 1'b0;   cache_nw_out=1'b0;

        // 2) if in DDR-to-BRAM transfer mode...
        if (chunk_transfer_ready) begin
            // all addrs point at DDR, all BRAM wren = 1
            null1_out = DDR_addr;   null1_wen = 1'b1;  null1_data_in = cache_null_in;  cache_null_out = null1_data_out;
            n1_out    = DDR_addr;   n1_wen    = 1'b1;  n1_data_in    = cache_n_in;     cache_n_out    = n1_data_out;
            ne1_out   = DDR_addr;   ne1_wen   = 1'b1;  ne1_data_in   = cache_ne_in;    cache_ne_out   = ne1_data_out;
            e1_out    = DDR_addr;   e1_wen    = 1'b1;  e1_data_in    = cache_e_in;     cache_e_out    = e1_data_out;
            se1_out   = DDR_addr;   se1_wen   = 1'b1;  se1_data_in   = cache_se_in;    cache_se_out   = se1_data_out;
            s1_out    = DDR_addr;   s1_wen    = 1'b1;  s1_data_in    = cache_s_in;     cache_s_out    = s1_data_out;
            sw1_out   = DDR_addr;   sw1_wen   = 1'b1;  sw1_data_in   = cache_sw_in;    cache_sw_out   = sw1_data_out;
            w1_out    = DDR_addr;   w1_wen    = 1'b1;  w1_data_in    = cache_w_in;     cache_w_out    = w1_data_out;
            nw1_out   = DDR_addr;   nw1_wen   = 1'b1;  nw1_data_in   = cache_nw_in;    cache_nw_out   = nw1_data_out;
        end
        // 3) else if in LBM-compute mode...
        else if (chunk_compute_ready) begin
            // route addresses & write enables into BRAM from LBM solver
            null1_out = null1;      null1_wen = LBM_null_w;  null1_data_in = LBM_null_in;  LBM_null_out = null1_data_out;
            n1_out    = n1;         n1_wen    = LBM_n_w;     n1_data_in    = LBM_n_in;     LBM_n_out    = n1_data_out;
            ne1_out   = ne1;        ne1_wen   = LBM_ne_w;    ne1_data_in   = LBM_ne_in;    LBM_ne_out   = ne1_data_out;
            e1_out    = e1;         e1_wen    = LBM_e_w;     e1_data_in    = LBM_e_in;     LBM_e_out    = e1_data_out;
            se1_out   = se1;        se1_wen   = LBM_se_w;    se1_data_in   = LBM_se_in;    LBM_se_out   = se1_data_out;
            s1_out    = s1;         s1_wen    = LBM_s_w;     s1_data_in    = LBM_s_in;     LBM_s_out    = s1_data_out;
            sw1_out   = sw1;        sw1_wen   = LBM_sw_w;    sw1_data_in   = LBM_sw_in;    LBM_sw_out   = sw1_data_out;
            w1_out    = w1;         w1_wen    = LBM_w_w;     w1_data_in    = LBM_w_in;     LBM_w_out    = w1_data_out;
            nw1_out   = nw1;        nw1_wen   = LBM_nw_w;    nw1_data_in   = LBM_nw_in;    LBM_nw_out   = nw1_data_out;
        end
        // 4) else, leave everything at 0
    end

endmodule
