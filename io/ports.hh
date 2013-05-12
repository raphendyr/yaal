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
        typedef Port<internal::PortAReg, internal::DdrAReg, internal::PinAReg, (0
#       ifdef PORTA0
          | _BV(PORTA0)
#       endif
#       ifdef PORTA1
          | _BV(PORTA1)
#       endif
#       ifdef PORTA2
          | _BV(PORTA2)
#       endif
#       ifdef PORTA3
          | _BV(PORTA3)
#       endif
#       ifdef PORTA4
          | _BV(PORTA4)
#       endif
#       ifdef PORTA5
          | _BV(PORTA5)
#       endif
#       ifdef PORTA6
          | _BV(PORTA6)
#       endif
#       ifdef PORTA7
          | _BV(PORTA7)
#       endif
        )> PortA;

#       ifdef PORTA0
            typedef Pin<PortA, PORTA0> PortA0;
#           undef PORTA0
#       endif
#       ifdef PORTA1
            typedef Pin<PortA, PORTA1> PortA1;
#           undef PORTA1
#       endif
#       ifdef PORTA2
            typedef Pin<PortA, PORTA2> PortA2;
#           undef PORTA2
#       endif
#       ifdef PORTA3
            typedef Pin<PortA, PORTA3> PortA3;
#           undef PORTA3
#       endif
#       ifdef PORTA4
            typedef Pin<PortA, PORTA4> PortA4;
#           undef PORTA4
#       endif
#       ifdef PORTA5
            typedef Pin<PortA, PORTA5> PortA5;
#           undef PORTA5
#       endif
#       ifdef PORTA6
            typedef Pin<PortA, PORTA6> PortA6;
#           undef PORTA6
#       endif
#       ifdef PORTA7
            typedef Pin<PortA, PORTA7> PortA7;
#           undef PORTA7
#       endif
#       undef PORTA
#       undef DDRA
#       undef PINA
#   endif

    /*  port B  */
#   if defined(PORTB) && defined(DDRB) && defined(PINB)
        typedef Port<internal::PortBReg, internal::DdrBReg, internal::PinBReg, (0
#       ifdef PORTB0
          | _BV(PORTB0)
#       endif
#       ifdef PORTB1
          | _BV(PORTB1)
#       endif
#       ifdef PORTB2
          | _BV(PORTB2)
#       endif
#       ifdef PORTB3
          | _BV(PORTB3)
#       endif
#       ifdef PORTB4
          | _BV(PORTB4)
#       endif
#       ifdef PORTB5
          | _BV(PORTB5)
#       endif
#       ifdef PORTB6
          | _BV(PORTB6)
#       endif
#       ifdef PORTB7
          | _BV(PORTB7)
#       endif
        )> PortB;

#       ifdef PORTB0
            typedef Pin<PortB, PORTB0> PortB0;
#           undef PORTB0
#       endif
#       ifdef PORTB1
            typedef Pin<PortB, PORTB1> PortB1;
#           undef PORTB1
#       endif
#       ifdef PORTB2
            typedef Pin<PortB, PORTB2> PortB2;
#           undef PORTB2
#       endif
#       ifdef PORTB3
            typedef Pin<PortB, PORTB3> PortB3;
#           undef PORTB3
#       endif
#       ifdef PORTB4
            typedef Pin<PortB, PORTB4> PortB4;
#           undef PORTB4
#       endif
#       ifdef PORTB5
            typedef Pin<PortB, PORTB5> PortB5;
#           undef PORTB5
#       endif
#       ifdef PORTB6
            typedef Pin<PortB, PORTB6> PortB6;
#           undef PORTB6
#       endif
#       ifdef PORTB7
            typedef Pin<PortB, PORTB7> PortB7;
#           undef PORTB7
#       endif
#       undef PORTB
#       undef DDRB
#       undef PINB
#   endif

    /*  port C  */
#   if defined(PORTC) && defined(DDRC) && defined(PINC)
        typedef Port<internal::PortCReg, internal::DdrCReg, internal::PinCReg, (0
#       ifdef PORTC0
          | _BV(PORTC0)
#       endif
#       ifdef PORTC1
          | _BV(PORTC1)
#       endif
#       ifdef PORTC2
          | _BV(PORTC2)
#       endif
#       ifdef PORTC3
          | _BV(PORTC3)
#       endif
#       ifdef PORTC4
          | _BV(PORTC4)
#       endif
#       ifdef PORTC5
          | _BV(PORTC5)
#       endif
#       ifdef PORTC6
          | _BV(PORTC6)
#       endif
#       ifdef PORTC7
          | _BV(PORTC7)
#       endif
        )> PortC;

