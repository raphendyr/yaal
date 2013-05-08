#ifndef __YAAL_IO__SERIALS__
#define __YAAL_IO__SERIALS__ 1
#include "../requirements.hh"
#ifdef __YAAL__

/* USART/Serial interface
 */

#include "types/serial.hh"
#include "registers/serial.hh"

namespace yaal {

#ifdef UDR
    typedef internal::Serial<internal::Udr, internal::Ucsra, internal::Ucsrb, internal::Ucsrc, internal::Ubrr> Serial0;
#else
#  ifdef UDR0
    typedef internal::Serial<internal::Udr0, internal::Ucsr0a, internal::Ucsr0b, internal::Ucsr0c, internal::Ubrr0> Serial0;
#  endif
#  ifdef UDR1
    typedef internal::Serial<internal::Udr1, internal::Ucsr1a, internal::Ucsr1b, internal::Ucsr1c, internal::Ubrr1> Serial1;
#  endif
#  ifdef UDR2
    typedef internal::Serial<internal::Udr2, internal::Ucsr2a, internal::Ucsr2b, internal::Ucsr2c, internal::Ubrr2> Serial2;
#  endif
#  ifdef UDR3
    typedef internal::Serial<internal::Udr3, internal::Ucsr3a, internal::Ucsr3b, internal::Ucsr3c, internal::Ubrr3> Serial3;
#  endif
#endif

}

#endif
#endif
