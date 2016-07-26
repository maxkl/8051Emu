//
// Created by max on 24.07.16.
//

#include <iostream>
#include <memory>
#include "Memory.h"
#include "sfrs.h"

namespace emu {

    Memory::Memory()
            : mem(256),
              sfrs(128, nullptr) {
    }

    uint8_t Memory::read(uint8_t address, bool indirect) {
        if(!indirect && address < 0x80) {
            return mem[address];
        } else {
            // SFR
            return readSfr(static_cast<uint8_t>(address - 0x80));
        }
    }

    uint8_t Memory::read(uint8_t address) {
        return read(address, false);
    }

    void Memory::write(uint8_t address, uint8_t value, bool indirect) {
        if(!indirect && address < 0x80) {
            mem[address] = value;
        } else {
            // SFR
            writeSfr(static_cast<uint8_t>(address - 0x80), value);
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
            uint8_t byte = static_cast<uint8_t>(((address - 0x80) >> 3) << 3);
            uint8_t bit = static_cast<uint8_t>(address & 0x7);

            return readSfrBit(byte, bit);
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
            uint8_t byte = static_cast<uint8_t>(((address - 0x80) >> 3) << 3);
            uint8_t bit = static_cast<uint8_t>(address & 0x7);

            writeSfrBit(byte, bit, value);
        }
    }

    uint8_t Memory::readSfr(uint8_t address) {
        if(address <= 0xff && sfrs[address] != nullptr) {
            return sfrs[address]->read();
        } else {
            printf("Reading unregistered SFR 0x%02x\n", address);
            return 0x00;
        }
    }

    void Memory::writeSfr(uint8_t address, uint8_t value) {
        if(address <= 0xff && sfrs[address] != nullptr) {
            sfrs[address]->write(value);
        } else {
            printf("Writing unregistered SFR 0x%02x\n", address);
        }
    }

    bool Memory::readSfrBit(uint8_t address, uint8_t bit) {
        if(address <= 0xff && bit <= 0x7 && sfrs[address] != nullptr) {
            return sfrs[address]->readBit(bit);
        } else {
            printf("Reading unregistered SFR bit 0x%02x\n", address);
            return 0x00;
        }
    }

    void Memory::writeSfrBit(uint8_t address, uint8_t bit, bool value) {
        if(address <= 0xff && bit <= 0x7 && sfrs[address] != nullptr) {
            sfrs[address]->writeBit(bit, value);
        } else {
            printf("Writing unregistered SFR bit 0x%02x\n", address);
        }
    }

    void Memory::registerSfr(uint8_t address, Sfr& sfr) {
        if(address <= 0xff) {
            sfrs[address] = &sfr;
        }
    }

}
