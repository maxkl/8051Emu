
#include <iostream>
#include "Processor.h"
#include "ops.h"

namespace emu {

    // TODO: proper input output handling of ports:
    // ANL, CPL, DEC, DJNZ, INC, JBC, ORL, XRL

    void nop(Processor& p) {}

    void ajmp(Processor& p) { uint8_t lower = p.fetchRom(); uint8_t upper = static_cast<uint8_t>(((p.pc & 0xf800) >> 8) | ((p.instruction & 0xe0) >> 5)); p.setPc(lower, upper); }

    void ljmp(Processor& p) { uint8_t upper = p.fetchRom(); uint8_t lower = p.fetchRom(); p.setPc(lower, upper); }
    void sjmp(Processor& p) { int8_t offset = p.fetchRom(); p.setPc(p.pc + offset); }
    void jmp_dptr(Processor &p) { uint16_t addr = p.getDptr() + p.a.read(); p.setPc(addr); }

    void acall(Processor& p) { uint8_t lower = p.fetchRom(); uint8_t upper = static_cast<uint8_t>(((p.pc & 0xf800) >> 8) | ((p.instruction & 0xe0) >> 5)); uint8_t pcUpper =
                static_cast<uint8_t>((p.pc & 0xff00) >> 8); uint8_t pcLower = static_cast<uint8_t>(p.pc & 0x00ff); p.pushStack(pcLower); p.pushStack(pcUpper); p.setPc(lower, upper); }

    void lcall(Processor& p) { uint8_t upper = p.fetchRom(); uint8_t lower = p.fetchRom(); uint8_t pcUpper =
                static_cast<uint8_t>((p.pc & 0xff00) >> 8); uint8_t pcLower = static_cast<uint8_t>(p.pc & 0x00ff); p.pushStack(pcLower); p.pushStack(pcUpper); p.setPc(lower, upper); }

    void rr(Processor& p) { uint8_t value = p.a.read(); p.a.write((value >> 1) | (value << 7)); }
    void rrc(Processor& p) { printf("\"rrc\" called but not implemented\n"); }
    void rl(Processor& p) { uint8_t value = p.a.read(); p.a.write((value << 1) | (value >> 7)); }
    void rlc(Processor& p) { printf("\"rlc\" called but not implemented\n"); }

    void inc_a(Processor& p) { p.a.write(static_cast<uint8_t>(p.a.read() + 1)); }
    void inc_dadr(Processor& p) { uint8_t addr = p.fetchRom(); p.ram.write(addr, static_cast<uint8_t>(p.ram.read(addr) + 1)); }
    void inc_atr(Processor& p) { uint8_t addr = p.ram.read(p.getReg(static_cast<uint8_t>(p.instruction & 0x1))); p.ram.write(addr, static_cast<uint8_t>(p.ram.read(addr, true) + 1), true); }
    void inc_r(Processor& p) { uint8_t reg = static_cast<uint8_t>(p.instruction & 0x7); p.setReg(reg, static_cast<uint8_t>(p.getReg(reg) + 1)); }
    void inc_dptr(Processor& p) { p.setDptr(static_cast<uint16_t>(p.getDptr() + 1)); }

    void dec_a(Processor& p) { p.a.write(static_cast<uint8_t>(p.a.read() - 1)); }
    void dec_dadr(Processor& p) { uint8_t addr = p.fetchRom(); p.ram.write(addr, static_cast<uint8_t>(p.ram.read(addr) - 1)); }
    void dec_atr(Processor& p) { uint8_t addr = p.ram.read(p.getReg(static_cast<uint8_t>(p.instruction & 0x1))); p.ram.write(addr, static_cast<uint8_t>(p.ram.read(addr, true) - 1), true); }
    void dec_r(Processor& p) { uint8_t reg = static_cast<uint8_t>(p.instruction & 0x7); p.setReg(reg, static_cast<uint8_t>(p.getReg(reg) - 1)); }

