#ifndef __YAAL_IO__SERIALREGS__
#define __YAAL_IO__SERIALREGS__ 1
#include "../../requirements.hh"
#ifdef __YAAL__
// do not edit. generated using serialregs.sh

#include "../register.hh"
#include <avr/io.h>

namespace yaal {
    namespace internal {

#       ifdef UBRR
            typedef Register<YAAL_ADDR(UBRR), reg16_t> Ubrr;
#       endif

#       ifdef UBRR0
            typedef Register<YAAL_ADDR(UBRR0), reg16_t> Ubrr0;
#       endif

#       ifdef UBRR1
            typedef Register<YAAL_ADDR(UBRR1), reg16_t> Ubrr1;
#       endif

#       ifdef UBRR2
            typedef Register<YAAL_ADDR(UBRR2), reg16_t> Ubrr2;
#       endif

#       ifdef UBRR3
            typedef Register<YAAL_ADDR(UBRR3), reg16_t> Ubrr3;
#       endif

#       ifdef UBRR0H
            typedef Register<YAAL_ADDR(UBRR0H), reg8_t> Ubrr0h;
#       endif

#       ifdef UBRR0L
            typedef Register<YAAL_ADDR(UBRR0L), reg8_t> Ubrr0l;
#       endif

#       ifdef UBRR1H
            typedef Register<YAAL_ADDR(UBRR1H), reg8_t> Ubrr1h;
#       endif

#       ifdef UBRR1L
            typedef Register<YAAL_ADDR(UBRR1L), reg8_t> Ubrr1l;
#       endif

#       ifdef UBRR2H
            typedef Register<YAAL_ADDR(UBRR2H), reg8_t> Ubrr2h;
#       endif

#       ifdef UBRR2L
            typedef Register<YAAL_ADDR(UBRR2L), reg8_t> Ubrr2l;
#       endif

#       ifdef UBRR3H
            typedef Register<YAAL_ADDR(UBRR3H), reg8_t> Ubrr3h;
#       endif

#       ifdef UBRR3L
            typedef Register<YAAL_ADDR(UBRR3L), reg8_t> Ubrr3l;
#       endif

#       ifdef UBRRH
            typedef Register<YAAL_ADDR(UBRRH), reg8_t> Ubrrh;
#       endif

#       ifdef UBRRL
            typedef Register<YAAL_ADDR(UBRRL), reg8_t> Ubrrl;
#       endif

#       ifdef UCSR0A
            typedef Register<YAAL_ADDR(UCSR0A), reg8_t> Ucsr0a;
#       endif

#       ifdef UCSR0B
            typedef Register<YAAL_ADDR(UCSR0B), reg8_t> Ucsr0b;
#       endif

#       ifdef UCSR0C
            typedef Register<YAAL_ADDR(UCSR0C), reg8_t> Ucsr0c;
#       endif

#       ifdef UCSR1A
            typedef Register<YAAL_ADDR(UCSR1A), reg8_t> Ucsr1a;
#       endif

#       ifdef UCSR1B
            typedef Register<YAAL_ADDR(UCSR1B), reg8_t> Ucsr1b;
#       endif

#       ifdef UCSR1C
            typedef Register<YAAL_ADDR(UCSR1C), reg8_t> Ucsr1c;
#       endif

#       ifdef UCSR2A
            typedef Register<YAAL_ADDR(UCSR2A), reg8_t> Ucsr2a;
#       endif

#       ifdef UCSR2B
            typedef Register<YAAL_ADDR(UCSR2B), reg8_t> Ucsr2b;
#       endif

#       ifdef UCSR2C
            typedef Register<YAAL_ADDR(UCSR2C), reg8_t> Ucsr2c;
#       endif

#       ifdef UCSR3A
            typedef Register<YAAL_ADDR(UCSR3A), reg8_t> Ucsr3a;
#       endif

#       ifdef UCSR3B
            typedef Register<YAAL_ADDR(UCSR3B), reg8_t> Ucsr3b;
#       endif

#       ifdef UCSR3C
            typedef Register<YAAL_ADDR(UCSR3C), reg8_t> Ucsr3c;
#       endif

#       ifdef UCSRA
            typedef Register<YAAL_ADDR(UCSRA), reg8_t> Ucsra;
#       endif

#       ifdef UCSRB
            typedef Register<YAAL_ADDR(UCSRB), reg8_t> Ucsrb;
#       endif

#       ifdef UCSRC
            typedef Register<YAAL_ADDR(UCSRC), reg8_t> Ucsrc;
#       endif

#       ifdef UDR
            typedef Register<YAAL_ADDR(UDR), reg8_t> Udr;
#       endif

#       ifdef UDR0
            typedef Register<YAAL_ADDR(UDR0), reg8_t> Udr0;
#       endif

#       ifdef UDR1
            typedef Register<YAAL_ADDR(UDR1), reg8_t> Udr1;
#       endif

#       ifdef UDR2
            typedef Register<YAAL_ADDR(UDR2), reg8_t> Udr2;
#       endif

#       ifdef UDR3
            typedef Register<YAAL_ADDR(UDR3), reg8_t> Udr3;
#       endif

    }
}

#endif
#endif
