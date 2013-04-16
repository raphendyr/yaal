#ifndef __YAAL_IO__SERIALS__
#define __YAAL_IO__SERIALS__ 1

#include <avr/io.h>
#include "registers/serial.hh"
#include "types/serial.hh"

namespace yaal {

    #ifdef UDR0
    typedef internal::Serial<internal::Udr0, internal::Ucsr0a, internal::Ucsr0b, internal::Ucsr0c, internal::Ubrr0l, internal::Ubrr0h> Serial0;
    #endif

    #ifdef UDR1
    typedef internal::Serial<internal::Udr1, internal::Ucsr1a, internal::Ucsr1b, internal::Ucsr1c, internal::Ubrr1l, internal::Ubrr1h> Serial1;
    #endif

    #ifdef UDR2
    typedef internal::Serial<internal::Udr2, internal::Ucsr2a, internal::Ucsr2b, internal::Ucsr2c, internal::Ubrr2l, internal::Ubrr2h> Serial2;
    #endif

    #ifdef UDR3
    typedef internal::Serial<internal::Udr3, internal::Ucsr3a, internal::Ucsr3b, internal::Ucsr3c, internal::Ubrr3l, internal::Ubrr3h> Serial3;
    #endif
}

#endif
