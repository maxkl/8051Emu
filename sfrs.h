
#ifndef SFRS_H
#define SFRS_H

#include <iostream>
#include "Sfr.h"

namespace emu {

    class StoreSfr : public Sfr {
    public:
        StoreSfr();
        StoreSfr(uint8_t value);

        virtual uint8_t read();
        virtual void write(uint8_t value);

    protected:
        uint8_t val;
    };

    class PswSfr : public Sfr {
    public:
        PswSfr();

        virtual uint8_t read();
        virtual void write(uint8_t value);

        uint8_t getRegistersBaseAddress();

        bool p = false, ud = false, ov = false, rs0 = false, rs1 = false, f0 = false, ac = false, cy = false;
    };

    class PortSfr : public Sfr {
    public:
        PortSfr();

        virtual uint8_t read();
        virtual void write(uint8_t value);

    private:
        uint8_t outputValue;
        uint8_t inputValue;
    };

    class DebugPortSfr : public PortSfr {
    public:
        DebugPortSfr();

        virtual void write(uint8_t value);
    };

}

#endif // SFRS_H