    void jb(Processor& p) { uint8_t badr = p.fetchRom(); int8_t offset = p.fetchRom(); if(p.ram.readBit(badr)) { p.setPc(p.pc + offset); } }
    void jbc(Processor& p) { uint8_t badr = p.fetchRom(); int8_t offset = p.fetchRom(); if(p.ram.readBit(badr)) { p.ram.writeBit(badr, false); p.setPc(p.pc + offset); } }
    void jnb(Processor& p) { uint8_t badr = p.fetchRom(); int8_t offset = p.fetchRom(); if(!p.ram.readBit(badr)) { p.setPc(p.pc + offset); } }
    void jc(Processor& p) { int8_t offset = p.fetchRom(); if(p.psw.cy) { p.setPc(p.pc + offset); } }
    void jnc(Processor& p) { int8_t offset = p.fetchRom(); if(!p.psw.cy) { p.setPc(p.pc + offset); } }
    void jz(Processor& p) { int8_t offset = p.fetchRom(); if(p.a.read() == 0x00) { p.setPc(p.pc + offset); } }
    void jnz(Processor& p) { int8_t offset = p.fetchRom(); if(p.a.read() != 0x00) { p.setPc(p.pc + offset); } }

    void cjne(Processor& p, uint8_t a, uint8_t b, int8_t offset) { if(a == b) { p.setPc(p.pc + offset); } p.psw.cy = a < b; }
    void cjne_a_const(Processor& p) { uint8_t value = p.fetchRom(); int8_t offset = p.fetchRom(); cjne(p, p.a.read(), value, offset); }
    void cjne_a_dadr(Processor& p) { uint8_t addr = p.fetchRom(); int8_t offset = p.fetchRom(); cjne(p, p.a.read(), p.ram.read(addr), offset); }
    void cjne_atr_const(Processor& p) { uint8_t value = p.fetchRom(); int8_t offset = p.fetchRom(); cjne(p, p.ram.read(p.getReg(static_cast<uint8_t>(p.instruction & 0x1)), true), value, offset); }
    void cjne_r_const(Processor& p) { uint8_t value = p.fetchRom(); int8_t offset = p.fetchRom(); cjne(p, p.getReg(static_cast<uint8_t>(p.instruction & 0x7)), value, offset); }

    void djnz_dadr(Processor& p) { uint8_t addr = p.fetchRom(); int8_t offset = p.fetchRom(); uint8_t newVal = static_cast<uint8_t>(p.ram.read(addr) - 1); p.ram.write(addr, newVal); if(newVal != 0) { p.setPc(p.pc + offset); } }
    void djnz_r(Processor& p) { int8_t offset = p.fetchRom(); uint8_t reg = static_cast<uint8_t>(p.instruction & 0x7); uint8_t newVal = static_cast<uint8_t>(p.getReg(reg) - 1); p.setReg(reg, newVal); if(newVal != 0) { p.setPc(p.pc + offset); } }

    void push(Processor& p) { uint8_t addr = p.fetchRom(); p.pushStack(p.ram.read(addr)); }
    void pop(Processor& p) { uint8_t addr = p.fetchRom(); p.ram.write(addr, p.popStack()); }

    void ret(Processor& p) { uint8_t upper = p.popStack(); uint8_t lower = p.popStack(); p.setPc(lower, upper); }
    void reti(Processor& p) { printf("\"reti\" called but not implemented\n"); }

    void add_a_const(Processor& p) { printf("\"add_a_const\" called but not implemented\n"); }
    void add_a_dadr(Processor& p) { printf("\"add_a_dadr\" called but not implemented\n"); }
    void add_a_atr(Processor& p) { printf("\"add_a_atr\" called but not implemented\n"); }
    void add_a_r(Processor& p) { printf("\"add_a_r\" called but not implemented\n"); }

    void addc_a_const(Processor& p) { printf("\"addc_a_const\" called but not implemented\n"); }
    void addc_a_dadr(Processor& p) { printf("\"addc_a_dadr\" called but not implemented\n"); }
    void addc_a_atr(Processor& p) { printf("\"addc_a_atr\" called but not implemented\n"); }
    void addc_a_r(Processor& p) { printf("\"addc_a_r\" called but not implemented\n"); }

    void subb_a_const(Processor& p) { printf("\"subb_a_const\" called but not implemented\n"); }
    void subb_a_dadr(Processor& p) { printf("\"subb_a_dadr\" called but not implemented\n"); }
    void subb_a_atr(Processor& p) { printf("\"subb_a_atr\" called but not implemented\n"); }
    void subb_a_r(Processor& p) { printf("\"subb_a_r\" called but not implemented\n"); }

    void div(Processor& p) { printf("\"div\" called but not implemented\n"); }
    void mul(Processor& p) { printf("\"mul\" called but not implemented\n"); }

    void swap(Processor& p) { uint8_t value = p.a.read(); p.a.write(static_cast<uint8_t >(((value & 0x0f) << 4) | ((value & 0xf0) >> 4))); }

