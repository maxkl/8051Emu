
#include <iostream>
#include "Processor.h"
#include "ops.h"

namespace emu {

    void nop(Processor& p) {}

    void ajmp1(Processor& p) { printf("\"ajmp1\" called but not implemented\n"); }
    void ajmp2(Processor& p) { printf("\"ajmp2\" called but not implemented\n"); }
    void ajmp3(Processor& p) { printf("\"ajmp3\" called but not implemented\n"); }
    void ajmp4(Processor& p) { printf("\"ajmp4\" called but not implemented\n"); }
    void ajmp5(Processor& p) { printf("\"ajmp5\" called but not implemented\n"); }
    void ajmp6(Processor& p) { printf("\"ajmp6\" called but not implemented\n"); }
    void ajmp7(Processor& p) { printf("\"ajmp7\" called but not implemented\n"); }
    void ajmp8(Processor& p) { printf("\"ajmp8\" called but not implemented\n"); }

    void ljmp(Processor& p) { printf("\"ljmp\" called but not implemented\n"); }
    void sjmp(Processor& p) { p.pc += static_cast<int8_t>(p.fetchRom()); }
    void jmp(Processor& p) { printf("\"jmp\" called but not implemented\n"); }

    void acall1(Processor& p) { printf("\"acall1\" called but not implemented\n"); }
    void acall2(Processor& p) { printf("\"acall2\" called but not implemented\n"); }
    void acall3(Processor& p) { printf("\"acall3\" called but not implemented\n"); }
    void acall4(Processor& p) { printf("\"acall4\" called but not implemented\n"); }
    void acall5(Processor& p) { printf("\"acall5\" called but not implemented\n"); }
    void acall6(Processor& p) { printf("\"acall6\" called but not implemented\n"); }
    void acall7(Processor& p) { printf("\"acall7\" called but not implemented\n"); }
    void acall8(Processor& p) { printf("\"acall8\" called but not implemented\n"); }

    void lcall(Processor& p) { printf("\"lcall\" called but not implemented\n"); }

    void rr(Processor& p) { printf("\"rr\" called but not implemented\n"); }
    void rrc(Processor& p) { printf("\"rrc\" called but not implemented\n"); }
    void rl(Processor& p) { printf("\"rl\" called but not implemented\n"); }
    void rlc(Processor& p) { printf("\"rlc\" called but not implemented\n"); }

    void inc_a(Processor& p) { printf("\"inc_a\" called but not implemented\n"); }
    void inc_dadr(Processor& p) { printf("\"inc_dadr\" called but not implemented\n"); }
    void inc_atr0(Processor& p) { printf("\"inc_atr0\" called but not implemented\n"); }
    void inc_atr1(Processor& p) { printf("\"inc_atr1\" called but not implemented\n"); }
    void inc_r0(Processor& p) { printf("\"inc_r0\" called but not implemented\n"); }
    void inc_r1(Processor& p) { printf("\"inc_r1\" called but not implemented\n"); }
    void inc_r2(Processor& p) { printf("\"inc_r2\" called but not implemented\n"); }
    void inc_r3(Processor& p) { printf("\"inc_r3\" called but not implemented\n"); }
    void inc_r4(Processor& p) { printf("\"inc_r4\" called but not implemented\n"); }
    void inc_r5(Processor& p) { printf("\"inc_r5\" called but not implemented\n"); }
    void inc_r6(Processor& p) { printf("\"inc_r6\" called but not implemented\n"); }
    void inc_r7(Processor& p) { printf("\"inc_r7\" called but not implemented\n"); }
    void inc_dptr(Processor& p) { printf("\"inc_dptr\" called but not implemented\n"); }

