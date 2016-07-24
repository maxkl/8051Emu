
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <map>
#include "Processor.h"
#include "ops.h"

namespace emu {

    Processor::Processor()
            : rom(0x8000) {

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
        std::uint8_t opcode = fetchRom();

        if (opcode < op_count) {
            ops[opcode](*this);
        } else {
            printf("Opcode 0x%02x not implemented\n", opcode);
        }
    }

    void Processor::setPc(uint16_t value) {
        pc = static_cast<uint16_t>(value & 0x7fff);
    }

    Memory::Memory()
            : mem(256) {

    }

    uint8_t Memory::read(uint8_t address, bool indirect) {
        if(!indirect || address < 0x80) {
            return mem[address];
        } else {
            // SFR
            return readSfr(address);
        }
    }

    uint8_t Memory::read(uint8_t address) {
        return read(address, false);
    }

    void Memory::write(uint8_t address, uint8_t value, bool indirect) {
        if(!indirect || address < 0x80) {
            mem[address] = value;
        } else {
            // SFR
            writeSfr(address, value);
        }
    }

    void Memory::write(uint8_t address, uint8_t value) {
        write(address, value, false);
    }

    bool Memory::readBit(uint8_t address) {
        if(address < 0x80) {
            uint8_t byte = static_cast<uint8_t>(0x20 + address >> 3);
            uint8_t bit = static_cast<uint8_t>(1 << (address & 0x7));

            return mem[byte] & bit;
        } else {
            // SFR
            uint8_t byte = static_cast<uint8_t>(0x80 + (((address - 0x80) >> 3) << 3));
            uint8_t bit = static_cast<uint8_t>(1 << (address & 0x7));

            return readSfr(byte) & bit;
        }
    }

    void Memory::writeBit(uint8_t address, bool value) {
        if(address < 0x80) {
            uint8_t byte = static_cast<uint8_t>(0x20 + address >> 3);
            uint8_t bit = static_cast<uint8_t>(1 << (address & 0x7));

            if(value) {
                mem[byte] |= bit;
            } else {
                mem[byte] &= ~bit;
            }
        } else {
            // SFR
            uint8_t byte = static_cast<uint8_t>(0x80 + (((address - 0x80) >> 3) << 3));
            uint8_t bit = static_cast<uint8_t>(1 << (address & 0x7));

            // TODO: need writeSfrBit?
            if(value) {
                writeSfr(byte, readSfr(byte) | bit);
            } else {
                writeSfr(byte, readSfr(byte) & ~bit);
            }
        }
    }

    // TODO
    uint8_t Memory::readSfr(uint8_t address) {
        return 0x00;
    }

    // TODO
    void Memory::writeSfr(uint8_t address, uint8_t value) {

    }

}