    void cpl_badr(Processor& p) { uint8_t badr = p.fetchRom(); p.ram.writeBit(badr, !p.ram.readBit(badr)); }
    void cpl_c(Processor& p) { p.psw.cy = !p.psw.cy; }
    void cpl_a(Processor& p) { p.a.write(~p.a.read()); }

    void clr_badr(Processor& p) { uint8_t badr = p.fetchRom(); p.ram.writeBit(badr, false); }
    void clr_c(Processor& p) { p.psw.cy = false; }

    void setb_badr(Processor& p) { uint8_t badr = p.fetchRom(); p.ram.writeBit(badr, true); }
    void setb_c(Processor& p) { p.psw.cy = true; }

    void clr_a(Processor& p) { p.a.write(0x00); }

    void orl_dadr_a(Processor& p) { printf("\"orl_dadr_a\" called but not implemented\n"); }
    void orl_dadr_const(Processor& p) { printf("\"orl_dadr_const\" called but not implemented\n"); }
    void orl_a_const(Processor& p) { printf("\"orl_a_const\" called but not implemented\n"); }
    void orl_a_dadr(Processor& p) { printf("\"orl_a_dadr\" called but not implemented\n"); }
    void orl_a_atr(Processor& p) { printf("\"orl_a_atr\" called but not implemented\n"); }
    void orl_a_r(Processor& p) { printf("\"orl_a_r\" called but not implemented\n"); }
    void orl_c_badr(Processor& p) { printf("\"orl_c_badr\" called but not implemented\n"); }
    void orl_c_not_badr(Processor& p) { printf("\"orl_c_not_badr\" called but not implemented\n"); }

    void anl_dadr_a(Processor& p) { printf("\"anl_dadr_a\" called but not implemented\n"); }
    void anl_dadr_const(Processor& p) { printf("\"anl_dadr_const\" called but not implemented\n"); }
    void anl_a_const(Processor& p) { printf("\"anl_a_const\" called but not implemented\n"); }
    void anl_a_dadr(Processor& p) { printf("\"anl_a_dadr\" called but not implemented\n"); }
    void anl_a_atr(Processor& p) { printf("\"anl_a_atr\" called but not implemented\n"); }
    void anl_a_r(Processor& p) { printf("\"anl_a_r\" called but not implemented\n"); }
    void anl_c_badr(Processor& p) { printf("\"anl_c_badr\" called but not implemented\n"); }
    void anl_c_not_badr(Processor& p) { printf("\"anl_c_not_badr\" called but not implemented\n"); }

    void xrl_dadr_a(Processor& p) { printf("\"xrl_dadr_a\" called but not implemented\n"); }
    void xrl_dadr_const(Processor& p) { printf("\"xrl_dadr_const\" called but not implemented\n"); }
    void xrl_a_const(Processor& p) { printf("\"xrl_a_const\" called but not implemented\n"); }
    void xrl_a_dadr(Processor& p) { printf("\"xrl_a_dadr\" called but not implemented\n"); }
    void xrl_a_atr(Processor& p) { printf("\"xrl_a_atr\" called but not implemented\n"); }
    void xrl_a_r(Processor& p) { printf("\"xrl_a_r\" called but not implemented\n"); }