    void dec_a(Processor& p) { printf("\"dec_a\" called but not implemented\n"); }
    void dec_dadr(Processor& p) { printf("\"dec_dadr\" called but not implemented\n"); }
    void dec_atr0(Processor& p) { printf("\"dec_atr0\" called but not implemented\n"); }
    void dec_atr1(Processor& p) { printf("\"dec_atr1\" called but not implemented\n"); }
    void dec_r0(Processor& p) { printf("\"dec_r0\" called but not implemented\n"); }
    void dec_r1(Processor& p) { printf("\"dec_r1\" called but not implemented\n"); }
    void dec_r2(Processor& p) { printf("\"dec_r2\" called but not implemented\n"); }
    void dec_r3(Processor& p) { printf("\"dec_r3\" called but not implemented\n"); }
    void dec_r4(Processor& p) { printf("\"dec_r4\" called but not implemented\n"); }
    void dec_r5(Processor& p) { printf("\"dec_r5\" called but not implemented\n"); }
    void dec_r6(Processor& p) { printf("\"dec_r6\" called but not implemented\n"); }
    void dec_r7(Processor& p) { printf("\"dec_r7\" called but not implemented\n"); }

    void jb(Processor& p) { printf("\"jb\" called but not implemented\n"); }
    void jbc(Processor& p) { printf("\"jbc\" called but not implemented\n"); }
    void jnb(Processor& p) { printf("\"jnb\" called but not implemented\n"); }
    void jc(Processor& p) { printf("\"jc\" called but not implemented\n"); }
    void jnc(Processor& p) { printf("\"jnc\" called but not implemented\n"); }
    void jz(Processor& p) { printf("\"jz\" called but not implemented\n"); }
    void jnz(Processor& p) { printf("\"jnz\" called but not implemented\n"); }

    void cjne_a_const(Processor& p) { printf("\"cjne_a_const\" called but not implemented\n"); }
    void cjne_a_dadr(Processor& p) { printf("\"cjne_a_dadr\" called but not implemented\n"); }
    void cjne_atr0_const(Processor& p) { printf("\"cjne_atr0_const\" called but not implemented\n"); }
    void cjne_atr1_const(Processor& p) { printf("\"cjne_atr1_const\" called but not implemented\n"); }
    void cjne_r0_const(Processor& p) { printf("\"cjne_r0_const\" called but not implemented\n"); }
    void cjne_r1_const(Processor& p) { printf("\"cjne_r1_const\" called but not implemented\n"); }
    void cjne_r2_const(Processor& p) { printf("\"cjne_r2_const\" called but not implemented\n"); }
    void cjne_r3_const(Processor& p) { printf("\"cjne_r3_const\" called but not implemented\n"); }
    void cjne_r4_const(Processor& p) { printf("\"cjne_r4_const\" called but not implemented\n"); }
    void cjne_r5_const(Processor& p) { printf("\"cjne_r5_const\" called but not implemented\n"); }
    void cjne_r6_const(Processor& p) { printf("\"cjne_r6_const\" called but not implemented\n"); }
    void cjne_r7_const(Processor& p) { printf("\"cjne_r7_const\" called but not implemented\n"); }

    void djnz_dadr(Processor& p) { printf("\"djnz_dadr\" called but not implemented\n"); }
    void djnz_r0(Processor& p) { printf("\"djnz_r0\" called but not implemented\n"); }
    void djnz_r1(Processor& p) { printf("\"djnz_r1\" called but not implemented\n"); }
    void djnz_r2(Processor& p) { printf("\"djnz_r2\" called but not implemented\n"); }
    void djnz_r3(Processor& p) { printf("\"djnz_r3\" called but not implemented\n"); }
    void djnz_r4(Processor& p) { printf("\"djnz_r4\" called but not implemented\n"); }
    void djnz_r5(Processor& p) { printf("\"djnz_r5\" called but not implemented\n"); }
    void djnz_r6(Processor& p) { printf("\"djnz_r6\" called but not implemented\n"); }
    void djnz_r7(Processor& p) { printf("\"djnz_r7\" called but not implemented\n"); }

    void push(Processor& p) { printf("\"push\" called but not implemented\n"); }
    void pop(Processor& p) { printf("\"pop\" called but not implemented\n"); }

    void ret(Processor& p) { printf("\"ret\" called but not implemented\n"); }
    void reti(Processor& p) { printf("\"reti\" called but not implemented\n"); }

