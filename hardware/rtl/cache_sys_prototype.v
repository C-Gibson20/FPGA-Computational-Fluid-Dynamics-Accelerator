`include "def.vh"

module mmu(
    input wire clk,
    input wire rst, 
    input wire swap_block, // go high when block should be swapped
    input wire [`DATA_WIDTH-1:0] block_index,

    // also, this module should mux between LBMSolver and mmu to 
    // control ram

    ///////// BRAM i/o /////////////////////////////
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

    //////////////// LBMSolver BRAM Controls //////////////
    // BRAM c0
    output reg  [`ADDRESS_WIDTH-1:0]    solver_c0_addr,
    output reg  [`DATA_WIDTH-1:0]       solver_c0_data_in, 
    output reg                          solver_c0_write_en,
    input  wire [`DATA_WIDTH-1:0]       solver_c0_data_out,

    // BRAM c0_nsolver_
    output reg  [`ADDRESS_WIDTH-1:0]    solver_c0_n_addr,
    output reg  [`DATA_WIDTH-1:0]       solver_c0_n_data_in, 
    output reg                          solver_c0_n_write_en,
    input  wire [`DATA_WIDTH-1:0]       solver_c0_n_data_out,


    // BRAM cnsolver_
    output reg  [`ADDRESS_WIDTH-1:0]    solver_cn_addr,
    output reg  [`DATA_WIDTH-1:0]       solver_cn_data_in, 
    output reg                          solver_cn_write_en,
    input  wire [`DATA_WIDTH-1:0]       solver_cn_data_out,

    // BRAM cn_nsolver_
    output reg  [`ADDRESS_WIDTH-1:0]    solver_cn_n_addr,
    output reg  [`DATA_WIDTH-1:0]       solver_cn_n_data_in, 
    output reg                          solver_cn_n_write_en,
    input  wire [`DATA_WIDTH-1:0]       solver_cn_n_data_out,


    // BRAM cnesolver_
    output reg  [`ADDRESS_WIDTH-1:0]    solver_cne_addr,
    output reg  [`DATA_WIDTH-1:0]       solver_cne_data_in, 
    output reg                          solver_cne_write_en,
    input  wire [`DATA_WIDTH-1:0]       solver_cne_data_out,

    // BRAM cne_nsolver_
    output reg  [`ADDRESS_WIDTH-1:0]    solver_cne_n_addr,
    output reg  [`DATA_WIDTH-1:0]       solver_cne_n_data_in, 
    output reg                          solver_cne_n_write_en,
    input  wire [`DATA_WIDTH-1:0]       solver_cne_n_data_out,


    // BRAM cesolver_
    output reg  [`ADDRESS_WIDTH-1:0]    solver_ce_addr,
    output reg  [`DATA_WIDTH-1:0]       solver_ce_data_in, 
    output reg                          solver_ce_write_en,
    input  wire [`DATA_WIDTH-1:0]       solver_ce_data_out,

    // BRAM ce_nsolver_
    output reg  [`ADDRESS_WIDTH-1:0]    solver_ce_n_addr,
    output reg  [`DATA_WIDTH-1:0]       solver_ce_n_data_in, 
    output reg                          solver_ce_n_write_en,
    input  wire [`DATA_WIDTH-1:0]       solver_ce_n_data_out,


    // BRAM csesolver_
    output reg  [`ADDRESS_WIDTH-1:0]    solver_cse_addr,
    output reg  [`DATA_WIDTH-1:0]       solver_cse_data_in, 
    output reg                          solver_cse_write_en,
    input  wire [`DATA_WIDTH-1:0]       solver_cse_data_out,

    // BRAM cse_nsolver_
    output reg  [`ADDRESS_WIDTH-1:0]    solver_cse_n_addr,
    output reg  [`DATA_WIDTH-1:0]       solver_cse_n_data_in, 
    output reg                          solver_cse_n_write_en,
    input  wire [`DATA_WIDTH-1:0]       solver_cse_n_data_out,


    // BRAM cssolver_
    output reg  [`ADDRESS_WIDTH-1:0]    solver_cs_addr,
    output reg  [`DATA_WIDTH-1:0]       solver_cs_data_in, 
    output reg                          solver_cs_write_en,
    input  wire [`DATA_WIDTH-1:0]       solver_cs_data_out,

    // BRAM cs_nsolver_
    output reg  [`ADDRESS_WIDTH-1:0]    solver_cs_n_addr,
    output reg  [`DATA_WIDTH-1:0]       solver_cs_n_data_in, 
    output reg                          solver_cs_n_write_en,
    input  wire [`DATA_WIDTH-1:0]       solver_cs_n_data_out,


    // BRAM cswsolver_
    output reg  [`ADDRESS_WIDTH-1:0]    solver_csw_addr,
    output reg  [`DATA_WIDTH-1:0]       solver_csw_data_in, 
    output reg                          solver_csw_write_en,
    input  wire [`DATA_WIDTH-1:0]       solver_csw_data_out,

    // BRAM csw_nsolver_
    output reg  [`ADDRESS_WIDTH-1:0]    solver_csw_n_addr,
    output reg  [`DATA_WIDTH-1:0]       solver_csw_n_data_in, 
    output reg                          solver_csw_n_write_en,
    input  wire [`DATA_WIDTH-1:0]       solver_csw_n_data_out,


    // BRAM cwsolver_
    output reg  [`ADDRESS_WIDTH-1:0]    solver_cw_addr,
    output reg  [`DATA_WIDTH-1:0]       solver_cw_data_in, 
    output reg                          solver_cw_write_en,
    input  wire [`DATA_WIDTH-1:0]       solver_cw_data_out,

    // BRAM cw_nsolver_
    output reg  [`ADDRESS_WIDTH-1:0]    solver_cw_n_addr,
    output reg  [`DATA_WIDTH-1:0]       solver_cw_n_data_in, 
    output reg                          solver_cw_n_write_en,
    input  wire [`DATA_WIDTH-1:0]       solver_cw_n_data_out,


    // BRAM cnwsolver_
    output reg  [`ADDRESS_WIDTH-1:0]    solver_cnw_addr,
    output reg  [`DATA_WIDTH-1:0]       solver_cnw_data_in, 
    output reg                          solver_cnw_write_en,
    input  wire [`DATA_WIDTH-1:0]       solver_cnw_data_out,

    // BRAM cnw_nsolver_
    output reg  [`ADDRESS_WIDTH-1:0]    solver_cnw_n_addr,
    output reg  [`DATA_WIDTH-1:0]       solver_cnw_n_data_in, 
    output reg                          solver_cnw_n_write_en,
    input  wire [`DATA_WIDTH-1:0]       solver_cnw_n_data_out,
);
// 


endmodule