#       ifdef PORTC0
            typedef Pin<PortC, PORTC0> PortC0;
#           undef PORTC0
#       endif
#       ifdef PORTC1
            typedef Pin<PortC, PORTC1> PortC1;
#           undef PORTC1
#       endif
#       ifdef PORTC2
            typedef Pin<PortC, PORTC2> PortC2;
#           undef PORTC2
#       endif
#       ifdef PORTC3
            typedef Pin<PortC, PORTC3> PortC3;
#           undef PORTC3
#       endif
#       ifdef PORTC4
            typedef Pin<PortC, PORTC4> PortC4;
#           undef PORTC4
#       endif
#       ifdef PORTC5
            typedef Pin<PortC, PORTC5> PortC5;
#           undef PORTC5
#       endif
#       ifdef PORTC6
            typedef Pin<PortC, PORTC6> PortC6;
#           undef PORTC6
#       endif
#       ifdef PORTC7
            typedef Pin<PortC, PORTC7> PortC7;
#           undef PORTC7
#       endif
#       undef PORTC
#       undef DDRC
#       undef PINC
#   endif

    /*  port D  */
#   if defined(PORTD) && defined(DDRD) && defined(PIND)
        typedef Port<internal::PortDReg, internal::DdrDReg, internal::PinDReg, (0
#       ifdef PORTD0
          | _BV(PORTD0)
#       endif
#       ifdef PORTD1
          | _BV(PORTD1)
#       endif
#       ifdef PORTD2
          | _BV(PORTD2)
#       endif
#       ifdef PORTD3
          | _BV(PORTD3)
#       endif
#       ifdef PORTD4
          | _BV(PORTD4)
#       endif
#       ifdef PORTD5
          | _BV(PORTD5)
#       endif
#       ifdef PORTD6
          | _BV(PORTD6)
#       endif
#       ifdef PORTD7
          | _BV(PORTD7)
#       endif
        )> PortD;

#       ifdef PORTD0
            typedef Pin<PortD, PORTD0> PortD0;
#           undef PORTD0
#       endif
#       ifdef PORTD1
            typedef Pin<PortD, PORTD1> PortD1;
#           undef PORTD1
#       endif
#       ifdef PORTD2
            typedef Pin<PortD, PORTD2> PortD2;
#           undef PORTD2
#       endif
#       ifdef PORTD3
            typedef Pin<PortD, PORTD3> PortD3;
#           undef PORTD3
#       endif
#       ifdef PORTD4
            typedef Pin<PortD, PORTD4> PortD4;
#           undef PORTD4
#       endif
#       ifdef PORTD5
            typedef Pin<PortD, PORTD5> PortD5;
#           undef PORTD5
#       endif
#       ifdef PORTD6
            typedef Pin<PortD, PORTD6> PortD6;
#           undef PORTD6
#       endif
#       ifdef PORTD7
            typedef Pin<PortD, PORTD7> PortD7;
#           undef PORTD7
#       endif
#       undef PORTD
#       undef DDRD
#       undef PIND
#   endif

    /*  port E  */
#   if defined(PORTE) && defined(DDRE) && defined(PINE)
        typedef Port<internal::PortEReg, internal::DdrEReg, internal::PinEReg, (0
#       ifdef PORTE0
          | _BV(PORTE0)
#       endif
#       ifdef PORTE1
          | _BV(PORTE1)
#       endif
#       ifdef PORTE2
          | _BV(PORTE2)
#       endif
#       ifdef PORTE3
          | _BV(PORTE3)
#       endif
#       ifdef PORTE4
          | _BV(PORTE4)
#       endif
#       ifdef PORTE5
          | _BV(PORTE5)
#       endif
#       ifdef PORTE6
          | _BV(PORTE6)
#       endif
#       ifdef PORTE7
          | _BV(PORTE7)
#       endif
        )> PortE;

#       ifdef PORTE0
            typedef Pin<PortE, PORTE0> PortE0;
#           undef PORTE0
#       endif
#       ifdef PORTE1
            typedef Pin<PortE, PORTE1> PortE1;
#           undef PORTE1
#       endif
#       ifdef PORTE2
            typedef Pin<PortE, PORTE2> PortE2;
#           undef PORTE2
#       endif
#       ifdef PORTE3
            typedef Pin<PortE, PORTE3> PortE3;
