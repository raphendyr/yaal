#ifndef __YAAL_COMMUNICATION__HWSPI__
#define __YAAL_COMMUNICATION__HWSPI__ 1
#include "../requirements.hh"
#ifdef __YAAL__

namespace yaal {

    template< typename Derived >
    struct HWSPI : public interface::SycronousPointToPoint<Derived> {

        void setup(void) {
            // implement
            SPCR |= _BV(MSTR); // ?
            SPCR |= _BV(SPE);  // ?
        }

        void teardown(void) {
            SPCR &= ~_BV(SPE); // ?
        }

        void SPIClass::setBitOrder(uint8_t bitOrder)
        {
            if(bitOrder == LSBFIRST) {
                SPCR |= _BV(DORD);
            } else {
                SPCR &= ~(_BV(DORD));
            }
        }

        void SPIClass::setDataMode(uint8_t mode)
        {
            SPCR = (SPCR & ~SPI_MODE_MASK) | mode;
        }

        void SPIClass::setClockDivider(uint8_t rate)
        {
            SPCR = (SPCR & ~SPI_CLOCK_MASK) | (rate & SPI_CLOCK_MASK);
            SPSR = (SPSR & ~SPI_2XCLOCK_MASK) | ((rate >> 2) & SPI_2XCLOCK_MASK);
        }

        bool transfer_complete(void) {
            return SPSR & _BV(SPIF);
        }

        uint8_t transfer(uint8_t data) {
            SPDR = data;
            while (!transfer_complete());
            return SPDR;
        }

        void SPIClass::attachInterrupt() {
            SPCR |= _BV(SPIE);
        }

        void SPIClass::detachInterrupt() {
            SPCR &= ~_BV(SPIE);
        }


        uint8_t get(void) {
        }

        void put(uint8_t data) {
        }


        template<typename T>
        static inline
        T transfer(T data) {
        }

        template<typename T>
        static inline
        T transfer(T data, uint8_t bits) {
        }
    };

}

#endif
#endif