    void add_a_const(Processor& p) { printf("\"add_a_const\" called but not implemented\n"); }
    void add_a_dadr(Processor& p) { printf("\"add_a_dadr\" called but not implemented\n"); }
    void add_a_atr0(Processor& p) { printf("\"add_a_atr0\" called but not implemented\n"); }
    void add_a_atr1(Processor& p) { printf("\"add_a_atr1\" called but not implemented\n"); }
    void add_a_r0(Processor& p) { printf("\"add_a_r0\" called but not implemented\n"); }
    void add_a_r1(Processor& p) { printf("\"add_a_r1\" called but not implemented\n"); }
    void add_a_r2(Processor& p) { printf("\"add_a_r2\" called but not implemented\n"); }
    void add_a_r3(Processor& p) { printf("\"add_a_r3\" called but not implemented\n"); }
    void add_a_r4(Processor& p) { printf("\"add_a_r4\" called but not implemented\n"); }
    void add_a_r5(Processor& p) { printf("\"add_a_r5\" called but not implemented\n"); }
    void add_a_r6(Processor& p) { printf("\"add_a_r6\" called but not implemented\n"); }
    void add_a_r7(Processor& p) { printf("\"add_a_r7\" called but not implemented\n"); }

    void addc_a_const(Processor& p) { printf("\"addc_a_const\" called but not implemented\n"); }
    void addc_a_dadr(Processor& p) { printf("\"addc_a_dadr\" called but not implemented\n"); }
    void addc_a_atr0(Processor& p) { printf("\"addc_a_atr0\" called but not implemented\n"); }
    void addc_a_atr1(Processor& p) { printf("\"addc_a_atr1\" called but not implemented\n"); }
    void addc_a_r0(Processor& p) { printf("\"addc_a_r0\" called but not implemented\n"); }
    void addc_a_r1(Processor& p) { printf("\"addc_a_r1\" called but not implemented\n"); }
    void addc_a_r2(Processor& p) { printf("\"addc_a_r2\" called but not implemented\n"); }
    void addc_a_r3(Processor& p) { printf("\"addc_a_r3\" called but not implemented\n"); }
    void addc_a_r4(Processor& p) { printf("\"addc_a_r4\" called but not implemented\n"); }
    void addc_a_r5(Processor& p) { printf("\"addc_a_r5\" called but not implemented\n"); }
    void addc_a_r6(Processor& p) { printf("\"addc_a_r6\" called but not implemented\n"); }
    void addc_a_r7(Processor& p) { printf("\"addc_a_r7\" called but not implemented\n"); }

    void subb_a_const(Processor& p) { printf("\"subb_a_const\" called but not implemented\n"); }
    void subb_a_dadr(Processor& p) { printf("\"subb_a_dadr\" called but not implemented\n"); }
    void subb_a_atr0(Processor& p) { printf("\"subb_a_atr0\" called but not implemented\n"); }
    void subb_a_atr1(Processor& p) { printf("\"subb_a_atr1\" called but not implemented\n"); }
    void subb_a_r0(Processor& p) { printf("\"subb_a_r0\" called but not implemented\n"); }
    void subb_a_r1(Processor& p) { printf("\"subb_a_r1\" called but not implemented\n"); }
    void subb_a_r2(Processor& p) { printf("\"subb_a_r2\" called but not implemented\n"); }
    void subb_a_r3(Processor& p) { printf("\"subb_a_r3\" called but not implemented\n"); }
    void subb_a_r4(Processor& p) { printf("\"subb_a_r4\" called but not implemented\n"); }
    void subb_a_r5(Processor& p) { printf("\"subb_a_r5\" called but not implemented\n"); }
    void subb_a_r6(Processor& p) { printf("\"subb_a_r6\" called but not implemented\n"); }
    void subb_a_r7(Processor& p) { printf("\"subb_a_r7\" called but not implemented\n"); }

    void div(Processor& p) { printf("\"div\" called but not implemented\n"); }
    void mul(Processor& p) { printf("\"mul\" called but not implemented\n"); }

    void swap(Processor& p) { printf("\"swap\" called but not implemented\n"); }

    void cpl_badr(Processor& p) { printf("\"cpl_badr\" called but not implemented\n"); }
    void cpl_c(Processor& p) { printf("\"cpl_c\" called but not implemented\n"); }
    void cpl_a(Processor& p) { printf("\"cpl_a\" called but not implemented\n"); }

