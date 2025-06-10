// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdut__Syms.h"


void Vdut___024root__trace_chg_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vdut___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_chg_top_0\n"); );
    // Init
    Vdut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdut___024root*>(voidSelf);
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vdut___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vdut___024root__trace_chg_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgSData(oldp+0,(vlSelf->top__DOT__lbm__DOT__step_count),16);
        bufp->chgSData(oldp+1,(vlSelf->top__DOT__lbm__DOT__width_count),16);
        bufp->chgCData(oldp+2,(vlSelf->top__DOT__lbm__DOT__sim_state),4);
        bufp->chgCData(oldp+3,(vlSelf->top__DOT__lbm__DOT__ram_wait_count),3);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgSData(oldp+4,(vlSelf->top__DOT__c0_data_out),16);
        bufp->chgSData(oldp+5,(vlSelf->top__DOT__c0_n_data_out),16);
        bufp->chgSData(oldp+6,(vlSelf->top__DOT__cn_data_out),16);
        bufp->chgSData(oldp+7,(vlSelf->top__DOT__cn_n_data_out),16);
        bufp->chgSData(oldp+8,(vlSelf->top__DOT__cne_data_out),16);
        bufp->chgSData(oldp+9,(vlSelf->top__DOT__cne_n_data_out),16);
        bufp->chgSData(oldp+10,(vlSelf->top__DOT__ce_data_out),16);
        bufp->chgSData(oldp+11,(vlSelf->top__DOT__ce_n_data_out),16);
        bufp->chgSData(oldp+12,(vlSelf->top__DOT__cse_data_out),16);
        bufp->chgSData(oldp+13,(vlSelf->top__DOT__cse_n_data_out),16);
        bufp->chgSData(oldp+14,(vlSelf->top__DOT__cs_data_out),16);
        bufp->chgSData(oldp+15,(vlSelf->top__DOT__cs_n_data_out),16);
        bufp->chgSData(oldp+16,(vlSelf->top__DOT__csw_data_out),16);
        bufp->chgSData(oldp+17,(vlSelf->top__DOT__csw_n_data_out),16);
        bufp->chgSData(oldp+18,(vlSelf->top__DOT__cw_data_out),16);
        bufp->chgSData(oldp+19,(vlSelf->top__DOT__cw_n_data_out),16);
        bufp->chgSData(oldp+20,(vlSelf->top__DOT__cnw_data_out),16);
        bufp->chgSData(oldp+21,(vlSelf->top__DOT__cnw_n_data_out),16);
        bufp->chgSData(oldp+22,(vlSelf->top__DOT__c0__DOT__mem[0]),16);
        bufp->chgSData(oldp+23,(vlSelf->top__DOT__c0__DOT__mem[1]),16);
        bufp->chgSData(oldp+24,(vlSelf->top__DOT__c0__DOT__mem[2]),16);
        bufp->chgSData(oldp+25,(vlSelf->top__DOT__c0__DOT__mem[3]),16);
        bufp->chgSData(oldp+26,(vlSelf->top__DOT__c0__DOT__mem[4]),16);
        bufp->chgSData(oldp+27,(vlSelf->top__DOT__c0__DOT__mem[5]),16);
        bufp->chgSData(oldp+28,(vlSelf->top__DOT__c0__DOT__mem[6]),16);
        bufp->chgSData(oldp+29,(vlSelf->top__DOT__c0__DOT__mem[7]),16);
        bufp->chgSData(oldp+30,(vlSelf->top__DOT__c0__DOT__mem[8]),16);
        bufp->chgSData(oldp+31,(vlSelf->top__DOT__c0__DOT__mem[9]),16);
        bufp->chgSData(oldp+32,(vlSelf->top__DOT__c0__DOT__mem[10]),16);
        bufp->chgSData(oldp+33,(vlSelf->top__DOT__c0__DOT__mem[11]),16);
        bufp->chgSData(oldp+34,(vlSelf->top__DOT__c0__DOT__mem[12]),16);
        bufp->chgSData(oldp+35,(vlSelf->top__DOT__c0__DOT__mem[13]),16);
        bufp->chgSData(oldp+36,(vlSelf->top__DOT__c0__DOT__mem[14]),16);
        bufp->chgSData(oldp+37,(vlSelf->top__DOT__c0__DOT__mem[15]),16);
        bufp->chgSData(oldp+38,(vlSelf->top__DOT__c0__DOT__mem[16]),16);
        bufp->chgSData(oldp+39,(vlSelf->top__DOT__c0__DOT__mem[17]),16);
        bufp->chgSData(oldp+40,(vlSelf->top__DOT__c0__DOT__mem[18]),16);
        bufp->chgSData(oldp+41,(vlSelf->top__DOT__c0__DOT__mem[19]),16);
        bufp->chgSData(oldp+42,(vlSelf->top__DOT__c0__DOT__mem[20]),16);
        bufp->chgSData(oldp+43,(vlSelf->top__DOT__c0__DOT__mem[21]),16);
        bufp->chgSData(oldp+44,(vlSelf->top__DOT__c0__DOT__mem[22]),16);
        bufp->chgSData(oldp+45,(vlSelf->top__DOT__c0__DOT__mem[23]),16);
        bufp->chgSData(oldp+46,(vlSelf->top__DOT__c0__DOT__mem[24]),16);
        bufp->chgSData(oldp+47,(vlSelf->top__DOT__c0_n__DOT__mem[0]),16);
        bufp->chgSData(oldp+48,(vlSelf->top__DOT__c0_n__DOT__mem[1]),16);
        bufp->chgSData(oldp+49,(vlSelf->top__DOT__c0_n__DOT__mem[2]),16);
        bufp->chgSData(oldp+50,(vlSelf->top__DOT__c0_n__DOT__mem[3]),16);
        bufp->chgSData(oldp+51,(vlSelf->top__DOT__c0_n__DOT__mem[4]),16);
        bufp->chgSData(oldp+52,(vlSelf->top__DOT__c0_n__DOT__mem[5]),16);
        bufp->chgSData(oldp+53,(vlSelf->top__DOT__c0_n__DOT__mem[6]),16);
        bufp->chgSData(oldp+54,(vlSelf->top__DOT__c0_n__DOT__mem[7]),16);
        bufp->chgSData(oldp+55,(vlSelf->top__DOT__c0_n__DOT__mem[8]),16);
        bufp->chgSData(oldp+56,(vlSelf->top__DOT__c0_n__DOT__mem[9]),16);
        bufp->chgSData(oldp+57,(vlSelf->top__DOT__c0_n__DOT__mem[10]),16);
        bufp->chgSData(oldp+58,(vlSelf->top__DOT__c0_n__DOT__mem[11]),16);
        bufp->chgSData(oldp+59,(vlSelf->top__DOT__c0_n__DOT__mem[12]),16);
        bufp->chgSData(oldp+60,(vlSelf->top__DOT__c0_n__DOT__mem[13]),16);
        bufp->chgSData(oldp+61,(vlSelf->top__DOT__c0_n__DOT__mem[14]),16);
        bufp->chgSData(oldp+62,(vlSelf->top__DOT__c0_n__DOT__mem[15]),16);
        bufp->chgSData(oldp+63,(vlSelf->top__DOT__c0_n__DOT__mem[16]),16);
        bufp->chgSData(oldp+64,(vlSelf->top__DOT__c0_n__DOT__mem[17]),16);
        bufp->chgSData(oldp+65,(vlSelf->top__DOT__c0_n__DOT__mem[18]),16);
        bufp->chgSData(oldp+66,(vlSelf->top__DOT__c0_n__DOT__mem[19]),16);
        bufp->chgSData(oldp+67,(vlSelf->top__DOT__c0_n__DOT__mem[20]),16);
        bufp->chgSData(oldp+68,(vlSelf->top__DOT__c0_n__DOT__mem[21]),16);
        bufp->chgSData(oldp+69,(vlSelf->top__DOT__c0_n__DOT__mem[22]),16);
        bufp->chgSData(oldp+70,(vlSelf->top__DOT__c0_n__DOT__mem[23]),16);
        bufp->chgSData(oldp+71,(vlSelf->top__DOT__c0_n__DOT__mem[24]),16);
        bufp->chgSData(oldp+72,(vlSelf->top__DOT__ce__DOT__mem[0]),16);
        bufp->chgSData(oldp+73,(vlSelf->top__DOT__ce__DOT__mem[1]),16);
        bufp->chgSData(oldp+74,(vlSelf->top__DOT__ce__DOT__mem[2]),16);
        bufp->chgSData(oldp+75,(vlSelf->top__DOT__ce__DOT__mem[3]),16);
        bufp->chgSData(oldp+76,(vlSelf->top__DOT__ce__DOT__mem[4]),16);
        bufp->chgSData(oldp+77,(vlSelf->top__DOT__ce__DOT__mem[5]),16);
        bufp->chgSData(oldp+78,(vlSelf->top__DOT__ce__DOT__mem[6]),16);
        bufp->chgSData(oldp+79,(vlSelf->top__DOT__ce__DOT__mem[7]),16);
        bufp->chgSData(oldp+80,(vlSelf->top__DOT__ce__DOT__mem[8]),16);
        bufp->chgSData(oldp+81,(vlSelf->top__DOT__ce__DOT__mem[9]),16);
        bufp->chgSData(oldp+82,(vlSelf->top__DOT__ce__DOT__mem[10]),16);
        bufp->chgSData(oldp+83,(vlSelf->top__DOT__ce__DOT__mem[11]),16);
        bufp->chgSData(oldp+84,(vlSelf->top__DOT__ce__DOT__mem[12]),16);
        bufp->chgSData(oldp+85,(vlSelf->top__DOT__ce__DOT__mem[13]),16);
        bufp->chgSData(oldp+86,(vlSelf->top__DOT__ce__DOT__mem[14]),16);
        bufp->chgSData(oldp+87,(vlSelf->top__DOT__ce__DOT__mem[15]),16);
        bufp->chgSData(oldp+88,(vlSelf->top__DOT__ce__DOT__mem[16]),16);
        bufp->chgSData(oldp+89,(vlSelf->top__DOT__ce__DOT__mem[17]),16);
        bufp->chgSData(oldp+90,(vlSelf->top__DOT__ce__DOT__mem[18]),16);
        bufp->chgSData(oldp+91,(vlSelf->top__DOT__ce__DOT__mem[19]),16);
        bufp->chgSData(oldp+92,(vlSelf->top__DOT__ce__DOT__mem[20]),16);
        bufp->chgSData(oldp+93,(vlSelf->top__DOT__ce__DOT__mem[21]),16);
        bufp->chgSData(oldp+94,(vlSelf->top__DOT__ce__DOT__mem[22]),16);
        bufp->chgSData(oldp+95,(vlSelf->top__DOT__ce__DOT__mem[23]),16);
        bufp->chgSData(oldp+96,(vlSelf->top__DOT__ce__DOT__mem[24]),16);
        bufp->chgSData(oldp+97,(vlSelf->top__DOT__ce_n__DOT__mem[0]),16);
        bufp->chgSData(oldp+98,(vlSelf->top__DOT__ce_n__DOT__mem[1]),16);
        bufp->chgSData(oldp+99,(vlSelf->top__DOT__ce_n__DOT__mem[2]),16);
        bufp->chgSData(oldp+100,(vlSelf->top__DOT__ce_n__DOT__mem[3]),16);
        bufp->chgSData(oldp+101,(vlSelf->top__DOT__ce_n__DOT__mem[4]),16);
        bufp->chgSData(oldp+102,(vlSelf->top__DOT__ce_n__DOT__mem[5]),16);
        bufp->chgSData(oldp+103,(vlSelf->top__DOT__ce_n__DOT__mem[6]),16);
        bufp->chgSData(oldp+104,(vlSelf->top__DOT__ce_n__DOT__mem[7]),16);
        bufp->chgSData(oldp+105,(vlSelf->top__DOT__ce_n__DOT__mem[8]),16);
        bufp->chgSData(oldp+106,(vlSelf->top__DOT__ce_n__DOT__mem[9]),16);
        bufp->chgSData(oldp+107,(vlSelf->top__DOT__ce_n__DOT__mem[10]),16);
        bufp->chgSData(oldp+108,(vlSelf->top__DOT__ce_n__DOT__mem[11]),16);
        bufp->chgSData(oldp+109,(vlSelf->top__DOT__ce_n__DOT__mem[12]),16);
        bufp->chgSData(oldp+110,(vlSelf->top__DOT__ce_n__DOT__mem[13]),16);
        bufp->chgSData(oldp+111,(vlSelf->top__DOT__ce_n__DOT__mem[14]),16);
        bufp->chgSData(oldp+112,(vlSelf->top__DOT__ce_n__DOT__mem[15]),16);
        bufp->chgSData(oldp+113,(vlSelf->top__DOT__ce_n__DOT__mem[16]),16);
        bufp->chgSData(oldp+114,(vlSelf->top__DOT__ce_n__DOT__mem[17]),16);
        bufp->chgSData(oldp+115,(vlSelf->top__DOT__ce_n__DOT__mem[18]),16);
        bufp->chgSData(oldp+116,(vlSelf->top__DOT__ce_n__DOT__mem[19]),16);
        bufp->chgSData(oldp+117,(vlSelf->top__DOT__ce_n__DOT__mem[20]),16);
        bufp->chgSData(oldp+118,(vlSelf->top__DOT__ce_n__DOT__mem[21]),16);
        bufp->chgSData(oldp+119,(vlSelf->top__DOT__ce_n__DOT__mem[22]),16);
        bufp->chgSData(oldp+120,(vlSelf->top__DOT__ce_n__DOT__mem[23]),16);
        bufp->chgSData(oldp+121,(vlSelf->top__DOT__ce_n__DOT__mem[24]),16);
        bufp->chgSData(oldp+122,(vlSelf->top__DOT__cn__DOT__mem[0]),16);
        bufp->chgSData(oldp+123,(vlSelf->top__DOT__cn__DOT__mem[1]),16);
        bufp->chgSData(oldp+124,(vlSelf->top__DOT__cn__DOT__mem[2]),16);
        bufp->chgSData(oldp+125,(vlSelf->top__DOT__cn__DOT__mem[3]),16);
        bufp->chgSData(oldp+126,(vlSelf->top__DOT__cn__DOT__mem[4]),16);
        bufp->chgSData(oldp+127,(vlSelf->top__DOT__cn__DOT__mem[5]),16);
        bufp->chgSData(oldp+128,(vlSelf->top__DOT__cn__DOT__mem[6]),16);
        bufp->chgSData(oldp+129,(vlSelf->top__DOT__cn__DOT__mem[7]),16);
        bufp->chgSData(oldp+130,(vlSelf->top__DOT__cn__DOT__mem[8]),16);
        bufp->chgSData(oldp+131,(vlSelf->top__DOT__cn__DOT__mem[9]),16);
        bufp->chgSData(oldp+132,(vlSelf->top__DOT__cn__DOT__mem[10]),16);
        bufp->chgSData(oldp+133,(vlSelf->top__DOT__cn__DOT__mem[11]),16);
        bufp->chgSData(oldp+134,(vlSelf->top__DOT__cn__DOT__mem[12]),16);
        bufp->chgSData(oldp+135,(vlSelf->top__DOT__cn__DOT__mem[13]),16);
        bufp->chgSData(oldp+136,(vlSelf->top__DOT__cn__DOT__mem[14]),16);
        bufp->chgSData(oldp+137,(vlSelf->top__DOT__cn__DOT__mem[15]),16);
        bufp->chgSData(oldp+138,(vlSelf->top__DOT__cn__DOT__mem[16]),16);
        bufp->chgSData(oldp+139,(vlSelf->top__DOT__cn__DOT__mem[17]),16);
        bufp->chgSData(oldp+140,(vlSelf->top__DOT__cn__DOT__mem[18]),16);
        bufp->chgSData(oldp+141,(vlSelf->top__DOT__cn__DOT__mem[19]),16);
        bufp->chgSData(oldp+142,(vlSelf->top__DOT__cn__DOT__mem[20]),16);
        bufp->chgSData(oldp+143,(vlSelf->top__DOT__cn__DOT__mem[21]),16);
        bufp->chgSData(oldp+144,(vlSelf->top__DOT__cn__DOT__mem[22]),16);
        bufp->chgSData(oldp+145,(vlSelf->top__DOT__cn__DOT__mem[23]),16);
        bufp->chgSData(oldp+146,(vlSelf->top__DOT__cn__DOT__mem[24]),16);
        bufp->chgSData(oldp+147,(vlSelf->top__DOT__cn_n__DOT__mem[0]),16);
        bufp->chgSData(oldp+148,(vlSelf->top__DOT__cn_n__DOT__mem[1]),16);
        bufp->chgSData(oldp+149,(vlSelf->top__DOT__cn_n__DOT__mem[2]),16);
        bufp->chgSData(oldp+150,(vlSelf->top__DOT__cn_n__DOT__mem[3]),16);
        bufp->chgSData(oldp+151,(vlSelf->top__DOT__cn_n__DOT__mem[4]),16);
        bufp->chgSData(oldp+152,(vlSelf->top__DOT__cn_n__DOT__mem[5]),16);
        bufp->chgSData(oldp+153,(vlSelf->top__DOT__cn_n__DOT__mem[6]),16);
        bufp->chgSData(oldp+154,(vlSelf->top__DOT__cn_n__DOT__mem[7]),16);
        bufp->chgSData(oldp+155,(vlSelf->top__DOT__cn_n__DOT__mem[8]),16);
        bufp->chgSData(oldp+156,(vlSelf->top__DOT__cn_n__DOT__mem[9]),16);
        bufp->chgSData(oldp+157,(vlSelf->top__DOT__cn_n__DOT__mem[10]),16);
        bufp->chgSData(oldp+158,(vlSelf->top__DOT__cn_n__DOT__mem[11]),16);
        bufp->chgSData(oldp+159,(vlSelf->top__DOT__cn_n__DOT__mem[12]),16);
        bufp->chgSData(oldp+160,(vlSelf->top__DOT__cn_n__DOT__mem[13]),16);
        bufp->chgSData(oldp+161,(vlSelf->top__DOT__cn_n__DOT__mem[14]),16);
        bufp->chgSData(oldp+162,(vlSelf->top__DOT__cn_n__DOT__mem[15]),16);
        bufp->chgSData(oldp+163,(vlSelf->top__DOT__cn_n__DOT__mem[16]),16);
        bufp->chgSData(oldp+164,(vlSelf->top__DOT__cn_n__DOT__mem[17]),16);
        bufp->chgSData(oldp+165,(vlSelf->top__DOT__cn_n__DOT__mem[18]),16);
        bufp->chgSData(oldp+166,(vlSelf->top__DOT__cn_n__DOT__mem[19]),16);
        bufp->chgSData(oldp+167,(vlSelf->top__DOT__cn_n__DOT__mem[20]),16);
        bufp->chgSData(oldp+168,(vlSelf->top__DOT__cn_n__DOT__mem[21]),16);
        bufp->chgSData(oldp+169,(vlSelf->top__DOT__cn_n__DOT__mem[22]),16);
        bufp->chgSData(oldp+170,(vlSelf->top__DOT__cn_n__DOT__mem[23]),16);
        bufp->chgSData(oldp+171,(vlSelf->top__DOT__cn_n__DOT__mem[24]),16);
        bufp->chgSData(oldp+172,(vlSelf->top__DOT__cne__DOT__mem[0]),16);
        bufp->chgSData(oldp+173,(vlSelf->top__DOT__cne__DOT__mem[1]),16);
        bufp->chgSData(oldp+174,(vlSelf->top__DOT__cne__DOT__mem[2]),16);
        bufp->chgSData(oldp+175,(vlSelf->top__DOT__cne__DOT__mem[3]),16);
        bufp->chgSData(oldp+176,(vlSelf->top__DOT__cne__DOT__mem[4]),16);
        bufp->chgSData(oldp+177,(vlSelf->top__DOT__cne__DOT__mem[5]),16);
        bufp->chgSData(oldp+178,(vlSelf->top__DOT__cne__DOT__mem[6]),16);
        bufp->chgSData(oldp+179,(vlSelf->top__DOT__cne__DOT__mem[7]),16);
        bufp->chgSData(oldp+180,(vlSelf->top__DOT__cne__DOT__mem[8]),16);
        bufp->chgSData(oldp+181,(vlSelf->top__DOT__cne__DOT__mem[9]),16);
        bufp->chgSData(oldp+182,(vlSelf->top__DOT__cne__DOT__mem[10]),16);
        bufp->chgSData(oldp+183,(vlSelf->top__DOT__cne__DOT__mem[11]),16);
        bufp->chgSData(oldp+184,(vlSelf->top__DOT__cne__DOT__mem[12]),16);
        bufp->chgSData(oldp+185,(vlSelf->top__DOT__cne__DOT__mem[13]),16);
        bufp->chgSData(oldp+186,(vlSelf->top__DOT__cne__DOT__mem[14]),16);
        bufp->chgSData(oldp+187,(vlSelf->top__DOT__cne__DOT__mem[15]),16);
        bufp->chgSData(oldp+188,(vlSelf->top__DOT__cne__DOT__mem[16]),16);
        bufp->chgSData(oldp+189,(vlSelf->top__DOT__cne__DOT__mem[17]),16);
        bufp->chgSData(oldp+190,(vlSelf->top__DOT__cne__DOT__mem[18]),16);
        bufp->chgSData(oldp+191,(vlSelf->top__DOT__cne__DOT__mem[19]),16);
        bufp->chgSData(oldp+192,(vlSelf->top__DOT__cne__DOT__mem[20]),16);
        bufp->chgSData(oldp+193,(vlSelf->top__DOT__cne__DOT__mem[21]),16);
        bufp->chgSData(oldp+194,(vlSelf->top__DOT__cne__DOT__mem[22]),16);
        bufp->chgSData(oldp+195,(vlSelf->top__DOT__cne__DOT__mem[23]),16);
        bufp->chgSData(oldp+196,(vlSelf->top__DOT__cne__DOT__mem[24]),16);
        bufp->chgSData(oldp+197,(vlSelf->top__DOT__cne_n__DOT__mem[0]),16);
        bufp->chgSData(oldp+198,(vlSelf->top__DOT__cne_n__DOT__mem[1]),16);
        bufp->chgSData(oldp+199,(vlSelf->top__DOT__cne_n__DOT__mem[2]),16);
        bufp->chgSData(oldp+200,(vlSelf->top__DOT__cne_n__DOT__mem[3]),16);
        bufp->chgSData(oldp+201,(vlSelf->top__DOT__cne_n__DOT__mem[4]),16);
        bufp->chgSData(oldp+202,(vlSelf->top__DOT__cne_n__DOT__mem[5]),16);
        bufp->chgSData(oldp+203,(vlSelf->top__DOT__cne_n__DOT__mem[6]),16);
        bufp->chgSData(oldp+204,(vlSelf->top__DOT__cne_n__DOT__mem[7]),16);
        bufp->chgSData(oldp+205,(vlSelf->top__DOT__cne_n__DOT__mem[8]),16);
        bufp->chgSData(oldp+206,(vlSelf->top__DOT__cne_n__DOT__mem[9]),16);
        bufp->chgSData(oldp+207,(vlSelf->top__DOT__cne_n__DOT__mem[10]),16);
        bufp->chgSData(oldp+208,(vlSelf->top__DOT__cne_n__DOT__mem[11]),16);
        bufp->chgSData(oldp+209,(vlSelf->top__DOT__cne_n__DOT__mem[12]),16);
        bufp->chgSData(oldp+210,(vlSelf->top__DOT__cne_n__DOT__mem[13]),16);
        bufp->chgSData(oldp+211,(vlSelf->top__DOT__cne_n__DOT__mem[14]),16);
        bufp->chgSData(oldp+212,(vlSelf->top__DOT__cne_n__DOT__mem[15]),16);
        bufp->chgSData(oldp+213,(vlSelf->top__DOT__cne_n__DOT__mem[16]),16);
        bufp->chgSData(oldp+214,(vlSelf->top__DOT__cne_n__DOT__mem[17]),16);
        bufp->chgSData(oldp+215,(vlSelf->top__DOT__cne_n__DOT__mem[18]),16);
        bufp->chgSData(oldp+216,(vlSelf->top__DOT__cne_n__DOT__mem[19]),16);
        bufp->chgSData(oldp+217,(vlSelf->top__DOT__cne_n__DOT__mem[20]),16);
        bufp->chgSData(oldp+218,(vlSelf->top__DOT__cne_n__DOT__mem[21]),16);
        bufp->chgSData(oldp+219,(vlSelf->top__DOT__cne_n__DOT__mem[22]),16);
        bufp->chgSData(oldp+220,(vlSelf->top__DOT__cne_n__DOT__mem[23]),16);
        bufp->chgSData(oldp+221,(vlSelf->top__DOT__cne_n__DOT__mem[24]),16);
        bufp->chgSData(oldp+222,(vlSelf->top__DOT__cnw__DOT__mem[0]),16);
        bufp->chgSData(oldp+223,(vlSelf->top__DOT__cnw__DOT__mem[1]),16);
        bufp->chgSData(oldp+224,(vlSelf->top__DOT__cnw__DOT__mem[2]),16);
        bufp->chgSData(oldp+225,(vlSelf->top__DOT__cnw__DOT__mem[3]),16);
        bufp->chgSData(oldp+226,(vlSelf->top__DOT__cnw__DOT__mem[4]),16);
        bufp->chgSData(oldp+227,(vlSelf->top__DOT__cnw__DOT__mem[5]),16);
        bufp->chgSData(oldp+228,(vlSelf->top__DOT__cnw__DOT__mem[6]),16);
        bufp->chgSData(oldp+229,(vlSelf->top__DOT__cnw__DOT__mem[7]),16);
        bufp->chgSData(oldp+230,(vlSelf->top__DOT__cnw__DOT__mem[8]),16);
        bufp->chgSData(oldp+231,(vlSelf->top__DOT__cnw__DOT__mem[9]),16);
        bufp->chgSData(oldp+232,(vlSelf->top__DOT__cnw__DOT__mem[10]),16);
        bufp->chgSData(oldp+233,(vlSelf->top__DOT__cnw__DOT__mem[11]),16);
        bufp->chgSData(oldp+234,(vlSelf->top__DOT__cnw__DOT__mem[12]),16);
        bufp->chgSData(oldp+235,(vlSelf->top__DOT__cnw__DOT__mem[13]),16);
        bufp->chgSData(oldp+236,(vlSelf->top__DOT__cnw__DOT__mem[14]),16);
        bufp->chgSData(oldp+237,(vlSelf->top__DOT__cnw__DOT__mem[15]),16);
        bufp->chgSData(oldp+238,(vlSelf->top__DOT__cnw__DOT__mem[16]),16);
        bufp->chgSData(oldp+239,(vlSelf->top__DOT__cnw__DOT__mem[17]),16);
        bufp->chgSData(oldp+240,(vlSelf->top__DOT__cnw__DOT__mem[18]),16);
        bufp->chgSData(oldp+241,(vlSelf->top__DOT__cnw__DOT__mem[19]),16);
        bufp->chgSData(oldp+242,(vlSelf->top__DOT__cnw__DOT__mem[20]),16);
        bufp->chgSData(oldp+243,(vlSelf->top__DOT__cnw__DOT__mem[21]),16);
        bufp->chgSData(oldp+244,(vlSelf->top__DOT__cnw__DOT__mem[22]),16);
        bufp->chgSData(oldp+245,(vlSelf->top__DOT__cnw__DOT__mem[23]),16);
        bufp->chgSData(oldp+246,(vlSelf->top__DOT__cnw__DOT__mem[24]),16);
        bufp->chgSData(oldp+247,(vlSelf->top__DOT__cnw_n__DOT__mem[0]),16);
        bufp->chgSData(oldp+248,(vlSelf->top__DOT__cnw_n__DOT__mem[1]),16);
        bufp->chgSData(oldp+249,(vlSelf->top__DOT__cnw_n__DOT__mem[2]),16);
        bufp->chgSData(oldp+250,(vlSelf->top__DOT__cnw_n__DOT__mem[3]),16);
        bufp->chgSData(oldp+251,(vlSelf->top__DOT__cnw_n__DOT__mem[4]),16);
        bufp->chgSData(oldp+252,(vlSelf->top__DOT__cnw_n__DOT__mem[5]),16);
        bufp->chgSData(oldp+253,(vlSelf->top__DOT__cnw_n__DOT__mem[6]),16);
        bufp->chgSData(oldp+254,(vlSelf->top__DOT__cnw_n__DOT__mem[7]),16);
        bufp->chgSData(oldp+255,(vlSelf->top__DOT__cnw_n__DOT__mem[8]),16);
        bufp->chgSData(oldp+256,(vlSelf->top__DOT__cnw_n__DOT__mem[9]),16);
        bufp->chgSData(oldp+257,(vlSelf->top__DOT__cnw_n__DOT__mem[10]),16);
        bufp->chgSData(oldp+258,(vlSelf->top__DOT__cnw_n__DOT__mem[11]),16);
        bufp->chgSData(oldp+259,(vlSelf->top__DOT__cnw_n__DOT__mem[12]),16);
        bufp->chgSData(oldp+260,(vlSelf->top__DOT__cnw_n__DOT__mem[13]),16);
        bufp->chgSData(oldp+261,(vlSelf->top__DOT__cnw_n__DOT__mem[14]),16);
        bufp->chgSData(oldp+262,(vlSelf->top__DOT__cnw_n__DOT__mem[15]),16);
        bufp->chgSData(oldp+263,(vlSelf->top__DOT__cnw_n__DOT__mem[16]),16);
        bufp->chgSData(oldp+264,(vlSelf->top__DOT__cnw_n__DOT__mem[17]),16);
        bufp->chgSData(oldp+265,(vlSelf->top__DOT__cnw_n__DOT__mem[18]),16);
        bufp->chgSData(oldp+266,(vlSelf->top__DOT__cnw_n__DOT__mem[19]),16);
        bufp->chgSData(oldp+267,(vlSelf->top__DOT__cnw_n__DOT__mem[20]),16);
        bufp->chgSData(oldp+268,(vlSelf->top__DOT__cnw_n__DOT__mem[21]),16);
        bufp->chgSData(oldp+269,(vlSelf->top__DOT__cnw_n__DOT__mem[22]),16);
        bufp->chgSData(oldp+270,(vlSelf->top__DOT__cnw_n__DOT__mem[23]),16);
        bufp->chgSData(oldp+271,(vlSelf->top__DOT__cnw_n__DOT__mem[24]),16);
        bufp->chgSData(oldp+272,(vlSelf->top__DOT__cs__DOT__mem[0]),16);
        bufp->chgSData(oldp+273,(vlSelf->top__DOT__cs__DOT__mem[1]),16);
        bufp->chgSData(oldp+274,(vlSelf->top__DOT__cs__DOT__mem[2]),16);
        bufp->chgSData(oldp+275,(vlSelf->top__DOT__cs__DOT__mem[3]),16);
        bufp->chgSData(oldp+276,(vlSelf->top__DOT__cs__DOT__mem[4]),16);
        bufp->chgSData(oldp+277,(vlSelf->top__DOT__cs__DOT__mem[5]),16);
        bufp->chgSData(oldp+278,(vlSelf->top__DOT__cs__DOT__mem[6]),16);
        bufp->chgSData(oldp+279,(vlSelf->top__DOT__cs__DOT__mem[7]),16);
        bufp->chgSData(oldp+280,(vlSelf->top__DOT__cs__DOT__mem[8]),16);
        bufp->chgSData(oldp+281,(vlSelf->top__DOT__cs__DOT__mem[9]),16);
        bufp->chgSData(oldp+282,(vlSelf->top__DOT__cs__DOT__mem[10]),16);
        bufp->chgSData(oldp+283,(vlSelf->top__DOT__cs__DOT__mem[11]),16);
        bufp->chgSData(oldp+284,(vlSelf->top__DOT__cs__DOT__mem[12]),16);
        bufp->chgSData(oldp+285,(vlSelf->top__DOT__cs__DOT__mem[13]),16);
        bufp->chgSData(oldp+286,(vlSelf->top__DOT__cs__DOT__mem[14]),16);
        bufp->chgSData(oldp+287,(vlSelf->top__DOT__cs__DOT__mem[15]),16);
        bufp->chgSData(oldp+288,(vlSelf->top__DOT__cs__DOT__mem[16]),16);
        bufp->chgSData(oldp+289,(vlSelf->top__DOT__cs__DOT__mem[17]),16);
        bufp->chgSData(oldp+290,(vlSelf->top__DOT__cs__DOT__mem[18]),16);
        bufp->chgSData(oldp+291,(vlSelf->top__DOT__cs__DOT__mem[19]),16);
        bufp->chgSData(oldp+292,(vlSelf->top__DOT__cs__DOT__mem[20]),16);
        bufp->chgSData(oldp+293,(vlSelf->top__DOT__cs__DOT__mem[21]),16);
        bufp->chgSData(oldp+294,(vlSelf->top__DOT__cs__DOT__mem[22]),16);
        bufp->chgSData(oldp+295,(vlSelf->top__DOT__cs__DOT__mem[23]),16);
        bufp->chgSData(oldp+296,(vlSelf->top__DOT__cs__DOT__mem[24]),16);
        bufp->chgSData(oldp+297,(vlSelf->top__DOT__cs_n__DOT__mem[0]),16);
        bufp->chgSData(oldp+298,(vlSelf->top__DOT__cs_n__DOT__mem[1]),16);
        bufp->chgSData(oldp+299,(vlSelf->top__DOT__cs_n__DOT__mem[2]),16);
        bufp->chgSData(oldp+300,(vlSelf->top__DOT__cs_n__DOT__mem[3]),16);
        bufp->chgSData(oldp+301,(vlSelf->top__DOT__cs_n__DOT__mem[4]),16);
        bufp->chgSData(oldp+302,(vlSelf->top__DOT__cs_n__DOT__mem[5]),16);
        bufp->chgSData(oldp+303,(vlSelf->top__DOT__cs_n__DOT__mem[6]),16);
        bufp->chgSData(oldp+304,(vlSelf->top__DOT__cs_n__DOT__mem[7]),16);
        bufp->chgSData(oldp+305,(vlSelf->top__DOT__cs_n__DOT__mem[8]),16);
        bufp->chgSData(oldp+306,(vlSelf->top__DOT__cs_n__DOT__mem[9]),16);
        bufp->chgSData(oldp+307,(vlSelf->top__DOT__cs_n__DOT__mem[10]),16);
        bufp->chgSData(oldp+308,(vlSelf->top__DOT__cs_n__DOT__mem[11]),16);
        bufp->chgSData(oldp+309,(vlSelf->top__DOT__cs_n__DOT__mem[12]),16);
        bufp->chgSData(oldp+310,(vlSelf->top__DOT__cs_n__DOT__mem[13]),16);
        bufp->chgSData(oldp+311,(vlSelf->top__DOT__cs_n__DOT__mem[14]),16);
        bufp->chgSData(oldp+312,(vlSelf->top__DOT__cs_n__DOT__mem[15]),16);
        bufp->chgSData(oldp+313,(vlSelf->top__DOT__cs_n__DOT__mem[16]),16);
        bufp->chgSData(oldp+314,(vlSelf->top__DOT__cs_n__DOT__mem[17]),16);
        bufp->chgSData(oldp+315,(vlSelf->top__DOT__cs_n__DOT__mem[18]),16);
        bufp->chgSData(oldp+316,(vlSelf->top__DOT__cs_n__DOT__mem[19]),16);
        bufp->chgSData(oldp+317,(vlSelf->top__DOT__cs_n__DOT__mem[20]),16);
        bufp->chgSData(oldp+318,(vlSelf->top__DOT__cs_n__DOT__mem[21]),16);
        bufp->chgSData(oldp+319,(vlSelf->top__DOT__cs_n__DOT__mem[22]),16);
        bufp->chgSData(oldp+320,(vlSelf->top__DOT__cs_n__DOT__mem[23]),16);
        bufp->chgSData(oldp+321,(vlSelf->top__DOT__cs_n__DOT__mem[24]),16);
        bufp->chgSData(oldp+322,(vlSelf->top__DOT__cse__DOT__mem[0]),16);
        bufp->chgSData(oldp+323,(vlSelf->top__DOT__cse__DOT__mem[1]),16);
        bufp->chgSData(oldp+324,(vlSelf->top__DOT__cse__DOT__mem[2]),16);
        bufp->chgSData(oldp+325,(vlSelf->top__DOT__cse__DOT__mem[3]),16);
        bufp->chgSData(oldp+326,(vlSelf->top__DOT__cse__DOT__mem[4]),16);
        bufp->chgSData(oldp+327,(vlSelf->top__DOT__cse__DOT__mem[5]),16);
        bufp->chgSData(oldp+328,(vlSelf->top__DOT__cse__DOT__mem[6]),16);
        bufp->chgSData(oldp+329,(vlSelf->top__DOT__cse__DOT__mem[7]),16);
        bufp->chgSData(oldp+330,(vlSelf->top__DOT__cse__DOT__mem[8]),16);
        bufp->chgSData(oldp+331,(vlSelf->top__DOT__cse__DOT__mem[9]),16);
        bufp->chgSData(oldp+332,(vlSelf->top__DOT__cse__DOT__mem[10]),16);
        bufp->chgSData(oldp+333,(vlSelf->top__DOT__cse__DOT__mem[11]),16);
        bufp->chgSData(oldp+334,(vlSelf->top__DOT__cse__DOT__mem[12]),16);
        bufp->chgSData(oldp+335,(vlSelf->top__DOT__cse__DOT__mem[13]),16);
        bufp->chgSData(oldp+336,(vlSelf->top__DOT__cse__DOT__mem[14]),16);
        bufp->chgSData(oldp+337,(vlSelf->top__DOT__cse__DOT__mem[15]),16);
        bufp->chgSData(oldp+338,(vlSelf->top__DOT__cse__DOT__mem[16]),16);
        bufp->chgSData(oldp+339,(vlSelf->top__DOT__cse__DOT__mem[17]),16);
        bufp->chgSData(oldp+340,(vlSelf->top__DOT__cse__DOT__mem[18]),16);
        bufp->chgSData(oldp+341,(vlSelf->top__DOT__cse__DOT__mem[19]),16);
        bufp->chgSData(oldp+342,(vlSelf->top__DOT__cse__DOT__mem[20]),16);
        bufp->chgSData(oldp+343,(vlSelf->top__DOT__cse__DOT__mem[21]),16);
        bufp->chgSData(oldp+344,(vlSelf->top__DOT__cse__DOT__mem[22]),16);
        bufp->chgSData(oldp+345,(vlSelf->top__DOT__cse__DOT__mem[23]),16);
        bufp->chgSData(oldp+346,(vlSelf->top__DOT__cse__DOT__mem[24]),16);
        bufp->chgSData(oldp+347,(vlSelf->top__DOT__cse_n__DOT__mem[0]),16);
        bufp->chgSData(oldp+348,(vlSelf->top__DOT__cse_n__DOT__mem[1]),16);
        bufp->chgSData(oldp+349,(vlSelf->top__DOT__cse_n__DOT__mem[2]),16);
        bufp->chgSData(oldp+350,(vlSelf->top__DOT__cse_n__DOT__mem[3]),16);
        bufp->chgSData(oldp+351,(vlSelf->top__DOT__cse_n__DOT__mem[4]),16);
        bufp->chgSData(oldp+352,(vlSelf->top__DOT__cse_n__DOT__mem[5]),16);
        bufp->chgSData(oldp+353,(vlSelf->top__DOT__cse_n__DOT__mem[6]),16);
        bufp->chgSData(oldp+354,(vlSelf->top__DOT__cse_n__DOT__mem[7]),16);
        bufp->chgSData(oldp+355,(vlSelf->top__DOT__cse_n__DOT__mem[8]),16);
        bufp->chgSData(oldp+356,(vlSelf->top__DOT__cse_n__DOT__mem[9]),16);
        bufp->chgSData(oldp+357,(vlSelf->top__DOT__cse_n__DOT__mem[10]),16);
        bufp->chgSData(oldp+358,(vlSelf->top__DOT__cse_n__DOT__mem[11]),16);
        bufp->chgSData(oldp+359,(vlSelf->top__DOT__cse_n__DOT__mem[12]),16);
        bufp->chgSData(oldp+360,(vlSelf->top__DOT__cse_n__DOT__mem[13]),16);
        bufp->chgSData(oldp+361,(vlSelf->top__DOT__cse_n__DOT__mem[14]),16);
        bufp->chgSData(oldp+362,(vlSelf->top__DOT__cse_n__DOT__mem[15]),16);
        bufp->chgSData(oldp+363,(vlSelf->top__DOT__cse_n__DOT__mem[16]),16);
        bufp->chgSData(oldp+364,(vlSelf->top__DOT__cse_n__DOT__mem[17]),16);
        bufp->chgSData(oldp+365,(vlSelf->top__DOT__cse_n__DOT__mem[18]),16);
        bufp->chgSData(oldp+366,(vlSelf->top__DOT__cse_n__DOT__mem[19]),16);
        bufp->chgSData(oldp+367,(vlSelf->top__DOT__cse_n__DOT__mem[20]),16);
        bufp->chgSData(oldp+368,(vlSelf->top__DOT__cse_n__DOT__mem[21]),16);
        bufp->chgSData(oldp+369,(vlSelf->top__DOT__cse_n__DOT__mem[22]),16);
        bufp->chgSData(oldp+370,(vlSelf->top__DOT__cse_n__DOT__mem[23]),16);
        bufp->chgSData(oldp+371,(vlSelf->top__DOT__cse_n__DOT__mem[24]),16);
        bufp->chgSData(oldp+372,(vlSelf->top__DOT__csw__DOT__mem[0]),16);
        bufp->chgSData(oldp+373,(vlSelf->top__DOT__csw__DOT__mem[1]),16);
        bufp->chgSData(oldp+374,(vlSelf->top__DOT__csw__DOT__mem[2]),16);
        bufp->chgSData(oldp+375,(vlSelf->top__DOT__csw__DOT__mem[3]),16);
        bufp->chgSData(oldp+376,(vlSelf->top__DOT__csw__DOT__mem[4]),16);
        bufp->chgSData(oldp+377,(vlSelf->top__DOT__csw__DOT__mem[5]),16);
        bufp->chgSData(oldp+378,(vlSelf->top__DOT__csw__DOT__mem[6]),16);
        bufp->chgSData(oldp+379,(vlSelf->top__DOT__csw__DOT__mem[7]),16);
        bufp->chgSData(oldp+380,(vlSelf->top__DOT__csw__DOT__mem[8]),16);
        bufp->chgSData(oldp+381,(vlSelf->top__DOT__csw__DOT__mem[9]),16);
        bufp->chgSData(oldp+382,(vlSelf->top__DOT__csw__DOT__mem[10]),16);
        bufp->chgSData(oldp+383,(vlSelf->top__DOT__csw__DOT__mem[11]),16);
        bufp->chgSData(oldp+384,(vlSelf->top__DOT__csw__DOT__mem[12]),16);
        bufp->chgSData(oldp+385,(vlSelf->top__DOT__csw__DOT__mem[13]),16);
        bufp->chgSData(oldp+386,(vlSelf->top__DOT__csw__DOT__mem[14]),16);
        bufp->chgSData(oldp+387,(vlSelf->top__DOT__csw__DOT__mem[15]),16);
        bufp->chgSData(oldp+388,(vlSelf->top__DOT__csw__DOT__mem[16]),16);
        bufp->chgSData(oldp+389,(vlSelf->top__DOT__csw__DOT__mem[17]),16);
        bufp->chgSData(oldp+390,(vlSelf->top__DOT__csw__DOT__mem[18]),16);
        bufp->chgSData(oldp+391,(vlSelf->top__DOT__csw__DOT__mem[19]),16);
        bufp->chgSData(oldp+392,(vlSelf->top__DOT__csw__DOT__mem[20]),16);
        bufp->chgSData(oldp+393,(vlSelf->top__DOT__csw__DOT__mem[21]),16);
        bufp->chgSData(oldp+394,(vlSelf->top__DOT__csw__DOT__mem[22]),16);
        bufp->chgSData(oldp+395,(vlSelf->top__DOT__csw__DOT__mem[23]),16);
        bufp->chgSData(oldp+396,(vlSelf->top__DOT__csw__DOT__mem[24]),16);
        bufp->chgSData(oldp+397,(vlSelf->top__DOT__csw_n__DOT__mem[0]),16);
        bufp->chgSData(oldp+398,(vlSelf->top__DOT__csw_n__DOT__mem[1]),16);
        bufp->chgSData(oldp+399,(vlSelf->top__DOT__csw_n__DOT__mem[2]),16);
        bufp->chgSData(oldp+400,(vlSelf->top__DOT__csw_n__DOT__mem[3]),16);
        bufp->chgSData(oldp+401,(vlSelf->top__DOT__csw_n__DOT__mem[4]),16);
        bufp->chgSData(oldp+402,(vlSelf->top__DOT__csw_n__DOT__mem[5]),16);
        bufp->chgSData(oldp+403,(vlSelf->top__DOT__csw_n__DOT__mem[6]),16);
        bufp->chgSData(oldp+404,(vlSelf->top__DOT__csw_n__DOT__mem[7]),16);
        bufp->chgSData(oldp+405,(vlSelf->top__DOT__csw_n__DOT__mem[8]),16);
        bufp->chgSData(oldp+406,(vlSelf->top__DOT__csw_n__DOT__mem[9]),16);
        bufp->chgSData(oldp+407,(vlSelf->top__DOT__csw_n__DOT__mem[10]),16);
        bufp->chgSData(oldp+408,(vlSelf->top__DOT__csw_n__DOT__mem[11]),16);
        bufp->chgSData(oldp+409,(vlSelf->top__DOT__csw_n__DOT__mem[12]),16);
        bufp->chgSData(oldp+410,(vlSelf->top__DOT__csw_n__DOT__mem[13]),16);
        bufp->chgSData(oldp+411,(vlSelf->top__DOT__csw_n__DOT__mem[14]),16);
        bufp->chgSData(oldp+412,(vlSelf->top__DOT__csw_n__DOT__mem[15]),16);
        bufp->chgSData(oldp+413,(vlSelf->top__DOT__csw_n__DOT__mem[16]),16);
        bufp->chgSData(oldp+414,(vlSelf->top__DOT__csw_n__DOT__mem[17]),16);
        bufp->chgSData(oldp+415,(vlSelf->top__DOT__csw_n__DOT__mem[18]),16);
        bufp->chgSData(oldp+416,(vlSelf->top__DOT__csw_n__DOT__mem[19]),16);
        bufp->chgSData(oldp+417,(vlSelf->top__DOT__csw_n__DOT__mem[20]),16);
        bufp->chgSData(oldp+418,(vlSelf->top__DOT__csw_n__DOT__mem[21]),16);
        bufp->chgSData(oldp+419,(vlSelf->top__DOT__csw_n__DOT__mem[22]),16);
        bufp->chgSData(oldp+420,(vlSelf->top__DOT__csw_n__DOT__mem[23]),16);
        bufp->chgSData(oldp+421,(vlSelf->top__DOT__csw_n__DOT__mem[24]),16);
        bufp->chgSData(oldp+422,(vlSelf->top__DOT__cw__DOT__mem[0]),16);
        bufp->chgSData(oldp+423,(vlSelf->top__DOT__cw__DOT__mem[1]),16);
        bufp->chgSData(oldp+424,(vlSelf->top__DOT__cw__DOT__mem[2]),16);
        bufp->chgSData(oldp+425,(vlSelf->top__DOT__cw__DOT__mem[3]),16);
        bufp->chgSData(oldp+426,(vlSelf->top__DOT__cw__DOT__mem[4]),16);
        bufp->chgSData(oldp+427,(vlSelf->top__DOT__cw__DOT__mem[5]),16);
        bufp->chgSData(oldp+428,(vlSelf->top__DOT__cw__DOT__mem[6]),16);
        bufp->chgSData(oldp+429,(vlSelf->top__DOT__cw__DOT__mem[7]),16);
        bufp->chgSData(oldp+430,(vlSelf->top__DOT__cw__DOT__mem[8]),16);
        bufp->chgSData(oldp+431,(vlSelf->top__DOT__cw__DOT__mem[9]),16);
        bufp->chgSData(oldp+432,(vlSelf->top__DOT__cw__DOT__mem[10]),16);
        bufp->chgSData(oldp+433,(vlSelf->top__DOT__cw__DOT__mem[11]),16);
        bufp->chgSData(oldp+434,(vlSelf->top__DOT__cw__DOT__mem[12]),16);
        bufp->chgSData(oldp+435,(vlSelf->top__DOT__cw__DOT__mem[13]),16);
        bufp->chgSData(oldp+436,(vlSelf->top__DOT__cw__DOT__mem[14]),16);
        bufp->chgSData(oldp+437,(vlSelf->top__DOT__cw__DOT__mem[15]),16);
        bufp->chgSData(oldp+438,(vlSelf->top__DOT__cw__DOT__mem[16]),16);
        bufp->chgSData(oldp+439,(vlSelf->top__DOT__cw__DOT__mem[17]),16);
        bufp->chgSData(oldp+440,(vlSelf->top__DOT__cw__DOT__mem[18]),16);
        bufp->chgSData(oldp+441,(vlSelf->top__DOT__cw__DOT__mem[19]),16);
        bufp->chgSData(oldp+442,(vlSelf->top__DOT__cw__DOT__mem[20]),16);
        bufp->chgSData(oldp+443,(vlSelf->top__DOT__cw__DOT__mem[21]),16);
        bufp->chgSData(oldp+444,(vlSelf->top__DOT__cw__DOT__mem[22]),16);
        bufp->chgSData(oldp+445,(vlSelf->top__DOT__cw__DOT__mem[23]),16);
        bufp->chgSData(oldp+446,(vlSelf->top__DOT__cw__DOT__mem[24]),16);
        bufp->chgSData(oldp+447,(vlSelf->top__DOT__cw_n__DOT__mem[0]),16);
        bufp->chgSData(oldp+448,(vlSelf->top__DOT__cw_n__DOT__mem[1]),16);
        bufp->chgSData(oldp+449,(vlSelf->top__DOT__cw_n__DOT__mem[2]),16);
        bufp->chgSData(oldp+450,(vlSelf->top__DOT__cw_n__DOT__mem[3]),16);
        bufp->chgSData(oldp+451,(vlSelf->top__DOT__cw_n__DOT__mem[4]),16);
        bufp->chgSData(oldp+452,(vlSelf->top__DOT__cw_n__DOT__mem[5]),16);
        bufp->chgSData(oldp+453,(vlSelf->top__DOT__cw_n__DOT__mem[6]),16);
        bufp->chgSData(oldp+454,(vlSelf->top__DOT__cw_n__DOT__mem[7]),16);
        bufp->chgSData(oldp+455,(vlSelf->top__DOT__cw_n__DOT__mem[8]),16);
        bufp->chgSData(oldp+456,(vlSelf->top__DOT__cw_n__DOT__mem[9]),16);
        bufp->chgSData(oldp+457,(vlSelf->top__DOT__cw_n__DOT__mem[10]),16);
        bufp->chgSData(oldp+458,(vlSelf->top__DOT__cw_n__DOT__mem[11]),16);
        bufp->chgSData(oldp+459,(vlSelf->top__DOT__cw_n__DOT__mem[12]),16);
        bufp->chgSData(oldp+460,(vlSelf->top__DOT__cw_n__DOT__mem[13]),16);
        bufp->chgSData(oldp+461,(vlSelf->top__DOT__cw_n__DOT__mem[14]),16);
        bufp->chgSData(oldp+462,(vlSelf->top__DOT__cw_n__DOT__mem[15]),16);
        bufp->chgSData(oldp+463,(vlSelf->top__DOT__cw_n__DOT__mem[16]),16);
        bufp->chgSData(oldp+464,(vlSelf->top__DOT__cw_n__DOT__mem[17]),16);
        bufp->chgSData(oldp+465,(vlSelf->top__DOT__cw_n__DOT__mem[18]),16);
        bufp->chgSData(oldp+466,(vlSelf->top__DOT__cw_n__DOT__mem[19]),16);
        bufp->chgSData(oldp+467,(vlSelf->top__DOT__cw_n__DOT__mem[20]),16);
        bufp->chgSData(oldp+468,(vlSelf->top__DOT__cw_n__DOT__mem[21]),16);
        bufp->chgSData(oldp+469,(vlSelf->top__DOT__cw_n__DOT__mem[22]),16);
        bufp->chgSData(oldp+470,(vlSelf->top__DOT__cw_n__DOT__mem[23]),16);
        bufp->chgSData(oldp+471,(vlSelf->top__DOT__cw_n__DOT__mem[24]),16);
        bufp->chgSData(oldp+472,((0xffffU & ((((((IData)(vlSelf->top__DOT__ce_n_data_out) 
                                                 - (IData)(vlSelf->top__DOT__cw_n_data_out)) 
                                                + (IData)(vlSelf->top__DOT__cne_n_data_out)) 
                                               - (IData)(vlSelf->top__DOT__csw_n_data_out)) 
                                              - (IData)(vlSelf->top__DOT__cnw_n_data_out)) 
                                             + (IData)(vlSelf->top__DOT__cse_n_data_out)))),16);
        bufp->chgSData(oldp+473,((0xffffU & ((((((IData)(vlSelf->top__DOT__cn_n_data_out) 
                                                 - (IData)(vlSelf->top__DOT__cs_n_data_out)) 
                                                + (IData)(vlSelf->top__DOT__cne_n_data_out)) 
                                               - (IData)(vlSelf->top__DOT__csw_n_data_out)) 
                                              + (IData)(vlSelf->top__DOT__cnw_n_data_out)) 
                                             - (IData)(vlSelf->top__DOT__cse_n_data_out)))),16);
        bufp->chgIData(oldp+474,(vlSelf->top__DOT__lbm__DOT__collider__DOT__x2),32);
        bufp->chgIData(oldp+475,(vlSelf->top__DOT__lbm__DOT__collider__DOT__x3),32);
        bufp->chgIData(oldp+476,(VL_MULS_III(32, VL_EXTENDS_II(32,16, 
                                                               (0xffffU 
                                                                & ((((((IData)(vlSelf->top__DOT__ce_n_data_out) 
                                                                       - (IData)(vlSelf->top__DOT__cw_n_data_out)) 
                                                                      + (IData)(vlSelf->top__DOT__cne_n_data_out)) 
                                                                     - (IData)(vlSelf->top__DOT__csw_n_data_out)) 
                                                                    - (IData)(vlSelf->top__DOT__cnw_n_data_out)) 
                                                                   + (IData)(vlSelf->top__DOT__cse_n_data_out)))), 
                                             VL_SHIFTRS_III(32,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x3, 0xdU))),32);
        bufp->chgIData(oldp+477,(VL_MULS_III(32, VL_EXTENDS_II(32,16, 
                                                               (0xffffU 
                                                                & ((((((IData)(vlSelf->top__DOT__cn_n_data_out) 
                                                                       - (IData)(vlSelf->top__DOT__cs_n_data_out)) 
                                                                      + (IData)(vlSelf->top__DOT__cne_n_data_out)) 
                                                                     - (IData)(vlSelf->top__DOT__csw_n_data_out)) 
                                                                    + (IData)(vlSelf->top__DOT__cnw_n_data_out)) 
                                                                   - (IData)(vlSelf->top__DOT__cse_n_data_out)))), 
                                             VL_SHIFTRS_III(32,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x3, 0xdU))),32);
        bufp->chgIData(oldp+478,(vlSelf->top__DOT__lbm__DOT__collider__DOT__u_x_squared_intermediate),32);
        bufp->chgIData(oldp+479,(vlSelf->top__DOT__lbm__DOT__collider__DOT__u_y_squared_intermediate),32);
        bufp->chgSData(oldp+480,((0xffffU & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__u_x_squared_intermediate, 0xdU))),16);
        bufp->chgSData(oldp+481,((0xffffU & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__u_y_squared_intermediate, 0xdU))),16);
        bufp->chgIData(oldp+482,(VL_MULS_III(32, (IData)(0x4800U), 
                                             (VL_EXTENDS_II(32,16, 
                                                            (0xffffU 
                                                             & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__u_x_squared_intermediate, 0xdU))) 
                                              << 1U))),32);
        bufp->chgIData(oldp+483,(VL_MULS_III(32, (IData)(0x4800U), 
                                             (VL_EXTENDS_II(32,16, 
                                                            (0xffffU 
                                                             & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__u_y_squared_intermediate, 0xdU))) 
                                              << 1U))),32);
        bufp->chgSData(oldp+484,((0xffffU & VL_SHIFTRS_III(16,32,32, 
                                                           VL_MULS_III(32, (IData)(0x4800U), 
                                                                       (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__u_x_squared_intermediate, 0xdU))) 
                                                                        << 1U)), 0xdU))),16);
        bufp->chgSData(oldp+485,((0xffffU & VL_SHIFTRS_III(16,32,32, 
                                                           VL_MULS_III(32, (IData)(0x4800U), 
                                                                       (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__u_y_squared_intermediate, 0xdU))) 
                                                                        << 1U)), 0xdU))),16);
        bufp->chgSData(oldp+486,(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y),16);
        bufp->chgSData(oldp+487,(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y),16);
        bufp->chgSData(oldp+488,((0xffffU & (- (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y)))),16);
        bufp->chgSData(oldp+489,((0xffffU & (- (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y)))),16);
        bufp->chgIData(oldp+490,(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y_squared_intermediate),32);
        bufp->chgSData(oldp+491,((0xffffU & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y_squared_intermediate, 0xdU))),16);
        bufp->chgIData(oldp+492,(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y_squared_intermediate),32);
        bufp->chgSData(oldp+493,((0xffffU & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y_squared_intermediate, 0xdU))),16);
        bufp->chgIData(oldp+494,(VL_MULS_III(32, (IData)(0x6000U), 
                                             VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y)))),32);
        bufp->chgSData(oldp+495,((0xffffU & VL_SHIFTRS_III(16,32,32, 
                                                           VL_MULS_III(32, (IData)(0x6000U), 
                                                                       VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y))), 0xdU))),16);
        bufp->chgIData(oldp+496,(VL_MULS_III(32, (IData)(0x6000U), 
                                             VL_EXTENDS_II(32,16, 
                                                           (0xffffU 
                                                            & (- (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y)))))),32);
        bufp->chgSData(oldp+497,((0xffffU & VL_SHIFTRS_III(16,32,32, 
                                                           VL_MULS_III(32, (IData)(0x6000U), 
                                                                       VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & (- (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y))))), 0xdU))),16);
        bufp->chgIData(oldp+498,(VL_MULS_III(32, (IData)(0x6000U), 
                                             VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y)))),32);
        bufp->chgSData(oldp+499,((0xffffU & VL_SHIFTRS_III(16,32,32, 
                                                           VL_MULS_III(32, (IData)(0x6000U), 
                                                                       VL_EXTENDS_II(32,16, (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y))), 0xdU))),16);
        bufp->chgIData(oldp+500,(VL_MULS_III(32, (IData)(0x6000U), 
                                             VL_EXTENDS_II(32,16, 
                                                           (0xffffU 
                                                            & (- (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y)))))),32);
        bufp->chgSData(oldp+501,((0xffffU & VL_SHIFTRS_III(16,32,32, 
                                                           VL_MULS_III(32, (IData)(0x6000U), 
                                                                       VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & (- (IData)(vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y))))), 0xdU))),16);
        bufp->chgIData(oldp+502,(VL_MULS_III(32, (IData)(0x4800U), 
                                             (VL_EXTENDS_II(32,16, 
                                                            (0xffffU 
                                                             & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y_squared_intermediate, 0xdU))) 
                                              << 1U))),32);
        bufp->chgSData(oldp+503,((0xffffU & VL_SHIFTRS_III(16,32,32, 
                                                           VL_MULS_III(32, (IData)(0x4800U), 
                                                                       (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x_plus_y_squared_intermediate, 0xdU))) 
                                                                        << 1U)), 0xdU))),16);
        bufp->chgIData(oldp+504,(VL_MULS_III(32, (IData)(0x4800U), 
                                             (VL_EXTENDS_II(32,16, 
                                                            (0xffffU 
                                                             & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y_squared_intermediate, 0xdU))) 
                                              << 1U))),32);
        bufp->chgSData(oldp+505,((0xffffU & VL_SHIFTRS_III(16,32,32, 
                                                           VL_MULS_III(32, (IData)(0x4800U), 
                                                                       (VL_EXTENDS_II(32,16, 
                                                                                (0xffffU 
                                                                                & VL_SHIFTRS_III(16,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x_minus_y_squared_intermediate, 0xdU))) 
                                                                        << 1U)), 0xdU))),16);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgSData(oldp+506,(vlSelf->top__DOT__c0_addr),13);
        bufp->chgSData(oldp+507,(vlSelf->top__DOT__c0_n_addr),13);
        bufp->chgSData(oldp+508,(vlSelf->top__DOT__cn_addr),13);
        bufp->chgSData(oldp+509,(vlSelf->top__DOT__cn_n_addr),13);
        bufp->chgSData(oldp+510,(vlSelf->top__DOT__cne_addr),13);
        bufp->chgSData(oldp+511,(vlSelf->top__DOT__cne_n_addr),13);
        bufp->chgSData(oldp+512,(vlSelf->top__DOT__ce_addr),13);
        bufp->chgSData(oldp+513,(vlSelf->top__DOT__ce_n_addr),13);
        bufp->chgSData(oldp+514,(vlSelf->top__DOT__cse_addr),13);
        bufp->chgSData(oldp+515,(vlSelf->top__DOT__cse_n_addr),13);
        bufp->chgSData(oldp+516,(vlSelf->top__DOT__cs_addr),13);
        bufp->chgSData(oldp+517,(vlSelf->top__DOT__cs_n_addr),13);
        bufp->chgSData(oldp+518,(vlSelf->top__DOT__csw_addr),13);
        bufp->chgSData(oldp+519,(vlSelf->top__DOT__csw_n_addr),13);
        bufp->chgSData(oldp+520,(vlSelf->top__DOT__cw_addr),13);
        bufp->chgSData(oldp+521,(vlSelf->top__DOT__cw_n_addr),13);
        bufp->chgSData(oldp+522,(vlSelf->top__DOT__cnw_addr),13);
        bufp->chgSData(oldp+523,(vlSelf->top__DOT__cnw_n_addr),13);
        bufp->chgSData(oldp+524,(vlSelf->top__DOT__c0_data_in),16);
        bufp->chgSData(oldp+525,(vlSelf->top__DOT__c0_n_data_in),16);
        bufp->chgSData(oldp+526,(vlSelf->top__DOT__cn_data_in),16);
        bufp->chgSData(oldp+527,(vlSelf->top__DOT__cn_n_data_in),16);
        bufp->chgSData(oldp+528,(vlSelf->top__DOT__cne_data_in),16);
        bufp->chgSData(oldp+529,(vlSelf->top__DOT__cne_n_data_in),16);
        bufp->chgSData(oldp+530,(vlSelf->top__DOT__ce_data_in),16);
        bufp->chgSData(oldp+531,(vlSelf->top__DOT__ce_n_data_in),16);
        bufp->chgSData(oldp+532,(vlSelf->top__DOT__cse_data_in),16);
        bufp->chgSData(oldp+533,(vlSelf->top__DOT__cse_n_data_in),16);
        bufp->chgSData(oldp+534,(vlSelf->top__DOT__cs_data_in),16);
        bufp->chgSData(oldp+535,(vlSelf->top__DOT__cs_n_data_in),16);
        bufp->chgSData(oldp+536,(vlSelf->top__DOT__csw_data_in),16);
        bufp->chgSData(oldp+537,(vlSelf->top__DOT__csw_n_data_in),16);
        bufp->chgSData(oldp+538,(vlSelf->top__DOT__cw_data_in),16);
        bufp->chgSData(oldp+539,(vlSelf->top__DOT__cw_n_data_in),16);
        bufp->chgSData(oldp+540,(vlSelf->top__DOT__cnw_data_in),16);
        bufp->chgSData(oldp+541,(vlSelf->top__DOT__cnw_n_data_in),16);
        bufp->chgBit(oldp+542,(vlSelf->top__DOT__c0_write_en));
        bufp->chgBit(oldp+543,(vlSelf->top__DOT__c0_n_write_en));
        bufp->chgBit(oldp+544,(vlSelf->top__DOT__cn_write_en));
        bufp->chgBit(oldp+545,(vlSelf->top__DOT__cn_n_write_en));
        bufp->chgBit(oldp+546,(vlSelf->top__DOT__cne_write_en));
        bufp->chgBit(oldp+547,(vlSelf->top__DOT__cne_n_write_en));
        bufp->chgBit(oldp+548,(vlSelf->top__DOT__ce_write_en));
        bufp->chgBit(oldp+549,(vlSelf->top__DOT__ce_n_write_en));
        bufp->chgBit(oldp+550,(vlSelf->top__DOT__cse_write_en));
        bufp->chgBit(oldp+551,(vlSelf->top__DOT__cse_n_write_en));
        bufp->chgBit(oldp+552,(vlSelf->top__DOT__cs_write_en));
        bufp->chgBit(oldp+553,(vlSelf->top__DOT__cs_n_write_en));
        bufp->chgBit(oldp+554,(vlSelf->top__DOT__csw_write_en));
        bufp->chgBit(oldp+555,(vlSelf->top__DOT__csw_n_write_en));
        bufp->chgBit(oldp+556,(vlSelf->top__DOT__cw_write_en));
        bufp->chgBit(oldp+557,(vlSelf->top__DOT__cw_n_write_en));
        bufp->chgBit(oldp+558,(vlSelf->top__DOT__cnw_write_en));
        bufp->chgBit(oldp+559,(vlSelf->top__DOT__cnw_n_write_en));
        bufp->chgSData(oldp+560,(vlSelf->top__DOT__lbm__DOT__index),13);
        bufp->chgBit(oldp+561,(vlSelf->top__DOT__lbm__DOT__c0_next_write_en));
        bufp->chgBit(oldp+562,(vlSelf->top__DOT__lbm__DOT__cn_next_write_en));
        bufp->chgBit(oldp+563,(vlSelf->top__DOT__lbm__DOT__cne_next_write_en));
        bufp->chgBit(oldp+564,(vlSelf->top__DOT__lbm__DOT__ce_next_write_en));
        bufp->chgBit(oldp+565,(vlSelf->top__DOT__lbm__DOT__cse_next_write_en));
        bufp->chgBit(oldp+566,(vlSelf->top__DOT__lbm__DOT__cs_next_write_en));
        bufp->chgBit(oldp+567,(vlSelf->top__DOT__lbm__DOT__csw_next_write_en));
        bufp->chgBit(oldp+568,(vlSelf->top__DOT__lbm__DOT__cw_next_write_en));
        bufp->chgBit(oldp+569,(vlSelf->top__DOT__lbm__DOT__cnw_next_write_en));
        bufp->chgBit(oldp+570,(vlSelf->top__DOT__lbm__DOT__incr_step));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[4U])) {
        bufp->chgSData(oldp+571,(vlSelf->top__DOT__lbm__DOT__next_width_count),16);
        bufp->chgCData(oldp+572,(vlSelf->top__DOT__lbm__DOT__next_sim_state),4);
        bufp->chgSData(oldp+573,(vlSelf->top__DOT__lbm__DOT__next_index),13);
        bufp->chgSData(oldp+574,(vlSelf->top__DOT__lbm__DOT__c0_next_data_in),16);
        bufp->chgBit(oldp+575,(vlSelf->top__DOT__lbm__DOT__c0_n_next_write_en));
        bufp->chgSData(oldp+576,(vlSelf->top__DOT__lbm__DOT__c0_next_write_addr),13);
        bufp->chgSData(oldp+577,(vlSelf->top__DOT__lbm__DOT__cn_next_data_in),16);
        bufp->chgBit(oldp+578,(vlSelf->top__DOT__lbm__DOT__cn_n_next_write_en));
        bufp->chgSData(oldp+579,(vlSelf->top__DOT__lbm__DOT__cn_next_write_addr),13);
        bufp->chgSData(oldp+580,(vlSelf->top__DOT__lbm__DOT__cne_next_data_in),16);
        bufp->chgBit(oldp+581,(vlSelf->top__DOT__lbm__DOT__cne_n_next_write_en));
        bufp->chgSData(oldp+582,(vlSelf->top__DOT__lbm__DOT__cne_next_write_addr),13);
        bufp->chgSData(oldp+583,(vlSelf->top__DOT__lbm__DOT__ce_next_data_in),16);
        bufp->chgBit(oldp+584,(vlSelf->top__DOT__lbm__DOT__ce_n_next_write_en));
        bufp->chgSData(oldp+585,(vlSelf->top__DOT__lbm__DOT__ce_next_write_addr),13);
        bufp->chgSData(oldp+586,(vlSelf->top__DOT__lbm__DOT__cse_next_data_in),16);
        bufp->chgBit(oldp+587,(vlSelf->top__DOT__lbm__DOT__cse_n_next_write_en));
        bufp->chgSData(oldp+588,(vlSelf->top__DOT__lbm__DOT__cse_next_write_addr),13);
        bufp->chgSData(oldp+589,(vlSelf->top__DOT__lbm__DOT__cs_next_data_in),16);
        bufp->chgBit(oldp+590,(vlSelf->top__DOT__lbm__DOT__cs_n_next_write_en));
        bufp->chgSData(oldp+591,(vlSelf->top__DOT__lbm__DOT__cs_next_write_addr),13);
        bufp->chgSData(oldp+592,(vlSelf->top__DOT__lbm__DOT__csw_next_data_in),16);
        bufp->chgBit(oldp+593,(vlSelf->top__DOT__lbm__DOT__csw_n_next_write_en));
        bufp->chgSData(oldp+594,(vlSelf->top__DOT__lbm__DOT__csw_next_write_addr),13);
        bufp->chgSData(oldp+595,(vlSelf->top__DOT__lbm__DOT__cw_next_data_in),16);
        bufp->chgBit(oldp+596,(vlSelf->top__DOT__lbm__DOT__cw_n_next_write_en));
        bufp->chgSData(oldp+597,(vlSelf->top__DOT__lbm__DOT__cw_next_write_addr),13);
        bufp->chgSData(oldp+598,(vlSelf->top__DOT__lbm__DOT__cnw_next_data_in),16);
        bufp->chgBit(oldp+599,(vlSelf->top__DOT__lbm__DOT__cnw_n_next_write_en));
        bufp->chgSData(oldp+600,(vlSelf->top__DOT__lbm__DOT__cnw_next_write_addr),13);
        bufp->chgCData(oldp+601,(vlSelf->top__DOT__lbm__DOT__next_ram_wait_count),3);
        bufp->chgSData(oldp+602,(vlSelf->top__DOT__lbm__DOT__c_cn),16);
        bufp->chgSData(oldp+603,(vlSelf->top__DOT__lbm__DOT__c_cne),16);
        bufp->chgSData(oldp+604,(vlSelf->top__DOT__lbm__DOT__c_ce),16);
        bufp->chgSData(oldp+605,(vlSelf->top__DOT__lbm__DOT__c_cse),16);
        bufp->chgSData(oldp+606,(vlSelf->top__DOT__lbm__DOT__c_cs),16);
        bufp->chgSData(oldp+607,(vlSelf->top__DOT__lbm__DOT__c_csw),16);
        bufp->chgSData(oldp+608,(vlSelf->top__DOT__lbm__DOT__c_cw),16);
        bufp->chgSData(oldp+609,(vlSelf->top__DOT__lbm__DOT__c_cnw),16);
    }
    bufp->chgBit(oldp+610,(vlSelf->clk));
    bufp->chgBit(oldp+611,(vlSelf->rst));
    bufp->chgBit(oldp+612,(vlSelf->en));
    bufp->chgIData(oldp+613,(vlSelf->step),32);
    bufp->chgIData(oldp+614,(vlSelf->barriers),25);
    bufp->chgSData(oldp+615,(vlSelf->omega),16);
    bufp->chgSData(oldp+616,(vlSelf->init_c0),16);
    bufp->chgSData(oldp+617,(vlSelf->init_cn),16);
    bufp->chgSData(oldp+618,(vlSelf->init_cne),16);
    bufp->chgSData(oldp+619,(vlSelf->init_ce),16);
    bufp->chgSData(oldp+620,(vlSelf->init_cse),16);
    bufp->chgSData(oldp+621,(vlSelf->init_cs),16);
    bufp->chgSData(oldp+622,(vlSelf->init_csw),16);
    bufp->chgSData(oldp+623,(vlSelf->init_cw),16);
    bufp->chgSData(oldp+624,(vlSelf->init_cnw),16);
    bufp->chgSData(oldp+625,(vlSelf->testing_cs_n_data_in),16);
    bufp->chgSData(oldp+626,(vlSelf->testing_c0_data_in),16);
    bufp->chgSData(oldp+627,(vlSelf->u_x),16);
    bufp->chgSData(oldp+628,(vlSelf->u_y),16);
    bufp->chgSData(oldp+629,(vlSelf->rho),16);
    bufp->chgSData(oldp+630,(vlSelf->u_squared),16);
    bufp->chgBit(oldp+631,(vlSelf->collider_ready));
    bufp->chgBit(oldp+632,(vlSelf->in_collision_state));
    bufp->chgSData(oldp+633,((0xffffU & vlSelf->step)),16);
    bufp->chgSData(oldp+634,((0xffffU & ((IData)(vlSelf->rho) 
                                         - ((((((((IData)(vlSelf->top__DOT__lbm__DOT__c_cn) 
                                                  + (IData)(vlSelf->top__DOT__lbm__DOT__c_cne)) 
                                                 + (IData)(vlSelf->top__DOT__lbm__DOT__c_ce)) 
                                                + (IData)(vlSelf->top__DOT__lbm__DOT__c_cse)) 
                                               + (IData)(vlSelf->top__DOT__lbm__DOT__c_cs)) 
                                              + (IData)(vlSelf->top__DOT__lbm__DOT__c_csw)) 
                                             + (IData)(vlSelf->top__DOT__lbm__DOT__c_cw)) 
                                            + (IData)(vlSelf->top__DOT__lbm__DOT__c_cnw))))),16);
    bufp->chgIData(oldp+635,(VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
                                         ((IData)(0x4000U) 
                                          - VL_EXTENDS_II(32,16, (IData)(vlSelf->rho))))),32);
    bufp->chgIData(oldp+636,(VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
                                         VL_SHIFTRS_III(32,32,32, vlSelf->top__DOT__lbm__DOT__collider__DOT__x2, 0xdU))),32);
    bufp->chgIData(oldp+637,(VL_MULS_III(32, (IData)(0x3000U), 
                                         VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared)))),32);
    bufp->chgSData(oldp+638,((0xffffU & VL_SHIFTRS_III(16,32,32, 
                                                       VL_MULS_III(32, (IData)(0x3000U), 
                                                                   VL_EXTENDS_II(32,16, (IData)(vlSelf->u_squared))), 0xdU))),16);
    bufp->chgIData(oldp+639,(VL_MULS_III(32, (IData)(0x6000U), 
                                         VL_EXTENDS_II(32,16, (IData)(vlSelf->u_x)))),32);
    bufp->chgIData(oldp+640,(VL_MULS_III(32, (IData)(0x6000U), 
                                         VL_EXTENDS_II(32,16, (IData)(vlSelf->u_y)))),32);
    bufp->chgSData(oldp+641,((0xffffU & VL_SHIFTRS_III(16,32,32, 
                                                       VL_MULS_III(32, (IData)(0x6000U), 
                                                                   VL_EXTENDS_II(32,16, (IData)(vlSelf->u_x))), 0xdU))),16);
    bufp->chgSData(oldp+642,((0xffffU & VL_SHIFTRS_III(16,32,32, 
                                                       VL_MULS_III(32, (IData)(0x6000U), 
                                                                   VL_EXTENDS_II(32,16, (IData)(vlSelf->u_y))), 0xdU))),16);
    bufp->chgSData(oldp+643,((0xffffU & (((IData)(0x2000U) 
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
    bufp->chgSData(oldp+644,((0xffffU & ((((IData)(0x2000U) 
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
    bufp->chgSData(oldp+645,((0xffffU & (((IData)(0x2000U) 
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
    bufp->chgSData(oldp+646,((0xffffU & ((((IData)(0x2000U) 
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
    bufp->chgIData(oldp+647,(VL_MULS_III(32, (IData)(0x38eU), 
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
    bufp->chgIData(oldp+648,(VL_MULS_III(32, (IData)(0x38eU), 
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
    bufp->chgIData(oldp+649,(VL_MULS_III(32, (IData)(0x38eU), 
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
    bufp->chgIData(oldp+650,(VL_MULS_III(32, (IData)(0x38eU), 
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
    bufp->chgIData(oldp+651,(VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
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
    bufp->chgIData(oldp+652,(VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
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
    bufp->chgIData(oldp+653,(VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
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
    bufp->chgIData(oldp+654,(VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
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
    bufp->chgSData(oldp+655,((0xffffU & VL_SHIFTRS_III(16,32,32, 
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
    bufp->chgSData(oldp+656,((0xffffU & VL_SHIFTRS_III(16,32,32, 
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
    bufp->chgSData(oldp+657,((0xffffU & VL_SHIFTRS_III(16,32,32, 
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
    bufp->chgSData(oldp+658,((0xffffU & VL_SHIFTRS_III(16,32,32, 
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
    bufp->chgSData(oldp+659,((0xffffU & (((IData)(0x2000U) 
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
    bufp->chgSData(oldp+660,((0xffffU & (((IData)(0x2000U) 
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
    bufp->chgSData(oldp+661,((0xffffU & (((IData)(0x2000U) 
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
    bufp->chgSData(oldp+662,((0xffffU & (((IData)(0x2000U) 
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
    bufp->chgIData(oldp+663,(VL_MULS_III(32, (IData)(0xe4U), 
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
    bufp->chgIData(oldp+664,(VL_MULS_III(32, (IData)(0xe4U), 
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
    bufp->chgIData(oldp+665,(VL_MULS_III(32, (IData)(0xe4U), 
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
    bufp->chgIData(oldp+666,(VL_MULS_III(32, (IData)(0xe4U), 
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
    bufp->chgIData(oldp+667,(VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
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
    bufp->chgIData(oldp+668,(VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
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
    bufp->chgIData(oldp+669,(VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
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
    bufp->chgIData(oldp+670,(VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->rho)), 
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
    bufp->chgSData(oldp+671,((0xffffU & VL_SHIFTRS_III(16,32,32, 
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
    bufp->chgSData(oldp+672,((0xffffU & VL_SHIFTRS_III(16,32,32, 
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
    bufp->chgSData(oldp+673,((0xffffU & VL_SHIFTRS_III(16,32,32, 
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
    bufp->chgSData(oldp+674,((0xffffU & VL_SHIFTRS_III(16,32,32, 
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
    bufp->chgIData(oldp+675,(VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->omega)), 
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
    bufp->chgIData(oldp+676,(VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->omega)), 
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
    bufp->chgIData(oldp+677,(VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->omega)), 
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
    bufp->chgIData(oldp+678,(VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->omega)), 
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
    bufp->chgIData(oldp+679,(VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->omega)), 
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
    bufp->chgIData(oldp+680,(VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->omega)), 
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
    bufp->chgIData(oldp+681,(VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->omega)), 
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
    bufp->chgIData(oldp+682,(VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->omega)), 
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
}

void Vdut___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_cleanup\n"); );
    // Init
    Vdut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdut___024root*>(voidSelf);
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
}
