// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "verilated.h"

#include "Vdut___024root.h"

VL_INLINE_OPT void Vdut___024root___sequent__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___sequent__TOP__0\n"); );
    // Body
    if (vlSelf->rst) {
        vlSelf->top__DOT__lbm__DOT__step_count = (0xffffU 
                                                  & ((IData)(vlSelf->top__DOT__lbm__DOT__incr_step)
                                                      ? 
                                                     ((IData)(1U) 
                                                      + (IData)(vlSelf->top__DOT__lbm__DOT__step_count))
                                                      : (IData)(vlSelf->top__DOT__lbm__DOT__step_count)));
        vlSelf->top__DOT__lbm__DOT__width_count = vlSelf->top__DOT__lbm__DOT__next_width_count;
        vlSelf->top__DOT__lbm__DOT__ram_wait_count 
            = vlSelf->top__DOT__lbm__DOT__next_ram_wait_count;
        vlSelf->top__DOT__lbm__DOT__sim_state = vlSelf->top__DOT__lbm__DOT__next_sim_state;
    } else {
        vlSelf->top__DOT__lbm__DOT__step_count = 0U;
        vlSelf->top__DOT__lbm__DOT__width_count = 0U;
        vlSelf->top__DOT__lbm__DOT__ram_wait_count = 2U;
        vlSelf->top__DOT__lbm__DOT__sim_state = 9U;
    }
    vlSelf->in_collision_state = (8U == (IData)(vlSelf->top__DOT__lbm__DOT__sim_state));
    vlSelf->collider_ready = ((8U == (IData)(vlSelf->top__DOT__lbm__DOT__sim_state)) 
                              & (0U == (IData)(vlSelf->top__DOT__lbm__DOT__ram_wait_count)));
}