    void clr_badr(Processor& p) { printf("\"clr_badr\" called but not implemented\n"); }
    void clr_c(Processor& p) { printf("\"clr_c\" called but not implemented\n"); }

    void setb_badr(Processor& p) { printf("\"setb_badr\" called but not implemented\n"); }
    void setb_c(Processor& p) { printf("\"setb_c\" called but not implemented\n"); }

    void clr_a(Processor& p) { printf("\"clr_a\" called but not implemented\n"); }

    void orl_dadr_a(Processor& p) { printf("\"orl_dadr_a\" called but not implemented\n"); }
    void orl_dadr_const(Processor& p) { printf("\"orl_dadr_const\" called but not implemented\n"); }
    void orl_a_const(Processor& p) { printf("\"orl_a_const\" called but not implemented\n"); }
    void orl_a_dadr(Processor& p) { printf("\"orl_a_dadr\" called but not implemented\n"); }
    void orl_a_atr0(Processor& p) { printf("\"orl_a_atr0\" called but not implemented\n"); }
    void orl_a_atr1(Processor& p) { printf("\"orl_a_atr1\" called but not implemented\n"); }
    void orl_a_r0(Processor& p) { printf("\"orl_a_r0\" called but not implemented\n"); }
    void orl_a_r1(Processor& p) { printf("\"orl_a_r1\" called but not implemented\n"); }
    void orl_a_r2(Processor& p) { printf("\"orl_a_r2\" called but not implemented\n"); }
    void orl_a_r3(Processor& p) { printf("\"orl_a_r3\" called but not implemented\n"); }
    void orl_a_r4(Processor& p) { printf("\"orl_a_r4\" called but not implemented\n"); }
    void orl_a_r5(Processor& p) { printf("\"orl_a_r5\" called but not implemented\n"); }
    void orl_a_r6(Processor& p) { printf("\"orl_a_r6\" called but not implemented\n"); }
    void orl_a_r7(Processor& p) { printf("\"orl_a_r7\" called but not implemented\n"); }
    void orl_c_badr(Processor& p) { printf("\"orl_c_badr\" called but not implemented\n"); }
    void orl_c_not_badr(Processor& p) { printf("\"orl_c_not_badr\" called but not implemented\n"); }

    void anl_dadr_a(Processor& p) { printf("\"anl_dadr_a\" called but not implemented\n"); }
    void anl_dadr_const(Processor& p) { printf("\"anl_dadr_const\" called but not implemented\n"); }
    void anl_a_const(Processor& p) { printf("\"anl_a_const\" called but not implemented\n"); }
    void anl_a_dadr(Processor& p) { printf("\"anl_a_dadr\" called but not implemented\n"); }
    void anl_a_atr0(Processor& p) { printf("\"anl_a_atr0\" called but not implemented\n"); }
    void anl_a_atr1(Processor& p) { printf("\"anl_a_atr1\" called but not implemented\n"); }
    void anl_a_r0(Processor& p) { printf("\"anl_a_r0\" called but not implemented\n"); }
    void anl_a_r1(Processor& p) { printf("\"anl_a_r1\" called but not implemented\n"); }
    void anl_a_r2(Processor& p) { printf("\"anl_a_r2\" called but not implemented\n"); }
    void anl_a_r3(Processor& p) { printf("\"anl_a_r3\" called but not implemented\n"); }
    void anl_a_r4(Processor& p) { printf("\"anl_a_r4\" called but not implemented\n"); }
    void anl_a_r5(Processor& p) { printf("\"anl_a_r5\" called but not implemented\n"); }
    void anl_a_r6(Processor& p) { printf("\"anl_a_r6\" called but not implemented\n"); }
    void anl_a_r7(Processor& p) { printf("\"anl_a_r7\" called but not implemented\n"); }
    void anl_c_badr(Processor& p) { printf("\"anl_c_badr\" called but not implemented\n"); }
    void anl_c_not_badr(Processor& p) { printf("\"anl_c_not_badr\" called but not implemented\n"); }

