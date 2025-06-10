// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdut__Syms.h"


VL_ATTR_COLD void Vdut___024root__trace_init_sub__TOP__0(Vdut___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+611,"clk", false,-1);
    tracep->declBit(c+612,"rst", false,-1);
    tracep->declBit(c+613,"en", false,-1);
    tracep->declBus(c+614,"step", false,-1, 31,0);
    tracep->declBus(c+615,"barriers", false,-1, 24,0);
    tracep->declBus(c+616,"omega", false,-1, 15,0);
    tracep->declBus(c+617,"init_c0", false,-1, 15,0);
    tracep->declBus(c+618,"init_cn", false,-1, 15,0);
    tracep->declBus(c+619,"init_cne", false,-1, 15,0);
    tracep->declBus(c+620,"init_ce", false,-1, 15,0);
    tracep->declBus(c+621,"init_cse", false,-1, 15,0);
    tracep->declBus(c+622,"init_cs", false,-1, 15,0);
    tracep->declBus(c+623,"init_csw", false,-1, 15,0);
    tracep->declBus(c+624,"init_cw", false,-1, 15,0);
    tracep->declBus(c+625,"init_cnw", false,-1, 15,0);
    tracep->declBus(c+626,"testing_cs_n_data_in", false,-1, 15,0);
    tracep->declBus(c+627,"testing_c0_data_in", false,-1, 15,0);
    tracep->declBus(c+628,"u_x", false,-1, 15,0);
    tracep->declBus(c+629,"u_y", false,-1, 15,0);
    tracep->declBus(c+630,"rho", false,-1, 15,0);
    tracep->declBus(c+631,"u_squared", false,-1, 15,0);
    tracep->declBit(c+632,"collider_ready", false,-1);
    tracep->declBit(c+633,"in_collision_state", false,-1);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+611,"clk", false,-1);
    tracep->declBit(c+612,"rst", false,-1);
    tracep->declBit(c+613,"en", false,-1);
    tracep->declBus(c+614,"step", false,-1, 31,0);
    tracep->declBus(c+615,"barriers", false,-1, 24,0);
    tracep->declBus(c+616,"omega", false,-1, 15,0);
    tracep->declBus(c+617,"init_c0", false,-1, 15,0);
    tracep->declBus(c+618,"init_cn", false,-1, 15,0);
    tracep->declBus(c+619,"init_cne", false,-1, 15,0);
    tracep->declBus(c+620,"init_ce", false,-1, 15,0);
    tracep->declBus(c+621,"init_cse", false,-1, 15,0);
    tracep->declBus(c+622,"init_cs", false,-1, 15,0);
    tracep->declBus(c+623,"init_csw", false,-1, 15,0);
    tracep->declBus(c+624,"init_cw", false,-1, 15,0);
    tracep->declBus(c+625,"init_cnw", false,-1, 15,0);
    tracep->declBus(c+626,"testing_cs_n_data_in", false,-1, 15,0);
    tracep->declBus(c+627,"testing_c0_data_in", false,-1, 15,0);
    tracep->declBus(c+628,"u_x", false,-1, 15,0);
    tracep->declBus(c+629,"u_y", false,-1, 15,0);
    tracep->declBus(c+630,"rho", false,-1, 15,0);
    tracep->declBus(c+631,"u_squared", false,-1, 15,0);
    tracep->declBit(c+632,"collider_ready", false,-1);
    tracep->declBit(c+633,"in_collision_state", false,-1);
    tracep->declBus(c+507,"c0_addr", false,-1, 12,0);
    tracep->declBus(c+508,"c0_n_addr", false,-1, 12,0);
    tracep->declBus(c+509,"cn_addr", false,-1, 12,0);
    tracep->declBus(c+510,"cn_n_addr", false,-1, 12,0);
    tracep->declBus(c+511,"cne_addr", false,-1, 12,0);
    tracep->declBus(c+512,"cne_n_addr", false,-1, 12,0);
    tracep->declBus(c+513,"ce_addr", false,-1, 12,0);
    tracep->declBus(c+514,"ce_n_addr", false,-1, 12,0);
    tracep->declBus(c+515,"cse_addr", false,-1, 12,0);
    tracep->declBus(c+516,"cse_n_addr", false,-1, 12,0);
    tracep->declBus(c+517,"cs_addr", false,-1, 12,0);
    tracep->declBus(c+518,"cs_n_addr", false,-1, 12,0);
    tracep->declBus(c+519,"csw_addr", false,-1, 12,0);
    tracep->declBus(c+520,"csw_n_addr", false,-1, 12,0);
    tracep->declBus(c+521,"cw_addr", false,-1, 12,0);
    tracep->declBus(c+522,"cw_n_addr", false,-1, 12,0);
    tracep->declBus(c+523,"cnw_addr", false,-1, 12,0);
    tracep->declBus(c+524,"cnw_n_addr", false,-1, 12,0);
    tracep->declBus(c+525,"c0_data_in", false,-1, 15,0);
    tracep->declBus(c+526,"c0_n_data_in", false,-1, 15,0);
    tracep->declBus(c+527,"cn_data_in", false,-1, 15,0);
    tracep->declBus(c+528,"cn_n_data_in", false,-1, 15,0);
    tracep->declBus(c+529,"cne_data_in", false,-1, 15,0);
    tracep->declBus(c+530,"cne_n_data_in", false,-1, 15,0);
    tracep->declBus(c+531,"ce_data_in", false,-1, 15,0);
    tracep->declBus(c+532,"ce_n_data_in", false,-1, 15,0);
    tracep->declBus(c+533,"cse_data_in", false,-1, 15,0);
    tracep->declBus(c+534,"cse_n_data_in", false,-1, 15,0);
    tracep->declBus(c+535,"cs_data_in", false,-1, 15,0);
    tracep->declBus(c+536,"cs_n_data_in", false,-1, 15,0);
    tracep->declBus(c+537,"csw_data_in", false,-1, 15,0);
    tracep->declBus(c+538,"csw_n_data_in", false,-1, 15,0);
    tracep->declBus(c+539,"cw_data_in", false,-1, 15,0);
    tracep->declBus(c+540,"cw_n_data_in", false,-1, 15,0);
    tracep->declBus(c+541,"cnw_data_in", false,-1, 15,0);
    tracep->declBus(c+542,"cnw_n_data_in", false,-1, 15,0);
    tracep->declBus(c+5,"c0_data_out", false,-1, 15,0);
    tracep->declBus(c+6,"c0_n_data_out", false,-1, 15,0);
    tracep->declBus(c+7,"cn_data_out", false,-1, 15,0);
    tracep->declBus(c+8,"cn_n_data_out", false,-1, 15,0);
    tracep->declBus(c+9,"cne_data_out", false,-1, 15,0);
    tracep->declBus(c+10,"cne_n_data_out", false,-1, 15,0);
    tracep->declBus(c+11,"ce_data_out", false,-1, 15,0);
    tracep->declBus(c+12,"ce_n_data_out", false,-1, 15,0);
    tracep->declBus(c+13,"cse_data_out", false,-1, 15,0);
    tracep->declBus(c+14,"cse_n_data_out", false,-1, 15,0);
    tracep->declBus(c+15,"cs_data_out", false,-1, 15,0);
    tracep->declBus(c+16,"cs_n_data_out", false,-1, 15,0);
    tracep->declBus(c+17,"csw_data_out", false,-1, 15,0);
    tracep->declBus(c+18,"csw_n_data_out", false,-1, 15,0);
    tracep->declBus(c+19,"cw_data_out", false,-1, 15,0);
    tracep->declBus(c+20,"cw_n_data_out", false,-1, 15,0);
    tracep->declBus(c+21,"cnw_data_out", false,-1, 15,0);
    tracep->declBus(c+22,"cnw_n_data_out", false,-1, 15,0);
    tracep->declBit(c+543,"c0_write_en", false,-1);
    tracep->declBit(c+544,"c0_n_write_en", false,-1);
    tracep->declBit(c+545,"cn_write_en", false,-1);
    tracep->declBit(c+546,"cn_n_write_en", false,-1);
    tracep->declBit(c+547,"cne_write_en", false,-1);
    tracep->declBit(c+548,"cne_n_write_en", false,-1);
    tracep->declBit(c+549,"ce_write_en", false,-1);
    tracep->declBit(c+550,"ce_n_write_en", false,-1);
    tracep->declBit(c+551,"cse_write_en", false,-1);
    tracep->declBit(c+552,"cse_n_write_en", false,-1);
    tracep->declBit(c+553,"cs_write_en", false,-1);
    tracep->declBit(c+554,"cs_n_write_en", false,-1);
    tracep->declBit(c+555,"csw_write_en", false,-1);
    tracep->declBit(c+556,"csw_n_write_en", false,-1);
    tracep->declBit(c+557,"cw_write_en", false,-1);
    tracep->declBit(c+558,"cw_n_write_en", false,-1);
    tracep->declBit(c+559,"cnw_write_en", false,-1);
    tracep->declBit(c+560,"cnw_n_write_en", false,-1);
    tracep->pushNamePrefix("c0 ");
    tracep->declBus(c+684,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+685,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declArray(c+686,"INIT_FILE", false,-1, 87,0);
    tracep->declBit(c+611,"clk", false,-1);
    tracep->declBus(c+507,"addr", false,-1, 12,0);
    tracep->declBus(c+525,"data_in", false,-1, 15,0);
    tracep->declBit(c+543,"write_en", false,-1);
    tracep->declBus(c+5,"data_out", false,-1, 15,0);
    for (int i = 0; i < 25; ++i) {
        tracep->declBus(c+23+i*1,"mem", true,(i+0), 15,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("c0_n ");
    tracep->declBus(c+684,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+685,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declArray(c+686,"INIT_FILE", false,-1, 87,0);
    tracep->declBit(c+611,"clk", false,-1);
    tracep->declBus(c+508,"addr", false,-1, 12,0);
    tracep->declBus(c+526,"data_in", false,-1, 15,0);
    tracep->declBit(c+544,"write_en", false,-1);
    tracep->declBus(c+6,"data_out", false,-1, 15,0);
    for (int i = 0; i < 25; ++i) {
        tracep->declBus(c+48+i*1,"mem", true,(i+0), 15,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ce ");
    tracep->declBus(c+684,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+685,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declArray(c+689,"INIT_FILE", false,-1, 87,0);
    tracep->declBit(c+611,"clk", false,-1);
    tracep->declBus(c+513,"addr", false,-1, 12,0);
    tracep->declBus(c+531,"data_in", false,-1, 15,0);
    tracep->declBit(c+549,"write_en", false,-1);
    tracep->declBus(c+11,"data_out", false,-1, 15,0);
    for (int i = 0; i < 25; ++i) {
        tracep->declBus(c+73+i*1,"mem", true,(i+0), 15,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ce_n ");
    tracep->declBus(c+684,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+685,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declArray(c+689,"INIT_FILE", false,-1, 87,0);
    tracep->declBit(c+611,"clk", false,-1);
    tracep->declBus(c+514,"addr", false,-1, 12,0);
    tracep->declBus(c+532,"data_in", false,-1, 15,0);
    tracep->declBit(c+550,"write_en", false,-1);
    tracep->declBus(c+12,"data_out", false,-1, 15,0);
    for (int i = 0; i < 25; ++i) {
        tracep->declBus(c+98+i*1,"mem", true,(i+0), 15,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("cn ");
    tracep->declBus(c+684,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+685,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declArray(c+692,"INIT_FILE", false,-1, 87,0);
    tracep->declBit(c+611,"clk", false,-1);
    tracep->declBus(c+509,"addr", false,-1, 12,0);
    tracep->declBus(c+527,"data_in", false,-1, 15,0);
    tracep->declBit(c+545,"write_en", false,-1);
    tracep->declBus(c+7,"data_out", false,-1, 15,0);
    for (int i = 0; i < 25; ++i) {
        tracep->declBus(c+123+i*1,"mem", true,(i+0), 15,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("cn_n ");
    tracep->declBus(c+684,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+685,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declArray(c+692,"INIT_FILE", false,-1, 87,0);
    tracep->declBit(c+611,"clk", false,-1);
    tracep->declBus(c+510,"addr", false,-1, 12,0);
    tracep->declBus(c+528,"data_in", false,-1, 15,0);
    tracep->declBit(c+546,"write_en", false,-1);
    tracep->declBus(c+8,"data_out", false,-1, 15,0);
    for (int i = 0; i < 25; ++i) {
        tracep->declBus(c+148+i*1,"mem", true,(i+0), 15,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("cne ");
    tracep->declBus(c+684,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+685,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declArray(c+695,"INIT_FILE", false,-1, 87,0);
    tracep->declBit(c+611,"clk", false,-1);
    tracep->declBus(c+511,"addr", false,-1, 12,0);
    tracep->declBus(c+529,"data_in", false,-1, 15,0);
    tracep->declBit(c+547,"write_en", false,-1);
    tracep->declBus(c+9,"data_out", false,-1, 15,0);
    for (int i = 0; i < 25; ++i) {
        tracep->declBus(c+173+i*1,"mem", true,(i+0), 15,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("cne_n ");
    tracep->declBus(c+684,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+685,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declArray(c+695,"INIT_FILE", false,-1, 87,0);
    tracep->declBit(c+611,"clk", false,-1);
    tracep->declBus(c+512,"addr", false,-1, 12,0);
    tracep->declBus(c+530,"data_in", false,-1, 15,0);
    tracep->declBit(c+548,"write_en", false,-1);
    tracep->declBus(c+10,"data_out", false,-1, 15,0);
    for (int i = 0; i < 25; ++i) {
        tracep->declBus(c+198+i*1,"mem", true,(i+0), 15,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("cnw ");
    tracep->declBus(c+684,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+685,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declArray(c+698,"INIT_FILE", false,-1, 87,0);
    tracep->declBit(c+611,"clk", false,-1);
    tracep->declBus(c+523,"addr", false,-1, 12,0);
    tracep->declBus(c+541,"data_in", false,-1, 15,0);
    tracep->declBit(c+559,"write_en", false,-1);
    tracep->declBus(c+21,"data_out", false,-1, 15,0);
    for (int i = 0; i < 25; ++i) {
        tracep->declBus(c+223+i*1,"mem", true,(i+0), 15,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("cnw_n ");
    tracep->declBus(c+684,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+685,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declArray(c+698,"INIT_FILE", false,-1, 87,0);
    tracep->declBit(c+611,"clk", false,-1);
    tracep->declBus(c+524,"addr", false,-1, 12,0);
    tracep->declBus(c+542,"data_in", false,-1, 15,0);
    tracep->declBit(c+560,"write_en", false,-1);
    tracep->declBus(c+22,"data_out", false,-1, 15,0);
    for (int i = 0; i < 25; ++i) {
        tracep->declBus(c+248+i*1,"mem", true,(i+0), 15,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("cs ");
    tracep->declBus(c+684,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+685,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declArray(c+692,"INIT_FILE", false,-1, 87,0);
    tracep->declBit(c+611,"clk", false,-1);
    tracep->declBus(c+517,"addr", false,-1, 12,0);
    tracep->declBus(c+535,"data_in", false,-1, 15,0);
    tracep->declBit(c+553,"write_en", false,-1);
    tracep->declBus(c+15,"data_out", false,-1, 15,0);
    for (int i = 0; i < 25; ++i) {
        tracep->declBus(c+273+i*1,"mem", true,(i+0), 15,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("cs_n ");
    tracep->declBus(c+684,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+685,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declArray(c+692,"INIT_FILE", false,-1, 87,0);
    tracep->declBit(c+611,"clk", false,-1);
    tracep->declBus(c+518,"addr", false,-1, 12,0);
    tracep->declBus(c+536,"data_in", false,-1, 15,0);
    tracep->declBit(c+554,"write_en", false,-1);
    tracep->declBus(c+16,"data_out", false,-1, 15,0);
    for (int i = 0; i < 25; ++i) {
        tracep->declBus(c+298+i*1,"mem", true,(i+0), 15,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("cse ");
    tracep->declBus(c+684,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+685,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declArray(c+695,"INIT_FILE", false,-1, 87,0);
    tracep->declBit(c+611,"clk", false,-1);
    tracep->declBus(c+515,"addr", false,-1, 12,0);
    tracep->declBus(c+533,"data_in", false,-1, 15,0);
    tracep->declBit(c+551,"write_en", false,-1);
    tracep->declBus(c+13,"data_out", false,-1, 15,0);
    for (int i = 0; i < 25; ++i) {
        tracep->declBus(c+323+i*1,"mem", true,(i+0), 15,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("cse_n ");
    tracep->declBus(c+684,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+685,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declArray(c+695,"INIT_FILE", false,-1, 87,0);
    tracep->declBit(c+611,"clk", false,-1);
    tracep->declBus(c+516,"addr", false,-1, 12,0);
    tracep->declBus(c+534,"data_in", false,-1, 15,0);
    tracep->declBit(c+552,"write_en", false,-1);
    tracep->declBus(c+14,"data_out", false,-1, 15,0);
    for (int i = 0; i < 25; ++i) {
        tracep->declBus(c+348+i*1,"mem", true,(i+0), 15,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("csw ");
    tracep->declBus(c+684,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+685,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declArray(c+698,"INIT_FILE", false,-1, 87,0);
    tracep->declBit(c+611,"clk", false,-1);
    tracep->declBus(c+519,"addr", false,-1, 12,0);
    tracep->declBus(c+537,"data_in", false,-1, 15,0);
    tracep->declBit(c+555,"write_en", false,-1);
    tracep->declBus(c+17,"data_out", false,-1, 15,0);
    for (int i = 0; i < 25; ++i) {
        tracep->declBus(c+373+i*1,"mem", true,(i+0), 15,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("csw_n ");
    tracep->declBus(c+684,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+685,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declArray(c+698,"INIT_FILE", false,-1, 87,0);
    tracep->declBit(c+611,"clk", false,-1);
    tracep->declBus(c+520,"addr", false,-1, 12,0);
    tracep->declBus(c+538,"data_in", false,-1, 15,0);
    tracep->declBit(c+556,"write_en", false,-1);
    tracep->declBus(c+18,"data_out", false,-1, 15,0);
    for (int i = 0; i < 25; ++i) {
        tracep->declBus(c+398+i*1,"mem", true,(i+0), 15,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("cw ");
    tracep->declBus(c+684,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+685,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declArray(c+701,"INIT_FILE", false,-1, 87,0);
    tracep->declBit(c+611,"clk", false,-1);
    tracep->declBus(c+521,"addr", false,-1, 12,0);
    tracep->declBus(c+539,"data_in", false,-1, 15,0);
    tracep->declBit(c+557,"write_en", false,-1);
    tracep->declBus(c+19,"data_out", false,-1, 15,0);
    for (int i = 0; i < 25; ++i) {
        tracep->declBus(c+423+i*1,"mem", true,(i+0), 15,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("cw_n ");
    tracep->declBus(c+684,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+685,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declArray(c+701,"INIT_FILE", false,-1, 87,0);
    tracep->declBit(c+611,"clk", false,-1);
    tracep->declBus(c+522,"addr", false,-1, 12,0);
    tracep->declBus(c+540,"data_in", false,-1, 15,0);
    tracep->declBit(c+558,"write_en", false,-1);
    tracep->declBus(c+20,"data_out", false,-1, 15,0);
    for (int i = 0; i < 25; ++i) {
        tracep->declBus(c+448+i*1,"mem", true,(i+0), 15,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("lbm ");
    tracep->declBit(c+611,"clk", false,-1);
    tracep->declBit(c+612,"rst", false,-1);
    tracep->declBus(c+615,"barriers", false,-1, 24,0);
    tracep->declBit(c+613,"en", false,-1);
    tracep->declBus(c+634,"step", false,-1, 15,0);
    tracep->declBus(c+616,"omega", false,-1, 15,0);
    tracep->declBus(c+626,"testing_cs_n_data_in", false,-1, 15,0);
    tracep->declBus(c+507,"c0_addr", false,-1, 12,0);
    tracep->declBus(c+525,"c0_data_in", false,-1, 15,0);
    tracep->declBit(c+543,"c0_write_en", false,-1);
    tracep->declBus(c+5,"c0_data_out", false,-1, 15,0);
    tracep->declBus(c+508,"c0_n_addr", false,-1, 12,0);
    tracep->declBus(c+526,"c0_n_data_in", false,-1, 15,0);
    tracep->declBit(c+544,"c0_n_write_en", false,-1);
    tracep->declBus(c+6,"c0_n_data_out", false,-1, 15,0);
    tracep->declBus(c+509,"cn_addr", false,-1, 12,0);
    tracep->declBus(c+527,"cn_data_in", false,-1, 15,0);
    tracep->declBit(c+545,"cn_write_en", false,-1);
    tracep->declBus(c+7,"cn_data_out", false,-1, 15,0);
    tracep->declBus(c+510,"cn_n_addr", false,-1, 12,0);
    tracep->declBus(c+528,"cn_n_data_in", false,-1, 15,0);
    tracep->declBit(c+546,"cn_n_write_en", false,-1);
    tracep->declBus(c+8,"cn_n_data_out", false,-1, 15,0);
    tracep->declBus(c+511,"cne_addr", false,-1, 12,0);
    tracep->declBus(c+529,"cne_data_in", false,-1, 15,0);
    tracep->declBit(c+547,"cne_write_en", false,-1);
    tracep->declBus(c+9,"cne_data_out", false,-1, 15,0);
    tracep->declBus(c+512,"cne_n_addr", false,-1, 12,0);
    tracep->declBus(c+530,"cne_n_data_in", false,-1, 15,0);
    tracep->declBit(c+548,"cne_n_write_en", false,-1);
    tracep->declBus(c+10,"cne_n_data_out", false,-1, 15,0);
    tracep->declBus(c+513,"ce_addr", false,-1, 12,0);
    tracep->declBus(c+531,"ce_data_in", false,-1, 15,0);
    tracep->declBit(c+549,"ce_write_en", false,-1);
    tracep->declBus(c+11,"ce_data_out", false,-1, 15,0);
    tracep->declBus(c+514,"ce_n_addr", false,-1, 12,0);
    tracep->declBus(c+532,"ce_n_data_in", false,-1, 15,0);
    tracep->declBit(c+550,"ce_n_write_en", false,-1);
    tracep->declBus(c+12,"ce_n_data_out", false,-1, 15,0);
    tracep->declBus(c+515,"cse_addr", false,-1, 12,0);
    tracep->declBus(c+533,"cse_data_in", false,-1, 15,0);
    tracep->declBit(c+551,"cse_write_en", false,-1);
    tracep->declBus(c+13,"cse_data_out", false,-1, 15,0);
    tracep->declBus(c+516,"cse_n_addr", false,-1, 12,0);
    tracep->declBus(c+534,"cse_n_data_in", false,-1, 15,0);
    tracep->declBit(c+552,"cse_n_write_en", false,-1);
    tracep->declBus(c+14,"cse_n_data_out", false,-1, 15,0);
    tracep->declBus(c+517,"cs_addr", false,-1, 12,0);
    tracep->declBus(c+535,"cs_data_in", false,-1, 15,0);
    tracep->declBit(c+553,"cs_write_en", false,-1);
    tracep->declBus(c+15,"cs_data_out", false,-1, 15,0);
    tracep->declBus(c+518,"cs_n_addr", false,-1, 12,0);
    tracep->declBus(c+536,"cs_n_data_in", false,-1, 15,0);
    tracep->declBit(c+554,"cs_n_write_en", false,-1);
    tracep->declBus(c+16,"cs_n_data_out", false,-1, 15,0);
    tracep->declBus(c+519,"csw_addr", false,-1, 12,0);
    tracep->declBus(c+537,"csw_data_in", false,-1, 15,0);
    tracep->declBit(c+555,"csw_write_en", false,-1);
    tracep->declBus(c+17,"csw_data_out", false,-1, 15,0);
    tracep->declBus(c+520,"csw_n_addr", false,-1, 12,0);
    tracep->declBus(c+538,"csw_n_data_in", false,-1, 15,0);
    tracep->declBit(c+556,"csw_n_write_en", false,-1);
    tracep->declBus(c+18,"csw_n_data_out", false,-1, 15,0);
    tracep->declBus(c+521,"cw_addr", false,-1, 12,0);
    tracep->declBus(c+539,"cw_data_in", false,-1, 15,0);
    tracep->declBit(c+557,"cw_write_en", false,-1);
    tracep->declBus(c+19,"cw_data_out", false,-1, 15,0);
    tracep->declBus(c+522,"cw_n_addr", false,-1, 12,0);
    tracep->declBus(c+540,"cw_n_data_in", false,-1, 15,0);
    tracep->declBit(c+558,"cw_n_write_en", false,-1);
    tracep->declBus(c+20,"cw_n_data_out", false,-1, 15,0);
    tracep->declBus(c+523,"cnw_addr", false,-1, 12,0);
    tracep->declBus(c+541,"cnw_data_in", false,-1, 15,0);
    tracep->declBit(c+559,"cnw_write_en", false,-1);
    tracep->declBus(c+21,"cnw_data_out", false,-1, 15,0);
    tracep->declBus(c+524,"cnw_n_addr", false,-1, 12,0);
    tracep->declBus(c+542,"cnw_n_data_in", false,-1, 15,0);
    tracep->declBit(c+560,"cnw_n_write_en", false,-1);
    tracep->declBus(c+22,"cnw_n_data_out", false,-1, 15,0);
    tracep->declBus(c+617,"init_c0", false,-1, 15,0);
    tracep->declBus(c+618,"init_cn", false,-1, 15,0);
    tracep->declBus(c+619,"init_cne", false,-1, 15,0);
    tracep->declBus(c+620,"init_ce", false,-1, 15,0);
    tracep->declBus(c+621,"init_cse", false,-1, 15,0);
    tracep->declBus(c+622,"init_cs", false,-1, 15,0);
    tracep->declBus(c+623,"init_csw", false,-1, 15,0);
    tracep->declBus(c+624,"init_cw", false,-1, 15,0);
    tracep->declBus(c+625,"init_cnw", false,-1, 15,0);
    tracep->declBus(c+628,"u_x", false,-1, 15,0);
    tracep->declBus(c+629,"u_y", false,-1, 15,0);
    tracep->declBus(c+630,"rho", false,-1, 15,0);
    tracep->declBus(c+631,"u_squared", false,-1, 15,0);
    tracep->declBit(c+632,"collider_ready", false,-1);
    tracep->declBit(c+633,"in_collision_state", false,-1);
    tracep->declBus(c+1,"step_countn", false,-1, 15,0);
    tracep->declBus(c+704,"IDLE", false,-1, 3,0);
    tracep->declBus(c+705,"STREAM", false,-1, 3,0);
    tracep->declBus(c+706,"STREAM_WAIT", false,-1, 3,0);
    tracep->declBus(c+707,"BOUNDARY", false,-1, 3,0);
    tracep->declBus(c+708,"BOUNDARY_WAIT", false,-1, 3,0);
    tracep->declBus(c+709,"BOUNCE", false,-1, 3,0);
    tracep->declBus(c+710,"BOUNCE_WAIT", false,-1, 3,0);
    tracep->declBus(c+711,"ZERO_BOUNCE", false,-1, 3,0);
    tracep->declBus(c+712,"COLLIDE", false,-1, 3,0);
    tracep->declBus(c+713,"MEM_RESET", false,-1, 3,0);
    tracep->declBus(c+2,"width_count", false,-1, 15,0);
    tracep->declBus(c+572,"next_width_count", false,-1, 15,0);
    tracep->declBus(c+3,"sim_state", false,-1, 3,0);
    tracep->declBus(c+573,"next_sim_state", false,-1, 3,0);
    tracep->declBus(c+561,"index", false,-1, 12,0);
    tracep->declBus(c+574,"next_index", false,-1, 12,0);
    tracep->declBit(c+714,"c_busy", false,-1);
    tracep->declBit(c+715,"nv_ready", false,-1);
    tracep->declBit(c+715,"v_d_ready", false,-1);
    tracep->declBus(c+575,"c0_next_data_in", false,-1, 15,0);
    tracep->declBit(c+562,"c0_next_write_en", false,-1);
    tracep->declBit(c+576,"c0_n_next_write_en", false,-1);
    tracep->declBus(c+577,"c0_next_write_addr", false,-1, 12,0);
    tracep->declBus(c+578,"cn_next_data_in", false,-1, 15,0);
    tracep->declBit(c+563,"cn_next_write_en", false,-1);
    tracep->declBit(c+579,"cn_n_next_write_en", false,-1);
    tracep->declBus(c+580,"cn_next_write_addr", false,-1, 12,0);
    tracep->declBus(c+581,"cne_next_data_in", false,-1, 15,0);
    tracep->declBit(c+564,"cne_next_write_en", false,-1);
    tracep->declBit(c+582,"cne_n_next_write_en", false,-1);
    tracep->declBus(c+583,"cne_next_write_addr", false,-1, 12,0);
    tracep->declBus(c+584,"ce_next_data_in", false,-1, 15,0);
    tracep->declBit(c+565,"ce_next_write_en", false,-1);
    tracep->declBit(c+585,"ce_n_next_write_en", false,-1);
    tracep->declBus(c+586,"ce_next_write_addr", false,-1, 12,0);
    tracep->declBus(c+587,"cse_next_data_in", false,-1, 15,0);
    tracep->declBit(c+566,"cse_next_write_en", false,-1);
    tracep->declBit(c+588,"cse_n_next_write_en", false,-1);
    tracep->declBus(c+589,"cse_next_write_addr", false,-1, 12,0);
    tracep->declBus(c+590,"cs_next_data_in", false,-1, 15,0);
    tracep->declBit(c+567,"cs_next_write_en", false,-1);
    tracep->declBit(c+591,"cs_n_next_write_en", false,-1);
    tracep->declBus(c+592,"cs_next_write_addr", false,-1, 12,0);
    tracep->declBus(c+593,"csw_next_data_in", false,-1, 15,0);
    tracep->declBit(c+568,"csw_next_write_en", false,-1);
    tracep->declBit(c+594,"csw_n_next_write_en", false,-1);
    tracep->declBus(c+595,"csw_next_write_addr", false,-1, 12,0);
    tracep->declBus(c+596,"cw_next_data_in", false,-1, 15,0);
    tracep->declBit(c+569,"cw_next_write_en", false,-1);
    tracep->declBit(c+597,"cw_n_next_write_en", false,-1);
    tracep->declBus(c+598,"cw_next_write_addr", false,-1, 12,0);
    tracep->declBus(c+599,"cnw_next_data_in", false,-1, 15,0);
    tracep->declBit(c+570,"cnw_next_write_en", false,-1);
    tracep->declBit(c+600,"cnw_n_next_write_en", false,-1);
    tracep->declBus(c+601,"cnw_next_write_addr", false,-1, 12,0);
    tracep->declBus(c+4,"ram_wait_count", false,-1, 2,0);
    tracep->declBus(c+602,"next_ram_wait_count", false,-1, 2,0);
    tracep->declBus(c+1,"step_count", false,-1, 15,0);
    tracep->declBit(c+571,"incr_step", false,-1);
    tracep->declBus(c+635,"c_c0", false,-1, 15,0);
    tracep->declBus(c+603,"c_cn", false,-1, 15,0);
    tracep->declBus(c+604,"c_cne", false,-1, 15,0);
    tracep->declBus(c+605,"c_ce", false,-1, 15,0);
    tracep->declBus(c+606,"c_cse", false,-1, 15,0);
    tracep->declBus(c+607,"c_cs", false,-1, 15,0);
    tracep->declBus(c+608,"c_csw", false,-1, 15,0);
    tracep->declBus(c+609,"c_cw", false,-1, 15,0);
    tracep->declBus(c+610,"c_cnw", false,-1, 15,0);
    tracep->pushNamePrefix("collider ");
    tracep->declBus(c+616,"omega", false,-1, 15,0);
    tracep->declBus(c+6,"f_null", false,-1, 15,0);
    tracep->declBus(c+8,"f_n", false,-1, 15,0);
    tracep->declBus(c+10,"f_ne", false,-1, 15,0);
    tracep->declBus(c+12,"f_e", false,-1, 15,0);
    tracep->declBus(c+14,"f_se", false,-1, 15,0);
    tracep->declBus(c+16,"f_s", false,-1, 15,0);
    tracep->declBus(c+18,"f_sw", false,-1, 15,0);
    tracep->declBus(c+20,"f_w", false,-1, 15,0);
    tracep->declBus(c+22,"f_nw", false,-1, 15,0);
    tracep->declBus(c+635,"f_new_null", false,-1, 15,0);
    tracep->declBus(c+603,"f_new_n", false,-1, 15,0);
    tracep->declBus(c+604,"f_new_ne", false,-1, 15,0);
    tracep->declBus(c+605,"f_new_e", false,-1, 15,0);
    tracep->declBus(c+606,"f_new_se", false,-1, 15,0);
    tracep->declBus(c+607,"f_new_s", false,-1, 15,0);
    tracep->declBus(c+608,"f_new_sw", false,-1, 15,0);
    tracep->declBus(c+609,"f_new_w", false,-1, 15,0);
    tracep->declBus(c+610,"f_new_nw", false,-1, 15,0);
    tracep->declBit(c+714,"collider_busy", false,-1);
    tracep->declBit(c+715,"newval_ready", false,-1);
    tracep->declBit(c+715,"axi_ready", false,-1);
    tracep->declBus(c+628,"u_x", false,-1, 15,0);
    tracep->declBus(c+629,"u_y", false,-1, 15,0);
    tracep->declBus(c+630,"rho", false,-1, 15,0);
    tracep->declBus(c+631,"u_squared", false,-1, 15,0);
    tracep->declBus(c+716,"w_null", false,-1, 15,0);
    tracep->declBus(c+717,"w_side", false,-1, 15,0);
    tracep->declBus(c+718,"w_diag", false,-1, 15,0);
    tracep->declBus(c+719,"one", false,-1, 15,0);
    tracep->declBus(c+720,"two", false,-1, 15,0);
    tracep->declBus(c+721,"three", false,-1, 15,0);
    tracep->declBus(c+722,"three_halves", false,-1, 15,0);
    tracep->declBus(c+723,"nine_quarters", false,-1, 15,0);
    tracep->declBus(c+473,"rho_ux", false,-1, 15,0);
    tracep->declBus(c+474,"rho_uy", false,-1, 15,0);
    tracep->declBus(c+636,"rho_x1", false,-1, 31,0);
    tracep->declBus(c+475,"x2", false,-1, 31,0);
    tracep->declBus(c+637,"rho_x2", false,-1, 31,0);
    tracep->declBus(c+476,"x3", false,-1, 31,0);
    tracep->declBus(c+477,"u_x_intermediate", false,-1, 31,0);
    tracep->declBus(c+478,"u_y_intermediate", false,-1, 31,0);
    tracep->declBus(c+479,"u_x_squared_intermediate", false,-1, 31,0);
    tracep->declBus(c+480,"u_y_squared_intermediate", false,-1, 31,0);
    tracep->declBus(c+481,"u_x_squared", false,-1, 15,0);
    tracep->declBus(c+482,"u_y_squared", false,-1, 15,0);
    tracep->declBus(c+638,"three_halves_u_squared_intermediate", false,-1, 31,0);
    tracep->declBus(c+639,"three_halves_u_squared", false,-1, 15,0);
    tracep->declBus(c+640,"three_u_x_intermediate", false,-1, 31,0);
    tracep->declBus(c+641,"three_u_y_intermediate", false,-1, 31,0);
    tracep->declBus(c+642,"three_u_x", false,-1, 15,0);
    tracep->declBus(c+643,"three_u_y", false,-1, 15,0);
    tracep->declBus(c+483,"nine_half_u_x_squared_intermediate", false,-1, 31,0);
    tracep->declBus(c+484,"nine_half_u_y_squared_intermediate", false,-1, 31,0);
    tracep->declBus(c+485,"nine_half_u_x_squared", false,-1, 15,0);
    tracep->declBus(c+486,"nine_half_u_y_squared", false,-1, 15,0);
    tracep->declBus(c+644,"polynomial_n", false,-1, 15,0);
    tracep->declBus(c+645,"polynomial_s", false,-1, 15,0);
    tracep->declBus(c+646,"polynomial_e", false,-1, 15,0);
    tracep->declBus(c+647,"polynomial_w", false,-1, 15,0);
    tracep->declBus(c+648,"f_eq_n_intermediate", false,-1, 31,0);
    tracep->declBus(c+649,"f_eq_s_intermediate", false,-1, 31,0);
    tracep->declBus(c+650,"f_eq_e_intermediate", false,-1, 31,0);
    tracep->declBus(c+651,"f_eq_w_intermediate", false,-1, 31,0);
    tracep->declBus(c+652,"f_eq_n_intermediate_2", false,-1, 31,0);
    tracep->declBus(c+653,"f_eq_s_intermediate_2", false,-1, 31,0);
    tracep->declBus(c+654,"f_eq_e_intermediate_2", false,-1, 31,0);
    tracep->declBus(c+655,"f_eq_w_intermediate_2", false,-1, 31,0);
    tracep->declBus(c+656,"f_eq_n", false,-1, 15,0);
    tracep->declBus(c+657,"f_eq_s", false,-1, 15,0);
    tracep->declBus(c+658,"f_eq_e", false,-1, 15,0);
    tracep->declBus(c+659,"f_eq_w", false,-1, 15,0);
    tracep->declBus(c+487,"x_plus_y", false,-1, 15,0);
    tracep->declBus(c+488,"x_minus_y", false,-1, 15,0);
    tracep->declBus(c+489,"neg_x_plus_y", false,-1, 15,0);
    tracep->declBus(c+490,"neg_x_minus_y", false,-1, 15,0);
    tracep->declBus(c+491,"x_plus_y_squared_intermediate", false,-1, 31,0);
    tracep->declBus(c+492,"x_plus_y_squared", false,-1, 15,0);
    tracep->declBus(c+493,"x_minus_y_squared_intermediate", false,-1, 31,0);
    tracep->declBus(c+494,"x_minus_y_squared", false,-1, 15,0);
    tracep->declBus(c+495,"three_x_plus_y_intermediate", false,-1, 31,0);
    tracep->declBus(c+496,"three_x_plus_y", false,-1, 15,0);
    tracep->declBus(c+497,"three_neg_x_plus_y_intermediate", false,-1, 31,0);
    tracep->declBus(c+498,"three_neg_x_plus_y", false,-1, 15,0);
    tracep->declBus(c+499,"three_x_minus_y_intermediate", false,-1, 31,0);
    tracep->declBus(c+500,"three_x_minus_y", false,-1, 15,0);
    tracep->declBus(c+501,"three_neg_x_minus_y_intermediate", false,-1, 31,0);
    tracep->declBus(c+502,"three_neg_x_minus_y", false,-1, 15,0);
    tracep->declBus(c+503,"nine_half_x_plus_y_squared_intermediate", false,-1, 31,0);
    tracep->declBus(c+504,"nine_half_x_plus_y_squared", false,-1, 15,0);
    tracep->declBus(c+505,"nine_half_x_minus_y_squared_intermediate", false,-1, 31,0);
    tracep->declBus(c+506,"nine_half_x_minus_y_squared", false,-1, 15,0);
    tracep->declBus(c+660,"polynomial_ne", false,-1, 15,0);
    tracep->declBus(c+661,"polynomial_sw", false,-1, 15,0);
    tracep->declBus(c+662,"polynomial_nw", false,-1, 15,0);
    tracep->declBus(c+663,"polynomial_se", false,-1, 15,0);
    tracep->declBus(c+664,"f_eq_ne_intermediate", false,-1, 31,0);
    tracep->declBus(c+665,"f_eq_sw_intermediate", false,-1, 31,0);
    tracep->declBus(c+666,"f_eq_nw_intermediate", false,-1, 31,0);
    tracep->declBus(c+667,"f_eq_se_intermediate", false,-1, 31,0);
    tracep->declBus(c+668,"f_eq_ne_intermediate_2", false,-1, 31,0);
    tracep->declBus(c+669,"f_eq_sw_intermediate_2", false,-1, 31,0);
    tracep->declBus(c+670,"f_eq_nw_intermediate_2", false,-1, 31,0);
    tracep->declBus(c+671,"f_eq_se_intermediate_2", false,-1, 31,0);
    tracep->declBus(c+672,"f_eq_ne", false,-1, 15,0);
    tracep->declBus(c+673,"f_eq_sw", false,-1, 15,0);
    tracep->declBus(c+674,"f_eq_nw", false,-1, 15,0);
    tracep->declBus(c+675,"f_eq_se", false,-1, 15,0);
    tracep->declBus(c+676,"delta_f_n", false,-1, 31,0);
    tracep->declBus(c+677,"delta_f_ne", false,-1, 31,0);
    tracep->declBus(c+678,"delta_f_e", false,-1, 31,0);
    tracep->declBus(c+679,"delta_f_se", false,-1, 31,0);
    tracep->declBus(c+680,"delta_f_s", false,-1, 31,0);
    tracep->declBus(c+681,"delta_f_sw", false,-1, 31,0);
    tracep->declBus(c+682,"delta_f_w", false,-1, 31,0);
    tracep->declBus(c+683,"delta_f_nw", false,-1, 31,0);
    tracep->popNamePrefix(3);
}

VL_ATTR_COLD void Vdut___024root__trace_init_top(Vdut___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_init_top\n"); );
    // Body
    Vdut___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vdut___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vdut___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vdut___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vdut___024root__trace_register(Vdut___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vdut___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vdut___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vdut___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vdut___024root__trace_full_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vdut___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_full_top_0\n"); );
    // Init
    Vdut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdut___024root*>(voidSelf);
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vdut___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vdut___024root__trace_full_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    VlWide<3>/*95:0*/ __Vtemp_h02def8a8__0;
    VlWide<3>/*95:0*/ __Vtemp_hc5db363f__0;
    VlWide<3>/*95:0*/ __Vtemp_hb3450750__0;
    VlWide<3>/*95:0*/ __Vtemp_h5781e13f__0;
    VlWide<3>/*95:0*/ __Vtemp_h02cdee20__0;
    VlWide<3>/*95:0*/ __Vtemp_h63d4f183__0;
    // Body
    bufp->fullSData(oldp+1,(vlSelf->top__DOT__lbm__DOT__step_count),16);
    bufp->fullSData(oldp+2,(vlSelf->top__DOT__lbm__DOT__width_count),16);
    bufp->fullCData(oldp+3,(vlSelf->top__DOT__lbm__DOT__sim_state),4);
    bufp->fullCData(oldp+4,(vlSelf->top__DOT__lbm__DOT__ram_wait_count),3);
    bufp->fullSData(oldp+5,(vlSelf->top__DOT__c0_data_out),16);
    bufp->fullSData(oldp+6,(vlSelf->top__DOT__c0_n_data_out),16);
    bufp->fullSData(oldp+7,(vlSelf->top__DOT__cn_data_out),16);
    bufp->fullSData(oldp+8,(vlSelf->top__DOT__cn_n_data_out),16);
    bufp->fullSData(oldp+9,(vlSelf->top__DOT__cne_data_out),16);
    bufp->fullSData(oldp+10,(vlSelf->top__DOT__cne_n_data_out),16);
    bufp->fullSData(oldp+11,(vlSelf->top__DOT__ce_data_out),16);
    bufp->fullSData(oldp+12,(vlSelf->top__DOT__ce_n_data_out),16);
    bufp->fullSData(oldp+13,(vlSelf->top__DOT__cse_data_out),16);
    bufp->fullSData(oldp+14,(vlSelf->top__DOT__cse_n_data_out),16);
    bufp->fullSData(oldp+15,(vlSelf->top__DOT__cs_data_out),16);
    bufp->fullSData(oldp+16,(vlSelf->top__DOT__cs_n_data_out),16);
    bufp->fullSData(oldp+17,(vlSelf->top__DOT__csw_data_out),16);
    bufp->fullSData(oldp+18,(vlSelf->top__DOT__csw_n_data_out),16);
    bufp->fullSData(oldp+19,(vlSelf->top__DOT__cw_data_out),16);
    bufp->fullSData(oldp+20,(vlSelf->top__DOT__cw_n_data_out),16);
    bufp->fullSData(oldp+21,(vlSelf->top__DOT__cnw_data_out),16);
    bufp->fullSData(oldp+22,(vlSelf->top__DOT__cnw_n_data_out),16);
    bufp->fullSData(oldp+23,(vlSelf->top__DOT__c0__DOT__mem[0]),16);
    bufp->fullSData(oldp+24,(vlSelf->top__DOT__c0__DOT__mem[1]),16);
    bufp->fullSData(oldp+25,(vlSelf->top__DOT__c0__DOT__mem[2]),16);
    bufp->fullSData(oldp+26,(vlSelf->top__DOT__c0__DOT__mem[3]),16);
    bufp->fullSData(oldp+27,(vlSelf->top__DOT__c0__DOT__mem[4]),16);
    bufp->fullSData(oldp+28,(vlSelf->top__DOT__c0__DOT__mem[5]),16);
    bufp->fullSData(oldp+29,(vlSelf->top__DOT__c0__DOT__mem[6]),16);
    bufp->fullSData(oldp+30,(vlSelf->top__DOT__c0__DOT__mem[7]),16);
    bufp->fullSData(oldp+31,(vlSelf->top__DOT__c0__DOT__mem[8]),16);
    bufp->fullSData(oldp+32,(vlSelf->top__DOT__c0__DOT__mem[9]),16);
    bufp->fullSData(oldp+33,(vlSelf->top__DOT__c0__DOT__mem[10]),16);
    bufp->fullSData(oldp+34,(vlSelf->top__DOT__c0__DOT__mem[11]),16);
    bufp->fullSData(oldp+35,(vlSelf->top__DOT__c0__DOT__mem[12]),16);
    bufp->fullSData(oldp+36,(vlSelf->top__DOT__c0__DOT__mem[13]),16);
    bufp->fullSData(oldp+37,(vlSelf->top__DOT__c0__DOT__mem[14]),16);
    bufp->fullSData(oldp+38,(vlSelf->top__DOT__c0__DOT__mem[15]),16);
    bufp->fullSData(oldp+39,(vlSelf->top__DOT__c0__DOT__mem[16]),16);
    bufp->fullSData(oldp+40,(vlSelf->top__DOT__c0__DOT__mem[17]),16);
    bufp->fullSData(oldp+41,(vlSelf->top__DOT__c0__DOT__mem[18]),16);
    bufp->fullSData(oldp+42,(vlSelf->top__DOT__c0__DOT__mem[19]),16);
    bufp->fullSData(oldp+43,(vlSelf->top__DOT__c0__DOT__mem[20]),16);
    bufp->fullSData(oldp+44,(vlSelf->top__DOT__c0__DOT__mem[21]),16);
    bufp->fullSData(oldp+45,(vlSelf->top__DOT__c0__DOT__mem[22]),16);
    bufp->fullSData(oldp+46,(vlSelf->top__DOT__c0__DOT__mem[23]),16);
    bufp->fullSData(oldp+47,(vlSelf->top__DOT__c0__DOT__mem[24]),16);
    bufp->fullSData(oldp+48,(vlSelf->top__DOT__c0_n__DOT__mem[0]),16);
    bufp->fullSData(oldp+49,(vlSelf->top__DOT__c0_n__DOT__mem[1]),16);
    bufp->fullSData(oldp+50,(vlSelf->top__DOT__c0_n__DOT__mem[2]),16);
    bufp->fullSData(oldp+51,(vlSelf->top__DOT__c0_n__DOT__mem[3]),16);
    bufp->fullSData(oldp+52,(vlSelf->top__DOT__c0_n__DOT__mem[4]),16);
    bufp->fullSData(oldp+53,(vlSelf->top__DOT__c0_n__DOT__mem[5]),16);
    bufp->fullSData(oldp+54,(vlSelf->top__DOT__c0_n__DOT__mem[6]),16);
    bufp->fullSData(oldp+55,(vlSelf->top__DOT__c0_n__DOT__mem[7]),16);
    bufp->fullSData(oldp+56,(vlSelf->top__DOT__c0_n__DOT__mem[8]),16);
    bufp->fullSData(oldp+57,(vlSelf->top__DOT__c0_n__DOT__mem[9]),16);
    bufp->fullSData(oldp+58,(vlSelf->top__DOT__c0_n__DOT__mem[10]),16);
    bufp->fullSData(oldp+59,(vlSelf->top__DOT__c0_n__DOT__mem[11]),16);
    bufp->fullSData(oldp+60,(vlSelf->top__DOT__c0_n__DOT__mem[12]),16);
    bufp->fullSData(oldp+61,(vlSelf->top__DOT__c0_n__DOT__mem[13]),16);
    bufp->fullSData(oldp+62,(vlSelf->top__DOT__c0_n__DOT__mem[14]),16);
    bufp->fullSData(oldp+63,(vlSelf->top__DOT__c0_n__DOT__mem[15]),16);
    bufp->fullSData(oldp+64,(vlSelf->top__DOT__c0_n__DOT__mem[16]),16);
    bufp->fullSData(oldp+65,(vlSelf->top__DOT__c0_n__DOT__mem[17]),16);
    bufp->fullSData(oldp+66,(vlSelf->top__DOT__c0_n__DOT__mem[18]),16);
    bufp->fullSData(oldp+67,(vlSelf->top__DOT__c0_n__DOT__mem[19]),16);
    bufp->fullSData(oldp+68,(vlSelf->top__DOT__c0_n__DOT__mem[20]),16);
    bufp->fullSData(oldp+69,(vlSelf->top__DOT__c0_n__DOT__mem[21]),16);
    bufp->fullSData(oldp+70,(vlSelf->top__DOT__c0_n__DOT__mem[22]),16);
    bufp->fullSData(oldp+71,(vlSelf->top__DOT__c0_n__DOT__mem[23]),16);
    bufp->fullSData(oldp+72,(vlSelf->top__DOT__c0_n__DOT__mem[24]),16);
    bufp->fullSData(oldp+73,(vlSelf->top__DOT__ce__DOT__mem[0]),16);
    bufp->fullSData(oldp+74,(vlSelf->top__DOT__ce__DOT__mem[1]),16);
    bufp->fullSData(oldp+75,(vlSelf->top__DOT__ce__DOT__mem[2]),16);
    bufp->fullSData(oldp+76,(vlSelf->top__DOT__ce__DOT__mem[3]),16);
    bufp->fullSData(oldp+77,(vlSelf->top__DOT__ce__DOT__mem[4]),16);
    bufp->fullSData(oldp+78,(vlSelf->top__DOT__ce__DOT__mem[5]),16);
    bufp->fullSData(oldp+79,(vlSelf->top__DOT__ce__DOT__mem[6]),16);
    bufp->fullSData(oldp+80,(vlSelf->top__DOT__ce__DOT__mem[7]),16);
    bufp->fullSData(oldp+81,(vlSelf->top__DOT__ce__DOT__mem[8]),16);
    bufp->fullSData(oldp+82,(vlSelf->top__DOT__ce__DOT__mem[9]),16);
    bufp->fullSData(oldp+83,(vlSelf->top__DOT__ce__DOT__mem[10]),16);
    bufp->fullSData(oldp+84,(vlSelf->top__DOT__ce__DOT__mem[11]),16);
    bufp->fullSData(oldp+85,(vlSelf->top__DOT__ce__DOT__mem[12]),16);
    bufp->fullSData(oldp+86,(vlSelf->top__DOT__ce__DOT__mem[13]),16);
    bufp->fullSData(oldp+87,(vlSelf->top__DOT__ce__DOT__mem[14]),16);
    bufp->fullSData(oldp+88,(vlSelf->top__DOT__ce__DOT__mem[15]),16);
    bufp->fullSData(oldp+89,(vlSelf->top__DOT__ce__DOT__mem[16]),16);
    bufp->fullSData(oldp+90,(vlSelf->top__DOT__ce__DOT__mem[17]),16);
    bufp->fullSData(oldp+91,(vlSelf->top__DOT__ce__DOT__mem[18]),16);
    bufp->fullSData(oldp+92,(vlSelf->top__DOT__ce__DOT__mem[19]),16);
    bufp->fullSData(oldp+93,(vlSelf->top__DOT__ce__DOT__mem[20]),16);
    bufp->fullSData(oldp+94,(vlSelf->top__DOT__ce__DOT__mem[21]),16);
    bufp->fullSData(oldp+95,(vlSelf->top__DOT__ce__DOT__mem[22]),16);
    bufp->fullSData(oldp+96,(vlSelf->top__DOT__ce__DOT__mem[23]),16);
    bufp->fullSData(oldp+97,(vlSelf->top__DOT__ce__DOT__mem[24]),16);
    bufp->fullSData(oldp+98,(vlSelf->top__DOT__ce_n__DOT__mem[0]),16);
    bufp->fullSData(oldp+99,(vlSelf->top__DOT__ce_n__DOT__mem[1]),16);
    bufp->fullSData(oldp+100,(vlSelf->top__DOT__ce_n__DOT__mem[2]),16);
    bufp->fullSData(oldp+101,(vlSelf->top__DOT__ce_n__DOT__mem[3]),16);
    bufp->fullSData(oldp+102,(vlSelf->top__DOT__ce_n__DOT__mem[4]),16);
    bufp->fullSData(oldp+103,(vlSelf->top__DOT__ce_n__DOT__mem[5]),16);
    bufp->fullSData(oldp+104,(vlSelf->top__DOT__ce_n__DOT__mem[6]),16);
    bufp->fullSData(oldp+105,(vlSelf->top__DOT__ce_n__DOT__mem[7]),16);
    bufp->fullSData(oldp+106,(vlSelf->top__DOT__ce_n__DOT__mem[8]),16);
    bufp->fullSData(oldp+107,(vlSelf->top__DOT__ce_n__DOT__mem[9]),16);
    bufp->fullSData(oldp+108,(vlSelf->top__DOT__ce_n__DOT__mem[10]),16);
    bufp->fullSData(oldp+109,(vlSelf->top__DOT__ce_n__DOT__mem[11]),16);
    bufp->fullSData(oldp+110,(vlSelf->top__DOT__ce_n__DOT__mem[12]),16);
    bufp->fullSData(oldp+111,(vlSelf->top__DOT__ce_n__DOT__mem[13]),16);
    bufp->fullSData(oldp+112,(vlSelf->top__DOT__ce_n__DOT__mem[14]),16);
    bufp->fullSData(oldp+113,(vlSelf->top__DOT__ce_n__DOT__mem[15]),16);
    bufp->fullSData(oldp+114,(vlSelf->top__DOT__ce_n__DOT__mem[16]),16);
    bufp->fullSData(oldp+115,(vlSelf->top__DOT__ce_n__DOT__mem[17]),16);
    bufp->fullSData(oldp+116,(vlSelf->top__DOT__ce_n__DOT__mem[18]),16);
    bufp->fullSData(oldp+117,(vlSelf->top__DOT__ce_n__DOT__mem[19]),16);
    bufp->fullSData(oldp+118,(vlSelf->top__DOT__ce_n__DOT__mem[20]),16);
    bufp->fullSData(oldp+119,(vlSelf->top__DOT__ce_n__DOT__mem[21]),16);
    bufp->fullSData(oldp+120,(vlSelf->top__DOT__ce_n__DOT__mem[22]),16);
    bufp->fullSData(oldp+121,(vlSelf->top__DOT__ce_n__DOT__mem[23]),16);
    bufp->fullSData(oldp+122,(vlSelf->top__DOT__ce_n__DOT__mem[24]),16);
    bufp->fullSData(oldp+123,(vlSelf->top__DOT__cn__DOT__mem[0]),16);
    bufp->fullSData(oldp+124,(vlSelf->top__DOT__cn__DOT__mem[1]),16);
    bufp->fullSData(oldp+125,(vlSelf->top__DOT__cn__DOT__mem[2]),16);
    bufp->fullSData(oldp+126,(vlSelf->top__DOT__cn__DOT__mem[3]),16);
    bufp->fullSData(oldp+127,(vlSelf->top__DOT__cn__DOT__mem[4]),16);
    bufp->fullSData(oldp+128,(vlSelf->top__DOT__cn__DOT__mem[5]),16);
    bufp->fullSData(oldp+129,(vlSelf->top__DOT__cn__DOT__mem[6]),16);
    bufp->fullSData(oldp+130,(vlSelf->top__DOT__cn__DOT__mem[7]),16);
    bufp->fullSData(oldp+131,(vlSelf->top__DOT__cn__DOT__mem[8]),16);
    bufp->fullSData(oldp+132,(vlSelf->top__DOT__cn__DOT__mem[9]),16);
    bufp->fullSData(oldp+133,(vlSelf->top__DOT__cn__DOT__mem[10]),16);
    bufp->fullSData(oldp+134,(vlSelf->top__DOT__cn__DOT__mem[11]),16);
    bufp->fullSData(oldp+135,(vlSelf->top__DOT__cn__DOT__mem[12]),16);
    bufp->fullSData(oldp+136,(vlSelf->top__DOT__cn__DOT__mem[13]),16);
    bufp->fullSData(oldp+137,(vlSelf->top__DOT__cn__DOT__mem[14]),16);
    bufp->fullSData(oldp+138,(vlSelf->top__DOT__cn__DOT__mem[15]),16);
    bufp->fullSData(oldp+139,(vlSelf->top__DOT__cn__DOT__mem[16]),16);
    bufp->fullSData(oldp+140,(vlSelf->top__DOT__cn__DOT__mem[17]),16);
    bufp->fullSData(oldp+141,(vlSelf->top__DOT__cn__DOT__mem[18]),16);
    bufp->fullSData(oldp+142,(vlSelf->top__DOT__cn__DOT__mem[19]),16);
    bufp->fullSData(oldp+143,(vlSelf->top__DOT__cn__DOT__mem[20]),16);
    bufp->fullSData(oldp+144,(vlSelf->top__DOT__cn__DOT__mem[21]),16);
    bufp->fullSData(oldp+145,(vlSelf->top__DOT__cn__DOT__mem[22]),16);
    bufp->fullSData(oldp+146,(vlSelf->top__DOT__cn__DOT__mem[23]),16);
    bufp->fullSData(oldp+147,(vlSelf->top__DOT__cn__DOT__mem[24]),16);
    bufp->fullSData(oldp+148,(vlSelf->top__DOT__cn_n__DOT__mem[0]),16);
    bufp->fullSData(oldp+149,(vlSelf->top__DOT__cn_n__DOT__mem[1]),16);
    bufp->fullSData(oldp+150,(vlSelf->top__DOT__cn_n__DOT__mem[2]),16);
    bufp->fullSData(oldp+151,(vlSelf->top__DOT__cn_n__DOT__mem[3]),16);
    bufp->fullSData(oldp+152,(vlSelf->top__DOT__cn_n__DOT__mem[4]),16);
    bufp->fullSData(oldp+153,(vlSelf->top__DOT__cn_n__DOT__mem[5]),16);
    bufp->fullSData(oldp+154,(vlSelf->top__DOT__cn_n__DOT__mem[6]),16);
    bufp->fullSData(oldp+155,(vlSelf->top__DOT__cn_n__DOT__mem[7]),16);
    bufp->fullSData(oldp+156,(vlSelf->top__DOT__cn_n__DOT__mem[8]),16);
    bufp->fullSData(oldp+157,(vlSelf->top__DOT__cn_n__DOT__mem[9]),16);
    bufp->fullSData(oldp+158,(vlSelf->top__DOT__cn_n__DOT__mem[10]),16);
    bufp->fullSData(oldp+159,(vlSelf->top__DOT__cn_n__DOT__mem[11]),16);
    bufp->fullSData(oldp+160,(vlSelf->top__DOT__cn_n__DOT__mem[12]),16);
    bufp->fullSData(oldp+161,(vlSelf->top__DOT__cn_n__DOT__mem[13]),16);
    bufp->fullSData(oldp+162,(vlSelf->top__DOT__cn_n__DOT__mem[14]),16);
    bufp->fullSData(oldp+163,(vlSelf->top__DOT__cn_n__DOT__mem[15]),16);
    bufp->fullSData(oldp+164,(vlSelf->top__DOT__cn_n__DOT__mem[16]),16);
    bufp->fullSData(oldp+165,(vlSelf->top__DOT__cn_n__DOT__mem[17]),16);
    bufp->fullSData(oldp+166,(vlSelf->top__DOT__cn_n__DOT__mem[18]),16);
    bufp->fullSData(oldp+167,(vlSelf->top__DOT__cn_n__DOT__mem[19]),16);
    bufp->fullSData(oldp+168,(vlSelf->top__DOT__cn_n__DOT__mem[20]),16);
    bufp->fullSData(oldp+169,(vlSelf->top__DOT__cn_n__DOT__mem[21]),16);
    bufp->fullSData(oldp+170,(vlSelf->top__DOT__cn_n__DOT__mem[22]),16);
    bufp->fullSData(oldp+171,(vlSelf->top__DOT__cn_n__DOT__mem[23]),16);
    bufp->fullSData(oldp+172,(vlSelf->top__DOT__cn_n__DOT__mem[24]),16);
    bufp->fullSData(oldp+173,(vlSelf->top__DOT__cne__DOT__mem[0]),16);
    bufp->fullSData(oldp+174,(vlSelf->top__DOT__cne__DOT__mem[1]),16);
    bufp->fullSData(oldp+175,(vlSelf->top__DOT__cne__DOT__mem[2]),16);
    bufp->fullSData(oldp+176,(vlSelf->top__DOT__cne__DOT__mem[3]),16);
    bufp->fullSData(oldp+177,(vlSelf->top__DOT__cne__DOT__mem[4]),16);
    bufp->fullSData(oldp+178,(vlSelf->top__DOT__cne__DOT__mem[5]),16);
    bufp->fullSData(oldp+179,(vlSelf->top__DOT__cne__DOT__mem[6]),16);
    bufp->fullSData(oldp+180,(vlSelf->top__DOT__cne__DOT__mem[7]),16);
    bufp->fullSData(oldp+181,(vlSelf->top__DOT__cne__DOT__mem[8]),16);
    bufp->fullSData(oldp+182,(vlSelf->top__DOT__cne__DOT__mem[9]),16);
    bufp->fullSData(oldp+183,(vlSelf->top__DOT__cne__DOT__mem[10]),16);
    bufp->fullSData(oldp+184,(vlSelf->top__DOT__cne__DOT__mem[11]),16);
    bufp->fullSData(oldp+185,(vlSelf->top__DOT__cne__DOT__mem[12]),16);
    bufp->fullSData(oldp+186,(vlSelf->top__DOT__cne__DOT__mem[13]),16);
    bufp->fullSData(oldp+187,(vlSelf->top__DOT__cne__DOT__mem[14]),16);
    bufp->fullSData(oldp+188,(vlSelf->top__DOT__cne__DOT__mem[15]),16);
    bufp->fullSData(oldp+189,(vlSelf->top__DOT__cne__DOT__mem[16]),16);
    bufp->fullSData(oldp+190,(vlSelf->top__DOT__cne__DOT__mem[17]),16);
    bufp->fullSData(oldp+191,(vlSelf->top__DOT__cne__DOT__mem[18]),16);
    bufp->fullSData(oldp+192,(vlSelf->top__DOT__cne__DOT__mem[19]),16);
    bufp->fullSData(oldp+193,(vlSelf->top__DOT__cne__DOT__mem[20]),16);
    bufp->fullSData(oldp+194,(vlSelf->top__DOT__cne__DOT__mem[21]),16);
    bufp->fullSData(oldp+195,(vlSelf->top__DOT__cne__DOT__mem[22]),16);
    bufp->fullSData(oldp+196,(vlSelf->top__DOT__cne__DOT__mem[23]),16);
    bufp->fullSData(oldp+197,(vlSelf->top__DOT__cne__DOT__mem[24]),16);
    bufp->fullSData(oldp+198,(vlSelf->top__DOT__cne_n__DOT__mem[0]),16);
    bufp->fullSData(oldp+199,(vlSelf->top__DOT__cne_n__DOT__mem[1]),16);
    bufp->fullSData(oldp+200,(vlSelf->top__DOT__cne_n__DOT__mem[2]),16);
    bufp->fullSData(oldp+201,(vlSelf->top__DOT__cne_n__DOT__mem[3]),16);
    bufp->fullSData(oldp+202,(vlSelf->top__DOT__cne_n__DOT__mem[4]),16);
    bufp->fullSData(oldp+203,(vlSelf->top__DOT__cne_n__DOT__mem[5]),16);
    bufp->fullSData(oldp+204,(vlSelf->top__DOT__cne_n__DOT__mem[6]),16);
    bufp->fullSData(oldp+205,(vlSelf->top__DOT__cne_n__DOT__mem[7]),16);
    bufp->fullSData(oldp+206,(vlSelf->top__DOT__cne_n__DOT__mem[8]),16);
    bufp->fullSData(oldp+207,(vlSelf->top__DOT__cne_n__DOT__mem[9]),16);
    bufp->fullSData(oldp+208,(vlSelf->top__DOT__cne_n__DOT__mem[10]),16);
    bufp->fullSData(oldp+209,(vlSelf->top__DOT__cne_n__DOT__mem[11]),16);
    bufp->fullSData(oldp+210,(vlSelf->top__DOT__cne_n__DOT__mem[12]),16);
    bufp->fullSData(oldp+211,(vlSelf->top__DOT__cne_n__DOT__mem[13]),16);
    bufp->fullSData(oldp+212,(vlSelf->top__DOT__cne_n__DOT__mem[14]),16);
    bufp->fullSData(oldp+213,(vlSelf->top__DOT__cne_n__DOT__mem[15]),16);
    bufp->fullSData(oldp+214,(vlSelf->top__DOT__cne_n__DOT__mem[16]),16);
    bufp->fullSData(oldp+215,(vlSelf->top__DOT__cne_n__DOT__mem[17]),16);
    bufp->fullSData(oldp+216,(vlSelf->top__DOT__cne_n__DOT__mem[18]),16);
    bufp->fullSData(oldp+217,(vlSelf->top__DOT__cne_n__DOT__mem[19]),16);
    bufp->fullSData(oldp+218,(vlSelf->top__DOT__cne_n__DOT__mem[20]),16);
    bufp->fullSData(oldp+219,(vlSelf->top__DOT__cne_n__DOT__mem[21]),16);
    bufp->fullSData(oldp+220,(vlSelf->top__DOT__cne_n__DOT__mem[22]),16);
    bufp->fullSData(oldp+221,(vlSelf->top__DOT__cne_n__DOT__mem[23]),16);
    bufp->fullSData(oldp+222,(vlSelf->top__DOT__cne_n__DOT__mem[24]),16);
    bufp->fullSData(oldp+223,(vlSelf->top__DOT__cnw__DOT__mem[0]),16);
    bufp->fullSData(oldp+224,(vlSelf->top__DOT__cnw__DOT__mem[1]),16);
    bufp->fullSData(oldp+225,(vlSelf->top__DOT__cnw__DOT__mem[2]),16);
    bufp->fullSData(oldp+226,(vlSelf->top__DOT__cnw__DOT__mem[3]),16);
    bufp->fullSData(oldp+227,(vlSelf->top__DOT__cnw__DOT__mem[4]),16);
    bufp->fullSData(oldp+228,(vlSelf->top__DOT__cnw__DOT__mem[5]),16);
    bufp->fullSData(oldp+229,(vlSelf->top__DOT__cnw__DOT__mem[6]),16);
    bufp->fullSData(oldp+230,(vlSelf->top__DOT__cnw__DOT__mem[7]),16);
    bufp->fullSData(oldp+231,(vlSelf->top__DOT__cnw__DOT__mem[8]),16);
    bufp->fullSData(oldp+232,(vlSelf->top__DOT__cnw__DOT__mem[9]),16);
    bufp->fullSData(oldp+233,(vlSelf->top__DOT__cnw__DOT__mem[10]),16);
    bufp->fullSData(oldp+234,(vlSelf->top__DOT__cnw__DOT__mem[11]),16);
    bufp->fullSData(oldp+235,(vlSelf->top__DOT__cnw__DOT__mem[12]),16);
    bufp->fullSData(oldp+236,(vlSelf->top__DOT__cnw__DOT__mem[13]),16);
    bufp->fullSData(oldp+237,(vlSelf->top__DOT__cnw__DOT__mem[14]),16);
    bufp->fullSData(oldp+238,(vlSelf->top__DOT__cnw__DOT__mem[15]),16);
    bufp->fullSData(oldp+239,(vlSelf->top__DOT__cnw__DOT__mem[16]),16);
    bufp->fullSData(oldp+240,(vlSelf->top__DOT__cnw__DOT__mem[17]),16);
    bufp->fullSData(oldp+241,(vlSelf->top__DOT__cnw__DOT__mem[18]),16);
    bufp->fullSData(oldp+242,(vlSelf->top__DOT__cnw__DOT__mem[19]),16);
    bufp->fullSData(oldp+243,(vlSelf->top__DOT__cnw__DOT__mem[20]),16);
    bufp->fullSData(oldp+244,(vlSelf->top__DOT__cnw__DOT__mem[21]),16);
    bufp->fullSData(oldp+245,(vlSelf->top__DOT__cnw__DOT__mem[22]),16);
    bufp->fullSData(oldp+246,(vlSelf->top__DOT__cnw__DOT__mem[23]),16);
    bufp->fullSData(oldp+247,(vlSelf->top__DOT__cnw__DOT__mem[24]),16);
    bufp->fullSData(oldp+248,(vlSelf->top__DOT__cnw_n__DOT__mem[0]),16);
    bufp->fullSData(oldp+249,(vlSelf->top__DOT__cnw_n__DOT__mem[1]),16);
    bufp->fullSData(oldp+250,(vlSelf->top__DOT__cnw_n__DOT__mem[2]),16);
    bufp->fullSData(oldp+251,(vlSelf->top__DOT__cnw_n__DOT__mem[3]),16);
    bufp->fullSData(oldp+252,(vlSelf->top__DOT__cnw_n__DOT__mem[4]),16);
    bufp->fullSData(oldp+253,(vlSelf->top__DOT__cnw_n__DOT__mem[5]),16);
    bufp->fullSData(oldp+254,(vlSelf->top__DOT__cnw_n__DOT__mem[6]),16);
    bufp->fullSData(oldp+255,(vlSelf->top__DOT__cnw_n__DOT__mem[7]),16);
    bufp->fullSData(oldp+256,(vlSelf->top__DOT__cnw_n__DOT__mem[8]),16);
    bufp->fullSData(oldp+257,(vlSelf->top__DOT__cnw_n__DOT__mem[9]),16);
    bufp->fullSData(oldp+258,(vlSelf->top__DOT__cnw_n__DOT__mem[10]),16);
    bufp->fullSData(oldp+259,(vlSelf->top__DOT__cnw_n__DOT__mem[11]),16);
    bufp->fullSData(oldp+260,(vlSelf->top__DOT__cnw_n__DOT__mem[12]),16);
    bufp->fullSData(oldp+261,(vlSelf->top__DOT__cnw_n__DOT__mem[13]),16);
    bufp->fullSData(oldp+262,(vlSelf->top__DOT__cnw_n__DOT__mem[14]),16);
    bufp->fullSData(oldp+263,(vlSelf->top__DOT__cnw_n__DOT__mem[15]),16);
    bufp->fullSData(oldp+264,(vlSelf->top__DOT__cnw_n__DOT__mem[16]),16);
    bufp->fullSData(oldp+265,(vlSelf->top__DOT__cnw_n__DOT__mem[17]),16);
    bufp->fullSData(oldp+266,(vlSelf->top__DOT__cnw_n__DOT__mem[18]),16);
    bufp->fullSData(oldp+267,(vlSelf->top__DOT__cnw_n__DOT__mem[19]),16);
    bufp->fullSData(oldp+268,(vlSelf->top__DOT__cnw_n__DOT__mem[20]),16);
    bufp->fullSData(oldp+269,(vlSelf->top__DOT__cnw_n__DOT__mem[21]),16);
    bufp->fullSData(oldp+270,(vlSelf->top__DOT__cnw_n__DOT__mem[22]),16);
    bufp->fullSData(oldp+271,(vlSelf->top__DOT__cnw_n__DOT__mem[23]),16);
    bufp->fullSData(oldp+272,(vlSelf->top__DOT__cnw_n__DOT__mem[24]),16);
    bufp->fullSData(oldp+273,(vlSelf->top__DOT__cs__DOT__mem[0]),16);
    bufp->fullSData(oldp+274,(vlSelf->top__DOT__cs__DOT__mem[1]),16);
    bufp->fullSData(oldp+275,(vlSelf->top__DOT__cs__DOT__mem[2]),16);
    bufp->fullSData(oldp+276,(vlSelf->top__DOT__cs__DOT__mem[3]),16);
    bufp->fullSData(oldp+277,(vlSelf->top__DOT__cs__DOT__mem[4]),16);
    bufp->fullSData(oldp+278,(vlSelf->top__DOT__cs__DOT__mem[5]),16);
    bufp->fullSData(oldp+279,(vlSelf->top__DOT__cs__DOT__mem[6]),16);
    bufp->fullSData(oldp+280,(vlSelf->top__DOT__cs__DOT__mem[7]),16);
    bufp->fullSData(oldp+281,(vlSelf->top__DOT__cs__DOT__mem[8]),16);
    bufp->fullSData(oldp+282,(vlSelf->top__DOT__cs__DOT__mem[9]),16);
    bufp->fullSData(oldp+283,(vlSelf->top__DOT__cs__DOT__mem[10]),16);
    bufp->fullSData(oldp+284,(vlSelf->top__DOT__cs__DOT__mem[11]),16);
    bufp->fullSData(oldp+285,(vlSelf->top__DOT__cs__DOT__mem[12]),16);
    bufp->fullSData(oldp+286,(vlSelf->top__DOT__cs__DOT__mem[13]),16);
    bufp->fullSData(oldp+287,(vlSelf->top__DOT__cs__DOT__mem[14]),16);
    bufp->fullSData(oldp+288,(vlSelf->top__DOT__cs__DOT__mem[15]),16);
    bufp->fullSData(oldp+289,(vlSelf->top__DOT__cs__DOT__mem[16]),16);
    bufp->fullSData(oldp+290,(vlSelf->top__DOT__cs__DOT__mem[17]),16);
    bufp->fullSData(oldp+291,(vlSelf->top__DOT__cs__DOT__mem[18]),16);
    bufp->fullSData(oldp+292,(vlSelf->top__DOT__cs__DOT__mem[19]),16);
    bufp->fullSData(oldp+293,(vlSelf->top__DOT__cs__DOT__mem[20]),16);
    bufp->fullSData(oldp+294,(vlSelf->top__DOT__cs__DOT__mem[21]),16);
    bufp->fullSData(oldp+295,(vlSelf->top__DOT__cs__DOT__mem[22]),16);
    bufp->fullSData(oldp+296,(vlSelf->top__DOT__cs__DOT__mem[23]),16);
    bufp->fullSData(oldp+297,(vlSelf->top__DOT__cs__DOT__mem[24]),16);
    bufp->fullSData(oldp+298,(vlSelf->top__DOT__cs_n__DOT__mem[0]),16);
    bufp->fullSData(oldp+299,(vlSelf->top__DOT__cs_n__DOT__mem[1]),16);
    bufp->fullSData(oldp+300,(vlSelf->top__DOT__cs_n__DOT__mem[2]),16);
    bufp->fullSData(oldp+301,(vlSelf->top__DOT__cs_n__DOT__mem[3]),16);
    bufp->fullSData(oldp+302,(vlSelf->top__DOT__cs_n__DOT__mem[4]),16);
    bufp->fullSData(oldp+303,(vlSelf->top__DOT__cs_n__DOT__mem[5]),16);
    bufp->fullSData(oldp+304,(vlSelf->top__DOT__cs_n__DOT__mem[6]),16);
    bufp->fullSData(oldp+305,(vlSelf->top__DOT__cs_n__DOT__mem[7]),16);
    bufp->fullSData(oldp+306,(vlSelf->top__DOT__cs_n__DOT__mem[8]),16);
    bufp->fullSData(oldp+307,(vlSelf->top__DOT__cs_n__DOT__mem[9]),16);
    bufp->fullSData(oldp+308,(vlSelf->top__DOT__cs_n__DOT__mem[10]),16);
    bufp->fullSData(oldp+309,(vlSelf->top__DOT__cs_n__DOT__mem[11]),16);
    bufp->fullSData(oldp+310,(vlSelf->top__DOT__cs_n__DOT__mem[12]),16);
    bufp->fullSData(oldp+311,(vlSelf->top__DOT__cs_n__DOT__mem[13]),16);
    bufp->fullSData(oldp+312,(vlSelf->top__DOT__cs_n__DOT__mem[14]),16);
    bufp->fullSData(oldp+313,(vlSelf->top__DOT__cs_n__DOT__mem[15]),16);
    bufp->fullSData(oldp+314,(vlSelf->top__DOT__cs_n__DOT__mem[16]),16);
    bufp->fullSData(oldp+315,(vlSelf->top__DOT__cs_n__DOT__mem[17]),16);
    bufp->fullSData(oldp+316,(vlSelf->top__DOT__cs_n__DOT__mem[18]),16);
    bufp->fullSData(oldp+317,(vlSelf->top__DOT__cs_n__DOT__mem[19]),16);
    bufp->fullSData(oldp+318,(vlSelf->top__DOT__cs_n__DOT__mem[20]),16);
    bufp->fullSData(oldp+319,(vlSelf->top__DOT__cs_n__DOT__mem[21]),16);
    bufp->fullSData(oldp+320,(vlSelf->top__DOT__cs_n__DOT__mem[22]),16);
    bufp->fullSData(oldp+321,(vlSelf->top__DOT__cs_n__DOT__mem[23]),16);
    bufp->fullSData(oldp+322,(vlSelf->top__DOT__cs_n__DOT__mem[24]),16);
    bufp->fullSData(oldp+323,(vlSelf->top__DOT__cse__DOT__mem[0]),16);
    bufp->fullSData(oldp+324,(vlSelf->top__DOT__cse__DOT__mem[1]),16);
    bufp->fullSData(oldp+325,(vlSelf->top__DOT__cse__DOT__mem[2]),16);
    bufp->fullSData(oldp+326,(vlSelf->top__DOT__cse__DOT__mem[3]),16);
    bufp->fullSData(oldp+327,(vlSelf->top__DOT__cse__DOT__mem[4]),16);
    bufp->fullSData(oldp+328,(vlSelf->top__DOT__cse__DOT__mem[5]),16);
    bufp->fullSData(oldp+329,(vlSelf->top__DOT__cse__DOT__mem[6]),16);
    bufp->fullSData(oldp+330,(vlSelf->top__DOT__cse__DOT__mem[7]),16);
    bufp->fullSData(oldp+331,(vlSelf->top__DOT__cse__DOT__mem[8]),16);
    bufp->fullSData(oldp+332,(vlSelf->top__DOT__cse__DOT__mem[9]),16);
    bufp->fullSData(oldp+333,(vlSelf->top__DOT__cse__DOT__mem[10]),16);
    bufp->fullSData(oldp+334,(vlSelf->top__DOT__cse__DOT__mem[11]),16);
    bufp->fullSData(oldp+335,(vlSelf->top__DOT__cse__DOT__mem[12]),16);
    bufp->fullSData(oldp+336,(vlSelf->top__DOT__cse__DOT__mem[13]),16);
    bufp->fullSData(oldp+337,(vlSelf->top__DOT__cse__DOT__mem[14]),16);
    bufp->fullSData(oldp+338,(vlSelf->top__DOT__cse__DOT__mem[15]),16);
    bufp->fullSData(oldp+339,(vlSelf->top__DOT__cse__DOT__mem[16]),16);
    bufp->fullSData(oldp+340,(vlSelf->top__DOT__cse__DOT__mem[17]),16);
    bufp->fullSData(oldp+341,(vlSelf->top__DOT__cse__DOT__mem[18]),16);
    bufp->fullSData(oldp+342,(vlSelf->top__DOT__cse__DOT__mem[19]),16);
    bufp->fullSData(oldp+343,(vlSelf->top__DOT__cse__DOT__mem[20]),16);
    bufp->fullSData(oldp+344,(vlSelf->top__DOT__cse__DOT__mem[21]),16);
    bufp->fullSData(oldp+345,(vlSelf->top__DOT__cse__DOT__mem[22]),16);
    bufp->fullSData(oldp+346,(vlSelf->top__DOT__cse__DOT__mem[23]),16);
    bufp->fullSData(oldp+347,(vlSelf->top__DOT__cse__DOT__mem[24]),16);
    bufp->fullSData(oldp+348,(vlSelf->top__DOT__cse_n__DOT__mem[0]),16);
    bufp->fullSData(oldp+349,(vlSelf->top__DOT__cse_n__DOT__mem[1]),16);
    bufp->fullSData(oldp+350,(vlSelf->top__DOT__cse_n__DOT__mem[2]),16);
    bufp->fullSData(oldp+351,(vlSelf->top__DOT__cse_n__DOT__mem[3]),16);
    bufp->fullSData(oldp+352,(vlSelf->top__DOT__cse_n__DOT__mem[4]),16);
    bufp->fullSData(oldp+353,(vlSelf->top__DOT__cse_n__DOT__mem[5]),16);
    bufp->fullSData(oldp+354,(vlSelf->top__DOT__cse_n__DOT__mem[6]),16);
    bufp->fullSData(oldp+355,(vlSelf->top__DOT__cse_n__DOT__mem[7]),16);
    bufp->fullSData(oldp+356,(vlSelf->top__DOT__cse_n__DOT__mem[8]),16);
    bufp->fullSData(oldp+357,(vlSelf->top__DOT__cse_n__DOT__mem[9]),16);
    bufp->fullSData(oldp+358,(vlSelf->top__DOT__cse_n__DOT__mem[10]),16);
    bufp->fullSData(oldp+359,(vlSelf->top__DOT__cse_n__DOT__mem[11]),16);
    bufp->fullSData(oldp+360,(vlSelf->top__DOT__cse_n__DOT__mem[12]),16);
    bufp->fullSData(oldp+361,(vlSelf->top__DOT__cse_n__DOT__mem[13]),16);
    bufp->fullSData(oldp+362,(vlSelf->top__DOT__cse_n__DOT__mem[14]),16);
    bufp->fullSData(oldp+363,(vlSelf->top__DOT__cse_n__DOT__mem[15]),16);
    bufp->fullSData(oldp+364,(vlSelf->top__DOT__cse_n__DOT__mem[16]),16);
    bufp->fullSData(oldp+365,(vlSelf->top__DOT__cse_n__DOT__mem[17]),16);
    bufp->fullSData(oldp+366,(vlSelf->top__DOT__cse_n__DOT__mem[18]),16);
    bufp->fullSData(oldp+367,(vlSelf->top__DOT__cse_n__DOT__mem[19]),16);
    bufp->fullSData(oldp+368,(vlSelf->top__DOT__cse_n__DOT__mem[20]),16);
    bufp->fullSData(oldp+369,(vlSelf->top__DOT__cse_n__DOT__mem[21]),16);
    bufp->fullSData(oldp+370,(vlSelf->top__DOT__cse_n__DOT__mem[22]),16);
    bufp->fullSData(oldp+371,(vlSelf->top__DOT__cse_n__DOT__mem[23]),16);
    bufp->fullSData(oldp+372,(vlSelf->top__DOT__cse_n__DOT__mem[24]),16);
    bufp->fullSData(oldp+373,(vlSelf->top__DOT__csw__DOT__mem[0]),16);
    bufp->fullSData(oldp+374,(vlSelf->top__DOT__csw__DOT__mem[1]),16);
    bufp->fullSData(oldp+375,(vlSelf->top__DOT__csw__DOT__mem[2]),16);
    bufp->fullSData(oldp+376,(vlSelf->top__DOT__csw__DOT__mem[3]),16);
    bufp->fullSData(oldp+377,(vlSelf->top__DOT__csw__DOT__mem[4]),16);
    bufp->fullSData(oldp+378,(vlSelf->top__DOT__csw__DOT__mem[5]),16);
    bufp->fullSData(oldp+379,(vlSelf->top__DOT__csw__DOT__mem[6]),16);
    bufp->fullSData(oldp+380,(vlSelf->top__DOT__csw__DOT__mem[7]),16);
    bufp->fullSData(oldp+381,(vlSelf->top__DOT__csw__DOT__mem[8]),16);
    bufp->fullSData(oldp+382,(vlSelf->top__DOT__csw__DOT__mem[9]),16);
    bufp->fullSData(oldp+383,(vlSelf->top__DOT__csw__DOT__mem[10]),16);
    bufp->fullSData(oldp+384,(vlSelf->top__DOT__csw__DOT__mem[11]),16);
    bufp->fullSData(oldp+385,(vlSelf->top__DOT__csw__DOT__mem[12]),16);
    bufp->fullSData(oldp+386,(vlSelf->top__DOT__csw__DOT__mem[13]),16);
    bufp->fullSData(oldp+387,(vlSelf->top__DOT__csw__DOT__mem[14]),16);
    bufp->fullSData(oldp+388,(vlSelf->top__DOT__csw__DOT__mem[15]),16);
    bufp->fullSData(oldp+389,(vlSelf->top__DOT__csw__DOT__mem[16]),16);
    bufp->fullSData(oldp+390,(vlSelf->top__DOT__csw__DOT__mem[17]),16);
    bufp->fullSData(oldp+391,(vlSelf->top__DOT__csw__DOT__mem[18]),16);
    bufp->fullSData(oldp+392,(vlSelf->top__DOT__csw__DOT__mem[19]),16);
    bufp->fullSData(oldp+393,(vlSelf->top__DOT__csw__DOT__mem[20]),16);
    bufp->fullSData(oldp+394,(vlSelf->top__DOT__csw__DOT__mem[21]),16);
    bufp->fullSData(oldp+395,(vlSelf->top__DOT__csw__DOT__mem[22]),16);
    bufp->fullSData(oldp+396,(vlSelf->top__DOT__csw__DOT__mem[23]),16);
    bufp->fullSData(oldp+397,(vlSelf->top__DOT__csw__DOT__mem[24]),16);
    bufp->fullSData(oldp+398,(vlSelf->top__DOT__csw_n__DOT__mem[0]),16);
    bufp->fullSData(oldp+399,(vlSelf->top__DOT__csw_n__DOT__mem[1]),16);
    bufp->fullSData(oldp+400,(vlSelf->top__DOT__csw_n__DOT__mem[2]),16);
    bufp->fullSData(oldp+401,(vlSelf->top__DOT__csw_n__DOT__mem[3]),16);
    bufp->fullSData(oldp+402,(vlSelf->top__DOT__csw_n__DOT__mem[4]),16);
    bufp->fullSData(oldp+403,(vlSelf->top__DOT__csw_n__DOT__mem[5]),16);
    bufp->fullSData(oldp+404,(vlSelf->top__DOT__csw_n__DOT__mem[6]),16);
    bufp->fullSData(oldp+405,(vlSelf->top__DOT__csw_n__DOT__mem[7]),16);
    bufp->fullSData(oldp+406,(vlSelf->top__DOT__csw_n__DOT__mem[8]),16);
    bufp->fullSData(oldp+407,(vlSelf->top__DOT__csw_n__DOT__mem[9]),16);
    bufp->fullSData(oldp+408,(vlSelf->top__DOT__csw_n__DOT__mem[10]),16);
    bufp->fullSData(oldp+409,(vlSelf->top__DOT__csw_n__DOT__mem[11]),16);
    bufp->fullSData(oldp+410,(vlSelf->top__DOT__csw_n__DOT__mem[12]),16);
    bufp->fullSData(oldp+411,(vlSelf->top__DOT__csw_n__DOT__mem[13]),16);
    bufp->fullSData(oldp+412,(vlSelf->top__DOT__csw_n__DOT__mem[14]),16);
    bufp->fullSData(oldp+413,(vlSelf->top__DOT__csw_n__DOT__mem[15]),16);
    bufp->fullSData(oldp+414,(vlSelf->top__DOT__csw_n__DOT__mem[16]),16);
    bufp->fullSData(oldp+415,(vlSelf->top__DOT__csw_n__DOT__mem[17]),16);
    bufp->fullSData(oldp+416,(vlSelf->top__DOT__csw_n__DOT__mem[18]),16);
    bufp->fullSData(oldp+417,(vlSelf->top__DOT__csw_n__DOT__mem[19]),16);
    bufp->fullSData(oldp+418,(vlSelf->top__DOT__csw_n__DOT__mem[20]),16);
    bufp->fullSData(oldp+419,(vlSelf->top__DOT__csw_n__DOT__mem[21]),16);
    bufp->fullSData(oldp+420,(vlSelf->top__DOT__csw_n__DOT__mem[22]),16);
    bufp->fullSData(oldp+421,(vlSelf->top__DOT__csw_n__DOT__mem[23]),16);
    bufp->fullSData(oldp+422,(vlSelf->top__DOT__csw_n__DOT__mem[24]),16);
    bufp->fullSData(oldp+423,(vlSelf->top__DOT__cw__DOT__mem[0]),16);
    bufp->fullSData(oldp+424,(vlSelf->top__DOT__cw__DOT__mem[1]),16);
    bufp->fullSData(oldp+425,(vlSelf->top__DOT__cw__DOT__mem[2]),16);
    bufp->fullSData(oldp+426,(vlSelf->top__DOT__cw__DOT__mem[3]),16);
    bufp->fullSData(oldp+427,(vlSelf->top__DOT__cw__DOT__mem[4]),16);
    bufp->fullSData(oldp+428,(vlSelf->top__DOT__cw__DOT__mem[5]),16);
    bufp->fullSData(oldp+429,(vlSelf->top__DOT__cw__DOT__mem[6]),16);
    bufp->fullSData(oldp+430,(vlSelf->top__DOT__cw__DOT__mem[7]),16);
    bufp->fullSData(oldp+431,(vlSelf->top__DOT__cw__DOT__mem[8]),16);
    bufp->fullSData(oldp+432,(vlSelf->top__DOT__cw__DOT__mem[9]),16);
    bufp->fullSData(oldp+433,(vlSelf->top__DOT__cw__DOT__mem[10]),16);
    bufp->fullSData(oldp+434,(vlSelf->top__DOT__cw__DOT__mem[11]),16);
    bufp->fullSData(oldp+435,(vlSelf->top__DOT__cw__DOT__mem[12]),16);
    bufp->fullSData(oldp+436,(vlSelf->top__DOT__cw__DOT__mem[13]),16);
    bufp->fullSData(oldp+437,(vlSelf->top__DOT__cw__DOT__mem[14]),16);
    bufp->fullSData(oldp+438,(vlSelf->top__DOT__cw__DOT__mem[15]),16);
    bufp->fullSData(oldp+439,(vlSelf->top__DOT__cw__DOT__mem[16]),16);
    bufp->fullSData(oldp+440,(vlSelf->top__DOT__cw__DOT__mem[17]),16);
    bufp->fullSData(oldp+441,(vlSelf->top__DOT__cw__DOT__mem[18]),16);
    bufp->fullSData(oldp+442,(vlSelf->top__DOT__cw__DOT__mem[19]),16);
    bufp->fullSData(oldp+443,(vlSelf->top__DOT__cw__DOT__mem[20]),16);
    bufp->fullSData(oldp+444,(vlSelf->top__DOT__cw__DOT__mem[21]),16);
    bufp->fullSData(oldp+445,(vlSelf->top__DOT__cw__DOT__mem[22]),16);
    bufp->fullSData(oldp+446,(vlSelf->top__DOT__cw__DOT__mem[23]),16);
    bufp->fullSData(oldp+447,(vlSelf->top__DOT__cw__DOT__mem[24]),16);
    bufp->fullSData(oldp+448,(vlSelf->top__DOT__cw_n__DOT__mem[0]),16);
    bufp->fullSData(oldp+449,(vlSelf->top__DOT__cw_n__DOT__mem[1]),16);
    bufp->fullSData(oldp+450,(vlSelf->top__DOT__cw_n__DOT__mem[2]),16);
    bufp->fullSData(oldp+451,(vlSelf->top__DOT__cw_n__DOT__mem[3]),16);
    bufp->fullSData(oldp+452,(vlSelf->top__DOT__cw_n__DOT__mem[4]),16);
    bufp->fullSData(oldp+453,(vlSelf->top__DOT__cw_n__DOT__mem[5]),16);
    bufp->fullSData(oldp+454,(vlSelf->top__DOT__cw_n__DOT__mem[6]),16);
    bufp->fullSData(oldp+455,(vlSelf->top__DOT__cw_n__DOT__mem[7]),16);
    bufp->fullSData(oldp+456,(vlSelf->top__DOT__cw_n__DOT__mem[8]),16);
    bufp->fullSData(oldp+457,(vlSelf->top__DOT__cw_n__DOT__mem[9]),16);
    bufp->fullSData(oldp+458,(vlSelf->top__DOT__cw_n__DOT__mem[10]),16);
    bufp->fullSData(oldp+459,(vlSelf->top__DOT__cw_n__DOT__mem[11]),16);
    bufp->fullSData(oldp+460,(vlSelf->top__DOT__cw_n__DOT__mem[12]),16);
    bufp->fullSData(oldp+461,(vlSelf->top__DOT__cw_n__DOT__mem[13]),16);
    bufp->fullSData(oldp+462,(vlSelf->top__DOT__cw_n__DOT__mem[14]),16);
    bufp->fullSData(oldp+463,(vlSelf->top__DOT__cw_n__DOT__mem[15]),16);
    bufp->fullSData(oldp+464,(vlSelf->top__DOT__cw_n__DOT__mem[16]),16);
    bufp->fullSData(oldp+465,(vlSelf->top__DOT__cw_n__DOT__mem[17]),16);
    bufp->fullSData(oldp+466,(vlSelf->top__DOT__cw_n__DOT__mem[18]),16);
    bufp->fullSData(oldp+467,(vlSelf->top__DOT__cw_n__DOT__mem[19]),16);
    bufp->fullSData(oldp+468,(vlSelf->top__DOT__cw_n__DOT__mem[20]),16);
    bufp->fullSData(oldp+469,(vlSelf->top__DOT__cw_n__DOT__mem[21]),16);
    bufp->fullSData(oldp+470,(vlSelf->top__DOT__cw_n__DOT__mem[22]),16);
    bufp->fullSData(oldp+471,(vlSelf->top__DOT__cw_n__DOT__mem[23]),16);
    bufp->fullSData(oldp+472,(vlSelf->top__DOT__cw_n__DOT__mem[24]),16);
    bufp->fullSData(oldp+473,((0xffffU & ((((((IData)(vlSelf->top__DOT__ce_n_data_out) 
                                              - (IData)(vlSelf->top__DOT__cw_n_data_out)) 
                                             + (IData)(vlSelf->top__DOT__cne_n_data_out)) 
                                            - (IData)(vlSelf->top__DOT__csw_n_data_out)) 
                                           - (IData)(vlSelf->top__DOT__cnw_n_data_out)) 
                                          + (IData)(vlSelf->top__DOT__cse_n_data_out)))),16);
    bufp->fullSData(oldp+474,((0xffffU & ((((((IData)(vlSelf->top__DOT__cn_n_data_out) 
                                              - (IData)(vlSelf->top__DOT__cs_n_data_out)) 
                                             + (IData)(vlSelf->top__DOT__cne_n_data_out)) 
                                            - (IData)(vlSelf->top__DOT__csw_n_data_out)) 
                                           + (IData)(vlSelf->top__DOT__cnw_n_data_out)) 
                                          - (IData)(vlSelf->top__DOT__cse_n_data_out)))),16);
    bufp->fullIData(oldp+475,(vlSelf->top__DOT__lbm__DOT__collider__DOT__x2),32);
    bufp->fullIData(oldp+476,(vlSelf->top__DOT__lbm__DOT__collider__DOT__x3),32);
    bufp->fullIData(oldp+477,(VL_MULS_III(32, VL_EXTENDS_II(32,16, 
                                                            (0xffffU 
                                                             & ((((((IData)(vlSelf->top__DOT__ce_n_data_out) 
                                                                    - (IData)(vlSelf->top__DOT__cw_n_data_out)) 
                                                                   + (IData)(vlSelf->top__DOT__cne_n_data_out)) 
                                                                  - (IData)(vlSelf->top__DOT__csw_n_data_out)) 
                                                                 - (IData)(vlSelf->top__DOT__cnw_n_data_out)) 
                                                                + (IData)(vlSelf->top__DOT__cse_n_data_out)))), 
                                          VL_SHIFTRS_III(32,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x3, 0xdU))),32);
    bufp->fullIData(oldp+478,(VL_MULS_III(32, VL_EXTENDS_II(32,16, 
                                                            (0xffffU 
                                                             & ((((((IData)(vlSelf->top__DOT__cn_n_data_out) 
                                                                    - (IData)(vlSelf->top__DOT__cs_n_data_out)) 
                                                                   + (IData)(vlSelf->top__DOT__cne_n_data_out)) 
                                                                  - (IData)(vlSelf->top__DOT__csw_n_data_out)) 
                                                                 + (IData)(vlSelf->top__DOT__cnw_n_data_out)) 
                                                                - (IData)(vlSelf->top__DOT__cse_n_data_out)))), 
                                          VL_SHIFTRS_III(32,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x3, 0xdU))),32);
    bufp->fullIData(oldp+479,(vlSelf->top__DOT__lbm__DOT__collider__DOT__u_x_squared_intermediate),32);
    bufp->fullIData(oldp+480,(vlSelf->top__DOT__lbm__DOT__collider__DOT__u_y_squared_intermediate),32);
    bufp->fullSData(oldp+481,((0xffffU & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__u_x_squared_intermediate, 0xdU))),16);
    bufp->fullSData(oldp+482,((0xffffU & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__u_y_squared_intermediate, 0xdU))),16);
    bufp->fullIData(oldp+483,(VL_MULS_III(32, (IData)(0x4800U), 
                                          (VL_EXTENDS_II(32,16, 
                                                         (0xffffU 
                                                          & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__u_x_squared_intermediate, 0xdU))) 
                                           << 1U))),32);
    bufp->fullIData(oldp+484,(VL_MULS_III(32, (IData)(0x4800U), 
                                          (VL_EXTENDS_II(32,16, 
                                                         (0xffffU 
                                                          & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__u_y_squared_intermediate, 0xdU))) 
                                           << 1U))),32);
    bufp->fullSData(oldp+485,((0xffffU & VL_SHIFTRS_III(16,32,32, 
                                                        VL_MULS_III(32, (IData)(0x4800U), 
                                                                    (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__u_x_squared_intermediate, 0xdU))) 
                                                                     << 1U)), 0xdU))),16);
    bufp->fullSData(oldp+486,((0xffffU & VL_SHIFTRS_III(16,32,32, 
                                                        VL_MULS_III(32, (IData)(0x4800U), 
                                                                    (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__u_y_squared_intermediate, 0xdU))) 
                                                                     << 1U)), 0xdU))),16);
    bufp->fullSData(oldp+487,(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y),16);
    bufp->fullSData(oldp+488,(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y),16);
    bufp->fullSData(oldp+489,((0xffffU & (- (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y)))),16);
    bufp->fullSData(oldp+490,((0xffffU & (- (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y)))),16);
    bufp->fullIData(oldp+491,(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y_squared_intermediate),32);
    bufp->fullSData(oldp+492,((0xffffU & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y_squared_intermediate, 0xdU))),16);
    bufp->fullIData(oldp+493,(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y_squared_intermediate),32);
    bufp->fullSData(oldp+494,((0xffffU & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y_squared_intermediate, 0xdU))),16);
    bufp->fullIData(oldp+495,(VL_MULS_III(32, (IData)(0x6000U), 
                                          VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y)))),32);
    bufp->fullSData(oldp+496,((0xffffU & VL_SHIFTRS_III(16,32,32, 
                                                        VL_MULS_III(32, (IData)(0x6000U), 
                                                                    VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y))), 0xdU))),16);
    bufp->fullIData(oldp+497,(VL_MULS_III(32, (IData)(0x6000U), 
                                          VL_EXTENDS_II(32,16, 
                                                        (0xffffU 
                                                         & (- (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y)))))),32);
    bufp->fullSData(oldp+498,((0xffffU & VL_SHIFTRS_III(16,32,32, 
                                                        VL_MULS_III(32, (IData)(0x6000U), 
                                                                    VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & (- (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y))))), 0xdU))),16);
    bufp->fullIData(oldp+499,(VL_MULS_III(32, (IData)(0x6000U), 
                                          VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y)))),32);
    bufp->fullSData(oldp+500,((0xffffU & VL_SHIFTRS_III(16,32,32, 
                                                        VL_MULS_III(32, (IData)(0x6000U), 
                                                                    VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y))), 0xdU))),16);
    bufp->fullIData(oldp+501,(VL_MULS_III(32, (IData)(0x6000U), 
                                          VL_EXTENDS_II(32,16, 
                                                        (0xffffU 
                                                         & (- (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y)))))),32);
    bufp->fullSData(oldp+502,((0xffffU & VL_SHIFTRS_III(16,32,32, 
                                                        VL_MULS_III(32, (IData)(0x6000U), 
                                                                    VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & (- (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y))))), 0xdU))),16);
    bufp->fullIData(oldp+503,(VL_MULS_III(32, (IData)(0x4800U), 
                                          (VL_EXTENDS_II(32,16, 
                                                         (0xffffU 
                                                          & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y_squared_intermediate, 0xdU))) 
                                           << 1U))),32);
    bufp->fullSData(oldp+504,((0xffffU & VL_SHIFTRS_III(16,32,32, 
                                                        VL_MULS_III(32, (IData)(0x4800U), 
                                                                    (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y_squared_intermediate, 0xdU))) 
                                                                     << 1U)), 0xdU))),16);
    bufp->fullIData(oldp+505,(VL_MULS_III(32, (IData)(0x4800U), 
                                          (VL_EXTENDS_II(32,16, 
                                                         (0xffffU 
                                                          & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y_squared_intermediate, 0xdU))) 
                                           << 1U))),32);
    bufp->fullSData(oldp+506,((0xffffU & VL_SHIFTRS_III(16,32,32, 
                                                        VL_MULS_III(32, (IData)(0x4800U), 
                                                                    (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y_squared_intermediate, 0xdU))) 
                                                                     << 1U)), 0xdU))),16);
    bufp->fullSData(oldp+507,(vlSelf->top__DOT__c0_addr),13);
    bufp->fullSData(oldp+508,(vlSelf->top__DOT__c0_n_addr),13);
    bufp->fullSData(oldp+509,(vlSelf->top__DOT__cn_addr),13);
    bufp->fullSData(oldp+510,(vlSelf->top__DOT__cn_n_addr),13);
    bufp->fullSData(oldp+511,(vlSelf->top__DOT__cne_addr),13);
    bufp->fullSData(oldp+512,(vlSelf->top__DOT__cne_n_addr),13);
    bufp->fullSData(oldp+513,(vlSelf->top__DOT__ce_addr),13);
    bufp->fullSData(oldp+514,(vlSelf->top__DOT__ce_n_addr),13);
    bufp->fullSData(oldp+515,(vlSelf->top__DOT__cse_addr),13);
    bufp->fullSData(oldp+516,(vlSelf->top__DOT__cse_n_addr),13);
    bufp->fullSData(oldp+517,(vlSelf->top__DOT__cs_addr),13);
    bufp->fullSData(oldp+518,(vlSelf->top__DOT__cs_n_addr),13);
    bufp->fullSData(oldp+519,(vlSelf->top__DOT__csw_addr),13);
    bufp->fullSData(oldp+520,(vlSelf->top__DOT__csw_n_addr),13);
    bufp->fullSData(oldp+521,(vlSelf->top__DOT__cw_addr),13);
    bufp->fullSData(oldp+522,(vlSelf->top__DOT__cw_n_addr),13);
    bufp->fullSData(oldp+523,(vlSelf->top__DOT__cnw_addr),13);
    bufp->fullSData(oldp+524,(vlSelf->top__DOT__cnw_n_addr),13);
    bufp->fullSData(oldp+525,(vlSelf->top__DOT__c0_data_in),16);
    bufp->fullSData(oldp+526,(vlSelf->top__DOT__c0_n_data_in),16);
    bufp->fullSData(oldp+527,(vlSelf->top__DOT__cn_data_in),16);
    bufp->fullSData(oldp+528,(vlSelf->top__DOT__cn_n_data_in),16);
    bufp->fullSData(oldp+529,(vlSelf->top__DOT__cne_data_in),16);
    bufp->fullSData(oldp+530,(vlSelf->top__DOT__cne_n_data_in),16);
    bufp->fullSData(oldp+531,(vlSelf->top__DOT__ce_data_in),16);
    bufp->fullSData(oldp+532,(vlSelf->top__DOT__ce_n_data_in),16);
    bufp->fullSData(oldp+533,(vlSelf->top__DOT__cse_data_in),16);
    bufp->fullSData(oldp+534,(vlSelf->top__DOT__cse_n_data_in),16);
    bufp->fullSData(oldp+535,(vlSelf->top__DOT__cs_data_in),16);
    bufp->fullSData(oldp+536,(vlSelf->top__DOT__cs_n_data_in),16);
    bufp->fullSData(oldp+537,(vlSelf->top__DOT__csw_data_in),16);
    bufp->fullSData(oldp+538,(vlSelf->top__DOT__csw_n_data_in),16);
    bufp->fullSData(oldp+539,(vlSelf->top__DOT__cw_data_in),16);
    bufp->fullSData(oldp+540,(vlSelf->top__DOT__cw_n_data_in),16);
    bufp->fullSData(oldp+541,(vlSelf->top__DOT__cnw_data_in),16);
    bufp->fullSData(oldp+542,(vlSelf->top__DOT__cnw_n_data_in),16);
    bufp->fullBit(oldp+543,(vlSelf->top__DOT__c0_write_en));
    bufp->fullBit(oldp+544,(vlSelf->top__DOT__c0_n_write_en));
    bufp->fullBit(oldp+545,(vlSelf->top__DOT__cn_write_en));
    bufp->fullBit(oldp+546,(vlSelf->top__DOT__cn_n_write_en));
    bufp->fullBit(oldp+547,(vlSelf->top__DOT__cne_write_en));
    bufp->fullBit(oldp+548,(vlSelf->top__DOT__cne_n_write_en));
    bufp->fullBit(oldp+549,(vlSelf->top__DOT__ce_write_en));
    bufp->fullBit(oldp+550,(vlSelf->top__DOT__ce_n_write_en));
    bufp->fullBit(oldp+551,(vlSelf->top__DOT__cse_write_en));
    bufp->fullBit(oldp+552,(vlSelf->top__DOT__cse_n_write_en));
    bufp->fullBit(oldp+553,(vlSelf->top__DOT__cs_write_en));
    bufp->fullBit(oldp+554,(vlSelf->top__DOT__cs_n_write_en));
    bufp->fullBit(oldp+555,(vlSelf->top__DOT__csw_write_en));
    bufp->fullBit(oldp+556,(vlSelf->top__DOT__csw_n_write_en));
    bufp->fullBit(oldp+557,(vlSelf->top__DOT__cw_write_en));
    bufp->fullBit(oldp+558,(vlSelf->top__DOT__cw_n_write_en));
    bufp->fullBit(oldp+559,(vlSelf->top__DOT__cnw_write_en));
    bufp->fullBit(oldp+560,(vlSelf->top__DOT__cnw_n_write_en));
    bufp->fullSData(oldp+561,(vlSelf->top__DOT__lbm__DOT__index),13);
    bufp->fullBit(oldp+562,(vlSelf->top__DOT__lbm__DOT__c0_next_write_en));
    bufp->fullBit(oldp+563,(vlSelf->top__DOT__lbm__DOT__cn_next_write_en));
    bufp->fullBit(oldp+564,(vlSelf->top__DOT__lbm__DOT__cne_next_write_en));
    bufp->fullBit(oldp+565,(vlSelf->top__DOT__lbm__DOT__ce_next_write_en));
    bufp->fullBit(oldp+566,(vlSelf->top__DOT__lbm__DOT__cse_next_write_en));
    bufp->fullBit(oldp+567,(vlSelf->top__DOT__lbm__DOT__cs_next_write_en));
    bufp->fullBit(oldp+568,(vlSelf->top__DOT__lbm__DOT__csw_next_write_en));
    bufp->fullBit(oldp+569,(vlSelf->top__DOT__lbm__DOT__cw_next_write_en));
    bufp->fullBit(oldp+570,(vlSelf->top__DOT__lbm__DOT__cnw_next_write_en));
    bufp->fullBit(oldp+571,(vlSelf->top__DOT__lbm__DOT__incr_step));
    bufp->fullSData(oldp+572,(vlSelf->top__DOT__lbm__DOT__next_width_count),16);
    bufp->fullCData(oldp+573,(vlSelf->top__DOT__lbm__DOT__next_sim_state),4);
    bufp->fullSData(oldp+574,(vlSelf->top__DOT__lbm__DOT__next_index),13);
    bufp->fullSData(oldp+575,(vlSelf->top__DOT__lbm__DOT__c0_next_data_in),16);
    bufp->fullBit(oldp+576,(vlSelf->top__DOT__lbm__DOT__c0_n_next_write_en));
    bufp->fullSData(oldp+577,(vlSelf->top__DOT__lbm__DOT__c0_next_write_addr),13);
    bufp->fullSData(oldp+578,(vlSelf->top__DOT__lbm__DOT__cn_next_data_in),16);
    bufp->fullBit(oldp+579,(vlSelf->top__DOT__lbm__DOT__cn_n_next_write_en));
    bufp->fullSData(oldp+580,(vlSelf->top__DOT__lbm__DOT__cn_next_write_addr),13);
    bufp->fullSData(oldp+581,(vlSelf->top__DOT__lbm__DOT__cne_next_data_in),16);
    bufp->fullBit(oldp+582,(vlSelf->top__DOT__lbm__DOT__cne_n_next_write_en));
    bufp->fullSData(oldp+583,(vlSelf->top__DOT__lbm__DOT__cne_next_write_addr),13);
    bufp->fullSData(oldp+584,(vlSelf->top__DOT__lbm__DOT__ce_next_data_in),16);
    bufp->fullBit(oldp+585,(vlSelf->top__DOT__lbm__DOT__ce_n_next_write_en));
    bufp->fullSData(oldp+586,(vlSelf->top__DOT__lbm__DOT__ce_next_write_addr),13);
    bufp->fullSData(oldp+587,(vlSelf->top__DOT__lbm__DOT__cse_next_data_in),16);
    bufp->fullBit(oldp+588,(vlSelf->top__DOT__lbm__DOT__cse_n_next_write_en));
    bufp->fullSData(oldp+589,(vlSelf->top__DOT__lbm__DOT__cse_next_write_addr),13);
    bufp->fullSData(oldp+590,(vlSelf->top__DOT__lbm__DOT__cs_next_data_in),16);
    bufp->fullBit(oldp+591,(vlSelf->top__DOT__lbm__DOT__cs_n_next_write_en));
    bufp->fullSData(oldp+592,(vlSelf->top__DOT__lbm__DOT__cs_next_write_addr),13);
    bufp->fullSData(oldp+593,(vlSelf->top__DOT__lbm__DOT__csw_next_data_in),16);
    bufp->fullBit(oldp+594,(vlSelf->top__DOT__lbm__DOT__csw_n_next_write_en));
    bufp->fullSData(oldp+595,(vlSelf->top__DOT__lbm__DOT__csw_next_write_addr),13);
    bufp->fullSData(oldp+596,(vlSelf->top__DOT__lbm__DOT__cw_next_data_in),16);
    bufp->fullBit(oldp+597,(vlSelf->top__DOT__lbm__DOT__cw_n_next_write_en));
    bufp->fullSData(oldp+598,(vlSelf->top__DOT__lbm__DOT__cw_next_write_addr),13);
    bufp->fullSData(oldp+599,(vlSelf->top__DOT__lbm__DOT__cnw_next_data_in),16);
    bufp->fullBit(oldp+600,(vlSelf->top__DOT__lbm__DOT__cnw_n_next_write_en));
    bufp->fullSData(oldp+601,(vlSelf->top__DOT__lbm__DOT__cnw_next_write_addr),13);
    bufp->fullCData(oldp+602,(vlSelf->top__DOT__lbm__DOT__next_ram_wait_count),3);
    bufp->fullSData(oldp+603,(vlSelf->top__DOT__lbm__DOT__c_cn),16);
    bufp->fullSData(oldp+604,(vlSelf->top__DOT__lbm__DOT__c_cne),16);
    bufp->fullSData(oldp+605,(vlSelf->top__DOT__lbm__DOT__c_ce),16);
    bufp->fullSData(oldp+606,(vlSelf->top__DOT__lbm__DOT__c_cse),16);
    bufp->fullSData(oldp+607,(vlSelf->top__DOT__lbm__DOT__c_cs),16);
    bufp->fullSData(oldp+608,(vlSelf->top__DOT__lbm__DOT__c_csw),16);
    bufp->fullSData(oldp+609,(vlSelf->top__DOT__lbm__DOT__c_cw),16);
    bufp->fullSData(oldp+610,(vlSelf->top__DOT__lbm__DOT__c_cnw),16);
    bufp->fullBit(oldp+611,(vlSelf->clk));
    bufp->fullBit(oldp+612,(vlSelf->rst));
    bufp->fullBit(oldp+613,(vlSelf->en));
    bufp->fullIData(oldp+614,(vlSelf->step),32);
    bufp->fullIData(oldp+615,(vlSelf->barriers),25);
    bufp->fullSData(oldp+616,(vlSelf->omega),16);
    bufp->fullSData(oldp+617,(vlSelf->init_c0),16);
    bufp->fullSData(oldp+618,(vlSelf->init_cn),16);
    bufp->fullSData(oldp+619,(vlSelf->init_cne),16);
    bufp->fullSData(oldp+620,(vlSelf->init_ce),16);
    bufp->fullSData(oldp+621,(vlSelf->init_cse),16);
    bufp->fullSData(oldp+622,(vlSelf->init_cs),16);
    bufp->fullSData(oldp+623,(vlSelf->init_csw),16);
    bufp->fullSData(oldp+624,(vlSelf->init_cw),16);
    bufp->fullSData(oldp+625,(vlSelf->init_cnw),16);
    bufp->fullSData(oldp+626,(vlSelf->testing_cs_n_data_in),16);
    bufp->fullSData(oldp+627,(vlSelf->testing_c0_data_in),16);
    bufp->fullSData(oldp+628,(vlSelf->u_x),16);
    bufp->fullSData(oldp+629,(vlSelf->u_y),16);
    bufp->fullSData(oldp+630,(vlSelf->rho),16);
    bufp->fullSData(oldp+631,(vlSelf->u_squared),16);
    bufp->fullBit(oldp+632,(vlSelf->collider_ready));
    bufp->fullBit(oldp+633,(vlSelf->in_collision_state));
    bufp->fullSData(oldp+634,((0xffffU & vlSelf->step)),16);
    bufp->fullSData(oldp+635,((0xffffU & ((IData)(vlSelf->rho) 
                                          - ((((((((IData)(vlSelf->top__DOT__lbm__DOT__c_cn) 
                                                   + (IData)(vlSelf->top__DOT__lbm__DOT__c_cne)) 
                                                  + (IData)(vlSelf->top__DOT__lbm__DOT__c_ce)) 
                                                 + (IData)(vlSelf->top__DOT__lbm__DOT__c_cse)) 
                                                + (IData)(vlSelf->top__DOT__lbm__DOT__c_cs)) 
                                               + (IData)(vlSelf->top__DOT__lbm__DOT__c_csw)) 
                                              + (IData)(vlSelf->top__DOT__lbm__DOT__c_cw)) 
                                             + (IData)(vlSelf->top__DOT__lbm__DOT__c_cnw))))),16);
    bufp->fullIData(oldp+636,(VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
                                          ((IData)(0x4000U) 
                                           - VL_EXTENDS_II(32,16, (IData)(vlSelf->rho))))),32);
    bufp->fullIData(oldp+637,(VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
                                          VL_SHIFTRS_III(32,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x2, 0xdU))),32);
    bufp->fullIData(oldp+638,(VL_MULS_III(32, (IData)(0x3000U), 
                                          VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared)))),32);
    bufp->fullSData(oldp+639,((0xffffU & VL_SHIFTRS_III(16,32,32, 
                                                        VL_MULS_III(32, (IData)(0x3000U), 
                                                                    VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU))),16);
    bufp->fullIData(oldp+640,(VL_MULS_III(32, (IData)(0x6000U), 
                                          VL_EXTENDS_II(32,16, (IData)(vlSelf->u_x)))),32);
    bufp->fullIData(oldp+641,(VL_MULS_III(32, (IData)(0x6000U), 
                                          VL_EXTENDS_II(32,16, (IData)(vlSelf->u_y)))),32);
    bufp->fullSData(oldp+642,((0xffffU & VL_SHIFTRS_III(16,32,32, 
                                                        VL_MULS_III(32, (IData)(0x6000U), 
                                                                    VL_EXTENDS_II(32,16, (IData)(vlSelf->u_x))), 0xdU))),16);
    bufp->fullSData(oldp+643,((0xffffU & VL_SHIFTRS_III(16,32,32, 
                                                        VL_MULS_III(32, (IData)(0x6000U), 
                                                                    VL_EXTENDS_II(32,16, (IData)(vlSelf->u_y))), 0xdU))),16);
    bufp->fullSData(oldp+644,((0xffffU & (((IData)(0x2000U) 
                                           + (VL_SHIFTRS_III(16,32,32, 
                                                             VL_MULS_III(32, (IData)(0x6000U), 
                                                                         VL_EXTENDS_II(32,16, (IData)(vlSelf->u_y))), 0xdU) 
                                              + VL_SHIFTRS_III(16,32,32, 
                                                               VL_MULS_III(32, (IData)(0x4800U), 
                                                                           (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__u_y_squared_intermediate, 0xdU))) 
                                                                            << 1U)), 0xdU))) 
                                          - VL_SHIFTRS_III(16,32,32, 
                                                           VL_MULS_III(32, (IData)(0x3000U), 
                                                                       VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU)))),16);
    bufp->fullSData(oldp+645,((0xffffU & ((((IData)(0x2000U) 
                                            - VL_SHIFTRS_III(16,32,32, 
                                                             VL_MULS_III(32, (IData)(0x6000U), 
                                                                         VL_EXTENDS_II(32,16, (IData)(vlSelf->u_y))), 0xdU)) 
                                           + VL_SHIFTRS_III(16,32,32, 
                                                            VL_MULS_III(32, (IData)(0x4800U), 
                                                                        (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__u_y_squared_intermediate, 0xdU))) 
                                                                         << 1U)), 0xdU)) 
                                          - VL_SHIFTRS_III(16,32,32, 
                                                           VL_MULS_III(32, (IData)(0x3000U), 
                                                                       VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU)))),16);
    bufp->fullSData(oldp+646,((0xffffU & (((IData)(0x2000U) 
                                           + (VL_SHIFTRS_III(16,32,32, 
                                                             VL_MULS_III(32, (IData)(0x6000U), 
                                                                         VL_EXTENDS_II(32,16, (IData)(vlSelf->u_x))), 0xdU) 
                                              + VL_SHIFTRS_III(16,32,32, 
                                                               VL_MULS_III(32, (IData)(0x4800U), 
                                                                           (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__u_x_squared_intermediate, 0xdU))) 
                                                                            << 1U)), 0xdU))) 
                                          - VL_SHIFTRS_III(16,32,32, 
                                                           VL_MULS_III(32, (IData)(0x3000U), 
                                                                       VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU)))),16);
    bufp->fullSData(oldp+647,((0xffffU & ((((IData)(0x2000U) 
                                            - VL_SHIFTRS_III(16,32,32, 
                                                             VL_MULS_III(32, (IData)(0x6000U), 
                                                                         VL_EXTENDS_II(32,16, (IData)(vlSelf->u_x))), 0xdU)) 
                                           + VL_SHIFTRS_III(16,32,32, 
                                                            VL_MULS_III(32, (IData)(0x4800U), 
                                                                        (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__u_x_squared_intermediate, 0xdU))) 
                                                                         << 1U)), 0xdU)) 
                                          - VL_SHIFTRS_III(16,32,32, 
                                                           VL_MULS_III(32, (IData)(0x3000U), 
                                                                       VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU)))),16);
    bufp->fullIData(oldp+648,(VL_MULS_III(32, (IData)(0x38eU), 
                                          VL_EXTENDS_II(32,16, 
                                                        (0xffffU 
                                                         & (((IData)(0x2000U) 
                                                             + 
                                                             (VL_SHIFTRS_III(16,32,32, 
                                                                             VL_MULS_III(32, (IData)(0x6000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_y))), 0xdU) 
                                                              + 
                                                              VL_SHIFTRS_III(16,32,32, 
                                                                             VL_MULS_III(32, (IData)(0x4800U), 
                                                                                (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__u_y_squared_intermediate, 0xdU))) 
                                                                                << 1U)), 0xdU))) 
                                                            - 
                                                            VL_SHIFTRS_III(16,32,32, 
                                                                           VL_MULS_III(32, (IData)(0x3000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU)))))),32);
    bufp->fullIData(oldp+649,(VL_MULS_III(32, (IData)(0x38eU), 
                                          VL_EXTENDS_II(32,16, 
                                                        (0xffffU 
                                                         & ((((IData)(0x2000U) 
                                                              - 
                                                              VL_SHIFTRS_III(16,32,32, 
                                                                             VL_MULS_III(32, (IData)(0x6000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_y))), 0xdU)) 
                                                             + 
                                                             VL_SHIFTRS_III(16,32,32, 
                                                                            VL_MULS_III(32, (IData)(0x4800U), 
                                                                                (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__u_y_squared_intermediate, 0xdU))) 
                                                                                << 1U)), 0xdU)) 
                                                            - 
                                                            VL_SHIFTRS_III(16,32,32, 
                                                                           VL_MULS_III(32, (IData)(0x3000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU)))))),32);
    bufp->fullIData(oldp+650,(VL_MULS_III(32, (IData)(0x38eU), 
                                          VL_EXTENDS_II(32,16, 
                                                        (0xffffU 
                                                         & (((IData)(0x2000U) 
                                                             + 
                                                             (VL_SHIFTRS_III(16,32,32, 
                                                                             VL_MULS_III(32, (IData)(0x6000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_x))), 0xdU) 
                                                              + 
                                                              VL_SHIFTRS_III(16,32,32, 
                                                                             VL_MULS_III(32, (IData)(0x4800U), 
                                                                                (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__u_x_squared_intermediate, 0xdU))) 
                                                                                << 1U)), 0xdU))) 
                                                            - 
                                                            VL_SHIFTRS_III(16,32,32, 
                                                                           VL_MULS_III(32, (IData)(0x3000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU)))))),32);
    bufp->fullIData(oldp+651,(VL_MULS_III(32, (IData)(0x38eU), 
                                          VL_EXTENDS_II(32,16, 
                                                        (0xffffU 
                                                         & ((((IData)(0x2000U) 
                                                              - 
                                                              VL_SHIFTRS_III(16,32,32, 
                                                                             VL_MULS_III(32, (IData)(0x6000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_x))), 0xdU)) 
                                                             + 
                                                             VL_SHIFTRS_III(16,32,32, 
                                                                            VL_MULS_III(32, (IData)(0x4800U), 
                                                                                (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__u_x_squared_intermediate, 0xdU))) 
                                                                                << 1U)), 0xdU)) 
                                                            - 
                                                            VL_SHIFTRS_III(16,32,32, 
                                                                           VL_MULS_III(32, (IData)(0x3000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU)))))),32);
    bufp->fullIData(oldp+652,(VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
                                          VL_SHIFTRS_III(32,32,32, 
                                                         VL_MULS_III(32, (IData)(0x38eU), 
                                                                     VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & (((IData)(0x2000U) 
                                                                                + 
                                                                                (VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x6000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_y))), 0xdU) 
                                                                                + 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x4800U), 
                                                                                (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__u_y_squared_intermediate, 0xdU))) 
                                                                                << 1U)), 0xdU))) 
                                                                                - 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x3000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU))))), 0xdU))),32);
    bufp->fullIData(oldp+653,(VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
                                          VL_SHIFTRS_III(32,32,32, 
                                                         VL_MULS_III(32, (IData)(0x38eU), 
                                                                     VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & ((((IData)(0x2000U) 
                                                                                - 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x6000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_y))), 0xdU)) 
                                                                                + 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x4800U), 
                                                                                (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__u_y_squared_intermediate, 0xdU))) 
                                                                                << 1U)), 0xdU)) 
                                                                                - 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x3000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU))))), 0xdU))),32);
    bufp->fullIData(oldp+654,(VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
                                          VL_SHIFTRS_III(32,32,32, 
                                                         VL_MULS_III(32, (IData)(0x38eU), 
                                                                     VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & (((IData)(0x2000U) 
                                                                                + 
                                                                                (VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x6000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_x))), 0xdU) 
                                                                                + 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x4800U), 
                                                                                (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__u_x_squared_intermediate, 0xdU))) 
                                                                                << 1U)), 0xdU))) 
                                                                                - 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x3000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU))))), 0xdU))),32);
    bufp->fullIData(oldp+655,(VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
                                          VL_SHIFTRS_III(32,32,32, 
                                                         VL_MULS_III(32, (IData)(0x38eU), 
                                                                     VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & ((((IData)(0x2000U) 
                                                                                - 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x6000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_x))), 0xdU)) 
                                                                                + 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x4800U), 
                                                                                (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__u_x_squared_intermediate, 0xdU))) 
                                                                                << 1U)), 0xdU)) 
                                                                                - 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x3000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU))))), 0xdU))),32);
    bufp->fullSData(oldp+656,((0xffffU & VL_SHIFTRS_III(16,32,32, 
                                                        VL_MULS_III(32, 
                                                                    VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
                                                                    VL_SHIFTRS_III(32,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x38eU), 
                                                                                VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & (((IData)(0x2000U) 
                                                                                + 
                                                                                (VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x6000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_y))), 0xdU) 
                                                                                + 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x4800U), 
                                                                                (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__u_y_squared_intermediate, 0xdU))) 
                                                                                << 1U)), 0xdU))) 
                                                                                - 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x3000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU))))), 0xdU)), 0xdU))),16);
    bufp->fullSData(oldp+657,((0xffffU & VL_SHIFTRS_III(16,32,32, 
                                                        VL_MULS_III(32, 
                                                                    VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
                                                                    VL_SHIFTRS_III(32,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x38eU), 
                                                                                VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & ((((IData)(0x2000U) 
                                                                                - 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x6000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_y))), 0xdU)) 
                                                                                + 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x4800U), 
                                                                                (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__u_y_squared_intermediate, 0xdU))) 
                                                                                << 1U)), 0xdU)) 
                                                                                - 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x3000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU))))), 0xdU)), 0xdU))),16);
    bufp->fullSData(oldp+658,((0xffffU & VL_SHIFTRS_III(16,32,32, 
                                                        VL_MULS_III(32, 
                                                                    VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
                                                                    VL_SHIFTRS_III(32,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x38eU), 
                                                                                VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & (((IData)(0x2000U) 
                                                                                + 
                                                                                (VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x6000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_x))), 0xdU) 
                                                                                + 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x4800U), 
                                                                                (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__u_x_squared_intermediate, 0xdU))) 
                                                                                << 1U)), 0xdU))) 
                                                                                - 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x3000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU))))), 0xdU)), 0xdU))),16);
    bufp->fullSData(oldp+659,((0xffffU & VL_SHIFTRS_III(16,32,32, 
                                                        VL_MULS_III(32, 
                                                                    VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
                                                                    VL_SHIFTRS_III(32,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x38eU), 
                                                                                VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & ((((IData)(0x2000U) 
                                                                                - 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x6000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_x))), 0xdU)) 
                                                                                + 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x4800U), 
                                                                                (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__u_x_squared_intermediate, 0xdU))) 
                                                                                << 1U)), 0xdU)) 
                                                                                - 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x3000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU))))), 0xdU)), 0xdU))),16);
    bufp->fullSData(oldp+660,((0xffffU & (((IData)(0x2000U) 
                                           + (VL_SHIFTRS_III(16,32,32, 
                                                             VL_MULS_III(32, (IData)(0x6000U), 
                                                                         VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y))), 0xdU) 
                                              + VL_SHIFTRS_III(16,32,32, 
                                                               VL_MULS_III(32, (IData)(0x4800U), 
                                                                           (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y_squared_intermediate, 0xdU))) 
                                                                            << 1U)), 0xdU))) 
                                          - VL_SHIFTRS_III(16,32,32, 
                                                           VL_MULS_III(32, (IData)(0x3000U), 
                                                                       VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU)))),16);
    bufp->fullSData(oldp+661,((0xffffU & (((IData)(0x2000U) 
                                           + (VL_SHIFTRS_III(16,32,32, 
                                                             VL_MULS_III(32, (IData)(0x6000U), 
                                                                         VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & (- (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y))))), 0xdU) 
                                              + VL_SHIFTRS_III(16,32,32, 
                                                               VL_MULS_III(32, (IData)(0x4800U), 
                                                                           (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y_squared_intermediate, 0xdU))) 
                                                                            << 1U)), 0xdU))) 
                                          - VL_SHIFTRS_III(16,32,32, 
                                                           VL_MULS_III(32, (IData)(0x3000U), 
                                                                       VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU)))),16);
    bufp->fullSData(oldp+662,((0xffffU & (((IData)(0x2000U) 
                                           + (VL_SHIFTRS_III(16,32,32, 
                                                             VL_MULS_III(32, (IData)(0x6000U), 
                                                                         VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & (- (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y))))), 0xdU) 
                                              + VL_SHIFTRS_III(16,32,32, 
                                                               VL_MULS_III(32, (IData)(0x4800U), 
                                                                           (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y_squared_intermediate, 0xdU))) 
                                                                            << 1U)), 0xdU))) 
                                          - VL_SHIFTRS_III(16,32,32, 
                                                           VL_MULS_III(32, (IData)(0x3000U), 
                                                                       VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU)))),16);
    bufp->fullSData(oldp+663,((0xffffU & (((IData)(0x2000U) 
                                           + (VL_SHIFTRS_III(16,32,32, 
                                                             VL_MULS_III(32, (IData)(0x6000U), 
                                                                         VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y))), 0xdU) 
                                              + VL_SHIFTRS_III(16,32,32, 
                                                               VL_MULS_III(32, (IData)(0x4800U), 
                                                                           (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y_squared_intermediate, 0xdU))) 
                                                                            << 1U)), 0xdU))) 
                                          - VL_SHIFTRS_III(16,32,32, 
                                                           VL_MULS_III(32, (IData)(0x3000U), 
                                                                       VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU)))),16);
    bufp->fullIData(oldp+664,(VL_MULS_III(32, (IData)(0xe4U), 
                                          VL_EXTENDS_II(32,16, 
                                                        (0xffffU 
                                                         & (((IData)(0x2000U) 
                                                             + 
                                                             (VL_SHIFTRS_III(16,32,32, 
                                                                             VL_MULS_III(32, (IData)(0x6000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y))), 0xdU) 
                                                              + 
                                                              VL_SHIFTRS_III(16,32,32, 
                                                                             VL_MULS_III(32, (IData)(0x4800U), 
                                                                                (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y_squared_intermediate, 0xdU))) 
                                                                                << 1U)), 0xdU))) 
                                                            - 
                                                            VL_SHIFTRS_III(16,32,32, 
                                                                           VL_MULS_III(32, (IData)(0x3000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU)))))),32);
    bufp->fullIData(oldp+665,(VL_MULS_III(32, (IData)(0xe4U), 
                                          VL_EXTENDS_II(32,16, 
                                                        (0xffffU 
                                                         & (((IData)(0x2000U) 
                                                             + 
                                                             (VL_SHIFTRS_III(16,32,32, 
                                                                             VL_MULS_III(32, (IData)(0x6000U), 
                                                                                VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & (- (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y))))), 0xdU) 
                                                              + 
                                                              VL_SHIFTRS_III(16,32,32, 
                                                                             VL_MULS_III(32, (IData)(0x4800U), 
                                                                                (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y_squared_intermediate, 0xdU))) 
                                                                                << 1U)), 0xdU))) 
                                                            - 
                                                            VL_SHIFTRS_III(16,32,32, 
                                                                           VL_MULS_III(32, (IData)(0x3000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU)))))),32);
    bufp->fullIData(oldp+666,(VL_MULS_III(32, (IData)(0xe4U), 
                                          VL_EXTENDS_II(32,16, 
                                                        (0xffffU 
                                                         & (((IData)(0x2000U) 
                                                             + 
                                                             (VL_SHIFTRS_III(16,32,32, 
                                                                             VL_MULS_III(32, (IData)(0x6000U), 
                                                                                VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & (- (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y))))), 0xdU) 
                                                              + 
                                                              VL_SHIFTRS_III(16,32,32, 
                                                                             VL_MULS_III(32, (IData)(0x4800U), 
                                                                                (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y_squared_intermediate, 0xdU))) 
                                                                                << 1U)), 0xdU))) 
                                                            - 
                                                            VL_SHIFTRS_III(16,32,32, 
                                                                           VL_MULS_III(32, (IData)(0x3000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU)))))),32);
    bufp->fullIData(oldp+667,(VL_MULS_III(32, (IData)(0xe4U), 
                                          VL_EXTENDS_II(32,16, 
                                                        (0xffffU 
                                                         & (((IData)(0x2000U) 
                                                             + 
                                                             (VL_SHIFTRS_III(16,32,32, 
                                                                             VL_MULS_III(32, (IData)(0x6000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y))), 0xdU) 
                                                              + 
                                                              VL_SHIFTRS_III(16,32,32, 
                                                                             VL_MULS_III(32, (IData)(0x4800U), 
                                                                                (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y_squared_intermediate, 0xdU))) 
                                                                                << 1U)), 0xdU))) 
                                                            - 
                                                            VL_SHIFTRS_III(16,32,32, 
                                                                           VL_MULS_III(32, (IData)(0x3000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU)))))),32);
    bufp->fullIData(oldp+668,(VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
                                          VL_SHIFTRS_III(32,32,32, 
                                                         VL_MULS_III(32, (IData)(0xe4U), 
                                                                     VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & (((IData)(0x2000U) 
                                                                                + 
                                                                                (VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x6000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y))), 0xdU) 
                                                                                + 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x4800U), 
                                                                                (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y_squared_intermediate, 0xdU))) 
                                                                                << 1U)), 0xdU))) 
                                                                                - 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x3000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU))))), 0xdU))),32);
    bufp->fullIData(oldp+669,(VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
                                          VL_SHIFTRS_III(32,32,32, 
                                                         VL_MULS_III(32, (IData)(0xe4U), 
                                                                     VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & (((IData)(0x2000U) 
                                                                                + 
                                                                                (VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x6000U), 
                                                                                VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & (- (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y))))), 0xdU) 
                                                                                + 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x4800U), 
                                                                                (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y_squared_intermediate, 0xdU))) 
                                                                                << 1U)), 0xdU))) 
                                                                                - 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x3000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU))))), 0xdU))),32);
    bufp->fullIData(oldp+670,(VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
                                          VL_SHIFTRS_III(32,32,32, 
                                                         VL_MULS_III(32, (IData)(0xe4U), 
                                                                     VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & (((IData)(0x2000U) 
                                                                                + 
                                                                                (VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x6000U), 
                                                                                VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & (- (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y))))), 0xdU) 
                                                                                + 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x4800U), 
                                                                                (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y_squared_intermediate, 0xdU))) 
                                                                                << 1U)), 0xdU))) 
                                                                                - 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x3000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU))))), 0xdU))),32);
    bufp->fullIData(oldp+671,(VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
                                          VL_SHIFTRS_III(32,32,32, 
                                                         VL_MULS_III(32, (IData)(0xe4U), 
                                                                     VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & (((IData)(0x2000U) 
                                                                                + 
                                                                                (VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x6000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y))), 0xdU) 
                                                                                + 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x4800U), 
                                                                                (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y_squared_intermediate, 0xdU))) 
                                                                                << 1U)), 0xdU))) 
                                                                                - 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x3000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU))))), 0xdU))),32);
    bufp->fullSData(oldp+672,((0xffffU & VL_SHIFTRS_III(16,32,32, 
                                                        VL_MULS_III(32, 
                                                                    VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
                                                                    VL_SHIFTRS_III(32,32,32, 
                                                                                VL_MULS_III(32, (IData)(0xe4U), 
                                                                                VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & (((IData)(0x2000U) 
                                                                                + 
                                                                                (VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x6000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y))), 0xdU) 
                                                                                + 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x4800U), 
                                                                                (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y_squared_intermediate, 0xdU))) 
                                                                                << 1U)), 0xdU))) 
                                                                                - 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x3000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU))))), 0xdU)), 0xdU))),16);
    bufp->fullSData(oldp+673,((0xffffU & VL_SHIFTRS_III(16,32,32, 
                                                        VL_MULS_III(32, 
                                                                    VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
                                                                    VL_SHIFTRS_III(32,32,32, 
                                                                                VL_MULS_III(32, (IData)(0xe4U), 
                                                                                VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & (((IData)(0x2000U) 
                                                                                + 
                                                                                (VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x6000U), 
                                                                                VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & (- (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y))))), 0xdU) 
                                                                                + 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x4800U), 
                                                                                (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y_squared_intermediate, 0xdU))) 
                                                                                << 1U)), 0xdU))) 
                                                                                - 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x3000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU))))), 0xdU)), 0xdU))),16);
    bufp->fullSData(oldp+674,((0xffffU & VL_SHIFTRS_III(16,32,32, 
                                                        VL_MULS_III(32, 
                                                                    VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
                                                                    VL_SHIFTRS_III(32,32,32, 
                                                                                VL_MULS_III(32, (IData)(0xe4U), 
                                                                                VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & (((IData)(0x2000U) 
                                                                                + 
                                                                                (VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x6000U), 
                                                                                VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & (- (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y))))), 0xdU) 
                                                                                + 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x4800U), 
                                                                                (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y_squared_intermediate, 0xdU))) 
                                                                                << 1U)), 0xdU))) 
                                                                                - 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x3000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU))))), 0xdU)), 0xdU))),16);
    bufp->fullSData(oldp+675,((0xffffU & VL_SHIFTRS_III(16,32,32, 
                                                        VL_MULS_III(32, 
                                                                    VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
                                                                    VL_SHIFTRS_III(32,32,32, 
                                                                                VL_MULS_III(32, (IData)(0xe4U), 
                                                                                VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & (((IData)(0x2000U) 
                                                                                + 
                                                                                (VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x6000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y))), 0xdU) 
                                                                                + 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x4800U), 
                                                                                (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y_squared_intermediate, 0xdU))) 
                                                                                << 1U)), 0xdU))) 
                                                                                - 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x3000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU))))), 0xdU)), 0xdU))),16);
    bufp->fullIData(oldp+676,(VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->omega)), 
                                          (VL_EXTENDS_II(32,16, 
                                                         (0xffffU 
                                                          & VL_SHIFTRS_III(16,32,32, 
                                                                           VL_MULS_III(32, 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
                                                                                VL_SHIFTRS_III(32,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x38eU), 
                                                                                VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & (((IData)(0x2000U) 
                                                                                + 
                                                                                (VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x6000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_y))), 0xdU) 
                                                                                + 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x4800U), 
                                                                                (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__u_y_squared_intermediate, 0xdU))) 
                                                                                << 1U)), 0xdU))) 
                                                                                - 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x3000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU))))), 0xdU)), 0xdU))) 
                                           - VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__cn_n_data_out))))),32);
    bufp->fullIData(oldp+677,(VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->omega)), 
                                          (VL_EXTENDS_II(32,16, 
                                                         (0xffffU 
                                                          & VL_SHIFTRS_III(16,32,32, 
                                                                           VL_MULS_III(32, 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
                                                                                VL_SHIFTRS_III(32,32,32, 
                                                                                VL_MULS_III(32, (IData)(0xe4U), 
                                                                                VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & (((IData)(0x2000U) 
                                                                                + 
                                                                                (VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x6000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y))), 0xdU) 
                                                                                + 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x4800U), 
                                                                                (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y_squared_intermediate, 0xdU))) 
                                                                                << 1U)), 0xdU))) 
                                                                                - 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x3000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU))))), 0xdU)), 0xdU))) 
                                           - VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__cne_n_data_out))))),32);
    bufp->fullIData(oldp+678,(VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->omega)), 
                                          (VL_EXTENDS_II(32,16, 
                                                         (0xffffU 
                                                          & VL_SHIFTRS_III(16,32,32, 
                                                                           VL_MULS_III(32, 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
                                                                                VL_SHIFTRS_III(32,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x38eU), 
                                                                                VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & (((IData)(0x2000U) 
                                                                                + 
                                                                                (VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x6000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_x))), 0xdU) 
                                                                                + 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x4800U), 
                                                                                (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__u_x_squared_intermediate, 0xdU))) 
                                                                                << 1U)), 0xdU))) 
                                                                                - 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x3000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU))))), 0xdU)), 0xdU))) 
                                           - VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__ce_n_data_out))))),32);
    bufp->fullIData(oldp+679,(VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->omega)), 
                                          (VL_EXTENDS_II(32,16, 
                                                         (0xffffU 
                                                          & VL_SHIFTRS_III(16,32,32, 
                                                                           VL_MULS_III(32, 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
                                                                                VL_SHIFTRS_III(32,32,32, 
                                                                                VL_MULS_III(32, (IData)(0xe4U), 
                                                                                VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & (((IData)(0x2000U) 
                                                                                + 
                                                                                (VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x6000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y))), 0xdU) 
                                                                                + 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x4800U), 
                                                                                (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y_squared_intermediate, 0xdU))) 
                                                                                << 1U)), 0xdU))) 
                                                                                - 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x3000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU))))), 0xdU)), 0xdU))) 
                                           - VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__cse_n_data_out))))),32);
    bufp->fullIData(oldp+680,(VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->omega)), 
                                          (VL_EXTENDS_II(32,16, 
                                                         (0xffffU 
                                                          & VL_SHIFTRS_III(16,32,32, 
                                                                           VL_MULS_III(32, 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
                                                                                VL_SHIFTRS_III(32,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x38eU), 
                                                                                VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & ((((IData)(0x2000U) 
                                                                                - 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x6000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_y))), 0xdU)) 
                                                                                + 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x4800U), 
                                                                                (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__u_y_squared_intermediate, 0xdU))) 
                                                                                << 1U)), 0xdU)) 
                                                                                - 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x3000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU))))), 0xdU)), 0xdU))) 
                                           - VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__cs_n_data_out))))),32);
    bufp->fullIData(oldp+681,(VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->omega)), 
                                          (VL_EXTENDS_II(32,16, 
                                                         (0xffffU 
                                                          & VL_SHIFTRS_III(16,32,32, 
                                                                           VL_MULS_III(32, 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
                                                                                VL_SHIFTRS_III(32,32,32, 
                                                                                VL_MULS_III(32, (IData)(0xe4U), 
                                                                                VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & (((IData)(0x2000U) 
                                                                                + 
                                                                                (VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x6000U), 
                                                                                VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & (- (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y))))), 0xdU) 
                                                                                + 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x4800U), 
                                                                                (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y_squared_intermediate, 0xdU))) 
                                                                                << 1U)), 0xdU))) 
                                                                                - 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x3000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU))))), 0xdU)), 0xdU))) 
                                           - VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__csw_n_data_out))))),32);
    bufp->fullIData(oldp+682,(VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->omega)), 
                                          (VL_EXTENDS_II(32,16, 
                                                         (0xffffU 
                                                          & VL_SHIFTRS_III(16,32,32, 
                                                                           VL_MULS_III(32, 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
                                                                                VL_SHIFTRS_III(32,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x38eU), 
                                                                                VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & ((((IData)(0x2000U) 
                                                                                - 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x6000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_x))), 0xdU)) 
                                                                                + 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x4800U), 
                                                                                (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__u_x_squared_intermediate, 0xdU))) 
                                                                                << 1U)), 0xdU)) 
                                                                                - 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x3000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU))))), 0xdU)), 0xdU))) 
                                           - VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__cw_n_data_out))))),32);
    bufp->fullIData(oldp+683,(VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->omega)), 
                                          (VL_EXTENDS_II(32,16, 
                                                         (0xffffU 
                                                          & VL_SHIFTRS_III(16,32,32, 
                                                                           VL_MULS_III(32, 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
                                                                                VL_SHIFTRS_III(32,32,32, 
                                                                                VL_MULS_III(32, (IData)(0xe4U), 
                                                                                VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & (((IData)(0x2000U) 
                                                                                + 
                                                                                (VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x6000U), 
                                                                                VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & (- (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y))))), 0xdU) 
                                                                                + 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x4800U), 
                                                                                (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y_squared_intermediate, 0xdU))) 
                                                                                << 1U)), 0xdU))) 
                                                                                - 
                                                                                VL_SHIFTRS_III(16,32,32, 
                                                                                VL_MULS_III(32, (IData)(0x3000U), 
                                                                                VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU))))), 0xdU)), 0xdU))) 
                                           - VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__cnw_n_data_out))))),32);
    bufp->fullIData(oldp+684,(0x10U),32);
    bufp->fullIData(oldp+685,(0xdU),32);
    __Vtemp_h02def8a8__0[0U] = 0x2e6d656dU;
    __Vtemp_h02def8a8__0[1U] = 0x30453032U;
    __Vtemp_h02def8a8__0[2U] = 0x72616dU;
    bufp->fullWData(oldp+686,(__Vtemp_h02def8a8__0),88);
    __Vtemp_hc5db363f__0[0U] = 0x2e6d656dU;
    __Vtemp_hc5db363f__0[1U] = 0x30344242U;
    __Vtemp_hc5db363f__0[2U] = 0x72616dU;
    bufp->fullWData(oldp+689,(__Vtemp_hc5db363f__0),88);
    __Vtemp_hb3450750__0[0U] = 0x2e6d656dU;
    __Vtemp_hb3450750__0[1U] = 0x30333831U;
    __Vtemp_hb3450750__0[2U] = 0x72616dU;
    bufp->fullWData(oldp+692,(__Vtemp_hb3450750__0),88);
    __Vtemp_h5781e13f__0[0U] = 0x2e6d656dU;
    __Vtemp_h5781e13f__0[1U] = 0x30313246U;
    __Vtemp_h5781e13f__0[2U] = 0x72616dU;
    bufp->fullWData(oldp+695,(__Vtemp_h5781e13f__0),88);
    __Vtemp_h02cdee20__0[0U] = 0x2e6d656dU;
    __Vtemp_h02cdee20__0[1U] = 0x30304136U;
    __Vtemp_h02cdee20__0[2U] = 0x72616dU;
    bufp->fullWData(oldp+698,(__Vtemp_h02cdee20__0),88);
    __Vtemp_h63d4f183__0[0U] = 0x2e6d656dU;
    __Vtemp_h63d4f183__0[1U] = 0x30323938U;
    __Vtemp_h63d4f183__0[2U] = 0x72616dU;
    bufp->fullWData(oldp+701,(__Vtemp_h63d4f183__0),88);
    bufp->fullCData(oldp+704,(0U),4);
    bufp->fullCData(oldp+705,(1U),4);
    bufp->fullCData(oldp+706,(2U),4);
    bufp->fullCData(oldp+707,(3U),4);
    bufp->fullCData(oldp+708,(4U),4);
    bufp->fullCData(oldp+709,(5U),4);
    bufp->fullCData(oldp+710,(6U),4);
    bufp->fullCData(oldp+711,(7U),4);
    bufp->fullCData(oldp+712,(8U),4);
    bufp->fullCData(oldp+713,(9U),4);
    bufp->fullBit(oldp+714,(0U));
    bufp->fullBit(oldp+715,(1U));
    bufp->fullSData(oldp+716,(0xe39U),16);
    bufp->fullSData(oldp+717,(0x38eU),16);
    bufp->fullSData(oldp+718,(0xe4U),16);
    bufp->fullSData(oldp+719,(0x2000U),16);
    bufp->fullSData(oldp+720,(0x4000U),16);
    bufp->fullSData(oldp+721,(0x6000U),16);
    bufp->fullSData(oldp+722,(0x3000U),16);
    bufp->fullSData(oldp+723,(0x4800U),16);
}
