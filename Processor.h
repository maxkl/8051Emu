
#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <vector>
#include <cstdint>
#include "Memory.h"

namespace emu {

    class Processor {
    public:
        Processor();

        void run();

        void writeRom(uint16_t address, const std::vector<std::uint8_t> &data);

        std::uint8_t fetchRom();

        void execOp();

        void setPc(uint16_t value);
        void setPc(uint8_t lower, uint8_t upper);

        uint8_t getReg(uint8_t reg);
        void setReg(uint8_t reg, uint8_t value);

        uint8_t popStack();
        void pushStack(uint8_t value);

        std::vector<std::uint8_t> rom;
        Memory ram;
        std::uint16_t pc;
        std::uint8_t instruction;

        StoreSfr a;
        StoreSfr b;
        PswSfr psw;
        StoreSfr sp;
        DebugPortSfr p0;
        PortSfr p1, p2, p3, p4;
    private:
        void tick();
    };

}


#endif // PROCESSOR_H