    void xrl_dadr_a(Processor& p) { printf("\"xrl_dadr_a\" called but not implemented\n"); }
    void xrl_dadr_const(Processor& p) { printf("\"xrl_dadr_const\" called but not implemented\n"); }
    void xrl_a_const(Processor& p) { printf("\"xrl_a_const\" called but not implemented\n"); }
    void xrl_a_dadr(Processor& p) { printf("\"xrl_a_dadr\" called but not implemented\n"); }
    void xrl_a_atr0(Processor& p) { printf("\"xrl_a_atr0\" called but not implemented\n"); }
    void xrl_a_atr1(Processor& p) { printf("\"xrl_a_atr1\" called but not implemented\n"); }
    void xrl_a_r0(Processor& p) { printf("\"xrl_a_r0\" called but not implemented\n"); }
    void xrl_a_r1(Processor& p) { printf("\"xrl_a_r1\" called but not implemented\n"); }
    void xrl_a_r2(Processor& p) { printf("\"xrl_a_r2\" called but not implemented\n"); }
    void xrl_a_r3(Processor& p) { printf("\"xrl_a_r3\" called but not implemented\n"); }
    void xrl_a_r4(Processor& p) { printf("\"xrl_a_r4\" called but not implemented\n"); }
    void xrl_a_r5(Processor& p) { printf("\"xrl_a_r5\" called but not implemented\n"); }
    void xrl_a_r6(Processor& p) { printf("\"xrl_a_r6\" called but not implemented\n"); }
    void xrl_a_r7(Processor& p) { printf("\"xrl_a_r7\" called but not implemented\n"); }

