
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

        bool p, ud, ov, rs0, rs1, f0, ac, cy;
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

}

#endif // SFRS_H
