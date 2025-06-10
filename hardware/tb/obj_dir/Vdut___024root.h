// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdut.h for the primary calling header

#ifndef VERILATED_VDUT___024ROOT_H_
#define VERILATED_VDUT___024ROOT_H_  // guard

#include "verilated.h"

class Vdut__Syms;

class Vdut___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst,0,0);
        VL_IN8(en,0,0);
        VL_OUT8(collider_ready,0,0);
        VL_OUT8(in_collision_state,0,0);
        CData/*0:0*/ top__DOT__c0_write_en;
        CData/*0:0*/ top__DOT__c0_n_write_en;
        CData/*0:0*/ top__DOT__cn_write_en;
        CData/*0:0*/ top__DOT__cn_n_write_en;
        CData/*0:0*/ top__DOT__cne_write_en;
        CData/*0:0*/ top__DOT__cne_n_write_en;
        CData/*0:0*/ top__DOT__ce_write_en;
        CData/*0:0*/ top__DOT__ce_n_write_en;
        CData/*0:0*/ top__DOT__cse_write_en;
        CData/*0:0*/ top__DOT__cse_n_write_en;
        CData/*0:0*/ top__DOT__cs_write_en;
        CData/*0:0*/ top__DOT__cs_n_write_en;
        CData/*0:0*/ top__DOT__csw_write_en;
        CData/*0:0*/ top__DOT__csw_n_write_en;
        CData/*0:0*/ top__DOT__cw_write_en;
        CData/*0:0*/ top__DOT__cw_n_write_en;
        CData/*0:0*/ top__DOT__cnw_write_en;
        CData/*0:0*/ top__DOT__cnw_n_write_en;
        CData/*3:0*/ top__DOT__lbm__DOT__sim_state;
        CData/*3:0*/ top__DOT__lbm__DOT__next_sim_state;
        CData/*0:0*/ top__DOT__lbm__DOT__c0_next_write_en;
        CData/*0:0*/ top__DOT__lbm__DOT__c0_n_next_write_en;
        CData/*0:0*/ top__DOT__lbm__DOT__cn_next_write_en;
        CData/*0:0*/ top__DOT__lbm__DOT__cn_n_next_write_en;
        CData/*0:0*/ top__DOT__lbm__DOT__cne_next_write_en;
        CData/*0:0*/ top__DOT__lbm__DOT__cne_n_next_write_en;
        CData/*0:0*/ top__DOT__lbm__DOT__ce_next_write_en;
        CData/*0:0*/ top__DOT__lbm__DOT__ce_n_next_write_en;
        CData/*0:0*/ top__DOT__lbm__DOT__cse_next_write_en;
        CData/*0:0*/ top__DOT__lbm__DOT__cse_n_next_write_en;
        CData/*0:0*/ top__DOT__lbm__DOT__cs_next_write_en;
        CData/*0:0*/ top__DOT__lbm__DOT__cs_n_next_write_en;
        CData/*0:0*/ top__DOT__lbm__DOT__csw_next_write_en;
        CData/*0:0*/ top__DOT__lbm__DOT__csw_n_next_write_en;
        CData/*0:0*/ top__DOT__lbm__DOT__cw_next_write_en;
        CData/*0:0*/ top__DOT__lbm__DOT__cw_n_next_write_en;
        CData/*0:0*/ top__DOT__lbm__DOT__cnw_next_write_en;
        CData/*0:0*/ top__DOT__lbm__DOT__cnw_n_next_write_en;
        CData/*2:0*/ top__DOT__lbm__DOT__ram_wait_count;
        CData/*2:0*/ top__DOT__lbm__DOT__next_ram_wait_count;
        CData/*0:0*/ top__DOT__lbm__DOT__incr_step;
        CData/*0:0*/ __Vclklast__TOP__clk;
        CData/*0:0*/ __Vclklast__TOP__rst;
        VL_IN16(omega,15,0);
        VL_IN16(init_c0,15,0);
        VL_IN16(init_cn,15,0);
        VL_IN16(init_cne,15,0);
        VL_IN16(init_ce,15,0);
        VL_IN16(init_cse,15,0);
        VL_IN16(init_cs,15,0);
        VL_IN16(init_csw,15,0);
        VL_IN16(init_cw,15,0);
        VL_IN16(init_cnw,15,0);
        VL_OUT16(testing_cs_n_data_in,15,0);
        VL_OUT16(testing_c0_data_in,15,0);
        VL_OUT16(u_x,15,0);
        VL_OUT16(u_y,15,0);
        VL_OUT16(rho,15,0);
        VL_OUT16(u_squared,15,0);
    };
    struct {
        SData/*12:0*/ top__DOT__c0_addr;
        SData/*12:0*/ top__DOT__c0_n_addr;
        SData/*12:0*/ top__DOT__cn_addr;
        SData/*12:0*/ top__DOT__cn_n_addr;
        SData/*12:0*/ top__DOT__cne_addr;
        SData/*12:0*/ top__DOT__cne_n_addr;
        SData/*12:0*/ top__DOT__ce_addr;
        SData/*12:0*/ top__DOT__ce_n_addr;
        SData/*12:0*/ top__DOT__cse_addr;
        SData/*12:0*/ top__DOT__cse_n_addr;
        SData/*12:0*/ top__DOT__cs_addr;
        SData/*12:0*/ top__DOT__cs_n_addr;
        SData/*12:0*/ top__DOT__csw_addr;
        SData/*12:0*/ top__DOT__csw_n_addr;
        SData/*12:0*/ top__DOT__cw_addr;
        SData/*12:0*/ top__DOT__cw_n_addr;
        SData/*12:0*/ top__DOT__cnw_addr;
        SData/*12:0*/ top__DOT__cnw_n_addr;
        SData/*15:0*/ top__DOT__c0_data_in;
        SData/*15:0*/ top__DOT__c0_n_data_in;
        SData/*15:0*/ top__DOT__cn_data_in;
        SData/*15:0*/ top__DOT__cn_n_data_in;
        SData/*15:0*/ top__DOT__cne_data_in;
        SData/*15:0*/ top__DOT__cne_n_data_in;
        SData/*15:0*/ top__DOT__ce_data_in;
        SData/*15:0*/ top__DOT__ce_n_data_in;
        SData/*15:0*/ top__DOT__cse_data_in;
        SData/*15:0*/ top__DOT__cse_n_data_in;
        SData/*15:0*/ top__DOT__cs_data_in;
        SData/*15:0*/ top__DOT__cs_n_data_in;
        SData/*15:0*/ top__DOT__csw_data_in;
        SData/*15:0*/ top__DOT__csw_n_data_in;
        SData/*15:0*/ top__DOT__cw_data_in;
        SData/*15:0*/ top__DOT__cw_n_data_in;
        SData/*15:0*/ top__DOT__cnw_data_in;
        SData/*15:0*/ top__DOT__cnw_n_data_in;
        SData/*15:0*/ top__DOT__c0_data_out;
        SData/*15:0*/ top__DOT__c0_n_data_out;
        SData/*15:0*/ top__DOT__cn_data_out;
        SData/*15:0*/ top__DOT__cn_n_data_out;
        SData/*15:0*/ top__DOT__cne_data_out;
        SData/*15:0*/ top__DOT__cne_n_data_out;
        SData/*15:0*/ top__DOT__ce_data_out;
        SData/*15:0*/ top__DOT__ce_n_data_out;
        SData/*15:0*/ top__DOT__cse_data_out;
        SData/*15:0*/ top__DOT__cse_n_data_out;
        SData/*15:0*/ top__DOT__cs_data_out;
        SData/*15:0*/ top__DOT__cs_n_data_out;
        SData/*15:0*/ top__DOT__csw_data_out;
        SData/*15:0*/ top__DOT__csw_n_data_out;
        SData/*15:0*/ top__DOT__cw_data_out;
        SData/*15:0*/ top__DOT__cw_n_data_out;
        SData/*15:0*/ top__DOT__cnw_data_out;
        SData/*15:0*/ top__DOT__cnw_n_data_out;
        SData/*15:0*/ top__DOT__c0__DOT____Vlvbound_h1fbfd826__0;
        SData/*15:0*/ top__DOT__c0_n__DOT____Vlvbound_h1fbfd826__0;
        SData/*15:0*/ top__DOT__cn__DOT____Vlvbound_h1fbfd826__0;
        SData/*15:0*/ top__DOT__cn_n__DOT____Vlvbound_h1fbfd826__0;
        SData/*15:0*/ top__DOT__cne__DOT____Vlvbound_h1fbfd826__0;
        SData/*15:0*/ top__DOT__cne_n__DOT____Vlvbound_h1fbfd826__0;
        SData/*15:0*/ top__DOT__ce__DOT____Vlvbound_h1fbfd826__0;
        SData/*15:0*/ top__DOT__ce_n__DOT____Vlvbound_h1fbfd826__0;
        SData/*15:0*/ top__DOT__cse__DOT____Vlvbound_h1fbfd826__0;
        SData/*15:0*/ top__DOT__cse_n__DOT____Vlvbound_h1fbfd826__0;
    };
    struct {
        SData/*15:0*/ top__DOT__cs__DOT____Vlvbound_h1fbfd826__0;
        SData/*15:0*/ top__DOT__cs_n__DOT____Vlvbound_h1fbfd826__0;
        SData/*15:0*/ top__DOT__csw__DOT____Vlvbound_h1fbfd826__0;
        SData/*15:0*/ top__DOT__csw_n__DOT____Vlvbound_h1fbfd826__0;
        SData/*15:0*/ top__DOT__cw__DOT____Vlvbound_h1fbfd826__0;
        SData/*15:0*/ top__DOT__cw_n__DOT____Vlvbound_h1fbfd826__0;
        SData/*15:0*/ top__DOT__cnw__DOT____Vlvbound_h1fbfd826__0;
        SData/*15:0*/ top__DOT__cnw_n__DOT____Vlvbound_h1fbfd826__0;
        SData/*15:0*/ top__DOT__lbm__DOT__width_count;
        SData/*15:0*/ top__DOT__lbm__DOT__next_width_count;
        SData/*12:0*/ top__DOT__lbm__DOT__index;
        SData/*12:0*/ top__DOT__lbm__DOT__next_index;
        SData/*15:0*/ top__DOT__lbm__DOT__c0_next_data_in;
        SData/*12:0*/ top__DOT__lbm__DOT__c0_next_write_addr;
        SData/*15:0*/ top__DOT__lbm__DOT__cn_next_data_in;
        SData/*12:0*/ top__DOT__lbm__DOT__cn_next_write_addr;
        SData/*15:0*/ top__DOT__lbm__DOT__cne_next_data_in;
        SData/*12:0*/ top__DOT__lbm__DOT__cne_next_write_addr;
        SData/*15:0*/ top__DOT__lbm__DOT__ce_next_data_in;
        SData/*12:0*/ top__DOT__lbm__DOT__ce_next_write_addr;
        SData/*15:0*/ top__DOT__lbm__DOT__cse_next_data_in;
        SData/*12:0*/ top__DOT__lbm__DOT__cse_next_write_addr;
        SData/*15:0*/ top__DOT__lbm__DOT__cs_next_data_in;
        SData/*12:0*/ top__DOT__lbm__DOT__cs_next_write_addr;
        SData/*15:0*/ top__DOT__lbm__DOT__csw_next_data_in;
        SData/*12:0*/ top__DOT__lbm__DOT__csw_next_write_addr;
        SData/*15:0*/ top__DOT__lbm__DOT__cw_next_data_in;
        SData/*12:0*/ top__DOT__lbm__DOT__cw_next_write_addr;
        SData/*15:0*/ top__DOT__lbm__DOT__cnw_next_data_in;
        SData/*12:0*/ top__DOT__lbm__DOT__cnw_next_write_addr;
        SData/*15:0*/ top__DOT__lbm__DOT__step_count;
        SData/*15:0*/ top__DOT__lbm__DOT__c_cn;
        SData/*15:0*/ top__DOT__lbm__DOT__c_cne;
        SData/*15:0*/ top__DOT__lbm__DOT__c_ce;
        SData/*15:0*/ top__DOT__lbm__DOT__c_cse;
        SData/*15:0*/ top__DOT__lbm__DOT__c_cs;
        SData/*15:0*/ top__DOT__lbm__DOT__c_csw;
        SData/*15:0*/ top__DOT__lbm__DOT__c_cw;
        SData/*15:0*/ top__DOT__lbm__DOT__c_cnw;
        SData/*15:0*/ top__DOT__lbm__DOT__collider__DOT__x_plus_y;
        SData/*15:0*/ top__DOT__lbm__DOT__collider__DOT__x_minus_y;
        VL_IN(step,31,0);
        VL_IN(barriers,24,0);
        IData/*31:0*/ top__DOT__lbm__DOT__collider__DOT__x2;
        IData/*31:0*/ top__DOT__lbm__DOT__collider__DOT__x3;
        IData/*31:0*/ top__DOT__lbm__DOT__collider__DOT__u_x_squared_intermediate;
        IData/*31:0*/ top__DOT__lbm__DOT__collider__DOT__u_y_squared_intermediate;
        IData/*31:0*/ top__DOT__lbm__DOT__collider__DOT__x_plus_y_squared_intermediate;
        IData/*31:0*/ top__DOT__lbm__DOT__collider__DOT__x_minus_y_squared_intermediate;
        VlUnpacked<SData/*15:0*/, 25> top__DOT__c0__DOT__mem;
        VlUnpacked<SData/*15:0*/, 25> top__DOT__c0_n__DOT__mem;
        VlUnpacked<SData/*15:0*/, 25> top__DOT__cn__DOT__mem;
        VlUnpacked<SData/*15:0*/, 25> top__DOT__cn_n__DOT__mem;
        VlUnpacked<SData/*15:0*/, 25> top__DOT__cne__DOT__mem;
        VlUnpacked<SData/*15:0*/, 25> top__DOT__cne_n__DOT__mem;
        VlUnpacked<SData/*15:0*/, 25> top__DOT__ce__DOT__mem;
        VlUnpacked<SData/*15:0*/, 25> top__DOT__ce_n__DOT__mem;
        VlUnpacked<SData/*15:0*/, 25> top__DOT__cse__DOT__mem;
        VlUnpacked<SData/*15:0*/, 25> top__DOT__cse_n__DOT__mem;
        VlUnpacked<SData/*15:0*/, 25> top__DOT__cs__DOT__mem;
        VlUnpacked<SData/*15:0*/, 25> top__DOT__cs_n__DOT__mem;
        VlUnpacked<SData/*15:0*/, 25> top__DOT__csw__DOT__mem;
        VlUnpacked<SData/*15:0*/, 25> top__DOT__csw_n__DOT__mem;
        VlUnpacked<SData/*15:0*/, 25> top__DOT__cw__DOT__mem;
    };
    struct {
        VlUnpacked<SData/*15:0*/, 25> top__DOT__cw_n__DOT__mem;
        VlUnpacked<SData/*15:0*/, 25> top__DOT__cnw__DOT__mem;
        VlUnpacked<SData/*15:0*/, 25> top__DOT__cnw_n__DOT__mem;
        VlUnpacked<CData/*0:0*/, 5> __Vm_traceActivity;
    };

    // INTERNAL VARIABLES
    Vdut__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vdut___024root(Vdut__Syms* symsp, const char* name);
    ~Vdut___024root();
    VL_UNCOPYABLE(Vdut___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
