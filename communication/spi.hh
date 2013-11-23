#ifndef __YAAL_COMMUNICATION__SPI__
#define __YAAL_COMMUNICATION__SPI__ 1
#include "../requirements.hh"
#ifdef __YAAL__

#include "shift.hh"
#include "../io/types/pin.hh"
#include "../interface/stream.hh"

namespace yaal {

# define yaal__SPIType SPI < \
    ClockPin, \
    MosiPin, \
    MisoPin, \
    SelectPin, \
    LSBfirst, \
    ChangeClockFirst >
    template< typename ClockPin,
              typename MosiPin,
              typename MisoPin,
              typename SelectPin,
              bool LSBfirst = true,
              bool ChangeClockFirst = false >
    class SPI : public interface::Communicable< yaal__SPIType > {
        friend class interface::Communication< yaal__SPIType >;
# undef yaal__SPIType

    private:
        ClockPin clock;
        MosiPin mosi;
        MisoPin miso;
        SelectPin ss;

    public:
        YAAL_INLINE("SPI::setup")
        void setup(void) {
            clock.mode = OUTPUT;
            mosi.mode = OUTPUT;
            miso.mode = OUTPUT;
            ss.mode = OUTPUT;
        }

    protected:
        /* These protected methods should be used only through Communication interface.
         * Read more from interface::Communicable
         */

        void begin() {
            ss = false;
        }

        void end() {
            ss = true;
        }

        /* Read */

        uint8_t get() {
            uint8_t data;
            this->read(data);
            return data;
        }

        template<typename T>
        void read(T& data) {
            data = internal::shiftBits<T, ClockPin, NullPin, MisoPin, LSBfirst, ChangeClockFirst>(0);
        }

        template<typename T>
        void readbits(T& data, uint8_t bits) {
            data = internal::shiftBits<T, ClockPin, NullPin, MisoPin, LSBfirst, ChangeClockFirst>(0, bits);
        }

        /* Write */

        void put(uint8_t byte) {
            this->write(byte);
        }

        template<typename T>
        void write(T& data) {
            internal::shiftBits<T, ClockPin, MosiPin, NullPin, LSBfirst, ChangeClockFirst>(data);
        }

        template<typename T>
        void writebits(T& data, uint8_t bits) {
            internal::shiftBits<T, ClockPin, MosiPin, NullPin, LSBfirst, ChangeClockFirst>(data, bits);
        }

        /* Read/Write at same time = Transfer */

        template<typename T>
        T transfer(T data) {
            return internal::shiftBits<T, ClockPin, MosiPin, MisoPin, LSBfirst, ChangeClockFirst>(data);
        }

        template<typename T>
        T transferbits(T data, uint8_t bits) {
            return internal::shiftBits<T, ClockPin, MosiPin, MisoPin, LSBfirst, ChangeClockFirst>(data, bits);
        }
    };

}

#endif
#endif