    void mov_a_const(Processor& p) { printf("\"mov_a_const\" called but not implemented\n"); }
    void mov_dadr_const(Processor& p) { printf("\"mov_dadr_const\" called but not implemented\n"); }
    void mov_atr0_const(Processor& p) { printf("\"mov_atr0_const\" called but not implemented\n"); }
    void mov_atr1_const(Processor& p) { printf("\"mov_atr1_const\" called but not implemented\n"); }
    void mov_r0_const(Processor& p) { printf("\"mov_r0_const\" called but not implemented\n"); }
    void mov_r1_const(Processor& p) { printf("\"mov_r1_const\" called but not implemented\n"); }
    void mov_r2_const(Processor& p) { printf("\"mov_r2_const\" called but not implemented\n"); }
    void mov_r3_const(Processor& p) { printf("\"mov_r3_const\" called but not implemented\n"); }
    void mov_r4_const(Processor& p) { printf("\"mov_r4_const\" called but not implemented\n"); }
    void mov_r5_const(Processor& p) { printf("\"mov_r5_const\" called but not implemented\n"); }
    void mov_r6_const(Processor& p) { printf("\"mov_r6_const\" called but not implemented\n"); }
    void mov_r7_const(Processor& p) { printf("\"mov_r7_const\" called but not implemented\n"); }
    void mov_dadr_dadr(Processor& p) { printf("\"mov_dadr_dadr\" called but not implemented\n"); }
    void mov_dadr_atr0(Processor& p) { printf("\"mov_dadr_atr0\" called but not implemented\n"); }
    void mov_dadr_atr1(Processor& p) { printf("\"mov_dadr_atr1\" called but not implemented\n"); }
    void mov_dadr_r0(Processor& p) { printf("\"mov_dadr_r0\" called but not implemented\n"); }
    void mov_dadr_r1(Processor& p) { printf("\"mov_dadr_r1\" called but not implemented\n"); }
    void mov_dadr_r2(Processor& p) { printf("\"mov_dadr_r2\" called but not implemented\n"); }
    void mov_dadr_r3(Processor& p) { printf("\"mov_dadr_r3\" called but not implemented\n"); }
    void mov_dadr_r4(Processor& p) { printf("\"mov_dadr_r4\" called but not implemented\n"); }
    void mov_dadr_r5(Processor& p) { printf("\"mov_dadr_r5\" called but not implemented\n"); }
    void mov_dadr_r6(Processor& p) { printf("\"mov_dadr_r6\" called but not implemented\n"); }
    void mov_dadr_r7(Processor& p) { printf("\"mov_dadr_r7\" called but not implemented\n"); }
    void mov_dptr_const(Processor& p) { printf("\"mov_dptr_const\" called but not implemented\n"); }
    void mov_atr0_dadr(Processor& p) { printf("\"mov_atr0_dadr\" called but not implemented\n"); }
    void mov_atr1_dadr(Processor& p) { printf("\"mov_atr1_dadr\" called but not implemented\n"); }
    void mov_r0_dadr(Processor& p) { printf("\"mov_r0_dadr\" called but not implemented\n"); }
    void mov_r1_dadr(Processor& p) { printf("\"mov_r1_dadr\" called but not implemented\n"); }
    void mov_r2_dadr(Processor& p) { printf("\"mov_r2_dadr\" called but not implemented\n"); }
    void mov_r3_dadr(Processor& p) { printf("\"mov_r3_dadr\" called but not implemented\n"); }
    void mov_r4_dadr(Processor& p) { printf("\"mov_r4_dadr\" called but not implemented\n"); }
    void mov_r5_dadr(Processor& p) { printf("\"mov_r5_dadr\" called but not implemented\n"); }
    void mov_r6_dadr(Processor& p) { printf("\"mov_r6_dadr\" called but not implemented\n"); }
    void mov_r7_dadr(Processor& p) { printf("\"mov_r7_dadr\" called but not implemented\n"); }
    void mov_a_dadr(Processor& p) { printf("\"mov_a_dadr\" called but not implemented\n"); }
    void mov_a_atr0(Processor& p) { printf("\"mov_a_atr0\" called but not implemented\n"); }
    void mov_a_atr1(Processor& p) { printf("\"mov_a_atr1\" called but not implemented\n"); }
    void mov_a_r0(Processor& p) { printf("\"mov_a_r0\" called but not implemented\n"); }
    void mov_a_r1(Processor& p) { printf("\"mov_a_r1\" called but not implemented\n"); }
    void mov_a_r2(Processor& p) { printf("\"mov_a_r2\" called but not implemented\n"); }
    void mov_a_r3(Processor& p) { printf("\"mov_a_r3\" called but not implemented\n"); }
    void mov_a_r4(Processor& p) { printf("\"mov_a_r4\" called but not implemented\n"); }
    void mov_a_r5(Processor& p) { printf("\"mov_a_r5\" called but not implemented\n"); }
    void mov_a_r6(Processor& p) { printf("\"mov_a_r6\" called but not implemented\n"); }
    void mov_a_r7(Processor& p) { printf("\"mov_a_r7\" called but not implemented\n"); }
    void mov_dadr_a(Processor& p) { printf("\"mov_dadr_a\" called but not implemented\n"); }
    void mov_atr0_a(Processor& p) { printf("\"mov_atr0_a\" called but not implemented\n"); }
    void mov_atr1_a(Processor& p) { printf("\"mov_atr1_a\" called but not implemented\n"); }
    void mov_r0_a(Processor& p) { printf("\"mov_r0_a\" called but not implemented\n"); }
    void mov_r1_a(Processor& p) { printf("\"mov_r1_a\" called but not implemented\n"); }
    void mov_r2_a(Processor& p) { printf("\"mov_r2_a\" called but not implemented\n"); }
    void mov_r3_a(Processor& p) { printf("\"mov_r3_a\" called but not implemented\n"); }
    void mov_r4_a(Processor& p) { printf("\"mov_r4_a\" called but not implemented\n"); }
    void mov_r5_a(Processor& p) { printf("\"mov_r5_a\" called but not implemented\n"); }
    void mov_r6_a(Processor& p) { printf("\"mov_r6_a\" called but not implemented\n"); }
    void mov_r7_a(Processor& p) { printf("\"mov_r7_a\" called but not implemented\n"); }
    void mov_badr_c(Processor& p) { printf("\"mov_badr_c\" called but not implemented\n"); }
    void mov_c_badr(Processor& p) { printf("\"mov_c_badr\" called but not implemented\n"); }

    void movc_a_a_pc(Processor& p) { printf("\"movc_a_a_pc\" called but not implemented\n"); }
    void movc_a_a_dptr(Processor& p) { printf("\"movc_a_a_dptr\" called but not implemented\n"); }