#           undef PORTE3
#       endif
#       ifdef PORTE4
            typedef Pin<PortE, PORTE4> PortE4;
#           undef PORTE4
#       endif
#       ifdef PORTE5
            typedef Pin<PortE, PORTE5> PortE5;
#           undef PORTE5
#       endif
#       ifdef PORTE6
            typedef Pin<PortE, PORTE6> PortE6;
#           undef PORTE6
#       endif
#       ifdef PORTE7
            typedef Pin<PortE, PORTE7> PortE7;
#           undef PORTE7
#       endif
#       undef PORTE
#       undef DDRE
#       undef PINE
#   endif

    /*  port F  */
#   if defined(PORTF) && defined(DDRF) && defined(PINF)
        typedef Port<internal::PortFReg, internal::DdrFReg, internal::PinFReg, (0
#       ifdef PORTF0
          | _BV(PORTF0)
#       endif
#       ifdef PORTF1
          | _BV(PORTF1)
#       endif
#       ifdef PORTF2
          | _BV(PORTF2)
#       endif
#       ifdef PORTF3
          | _BV(PORTF3)
#       endif
#       ifdef PORTF4
          | _BV(PORTF4)
#       endif
#       ifdef PORTF5
          | _BV(PORTF5)
#       endif
#       ifdef PORTF6
          | _BV(PORTF6)
#       endif
#       ifdef PORTF7
          | _BV(PORTF7)
#       endif
        )> PortF;

#       ifdef PORTF0
            typedef Pin<PortF, PORTF0> PortF0;
#           undef PORTF0
#       endif
#       ifdef PORTF1
            typedef Pin<PortF, PORTF1> PortF1;
#           undef PORTF1
#       endif
#       ifdef PORTF2
            typedef Pin<PortF, PORTF2> PortF2;
#           undef PORTF2
#       endif
#       ifdef PORTF3
            typedef Pin<PortF, PORTF3> PortF3;
#           undef PORTF3
#       endif
#       ifdef PORTF4
            typedef Pin<PortF, PORTF4> PortF4;
#           undef PORTF4
#       endif
#       ifdef PORTF5
            typedef Pin<PortF, PORTF5> PortF5;
#           undef PORTF5
#       endif
#       ifdef PORTF6
            typedef Pin<PortF, PORTF6> PortF6;
#           undef PORTF6
#       endif
#       ifdef PORTF7
            typedef Pin<PortF, PORTF7> PortF7;
#           undef PORTF7
#       endif
#       undef PORTF
#       undef DDRF
#       undef PINF
#   endif

    /*  port G  */
#   if defined(PORTG) && defined(DDRG) && defined(PING)
        typedef Port<internal::PortGReg, internal::DdrGReg, internal::PinGReg, (0
#       ifdef PORTG0
          | _BV(PORTG0)
#       endif
#       ifdef PORTG1
          | _BV(PORTG1)
#       endif
#       ifdef PORTG2
          | _BV(PORTG2)
#       endif
#       ifdef PORTG3
          | _BV(PORTG3)
#       endif
#       ifdef PORTG4
          | _BV(PORTG4)
#       endif
#       ifdef PORTG5
          | _BV(PORTG5)
#       endif
#       ifdef PORTG6
          | _BV(PORTG6)
#       endif
#       ifdef PORTG7
          | _BV(PORTG7)
#       endif
        )> PortG;

#       ifdef PORTG0
            typedef Pin<PortG, PORTG0> PortG0;
#           undef PORTG0
#       endif
#       ifdef PORTG1
            typedef Pin<PortG, PORTG1> PortG1;
#           undef PORTG1
#       endif
#       ifdef PORTG2
            typedef Pin<PortG, PORTG2> PortG2;
#           undef PORTG2
#       endif
#       ifdef PORTG3
            typedef Pin<PortG, PORTG3> PortG3;
#           undef PORTG3
#       endif
#       ifdef PORTG4
            typedef Pin<PortG, PORTG4> PortG4;
#           undef PORTG4
#       endif
#       ifdef PORTG5
            typedef Pin<PortG, PORTG5> PortG5;
#           undef PORTG5
#       endif
#       ifdef PORTG6
            typedef Pin<PortG, PORTG6> PortG6;
#           undef PORTG6
#       endif
#       ifdef PORTG7
            typedef Pin<PortG, PORTG7> PortG7;
#           undef PORTG7
#       endif
#       undef PORTG
#       undef DDRG
#       undef PING
#   endif

    /*  port H  */