    void mov_a_const(Processor& p) { uint8_t value = p.fetchRom(); p.a.write(value); }
    void mov_dadr_const(Processor& p) { uint8_t addr = p.fetchRom(); uint8_t value = p.fetchRom(); p.ram.write(addr, value); }
    void mov_atr_const(Processor& p) { uint8_t value = p.fetchRom(); p.ram.write(p.getReg(static_cast<uint8_t>(p.instruction & 0x1)), value, true); }
    void mov_r_const(Processor& p) { uint8_t value = p.fetchRom(); p.setReg(static_cast<uint8_t>(p.instruction & 0x7), value); }
    void mov_dadr_dadr(Processor& p) { uint8_t addr1 = p.fetchRom(); uint8_t addr2 = p.fetchRom(); p.ram.write(addr2, p.ram.read(addr1)); }
    void mov_dadr_atr(Processor& p) { uint8_t addr = p.fetchRom(); p.ram.write(addr, p.ram.read(p.getReg(static_cast<uint8_t>(p.instruction & 0x1)), true)); }
    void mov_dadr_r(Processor& p) { uint8_t addr = p.fetchRom(); p.ram.write(addr, p.getReg(static_cast<uint8_t>(p.instruction & 0x7))); }
    void mov_atr_dadr(Processor& p) { uint8_t addr = p.fetchRom(); p.ram.write(p.getReg(static_cast<uint8_t>(p.instruction & 0x1)), p.ram.read(addr), true); }
    void mov_r_dadr(Processor& p) { uint8_t addr = p.fetchRom(); p.setReg(static_cast<uint8_t>(p.instruction & 0x7), p.ram.read(addr)); }
    void mov_a_dadr(Processor& p) { uint8_t addr = p.fetchRom(); p.a.write(p.ram.read(addr)); }
    void mov_a_atr(Processor& p) { p.a.write(p.ram.read(p.getReg(static_cast<uint8_t>(p.instruction & 0x1)), true)); }
    void mov_a_r(Processor& p) { p.a.write(p.getReg(static_cast<uint8_t>(p.instruction & 0x7))); }
    void mov_dadr_a(Processor& p) { uint8_t addr = p.fetchRom(); p.ram.write(addr, p.a.read()); }
    void mov_atr_a(Processor& p) { p.ram.write(p.getReg(static_cast<uint8_t>(p.instruction & 0x1)), p.a.read(), true); }
    void mov_r_a(Processor& p) { p.setReg(static_cast<uint8_t>(p.instruction & 0x7), p.a.read()); }
    void mov_dptr_const(Processor& p) { uint8_t upper = p.fetchRom(); uint8_t lower = p.fetchRom(); p.setDptr(lower, upper); }
    void mov_badr_c(Processor& p) { uint8_t badr = p.fetchRom(); p.ram.writeBit(badr, p.psw.cy); }
    void mov_c_badr(Processor& p) { uint8_t badr = p.fetchRom(); p.psw.cy = p.ram.readBit(badr); }

    void movc_a_a_pc(Processor& p) { uint16_t addr = p.pc + p.a.read(); p.a.write(p.rom[addr]); }
    void movc_a_a_dptr(Processor& p) { uint16_t addr = p.getDptr() + p.a.read(); p.a.write(p.rom[addr]); }

    void movx_a_dptr(Processor& p) { printf("\"movx_a_dptr\" called but not implemented\n"); }
    void movx_a_atr(Processor& p) { printf("\"movx_a_atr\" called but not implemented\n"); }
    void movx_dptr_a(Processor& p) { printf("\"movx_dptr_a\" called but not implemented\n"); }
    void movx_atr_a(Processor& p) { printf("\"movx_atr_a\" called but not implemented\n"); }

    void xch_a_dadr(Processor& p) { printf("\"xch_a_dadr\" called but not implemented\n"); }
    void xch_a_atr(Processor& p) { printf("\"xch_a_atr\" called but not implemented\n"); }
    void xch_a_r(Processor& p) { printf("\"xch_a_r\" called but not implemented\n"); }

    void xchd_a_atr(Processor& p) { printf("\"xchd_a_atr\" called but not implemented\n"); }

    void da(Processor& p) { printf("\"da\" called but not implemented\n"); }

    void reserved(Processor& p) {}