VL_INLINE_OPT void Vdut___024root___sequent__TOP__1(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___sequent__TOP__1\n"); );
    // Init
    CData/*4:0*/ __Vdlyvdim0__top__DOT__c0__DOT__mem__v0;
    SData/*15:0*/ __Vdlyvval__top__DOT__c0__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__c0__DOT__mem__v0;
    CData/*4:0*/ __Vdlyvdim0__top__DOT__c0_n__DOT__mem__v0;
    SData/*15:0*/ __Vdlyvval__top__DOT__c0_n__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__c0_n__DOT__mem__v0;
    CData/*4:0*/ __Vdlyvdim0__top__DOT__cn__DOT__mem__v0;
    SData/*15:0*/ __Vdlyvval__top__DOT__cn__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__cn__DOT__mem__v0;
    CData/*4:0*/ __Vdlyvdim0__top__DOT__cn_n__DOT__mem__v0;
    SData/*15:0*/ __Vdlyvval__top__DOT__cn_n__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__cn_n__DOT__mem__v0;
    CData/*4:0*/ __Vdlyvdim0__top__DOT__cne__DOT__mem__v0;
    SData/*15:0*/ __Vdlyvval__top__DOT__cne__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__cne__DOT__mem__v0;
    CData/*4:0*/ __Vdlyvdim0__top__DOT__cne_n__DOT__mem__v0;
    SData/*15:0*/ __Vdlyvval__top__DOT__cne_n__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__cne_n__DOT__mem__v0;
    CData/*4:0*/ __Vdlyvdim0__top__DOT__ce__DOT__mem__v0;
    SData/*15:0*/ __Vdlyvval__top__DOT__ce__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__ce__DOT__mem__v0;
    CData/*4:0*/ __Vdlyvdim0__top__DOT__ce_n__DOT__mem__v0;
    SData/*15:0*/ __Vdlyvval__top__DOT__ce_n__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__ce_n__DOT__mem__v0;
    CData/*4:0*/ __Vdlyvdim0__top__DOT__cse__DOT__mem__v0;
    SData/*15:0*/ __Vdlyvval__top__DOT__cse__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__cse__DOT__mem__v0;
    CData/*4:0*/ __Vdlyvdim0__top__DOT__cse_n__DOT__mem__v0;
    SData/*15:0*/ __Vdlyvval__top__DOT__cse_n__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__cse_n__DOT__mem__v0;
    CData/*4:0*/ __Vdlyvdim0__top__DOT__cs__DOT__mem__v0;
    SData/*15:0*/ __Vdlyvval__top__DOT__cs__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__cs__DOT__mem__v0;
    CData/*4:0*/ __Vdlyvdim0__top__DOT__cs_n__DOT__mem__v0;
    SData/*15:0*/ __Vdlyvval__top__DOT__cs_n__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__cs_n__DOT__mem__v0;
    CData/*4:0*/ __Vdlyvdim0__top__DOT__csw__DOT__mem__v0;
    SData/*15:0*/ __Vdlyvval__top__DOT__csw__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__csw__DOT__mem__v0;
    CData/*4:0*/ __Vdlyvdim0__top__DOT__csw_n__DOT__mem__v0;
    SData/*15:0*/ __Vdlyvval__top__DOT__csw_n__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__csw_n__DOT__mem__v0;
    CData/*4:0*/ __Vdlyvdim0__top__DOT__cw__DOT__mem__v0;
    SData/*15:0*/ __Vdlyvval__top__DOT__cw__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__cw__DOT__mem__v0;
    CData/*4:0*/ __Vdlyvdim0__top__DOT__cw_n__DOT__mem__v0;
    SData/*15:0*/ __Vdlyvval__top__DOT__cw_n__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__cw_n__DOT__mem__v0;
    CData/*4:0*/ __Vdlyvdim0__top__DOT__cnw__DOT__mem__v0;
    SData/*15:0*/ __Vdlyvval__top__DOT__cnw__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__cnw__DOT__mem__v0;
    CData/*4:0*/ __Vdlyvdim0__top__DOT__cnw_n__DOT__mem__v0;
    SData/*15:0*/ __Vdlyvval__top__DOT__cnw_n__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__cnw_n__DOT__mem__v0;
    // Body
    __Vdlyvset__top__DOT__cnw__DOT__mem__v0 = 0U;
    __Vdlyvset__top__DOT__cw__DOT__mem__v0 = 0U;
    __Vdlyvset__top__DOT__csw__DOT__mem__v0 = 0U;
    __Vdlyvset__top__DOT__cs__DOT__mem__v0 = 0U;
    __Vdlyvset__top__DOT__cse__DOT__mem__v0 = 0U;
    __Vdlyvset__top__DOT__ce__DOT__mem__v0 = 0U;
    __Vdlyvset__top__DOT__cne__DOT__mem__v0 = 0U;
    __Vdlyvset__top__DOT__cn_n__DOT__mem__v0 = 0U;
    __Vdlyvset__top__DOT__cn__DOT__mem__v0 = 0U;
    __Vdlyvset__top__DOT__cnw_n__DOT__mem__v0 = 0U;
    __Vdlyvset__top__DOT__cw_n__DOT__mem__v0 = 0U;
    __Vdlyvset__top__DOT__csw_n__DOT__mem__v0 = 0U;
    __Vdlyvset__top__DOT__cse_n__DOT__mem__v0 = 0U;
    __Vdlyvset__top__DOT__ce_n__DOT__mem__v0 = 0U;
    __Vdlyvset__top__DOT__cne_n__DOT__mem__v0 = 0U;
    __Vdlyvset__top__DOT__c0_n__DOT__mem__v0 = 0U;
    __Vdlyvset__top__DOT__cs_n__DOT__mem__v0 = 0U;
    __Vdlyvset__top__DOT__c0__DOT__mem__v0 = 0U;
    if (vlSelf->top__DOT__cnw_write_en) {
        vlSelf->top__DOT__cnw_data_out = ((0x18U >= 
                                           (0x1fU & (IData)(vlSelf->top__DOT__cnw_addr)))
                                           ? vlSelf->top__DOT__cnw__DOT__mem
                                          [(0x1fU & (IData)(vlSelf->top__DOT__cnw_addr))]
                                           : 0U);
        if ((0x19U > (IData)(vlSelf->top__DOT__cnw_addr))) {
            vlSelf->top__DOT__cnw__DOT____Vlvbound_h1fbfd826__0 
                = vlSelf->top__DOT__cnw_data_in;
            if ((0x18U >= (0x1fU & (IData)(vlSelf->top__DOT__cnw_addr)))) {
                __Vdlyvval__top__DOT__cnw__DOT__mem__v0 
                    = vlSelf->top__DOT__cnw__DOT____Vlvbound_h1fbfd826__0;
                __Vdlyvset__top__DOT__cnw__DOT__mem__v0 = 1U;
                __Vdlyvdim0__top__DOT__cnw__DOT__mem__v0 
                    = (0x1fU & (IData)(vlSelf->top__DOT__cnw_addr));
            }
        }
    } else {
        vlSelf->top__DOT__cnw_data_out = ((0x19U > (IData)(vlSelf->top__DOT__cnw_addr))
                                           ? ((0x18U 
                                               >= (0x1fU 
                                                   & (IData)(vlSelf->top__DOT__cnw_addr)))
                                               ? vlSelf->top__DOT__cnw__DOT__mem
                                              [(0x1fU 
                                                & (IData)(vlSelf->top__DOT__cnw_addr))]
                                               : 0U)
                                           : 0U);
    }
    if (vlSelf->top__DOT__cw_write_en) {
        vlSelf->top__DOT__cw_data_out = ((0x18U >= 
                                          (0x1fU & (IData)(vlSelf->top__DOT__cw_addr)))
                                          ? vlSelf->top__DOT__cw__DOT__mem
                                         [(0x1fU & (IData)(vlSelf->top__DOT__cw_addr))]
                                          : 0U);
        if ((0x19U > (IData)(vlSelf->top__DOT__cw_addr))) {
            vlSelf->top__DOT__cw__DOT____Vlvbound_h1fbfd826__0 
                = vlSelf->top__DOT__cw_data_in;
            if ((0x18U >= (0x1fU & (IData)(vlSelf->top__DOT__cw_addr)))) {
                __Vdlyvval__top__DOT__cw__DOT__mem__v0 
                    = vlSelf->top__DOT__cw__DOT____Vlvbound_h1fbfd826__0;
                __Vdlyvset__top__DOT__cw__DOT__mem__v0 = 1U;
                __Vdlyvdim0__top__DOT__cw__DOT__mem__v0 
                    = (0x1fU & (IData)(vlSelf->top__DOT__cw_addr));
            }
        }
    } else {
        vlSelf->top__DOT__cw_data_out = ((0x19U > (IData)(vlSelf->top__DOT__cw_addr))
                                          ? ((0x18U 
                                              >= (0x1fU 
                                                  & (IData)(vlSelf->top__DOT__cw_addr)))
                                              ? vlSelf->top__DOT__cw__DOT__mem
                                             [(0x1fU 
                                               & (IData)(vlSelf->top__DOT__cw_addr))]
                                              : 0U)
                                          : 0U);
    }
    if (vlSelf->top__DOT__csw_write_en) {
        vlSelf->top__DOT__csw_data_out = ((0x18U >= 
                                           (0x1fU & (IData)(vlSelf->top__DOT__csw_addr)))
                                           ? vlSelf->top__DOT__csw__DOT__mem
                                          [(0x1fU & (IData)(vlSelf->top__DOT__csw_addr))]
                                           : 0U);
        if ((0x19U > (IData)(vlSelf->top__DOT__csw_addr))) {
            vlSelf->top__DOT__csw__DOT____Vlvbound_h1fbfd826__0 
                = vlSelf->top__DOT__csw_data_in;
            if ((0x18U >= (0x1fU & (IData)(vlSelf->top__DOT__csw_addr)))) {
                __Vdlyvval__top__DOT__csw__DOT__mem__v0 
                    = vlSelf->top__DOT__csw__DOT____Vlvbound_h1fbfd826__0;
                __Vdlyvset__top__DOT__csw__DOT__mem__v0 = 1U;
                __Vdlyvdim0__top__DOT__csw__DOT__mem__v0 
                    = (0x1fU & (IData)(vlSelf->top__DOT__csw_addr));
            }
        }
    } else {
        vlSelf->top__DOT__csw_data_out = ((0x19U > (IData)(vlSelf->top__DOT__csw_addr))
                                           ? ((0x18U 
                                               >= (0x1fU 
                                                   & (IData)(vlSelf->top__DOT__csw_addr)))
                                               ? vlSelf->top__DOT__csw__DOT__mem
                                              [(0x1fU 
                                                & (IData)(vlSelf->top__DOT__csw_addr))]
                                               : 0U)
                                           : 0U);
    }
    if (vlSelf->top__DOT__cs_write_en) {
        vlSelf->top__DOT__cs_data_out = ((0x18U >= 
                                          (0x1fU & (IData)(vlSelf->top__DOT__cs_addr)))
                                          ? vlSelf->top__DOT__cs__DOT__mem
                                         [(0x1fU & (IData)(vlSelf->top__DOT__cs_addr))]
                                          : 0U);
        if ((0x19U > (IData)(vlSelf->top__DOT__cs_addr))) {
            vlSelf->top__DOT__cs__DOT____Vlvbound_h1fbfd826__0 
                = vlSelf->top__DOT__cs_data_in;
            if ((0x18U >= (0x1fU & (IData)(vlSelf->top__DOT__cs_addr)))) {
                __Vdlyvval__top__DOT__cs__DOT__mem__v0 
                    = vlSelf->top__DOT__cs__DOT____Vlvbound_h1fbfd826__0;
                __Vdlyvset__top__DOT__cs__DOT__mem__v0 = 1U;
                __Vdlyvdim0__top__DOT__cs__DOT__mem__v0 
                    = (0x1fU & (IData)(vlSelf->top__DOT__cs_addr));
            }
        }
    } else {
        vlSelf->top__DOT__cs_data_out = ((0x19U > (IData)(vlSelf->top__DOT__cs_addr))
                                          ? ((0x18U 
                                              >= (0x1fU 
                                                  & (IData)(vlSelf->top__DOT__cs_addr)))
                                              ? vlSelf->top__DOT__cs__DOT__mem
                                             [(0x1fU 
                                               & (IData)(vlSelf->top__DOT__cs_addr))]
                                              : 0U)
                                          : 0U);
    }
    if (vlSelf->top__DOT__cse_write_en) {
        vlSelf->top__DOT__cse_data_out = ((0x18U >= 
                                           (0x1fU & (IData)(vlSelf->top__DOT__cse_addr)))
                                           ? vlSelf->top__DOT__cse__DOT__mem
                                          [(0x1fU & (IData)(vlSelf->top__DOT__cse_addr))]
                                           : 0U);
        if ((0x19U > (IData)(vlSelf->top__DOT__cse_addr))) {
            vlSelf->top__DOT__cse__DOT____Vlvbound_h1fbfd826__0 
                = vlSelf->top__DOT__cse_data_in;
            if ((0x18U >= (0x1fU & (IData)(vlSelf->top__DOT__cse_addr)))) {
                __Vdlyvval__top__DOT__cse__DOT__mem__v0 
                    = vlSelf->top__DOT__cse__DOT____Vlvbound_h1fbfd826__0;
                __Vdlyvset__top__DOT__cse__DOT__mem__v0 = 1U;
                __Vdlyvdim0__top__DOT__cse__DOT__mem__v0 
                    = (0x1fU & (IData)(vlSelf->top__DOT__cse_addr));
            }
        }
    } else {
        vlSelf->top__DOT__cse_data_out = ((0x19U > (IData)(vlSelf->top__DOT__cse_addr))
                                           ? ((0x18U 
                                               >= (0x1fU 
                                                   & (IData)(vlSelf->top__DOT__cse_addr)))
                                               ? vlSelf->top__DOT__cse__DOT__mem
                                              [(0x1fU 
                                                & (IData)(vlSelf->top__DOT__cse_addr))]
                                               : 0U)
                                           : 0U);
    }
    if (vlSelf->top__DOT__ce_write_en) {
        vlSelf->top__DOT__ce_data_out = ((0x18U >= 
                                          (0x1fU & (IData)(vlSelf->top__DOT__ce_addr)))
                                          ? vlSelf->top__DOT__ce__DOT__mem
                                         [(0x1fU & (IData)(vlSelf->top__DOT__ce_addr))]
                                          : 0U);
        if ((0x19U > (IData)(vlSelf->top__DOT__ce_addr))) {
            vlSelf->top__DOT__ce__DOT____Vlvbound_h1fbfd826__0 
                = vlSelf->top__DOT__ce_data_in;
            if ((0x18U >= (0x1fU & (IData)(vlSelf->top__DOT__ce_addr)))) {
                __Vdlyvval__top__DOT__ce__DOT__mem__v0 
                    = vlSelf->top__DOT__ce__DOT____Vlvbound_h1fbfd826__0;
                __Vdlyvset__top__DOT__ce__DOT__mem__v0 = 1U;
                __Vdlyvdim0__top__DOT__ce__DOT__mem__v0 
                    = (0x1fU & (IData)(vlSelf->top__DOT__ce_addr));
            }
        }
    } else {
        vlSelf->top__DOT__ce_data_out = ((0x19U > (IData)(vlSelf->top__DOT__ce_addr))
                                          ? ((0x18U 
                                              >= (0x1fU 
                                                  & (IData)(vlSelf->top__DOT__ce_addr)))
                                              ? vlSelf->top__DOT__ce__DOT__mem
                                             [(0x1fU 
                                               & (IData)(vlSelf->top__DOT__ce_addr))]
                                              : 0U)
                                          : 0U);
    }
    if (vlSelf->top__DOT__cne_write_en) {
        vlSelf->top__DOT__cne_data_out = ((0x18U >= 
                                           (0x1fU & (IData)(vlSelf->top__DOT__cne_addr)))
                                           ? vlSelf->top__DOT__cne__DOT__mem
                                          [(0x1fU & (IData)(vlSelf->top__DOT__cne_addr))]
                                           : 0U);
        if ((0x19U > (IData)(vlSelf->top__DOT__cne_addr))) {
            vlSelf->top__DOT__cne__DOT____Vlvbound_h1fbfd826__0 
                = vlSelf->top__DOT__cne_data_in;
            if ((0x18U >= (0x1fU & (IData)(vlSelf->top__DOT__cne_addr)))) {
                __Vdlyvval__top__DOT__cne__DOT__mem__v0 
                    = vlSelf->top__DOT__cne__DOT____Vlvbound_h1fbfd826__0;
                __Vdlyvset__top__DOT__cne__DOT__mem__v0 = 1U;
                __Vdlyvdim0__top__DOT__cne__DOT__mem__v0 
                    = (0x1fU & (IData)(vlSelf->top__DOT__cne_addr));
            }
        }
    } else {
        vlSelf->top__DOT__cne_data_out = ((0x19U > (IData)(vlSelf->top__DOT__cne_addr))
                                           ? ((0x18U 
                                               >= (0x1fU 
                                                   & (IData)(vlSelf->top__DOT__cne_addr)))
                                               ? vlSelf->top__DOT__cne__DOT__mem
                                              [(0x1fU 
                                                & (IData)(vlSelf->top__DOT__cne_addr))]
                                               : 0U)
                                           : 0U);
    }
    if (vlSelf->top__DOT__cn_write_en) {
        vlSelf->top__DOT__cn_data_out = ((0x18U >= 
                                          (0x1fU & (IData)(vlSelf->top__DOT__cn_addr)))
                                          ? vlSelf->top__DOT__cn__DOT__mem
                                         [(0x1fU & (IData)(vlSelf->top__DOT__cn_addr))]
                                          : 0U);
        if ((0x19U > (IData)(vlSelf->top__DOT__cn_addr))) {
            vlSelf->top__DOT__cn__DOT____Vlvbound_h1fbfd826__0 
                = vlSelf->top__DOT__cn_data_in;
            if ((0x18U >= (0x1fU & (IData)(vlSelf->top__DOT__cn_addr)))) {
                __Vdlyvval__top__DOT__cn__DOT__mem__v0 
                    = vlSelf->top__DOT__cn__DOT____Vlvbound_h1fbfd826__0;
                __Vdlyvset__top__DOT__cn__DOT__mem__v0 = 1U;
                __Vdlyvdim0__top__DOT__cn__DOT__mem__v0 
                    = (0x1fU & (IData)(vlSelf->top__DOT__cn_addr));
            }
        }
    } else {
        vlSelf->top__DOT__cn_data_out = ((0x19U > (IData)(vlSelf->top__DOT__cn_addr))
                                          ? ((0x18U 
                                              >= (0x1fU 
                                                  & (IData)(vlSelf->top__DOT__cn_addr)))
                                              ? vlSelf->top__DOT__cn__DOT__mem
                                             [(0x1fU 
                                               & (IData)(vlSelf->top__DOT__cn_addr))]
                                              : 0U)
                                          : 0U);
    }
    if (vlSelf->top__DOT__c0_write_en) {
        vlSelf->top__DOT__c0_data_out = ((0x18U >= 
                                          (0x1fU & (IData)(vlSelf->top__DOT__c0_addr)))
                                          ? vlSelf->top__DOT__c0__DOT__mem
                                         [(0x1fU & (IData)(vlSelf->top__DOT__c0_addr))]
                                          : 0U);
        if ((0x19U > (IData)(vlSelf->top__DOT__c0_addr))) {
            vlSelf->top__DOT__c0__DOT____Vlvbound_h1fbfd826__0 
                = vlSelf->top__DOT__c0_data_in;
            if ((0x18U >= (0x1fU & (IData)(vlSelf->top__DOT__c0_addr)))) {
                __Vdlyvval__top__DOT__c0__DOT__mem__v0 
                    = vlSelf->top__DOT__c0__DOT____Vlvbound_h1fbfd826__0;
                __Vdlyvset__top__DOT__c0__DOT__mem__v0 = 1U;
                __Vdlyvdim0__top__DOT__c0__DOT__mem__v0 
                    = (0x1fU & (IData)(vlSelf->top__DOT__c0_addr));
            }
        }
    } else {
        vlSelf->top__DOT__c0_data_out = ((0x19U > (IData)(vlSelf->top__DOT__c0_addr))
                                          ? ((0x18U 
                                              >= (0x1fU 
                                                  & (IData)(vlSelf->top__DOT__c0_addr)))
                                              ? vlSelf->top__DOT__c0__DOT__mem
                                             [(0x1fU 
                                               & (IData)(vlSelf->top__DOT__c0_addr))]
                                              : 0U)
                                          : 0U);
    }
    if (vlSelf->top__DOT__cn_n_write_en) {
        if ((0x19U > (IData)(vlSelf->top__DOT__cn_n_addr))) {
            vlSelf->top__DOT__cn_n__DOT____Vlvbound_h1fbfd826__0 
                = vlSelf->top__DOT__cn_n_data_in;
            if ((0x18U >= (0x1fU & (IData)(vlSelf->top__DOT__cn_n_addr)))) {
                __Vdlyvval__top__DOT__cn_n__DOT__mem__v0 
                    = vlSelf->top__DOT__cn_n__DOT____Vlvbound_h1fbfd826__0;
                __Vdlyvset__top__DOT__cn_n__DOT__mem__v0 = 1U;
                __Vdlyvdim0__top__DOT__cn_n__DOT__mem__v0 
                    = (0x1fU & (IData)(vlSelf->top__DOT__cn_n_addr));
            }
        }
        vlSelf->top__DOT__cn_n_data_out = ((0x18U >= 
                                            (0x1fU 
                                             & (IData)(vlSelf->top__DOT__cn_n_addr)))
                                            ? vlSelf->top__DOT__cn_n__DOT__mem
                                           [(0x1fU 
                                             & (IData)(vlSelf->top__DOT__cn_n_addr))]
                                            : 0U);
    } else {
        vlSelf->top__DOT__cn_n_data_out = ((0x19U > (IData)(vlSelf->top__DOT__cn_n_addr))
                                            ? ((0x18U 
                                                >= 
                                                (0x1fU 
                                                 & (IData)(vlSelf->top__DOT__cn_n_addr)))
                                                ? vlSelf->top__DOT__cn_n__DOT__mem
                                               [(0x1fU 
                                                 & (IData)(vlSelf->top__DOT__cn_n_addr))]
                                                : 0U)
                                            : 0U);
    }
    if (vlSelf->top__DOT__cnw_n_write_en) {
        if ((0x19U > (IData)(vlSelf->top__DOT__cnw_n_addr))) {
            vlSelf->top__DOT__cnw_n__DOT____Vlvbound_h1fbfd826__0 
                = vlSelf->top__DOT__cnw_n_data_in;
            if ((0x18U >= (0x1fU & (IData)(vlSelf->top__DOT__cnw_n_addr)))) {
                __Vdlyvval__top__DOT__cnw_n__DOT__mem__v0 
                    = vlSelf->top__DOT__cnw_n__DOT____Vlvbound_h1fbfd826__0;
                __Vdlyvset__top__DOT__cnw_n__DOT__mem__v0 = 1U;
                __Vdlyvdim0__top__DOT__cnw_n__DOT__mem__v0 
                    = (0x1fU & (IData)(vlSelf->top__DOT__cnw_n_addr));
            }
        }
        vlSelf->top__DOT__cnw_n_data_out = ((0x18U 
                                             >= (0x1fU 
                                                 & (IData)(vlSelf->top__DOT__cnw_n_addr)))
                                             ? vlSelf->top__DOT__cnw_n__DOT__mem
                                            [(0x1fU 
                                              & (IData)(vlSelf->top__DOT__cnw_n_addr))]
                                             : 0U);
    } else {
        vlSelf->top__DOT__cnw_n_data_out = ((0x19U 
                                             > (IData)(vlSelf->top__DOT__cnw_n_addr))
                                             ? ((0x18U 
                                                 >= 
                                                 (0x1fU 
                                                  & (IData)(vlSelf->top__DOT__cnw_n_addr)))
                                                 ? 
                                                vlSelf->top__DOT__cnw_n__DOT__mem
                                                [(0x1fU 
                                                  & (IData)(vlSelf->top__DOT__cnw_n_addr))]
                                                 : 0U)
                                             : 0U);
    }
    if (vlSelf->top__DOT__cw_n_write_en) {
        if ((0x19U > (IData)(vlSelf->top__DOT__cw_n_addr))) {
            vlSelf->top__DOT__cw_n__DOT____Vlvbound_h1fbfd826__0 
                = vlSelf->top__DOT__cw_n_data_in;
            if ((0x18U >= (0x1fU & (IData)(vlSelf->top__DOT__cw_n_addr)))) {
                __Vdlyvval__top__DOT__cw_n__DOT__mem__v0 
                    = vlSelf->top__DOT__cw_n__DOT____Vlvbound_h1fbfd826__0;
                __Vdlyvset__top__DOT__cw_n__DOT__mem__v0 = 1U;
                __Vdlyvdim0__top__DOT__cw_n__DOT__mem__v0 
                    = (0x1fU & (IData)(vlSelf->top__DOT__cw_n_addr));
            }
        }
        vlSelf->top__DOT__cw_n_data_out = ((0x18U >= 
                                            (0x1fU 
                                             & (IData)(vlSelf->top__DOT__cw_n_addr)))
                                            ? vlSelf->top__DOT__cw_n__DOT__mem
                                           [(0x1fU 
                                             & (IData)(vlSelf->top__DOT__cw_n_addr))]
                                            : 0U);
    } else {
        vlSelf->top__DOT__cw_n_data_out = ((0x19U > (IData)(vlSelf->top__DOT__cw_n_addr))
                                            ? ((0x18U 
                                                >= 
                                                (0x1fU 
                                                 & (IData)(vlSelf->top__DOT__cw_n_addr)))
                                                ? vlSelf->top__DOT__cw_n__DOT__mem
                                               [(0x1fU 
                                                 & (IData)(vlSelf->top__DOT__cw_n_addr))]
                                                : 0U)
                                            : 0U);
    }
    if (vlSelf->top__DOT__csw_n_write_en) {
        if ((0x19U > (IData)(vlSelf->top__DOT__csw_n_addr))) {
            vlSelf->top__DOT__csw_n__DOT____Vlvbound_h1fbfd826__0 
                = vlSelf->top__DOT__csw_n_data_in;
            if ((0x18U >= (0x1fU & (IData)(vlSelf->top__DOT__csw_n_addr)))) {
                __Vdlyvval__top__DOT__csw_n__DOT__mem__v0 
                    = vlSelf->top__DOT__csw_n__DOT____Vlvbound_h1fbfd826__0;
                __Vdlyvset__top__DOT__csw_n__DOT__mem__v0 = 1U;
                __Vdlyvdim0__top__DOT__csw_n__DOT__mem__v0 
                    = (0x1fU & (IData)(vlSelf->top__DOT__csw_n_addr));
            }
        }
        vlSelf->top__DOT__csw_n_data_out = ((0x18U 
                                             >= (0x1fU 
                                                 & (IData)(vlSelf->top__DOT__csw_n_addr)))
                                             ? vlSelf->top__DOT__csw_n__DOT__mem
                                            [(0x1fU 
                                              & (IData)(vlSelf->top__DOT__csw_n_addr))]
                                             : 0U);
    } else {
        vlSelf->top__DOT__csw_n_data_out = ((0x19U 
                                             > (IData)(vlSelf->top__DOT__csw_n_addr))
                                             ? ((0x18U 
                                                 >= 
                                                 (0x1fU 
                                                  & (IData)(vlSelf->top__DOT__csw_n_addr)))
                                                 ? 
                                                vlSelf->top__DOT__csw_n__DOT__mem
                                                [(0x1fU 
                                                  & (IData)(vlSelf->top__DOT__csw_n_addr))]
                                                 : 0U)
                                             : 0U);
    }
    if (vlSelf->top__DOT__cse_n_write_en) {
        if ((0x19U > (IData)(vlSelf->top__DOT__cse_n_addr))) {
            vlSelf->top__DOT__cse_n__DOT____Vlvbound_h1fbfd826__0 
                = vlSelf->top__DOT__cse_n_data_in;
            if ((0x18U >= (0x1fU & (IData)(vlSelf->top__DOT__cse_n_addr)))) {
                __Vdlyvval__top__DOT__cse_n__DOT__mem__v0 
                    = vlSelf->top__DOT__cse_n__DOT____Vlvbound_h1fbfd826__0;
                __Vdlyvset__top__DOT__cse_n__DOT__mem__v0 = 1U;
                __Vdlyvdim0__top__DOT__cse_n__DOT__mem__v0 
                    = (0x1fU & (IData)(vlSelf->top__DOT__cse_n_addr));
            }
        }
        vlSelf->top__DOT__cse_n_data_out = ((0x18U 
                                             >= (0x1fU 
                                                 & (IData)(vlSelf->top__DOT__cse_n_addr)))
                                             ? vlSelf->top__DOT__cse_n__DOT__mem
                                            [(0x1fU 
                                              & (IData)(vlSelf->top__DOT__cse_n_addr))]
                                             : 0U);
    } else {
        vlSelf->top__DOT__cse_n_data_out = ((0x19U 
                                             > (IData)(vlSelf->top__DOT__cse_n_addr))
                                             ? ((0x18U 
                                                 >= 
                                                 (0x1fU 
                                                  & (IData)(vlSelf->top__DOT__cse_n_addr)))
                                                 ? 
                                                vlSelf->top__DOT__cse_n__DOT__mem
                                                [(0x1fU 
                                                  & (IData)(vlSelf->top__DOT__cse_n_addr))]
                                                 : 0U)
                                             : 0U);
    }
    if (vlSelf->top__DOT__ce_n_write_en) {
        if ((0x19U > (IData)(vlSelf->top__DOT__ce_n_addr))) {
            vlSelf->top__DOT__ce_n__DOT____Vlvbound_h1fbfd826__0 
                = vlSelf->top__DOT__ce_n_data_in;
            if ((0x18U >= (0x1fU & (IData)(vlSelf->top__DOT__ce_n_addr)))) {
                __Vdlyvval__top__DOT__ce_n__DOT__mem__v0 
                    = vlSelf->top__DOT__ce_n__DOT____Vlvbound_h1fbfd826__0;
                __Vdlyvset__top__DOT__ce_n__DOT__mem__v0 = 1U;
                __Vdlyvdim0__top__DOT__ce_n__DOT__mem__v0 
                    = (0x1fU & (IData)(vlSelf->top__DOT__ce_n_addr));
            }
        }
        vlSelf->top__DOT__ce_n_data_out = ((0x18U >= 
                                            (0x1fU 
                                             & (IData)(vlSelf->top__DOT__ce_n_addr)))
                                            ? vlSelf->top__DOT__ce_n__DOT__mem
                                           [(0x1fU 
                                             & (IData)(vlSelf->top__DOT__ce_n_addr))]
                                            : 0U);
    } else {
        vlSelf->top__DOT__ce_n_data_out = ((0x19U > (IData)(vlSelf->top__DOT__ce_n_addr))
                                            ? ((0x18U 
                                                >= 
                                                (0x1fU 
                                                 & (IData)(vlSelf->top__DOT__ce_n_addr)))
                                                ? vlSelf->top__DOT__ce_n__DOT__mem
                                               [(0x1fU 
                                                 & (IData)(vlSelf->top__DOT__ce_n_addr))]
                                                : 0U)
                                            : 0U);
    }
    if (vlSelf->top__DOT__cne_n_write_en) {
        if ((0x19U > (IData)(vlSelf->top__DOT__cne_n_addr))) {
            vlSelf->top__DOT__cne_n__DOT____Vlvbound_h1fbfd826__0 
                = vlSelf->top__DOT__cne_n_data_in;
            if ((0x18U >= (0x1fU & (IData)(vlSelf->top__DOT__cne_n_addr)))) {
                __Vdlyvval__top__DOT__cne_n__DOT__mem__v0 
                    = vlSelf->top__DOT__cne_n__DOT____Vlvbound_h1fbfd826__0;
                __Vdlyvset__top__DOT__cne_n__DOT__mem__v0 = 1U;
                __Vdlyvdim0__top__DOT__cne_n__DOT__mem__v0 
                    = (0x1fU & (IData)(vlSelf->top__DOT__cne_n_addr));
            }
        }
        vlSelf->top__DOT__cne_n_data_out = ((0x18U 
                                             >= (0x1fU 
                                                 & (IData)(vlSelf->top__DOT__cne_n_addr)))
                                             ? vlSelf->top__DOT__cne_n__DOT__mem
                                            [(0x1fU 
                                              & (IData)(vlSelf->top__DOT__cne_n_addr))]
                                             : 0U);
    } else {
        vlSelf->top__DOT__cne_n_data_out = ((0x19U 
                                             > (IData)(vlSelf->top__DOT__cne_n_addr))
                                             ? ((0x18U 
                                                 >= 
                                                 (0x1fU 
                                                  & (IData)(vlSelf->top__DOT__cne_n_addr)))
                                                 ? 
                                                vlSelf->top__DOT__cne_n__DOT__mem
                                                [(0x1fU 
                                                  & (IData)(vlSelf->top__DOT__cne_n_addr))]
                                                 : 0U)
                                             : 0U);
    }
    if (vlSelf->top__DOT__c0_n_write_en) {
        if ((0x19U > (IData)(vlSelf->top__DOT__c0_n_addr))) {
            vlSelf->top__DOT__c0_n__DOT____Vlvbound_h1fbfd826__0 
                = vlSelf->top__DOT__c0_n_data_in;
            if ((0x18U >= (0x1fU & (IData)(vlSelf->top__DOT__c0_n_addr)))) {
                __Vdlyvval__top__DOT__c0_n__DOT__mem__v0 
                    = vlSelf->top__DOT__c0_n__DOT____Vlvbound_h1fbfd826__0;
                __Vdlyvset__top__DOT__c0_n__DOT__mem__v0 = 1U;
                __Vdlyvdim0__top__DOT__c0_n__DOT__mem__v0 
                    = (0x1fU & (IData)(vlSelf->top__DOT__c0_n_addr));
            }
        }
        vlSelf->top__DOT__c0_n_data_out = ((0x18U >= 
                                            (0x1fU 
                                             & (IData)(vlSelf->top__DOT__c0_n_addr)))
                                            ? vlSelf->top__DOT__c0_n__DOT__mem
                                           [(0x1fU 
                                             & (IData)(vlSelf->top__DOT__c0_n_addr))]
                                            : 0U);
    } else {
        vlSelf->top__DOT__c0_n_data_out = ((0x19U > (IData)(vlSelf->top__DOT__c0_n_addr))
                                            ? ((0x18U 
                                                >= 
                                                (0x1fU 
                                                 & (IData)(vlSelf->top__DOT__c0_n_addr)))
                                                ? vlSelf->top__DOT__c0_n__DOT__mem
                                               [(0x1fU 
                                                 & (IData)(vlSelf->top__DOT__c0_n_addr))]
                                                : 0U)
                                            : 0U);
    }
    if (vlSelf->top__DOT__cs_n_write_en) {
        if ((0x19U > (IData)(vlSelf->top__DOT__cs_n_addr))) {
            vlSelf->top__DOT__cs_n__DOT____Vlvbound_h1fbfd826__0 
                = vlSelf->top__DOT__cs_n_data_in;
            if ((0x18U >= (0x1fU & (IData)(vlSelf->top__DOT__cs_n_addr)))) {
                __Vdlyvval__top__DOT__cs_n__DOT__mem__v0 
                    = vlSelf->top__DOT__cs_n__DOT____Vlvbound_h1fbfd826__0;
                __Vdlyvset__top__DOT__cs_n__DOT__mem__v0 = 1U;
                __Vdlyvdim0__top__DOT__cs_n__DOT__mem__v0 
                    = (0x1fU & (IData)(vlSelf->top__DOT__cs_n_addr));
            }
        }
        vlSelf->top__DOT__cs_n_data_out = ((0x18U >= 
                                            (0x1fU 
                                             & (IData)(vlSelf->top__DOT__cs_n_addr)))
                                            ? vlSelf->top__DOT__cs_n__DOT__mem
                                           [(0x1fU 
                                             & (IData)(vlSelf->top__DOT__cs_n_addr))]
                                            : 0U);
    } else {
        vlSelf->top__DOT__cs_n_data_out = ((0x19U > (IData)(vlSelf->top__DOT__cs_n_addr))
                                            ? ((0x18U 
                                                >= 
                                                (0x1fU 
                                                 & (IData)(vlSelf->top__DOT__cs_n_addr)))
                                                ? vlSelf->top__DOT__cs_n__DOT__mem
                                               [(0x1fU 
                                                 & (IData)(vlSelf->top__DOT__cs_n_addr))]
                                                : 0U)
                                            : 0U);
    }
    if (__Vdlyvset__top__DOT__cnw__DOT__mem__v0) {
        vlSelf->top__DOT__cnw__DOT__mem[__Vdlyvdim0__top__DOT__cnw__DOT__mem__v0] 
            = __Vdlyvval__top__DOT__cnw__DOT__mem__v0;
    }
    if (__Vdlyvset__top__DOT__cw__DOT__mem__v0) {
        vlSelf->top__DOT__cw__DOT__mem[__Vdlyvdim0__top__DOT__cw__DOT__mem__v0] 
            = __Vdlyvval__top__DOT__cw__DOT__mem__v0;
    }
    if (__Vdlyvset__top__DOT__csw__DOT__mem__v0) {
        vlSelf->top__DOT__csw__DOT__mem[__Vdlyvdim0__top__DOT__csw__DOT__mem__v0] 
            = __Vdlyvval__top__DOT__csw__DOT__mem__v0;
    }
    if (__Vdlyvset__top__DOT__cs__DOT__mem__v0) {
        vlSelf->top__DOT__cs__DOT__mem[__Vdlyvdim0__top__DOT__cs__DOT__mem__v0] 
            = __Vdlyvval__top__DOT__cs__DOT__mem__v0;
    }
    if (__Vdlyvset__top__DOT__cse__DOT__mem__v0) {
        vlSelf->top__DOT__cse__DOT__mem[__Vdlyvdim0__top__DOT__cse__DOT__mem__v0] 
            = __Vdlyvval__top__DOT__cse__DOT__mem__v0;
    }
    if (__Vdlyvset__top__DOT__ce__DOT__mem__v0) {
        vlSelf->top__DOT__ce__DOT__mem[__Vdlyvdim0__top__DOT__ce__DOT__mem__v0] 
            = __Vdlyvval__top__DOT__ce__DOT__mem__v0;
    }
    if (__Vdlyvset__top__DOT__cne__DOT__mem__v0) {
        vlSelf->top__DOT__cne__DOT__mem[__Vdlyvdim0__top__DOT__cne__DOT__mem__v0] 
            = __Vdlyvval__top__DOT__cne__DOT__mem__v0;
    }
    if (__Vdlyvset__top__DOT__cn__DOT__mem__v0) {
        vlSelf->top__DOT__cn__DOT__mem[__Vdlyvdim0__top__DOT__cn__DOT__mem__v0] 
            = __Vdlyvval__top__DOT__cn__DOT__mem__v0;
    }
    if (__Vdlyvset__top__DOT__c0__DOT__mem__v0) {
        vlSelf->top__DOT__c0__DOT__mem[__Vdlyvdim0__top__DOT__c0__DOT__mem__v0] 
            = __Vdlyvval__top__DOT__c0__DOT__mem__v0;
    }
    if (__Vdlyvset__top__DOT__c0_n__DOT__mem__v0) {
        vlSelf->top__DOT__c0_n__DOT__mem[__Vdlyvdim0__top__DOT__c0_n__DOT__mem__v0] 
            = __Vdlyvval__top__DOT__c0_n__DOT__mem__v0;
    }
    if (__Vdlyvset__top__DOT__cs_n__DOT__mem__v0) {
        vlSelf->top__DOT__cs_n__DOT__mem[__Vdlyvdim0__top__DOT__cs_n__DOT__mem__v0] 
            = __Vdlyvval__top__DOT__cs_n__DOT__mem__v0;
    }
    if (__Vdlyvset__top__DOT__cn_n__DOT__mem__v0) {
        vlSelf->top__DOT__cn_n__DOT__mem[__Vdlyvdim0__top__DOT__cn_n__DOT__mem__v0] 
            = __Vdlyvval__top__DOT__cn_n__DOT__mem__v0;
    }
    if (__Vdlyvset__top__DOT__cw_n__DOT__mem__v0) {
        vlSelf->top__DOT__cw_n__DOT__mem[__Vdlyvdim0__top__DOT__cw_n__DOT__mem__v0] 
            = __Vdlyvval__top__DOT__cw_n__DOT__mem__v0;
    }
    if (__Vdlyvset__top__DOT__ce_n__DOT__mem__v0) {
        vlSelf->top__DOT__ce_n__DOT__mem[__Vdlyvdim0__top__DOT__ce_n__DOT__mem__v0] 
            = __Vdlyvval__top__DOT__ce_n__DOT__mem__v0;
    }
    if (__Vdlyvset__top__DOT__cnw_n__DOT__mem__v0) {
        vlSelf->top__DOT__cnw_n__DOT__mem[__Vdlyvdim0__top__DOT__cnw_n__DOT__mem__v0] 
            = __Vdlyvval__top__DOT__cnw_n__DOT__mem__v0;
    }
    if (__Vdlyvset__top__DOT__csw_n__DOT__mem__v0) {
        vlSelf->top__DOT__csw_n__DOT__mem[__Vdlyvdim0__top__DOT__csw_n__DOT__mem__v0] 
            = __Vdlyvval__top__DOT__csw_n__DOT__mem__v0;
    }
    if (__Vdlyvset__top__DOT__cse_n__DOT__mem__v0) {
        vlSelf->top__DOT__cse_n__DOT__mem[__Vdlyvdim0__top__DOT__cse_n__DOT__mem__v0] 
            = __Vdlyvval__top__DOT__cse_n__DOT__mem__v0;
    }
    if (__Vdlyvset__top__DOT__cne_n__DOT__mem__v0) {
        vlSelf->top__DOT__cne_n__DOT__mem[__Vdlyvdim0__top__DOT__cne_n__DOT__mem__v0] 
            = __Vdlyvval__top__DOT__cne_n__DOT__mem__v0;
    }
    vlSelf->rho = (0xffffU & (((((((((IData)(vlSelf->top__DOT__c0_n_data_out) 
                                     + (IData)(vlSelf->top__DOT__cn_n_data_out)) 
                                    + (IData)(vlSelf->top__DOT__cne_n_data_out)) 
                                   + (IData)(vlSelf->top__DOT__ce_n_data_out)) 
                                  + (IData)(vlSelf->top__DOT__cse_n_data_out)) 
                                 + (IData)(vlSelf->top__DOT__cs_n_data_out)) 
                                + (IData)(vlSelf->top__DOT__csw_n_data_out)) 
                               + (IData)(vlSelf->top__DOT__cw_n_data_out)) 
                              + (IData)(vlSelf->top__DOT__cnw_n_data_out)));
    vlSelf->top__DOT__lbm__DOT__collider__DOT__x2 = 
        VL_MULS_III(32, ((IData)(0x4000U) - VL_EXTENDS_II(32,16, (IData)(vlSelf->rho))), 
                    ((IData)(0x4000U) - VL_SHIFTRS_III(32,32,32, 
                                                       VL_MULS_III(32, 
                                                                   VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
                                                                   ((IData)(0x4000U) 
                                                                    - 
                                                                    VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)))), 0xdU)));
    vlSelf->top__DOT__lbm__DOT__collider__DOT__x3 = 
        VL_MULS_III(32, VL_SHIFTRS_III(32,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x2, 0xdU), 
                    ((IData)(0x4000U) - VL_SHIFTRS_III(32,32,32, 
                                                       VL_MULS_III(32, 
                                                                   VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
                                                                   VL_SHIFTRS_III(32,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x2, 0xdU)), 0xdU)));
    vlSelf->u_x = (0xffffU & VL_SHIFTRS_III(16,32,32, 
                                            VL_MULS_III(32, 
                                                        VL_EXTENDS_II(32,16, 
                                                                      (0xffffU 
                                                                       & ((((((IData)(vlSelf->top__DOT__ce_n_data_out) 
                                                                              - (IData)(vlSelf->top__DOT__cw_n_data_out)) 
                                                                             + (IData)(vlSelf->top__DOT__cne_n_data_out)) 
                                                                            - (IData)(vlSelf->top__DOT__csw_n_data_out)) 
                                                                           - (IData)(vlSelf->top__DOT__cnw_n_data_out)) 
                                                                          + (IData)(vlSelf->top__DOT__cse_n_data_out)))), 
                                                        VL_SHIFTRS_III(32,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x3, 0xdU)), 0xdU));
    vlSelf->u_y = (0xffffU & VL_SHIFTRS_III(16,32,32, 
                                            VL_MULS_III(32, 
                                                        VL_EXTENDS_II(32,16, 
                                                                      (0xffffU 
                                                                       & ((((((IData)(vlSelf->top__DOT__cn_n_data_out) 
                                                                              - (IData)(vlSelf->top__DOT__cs_n_data_out)) 
                                                                             + (IData)(vlSelf->top__DOT__cne_n_data_out)) 
                                                                            - (IData)(vlSelf->top__DOT__csw_n_data_out)) 
                                                                           + (IData)(vlSelf->top__DOT__cnw_n_data_out)) 
                                                                          - (IData)(vlSelf->top__DOT__cse_n_data_out)))), 
                                                        VL_SHIFTRS_III(32,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x3, 0xdU)), 0xdU));
    vlSelf->top__DOT__lbm__DOT__collider__DOT__u_x_squared_intermediate 
        = VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->u_x)), 
                      VL_EXTENDS_II(32,16, (IData)(vlSelf->u_x)));
    vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y 
        = (0xffffU & ((IData)(vlSelf->u_x) + (IData)(vlSelf->u_y)));
    vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y 
        = (0xffffU & ((IData)(vlSelf->u_x) - (IData)(vlSelf->u_y)));
    vlSelf->top__DOT__lbm__DOT__collider__DOT__u_y_squared_intermediate 
        = VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->u_y)), 
                      VL_EXTENDS_II(32,16, (IData)(vlSelf->u_y)));
    vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y_squared_intermediate 
        = VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y)), 
                      VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y)));
    vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y_squared_intermediate 
        = VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y)), 
                      VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y)));
    vlSelf->u_squared = (0xffffU & (VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__u_x_squared_intermediate, 0xdU) 
                                    + VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__u_y_squared_intermediate, 0xdU)));
}

