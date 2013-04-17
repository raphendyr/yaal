#ifndef __YAAL_IO__PORTS__
#define __YAAL_IO__PORTS__ 1
#include "../requirements.hh"
#ifdef __YAAL__
/* Generated using ports.sh */

#include "types/port.hh"
#include "types/pin.hh"
#include "registers/port.hh"

namespace yaal {

    /*  port A  */
#   if defined(PORTA) && defined(DDRA) && defined(PINA)
        typedef Port<internal::PortAReg, internal::DdrAReg, internal::PinAReg> PortA;

#       ifdef PORTA0
            typedef Pin<PortA, PORTA0> PortA0;
#       endif
#       ifdef PORTA1
            typedef Pin<PortA, PORTA1> PortA1;
#       endif
#       ifdef PORTA2
            typedef Pin<PortA, PORTA2> PortA2;
#       endif
#       ifdef PORTA3
            typedef Pin<PortA, PORTA3> PortA3;
#       endif
#       ifdef PORTA4
            typedef Pin<PortA, PORTA4> PortA4;
#       endif
#       ifdef PORTA5
            typedef Pin<PortA, PORTA5> PortA5;
#       endif
#       ifdef PORTA6
            typedef Pin<PortA, PORTA6> PortA6;
#       endif
#       ifdef PORTA7
            typedef Pin<PortA, PORTA7> PortA7;
#       endif
#   endif

    /*  port B  */
#   if defined(PORTB) && defined(DDRB) && defined(PINB)
        typedef Port<internal::PortBReg, internal::DdrBReg, internal::PinBReg> PortB;

#       ifdef PORTB0
            typedef Pin<PortB, PORTB0> PortB0;
#       endif
#       ifdef PORTB1
            typedef Pin<PortB, PORTB1> PortB1;
#       endif
#       ifdef PORTB2
            typedef Pin<PortB, PORTB2> PortB2;
#       endif
#       ifdef PORTB3
            typedef Pin<PortB, PORTB3> PortB3;
#       endif
#       ifdef PORTB4
            typedef Pin<PortB, PORTB4> PortB4;
#       endif
#       ifdef PORTB5
            typedef Pin<PortB, PORTB5> PortB5;
#       endif
#       ifdef PORTB6
            typedef Pin<PortB, PORTB6> PortB6;
#       endif
#       ifdef PORTB7
            typedef Pin<PortB, PORTB7> PortB7;
#       endif
#   endif

    /*  port C  */
#   if defined(PORTC) && defined(DDRC) && defined(PINC)
        typedef Port<internal::PortCReg, internal::DdrCReg, internal::PinCReg> PortC;

#       ifdef PORTC0
            typedef Pin<PortC, PORTC0> PortC0;
#       endif
#       ifdef PORTC1
            typedef Pin<PortC, PORTC1> PortC1;
#       endif
#       ifdef PORTC2
            typedef Pin<PortC, PORTC2> PortC2;
#       endif
#       ifdef PORTC3
            typedef Pin<PortC, PORTC3> PortC3;
#       endif
#       ifdef PORTC4
            typedef Pin<PortC, PORTC4> PortC4;
#       endif
#       ifdef PORTC5
            typedef Pin<PortC, PORTC5> PortC5;
#       endif
#       ifdef PORTC6
            typedef Pin<PortC, PORTC6> PortC6;
#       endif
#       ifdef PORTC7
            typedef Pin<PortC, PORTC7> PortC7;
#       endif
#   endif

