
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <map>
#include "Processor.h"
#include "ops.h"

namespace emu {

    Processor::Processor()
            : rom(0x8000),
              ram(),
              a(),
              b(),
              psw(),
              sp(0x07) {
        ram.registerSfr(0x01, sp);
        ram.registerSfr(0x50, psw);
        ram.registerSfr(0x60, a);
        ram.registerSfr(0x70, b);
        ram.registerSfr(0x00, p0);
        ram.registerSfr(0x10, p1);
        ram.registerSfr(0x20, p2);
        ram.registerSfr(0x30, p3);
        ram.registerSfr(0x40, p4);
    }

    void Processor::run() {
        setPc(0);

        while (pc != 0x7fff) {
            tick();
        }
    }

    void Processor::tick() {
        // TODO: timers, interrupts
        execOp();
    }

    void Processor::writeRom(uint16_t address, const std::vector<std::uint8_t> &data) {
        auto dataLength = data.size();

        if (address + dataLength > rom.size()) {
            throw std::overflow_error("this would exceed the rom size");
        }

        printf("Processor ROM: Writing %lu byte(s) to 0x%04x\n", dataLength, address);

        std::copy(data.begin(), data.end(), rom.begin() + address);
    }

    std::uint8_t Processor::fetchRom() {
        uint8_t value = rom[pc];
        setPc(static_cast<uint16_t>(pc + 1));
        return value;
    }

    void Processor::execOp() {
        instruction = fetchRom();

        if (instruction < op_count) {
            ops[instruction](*this);
        } else {
            printf("Opcode 0x%02x not implemented\n", instruction);
        }
    }

    void Processor::setPc(uint16_t value) {
        pc = static_cast<uint16_t>(value & 0x7fff);
    }

    void Processor::setPc(uint8_t lower, uint8_t upper) {
        setPc(lower | upper << 8);
    }

    uint8_t Processor::getReg(uint8_t reg) {
        return ram.read(psw.getRegistersBaseAddress() + reg);
    }

    void Processor::setReg(uint8_t reg, uint8_t value) {
        ram.write(psw.getRegistersBaseAddress() + reg, value);
    }

    uint8_t Processor::popStack() {
        uint8_t oldSp = sp.read();
        uint8_t value = ram.read(oldSp);
        sp.write(static_cast<uint8_t>(oldSp - 1));
        return value;
    }

    void Processor::pushStack(uint8_t value) {
        uint8_t newSp = static_cast<uint8_t>(sp.read() + 1);
        sp.write(newSp);
        ram.write(newSp, value);
    }

}