VL_INLINE_OPT void Vdut___024root___sequent__TOP__2(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___sequent__TOP__2\n"); );
    // Body
    if (vlSelf->rst) {
        vlSelf->top__DOT__cnw_write_en = vlSelf->top__DOT__lbm__DOT__cnw_next_write_en;
        vlSelf->top__DOT__cnw_data_in = vlSelf->top__DOT__lbm__DOT__cnw_next_data_in;
        vlSelf->top__DOT__cw_write_en = vlSelf->top__DOT__lbm__DOT__cw_next_write_en;
        vlSelf->top__DOT__cw_data_in = vlSelf->top__DOT__lbm__DOT__cw_next_data_in;
        vlSelf->top__DOT__csw_write_en = vlSelf->top__DOT__lbm__DOT__csw_next_write_en;
        vlSelf->top__DOT__csw_data_in = vlSelf->top__DOT__lbm__DOT__csw_next_data_in;
        vlSelf->top__DOT__cs_write_en = vlSelf->top__DOT__lbm__DOT__cs_next_write_en;
        vlSelf->top__DOT__cs_data_in = vlSelf->top__DOT__lbm__DOT__cs_next_data_in;
        vlSelf->top__DOT__cse_write_en = vlSelf->top__DOT__lbm__DOT__cse_next_write_en;
        vlSelf->top__DOT__cse_data_in = vlSelf->top__DOT__lbm__DOT__cse_next_data_in;
        vlSelf->top__DOT__ce_write_en = vlSelf->top__DOT__lbm__DOT__ce_next_write_en;
        vlSelf->top__DOT__ce_data_in = vlSelf->top__DOT__lbm__DOT__ce_next_data_in;
        vlSelf->top__DOT__cne_write_en = vlSelf->top__DOT__lbm__DOT__cne_next_write_en;
        vlSelf->top__DOT__cne_data_in = vlSelf->top__DOT__lbm__DOT__cne_next_data_in;
        vlSelf->top__DOT__cn_n_data_in = vlSelf->top__DOT__lbm__DOT__cn_next_data_in;
        vlSelf->top__DOT__cn_write_en = vlSelf->top__DOT__lbm__DOT__cn_next_write_en;
        vlSelf->top__DOT__cn_data_in = vlSelf->top__DOT__lbm__DOT__cn_next_data_in;
        vlSelf->top__DOT__cnw_n_data_in = vlSelf->top__DOT__lbm__DOT__cnw_next_data_in;
        vlSelf->top__DOT__cw_n_data_in = vlSelf->top__DOT__lbm__DOT__cw_next_data_in;
        vlSelf->top__DOT__csw_n_data_in = vlSelf->top__DOT__lbm__DOT__csw_next_data_in;
        vlSelf->top__DOT__cse_n_data_in = vlSelf->top__DOT__lbm__DOT__cse_next_data_in;
        vlSelf->top__DOT__ce_n_data_in = vlSelf->top__DOT__lbm__DOT__ce_next_data_in;
        vlSelf->top__DOT__cne_n_data_in = vlSelf->top__DOT__lbm__DOT__cne_next_data_in;
        vlSelf->top__DOT__c0_n_data_in = vlSelf->top__DOT__lbm__DOT__c0_next_data_in;
        vlSelf->top__DOT__cs_n_data_in = vlSelf->top__DOT__lbm__DOT__cs_next_data_in;
        if (vlSelf->top__DOT__lbm__DOT__c0_next_write_en) {
            vlSelf->top__DOT__c0_write_en = 1U;
            vlSelf->top__DOT__c0_data_in = vlSelf->top__DOT__lbm__DOT__c0_next_data_in;
            vlSelf->top__DOT__c0_n_write_en = vlSelf->top__DOT__lbm__DOT__c0_n_next_write_en;
            vlSelf->top__DOT__cs_n_write_en = vlSelf->top__DOT__lbm__DOT__cs_n_next_write_en;
            vlSelf->top__DOT__cn_n_write_en = vlSelf->top__DOT__lbm__DOT__cn_n_next_write_en;
            vlSelf->top__DOT__cw_n_write_en = vlSelf->top__DOT__lbm__DOT__cw_n_next_write_en;
            vlSelf->top__DOT__ce_n_write_en = vlSelf->top__DOT__lbm__DOT__ce_n_next_write_en;
            vlSelf->top__DOT__cnw_n_write_en = vlSelf->top__DOT__lbm__DOT__cnw_n_next_write_en;
            vlSelf->top__DOT__csw_n_write_en = vlSelf->top__DOT__lbm__DOT__csw_n_next_write_en;
            vlSelf->top__DOT__cse_n_write_en = vlSelf->top__DOT__lbm__DOT__cse_n_next_write_en;
            vlSelf->top__DOT__cne_n_write_en = vlSelf->top__DOT__lbm__DOT__cne_n_next_write_en;
            vlSelf->top__DOT__c0_addr = vlSelf->top__DOT__lbm__DOT__c0_next_write_addr;
        } else {
            vlSelf->top__DOT__c0_write_en = 0U;
            vlSelf->top__DOT__c0_data_in = vlSelf->top__DOT__lbm__DOT__c0_next_data_in;
            vlSelf->top__DOT__c0_n_write_en = vlSelf->top__DOT__lbm__DOT__c0_n_next_write_en;
            vlSelf->top__DOT__cs_n_write_en = vlSelf->top__DOT__lbm__DOT__cs_n_next_write_en;
            vlSelf->top__DOT__cn_n_write_en = vlSelf->top__DOT__lbm__DOT__cn_n_next_write_en;
            vlSelf->top__DOT__cw_n_write_en = vlSelf->top__DOT__lbm__DOT__cw_n_next_write_en;
            vlSelf->top__DOT__ce_n_write_en = vlSelf->top__DOT__lbm__DOT__ce_n_next_write_en;
            vlSelf->top__DOT__cnw_n_write_en = vlSelf->top__DOT__lbm__DOT__cnw_n_next_write_en;
            vlSelf->top__DOT__csw_n_write_en = vlSelf->top__DOT__lbm__DOT__csw_n_next_write_en;
            vlSelf->top__DOT__cse_n_write_en = vlSelf->top__DOT__lbm__DOT__cse_n_next_write_en;
            vlSelf->top__DOT__cne_n_write_en = vlSelf->top__DOT__lbm__DOT__cne_n_next_write_en;
            vlSelf->top__DOT__c0_addr = vlSelf->top__DOT__lbm__DOT__index;
        }
        vlSelf->top__DOT__c0_n_addr = ((IData)(vlSelf->top__DOT__lbm__DOT__c0_n_next_write_en)
                                        ? (IData)(vlSelf->top__DOT__lbm__DOT__c0_next_write_addr)
                                        : (IData)(vlSelf->top__DOT__lbm__DOT__index));
        vlSelf->top__DOT__cn_addr = ((IData)(vlSelf->top__DOT__lbm__DOT__cn_next_write_en)
                                      ? (IData)(vlSelf->top__DOT__lbm__DOT__cn_next_write_addr)
                                      : (IData)(vlSelf->top__DOT__lbm__DOT__index));
        vlSelf->top__DOT__cn_n_addr = ((IData)(vlSelf->top__DOT__lbm__DOT__cn_n_next_write_en)
                                        ? (IData)(vlSelf->top__DOT__lbm__DOT__cn_next_write_addr)
                                        : (IData)(vlSelf->top__DOT__lbm__DOT__index));
        vlSelf->top__DOT__cne_addr = ((IData)(vlSelf->top__DOT__lbm__DOT__cne_next_write_en)
                                       ? (IData)(vlSelf->top__DOT__lbm__DOT__cne_next_write_addr)
                                       : (IData)(vlSelf->top__DOT__lbm__DOT__index));
        vlSelf->top__DOT__cne_n_addr = ((IData)(vlSelf->top__DOT__lbm__DOT__cne_n_next_write_en)
                                         ? (IData)(vlSelf->top__DOT__lbm__DOT__cne_next_write_addr)
                                         : (IData)(vlSelf->top__DOT__lbm__DOT__index));
        vlSelf->top__DOT__ce_addr = ((IData)(vlSelf->top__DOT__lbm__DOT__ce_next_write_en)
                                      ? (IData)(vlSelf->top__DOT__lbm__DOT__ce_next_write_addr)
                                      : (IData)(vlSelf->top__DOT__lbm__DOT__index));
        vlSelf->top__DOT__ce_n_addr = ((IData)(vlSelf->top__DOT__lbm__DOT__ce_n_next_write_en)
                                        ? (IData)(vlSelf->top__DOT__lbm__DOT__ce_next_write_addr)
                                        : (IData)(vlSelf->top__DOT__lbm__DOT__index));
        vlSelf->top__DOT__cse_addr = ((IData)(vlSelf->top__DOT__lbm__DOT__cse_next_write_en)
                                       ? (IData)(vlSelf->top__DOT__lbm__DOT__cse_next_write_addr)
                                       : (IData)(vlSelf->top__DOT__lbm__DOT__index));
        vlSelf->top__DOT__cse_n_addr = ((IData)(vlSelf->top__DOT__lbm__DOT__cse_n_next_write_en)
                                         ? (IData)(vlSelf->top__DOT__lbm__DOT__cse_next_write_addr)
                                         : (IData)(vlSelf->top__DOT__lbm__DOT__index));
        vlSelf->top__DOT__cs_addr = ((IData)(vlSelf->top__DOT__lbm__DOT__cs_next_write_en)
                                      ? (IData)(vlSelf->top__DOT__lbm__DOT__cs_next_write_addr)
                                      : (IData)(vlSelf->top__DOT__lbm__DOT__index));
        vlSelf->top__DOT__cs_n_addr = ((IData)(vlSelf->top__DOT__lbm__DOT__cs_n_next_write_en)
                                        ? (IData)(vlSelf->top__DOT__lbm__DOT__cs_next_write_addr)
                                        : (IData)(vlSelf->top__DOT__lbm__DOT__index));
        vlSelf->top__DOT__csw_addr = ((IData)(vlSelf->top__DOT__lbm__DOT__csw_next_write_en)
                                       ? (IData)(vlSelf->top__DOT__lbm__DOT__csw_next_write_addr)
                                       : (IData)(vlSelf->top__DOT__lbm__DOT__index));
        vlSelf->top__DOT__csw_n_addr = ((IData)(vlSelf->top__DOT__lbm__DOT__csw_n_next_write_en)
                                         ? (IData)(vlSelf->top__DOT__lbm__DOT__csw_next_write_addr)
                                         : (IData)(vlSelf->top__DOT__lbm__DOT__index));
        vlSelf->top__DOT__cw_addr = ((IData)(vlSelf->top__DOT__lbm__DOT__cw_next_write_en)
                                      ? (IData)(vlSelf->top__DOT__lbm__DOT__cw_next_write_addr)
                                      : (IData)(vlSelf->top__DOT__lbm__DOT__index));
        vlSelf->top__DOT__cw_n_addr = ((IData)(vlSelf->top__DOT__lbm__DOT__cw_n_next_write_en)
                                        ? (IData)(vlSelf->top__DOT__lbm__DOT__cw_next_write_addr)
                                        : (IData)(vlSelf->top__DOT__lbm__DOT__index));
        vlSelf->top__DOT__cnw_addr = ((IData)(vlSelf->top__DOT__lbm__DOT__cnw_next_write_en)
                                       ? (IData)(vlSelf->top__DOT__lbm__DOT__cnw_next_write_addr)
                                       : (IData)(vlSelf->top__DOT__lbm__DOT__index));
        vlSelf->top__DOT__cnw_n_addr = ((IData)(vlSelf->top__DOT__lbm__DOT__cnw_n_next_write_en)
                                         ? (IData)(vlSelf->top__DOT__lbm__DOT__cnw_next_write_addr)
                                         : (IData)(vlSelf->top__DOT__lbm__DOT__index));
        vlSelf->top__DOT__lbm__DOT__index = vlSelf->top__DOT__lbm__DOT__next_index;
    } else {
        vlSelf->top__DOT__lbm__DOT__index = 0U;
    }
    vlSelf->testing_cs_n_data_in = vlSelf->top__DOT__cs_n_data_in;
    vlSelf->testing_c0_data_in = vlSelf->top__DOT__c0_data_in;
    vlSelf->top__DOT__lbm__DOT__incr_step = 0U;
    vlSelf->top__DOT__lbm__DOT__ce_next_write_en = 0U;
    vlSelf->top__DOT__lbm__DOT__cnw_next_write_en = 0U;
    vlSelf->top__DOT__lbm__DOT__cw_next_write_en = 0U;
    vlSelf->top__DOT__lbm__DOT__cne_next_write_en = 0U;
    vlSelf->top__DOT__lbm__DOT__cn_next_write_en = 0U;
    vlSelf->top__DOT__lbm__DOT__c0_next_write_en = 0U;
    vlSelf->top__DOT__lbm__DOT__cse_next_write_en = 0U;
    vlSelf->top__DOT__lbm__DOT__cs_next_write_en = 0U;
    vlSelf->top__DOT__lbm__DOT__csw_next_write_en = 0U;
    if ((8U & (IData)(vlSelf->top__DOT__lbm__DOT__sim_state))) {
        if ((1U & (~ ((IData)(vlSelf->top__DOT__lbm__DOT__sim_state) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlSelf->top__DOT__lbm__DOT__sim_state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlSelf->top__DOT__lbm__DOT__sim_state)))) {
                    if ((0U >= (IData)(vlSelf->top__DOT__lbm__DOT__ram_wait_count))) {
                        if ((0x18U == (IData)(vlSelf->top__DOT__lbm__DOT__index))) {
                            vlSelf->top__DOT__lbm__DOT__incr_step = 1U;
                        }
                    }
                }
                if ((1U & (IData)(vlSelf->top__DOT__lbm__DOT__sim_state))) {
                    vlSelf->top__DOT__lbm__DOT__ce_next_write_en = 1U;
                    vlSelf->top__DOT__lbm__DOT__cnw_next_write_en = 1U;
                    vlSelf->top__DOT__lbm__DOT__cw_next_write_en = 1U;
                    vlSelf->top__DOT__lbm__DOT__cne_next_write_en = 1U;
                    vlSelf->top__DOT__lbm__DOT__cn_next_write_en = 1U;
                    vlSelf->top__DOT__lbm__DOT__c0_next_write_en = 1U;
                    vlSelf->top__DOT__lbm__DOT__cse_next_write_en = 1U;
                    vlSelf->top__DOT__lbm__DOT__cs_next_write_en = 1U;
                    vlSelf->top__DOT__lbm__DOT__csw_next_write_en = 1U;
                } else if ((0U >= (IData)(vlSelf->top__DOT__lbm__DOT__ram_wait_count))) {
                    if (((((5U <= (IData)(vlSelf->top__DOT__lbm__DOT__index)) 
                           & (0x13U >= (IData)(vlSelf->top__DOT__lbm__DOT__index))) 
                          & (0U != (IData)(vlSelf->top__DOT__lbm__DOT__width_count))) 
                         & (4U != (IData)(vlSelf->top__DOT__lbm__DOT__width_count)))) {
                        vlSelf->top__DOT__lbm__DOT__ce_next_write_en = 1U;
                        vlSelf->top__DOT__lbm__DOT__cnw_next_write_en = 1U;
                        vlSelf->top__DOT__lbm__DOT__cw_next_write_en = 1U;
                        vlSelf->top__DOT__lbm__DOT__cne_next_write_en = 1U;
                        vlSelf->top__DOT__lbm__DOT__cn_next_write_en = 1U;
                        vlSelf->top__DOT__lbm__DOT__c0_next_write_en = 1U;
                        vlSelf->top__DOT__lbm__DOT__cse_next_write_en = 1U;
                        vlSelf->top__DOT__lbm__DOT__cs_next_write_en = 1U;
                        vlSelf->top__DOT__lbm__DOT__csw_next_write_en = 1U;
                    }
                }
            }
        }
    }
}