    /*  port D  */
#   if defined(PORTD) && defined(DDRD) && defined(PIND)
        typedef Port<internal::PortDReg, internal::DdrDReg, internal::PinDReg> PortD;

#       ifdef PORTD0
            typedef Pin<PortD, PORTD0> PortD0;
#       endif
#       ifdef PORTD1
            typedef Pin<PortD, PORTD1> PortD1;
#       endif
#       ifdef PORTD2
            typedef Pin<PortD, PORTD2> PortD2;
#       endif
#       ifdef PORTD3
            typedef Pin<PortD, PORTD3> PortD3;
#       endif
#       ifdef PORTD4
            typedef Pin<PortD, PORTD4> PortD4;
#       endif
#       ifdef PORTD5
            typedef Pin<PortD, PORTD5> PortD5;
#       endif
#       ifdef PORTD6
            typedef Pin<PortD, PORTD6> PortD6;
#       endif
#       ifdef PORTD7
            typedef Pin<PortD, PORTD7> PortD7;
#       endif
#   endif

    /*  port E  */
#   if defined(PORTE) && defined(DDRE) && defined(PINE)
        typedef Port<internal::PortEReg, internal::DdrEReg, internal::PinEReg> PortE;

#       ifdef PORTE0
            typedef Pin<PortE, PORTE0> PortE0;
#       endif
#       ifdef PORTE1
            typedef Pin<PortE, PORTE1> PortE1;
#       endif
#       ifdef PORTE2
            typedef Pin<PortE, PORTE2> PortE2;
#       endif
#       ifdef PORTE3
            typedef Pin<PortE, PORTE3> PortE3;
#       endif
#       ifdef PORTE4
            typedef Pin<PortE, PORTE4> PortE4;
#       endif
#       ifdef PORTE5
            typedef Pin<PortE, PORTE5> PortE5;
#       endif
#       ifdef PORTE6
            typedef Pin<PortE, PORTE6> PortE6;
#       endif
#       ifdef PORTE7
            typedef Pin<PortE, PORTE7> PortE7;
#       endif
#   endif

    /*  port F  */
#   if defined(PORTF) && defined(DDRF) && defined(PINF)
        typedef Port<internal::PortFReg, internal::DdrFReg, internal::PinFReg> PortF;

#       ifdef PORTF0
            typedef Pin<PortF, PORTF0> PortF0;
#       endif
#       ifdef PORTF1
            typedef Pin<PortF, PORTF1> PortF1;
#       endif
#       ifdef PORTF2
            typedef Pin<PortF, PORTF2> PortF2;
#       endif
#       ifdef PORTF3
            typedef Pin<PortF, PORTF3> PortF3;
#       endif
#       ifdef PORTF4
            typedef Pin<PortF, PORTF4> PortF4;
#       endif
#       ifdef PORTF5
            typedef Pin<PortF, PORTF5> PortF5;
#       endif
#       ifdef PORTF6
            typedef Pin<PortF, PORTF6> PortF6;
#       endif
#       ifdef PORTF7
            typedef Pin<PortF, PORTF7> PortF7;
#       endif
#   endif

    /*  port G  */
#   if defined(PORTG) && defined(DDRG) && defined(PING)
        typedef Port<internal::PortGReg, internal::DdrGReg, internal::PinGReg> PortG;

#       ifdef PORTG0
            typedef Pin<PortG, PORTG0> PortG0;
#       endif
#       ifdef PORTG1
            typedef Pin<PortG, PORTG1> PortG1;
#       endif
#       ifdef PORTG2
            typedef Pin<PortG, PORTG2> PortG2;
#       endif
#       ifdef PORTG3
            typedef Pin<PortG, PORTG3> PortG3;
#       endif
#       ifdef PORTG4
            typedef Pin<PortG, PORTG4> PortG4;
#       endif
#       ifdef PORTG5
            typedef Pin<PortG, PORTG5> PortG5;
#       endif
#       ifdef PORTG6
            typedef Pin<PortG, PORTG6> PortG6;
#       endif
#       ifdef PORTG7
            typedef Pin<PortG, PORTG7> PortG7;
#       endif
#   endif