    const op_func_t ops[] = {
            nop,
            ajmp,
            ljmp,
            rr,
            inc_a,
            inc_dadr,
            inc_atr,
            inc_atr,
            inc_r,
            inc_r,
            inc_r,
            inc_r,
            inc_r,
            inc_r,
            inc_r,
            inc_r,
            jbc,
            acall,
            lcall,
            rrc,
            dec_a,
            dec_dadr,
            dec_atr,
            dec_atr,
            dec_r,
            dec_r,
            dec_r,
            dec_r,
            dec_r,
            dec_r,
            dec_r,
            dec_r,
            jb,
            ajmp,
            ret,
            rl,
            add_a_const,
            add_a_dadr,
            add_a_atr,
            add_a_atr,
            add_a_r,
            add_a_r,
            add_a_r,
            add_a_r,
            add_a_r,
            add_a_r,
            add_a_r,
            add_a_r,
            jnb,
            acall,
            reti,
            rlc,
            addc_a_const,
            addc_a_dadr,
            addc_a_atr,
            addc_a_atr,
            addc_a_r,
            addc_a_r,
            addc_a_r,
            addc_a_r,
            addc_a_r,
            addc_a_r,
            addc_a_r,
            addc_a_r,
            jc,
            ajmp,
            orl_dadr_a,
            orl_dadr_const,
            orl_a_const,
            orl_a_dadr,
            orl_a_atr,
            orl_a_atr,
            orl_a_r,
            orl_a_r,
            orl_a_r,
            orl_a_r,
            orl_a_r,
            orl_a_r,
            orl_a_r,
            orl_a_r,
            jnc,
            acall,
            anl_dadr_a,
            anl_dadr_const,
            anl_a_const,
            anl_a_dadr,
            anl_a_atr,
            anl_a_atr,
            anl_a_r,
            anl_a_r,
            anl_a_r,
            anl_a_r,
            anl_a_r,
            anl_a_r,
            anl_a_r,
            anl_a_r,
            jz,
            ajmp,
            xrl_dadr_a,
            xrl_dadr_const,
            xrl_a_const,
            xrl_a_dadr,
            xrl_a_atr,
            xrl_a_atr,
            xrl_a_r,
            xrl_a_r,
            xrl_a_r,
            xrl_a_r,
            xrl_a_r,
            xrl_a_r,
            xrl_a_r,
            xrl_a_r,
            jnz,
            acall,
            orl_c_badr,
            jmp_dptr,
            mov_a_const,
            mov_dadr_const,
            mov_atr_const,
            mov_atr_const,
            mov_r_const,
            mov_r_const,
            mov_r_const,
            mov_r_const,
            mov_r_const,
            mov_r_const,
            mov_r_const,
            mov_r_const,
            sjmp,
            ajmp,
            anl_c_badr,
            movc_a_a_pc,
            div,
            mov_dadr_dadr,
            mov_dadr_atr,
            mov_dadr_atr,
            mov_dadr_r,
            mov_dadr_r,
            mov_dadr_r,
            mov_dadr_r,
            mov_dadr_r,
            mov_dadr_r,
            mov_dadr_r,
            mov_dadr_r,
            mov_dptr_const,
            acall,
            mov_badr_c,
            movc_a_a_dptr,
            subb_a_const,
            subb_a_dadr,
            subb_a_atr,
            subb_a_atr,
            subb_a_r,
            subb_a_r,
            subb_a_r,
            subb_a_r,
            subb_a_r,
            subb_a_r,
            subb_a_r,
            subb_a_r,
            orl_c_not_badr,
            ajmp,
            mov_c_badr,
            inc_dptr,
            mul,
            reserved,
            mov_atr_dadr,
            mov_atr_dadr,
            mov_r_dadr,
            mov_r_dadr,
            mov_r_dadr,
            mov_r_dadr,
            mov_r_dadr,
            mov_r_dadr,
            mov_r_dadr,
            mov_r_dadr,
            anl_c_not_badr,
            acall,
            cpl_badr,
            cpl_c,
            cjne_a_const,
            cjne_a_dadr,
            cjne_atr_const,
            cjne_atr_const,
            cjne_r_const,
            cjne_r_const,
            cjne_r_const,
            cjne_r_const,
            cjne_r_const,
            cjne_r_const,
            cjne_r_const,
            cjne_r_const,
            push,
            ajmp,
            clr_badr,
            clr_c,
            swap,
            xch_a_dadr,
            xch_a_atr,
            xch_a_atr,
            xch_a_r,
            xch_a_r,
            xch_a_r,
            xch_a_r,
            xch_a_r,
            xch_a_r,
            xch_a_r,
            xch_a_r,
            pop,
            acall,
            setb_badr,
            setb_c,
            da,
            djnz_dadr,
            xchd_a_atr,
            xchd_a_atr,
            djnz_r,
            djnz_r,
            djnz_r,
            djnz_r,
            djnz_r,
            djnz_r,
            djnz_r,
            djnz_r,
            movx_a_dptr,
            ajmp,
            movx_a_atr,
            movx_a_atr,
            clr_a,
            mov_a_dadr,
            mov_a_atr,
            mov_a_atr,
            mov_a_r,
            mov_a_r,
            mov_a_r,
            mov_a_r,
            mov_a_r,
            mov_a_r,
            mov_a_r,
            mov_a_r,
            movx_dptr_a,
            acall,
            movx_atr_a,
            movx_atr_a,
            cpl_a,
            mov_dadr_a,
            mov_atr_a,
            mov_atr_a,
            mov_r_a,
            mov_r_a,
            mov_r_a,
            mov_r_a,
            mov_r_a,
            mov_r_a,
            mov_r_a,
            mov_r_a
    };

    const size_t op_count = sizeof(ops) / sizeof(*ops);

}
