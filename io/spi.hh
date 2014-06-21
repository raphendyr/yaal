#ifndef __YAAL_IO__SPI__
#define __YAAL_IO__SPI__ 1
#include "../requirements.hh"
#ifdef __YAAL__

/* SPI
 */
#include "types/spi.hh"
#include "registers/spi.hh"

namespace yaal {

    // atmega16u4 and atmega32u4
#   if defined(__AVR_ATmega16U4__) || defined(__AVR_ATmega32U4__)
        typedef internal::SpiBus<internal::SpiRegisters, PB1, PB2, PB3, PB0> SPI;

    // atmega48pa, atmega88pa, atmega168pa, atmega328p
#   elif defined(__ATmega48PA__) && defined(__ATmega88PA__) && defined(__ATmega168PA__) && defined(__AVR_ATmega328P__)
        typedef internal::SpiBus<internal::SpiRegisters, PB5, PB3, PB4, PB2> SPI;

#   else
#       warning "There is no SPI defines for your MCU. Update yaal/io/spi.hh"
#   endif

}

#endif
#endif
