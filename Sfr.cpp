
#include "Sfr.h"

namespace emu {

    bool Sfr::readBit(uint8_t bit) {
        return static_cast<bool>(read() & (1 << bit));
    }

    void Sfr::writeBit(uint8_t bit, bool value) {
        uint8_t old = read();
        uint8_t mask = static_cast<uint8_t>(1 << bit);
        write(value ? old | mask : old & ~mask);
    }

}
