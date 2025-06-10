// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "verilated.h"

#include "Vdut___024root.h"

VL_ATTR_COLD void Vdut___024root___initial__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___initial__TOP__0\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_h02def8a8__0;
    VlWide<3>/*95:0*/ __Vtemp_h02def8a8__1;
    VlWide<3>/*95:0*/ __Vtemp_hb3450750__0;
    VlWide<3>/*95:0*/ __Vtemp_hb3450750__1;
    VlWide<3>/*95:0*/ __Vtemp_h5781e13f__0;
    VlWide<3>/*95:0*/ __Vtemp_h5781e13f__1;
    VlWide<3>/*95:0*/ __Vtemp_hc5db363f__0;
    VlWide<3>/*95:0*/ __Vtemp_hc5db363f__1;
    VlWide<3>/*95:0*/ __Vtemp_h5781e13f__2;
    VlWide<3>/*95:0*/ __Vtemp_h5781e13f__3;
    VlWide<3>/*95:0*/ __Vtemp_hb3450750__2;
    VlWide<3>/*95:0*/ __Vtemp_hb3450750__3;
    VlWide<3>/*95:0*/ __Vtemp_h02cdee20__0;
    VlWide<3>/*95:0*/ __Vtemp_h02cdee20__1;
    VlWide<3>/*95:0*/ __Vtemp_h63d4f183__0;
    VlWide<3>/*95:0*/ __Vtemp_h63d4f183__1;
    VlWide<3>/*95:0*/ __Vtemp_h02cdee20__2;
    VlWide<3>/*95:0*/ __Vtemp_h02cdee20__3;
    // Body
    __Vtemp_h02def8a8__0[0U] = 0x2e6d656dU;
    __Vtemp_h02def8a8__0[1U] = 0x30453032U;
    __Vtemp_h02def8a8__0[2U] = 0x72616dU;
    VL_READMEM_N(true, 16, 25, 0, VL_CVT_PACK_STR_NW(3, __Vtemp_h02def8a8__0)
                 ,  &(vlSelf->top__DOT__c0__DOT__mem)
                 , 0U, 0x18U);
    __Vtemp_h02def8a8__1[0U] = 0x2e6d656dU;
    __Vtemp_h02def8a8__1[1U] = 0x30453032U;
    __Vtemp_h02def8a8__1[2U] = 0x72616dU;
    VL_READMEM_N(true, 16, 25, 0, VL_CVT_PACK_STR_NW(3, __Vtemp_h02def8a8__1)
                 ,  &(vlSelf->top__DOT__c0_n__DOT__mem)
                 , 0U, 0x18U);
    __Vtemp_hb3450750__0[0U] = 0x2e6d656dU;
    __Vtemp_hb3450750__0[1U] = 0x30333831U;
    __Vtemp_hb3450750__0[2U] = 0x72616dU;
    VL_READMEM_N(true, 16, 25, 0, VL_CVT_PACK_STR_NW(3, __Vtemp_hb3450750__0)
                 ,  &(vlSelf->top__DOT__cn__DOT__mem)
                 , 0U, 0x18U);
    __Vtemp_hb3450750__1[0U] = 0x2e6d656dU;
    __Vtemp_hb3450750__1[1U] = 0x30333831U;
    __Vtemp_hb3450750__1[2U] = 0x72616dU;
    VL_READMEM_N(true, 16, 25, 0, VL_CVT_PACK_STR_NW(3, __Vtemp_hb3450750__1)
                 ,  &(vlSelf->top__DOT__cn_n__DOT__mem)
                 , 0U, 0x18U);
    __Vtemp_h5781e13f__0[0U] = 0x2e6d656dU;
    __Vtemp_h5781e13f__0[1U] = 0x30313246U;
    __Vtemp_h5781e13f__0[2U] = 0x72616dU;
    VL_READMEM_N(true, 16, 25, 0, VL_CVT_PACK_STR_NW(3, __Vtemp_h5781e13f__0)
                 ,  &(vlSelf->top__DOT__cne__DOT__mem)
                 , 0U, 0x18U);
    __Vtemp_h5781e13f__1[0U] = 0x2e6d656dU;
    __Vtemp_h5781e13f__1[1U] = 0x30313246U;
    __Vtemp_h5781e13f__1[2U] = 0x72616dU;
    VL_READMEM_N(true, 16, 25, 0, VL_CVT_PACK_STR_NW(3, __Vtemp_h5781e13f__1)
                 ,  &(vlSelf->top__DOT__cne_n__DOT__mem)
                 , 0U, 0x18U);
    __Vtemp_hc5db363f__0[0U] = 0x2e6d656dU;
    __Vtemp_hc5db363f__0[1U] = 0x30344242U;
    __Vtemp_hc5db363f__0[2U] = 0x72616dU;
    VL_READMEM_N(true, 16, 25, 0, VL_CVT_PACK_STR_NW(3, __Vtemp_hc5db363f__0)
                 ,  &(vlSelf->top__DOT__ce__DOT__mem)
                 , 0U, 0x18U);
    __Vtemp_hc5db363f__1[0U] = 0x2e6d656dU;
    __Vtemp_hc5db363f__1[1U] = 0x30344242U;
    __Vtemp_hc5db363f__1[2U] = 0x72616dU;
    VL_READMEM_N(true, 16, 25, 0, VL_CVT_PACK_STR_NW(3, __Vtemp_hc5db363f__1)
                 ,  &(vlSelf->top__DOT__ce_n__DOT__mem)
                 , 0U, 0x18U);
    __Vtemp_h5781e13f__2[0U] = 0x2e6d656dU;
    __Vtemp_h5781e13f__2[1U] = 0x30313246U;
    __Vtemp_h5781e13f__2[2U] = 0x72616dU;
    VL_READMEM_N(true, 16, 25, 0, VL_CVT_PACK_STR_NW(3, __Vtemp_h5781e13f__2)
                 ,  &(vlSelf->top__DOT__cse__DOT__mem)
                 , 0U, 0x18U);
    __Vtemp_h5781e13f__3[0U] = 0x2e6d656dU;
    __Vtemp_h5781e13f__3[1U] = 0x30313246U;
    __Vtemp_h5781e13f__3[2U] = 0x72616dU;
    VL_READMEM_N(true, 16, 25, 0, VL_CVT_PACK_STR_NW(3, __Vtemp_h5781e13f__3)
                 ,  &(vlSelf->top__DOT__cse_n__DOT__mem)
                 , 0U, 0x18U);
    __Vtemp_hb3450750__2[0U] = 0x2e6d656dU;
    __Vtemp_hb3450750__2[1U] = 0x30333831U;
    __Vtemp_hb3450750__2[2U] = 0x72616dU;
    VL_READMEM_N(true, 16, 25, 0, VL_CVT_PACK_STR_NW(3, __Vtemp_hb3450750__2)
                 ,  &(vlSelf->top__DOT__cs__DOT__mem)
                 , 0U, 0x18U);
    __Vtemp_hb3450750__3[0U] = 0x2e6d656dU;
    __Vtemp_hb3450750__3[1U] = 0x30333831U;
    __Vtemp_hb3450750__3[2U] = 0x72616dU;
    VL_READMEM_N(true, 16, 25, 0, VL_CVT_PACK_STR_NW(3, __Vtemp_hb3450750__3)
                 ,  &(vlSelf->top__DOT__cs_n__DOT__mem)
                 , 0U, 0x18U);
    __Vtemp_h02cdee20__0[0U] = 0x2e6d656dU;
    __Vtemp_h02cdee20__0[1U] = 0x30304136U;
    __Vtemp_h02cdee20__0[2U] = 0x72616dU;
    VL_READMEM_N(true, 16, 25, 0, VL_CVT_PACK_STR_NW(3, __Vtemp_h02cdee20__0)
                 ,  &(vlSelf->top__DOT__csw__DOT__mem)
                 , 0U, 0x18U);
    __Vtemp_h02cdee20__1[0U] = 0x2e6d656dU;
    __Vtemp_h02cdee20__1[1U] = 0x30304136U;
    __Vtemp_h02cdee20__1[2U] = 0x72616dU;
    VL_READMEM_N(true, 16, 25, 0, VL_CVT_PACK_STR_NW(3, __Vtemp_h02cdee20__1)
                 ,  &(vlSelf->top__DOT__csw_n__DOT__mem)
                 , 0U, 0x18U);
    __Vtemp_h63d4f183__0[0U] = 0x2e6d656dU;
    __Vtemp_h63d4f183__0[1U] = 0x30323938U;
    __Vtemp_h63d4f183__0[2U] = 0x72616dU;
    VL_READMEM_N(true, 16, 25, 0, VL_CVT_PACK_STR_NW(3, __Vtemp_h63d4f183__0)
                 ,  &(vlSelf->top__DOT__cw__DOT__mem)
                 , 0U, 0x18U);
    __Vtemp_h63d4f183__1[0U] = 0x2e6d656dU;
    __Vtemp_h63d4f183__1[1U] = 0x30323938U;
    __Vtemp_h63d4f183__1[2U] = 0x72616dU;
    VL_READMEM_N(true, 16, 25, 0, VL_CVT_PACK_STR_NW(3, __Vtemp_h63d4f183__1)
                 ,  &(vlSelf->top__DOT__cw_n__DOT__mem)
                 , 0U, 0x18U);
    __Vtemp_h02cdee20__2[0U] = 0x2e6d656dU;
    __Vtemp_h02cdee20__2[1U] = 0x30304136U;
    __Vtemp_h02cdee20__2[2U] = 0x72616dU;
    VL_READMEM_N(true, 16, 25, 0, VL_CVT_PACK_STR_NW(3, __Vtemp_h02cdee20__2)
                 ,  &(vlSelf->top__DOT__cnw__DOT__mem)
                 , 0U, 0x18U);
    __Vtemp_h02cdee20__3[0U] = 0x2e6d656dU;
    __Vtemp_h02cdee20__3[1U] = 0x30304136U;
    __Vtemp_h02cdee20__3[2U] = 0x72616dU;
    VL_READMEM_N(true, 16, 25, 0, VL_CVT_PACK_STR_NW(3, __Vtemp_h02cdee20__3)
                 ,  &(vlSelf->top__DOT__cnw_n__DOT__mem)
                 , 0U, 0x18U);
}