VL_INLINE_OPT void Vdut___024root___combo__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->top__DOT__lbm__DOT__c_cn = (0xffffU & (
                                                   VL_EXTENDS_II(16,16, (IData)(vlSelf->top__DOT__cn_n_data_out)) 
                                                   + 
                                                   VL_SHIFTRS_III(16,32,32, 
                                                                  VL_MULS_III(32, 
                                                                              VL_EXTENDS_II(32,16, (IData)(vlSelf->omega)), 
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
                                                                               - 
                                                                               VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__cn_n_data_out)))), 0xdU)));
    vlSelf->top__DOT__lbm__DOT__c_cne = (0xffffU & 
                                         (VL_EXTENDS_II(16,16, (IData)(vlSelf->top__DOT__cne_n_data_out)) 
                                          + VL_SHIFTRS_III(16,32,32, 
                                                           VL_MULS_III(32, 
                                                                       VL_EXTENDS_II(32,16, (IData)(vlSelf->omega)), 
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
                                                                        - 
                                                                        VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__cne_n_data_out)))), 0xdU)));
    vlSelf->top__DOT__lbm__DOT__c_ce = (0xffffU & (
                                                   VL_EXTENDS_II(16,16, (IData)(vlSelf->top__DOT__ce_n_data_out)) 
                                                   + 
                                                   VL_SHIFTRS_III(16,32,32, 
                                                                  VL_MULS_III(32, 
                                                                              VL_EXTENDS_II(32,16, (IData)(vlSelf->omega)), 
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
                                                                               - 
                                                                               VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__ce_n_data_out)))), 0xdU)));
    vlSelf->top__DOT__lbm__DOT__c_cse = (0xffffU & 
                                         (VL_EXTENDS_II(16,16, (IData)(vlSelf->top__DOT__cse_n_data_out)) 
                                          + VL_SHIFTRS_III(16,32,32, 
                                                           VL_MULS_III(32, 
                                                                       VL_EXTENDS_II(32,16, (IData)(vlSelf->omega)), 
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
                                                                        - 
                                                                        VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__cse_n_data_out)))), 0xdU)));
    vlSelf->top__DOT__lbm__DOT__c_cs = (0xffffU & (
                                                   VL_EXTENDS_II(16,16, (IData)(vlSelf->top__DOT__cs_n_data_out)) 
                                                   + 
                                                   VL_SHIFTRS_III(16,32,32, 
                                                                  VL_MULS_III(32, 
                                                                              VL_EXTENDS_II(32,16, (IData)(vlSelf->omega)), 
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
                                                                               - 
                                                                               VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__cs_n_data_out)))), 0xdU)));
    vlSelf->top__DOT__lbm__DOT__c_csw = (0xffffU & 
                                         (VL_EXTENDS_II(16,16, (IData)(vlSelf->top__DOT__csw_n_data_out)) 
                                          + VL_SHIFTRS_III(16,32,32, 
                                                           VL_MULS_III(32, 
                                                                       VL_EXTENDS_II(32,16, (IData)(vlSelf->omega)), 
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
                                                                        - 
                                                                        VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__csw_n_data_out)))), 0xdU)));
    vlSelf->top__DOT__lbm__DOT__c_cw = (0xffffU & (
                                                   VL_EXTENDS_II(16,16, (IData)(vlSelf->top__DOT__cw_n_data_out)) 
                                                   + 
                                                   VL_SHIFTRS_III(16,32,32, 
                                                                  VL_MULS_III(32, 
                                                                              VL_EXTENDS_II(32,16, (IData)(vlSelf->omega)), 
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
                                                                               - 
                                                                               VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__cw_n_data_out)))), 0xdU)));
    vlSelf->top__DOT__lbm__DOT__c_cnw = (0xffffU & 
                                         (VL_EXTENDS_II(16,16, (IData)(vlSelf->top__DOT__cnw_n_data_out)) 
                                          + VL_SHIFTRS_III(16,32,32, 
                                                           VL_MULS_III(32, 
                                                                       VL_EXTENDS_II(32,16, (IData)(vlSelf->omega)), 
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
                                                                        - 
                                                                        VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__cnw_n_data_out)))), 0xdU)));
    vlSelf->top__DOT__lbm__DOT__cn_n_next_write_en = 0U;
    vlSelf->top__DOT__lbm__DOT__c0_n_next_write_en = 0U;
    vlSelf->top__DOT__lbm__DOT__cs_n_next_write_en = 0U;
    vlSelf->top__DOT__lbm__DOT__ce_next_write_addr = 0U;
    vlSelf->top__DOT__lbm__DOT__cnw_n_next_write_en = 0U;
    vlSelf->top__DOT__lbm__DOT__cnw_next_write_addr = 0U;
    vlSelf->top__DOT__lbm__DOT__cw_n_next_write_en = 0U;
    vlSelf->top__DOT__lbm__DOT__cne_n_next_write_en = 0U;
    vlSelf->top__DOT__lbm__DOT__cne_next_write_addr = 0U;
    vlSelf->top__DOT__lbm__DOT__cn_next_write_addr = 0U;
    vlSelf->top__DOT__lbm__DOT__c0_next_write_addr = 0U;
    vlSelf->top__DOT__lbm__DOT__ce_n_next_write_en = 0U;
    vlSelf->top__DOT__lbm__DOT__cse_next_write_addr = 0U;
    vlSelf->top__DOT__lbm__DOT__cse_n_next_write_en = 0U;
    vlSelf->top__DOT__lbm__DOT__cs_next_write_addr = 0U;
    vlSelf->top__DOT__lbm__DOT__csw_next_write_addr = 0U;
    vlSelf->top__DOT__lbm__DOT__csw_n_next_write_en = 0U;
    vlSelf->top__DOT__lbm__DOT__cw_next_write_addr = 0U;
    vlSelf->top__DOT__lbm__DOT__next_width_count = vlSelf->top__DOT__lbm__DOT__width_count;
    vlSelf->top__DOT__lbm__DOT__next_ram_wait_count 
        = vlSelf->top__DOT__lbm__DOT__ram_wait_count;
    vlSelf->top__DOT__lbm__DOT__next_index = vlSelf->top__DOT__lbm__DOT__index;
    vlSelf->top__DOT__lbm__DOT__cn_next_data_in = 0U;
    vlSelf->top__DOT__lbm__DOT__cne_next_data_in = 0U;
    vlSelf->top__DOT__lbm__DOT__ce_next_data_in = 0U;
    vlSelf->top__DOT__lbm__DOT__cse_next_data_in = 0U;
    vlSelf->top__DOT__lbm__DOT__cs_next_data_in = 0U;
    vlSelf->top__DOT__lbm__DOT__csw_next_data_in = 0U;
    vlSelf->top__DOT__lbm__DOT__cw_next_data_in = 0U;
    vlSelf->top__DOT__lbm__DOT__cnw_next_data_in = 0U;
    vlSelf->top__DOT__lbm__DOT__c0_next_data_in = 0U;
    if ((8U & (IData)(vlSelf->top__DOT__lbm__DOT__sim_state))) {
        if ((1U & (~ ((IData)(vlSelf->top__DOT__lbm__DOT__sim_state) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlSelf->top__DOT__lbm__DOT__sim_state) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSelf->top__DOT__lbm__DOT__sim_state))) {
                    vlSelf->top__DOT__lbm__DOT__cn_n_next_write_en = 1U;
                    vlSelf->top__DOT__lbm__DOT__c0_n_next_write_en = 1U;
                    vlSelf->top__DOT__lbm__DOT__cs_n_next_write_en = 1U;
                    vlSelf->top__DOT__lbm__DOT__ce_next_write_addr 
                        = vlSelf->top__DOT__lbm__DOT__index;
                    vlSelf->top__DOT__lbm__DOT__cnw_n_next_write_en = 1U;
                    vlSelf->top__DOT__lbm__DOT__cnw_next_write_addr 
                        = vlSelf->top__DOT__lbm__DOT__index;
                    vlSelf->top__DOT__lbm__DOT__cw_n_next_write_en = 1U;
                    vlSelf->top__DOT__lbm__DOT__cne_n_next_write_en = 1U;
                    vlSelf->top__DOT__lbm__DOT__cne_next_write_addr 
                        = vlSelf->top__DOT__lbm__DOT__index;
                    vlSelf->top__DOT__lbm__DOT__cn_next_write_addr 
                        = vlSelf->top__DOT__lbm__DOT__index;
                    vlSelf->top__DOT__lbm__DOT__c0_next_write_addr 
                        = vlSelf->top__DOT__lbm__DOT__index;
                    vlSelf->top__DOT__lbm__DOT__ce_n_next_write_en = 1U;
                    vlSelf->top__DOT__lbm__DOT__cse_next_write_addr 
                        = vlSelf->top__DOT__lbm__DOT__index;
                    vlSelf->top__DOT__lbm__DOT__cse_n_next_write_en = 1U;
                    vlSelf->top__DOT__lbm__DOT__cs_next_write_addr 
                        = vlSelf->top__DOT__lbm__DOT__index;
                    vlSelf->top__DOT__lbm__DOT__csw_next_write_addr 
                        = vlSelf->top__DOT__lbm__DOT__index;
                    vlSelf->top__DOT__lbm__DOT__csw_n_next_write_en = 1U;
                    vlSelf->top__DOT__lbm__DOT__cw_next_write_addr 
                        = vlSelf->top__DOT__lbm__DOT__index;
                    if ((0x18U == (IData)(vlSelf->top__DOT__lbm__DOT__index))) {
                        vlSelf->top__DOT__lbm__DOT__next_width_count 
                            = (0xffffU & 0U);
                        vlSelf->top__DOT__lbm__DOT__next_index 
                            = (0x1fffU & 0U);
                    } else {
                        vlSelf->top__DOT__lbm__DOT__next_width_count 
                            = (0xffffU & ((4U == (IData)(vlSelf->top__DOT__lbm__DOT__width_count))
                                           ? 0U : ((IData)(1U) 
                                                   + (IData)(vlSelf->top__DOT__lbm__DOT__width_count))));
                        vlSelf->top__DOT__lbm__DOT__next_index 
                            = (0x1fffU & ((IData)(1U) 
                                          + (IData)(vlSelf->top__DOT__lbm__DOT__index)));
                    }
                    if (((0x18U >= (0x1fU & (IData)(vlSelf->top__DOT__lbm__DOT__index))) 
                         & (vlSelf->barriers >> (0x1fU 
                                                 & (IData)(vlSelf->top__DOT__lbm__DOT__index))))) {
                        vlSelf->top__DOT__lbm__DOT__cn_next_data_in = 0U;
                        vlSelf->top__DOT__lbm__DOT__cne_next_data_in = 0U;
                        vlSelf->top__DOT__lbm__DOT__ce_next_data_in = 0U;
                        vlSelf->top__DOT__lbm__DOT__cse_next_data_in = 0U;
                        vlSelf->top__DOT__lbm__DOT__cs_next_data_in = 0U;
                        vlSelf->top__DOT__lbm__DOT__csw_next_data_in = 0U;
                        vlSelf->top__DOT__lbm__DOT__cw_next_data_in = 0U;
                        vlSelf->top__DOT__lbm__DOT__cnw_next_data_in = 0U;
                        vlSelf->top__DOT__lbm__DOT__c0_next_data_in = 0U;
                    } else {
                        vlSelf->top__DOT__lbm__DOT__cn_next_data_in 
                            = (0xffffU & (IData)(vlSelf->init_cn));
                        vlSelf->top__DOT__lbm__DOT__cne_next_data_in 
                            = (0xffffU & (IData)(vlSelf->init_cne));
                        vlSelf->top__DOT__lbm__DOT__ce_next_data_in 
                            = (0xffffU & (IData)(vlSelf->init_ce));
                        vlSelf->top__DOT__lbm__DOT__cse_next_data_in 
                            = (0xffffU & (IData)(vlSelf->init_cse));
                        vlSelf->top__DOT__lbm__DOT__cs_next_data_in 
                            = (0xffffU & (IData)(vlSelf->init_cs));
                        vlSelf->top__DOT__lbm__DOT__csw_next_data_in 
                            = (0xffffU & (IData)(vlSelf->init_csw));
                        vlSelf->top__DOT__lbm__DOT__cw_next_data_in 
                            = (0xffffU & (IData)(vlSelf->init_cw));
                        vlSelf->top__DOT__lbm__DOT__cnw_next_data_in 
                            = (0xffffU & (IData)(vlSelf->init_cnw));
                        vlSelf->top__DOT__lbm__DOT__c0_next_data_in 
                            = (0xffffU & (IData)(vlSelf->init_c0));
                    }
                } else {
                    if ((0U >= (IData)(vlSelf->top__DOT__lbm__DOT__ram_wait_count))) {
                        if (((((5U <= (IData)(vlSelf->top__DOT__lbm__DOT__index)) 
                               & (0x13U >= (IData)(vlSelf->top__DOT__lbm__DOT__index))) 
                              & (0U != (IData)(vlSelf->top__DOT__lbm__DOT__width_count))) 
                             & (4U != (IData)(vlSelf->top__DOT__lbm__DOT__width_count)))) {
                            vlSelf->top__DOT__lbm__DOT__ce_next_write_addr 
                                = vlSelf->top__DOT__lbm__DOT__index;
                            vlSelf->top__DOT__lbm__DOT__cnw_next_write_addr 
                                = vlSelf->top__DOT__lbm__DOT__index;
                            vlSelf->top__DOT__lbm__DOT__cne_next_write_addr 
                                = vlSelf->top__DOT__lbm__DOT__index;
                            vlSelf->top__DOT__lbm__DOT__cn_next_write_addr 
                                = vlSelf->top__DOT__lbm__DOT__index;
                            vlSelf->top__DOT__lbm__DOT__c0_next_write_addr 
                                = vlSelf->top__DOT__lbm__DOT__index;
                            vlSelf->top__DOT__lbm__DOT__cse_next_write_addr 
                                = vlSelf->top__DOT__lbm__DOT__index;
                            vlSelf->top__DOT__lbm__DOT__cs_next_write_addr 
                                = vlSelf->top__DOT__lbm__DOT__index;
                            vlSelf->top__DOT__lbm__DOT__csw_next_write_addr 
                                = vlSelf->top__DOT__lbm__DOT__index;
                            vlSelf->top__DOT__lbm__DOT__cw_next_write_addr 
                                = vlSelf->top__DOT__lbm__DOT__index;
                            if (((0x18U >= (0x1fU & (IData)(vlSelf->top__DOT__lbm__DOT__index))) 
                                 & (vlSelf->barriers 
                                    >> (0x1fU & (IData)(vlSelf->top__DOT__lbm__DOT__index))))) {
                                vlSelf->top__DOT__lbm__DOT__cn_next_data_in = 0U;
                                vlSelf->top__DOT__lbm__DOT__cne_next_data_in = 0U;
                                vlSelf->top__DOT__lbm__DOT__ce_next_data_in = 0U;
                                vlSelf->top__DOT__lbm__DOT__cse_next_data_in = 0U;
                                vlSelf->top__DOT__lbm__DOT__cs_next_data_in = 0U;
                                vlSelf->top__DOT__lbm__DOT__csw_next_data_in = 0U;
                                vlSelf->top__DOT__lbm__DOT__cw_next_data_in = 0U;
                                vlSelf->top__DOT__lbm__DOT__cnw_next_data_in = 0U;
                                vlSelf->top__DOT__lbm__DOT__c0_next_data_in = 0U;
                            } else {
                                vlSelf->top__DOT__lbm__DOT__cn_next_data_in 
                                    = (0xffffU & (IData)(vlSelf->top__DOT__lbm__DOT__c_cn));
                                vlSelf->top__DOT__lbm__DOT__cne_next_data_in 
                                    = (0xffffU & (IData)(vlSelf->top__DOT__lbm__DOT__c_cne));
                                vlSelf->top__DOT__lbm__DOT__ce_next_data_in 
                                    = (0xffffU & (IData)(vlSelf->top__DOT__lbm__DOT__c_ce));
                                vlSelf->top__DOT__lbm__DOT__cse_next_data_in 
                                    = (0xffffU & (IData)(vlSelf->top__DOT__lbm__DOT__c_cse));
                                vlSelf->top__DOT__lbm__DOT__cs_next_data_in 
                                    = (0xffffU & (IData)(vlSelf->top__DOT__lbm__DOT__c_cs));
                                vlSelf->top__DOT__lbm__DOT__csw_next_data_in 
                                    = (0xffffU & (IData)(vlSelf->top__DOT__lbm__DOT__c_csw));
                                vlSelf->top__DOT__lbm__DOT__cw_next_data_in 
                                    = (0xffffU & (IData)(vlSelf->top__DOT__lbm__DOT__c_cw));
                                vlSelf->top__DOT__lbm__DOT__cnw_next_data_in 
                                    = (0xffffU & (IData)(vlSelf->top__DOT__lbm__DOT__c_cnw));
                                vlSelf->top__DOT__lbm__DOT__c0_next_data_in 
                                    = (0xffffU & ((IData)(vlSelf->rho) 
                                                  - 
                                                  ((((((((IData)(vlSelf->top__DOT__lbm__DOT__c_cn) 
                                                         + (IData)(vlSelf->top__DOT__lbm__DOT__c_cne)) 
                                                        + (IData)(vlSelf->top__DOT__lbm__DOT__c_ce)) 
                                                       + (IData)(vlSelf->top__DOT__lbm__DOT__c_cse)) 
                                                      + (IData)(vlSelf->top__DOT__lbm__DOT__c_cs)) 
                                                     + (IData)(vlSelf->top__DOT__lbm__DOT__c_csw)) 
                                                    + (IData)(vlSelf->top__DOT__lbm__DOT__c_cw)) 
                                                   + (IData)(vlSelf->top__DOT__lbm__DOT__c_cnw))));
                            }
                        }
                    }
                    if ((0U < (IData)(vlSelf->top__DOT__lbm__DOT__ram_wait_count))) {
                        vlSelf->top__DOT__lbm__DOT__next_width_count 
                            = (0xffffU & (IData)(vlSelf->top__DOT__lbm__DOT__width_count));
                        vlSelf->top__DOT__lbm__DOT__next_index 
                            = (0x1fffU & (IData)(vlSelf->top__DOT__lbm__DOT__index));
                    } else if ((0x18U == (IData)(vlSelf->top__DOT__lbm__DOT__index))) {
                        vlSelf->top__DOT__lbm__DOT__next_width_count 
                            = (0xffffU & 0U);
                        vlSelf->top__DOT__lbm__DOT__next_index 
                            = (0x1fffU & 0U);
                    } else {
                        vlSelf->top__DOT__lbm__DOT__next_width_count 
                            = (0xffffU & ((4U == (IData)(vlSelf->top__DOT__lbm__DOT__width_count))
                                           ? 0U : ((IData)(1U) 
                                                   + (IData)(vlSelf->top__DOT__lbm__DOT__width_count))));
                        vlSelf->top__DOT__lbm__DOT__next_index 
                            = (0x1fffU & ((IData)(1U) 
                                          + (IData)(vlSelf->top__DOT__lbm__DOT__index)));
                    }
                }
            }
        }
        if ((4U & (IData)(vlSelf->top__DOT__lbm__DOT__sim_state))) {
            vlSelf->top__DOT__lbm__DOT__next_sim_state = 0U;
            vlSelf->top__DOT__lbm__DOT__next_ram_wait_count = 0U;
        } else if ((2U & (IData)(vlSelf->top__DOT__lbm__DOT__sim_state))) {
            vlSelf->top__DOT__lbm__DOT__next_sim_state = 0U;
            vlSelf->top__DOT__lbm__DOT__next_ram_wait_count = 0U;
        } else {
            vlSelf->top__DOT__lbm__DOT__next_sim_state 
                = ((1U & (IData)(vlSelf->top__DOT__lbm__DOT__sim_state))
                    ? ((0x18U == (IData)(vlSelf->top__DOT__lbm__DOT__index))
                        ? 0U : 9U) : ((0U < (IData)(vlSelf->top__DOT__lbm__DOT__ram_wait_count))
                                       ? 8U : ((0x18U 
                                                == (IData)(vlSelf->top__DOT__lbm__DOT__index))
                                                ? 0U
                                                : 8U)));
            if ((1U & (~ (IData)(vlSelf->top__DOT__lbm__DOT__sim_state)))) {
                if ((0U < (IData)(vlSelf->top__DOT__lbm__DOT__ram_wait_count))) {
                    vlSelf->top__DOT__lbm__DOT__next_ram_wait_count 
                        = (7U & ((IData)(vlSelf->top__DOT__lbm__DOT__ram_wait_count) 
                                 - (IData)(1U)));
                } else if ((0x18U != (IData)(vlSelf->top__DOT__lbm__DOT__index))) {
                    vlSelf->top__DOT__lbm__DOT__next_ram_wait_count = 2U;
                }
            }
        }
    } else if ((4U & (IData)(vlSelf->top__DOT__lbm__DOT__sim_state))) {
        if ((2U & (IData)(vlSelf->top__DOT__lbm__DOT__sim_state))) {
            if ((1U & (IData)(vlSelf->top__DOT__lbm__DOT__sim_state))) {
                if (((0x18U >= (0x1fU & (IData)(vlSelf->top__DOT__lbm__DOT__index))) 
                     & (vlSelf->barriers >> (0x1fU 
                                             & (IData)(vlSelf->top__DOT__lbm__DOT__index))))) {
                    vlSelf->top__DOT__lbm__DOT__cn_n_next_write_en = 1U;
                    vlSelf->top__DOT__lbm__DOT__c0_n_next_write_en = 1U;
                    vlSelf->top__DOT__lbm__DOT__cs_n_next_write_en = 1U;
                    vlSelf->top__DOT__lbm__DOT__ce_next_write_addr 
                        = vlSelf->top__DOT__lbm__DOT__index;
                    vlSelf->top__DOT__lbm__DOT__cnw_n_next_write_en = 1U;
                    vlSelf->top__DOT__lbm__DOT__cnw_next_write_addr 
                        = vlSelf->top__DOT__lbm__DOT__index;
                    vlSelf->top__DOT__lbm__DOT__cw_n_next_write_en = 1U;
                    vlSelf->top__DOT__lbm__DOT__cne_n_next_write_en = 1U;
                    vlSelf->top__DOT__lbm__DOT__cne_next_write_addr 
                        = vlSelf->top__DOT__lbm__DOT__index;
                    vlSelf->top__DOT__lbm__DOT__cn_next_write_addr 
                        = vlSelf->top__DOT__lbm__DOT__index;
                    vlSelf->top__DOT__lbm__DOT__c0_next_write_addr 
                        = vlSelf->top__DOT__lbm__DOT__index;
                    vlSelf->top__DOT__lbm__DOT__ce_n_next_write_en = 1U;
                    vlSelf->top__DOT__lbm__DOT__cse_next_write_addr 
                        = vlSelf->top__DOT__lbm__DOT__index;
                    vlSelf->top__DOT__lbm__DOT__cse_n_next_write_en = 1U;
                    vlSelf->top__DOT__lbm__DOT__cs_next_write_addr 
                        = vlSelf->top__DOT__lbm__DOT__index;
                    vlSelf->top__DOT__lbm__DOT__csw_next_write_addr 
                        = vlSelf->top__DOT__lbm__DOT__index;
                    vlSelf->top__DOT__lbm__DOT__csw_n_next_write_en = 1U;
                    vlSelf->top__DOT__lbm__DOT__cw_next_write_addr 
                        = vlSelf->top__DOT__lbm__DOT__index;
                    vlSelf->top__DOT__lbm__DOT__cn_next_data_in = 0U;
                    vlSelf->top__DOT__lbm__DOT__cne_next_data_in = 0U;
                    vlSelf->top__DOT__lbm__DOT__ce_next_data_in = 0U;
                    vlSelf->top__DOT__lbm__DOT__cse_next_data_in = 0U;
                    vlSelf->top__DOT__lbm__DOT__cs_next_data_in = 0U;
                    vlSelf->top__DOT__lbm__DOT__csw_next_data_in = 0U;
                    vlSelf->top__DOT__lbm__DOT__cw_next_data_in = 0U;
                    vlSelf->top__DOT__lbm__DOT__cnw_next_data_in = 0U;
                    vlSelf->top__DOT__lbm__DOT__c0_next_data_in = 0U;
                }
                if ((0x18U == (IData)(vlSelf->top__DOT__lbm__DOT__index))) {
                    vlSelf->top__DOT__lbm__DOT__next_width_count 
                        = (0xffffU & 0U);
                    vlSelf->top__DOT__lbm__DOT__next_sim_state = 8U;
                    vlSelf->top__DOT__lbm__DOT__next_index 
                        = (0x1fffU & 0U);
                } else {
                    vlSelf->top__DOT__lbm__DOT__next_width_count 
                        = (0xffffU & ((4U == (IData)(vlSelf->top__DOT__lbm__DOT__width_count))
                                       ? 0U : ((IData)(1U) 
                                               + (IData)(vlSelf->top__DOT__lbm__DOT__width_count))));
                    vlSelf->top__DOT__lbm__DOT__next_sim_state = 7U;
                    vlSelf->top__DOT__lbm__DOT__next_index 
                        = (0x1fffU & ((IData)(1U) + (IData)(vlSelf->top__DOT__lbm__DOT__index)));
                }
            } else {
                if ((0U >= (IData)(vlSelf->top__DOT__lbm__DOT__ram_wait_count))) {
                    vlSelf->top__DOT__lbm__DOT__cn_n_next_write_en 
                        = (5U <= (IData)(vlSelf->top__DOT__lbm__DOT__index));
                    vlSelf->top__DOT__lbm__DOT__cs_n_next_write_en 
                        = (0x13U >= (IData)(vlSelf->top__DOT__lbm__DOT__index));
                    vlSelf->top__DOT__lbm__DOT__ce_next_write_addr 
                        = (0x1fffU & ((IData)(1U) + (IData)(vlSelf->top__DOT__lbm__DOT__index)));
                    vlSelf->top__DOT__lbm__DOT__cnw_n_next_write_en 
                        = ((5U <= (IData)(vlSelf->top__DOT__lbm__DOT__index)) 
                           & (0U != (IData)(vlSelf->top__DOT__lbm__DOT__width_count)));
                    vlSelf->top__DOT__lbm__DOT__cnw_next_write_addr 
                        = (0x1fffU & (((IData)(vlSelf->top__DOT__lbm__DOT__index) 
                                       - (IData)(5U)) 
                                      - (IData)(1U)));
                    vlSelf->top__DOT__lbm__DOT__cw_n_next_write_en 
                        = (0U != (IData)(vlSelf->top__DOT__lbm__DOT__width_count));
                    vlSelf->top__DOT__lbm__DOT__cne_n_next_write_en 
                        = ((5U <= (IData)(vlSelf->top__DOT__lbm__DOT__index)) 
                           & (4U != (IData)(vlSelf->top__DOT__lbm__DOT__width_count)));
                    vlSelf->top__DOT__lbm__DOT__cne_next_write_addr 
                        = (0x1fffU & ((IData)(1U) + 
                                      ((IData)(vlSelf->top__DOT__lbm__DOT__index) 
                                       - (IData)(5U))));
                    vlSelf->top__DOT__lbm__DOT__cn_next_write_addr 
                        = (0x1fffU & ((IData)(vlSelf->top__DOT__lbm__DOT__index) 
                                      - (IData)(5U)));
                    vlSelf->top__DOT__lbm__DOT__ce_n_next_write_en 
                        = (4U != (IData)(vlSelf->top__DOT__lbm__DOT__width_count));
                    vlSelf->top__DOT__lbm__DOT__cse_next_write_addr 
                        = (0x1fffU & ((IData)(6U) + (IData)(vlSelf->top__DOT__lbm__DOT__index)));
                    vlSelf->top__DOT__lbm__DOT__cse_n_next_write_en 
                        = ((0x13U >= (IData)(vlSelf->top__DOT__lbm__DOT__index)) 
                           & (4U != (IData)(vlSelf->top__DOT__lbm__DOT__width_count)));
                    vlSelf->top__DOT__lbm__DOT__cs_next_write_addr 
                        = (0x1fffU & ((IData)(5U) + (IData)(vlSelf->top__DOT__lbm__DOT__index)));
                    vlSelf->top__DOT__lbm__DOT__csw_next_write_addr 
                        = (0x1fffU & ((IData)(4U) + (IData)(vlSelf->top__DOT__lbm__DOT__index)));
                    vlSelf->top__DOT__lbm__DOT__csw_n_next_write_en 
                        = ((0x13U >= (IData)(vlSelf->top__DOT__lbm__DOT__index)) 
                           & (0U != (IData)(vlSelf->top__DOT__lbm__DOT__width_count)));
                    vlSelf->top__DOT__lbm__DOT__cw_next_write_addr 
                        = (0x1fffU & ((IData)(vlSelf->top__DOT__lbm__DOT__index) 
                                      - (IData)(1U)));
                    vlSelf->top__DOT__lbm__DOT__cn_next_data_in 
                        = vlSelf->top__DOT__cs_n_data_out;
                    vlSelf->top__DOT__lbm__DOT__cne_next_data_in 
                        = vlSelf->top__DOT__csw_n_data_out;
                    vlSelf->top__DOT__lbm__DOT__ce_next_data_in 
                        = vlSelf->top__DOT__cw_n_data_out;
                    vlSelf->top__DOT__lbm__DOT__cse_next_data_in 
                        = vlSelf->top__DOT__cnw_n_data_out;
                    vlSelf->top__DOT__lbm__DOT__cs_next_data_in 
                        = vlSelf->top__DOT__cn_n_data_out;
                    vlSelf->top__DOT__lbm__DOT__csw_next_data_in 
                        = vlSelf->top__DOT__cne_n_data_out;
                    vlSelf->top__DOT__lbm__DOT__cw_next_data_in 
                        = vlSelf->top__DOT__ce_n_data_out;
                    vlSelf->top__DOT__lbm__DOT__cnw_next_data_in 
                        = vlSelf->top__DOT__cse_n_data_out;
                }
                if ((0U < (IData)(vlSelf->top__DOT__lbm__DOT__ram_wait_count))) {
                    vlSelf->top__DOT__lbm__DOT__next_width_count 
                        = (0xffffU & (IData)(vlSelf->top__DOT__lbm__DOT__width_count));
                    vlSelf->top__DOT__lbm__DOT__next_sim_state = 6U;
                    vlSelf->top__DOT__lbm__DOT__next_index 
                        = (0x1fffU & (IData)(vlSelf->top__DOT__lbm__DOT__index));
                } else if ((0xcU != (IData)(vlSelf->top__DOT__lbm__DOT__index))) {
                    if ((2U == (IData)(vlSelf->top__DOT__lbm__DOT__width_count))) {
                        vlSelf->top__DOT__lbm__DOT__next_width_count 
                            = (0xffffU & 2U);
                        vlSelf->top__DOT__lbm__DOT__next_index 
                            = (0x1fffU & ((IData)(5U) 
                                          + (IData)(vlSelf->top__DOT__lbm__DOT__index)));
                    } else {
                        vlSelf->top__DOT__lbm__DOT__next_width_count 
                            = (0xffffU & ((IData)(1U) 
                                          + (IData)(vlSelf->top__DOT__lbm__DOT__width_count)));
                        vlSelf->top__DOT__lbm__DOT__next_index 
                            = (0x1fffU & ((IData)(1U) 
                                          + (IData)(vlSelf->top__DOT__lbm__DOT__index)));
                    }
                    vlSelf->top__DOT__lbm__DOT__next_sim_state = 5U;
                } else {
                    vlSelf->top__DOT__lbm__DOT__next_width_count 
                        = (0xffffU & 0U);
                    vlSelf->top__DOT__lbm__DOT__next_sim_state = 7U;
                    vlSelf->top__DOT__lbm__DOT__next_index 
                        = (0x1fffU & 0U);
                }
            }
            if ((1U & (~ (IData)(vlSelf->top__DOT__lbm__DOT__sim_state)))) {
                if ((0U < (IData)(vlSelf->top__DOT__lbm__DOT__ram_wait_count))) {
                    vlSelf->top__DOT__lbm__DOT__next_ram_wait_count 
                        = (7U & ((IData)(vlSelf->top__DOT__lbm__DOT__ram_wait_count) 
                                 - (IData)(1U)));
                }
            }
        } else if ((1U & (IData)(vlSelf->top__DOT__lbm__DOT__sim_state))) {
            if ((1U & (~ ((0x18U >= (0x1fU & (IData)(vlSelf->top__DOT__lbm__DOT__index))) 
                          & (vlSelf->barriers >> (0x1fU 
                                                  & (IData)(vlSelf->top__DOT__lbm__DOT__index))))))) {
                vlSelf->top__DOT__lbm__DOT__next_width_count 
                    = ((0xcU == (IData)(vlSelf->top__DOT__lbm__DOT__index))
                        ? 0U : ((2U == (IData)(vlSelf->top__DOT__lbm__DOT__width_count))
                                 ? 2U : (0xffffU & 
                                         ((IData)(1U) 
                                          + (IData)(vlSelf->top__DOT__lbm__DOT__width_count)))));
            }
            if (((0x18U >= (0x1fU & (IData)(vlSelf->top__DOT__lbm__DOT__index))) 
                 & (vlSelf->barriers >> (0x1fU & (IData)(vlSelf->top__DOT__lbm__DOT__index))))) {
                vlSelf->top__DOT__lbm__DOT__next_sim_state = 6U;
                vlSelf->top__DOT__lbm__DOT__next_ram_wait_count = 2U;
                vlSelf->top__DOT__lbm__DOT__next_index 
                    = (0x1fffU & (IData)(vlSelf->top__DOT__lbm__DOT__index));
            } else if ((0xcU == (IData)(vlSelf->top__DOT__lbm__DOT__index))) {
                vlSelf->top__DOT__lbm__DOT__next_sim_state = 7U;
                vlSelf->top__DOT__lbm__DOT__next_index 
                    = (0x1fffU & 0U);
            } else {
                vlSelf->top__DOT__lbm__DOT__next_sim_state = 5U;
                vlSelf->top__DOT__lbm__DOT__next_index 
                    = (0x1fffU & ((2U == (IData)(vlSelf->top__DOT__lbm__DOT__width_count))
                                   ? ((IData)(5U) + (IData)(vlSelf->top__DOT__lbm__DOT__index))
                                   : ((IData)(1U) + (IData)(vlSelf->top__DOT__lbm__DOT__index))));
            }
        } else {
            vlSelf->top__DOT__lbm__DOT__next_sim_state = 0U;
            vlSelf->top__DOT__lbm__DOT__next_ram_wait_count = 0U;
        }
    } else if ((2U & (IData)(vlSelf->top__DOT__lbm__DOT__sim_state))) {
        if ((1U & (IData)(vlSelf->top__DOT__lbm__DOT__sim_state))) {
            if ((0U >= (IData)(vlSelf->top__DOT__lbm__DOT__ram_wait_count))) {
                if ((8U != (IData)(vlSelf->top__DOT__lbm__DOT__index))) {
                    if ((0x12U == (IData)(vlSelf->top__DOT__lbm__DOT__index))) {
                        vlSelf->top__DOT__lbm__DOT__cn_n_next_write_en = 1U;
                        vlSelf->top__DOT__lbm__DOT__cnw_n_next_write_en = 1U;
                        vlSelf->top__DOT__lbm__DOT__cnw_next_write_addr = 0x18U;
                        vlSelf->top__DOT__lbm__DOT__cn_next_write_addr = 0x17U;
                        vlSelf->top__DOT__lbm__DOT__cn_next_data_in 
                            = vlSelf->top__DOT__cn_data_out;
                        vlSelf->top__DOT__lbm__DOT__cnw_next_data_in 
                            = vlSelf->top__DOT__cnw_data_out;
                    } else if ((0x10U == (IData)(vlSelf->top__DOT__lbm__DOT__index))) {
                        vlSelf->top__DOT__lbm__DOT__cn_n_next_write_en = 1U;
                        vlSelf->top__DOT__lbm__DOT__cn_next_write_addr = 0x15U;
                        vlSelf->top__DOT__lbm__DOT__cn_next_data_in 
                            = vlSelf->top__DOT__cn_data_out;
                    } else if ((6U != (IData)(vlSelf->top__DOT__lbm__DOT__index))) {
                        if ((1U & (~ ((6U < (IData)(vlSelf->top__DOT__lbm__DOT__index)) 
                                      & (8U > (IData)(vlSelf->top__DOT__lbm__DOT__index)))))) {
                            if (((0x10U < (IData)(vlSelf->top__DOT__lbm__DOT__index)) 
                                 & (0x12U > (IData)(vlSelf->top__DOT__lbm__DOT__index)))) {
                                vlSelf->top__DOT__lbm__DOT__cn_n_next_write_en = 1U;
                                vlSelf->top__DOT__lbm__DOT__cn_next_write_addr 
                                    = (0x1fffU & ((IData)(vlSelf->top__DOT__lbm__DOT__index) 
                                                  - (IData)(5U)));
                                vlSelf->top__DOT__lbm__DOT__cn_next_data_in 
                                    = vlSelf->top__DOT__cn_data_out;
                            }
                        }
                    }
                    if ((0x12U != (IData)(vlSelf->top__DOT__lbm__DOT__index))) {
                        if ((0x10U == (IData)(vlSelf->top__DOT__lbm__DOT__index))) {
                            vlSelf->top__DOT__lbm__DOT__ce_next_write_addr = 0xfU;
                            vlSelf->top__DOT__lbm__DOT__cne_n_next_write_en = 1U;
                            vlSelf->top__DOT__lbm__DOT__cne_next_write_addr = 0x14U;
                            vlSelf->top__DOT__lbm__DOT__ce_n_next_write_en = 1U;
                            vlSelf->top__DOT__lbm__DOT__cne_next_data_in 
                                = vlSelf->top__DOT__cne_data_out;
                            vlSelf->top__DOT__lbm__DOT__ce_next_data_in 
                                = vlSelf->top__DOT__ce_data_out;
                        } else if ((6U == (IData)(vlSelf->top__DOT__lbm__DOT__index))) {
                            vlSelf->top__DOT__lbm__DOT__ce_next_write_addr = 5U;
                            vlSelf->top__DOT__lbm__DOT__ce_n_next_write_en = 1U;
                            vlSelf->top__DOT__lbm__DOT__ce_next_data_in 
                                = vlSelf->top__DOT__ce_data_out;
                        } else if ((1U & (~ ((6U < (IData)(vlSelf->top__DOT__lbm__DOT__index)) 
                                             & (8U 
                                                > (IData)(vlSelf->top__DOT__lbm__DOT__index)))))) {
                            if ((1U & (~ ((0x10U < (IData)(vlSelf->top__DOT__lbm__DOT__index)) 
                                          & (0x12U 
                                             > (IData)(vlSelf->top__DOT__lbm__DOT__index)))))) {
                                if ((1U == (IData)(vlSelf->top__DOT__lbm__DOT__width_count))) {
                                    vlSelf->top__DOT__lbm__DOT__ce_next_write_addr 
                                        = (0x1fffU 
                                           & ((IData)(vlSelf->top__DOT__lbm__DOT__index) 
                                              - (IData)(1U)));
                                    vlSelf->top__DOT__lbm__DOT__ce_n_next_write_en = 1U;
                                    vlSelf->top__DOT__lbm__DOT__ce_next_data_in 
                                        = vlSelf->top__DOT__ce_data_out;
                                }
                            }
                        }
                        if ((0x10U != (IData)(vlSelf->top__DOT__lbm__DOT__index))) {
                            if ((6U == (IData)(vlSelf->top__DOT__lbm__DOT__index))) {
                                vlSelf->top__DOT__lbm__DOT__cse_next_write_addr = 0U;
                                vlSelf->top__DOT__lbm__DOT__cse_n_next_write_en = 1U;
                                vlSelf->top__DOT__lbm__DOT__cse_next_data_in 
                                    = vlSelf->top__DOT__cse_data_out;
                            }
                        }
                    }
                }
                if ((8U == (IData)(vlSelf->top__DOT__lbm__DOT__index))) {
                    vlSelf->top__DOT__lbm__DOT__cs_n_next_write_en = 1U;
                    vlSelf->top__DOT__lbm__DOT__cw_n_next_write_en = 1U;
                    vlSelf->top__DOT__lbm__DOT__cs_next_write_addr = 3U;
                    vlSelf->top__DOT__lbm__DOT__csw_next_write_addr = 4U;
                    vlSelf->top__DOT__lbm__DOT__csw_n_next_write_en = 1U;
                    vlSelf->top__DOT__lbm__DOT__cw_next_write_addr = 9U;
                    vlSelf->top__DOT__lbm__DOT__cs_next_data_in 
                        = vlSelf->top__DOT__cs_data_out;
                    vlSelf->top__DOT__lbm__DOT__csw_next_data_in 
                        = vlSelf->top__DOT__csw_data_out;
                    vlSelf->top__DOT__lbm__DOT__cw_next_data_in 
                        = vlSelf->top__DOT__cw_data_out;
                } else {
                    if ((0x12U != (IData)(vlSelf->top__DOT__lbm__DOT__index))) {
                        if ((0x10U != (IData)(vlSelf->top__DOT__lbm__DOT__index))) {
                            if ((6U == (IData)(vlSelf->top__DOT__lbm__DOT__index))) {
                                vlSelf->top__DOT__lbm__DOT__cs_n_next_write_en = 1U;
                                vlSelf->top__DOT__lbm__DOT__cs_next_write_addr = 1U;
                                vlSelf->top__DOT__lbm__DOT__cs_next_data_in 
                                    = vlSelf->top__DOT__cs_data_out;
                            } else if (((6U < (IData)(vlSelf->top__DOT__lbm__DOT__index)) 
                                        & (8U > (IData)(vlSelf->top__DOT__lbm__DOT__index)))) {
                                vlSelf->top__DOT__lbm__DOT__cs_n_next_write_en = 1U;
                                vlSelf->top__DOT__lbm__DOT__cs_next_write_addr 
                                    = (0x1fffU & ((IData)(vlSelf->top__DOT__lbm__DOT__index) 
                                                  - (IData)(5U)));
                                vlSelf->top__DOT__lbm__DOT__cs_next_data_in 
                                    = vlSelf->top__DOT__cs_data_out;
                            }
                        }
                    }
                    if ((0x12U == (IData)(vlSelf->top__DOT__lbm__DOT__index))) {
                        vlSelf->top__DOT__lbm__DOT__cw_n_next_write_en = 1U;
                        vlSelf->top__DOT__lbm__DOT__cw_next_write_addr = 0x13U;
                        vlSelf->top__DOT__lbm__DOT__cw_next_data_in 
                            = vlSelf->top__DOT__cw_data_out;
                    } else if ((0x10U != (IData)(vlSelf->top__DOT__lbm__DOT__index))) {
                        if ((6U != (IData)(vlSelf->top__DOT__lbm__DOT__index))) {
                            if ((1U & (~ ((6U < (IData)(vlSelf->top__DOT__lbm__DOT__index)) 
                                          & (8U > (IData)(vlSelf->top__DOT__lbm__DOT__index)))))) {
                                if ((1U & (~ ((0x10U 
                                               < (IData)(vlSelf->top__DOT__lbm__DOT__index)) 
                                              & (0x12U 
                                                 > (IData)(vlSelf->top__DOT__lbm__DOT__index)))))) {
                                    if ((1U != (IData)(vlSelf->top__DOT__lbm__DOT__width_count))) {
                                        if ((3U == (IData)(vlSelf->top__DOT__lbm__DOT__width_count))) {
                                            vlSelf->top__DOT__lbm__DOT__cw_n_next_write_en = 1U;
                                            vlSelf->top__DOT__lbm__DOT__cw_next_write_addr 
                                                = (0x1fffU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelf->top__DOT__lbm__DOT__index)));
                                            vlSelf->top__DOT__lbm__DOT__cw_next_data_in 
                                                = vlSelf->top__DOT__cw_data_out;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if ((0U < (IData)(vlSelf->top__DOT__lbm__DOT__ram_wait_count))) {
                vlSelf->top__DOT__lbm__DOT__next_width_count 
                    = (0xffffU & (IData)(vlSelf->top__DOT__lbm__DOT__width_count));
                vlSelf->top__DOT__lbm__DOT__next_sim_state = 3U;
                vlSelf->top__DOT__lbm__DOT__next_ram_wait_count 
                    = (7U & ((IData)(vlSelf->top__DOT__lbm__DOT__ram_wait_count) 
                             - (IData)(1U)));
                vlSelf->top__DOT__lbm__DOT__next_index 
                    = (0x1fffU & (IData)(vlSelf->top__DOT__lbm__DOT__index));
            } else {
                if (((6U <= (IData)(vlSelf->top__DOT__lbm__DOT__index)) 
                     & (8U >= (IData)(vlSelf->top__DOT__lbm__DOT__index)))) {
                    if ((3U == (IData)(vlSelf->top__DOT__lbm__DOT__width_count))) {
                        vlSelf->top__DOT__lbm__DOT__next_width_count 
                            = (0xffffU & 1U);
                        vlSelf->top__DOT__lbm__DOT__next_index 
                            = (0x1fffU & ((IData)(3U) 
                                          + (IData)(vlSelf->top__DOT__lbm__DOT__index)));
                    } else {
                        vlSelf->top__DOT__lbm__DOT__next_width_count 
                            = (0xffffU & ((IData)(1U) 
                                          + (IData)(vlSelf->top__DOT__lbm__DOT__width_count)));
                        vlSelf->top__DOT__lbm__DOT__next_index 
                            = (0x1fffU & ((IData)(1U) 
                                          + (IData)(vlSelf->top__DOT__lbm__DOT__index)));
                    }
                    vlSelf->top__DOT__lbm__DOT__next_sim_state = 3U;
                } else if (((0x10U <= (IData)(vlSelf->top__DOT__lbm__DOT__index)) 
                            & (0x12U >= (IData)(vlSelf->top__DOT__lbm__DOT__index)))) {
                    if ((3U == (IData)(vlSelf->top__DOT__lbm__DOT__width_count))) {
                        vlSelf->top__DOT__lbm__DOT__next_width_count 
                            = (0xffffU & 2U);
                        vlSelf->top__DOT__lbm__DOT__next_sim_state = 5U;
                        vlSelf->top__DOT__lbm__DOT__next_index 
                            = (0x1fffU & 0xcU);
                    } else {
                        vlSelf->top__DOT__lbm__DOT__next_width_count 
                            = (0xffffU & ((IData)(1U) 
                                          + (IData)(vlSelf->top__DOT__lbm__DOT__width_count)));
                        vlSelf->top__DOT__lbm__DOT__next_sim_state = 3U;
                        vlSelf->top__DOT__lbm__DOT__next_index 
                            = (0x1fffU & ((IData)(1U) 
                                          + (IData)(vlSelf->top__DOT__lbm__DOT__index)));
                    }
                } else {
                    if ((3U == (IData)(vlSelf->top__DOT__lbm__DOT__width_count))) {
                        vlSelf->top__DOT__lbm__DOT__next_width_count 
                            = (0xffffU & 1U);
                        vlSelf->top__DOT__lbm__DOT__next_index 
                            = (0x1fffU & ((IData)(3U) 
                                          + (IData)(vlSelf->top__DOT__lbm__DOT__index)));
                    } else {
                        vlSelf->top__DOT__lbm__DOT__next_width_count 
                            = (0xffffU & 3U);
                        vlSelf->top__DOT__lbm__DOT__next_index 
                            = (0x1fffU & ((IData)(2U) 
                                          + (IData)(vlSelf->top__DOT__lbm__DOT__index)));
                    }
                    vlSelf->top__DOT__lbm__DOT__next_sim_state = 3U;
                }
                vlSelf->top__DOT__lbm__DOT__next_ram_wait_count = 2U;
                if ((1U & (~ ((6U <= (IData)(vlSelf->top__DOT__lbm__DOT__index)) 
                              & (8U >= (IData)(vlSelf->top__DOT__lbm__DOT__index)))))) {
                    if (((0x10U <= (IData)(vlSelf->top__DOT__lbm__DOT__index)) 
                         & (0x12U >= (IData)(vlSelf->top__DOT__lbm__DOT__index)))) {
                        vlSelf->top__DOT__lbm__DOT__next_ram_wait_count 
                            = ((3U == (IData)(vlSelf->top__DOT__lbm__DOT__width_count))
                                ? 2U : 0U);
                    }
                }
            }
        } else {
            if ((0U >= (IData)(vlSelf->top__DOT__lbm__DOT__ram_wait_count))) {
                vlSelf->top__DOT__lbm__DOT__cn_n_next_write_en = 1U;
                vlSelf->top__DOT__lbm__DOT__cs_n_next_write_en = 1U;
                vlSelf->top__DOT__lbm__DOT__ce_next_write_addr 
                    = (0x1fffU & ((IData)(1U) + (IData)(vlSelf->top__DOT__lbm__DOT__index)));
                vlSelf->top__DOT__lbm__DOT__cnw_n_next_write_en = 1U;
                vlSelf->top__DOT__lbm__DOT__cnw_next_write_addr 
                    = (0x1fffU & (((IData)(vlSelf->top__DOT__lbm__DOT__index) 
                                   - (IData)(1U)) - (IData)(5U)));
                vlSelf->top__DOT__lbm__DOT__cw_n_next_write_en = 1U;
                vlSelf->top__DOT__lbm__DOT__cne_n_next_write_en = 1U;
                vlSelf->top__DOT__lbm__DOT__cne_next_write_addr 
                    = (0x1fffU & ((IData)(1U) + ((IData)(vlSelf->top__DOT__lbm__DOT__index) 
                                                 - (IData)(5U))));
                vlSelf->top__DOT__lbm__DOT__cn_next_write_addr 
                    = (0x1fffU & ((IData)(vlSelf->top__DOT__lbm__DOT__index) 
                                  - (IData)(5U)));
                vlSelf->top__DOT__lbm__DOT__ce_n_next_write_en = 1U;
                vlSelf->top__DOT__lbm__DOT__cse_next_write_addr 
                    = (0x1fffU & ((IData)(6U) + (IData)(vlSelf->top__DOT__lbm__DOT__index)));
                vlSelf->top__DOT__lbm__DOT__cse_n_next_write_en = 1U;
                vlSelf->top__DOT__lbm__DOT__cs_next_write_addr 
                    = (0x1fffU & ((IData)(5U) + (IData)(vlSelf->top__DOT__lbm__DOT__index)));
                vlSelf->top__DOT__lbm__DOT__csw_next_write_addr 
                    = (0x1fffU & ((IData)(4U) + (IData)(vlSelf->top__DOT__lbm__DOT__index)));
                vlSelf->top__DOT__lbm__DOT__csw_n_next_write_en = 1U;
                vlSelf->top__DOT__lbm__DOT__cw_next_write_addr 
                    = (0x1fffU & ((IData)(vlSelf->top__DOT__lbm__DOT__index) 
                                  - (IData)(1U)));
                vlSelf->top__DOT__lbm__DOT__cn_next_data_in 
                    = vlSelf->top__DOT__cn_data_out;
                vlSelf->top__DOT__lbm__DOT__cne_next_data_in 
                    = vlSelf->top__DOT__cne_data_out;
                vlSelf->top__DOT__lbm__DOT__ce_next_data_in 
                    = vlSelf->top__DOT__ce_data_out;
                vlSelf->top__DOT__lbm__DOT__cse_next_data_in 
                    = vlSelf->top__DOT__cse_data_out;
                vlSelf->top__DOT__lbm__DOT__cs_next_data_in 
                    = vlSelf->top__DOT__cs_data_out;
                vlSelf->top__DOT__lbm__DOT__csw_next_data_in 
                    = vlSelf->top__DOT__csw_data_out;
                vlSelf->top__DOT__lbm__DOT__cw_next_data_in 
                    = vlSelf->top__DOT__cw_data_out;
                vlSelf->top__DOT__lbm__DOT__cnw_next_data_in 
                    = vlSelf->top__DOT__cnw_data_out;
            }
            if ((0U < (IData)(vlSelf->top__DOT__lbm__DOT__ram_wait_count))) {
                vlSelf->top__DOT__lbm__DOT__next_width_count 
                    = (0xffffU & (IData)(vlSelf->top__DOT__lbm__DOT__width_count));
                vlSelf->top__DOT__lbm__DOT__next_sim_state = 2U;
                vlSelf->top__DOT__lbm__DOT__next_ram_wait_count 
                    = (7U & ((IData)(vlSelf->top__DOT__lbm__DOT__ram_wait_count) 
                             - (IData)(1U)));
                vlSelf->top__DOT__lbm__DOT__next_index 
                    = (0x1fffU & (IData)(vlSelf->top__DOT__lbm__DOT__index));
            } else if ((0x12U == (IData)(vlSelf->top__DOT__lbm__DOT__index))) {
                vlSelf->top__DOT__lbm__DOT__next_width_count 
                    = (0xffffU & 1U);
                vlSelf->top__DOT__lbm__DOT__next_sim_state = 3U;
                vlSelf->top__DOT__lbm__DOT__next_index 
                    = (0x1fffU & 6U);
            } else {
                if ((3U == (IData)(vlSelf->top__DOT__lbm__DOT__width_count))) {
                    vlSelf->top__DOT__lbm__DOT__next_width_count 
                        = (0xffffU & 1U);
                    vlSelf->top__DOT__lbm__DOT__next_index 
                        = (0x1fffU & ((IData)(3U) + (IData)(vlSelf->top__DOT__lbm__DOT__index)));
                } else {
                    vlSelf->top__DOT__lbm__DOT__next_width_count 
                        = (0xffffU & ((IData)(1U) + (IData)(vlSelf->top__DOT__lbm__DOT__width_count)));
                    vlSelf->top__DOT__lbm__DOT__next_index 
                        = (0x1fffU & ((IData)(1U) + (IData)(vlSelf->top__DOT__lbm__DOT__index)));
                }
                vlSelf->top__DOT__lbm__DOT__next_sim_state = 1U;
            }
        }
        if ((1U & (~ (IData)(vlSelf->top__DOT__lbm__DOT__sim_state)))) {
            if ((0U >= (IData)(vlSelf->top__DOT__lbm__DOT__ram_wait_count))) {
                vlSelf->top__DOT__lbm__DOT__c0_n_next_write_en = 1U;
                vlSelf->top__DOT__lbm__DOT__c0_next_write_addr 
                    = vlSelf->top__DOT__lbm__DOT__index;
                vlSelf->top__DOT__lbm__DOT__c0_next_data_in 
                    = vlSelf->top__DOT__c0_data_out;
            }
        }
    } else if ((1U & (IData)(vlSelf->top__DOT__lbm__DOT__sim_state))) {
        if (((0x18U >= (0x1fU & (IData)(vlSelf->top__DOT__lbm__DOT__index))) 
             & (vlSelf->barriers >> (0x1fU & (IData)(vlSelf->top__DOT__lbm__DOT__index))))) {
            if ((3U == (IData)(vlSelf->top__DOT__lbm__DOT__width_count))) {
                vlSelf->top__DOT__lbm__DOT__next_width_count = 1U;
                vlSelf->top__DOT__lbm__DOT__next_index 
                    = (0x1fffU & ((IData)(3U) + (IData)(vlSelf->top__DOT__lbm__DOT__index)));
            } else {
                vlSelf->top__DOT__lbm__DOT__next_width_count 
                    = (0xffffU & ((IData)(1U) + (IData)(vlSelf->top__DOT__lbm__DOT__width_count)));
                vlSelf->top__DOT__lbm__DOT__next_index 
                    = (0x1fffU & ((IData)(1U) + (IData)(vlSelf->top__DOT__lbm__DOT__index)));
            }
            vlSelf->top__DOT__lbm__DOT__next_sim_state = 1U;
        } else {
            vlSelf->top__DOT__lbm__DOT__next_sim_state = 2U;
            vlSelf->top__DOT__lbm__DOT__next_index 
                = (0x1fffU & (IData)(vlSelf->top__DOT__lbm__DOT__index));
        }
        if ((0x12U == (IData)(vlSelf->top__DOT__lbm__DOT__index))) {
            vlSelf->top__DOT__lbm__DOT__next_width_count = 1U;
            vlSelf->top__DOT__lbm__DOT__next_sim_state = 3U;
            vlSelf->top__DOT__lbm__DOT__next_index = 6U;
        }
        if ((1U & (~ ((0x18U >= (0x1fU & (IData)(vlSelf->top__DOT__lbm__DOT__index))) 
                      & (vlSelf->barriers >> (0x1fU 
                                              & (IData)(vlSelf->top__DOT__lbm__DOT__index))))))) {
            vlSelf->top__DOT__lbm__DOT__next_ram_wait_count = 2U;
        }
    } else if (((IData)(vlSelf->top__DOT__lbm__DOT__step_count) 
                < (0xffffU & vlSelf->step))) {
        vlSelf->top__DOT__lbm__DOT__next_width_count = 1U;
        vlSelf->top__DOT__lbm__DOT__next_sim_state = 1U;
        vlSelf->top__DOT__lbm__DOT__next_ram_wait_count = 0U;
        vlSelf->top__DOT__lbm__DOT__next_index = 6U;
    } else {
        vlSelf->top__DOT__lbm__DOT__next_sim_state = 0U;
    }
}

void Vdut___024root___eval(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval\n"); );
    // Body
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlSelf->rst)) & (IData)(vlSelf->__Vclklast__TOP__rst)))) {
        Vdut___024root___sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vdut___024root___sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlSelf->rst)) & (IData)(vlSelf->__Vclklast__TOP__rst)))) {
        Vdut___024root___sequent__TOP__2(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
    Vdut___024root___combo__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
}

#ifdef VL_DEBUG
void Vdut___024root___eval_debug_assertions(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
    if (VL_UNLIKELY((vlSelf->barriers & 0xfe000000U))) {
        Verilated::overWidthError("barriers");}
}
#endif  // VL_DEBUG