#   if defined(PORTH) && defined(DDRH) && defined(PINH)
        typedef Port<internal::PortHReg, internal::DdrHReg, internal::PinHReg, (0
#       ifdef PORTH0
          | _BV(PORTH0)
#       endif
#       ifdef PORTH1
          | _BV(PORTH1)
#       endif
#       ifdef PORTH2
          | _BV(PORTH2)
#       endif
#       ifdef PORTH3
          | _BV(PORTH3)
#       endif
#       ifdef PORTH4
          | _BV(PORTH4)
#       endif
#       ifdef PORTH5
          | _BV(PORTH5)
#       endif
#       ifdef PORTH6
          | _BV(PORTH6)
#       endif
#       ifdef PORTH7
          | _BV(PORTH7)
#       endif
        )> PortH;

#       ifdef PORTH0
            typedef Pin<PortH, PORTH0> PortH0;
#           undef PORTH0
#       endif
#       ifdef PORTH1
            typedef Pin<PortH, PORTH1> PortH1;
#           undef PORTH1
#       endif
#       ifdef PORTH2
            typedef Pin<PortH, PORTH2> PortH2;
#           undef PORTH2
#       endif
#       ifdef PORTH3
            typedef Pin<PortH, PORTH3> PortH3;
#           undef PORTH3
#       endif
#       ifdef PORTH4
            typedef Pin<PortH, PORTH4> PortH4;
#           undef PORTH4
#       endif
#       ifdef PORTH5
            typedef Pin<PortH, PORTH5> PortH5;
#           undef PORTH5
#       endif
#       ifdef PORTH6
            typedef Pin<PortH, PORTH6> PortH6;
#           undef PORTH6
#       endif
#       ifdef PORTH7
            typedef Pin<PortH, PORTH7> PortH7;
#           undef PORTH7
#       endif
#       undef PORTH
#       undef DDRH
#       undef PINH
#   endif

    /*  port I  */
#   if defined(PORTI) && defined(DDRI) && defined(PINI)
        typedef Port<internal::PortIReg, internal::DdrIReg, internal::PinIReg, (0
#       ifdef PORTI0
          | _BV(PORTI0)
#       endif
#       ifdef PORTI1
          | _BV(PORTI1)
#       endif
#       ifdef PORTI2
          | _BV(PORTI2)
#       endif
#       ifdef PORTI3
          | _BV(PORTI3)
#       endif
#       ifdef PORTI4
          | _BV(PORTI4)
#       endif
#       ifdef PORTI5
          | _BV(PORTI5)
#       endif
#       ifdef PORTI6
          | _BV(PORTI6)
#       endif
#       ifdef PORTI7
          | _BV(PORTI7)
#       endif
        )> PortI;

#       ifdef PORTI0
            typedef Pin<PortI, PORTI0> PortI0;
#           undef PORTI0
#       endif
#       ifdef PORTI1
            typedef Pin<PortI, PORTI1> PortI1;
#           undef PORTI1
#       endif
#       ifdef PORTI2
            typedef Pin<PortI, PORTI2> PortI2;
#           undef PORTI2
#       endif
#       ifdef PORTI3
            typedef Pin<PortI, PORTI3> PortI3;
#           undef PORTI3
#       endif
#       ifdef PORTI4
            typedef Pin<PortI, PORTI4> PortI4;
#           undef PORTI4
#       endif
#       ifdef PORTI5
            typedef Pin<PortI, PORTI5> PortI5;
#           undef PORTI5
#       endif
#       ifdef PORTI6
            typedef Pin<PortI, PORTI6> PortI6;
#           undef PORTI6
#       endif
#       ifdef PORTI7
            typedef Pin<PortI, PORTI7> PortI7;
#           undef PORTI7
#       endif
#       undef PORTI
#       undef DDRI
#       undef PINI
#   endif

    /*  port J  */
#   if defined(PORTJ) && defined(DDRJ) && defined(PINJ)
        typedef Port<internal::PortJReg, internal::DdrJReg, internal::PinJReg, (0
#       ifdef PORTJ0
          | _BV(PORTJ0)
#       endif
#       ifdef PORTJ1
          | _BV(PORTJ1)
#       endif
#       ifdef PORTJ2
          | _BV(PORTJ2)
#       endif
#       ifdef PORTJ3
          | _BV(PORTJ3)
#       endif
#       ifdef PORTJ4
          | _BV(PORTJ4)
#       endif
#       ifdef PORTJ5
          | _BV(PORTJ5)
#       endif
#       ifdef PORTJ6
          | _BV(PORTJ6)
#       endif
#       ifdef PORTJ7
          | _BV(PORTJ7)
#       endif
        )> PortJ;