VL_ATTR_COLD void Vdut___024root___settle__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___settle__TOP__0\n"); );
    // Body
    vlSelf->in_collision_state = (8U == (IData)(vlSelf->top__DOT__lbm__DOT__sim_state));
    vlSelf->collider_ready = ((8U == (IData)(vlSelf->top__DOT__lbm__DOT__sim_state)) 
                              & (0U == (IData)(vlSelf->top__DOT__lbm__DOT__ram_wait_count)));
    vlSelf->rho = (0xffffU & (((((((((IData)(vlSelf->top__DOT__c0_n_data_out) 
                                     + (IData)(vlSelf->top__DOT__cn_n_data_out)) 
                                    + (IData)(vlSelf->top__DOT__cne_n_data_out)) 
                                   + (IData)(vlSelf->top__DOT__ce_n_data_out)) 
                                  + (IData)(vlSelf->top__DOT__cse_n_data_out)) 
                                 + (IData)(vlSelf->top__DOT__cs_n_data_out)) 
                                + (IData)(vlSelf->top__DOT__csw_n_data_out)) 
                               + (IData)(vlSelf->top__DOT__cw_n_data_out)) 
                              + (IData)(vlSelf->top__DOT__cnw_n_data_out)));
    vlSelf->testing_c0_data_in = vlSelf->top__DOT__c0_data_in;
    vlSelf->testing_cs_n_data_in = vlSelf->top__DOT__cs_n_data_in;
    vlSelf->top__DOT__lbm__DOT__incr_step = 0U;
    vlSelf->top__DOT__lbm__DOT__ce_next_write_en = 0U;
    vlSelf->top__DOT__lbm__DOT__cnw_next_write_en = 0U;
    vlSelf->top__DOT__lbm__DOT__cw_next_write_en = 0U;
    vlSelf->top__DOT__lbm__DOT__cne_next_write_en = 0U;
    vlSelf->top__DOT__lbm__DOT__cn_n_next_write_en = 0U;
    vlSelf->top__DOT__lbm__DOT__cn_next_write_en = 0U;
    vlSelf->top__DOT__lbm__DOT__c0_n_next_write_en = 0U;
    vlSelf->top__DOT__lbm__DOT__c0_next_write_en = 0U;
    vlSelf->top__DOT__lbm__DOT__cse_next_write_en = 0U;
    vlSelf->top__DOT__lbm__DOT__cs_next_write_en = 0U;
    vlSelf->top__DOT__lbm__DOT__cs_n_next_write_en = 0U;
    vlSelf->top__DOT__lbm__DOT__csw_next_write_en = 0U;
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
                    vlSelf->top__DOT__lbm__DOT__cn_n_next_write_en = 1U;
                    vlSelf->top__DOT__lbm__DOT__cn_next_write_en = 1U;
                    vlSelf->top__DOT__lbm__DOT__c0_n_next_write_en = 1U;
                    vlSelf->top__DOT__lbm__DOT__c0_next_write_en = 1U;
                    vlSelf->top__DOT__lbm__DOT__cse_next_write_en = 1U;
                    vlSelf->top__DOT__lbm__DOT__cs_next_write_en = 1U;
                    vlSelf->top__DOT__lbm__DOT__cs_n_next_write_en = 1U;
                    vlSelf->top__DOT__lbm__DOT__csw_next_write_en = 1U;
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
                            vlSelf->top__DOT__lbm__DOT__ce_next_write_en = 1U;
                            vlSelf->top__DOT__lbm__DOT__cnw_next_write_en = 1U;
                            vlSelf->top__DOT__lbm__DOT__cw_next_write_en = 1U;
                            vlSelf->top__DOT__lbm__DOT__cne_next_write_en = 1U;
                            vlSelf->top__DOT__lbm__DOT__cn_next_write_en = 1U;
                            vlSelf->top__DOT__lbm__DOT__c0_next_write_en = 1U;
                            vlSelf->top__DOT__lbm__DOT__cse_next_write_en = 1U;
                            vlSelf->top__DOT__lbm__DOT__cs_next_write_en = 1U;
                            vlSelf->top__DOT__lbm__DOT__csw_next_write_en = 1U;
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

