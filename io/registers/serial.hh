#ifndef __YAAL_IO__REGISTERS__SERIAL__
#define __YAAL_IO__REGISTERS__SERIAL__ 1
#include "../../requirements.hh"
#ifdef __YAAL__
// do not edit. generated using serial.sh

#include "../types/register.hh"
#include <avr/io.h>

namespace yaal {
    namespace internal {

#       ifdef UBRR
            typedef Register<YAAL_ADDR(UBRR), reg16_t> Ubrr;
#           undef UBRR
#       endif

#       ifdef UBRR0
            typedef Register<YAAL_ADDR(UBRR0), reg16_t> Ubrr0;
#           undef UBRR0
#       endif

#       ifdef UBRR1
            typedef Register<YAAL_ADDR(UBRR1), reg16_t> Ubrr1;
#           undef UBRR1
#       endif

#       ifdef UBRR2
            typedef Register<YAAL_ADDR(UBRR2), reg16_t> Ubrr2;
#           undef UBRR2
#       endif

#       ifdef UBRR3
            typedef Register<YAAL_ADDR(UBRR3), reg16_t> Ubrr3;
#           undef UBRR3
#       endif

#       ifdef UCSR0A
            typedef Register<YAAL_ADDR(UCSR0A), reg8_t> Ucsr0a;
#           undef UCSR0A
#       endif

#       ifdef UCSR0B
            typedef Register<YAAL_ADDR(UCSR0B), reg8_t> Ucsr0b;
#           undef UCSR0B
#       endif

#       ifdef UCSR0C
            typedef Register<YAAL_ADDR(UCSR0C), reg8_t> Ucsr0c;
#           undef UCSR0C
#       endif

#       ifdef UCSR1A
            typedef Register<YAAL_ADDR(UCSR1A), reg8_t> Ucsr1a;
#           undef UCSR1A
#       endif

#       ifdef UCSR1B
            typedef Register<YAAL_ADDR(UCSR1B), reg8_t> Ucsr1b;
#           undef UCSR1B
#       endif

#       ifdef UCSR1C
            typedef Register<YAAL_ADDR(UCSR1C), reg8_t> Ucsr1c;
#           undef UCSR1C
#       endif

#       ifdef UCSR2A
            typedef Register<YAAL_ADDR(UCSR2A), reg8_t> Ucsr2a;
#           undef UCSR2A
#       endif

#       ifdef UCSR2B
            typedef Register<YAAL_ADDR(UCSR2B), reg8_t> Ucsr2b;
#           undef UCSR2B
#       endif

#       ifdef UCSR2C
            typedef Register<YAAL_ADDR(UCSR2C), reg8_t> Ucsr2c;
#           undef UCSR2C
#       endif

#       ifdef UCSR3A
            typedef Register<YAAL_ADDR(UCSR3A), reg8_t> Ucsr3a;
#           undef UCSR3A
#       endif

#       ifdef UCSR3B
            typedef Register<YAAL_ADDR(UCSR3B), reg8_t> Ucsr3b;
#           undef UCSR3B
#       endif

#       ifdef UCSR3C
            typedef Register<YAAL_ADDR(UCSR3C), reg8_t> Ucsr3c;
#           undef UCSR3C
#       endif

#       ifdef UCSRA
            typedef Register<YAAL_ADDR(UCSRA), reg8_t> Ucsra;
#           undef UCSRA
#       endif

#       ifdef UCSRB
            typedef Register<YAAL_ADDR(UCSRB), reg8_t> Ucsrb;
#           undef UCSRB
#       endif

#       ifdef UCSRC
            typedef Register<YAAL_ADDR(UCSRC), reg8_t> Ucsrc;
#           undef UCSRC
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
