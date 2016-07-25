
#ifndef SFR_H
#define SFR_H

#include <cstdint>

namespace emu {

    class Sfr {
    public:
        virtual uint8_t read() = 0;
        virtual void write(uint8_t value) = 0;
        virtual bool readBit(uint8_t bit);
        virtual void writeBit(uint8_t bit, bool value);
    };

}

#endif // SFR_H