VL_ATTR_COLD void Vdut___024root___eval_initial(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
    Vdut___024root___initial__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    vlSelf->__Vm_traceActivity[3U] = 1U;
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vdut___024root___eval_settle(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_settle\n"); );
    // Body
    Vdut___024root___settle__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    vlSelf->__Vm_traceActivity[3U] = 1U;
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vdut___024root___final(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___final\n"); );
}

VL_ATTR_COLD void Vdut___024root___ctor_var_reset(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->en = VL_RAND_RESET_I(1);
    vlSelf->step = VL_RAND_RESET_I(32);
    vlSelf->barriers = VL_RAND_RESET_I(25);
    vlSelf->omega = VL_RAND_RESET_I(16);
    vlSelf->init_c0 = VL_RAND_RESET_I(16);
    vlSelf->init_cn = VL_RAND_RESET_I(16);
    vlSelf->init_cne = VL_RAND_RESET_I(16);
    vlSelf->init_ce = VL_RAND_RESET_I(16);
    vlSelf->init_cse = VL_RAND_RESET_I(16);
    vlSelf->init_cs = VL_RAND_RESET_I(16);
    vlSelf->init_csw = VL_RAND_RESET_I(16);
    vlSelf->init_cw = VL_RAND_RESET_I(16);
    vlSelf->init_cnw = VL_RAND_RESET_I(16);
    vlSelf->testing_cs_n_data_in = VL_RAND_RESET_I(16);
    vlSelf->testing_c0_data_in = VL_RAND_RESET_I(16);
    vlSelf->u_x = VL_RAND_RESET_I(16);
    vlSelf->u_y = VL_RAND_RESET_I(16);
    vlSelf->rho = VL_RAND_RESET_I(16);
    vlSelf->u_squared = VL_RAND_RESET_I(16);
    vlSelf->collider_ready = VL_RAND_RESET_I(1);
    vlSelf->in_collision_state = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__c0_addr = VL_RAND_RESET_I(13);
    vlSelf->top__DOT__c0_n_addr = VL_RAND_RESET_I(13);
    vlSelf->top__DOT__cn_addr = VL_RAND_RESET_I(13);
    vlSelf->top__DOT__cn_n_addr = VL_RAND_RESET_I(13);
    vlSelf->top__DOT__cne_addr = VL_RAND_RESET_I(13);
    vlSelf->top__DOT__cne_n_addr = VL_RAND_RESET_I(13);
    vlSelf->top__DOT__ce_addr = VL_RAND_RESET_I(13);
    vlSelf->top__DOT__ce_n_addr = VL_RAND_RESET_I(13);
    vlSelf->top__DOT__cse_addr = VL_RAND_RESET_I(13);
    vlSelf->top__DOT__cse_n_addr = VL_RAND_RESET_I(13);
    vlSelf->top__DOT__cs_addr = VL_RAND_RESET_I(13);
    vlSelf->top__DOT__cs_n_addr = VL_RAND_RESET_I(13);
    vlSelf->top__DOT__csw_addr = VL_RAND_RESET_I(13);
    vlSelf->top__DOT__csw_n_addr = VL_RAND_RESET_I(13);
    vlSelf->top__DOT__cw_addr = VL_RAND_RESET_I(13);
    vlSelf->top__DOT__cw_n_addr = VL_RAND_RESET_I(13);
    vlSelf->top__DOT__cnw_addr = VL_RAND_RESET_I(13);
    vlSelf->top__DOT__cnw_n_addr = VL_RAND_RESET_I(13);
    vlSelf->top__DOT__c0_data_in = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__c0_n_data_in = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__cn_data_in = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__cn_n_data_in = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__cne_data_in = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__cne_n_data_in = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__ce_data_in = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__ce_n_data_in = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__cse_data_in = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__cse_n_data_in = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__cs_data_in = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__cs_n_data_in = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__csw_data_in = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__csw_n_data_in = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__cw_data_in = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__cw_n_data_in = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__cnw_data_in = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__cnw_n_data_in = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__c0_data_out = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__c0_n_data_out = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__cn_data_out = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__cn_n_data_out = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__cne_data_out = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__cne_n_data_out = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__ce_data_out = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__ce_n_data_out = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__cse_data_out = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__cse_n_data_out = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__cs_data_out = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__cs_n_data_out = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__csw_data_out = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__csw_n_data_out = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__cw_data_out = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__cw_n_data_out = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__cnw_data_out = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__cnw_n_data_out = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__c0_write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__c0_n_write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__cn_write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__cn_n_write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__cne_write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__cne_n_write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ce_write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ce_n_write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__cse_write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__cse_n_write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__cs_write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__cs_n_write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__csw_write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__csw_n_write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__cw_write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__cw_n_write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__cnw_write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__cnw_n_write_en = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<25; ++__Vi0) {
        vlSelf->top__DOT__c0__DOT__mem[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->top__DOT__c0__DOT____Vlvbound_h1fbfd826__0 = VL_RAND_RESET_I(16);
    for (int __Vi0=0; __Vi0<25; ++__Vi0) {
        vlSelf->top__DOT__c0_n__DOT__mem[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->top__DOT__c0_n__DOT____Vlvbound_h1fbfd826__0 = VL_RAND_RESET_I(16);
    for (int __Vi0=0; __Vi0<25; ++__Vi0) {
        vlSelf->top__DOT__cn__DOT__mem[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->top__DOT__cn__DOT____Vlvbound_h1fbfd826__0 = VL_RAND_RESET_I(16);
    for (int __Vi0=0; __Vi0<25; ++__Vi0) {
        vlSelf->top__DOT__cn_n__DOT__mem[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->top__DOT__cn_n__DOT____Vlvbound_h1fbfd826__0 = VL_RAND_RESET_I(16);
    for (int __Vi0=0; __Vi0<25; ++__Vi0) {
        vlSelf->top__DOT__cne__DOT__mem[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->top__DOT__cne__DOT____Vlvbound_h1fbfd826__0 = VL_RAND_RESET_I(16);
    for (int __Vi0=0; __Vi0<25; ++__Vi0) {
        vlSelf->top__DOT__cne_n__DOT__mem[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->top__DOT__cne_n__DOT____Vlvbound_h1fbfd826__0 = VL_RAND_RESET_I(16);
    for (int __Vi0=0; __Vi0<25; ++__Vi0) {
        vlSelf->top__DOT__ce__DOT__mem[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->top__DOT__ce__DOT____Vlvbound_h1fbfd826__0 = VL_RAND_RESET_I(16);
    for (int __Vi0=0; __Vi0<25; ++__Vi0) {
        vlSelf->top__DOT__ce_n__DOT__mem[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->top__DOT__ce_n__DOT____Vlvbound_h1fbfd826__0 = VL_RAND_RESET_I(16);
    for (int __Vi0=0; __Vi0<25; ++__Vi0) {
        vlSelf->top__DOT__cse__DOT__mem[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->top__DOT__cse__DOT____Vlvbound_h1fbfd826__0 = VL_RAND_RESET_I(16);
    for (int __Vi0=0; __Vi0<25; ++__Vi0) {
        vlSelf->top__DOT__cse_n__DOT__mem[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->top__DOT__cse_n__DOT____Vlvbound_h1fbfd826__0 = VL_RAND_RESET_I(16);
    for (int __Vi0=0; __Vi0<25; ++__Vi0) {
        vlSelf->top__DOT__cs__DOT__mem[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->top__DOT__cs__DOT____Vlvbound_h1fbfd826__0 = VL_RAND_RESET_I(16);
    for (int __Vi0=0; __Vi0<25; ++__Vi0) {
        vlSelf->top__DOT__cs_n__DOT__mem[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->top__DOT__cs_n__DOT____Vlvbound_h1fbfd826__0 = VL_RAND_RESET_I(16);
    for (int __Vi0=0; __Vi0<25; ++__Vi0) {
        vlSelf->top__DOT__csw__DOT__mem[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->top__DOT__csw__DOT____Vlvbound_h1fbfd826__0 = VL_RAND_RESET_I(16);
    for (int __Vi0=0; __Vi0<25; ++__Vi0) {
        vlSelf->top__DOT__csw_n__DOT__mem[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->top__DOT__csw_n__DOT____Vlvbound_h1fbfd826__0 = VL_RAND_RESET_I(16);
    for (int __Vi0=0; __Vi0<25; ++__Vi0) {
        vlSelf->top__DOT__cw__DOT__mem[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->top__DOT__cw__DOT____Vlvbound_h1fbfd826__0 = VL_RAND_RESET_I(16);
    for (int __Vi0=0; __Vi0<25; ++__Vi0) {
        vlSelf->top__DOT__cw_n__DOT__mem[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->top__DOT__cw_n__DOT____Vlvbound_h1fbfd826__0 = VL_RAND_RESET_I(16);
    for (int __Vi0=0; __Vi0<25; ++__Vi0) {
        vlSelf->top__DOT__cnw__DOT__mem[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->top__DOT__cnw__DOT____Vlvbound_h1fbfd826__0 = VL_RAND_RESET_I(16);
    for (int __Vi0=0; __Vi0<25; ++__Vi0) {
        vlSelf->top__DOT__cnw_n__DOT__mem[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->top__DOT__cnw_n__DOT____Vlvbound_h1fbfd826__0 = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__lbm__DOT__width_count = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__lbm__DOT__next_width_count = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__lbm__DOT__sim_state = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__lbm__DOT__next_sim_state = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__lbm__DOT__index = VL_RAND_RESET_I(13);
    vlSelf->top__DOT__lbm__DOT__next_index = VL_RAND_RESET_I(13);
    vlSelf->top__DOT__lbm__DOT__c0_next_data_in = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__lbm__DOT__c0_next_write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__lbm__DOT__c0_n_next_write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__lbm__DOT__c0_next_write_addr = VL_RAND_RESET_I(13);
    vlSelf->top__DOT__lbm__DOT__cn_next_data_in = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__lbm__DOT__cn_next_write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__lbm__DOT__cn_n_next_write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__lbm__DOT__cn_next_write_addr = VL_RAND_RESET_I(13);
    vlSelf->top__DOT__lbm__DOT__cne_next_data_in = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__lbm__DOT__cne_next_write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__lbm__DOT__cne_n_next_write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__lbm__DOT__cne_next_write_addr = VL_RAND_RESET_I(13);
    vlSelf->top__DOT__lbm__DOT__ce_next_data_in = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__lbm__DOT__ce_next_write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__lbm__DOT__ce_n_next_write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__lbm__DOT__ce_next_write_addr = VL_RAND_RESET_I(13);
    vlSelf->top__DOT__lbm__DOT__cse_next_data_in = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__lbm__DOT__cse_next_write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__lbm__DOT__cse_n_next_write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__lbm__DOT__cse_next_write_addr = VL_RAND_RESET_I(13);
    vlSelf->top__DOT__lbm__DOT__cs_next_data_in = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__lbm__DOT__cs_next_write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__lbm__DOT__cs_n_next_write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__lbm__DOT__cs_next_write_addr = VL_RAND_RESET_I(13);
    vlSelf->top__DOT__lbm__DOT__csw_next_data_in = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__lbm__DOT__csw_next_write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__lbm__DOT__csw_n_next_write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__lbm__DOT__csw_next_write_addr = VL_RAND_RESET_I(13);
    vlSelf->top__DOT__lbm__DOT__cw_next_data_in = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__lbm__DOT__cw_next_write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__lbm__DOT__cw_n_next_write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__lbm__DOT__cw_next_write_addr = VL_RAND_RESET_I(13);
    vlSelf->top__DOT__lbm__DOT__cnw_next_data_in = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__lbm__DOT__cnw_next_write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__lbm__DOT__cnw_n_next_write_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__lbm__DOT__cnw_next_write_addr = VL_RAND_RESET_I(13);
    vlSelf->top__DOT__lbm__DOT__ram_wait_count = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__lbm__DOT__next_ram_wait_count = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__lbm__DOT__step_count = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__lbm__DOT__incr_step = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__lbm__DOT__c_cn = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__lbm__DOT__c_cne = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__lbm__DOT__c_ce = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__lbm__DOT__c_cse = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__lbm__DOT__c_cs = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__lbm__DOT__c_csw = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__lbm__DOT__c_cw = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__lbm__DOT__c_cnw = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__lbm__DOT__collider__DOT__x2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__lbm__DOT__collider__DOT__x3 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__lbm__DOT__collider__DOT__u_x_squared_intermediate = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__lbm__DOT__collider__DOT__u_y_squared_intermediate = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y_squared_intermediate = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y_squared_intermediate = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<5; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
