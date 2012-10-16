#ifndef __YAAL_COMMUNICATION__SHIFT__
#define __YAAL_COMMUNICATION__SHIFT__ 1

#include "../qualifiers.hh"

namespace yaal {
    namespace internal {

        template< typename ClockPin,
                  typename OutputPin,
                  typename InputPin,
                  bool LSBfirst = true,
                  bool ChangeClockFirst = false >
        static YAAL_INLINE("shiftByte")
        uint8_t shiftByte(uint8_t byte = 0) {
            ClockPin clock;
            OutputPin output;
            InputPin input;

            if (ChangeClockFirst)
                clock = false;

            for (uint8_t i = 0; i < 8; i++) {
                // clock
                clock = true;
                // write bit
                if (byte & (LSBfirst ? 0x01 : 0x80))
                    output = true;
                else
                    output = false;
                // shift byte
                // FIXME: there should be fixed bug in gcc 4.7.0 that wont produce 16 bit shift
                byte = LSBfirst ? (byte >> 1) : (byte << 1);
                // read bit
                if (input)
                    byte |= LSBfirst ? 0x80 : 0x01;
                // clock
                clock = false;
            }

            if (ChangeClockFirst)
                clock = true;

            return byte;
        }

    }
}

#endif