    void movx_a_dptr(Processor& p) { printf("\"movx_a_dptr\" called but not implemented\n"); }
    void movx_a_atr0(Processor& p) { printf("\"movx_a_atr0\" called but not implemented\n"); }
    void movx_a_atr1(Processor& p) { printf("\"movx_a_atr1\" called but not implemented\n"); }
    void movx_dptr_a(Processor& p) { printf("\"movx_dptr_a\" called but not implemented\n"); }
    void movx_atr0_a(Processor& p) { printf("\"movx_atr0_a\" called but not implemented\n"); }
    void movx_atr1_a(Processor& p) { printf("\"movx_atr1_a\" called but not implemented\n"); }

    void xch_a_dadr(Processor& p) { printf("\"xch_a_dadr\" called but not implemented\n"); }
    void xch_a_atr0(Processor& p) { printf("\"xch_a_atr0\" called but not implemented\n"); }
    void xch_a_atr1(Processor& p) { printf("\"xch_a_atr1\" called but not implemented\n"); }
    void xch_a_r0(Processor& p) { printf("\"xch_a_r0\" called but not implemented\n"); }
    void xch_a_r1(Processor& p) { printf("\"xch_a_r1\" called but not implemented\n"); }
    void xch_a_r2(Processor& p) { printf("\"xch_a_r2\" called but not implemented\n"); }
    void xch_a_r3(Processor& p) { printf("\"xch_a_r3\" called but not implemented\n"); }
    void xch_a_r4(Processor& p) { printf("\"xch_a_r4\" called but not implemented\n"); }
    void xch_a_r5(Processor& p) { printf("\"xch_a_r5\" called but not implemented\n"); }
    void xch_a_r6(Processor& p) { printf("\"xch_a_r6\" called but not implemented\n"); }
    void xch_a_r7(Processor& p) { printf("\"xch_a_r7\" called but not implemented\n"); }

    void xchd_a_atr0(Processor& p) { printf("\"xchd_a_atr0\" called but not implemented\n"); }
    void xchd_a_atr1(Processor& p) { printf("\"xchd_a_atr1\" called but not implemented\n"); }

    void da(Processor& p) { printf("\"da\" called but not implemented\n"); }

    void reserved(Processor& p) { printf("\"reserved\" called but not implemented\n"); }


