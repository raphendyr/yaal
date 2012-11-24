#ifndef __YAAL_COMMUNICATION__SHIFT__
#define __YAAL_COMMUNICATION__SHIFT__ 1

#include <inttypes.h>
#include "../qualifiers.hh"

namespace yaal {
    namespace internal {

        template< typename ClockPin,
                  typename OutputPin,
                  bool LSBfirst = true,
                  //bool ChangeClockFirst = false,
                  typename function>
        static YAAL_INLINE("shiftBitsIf")
        void shiftBitsIf(uint8_t bits, function callback) {
            ClockPin clock;
            OutputPin output;

            // put clock down first
            //if (ChangeClockFirst)
            //    clock = false;

            // loop through all bits
            for (uint8_t i = 0; i < bits; i++) {
                // clock
                clock = false;
                // write bit
                if (callback(i))
                    output = true;
                else
                    output = false;
                // clock
                clock = true;
            }

            clock = false;

            // put clock up first
            //if (ChangeClockFirst)
            //    clock = true;
        }

        // FIXME: rewrite using shiftBitsIf
        template< typename T,
                  typename ClockPin,
                  typename OutputPin,
                  typename InputPin,
                  bool LSBfirst = true,
                  bool ChangeClockFirst = false >
        static YAAL_INLINE("shiftBits")
        T shiftBits(T data, uint8_t bits) {
            ClockPin clock;
            OutputPin output;
            InputPin input;

            // move bits to left for MSB transfer
            // FIXME: do not do when output is null
            if (!LSBfirst)
                data <<= (8*sizeof(T) - bits);

            // put clock down first
            if (ChangeClockFirst)
                clock = false;

            // loop through all bits
            for (uint8_t i = 0; i < bits; i++) {
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

            // put clock up first
            if (ChangeClockFirst)
                clock = true;

            // right shift
            // FIXME: do not do this, when input is null
            if (LSBfirst)
                data >>= (8*sizeof(T) - bits);

            // reaturn read data
            return data;
        }

        template< typename T,
                  typename ClockPin,
                  typename OutputPin,
                  typename InputPin,
                  bool LSBfirst = true,
                  bool ChangeClockFirst = false >
        static YAAL_INLINE("shiftBits")
        T shiftBits(T data) {
            // Call myself with number of bits for type
            return shiftBits<T, ClockPin, OutputPin, InputPin, LSBfirst, ChangeClockFirst>(data, sizeof(T)*8);
        }

    }
}

#endif
