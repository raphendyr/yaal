#ifndef __YAAL_IO__PORTS__
#define __YAAL_IO__PORTS__ 1
#include "../requirements.hh"
#ifdef __YAAL__
/* Generated using ports.sh */

#include "types/register.hh"
#include "types/port.hh"
#include "port.hh"
#include <avr/io.h>

namespace yaal {

    namespace internal {
#       ifdef PINA
            typedef ReadonlyRegister<YAAL_ADDR(PINA)> PinA;
#       endif
#       ifdef DDRA
            typedef Register<YAAL_ADDR(DDRA)> DdrA;
#       endif
#       ifdef PORTA
            typedef Register<YAAL_ADDR(PORTA)> PortA;
#       endif
#       ifdef PINB
            typedef ReadonlyRegister<YAAL_ADDR(PINB)> PinB;
#       endif
#       ifdef DDRB
            typedef Register<YAAL_ADDR(DDRB)> DdrB;
#       endif
#       ifdef PORTB
            typedef Register<YAAL_ADDR(PORTB)> PortB;
#       endif
#       ifdef PINC
            typedef ReadonlyRegister<YAAL_ADDR(PINC)> PinC;
#       endif
#       ifdef DDRC
            typedef Register<YAAL_ADDR(DDRC)> DdrC;
#       endif
#       ifdef PORTC
            typedef Register<YAAL_ADDR(PORTC)> PortC;
#       endif
#       ifdef PIND
            typedef ReadonlyRegister<YAAL_ADDR(PIND)> PinD;
#       endif
#       ifdef DDRD
            typedef Register<YAAL_ADDR(DDRD)> DdrD;
#       endif
#       ifdef PORTD
            typedef Register<YAAL_ADDR(PORTD)> PortD;
#       endif
#       ifdef PINE
            typedef ReadonlyRegister<YAAL_ADDR(PINE)> PinE;
#       endif
#       ifdef DDRE
            typedef Register<YAAL_ADDR(DDRE)> DdrE;
#       endif
#       ifdef PORTE
            typedef Register<YAAL_ADDR(PORTE)> PortE;
#       endif
#       ifdef PINF
            typedef ReadonlyRegister<YAAL_ADDR(PINF)> PinF;
#       endif
#       ifdef DDRF
            typedef Register<YAAL_ADDR(DDRF)> DdrF;
#       endif
#       ifdef PORTF
            typedef Register<YAAL_ADDR(PORTF)> PortF;
#       endif
#       ifdef PING
            typedef ReadonlyRegister<YAAL_ADDR(PING)> PinG;
#       endif
#       ifdef DDRG
            typedef Register<YAAL_ADDR(DDRG)> DdrG;
#       endif
#       ifdef PORTG
            typedef Register<YAAL_ADDR(PORTG)> PortG;
#       endif
    }


#   if defined(PORTA) && defined(DDRA) && defined(PINA)
        typedef Port<internal::PortA, internal::DdrA, internal::PinA> PortA;
#       ifdef PORTA0
            typedef Pin<PortA, 0> PortA0;
#       endif
#       ifdef PORTA1
            typedef Pin<PortA, 1> PortA1;
#       endif
#       ifdef PORTA2
            typedef Pin<PortA, 2> PortA2;
#       endif
#       ifdef PORTA3
            typedef Pin<PortA, 3> PortA3;
#       endif
#       ifdef PORTA4
            typedef Pin<PortA, 4> PortA4;
#       endif
#       ifdef PORTA5
            typedef Pin<PortA, 5> PortA5;
#       endif
#       ifdef PORTA6
            typedef Pin<PortA, 6> PortA6;
#       endif
#       ifdef PORTA7
            typedef Pin<PortA, 7> PortA7;
#       endif
#   endif

#   if defined(PORTB) && defined(DDRB) && defined(PINB)
        typedef Port<internal::PortB, internal::DdrB, internal::PinB> PortB;
#       ifdef PORTB0
            typedef Pin<PortB, 0> PortB0;
#       endif
#       ifdef PORTB1
            typedef Pin<PortB, 1> PortB1;
#       endif
#       ifdef PORTB2
            typedef Pin<PortB, 2> PortB2;
#       endif
#       ifdef PORTB3
            typedef Pin<PortB, 3> PortB3;
#       endif
#       ifdef PORTB4
            typedef Pin<PortB, 4> PortB4;
#       endif
#       ifdef PORTB5
            typedef Pin<PortB, 5> PortB5;
#       endif
#       ifdef PORTB6
            typedef Pin<PortB, 6> PortB6;
#       endif
#       ifdef PORTB7
            typedef Pin<PortB, 7> PortB7;
#       endif
#   endif

#   if defined(PORTC) && defined(DDRC) && defined(PINC)
        typedef Port<internal::PortC, internal::DdrC, internal::PinC> PortC;
#       ifdef PORTC0
            typedef Pin<PortC, 0> PortC0;
#       endif
#       ifdef PORTC1
            typedef Pin<PortC, 1> PortC1;
#       endif
#       ifdef PORTC2
            typedef Pin<PortC, 2> PortC2;
#       endif
#       ifdef PORTC3
            typedef Pin<PortC, 3> PortC3;
#       endif
#       ifdef PORTC4
            typedef Pin<PortC, 4> PortC4;
#       endif
#       ifdef PORTC5
            typedef Pin<PortC, 5> PortC5;
#       endif
#       ifdef PORTC6
            typedef Pin<PortC, 6> PortC6;
#       endif
#       ifdef PORTC7
            typedef Pin<PortC, 7> PortC7;
#       endif
#   endif

#   if defined(PORTD) && defined(DDRD) && defined(PIND)
        typedef Port<internal::PortD, internal::DdrD, internal::PinD> PortD;
#       ifdef PORTD0
            typedef Pin<PortD, 0> PortD0;
#       endif
#       ifdef PORTD1
            typedef Pin<PortD, 1> PortD1;
#       endif
#       ifdef PORTD2
            typedef Pin<PortD, 2> PortD2;
#       endif
#       ifdef PORTD3
            typedef Pin<PortD, 3> PortD3;
#       endif
#       ifdef PORTD4
            typedef Pin<PortD, 4> PortD4;
#       endif
#       ifdef PORTD5
            typedef Pin<PortD, 5> PortD5;
#       endif
#       ifdef PORTD6
            typedef Pin<PortD, 6> PortD6;
#       endif
#       ifdef PORTD7
            typedef Pin<PortD, 7> PortD7;
#       endif
#   endif

#   if defined(PORTE) && defined(DDRE) && defined(PINE)
        typedef Port<internal::PortE, internal::DdrE, internal::PinE> PortE;
#       ifdef PORTE0
            typedef Pin<PortE, 0> PortE0;
#       endif
#       ifdef PORTE1
            typedef Pin<PortE, 1> PortE1;
#       endif
#       ifdef PORTE2
            typedef Pin<PortE, 2> PortE2;
#       endif
#       ifdef PORTE3
            typedef Pin<PortE, 3> PortE3;
#       endif
#       ifdef PORTE4
            typedef Pin<PortE, 4> PortE4;
#       endif
#       ifdef PORTE5
            typedef Pin<PortE, 5> PortE5;
#       endif
#       ifdef PORTE6
            typedef Pin<PortE, 6> PortE6;
#       endif
#       ifdef PORTE7
            typedef Pin<PortE, 7> PortE7;
#       endif
#   endif

#   if defined(PORTF) && defined(DDRF) && defined(PINF)
        typedef Port<internal::PortF, internal::DdrF, internal::PinF> PortF;
#       ifdef PORTF0
            typedef Pin<PortF, 0> PortF0;
#       endif
#       ifdef PORTF1
            typedef Pin<PortF, 1> PortF1;
#       endif
#       ifdef PORTF2
            typedef Pin<PortF, 2> PortF2;
#       endif
#       ifdef PORTF3
            typedef Pin<PortF, 3> PortF3;
#       endif
#       ifdef PORTF4
            typedef Pin<PortF, 4> PortF4;
#       endif
#       ifdef PORTF5
            typedef Pin<PortF, 5> PortF5;
#       endif
#       ifdef PORTF6
            typedef Pin<PortF, 6> PortF6;
#       endif
#       ifdef PORTF7
            typedef Pin<PortF, 7> PortF7;
#       endif
#   endif

#   if defined(PORTG) && defined(DDRG) && defined(PING)
        typedef Port<internal::PortG, internal::DdrG, internal::PinG> PortG;
#       ifdef PORTG0
            typedef Pin<PortG, 0> PortG0;
#       endif
#       ifdef PORTG1
            typedef Pin<PortG, 1> PortG1;
#       endif
#       ifdef PORTG2
            typedef Pin<PortG, 2> PortG2;
#       endif
#       ifdef PORTG3
            typedef Pin<PortG, 3> PortG3;
#       endif
#       ifdef PORTG4
            typedef Pin<PortG, 4> PortG4;
#       endif
#       ifdef PORTG5
            typedef Pin<PortG, 5> PortG5;
#       endif
#       ifdef PORTG6
            typedef Pin<PortG, 6> PortG6;
#       endif
#       ifdef PORTG7
            typedef Pin<PortG, 7> PortG7;
#       endif
#   endif

}

#endif
#endif
