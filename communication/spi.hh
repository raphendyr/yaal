#ifndef __YAAL_COMMUNICATION__SPI__
#define __YAAL_COMMUNICATION__SPI__ 1
#include "../requirements.hh"
#ifdef __YAAL__

#include "shift.hh"
#include "../io/types/pin.hh"

namespace yaal {

    /* SPIBus<ClockPin, MosiPin, MisoPin, LSBfirst> */
    template< typename ClockPin,
              typename MosiPin,
              typename MisoPin,
              bool LSBfirst = true,
              bool ChangeClockFirst = false >
    struct SPIBus {

        YAAL_INLINE("SPIBus::setup")
        void setup(void) {
            ClockPin clock;
            MosiPin mosi;
            MisoPin miso;

            clock.mode = OUTPUT;
            mosi.mode = OUTPUT;
            miso.mode = OUTPUT;
        }

        template<typename T>
        inline
        T read(void) {
            return internal::shiftBits<T, ClockPin, NullPin, MisoPin, LSBfirst, ChangeClockFirst>(0);
        }

        template<typename T>
        inline
        T read(uint8_t bits) {
            return internal::shiftBits<T, ClockPin, NullPin, MisoPin, LSBfirst, ChangeClockFirst>(0, bits);
        }


        template<typename T>
        inline
        void write(T data) {
            internal::shiftBits<T, ClockPin, MosiPin, NullPin, LSBfirst, ChangeClockFirst>(data);
        }

        template<typename T>
        inline
        void write(T data, uint8_t bits) {
            internal::shiftBits<T, ClockPin, MosiPin, NullPin, LSBfirst, ChangeClockFirst>(data, bits);
        }

        template<typename T>
        inline
        T transfer(T data) {
            return internal::shiftBits<T, ClockPin, MosiPin, MisoPin, LSBfirst, ChangeClockFirst>(data);
        }

        template<typename T>
        inline
        T transfer(T data, uint8_t bits) {
            return internal::shiftBits<T, ClockPin, MosiPin, MisoPin, LSBfirst, ChangeClockFirst>(data, bits);
        }
    };

    /* SPIDevice<SPIBus, ChipSelectPin> */
    template< typename SPIBus,
              typename SelectPin >
    struct SPIDevice {
        SPIBus bus;

        YAAL_INLINE("SPIDevice::setup")
        void setup() {
            SelectPin ss;
            ss.mode = OUTPUT;
        }

        template<typename T>
        T read() {
            LowPeriod<SelectPin> for_this_block;
            return bus.read<T>();
        }

        template<typename T>
        T read(uint8_t bits) {
            LowPeriod<SelectPin> for_this_block;
            return bus.read<T>(bits);
        }

        template<typename T>
        void write(T data) {
            LowPeriod<SelectPin> for_this_block;
            bus.write<T>(data);
        }

        template<typename T>
        void write(T data, uint8_t bits) {
            LowPeriod<SelectPin> for_this_block;
            bus.write<T>(data, bits);
        }

        template<typename T>
        T transfer(T data) {
            LowPeriod<SelectPin> for_this_block;
            return bus.transfer<T>(data);
        }

        template<typename T>
        T transfer(T data, uint8_t bits) {
            LowPeriod<SelectPin> for_this_block;
            return bus.transfer<T>(data, bits);
        }
    };

    template< typename ClockPin,
              typename MosiPin,
              typename MisoPin,
              typename SelectPin,
              bool LSBfirst = true,
              bool ChangeClockFirst = false >
    class SPI : public SPIDevice<SPIBus<ClockPin, MosiPin, MisoPin, LSBfirst, ChangeClockFirst>, SelectPin> {
        typedef SPIDevice<SPIBus<ClockPin, MosiPin, MisoPin, LSBfirst, ChangeClockFirst>, SelectPin> super;

    public:
        YAAL_INLINE("SPI::setup")
        void setup() {
            this->bus.setup();
            super::setup();
        }
    };
}

#endif
#endif
