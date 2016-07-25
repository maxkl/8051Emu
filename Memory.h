
#ifndef MEMORY_H
#define MEMORY_H

#include <cstdint>
#include <vector>
#include "Sfr.h"
#include "sfrs.h"

namespace emu {

    class Memory {
    public:
        Memory();
        uint8_t read(uint8_t address, bool indirect);
        uint8_t read(uint8_t address);
        void write(uint8_t address, uint8_t value, bool indirect);
        void write(uint8_t address, uint8_t value);
        bool readBit(uint8_t address);
        void writeBit(uint8_t address, bool value);
        uint8_t readSfr(uint8_t address);
        void writeSfr(uint8_t address, uint8_t value);
        bool readSfrBit(uint8_t address, uint8_t bit);
        void writeSfrBit(uint8_t address, uint8_t bit, bool value);

        void registerSfr(uint8_t address, Sfr& sfr);

    private:
        std::vector<std::uint8_t> mem;
        std::vector<Sfr*> sfrs;
    };

}


#endif // MEMORY_H
