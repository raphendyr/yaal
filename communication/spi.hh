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

            clock.output();
            mosi.output();
            miso.output();
            ss.output();
        }

        static inline
        uint8_t read(void) {
            SelectPin ss;
            ss = false;
            uint8_t byte = internal::shiftByte<ClockPin, NullPin, MisoPin, LSBfirst, ChangeClockFirst>();
            ss = true;
            return byte;
        }

        static inline
        void write(uint8_t byte) {
            SelectPin ss;
            ss = false;
            internal::shiftByte<ClockPin, MosiPin, NullPin, LSBfirst, ChangeClockFirst>(byte);
            ss = true;
        }

        static inline
        uint8_t transfer(uint8_t byte) {
            SelectPin ss;
            ss = false;
            byte = internal::shiftByte<ClockPin, MosiPin, MisoPin, LSBfirst, ChangeClockFirst>(byte);
            ss = true;
            return byte;
        }

    };

}

#endif
