
#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <vector>
#include <cstdint>

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

    private:
        std::vector<std::uint8_t> mem;
    };

    class Processor {
    public:
        Processor();

        void run();

        void writeRom(uint16_t address, const std::vector<std::uint8_t> &data);

        std::uint8_t fetchRom();

        void execOp();

        void setPc(uint16_t value);

        std::vector<std::uint8_t> rom;
        Memory ram;
        std::uint16_t pc;
    private:

        void tick();
    };

}


#endif // PROCESSOR_H