    /*  port H  */
#   if defined(PORTH) && defined(DDRH) && defined(PINH)
        typedef Port<internal::PortHReg, internal::DdrHReg, internal::PinHReg> PortH;

#       ifdef PORTH0
            typedef Pin<PortH, PORTH0> PortH0;
#       endif
#       ifdef PORTH1
            typedef Pin<PortH, PORTH1> PortH1;
#       endif
#       ifdef PORTH2
            typedef Pin<PortH, PORTH2> PortH2;
#       endif
#       ifdef PORTH3
            typedef Pin<PortH, PORTH3> PortH3;
#       endif
#       ifdef PORTH4
            typedef Pin<PortH, PORTH4> PortH4;
#       endif
#       ifdef PORTH5
            typedef Pin<PortH, PORTH5> PortH5;
#       endif
#       ifdef PORTH6
            typedef Pin<PortH, PORTH6> PortH6;
#       endif
#       ifdef PORTH7
            typedef Pin<PortH, PORTH7> PortH7;
#       endif
#   endif

    /*  port I  */
#   if defined(PORTI) && defined(DDRI) && defined(PINI)
        typedef Port<internal::PortIReg, internal::DdrIReg, internal::PinIReg> PortI;

#       ifdef PORTI0
            typedef Pin<PortI, PORTI0> PortI0;
#       endif
#       ifdef PORTI1
            typedef Pin<PortI, PORTI1> PortI1;
#       endif
#       ifdef PORTI2
            typedef Pin<PortI, PORTI2> PortI2;
#       endif
#       ifdef PORTI3
            typedef Pin<PortI, PORTI3> PortI3;
#       endif
#       ifdef PORTI4
            typedef Pin<PortI, PORTI4> PortI4;
#       endif
#       ifdef PORTI5
            typedef Pin<PortI, PORTI5> PortI5;
#       endif
#       ifdef PORTI6
            typedef Pin<PortI, PORTI6> PortI6;
#       endif
#       ifdef PORTI7
            typedef Pin<PortI, PORTI7> PortI7;
#       endif
#   endif

    /*  port J  */
#   if defined(PORTJ) && defined(DDRJ) && defined(PINJ)
        typedef Port<internal::PortJReg, internal::DdrJReg, internal::PinJReg> PortJ;

#       ifdef PORTJ0
            typedef Pin<PortJ, PORTJ0> PortJ0;
#       endif
#       ifdef PORTJ1
            typedef Pin<PortJ, PORTJ1> PortJ1;
#       endif
#       ifdef PORTJ2
            typedef Pin<PortJ, PORTJ2> PortJ2;
#       endif
#       ifdef PORTJ3
            typedef Pin<PortJ, PORTJ3> PortJ3;
#       endif
#       ifdef PORTJ4
            typedef Pin<PortJ, PORTJ4> PortJ4;
#       endif
#       ifdef PORTJ5
            typedef Pin<PortJ, PORTJ5> PortJ5;
#       endif
#       ifdef PORTJ6
            typedef Pin<PortJ, PORTJ6> PortJ6;
#       endif
#       ifdef PORTJ7
            typedef Pin<PortJ, PORTJ7> PortJ7;
#       endif
#   endif

    /*  port K  */
#   if defined(PORTK) && defined(DDRK) && defined(PINK)
        typedef Port<internal::PortKReg, internal::DdrKReg, internal::PinKReg> PortK;

#       ifdef PORTK0
            typedef Pin<PortK, PORTK0> PortK0;
#       endif
#       ifdef PORTK1
            typedef Pin<PortK, PORTK1> PortK1;
#       endif
#       ifdef PORTK2
            typedef Pin<PortK, PORTK2> PortK2;
#       endif
#       ifdef PORTK3
            typedef Pin<PortK, PORTK3> PortK3;
#       endif
#       ifdef PORTK4
            typedef Pin<PortK, PORTK4> PortK4;
#       endif
#       ifdef PORTK5
            typedef Pin<PortK, PORTK5> PortK5;
#       endif
#       ifdef PORTK6
            typedef Pin<PortK, PORTK6> PortK6;
#       endif
#       ifdef PORTK7
            typedef Pin<PortK, PORTK7> PortK7;
#       endif
#   endif
}

#endif
#endif
