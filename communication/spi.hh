#ifndef __YAAL_COMMUNICATION__SPI__
#define __YAAL_COMMUNICATION__SPI__ 1

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

        static inline
        template<typename T>
        T read(void) {
            SelectPin ss;
            ss = false;
            T data = internal::shiftByte<T, ClockPin, NullPin, MisoPin, LSBfirst, ChangeClockFirst>();
            ss = true;
            return data;
        }

        static inline
        template<typename T>
        void write(T data) {
            SelectPin ss;
            ss = false;
            internal::shiftByte<T, ClockPin, MosiPin, NullPin, LSBfirst, ChangeClockFirst>(data);
            ss = true;
        }

        static inline
        template<typename T>
        T transfer(T data) {
            SelectPin ss;
            ss = false;
            data = internal::shiftByte<T, ClockPin, MosiPin, MisoPin, LSBfirst, ChangeClockFirst>(data);
            ss = true;
            return data;
        }

    };

}

#endif