    const op_function_t ops[] = {
            nop,
            ajmp1,
            ljmp,
            rr,
            inc_a,
            inc_dadr,
            inc_atr0,
            inc_atr1,
            inc_r0,
            inc_r1,
            inc_r2,
            inc_r3,
            inc_r4,
            inc_r5,
            inc_r6,
            inc_r7,
            jbc,
            acall1,
            lcall,
            rrc,
            dec_a,
            dec_dadr,
            dec_atr0,
            dec_atr1,
            dec_r0,
            dec_r1,
            dec_r2,
            dec_r3,
            dec_r4,
            dec_r5,
            dec_r6,
            dec_r7,
            jb,
            ajmp2,
            ret,
            rl,
            add_a_const,
            add_a_dadr,
            add_a_atr0,
            add_a_atr1,
            add_a_r0,
            add_a_r1,
            add_a_r2,
            add_a_r3,
            add_a_r4,
            add_a_r5,
            add_a_r6,
            add_a_r7,
            jnb,
            acall2,
            reti,
            rlc,
            addc_a_const,
            addc_a_dadr,
            addc_a_atr0,
            addc_a_atr1,
            addc_a_r0,
            addc_a_r1,
            addc_a_r2,
            addc_a_r3,
            addc_a_r4,
            addc_a_r5,
            addc_a_r6,
            addc_a_r7,
            jc,
            ajmp3,
            orl_dadr_a,
            orl_dadr_const,
            orl_a_const,
            orl_a_dadr,
            orl_a_atr0,
            orl_a_atr1,
            orl_a_r0,
            orl_a_r1,
            orl_a_r2,
            orl_a_r3,
            orl_a_r4,
            orl_a_r5,
            orl_a_r6,
            orl_a_r7,
            jnc,
            acall3,
            anl_dadr_a,
            anl_dadr_const,
            anl_a_const,
            anl_a_dadr,
            anl_a_atr0,
            anl_a_atr1,
            anl_a_r0,
            anl_a_r1,
            anl_a_r2,
            anl_a_r3,
            anl_a_r4,
            anl_a_r5,
            anl_a_r6,
            anl_a_r7,
            jz,
            ajmp4,
            xrl_dadr_a,
            xrl_dadr_const,
            xrl_a_const,
            xrl_a_dadr,
            xrl_a_atr0,
            xrl_a_atr1,
            xrl_a_r0,
            xrl_a_r1,
            xrl_a_r2,
            xrl_a_r3,
            xrl_a_r4,
            xrl_a_r5,
            xrl_a_r6,
            xrl_a_r7,
            jnz,
            acall4,
            orl_c_badr,
            jmp,
            mov_a_const,
            mov_dadr_const,
            mov_atr0_const,
            mov_atr1_const,
            mov_r0_const,
            mov_r1_const,
            mov_r2_const,
            mov_r3_const,
            mov_r4_const,
            mov_r5_const,
            mov_r6_const,
            mov_r7_const,
            sjmp,
            ajmp5,
            anl_c_badr,
            movc_a_a_pc,
            div,
            mov_dadr_dadr,
            mov_dadr_atr0,
            mov_dadr_atr1,
            mov_dadr_r0,
            mov_dadr_r1,
            mov_dadr_r2,
            mov_dadr_r3,
            mov_dadr_r4,
            mov_dadr_r5,
            mov_dadr_r6,
            mov_dadr_r7,
            mov_dptr_const,
            acall5,
            mov_badr_c,
            movc_a_a_dptr,
            subb_a_const,
            subb_a_dadr,
            subb_a_atr0,
            subb_a_atr1,
            subb_a_r0,
            subb_a_r1,
            subb_a_r2,
            subb_a_r3,
            subb_a_r4,
            subb_a_r5,
            subb_a_r6,
            subb_a_r7,
            orl_c_not_badr,
            ajmp6,
            mov_c_badr,
            inc_dptr,
            mul,
            reserved,
            mov_atr0_dadr,
            mov_atr1_dadr,
            mov_r0_dadr,
            mov_r1_dadr,
            mov_r2_dadr,
            mov_r3_dadr,
            mov_r4_dadr,
            mov_r5_dadr,
            mov_r6_dadr,
            mov_r7_dadr,
            anl_c_not_badr,
            acall6,
            cpl_badr,
            cpl_c,
            cjne_a_const,
            cjne_a_dadr,
            cjne_atr0_const,
            cjne_atr1_const,
            cjne_r0_const,
            cjne_r1_const,
            cjne_r2_const,
            cjne_r3_const,
            cjne_r4_const,
            cjne_r5_const,
            cjne_r6_const,
            cjne_r7_const,
            push,
            ajmp7,
            clr_badr,
            clr_c,
            swap,
            xch_a_dadr,
            xch_a_atr0,
            xch_a_atr1,
            xch_a_r0,
            xch_a_r1,
            xch_a_r2,
            xch_a_r3,
            xch_a_r4,
            xch_a_r5,
            xch_a_r6,
            xch_a_r7,
            pop,
            acall7,
            setb_badr,
            setb_c,
            da,
            djnz_dadr,
            xchd_a_atr0,
            xchd_a_atr1,
            djnz_r0,
            djnz_r1,
            djnz_r2,
            djnz_r3,
            djnz_r4,
            djnz_r5,
            djnz_r6,
            djnz_r7,
            movx_a_dptr,
            ajmp8,
            movx_a_atr0,
            movx_a_atr1,
            clr_a,
            mov_a_dadr,
            mov_a_atr0,
            mov_a_atr1,
            mov_a_r0,
            mov_a_r1,
            mov_a_r2,
            mov_a_r3,
            mov_a_r4,
            mov_a_r5,
            mov_a_r6,
            mov_a_r7,
            movx_dptr_a,
            acall8,
            movx_atr0_a,
            movx_atr1_a,
            cpl_a,
            mov_dadr_a,
            mov_atr0_a,
            mov_atr1_a,
            mov_r0_a,
            mov_r1_a,
            mov_r2_a,
            mov_r3_a,
            mov_r4_a,
            mov_r5_a,
            mov_r6_a,
            mov_r7_a
    };

    const size_t op_count = sizeof(ops) / sizeof(*ops);

}
