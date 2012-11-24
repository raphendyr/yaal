#ifndef __YAAL_COMMUNICATION__SHIFT__
#define __YAAL_COMMUNICATION__SHIFT__ 1

#include <inttypes.h>
#include "../qualifiers.hh"

namespace yaal {
    namespace internal {

        template< typename T,
                  typename ClockPin,
                  typename OutputPin,
                  typename InputPin,
                  bool LSBfirst = true,
                  bool ChangeClockFirst = false >
        static YAAL_INLINE("shiftByte")
        T shiftByte(T data = 0) {
            ClockPin clock;
            OutputPin output;
            InputPin input;

            if (ChangeClockFirst)
                clock = false;

            for (uint8_t i = 0; i < sizeof(T)*8; i++) {
                // write bit
                if (data & (LSBfirst ? 0x01 : (1L << (8*sizeof(T) - 1))))
                    output = true;
                else
                    output = false;
                // clock
                clock = true;
                // shift byte
                // FIXME: there should be fixed bug in gcc 4.7.0 that wont produce 16 bit shift
                data = LSBfirst ? (data >> 1) : (data << 1);
                // read bit
                if (input)
                    data |= (LSBfirst ? (1L << (8*sizeof(T) - 1)) : 0x01);
                // clock
                clock = false;
            }

            if (ChangeClockFirst)
                clock = true;

            return data;
        }

    }
}

#endif