#       ifdef PORTJ0
            typedef Pin<PortJ, PORTJ0> PortJ0;
#           undef PORTJ0
#       endif
#       ifdef PORTJ1
            typedef Pin<PortJ, PORTJ1> PortJ1;
#           undef PORTJ1
#       endif
#       ifdef PORTJ2
            typedef Pin<PortJ, PORTJ2> PortJ2;
#           undef PORTJ2
#       endif
#       ifdef PORTJ3
            typedef Pin<PortJ, PORTJ3> PortJ3;
#           undef PORTJ3
#       endif
#       ifdef PORTJ4
            typedef Pin<PortJ, PORTJ4> PortJ4;
#           undef PORTJ4
#       endif
#       ifdef PORTJ5
            typedef Pin<PortJ, PORTJ5> PortJ5;
#           undef PORTJ5
#       endif
#       ifdef PORTJ6
            typedef Pin<PortJ, PORTJ6> PortJ6;
#           undef PORTJ6
#       endif
#       ifdef PORTJ7
            typedef Pin<PortJ, PORTJ7> PortJ7;
#           undef PORTJ7
#       endif
#       undef PORTJ
#       undef DDRJ
#       undef PINJ
#   endif

    /*  port K  */
#   if defined(PORTK) && defined(DDRK) && defined(PINK)
        typedef Port<internal::PortKReg, internal::DdrKReg, internal::PinKReg, (0
#       ifdef PORTK0
          | _BV(PORTK0)
#       endif
#       ifdef PORTK1
          | _BV(PORTK1)
#       endif
#       ifdef PORTK2
          | _BV(PORTK2)
#       endif
#       ifdef PORTK3
          | _BV(PORTK3)
#       endif
#       ifdef PORTK4
          | _BV(PORTK4)
#       endif
#       ifdef PORTK5
          | _BV(PORTK5)
#       endif
#       ifdef PORTK6
          | _BV(PORTK6)
#       endif
#       ifdef PORTK7
          | _BV(PORTK7)
#       endif
        )> PortK;

#       ifdef PORTK0
            typedef Pin<PortK, PORTK0> PortK0;
#           undef PORTK0
#       endif
#       ifdef PORTK1
            typedef Pin<PortK, PORTK1> PortK1;
#           undef PORTK1
#       endif
#       ifdef PORTK2
            typedef Pin<PortK, PORTK2> PortK2;
#           undef PORTK2
#       endif
#       ifdef PORTK3
            typedef Pin<PortK, PORTK3> PortK3;
#           undef PORTK3
#       endif
#       ifdef PORTK4
            typedef Pin<PortK, PORTK4> PortK4;
#           undef PORTK4
#       endif
#       ifdef PORTK5
            typedef Pin<PortK, PORTK5> PortK5;
#           undef PORTK5
#       endif
#       ifdef PORTK6
            typedef Pin<PortK, PORTK6> PortK6;
#           undef PORTK6
#       endif
#       ifdef PORTK7
            typedef Pin<PortK, PORTK7> PortK7;
#           undef PORTK7
#       endif
#       undef PORTK
#       undef DDRK
#       undef PINK
#   endif

    /*  port L  */
#   if defined(PORTL) && defined(DDRL) && defined(PINL)
        typedef Port<internal::PortLReg, internal::DdrLReg, internal::PinLReg, (0
#       ifdef PORTL0
          | _BV(PORTL0)
#       endif
#       ifdef PORTL1
          | _BV(PORTL1)
#       endif
#       ifdef PORTL2
          | _BV(PORTL2)
#       endif
#       ifdef PORTL3
          | _BV(PORTL3)
#       endif
#       ifdef PORTL4
          | _BV(PORTL4)
#       endif
#       ifdef PORTL5
          | _BV(PORTL5)
#       endif
#       ifdef PORTL6
          | _BV(PORTL6)
#       endif
#       ifdef PORTL7
          | _BV(PORTL7)
#       endif
        )> PortL;

#       ifdef PORTL0
            typedef Pin<PortL, PORTL0> PortL0;
#           undef PORTL0
#       endif
#       ifdef PORTL1
            typedef Pin<PortL, PORTL1> PortL1;
#           undef PORTL1
#       endif
#       ifdef PORTL2
            typedef Pin<PortL, PORTL2> PortL2;
#           undef PORTL2
#       endif
#       ifdef PORTL3
            typedef Pin<PortL, PORTL3> PortL3;
