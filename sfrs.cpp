
#include "sfrs.h"

namespace emu {

    StoreSfr::StoreSfr()
            : val(0) {

    }

    StoreSfr::StoreSfr(uint8_t value)
            : val(value) {

    }

    uint8_t StoreSfr::read() {
        return val;
    }

    void StoreSfr::write(uint8_t value) {
        val = value;
    }

    PswSfr::PswSfr() {

    }

    uint8_t PswSfr::read() {
        uint8_t psw = static_cast<uint8_t>(
                p << 0 |
                ud << 1 |
                ov << 2 |
                rs0 << 3 |
                rs1 << 4 |
                f0 << 5 |
                ac << 6 |
                cy << 7
        );

        return psw;
    }

    void PswSfr::write(uint8_t value) {
        p = static_cast<bool>(value & (1 << 0));
        ud = static_cast<bool>(value & (1 << 1));
        ov = static_cast<bool>(value & (1 << 2));
        rs0 = static_cast<bool>(value & (1 << 3));
        rs1 = static_cast<bool>(value & (1 << 4));
        f0 = static_cast<bool>(value & (1 << 5));
        ac = static_cast<bool>(value & (1 << 6));
        cy = static_cast<bool>(value & (1 << 7));
    }

    PortSfr::PortSfr()
            : outputValue(0xff),
              inputValue(0x00) {

    }

    uint8_t PortSfr::read() {
        return inputValue & outputValue;
    }

    void PortSfr::write(uint8_t value) {
        printf("Port set to 0x%02x\n", value);
        outputValue = value;
    }
}
