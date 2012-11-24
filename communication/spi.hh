#ifndef __YAAL_COMMUNICATION__SPI__
#define __YAAL_COMMUNICATION__SPI__ 1

#include <inttypes.h>
#include "shift.hh"
#include "../io/null.hh"
#include "../qualifiers.hh"

namespace yaal {

    template< typename ClockPin,
              typename MosiPin,
              typename MisoPin,
              typename SelectPin,
              bool LSBfirst = true,
              bool ChangeClockFirst = false >
    struct SPI {

        static YAAL_INLINE("SPI.setup()")
        void setup(void) {
            ClockPin clock;
            MosiPin mosi;
            MisoPin miso;
            SelectPin ss;

            clock.mode = OUTPUT;
            mosi.mode = OUTPUT;
            miso.mode = OUTPUT;
            ss.mode = OUTPUT;
        }

        template<typename T>
        static inline
        T read(void) {
            SelectPin ss;
            ss = false;
            T data = internal::shiftBits<T, ClockPin, NullPin, MisoPin, LSBfirst, ChangeClockFirst>(0);
            ss = true;
            return data;
        }

        template<typename T>
        static inline
        T read(uint8_t bits) {
            SelectPin ss;
            ss = false;
            T data = internal::shiftBits<T, ClockPin, NullPin, MisoPin, LSBfirst, ChangeClockFirst>(0, bits);
            ss = true;
            return data;
        }


        template<typename T>
        static inline
        void write(T data) {
            SelectPin ss;
            ss = false;
            internal::shiftBits<T, ClockPin, MosiPin, NullPin, LSBfirst, ChangeClockFirst>(data);
            ss = true;
        }

        template<typename T>
        static inline
        void write(T data, uint8_t bits) {
            SelectPin ss;
            ss = false;
            internal::shiftBits<T, ClockPin, MosiPin, NullPin, LSBfirst, ChangeClockFirst>(data, bits);
            ss = true;
        }

        template<typename T>
        static inline
        T transfer(T data) {
            SelectPin ss;
            ss = false;
            data = internal::shiftBits<T, ClockPin, MosiPin, MisoPin, LSBfirst, ChangeClockFirst>(data);
            ss = true;
            return data;
        }

        template<typename T>
        static inline
        T transfer(T data, uint8_t bits) {
            SelectPin ss;
            ss = false;
            data = internal::shiftBits<T, ClockPin, MosiPin, MisoPin, LSBfirst, ChangeClockFirst>(data, bits);
            ss = true;
            return data;
        }
    };

}

#endif