#           undef PORTL3
#       endif
#       ifdef PORTL4
            typedef Pin<PortL, PORTL4> PortL4;
#           undef PORTL4
#       endif
#       ifdef PORTL5
            typedef Pin<PortL, PORTL5> PortL5;
#           undef PORTL5
#       endif
#       ifdef PORTL6
            typedef Pin<PortL, PORTL6> PortL6;
#           undef PORTL6
#       endif
#       ifdef PORTL7
            typedef Pin<PortL, PORTL7> PortL7;
#           undef PORTL7
#       endif
#       undef PORTL
#       undef DDRL
#       undef PINL
#   endif

    /*  port M  */
#   if defined(PORTM) && defined(DDRM) && defined(PINM)
        typedef Port<internal::PortMReg, internal::DdrMReg, internal::PinMReg, (0
#       ifdef PORTM0
          | _BV(PORTM0)
#       endif
#       ifdef PORTM1
          | _BV(PORTM1)
#       endif
#       ifdef PORTM2
          | _BV(PORTM2)
#       endif
#       ifdef PORTM3
          | _BV(PORTM3)
#       endif
#       ifdef PORTM4
          | _BV(PORTM4)
#       endif
#       ifdef PORTM5
          | _BV(PORTM5)
#       endif
#       ifdef PORTM6
          | _BV(PORTM6)
#       endif
#       ifdef PORTM7
          | _BV(PORTM7)
#       endif
        )> PortM;

#       ifdef PORTM0
            typedef Pin<PortM, PORTM0> PortM0;
#           undef PORTM0
#       endif
#       ifdef PORTM1
            typedef Pin<PortM, PORTM1> PortM1;
#           undef PORTM1
#       endif
#       ifdef PORTM2
            typedef Pin<PortM, PORTM2> PortM2;
#           undef PORTM2
#       endif
#       ifdef PORTM3
            typedef Pin<PortM, PORTM3> PortM3;
#           undef PORTM3
#       endif
#       ifdef PORTM4
            typedef Pin<PortM, PORTM4> PortM4;
#           undef PORTM4
#       endif
#       ifdef PORTM5
            typedef Pin<PortM, PORTM5> PortM5;
#           undef PORTM5
#       endif
#       ifdef PORTM6
            typedef Pin<PortM, PORTM6> PortM6;
#           undef PORTM6
#       endif
#       ifdef PORTM7
            typedef Pin<PortM, PORTM7> PortM7;
#           undef PORTM7
#       endif
#       undef PORTM
#       undef DDRM
#       undef PINM
#   endif

    /*  port N  */
#   if defined(PORTN) && defined(DDRN) && defined(PINN)
        typedef Port<internal::PortNReg, internal::DdrNReg, internal::PinNReg, (0
#       ifdef PORTN0
          | _BV(PORTN0)
#       endif
#       ifdef PORTN1
          | _BV(PORTN1)
#       endif
#       ifdef PORTN2
          | _BV(PORTN2)
#       endif
#       ifdef PORTN3
          | _BV(PORTN3)
#       endif
#       ifdef PORTN4
          | _BV(PORTN4)
#       endif
#       ifdef PORTN5
          | _BV(PORTN5)
#       endif
#       ifdef PORTN6
          | _BV(PORTN6)
#       endif
#       ifdef PORTN7
          | _BV(PORTN7)
#       endif
        )> PortN;

#       ifdef PORTN0
            typedef Pin<PortN, PORTN0> PortN0;
#           undef PORTN0
#       endif
#       ifdef PORTN1
            typedef Pin<PortN, PORTN1> PortN1;
#           undef PORTN1
#       endif
#       ifdef PORTN2
            typedef Pin<PortN, PORTN2> PortN2;
#           undef PORTN2
#       endif
#       ifdef PORTN3
            typedef Pin<PortN, PORTN3> PortN3;
#           undef PORTN3
#       endif
#       ifdef PORTN4
            typedef Pin<PortN, PORTN4> PortN4;
#           undef PORTN4
#       endif
#       ifdef PORTN5
            typedef Pin<PortN, PORTN5> PortN5;
#           undef PORTN5
#       endif
#       ifdef PORTN6
            typedef Pin<PortN, PORTN6> PortN6;
#           undef PORTN6
#       endif
#       ifdef PORTN7
            typedef Pin<PortN, PORTN7> PortN7;
#           undef PORTN7
#       endif
#       undef PORTN
#       undef DDRN
#       undef PINN
#   endif
}

#endif
#endif
