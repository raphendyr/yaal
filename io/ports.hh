#ifndef __YAAL_IO__PORTS__
#define __YAAL_IO__PORTS__ 1
/* Generated using ports.sh */

#include "../requirements.hh"
#include <avr/io.h>

namespace yaal {

    namespace registers {
#       ifdef PORTA
            typdef Register<PORTA> PortA;
#       endif
#       ifdef DDRA
            typdef Register<DDRA> DdrA;
#       endif
#       ifdef PINA
            typdef ReadonlyRegister<PINA> PinA;
#       endif
#       ifdef PORTB
            typdef Register<PORTB> PortB;
#       endif
#       ifdef DDRB
            typdef Register<DDRB> DdrB;
#       endif
#       ifdef PINB
            typdef ReadonlyRegister<PINB> PinB;
#       endif
#       ifdef PORTC
            typdef Register<PORTC> PortC;
#       endif
#       ifdef DDRC
            typdef Register<DDRC> DdrC;
#       endif
#       ifdef PINC
            typdef ReadonlyRegister<PINC> PinC;
#       endif
#       ifdef PORTD
            typdef Register<PORTD> PortD;
#       endif
#       ifdef DDRD
            typdef Register<DDRD> DdrD;
#       endif
#       ifdef PIND
            typdef ReadonlyRegister<PIND> PinD;
#       endif
#       ifdef PORTE
            typdef Register<PORTE> PortE;
#       endif
#       ifdef DDRE
            typdef Register<DDRE> DdrE;
#       endif
#       ifdef PINE
            typdef ReadonlyRegister<PINE> PinE;
#       endif
#       ifdef PORTF
            typdef Register<PORTF> PortF;
#       endif
#       ifdef DDRF
            typdef Register<DDRF> DdrF;
#       endif
#       ifdef PINF
            typdef ReadonlyRegister<PINF> PinF;
#       endif
#       ifdef PORTG
            typdef Register<PORTG> PortG;
#       endif
#       ifdef DDRG
            typdef Register<DDRG> DdrG;
#       endif
#       ifdef PING
            typdef ReadonlyRegister<PING> PinG;
#       endif
    }
#   if defined(PORTA) && defined(DDRA) && defined(PINA)
        typedef Port<registers::PortA, registers::DdrA, registers::PinA> PortA;
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
        typedef Port<registers::PortB, registers::DdrB, registers::PinB> PortB;
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
        typedef Port<registers::PortC, registers::DdrC, registers::PinC> PortC;
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
        typedef Port<registers::PortD, registers::DdrD, registers::PinD> PortD;
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
        typedef Port<registers::PortE, registers::DdrE, registers::PinE> PortE;
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
        typedef Port<registers::PortF, registers::DdrF, registers::PinF> PortF;
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
        typedef Port<registers::PortG, registers::DdrG, registers::PinG> PortG;
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

#   if defined(PORTH) && defined(DDRH) && defined(PINH)
        typedef Port<registers::PortH, registers::DdrH, registers::PinH> PortH;
#       ifdef PORTH0
            typedef Pin<PortH, 0> PortH0;
#       endif
#       ifdef PORTH1
            typedef Pin<PortH, 1> PortH1;
#       endif
#       ifdef PORTH2
            typedef Pin<PortH, 2> PortH2;
#       endif
#       ifdef PORTH3
            typedef Pin<PortH, 3> PortH3;
#       endif
#       ifdef PORTH4
            typedef Pin<PortH, 4> PortH4;
#       endif
#       ifdef PORTH5
            typedef Pin<PortH, 5> PortH5;
#       endif
#       ifdef PORTH6
            typedef Pin<PortH, 6> PortH6;
#       endif
#       ifdef PORTH7
            typedef Pin<PortH, 7> PortH7;
#       endif
#   endif

#   if defined(PORTI) && defined(DDRI) && defined(PINI)
        typedef Port<registers::PortI, registers::DdrI, registers::PinI> PortI;
#       ifdef PORTI0
            typedef Pin<PortI, 0> PortI0;
#       endif
#       ifdef PORTI1
            typedef Pin<PortI, 1> PortI1;
#       endif
#       ifdef PORTI2
            typedef Pin<PortI, 2> PortI2;
#       endif
#       ifdef PORTI3
            typedef Pin<PortI, 3> PortI3;
#       endif
#       ifdef PORTI4
            typedef Pin<PortI, 4> PortI4;
#       endif
#       ifdef PORTI5
            typedef Pin<PortI, 5> PortI5;
#       endif
#       ifdef PORTI6
            typedef Pin<PortI, 6> PortI6;
#       endif
#       ifdef PORTI7
            typedef Pin<PortI, 7> PortI7;
#       endif
#   endif

#   if defined(PORTJ) && defined(DDRJ) && defined(PINJ)
        typedef Port<registers::PortJ, registers::DdrJ, registers::PinJ> PortJ;
#       ifdef PORTJ0
            typedef Pin<PortJ, 0> PortJ0;
#       endif
#       ifdef PORTJ1
            typedef Pin<PortJ, 1> PortJ1;
#       endif
#       ifdef PORTJ2
            typedef Pin<PortJ, 2> PortJ2;
#       endif
#       ifdef PORTJ3
            typedef Pin<PortJ, 3> PortJ3;
#       endif
#       ifdef PORTJ4
            typedef Pin<PortJ, 4> PortJ4;
#       endif
#       ifdef PORTJ5
            typedef Pin<PortJ, 5> PortJ5;
#       endif
#       ifdef PORTJ6
            typedef Pin<PortJ, 6> PortJ6;
#       endif
#       ifdef PORTJ7
            typedef Pin<PortJ, 7> PortJ7;
#       endif
#   endif

#   if defined(PORTK) && defined(DDRK) && defined(PINK)
        typedef Port<registers::PortK, registers::DdrK, registers::PinK> PortK;
#       ifdef PORTK0
            typedef Pin<PortK, 0> PortK0;
#       endif
#       ifdef PORTK1
            typedef Pin<PortK, 1> PortK1;
#       endif
#       ifdef PORTK2
            typedef Pin<PortK, 2> PortK2;
#       endif
#       ifdef PORTK3
            typedef Pin<PortK, 3> PortK3;
#       endif
#       ifdef PORTK4
            typedef Pin<PortK, 4> PortK4;
#       endif
#       ifdef PORTK5
            typedef Pin<PortK, 5> PortK5;
#       endif
#       ifdef PORTK6
            typedef Pin<PortK, 6> PortK6;
#       endif
#       ifdef PORTK7
            typedef Pin<PortK, 7> PortK7;
#       endif
#   endif

#   if defined(PORTL) && defined(DDRL) && defined(PINL)
        typedef Port<registers::PortL, registers::DdrL, registers::PinL> PortL;
#       ifdef PORTL0
            typedef Pin<PortL, 0> PortL0;
#       endif
#       ifdef PORTL1
            typedef Pin<PortL, 1> PortL1;
#       endif
#       ifdef PORTL2
            typedef Pin<PortL, 2> PortL2;
#       endif
#       ifdef PORTL3
            typedef Pin<PortL, 3> PortL3;
#       endif
#       ifdef PORTL4
            typedef Pin<PortL, 4> PortL4;
#       endif
#       ifdef PORTL5
            typedef Pin<PortL, 5> PortL5;
#       endif
#       ifdef PORTL6
            typedef Pin<PortL, 6> PortL6;
#       endif
#       ifdef PORTL7
            typedef Pin<PortL, 7> PortL7;
#       endif
#   endif

#   if defined(PORTM) && defined(DDRM) && defined(PINM)
        typedef Port<registers::PortM, registers::DdrM, registers::PinM> PortM;
#       ifdef PORTM0
            typedef Pin<PortM, 0> PortM0;
#       endif
#       ifdef PORTM1
            typedef Pin<PortM, 1> PortM1;
#       endif
#       ifdef PORTM2
            typedef Pin<PortM, 2> PortM2;
#       endif
#       ifdef PORTM3
            typedef Pin<PortM, 3> PortM3;
#       endif
#       ifdef PORTM4
            typedef Pin<PortM, 4> PortM4;
#       endif
#       ifdef PORTM5
            typedef Pin<PortM, 5> PortM5;
#       endif
#       ifdef PORTM6
            typedef Pin<PortM, 6> PortM6;
#       endif
#       ifdef PORTM7
            typedef Pin<PortM, 7> PortM7;
#       endif
#   endif

#   if defined(PORTN) && defined(DDRN) && defined(PINN)
        typedef Port<registers::PortN, registers::DdrN, registers::PinN> PortN;
#       ifdef PORTN0
            typedef Pin<PortN, 0> PortN0;
#       endif
#       ifdef PORTN1
            typedef Pin<PortN, 1> PortN1;
#       endif
#       ifdef PORTN2
            typedef Pin<PortN, 2> PortN2;
#       endif
#       ifdef PORTN3
            typedef Pin<PortN, 3> PortN3;
#       endif
#       ifdef PORTN4
            typedef Pin<PortN, 4> PortN4;
#       endif
#       ifdef PORTN5
            typedef Pin<PortN, 5> PortN5;
#       endif
#       ifdef PORTN6
            typedef Pin<PortN, 6> PortN6;
#       endif
#       ifdef PORTN7
            typedef Pin<PortN, 7> PortN7;
#       endif
#   endif

#   if defined(PORTO) && defined(DDRO) && defined(PINO)
        typedef Port<registers::PortO, registers::DdrO, registers::PinO> PortO;
#       ifdef PORTO0
            typedef Pin<PortO, 0> PortO0;
#       endif
#       ifdef PORTO1
            typedef Pin<PortO, 1> PortO1;
#       endif
#       ifdef PORTO2
            typedef Pin<PortO, 2> PortO2;
#       endif
#       ifdef PORTO3
            typedef Pin<PortO, 3> PortO3;
#       endif
#       ifdef PORTO4
            typedef Pin<PortO, 4> PortO4;
#       endif
#       ifdef PORTO5
            typedef Pin<PortO, 5> PortO5;
#       endif
#       ifdef PORTO6
            typedef Pin<PortO, 6> PortO6;
#       endif
#       ifdef PORTO7
            typedef Pin<PortO, 7> PortO7;
#       endif
#   endif

#   if defined(PORTP) && defined(DDRP) && defined(PINP)
        typedef Port<registers::PortP, registers::DdrP, registers::PinP> PortP;
#       ifdef PORTP0
            typedef Pin<PortP, 0> PortP0;
#       endif
#       ifdef PORTP1
            typedef Pin<PortP, 1> PortP1;
#       endif
#       ifdef PORTP2
            typedef Pin<PortP, 2> PortP2;
#       endif
#       ifdef PORTP3
            typedef Pin<PortP, 3> PortP3;
#       endif
#       ifdef PORTP4
            typedef Pin<PortP, 4> PortP4;
#       endif
#       ifdef PORTP5
            typedef Pin<PortP, 5> PortP5;
#       endif
#       ifdef PORTP6
            typedef Pin<PortP, 6> PortP6;
#       endif
#       ifdef PORTP7
            typedef Pin<PortP, 7> PortP7;
#       endif
#   endif

#   if defined(PORTQ) && defined(DDRQ) && defined(PINQ)
        typedef Port<registers::PortQ, registers::DdrQ, registers::PinQ> PortQ;
#       ifdef PORTQ0
            typedef Pin<PortQ, 0> PortQ0;
#       endif
#       ifdef PORTQ1
            typedef Pin<PortQ, 1> PortQ1;
#       endif
#       ifdef PORTQ2
            typedef Pin<PortQ, 2> PortQ2;
#       endif
#       ifdef PORTQ3
            typedef Pin<PortQ, 3> PortQ3;
#       endif
#       ifdef PORTQ4
            typedef Pin<PortQ, 4> PortQ4;
#       endif
#       ifdef PORTQ5
            typedef Pin<PortQ, 5> PortQ5;
#       endif
#       ifdef PORTQ6
            typedef Pin<PortQ, 6> PortQ6;
#       endif
#       ifdef PORTQ7
            typedef Pin<PortQ, 7> PortQ7;
#       endif
#   endif

#   if defined(PORTR) && defined(DDRR) && defined(PINR)
        typedef Port<registers::PortR, registers::DdrR, registers::PinR> PortR;
#       ifdef PORTR0
            typedef Pin<PortR, 0> PortR0;
#       endif
#       ifdef PORTR1
            typedef Pin<PortR, 1> PortR1;
#       endif
#       ifdef PORTR2
            typedef Pin<PortR, 2> PortR2;
#       endif
#       ifdef PORTR3
            typedef Pin<PortR, 3> PortR3;
#       endif
#       ifdef PORTR4
            typedef Pin<PortR, 4> PortR4;
#       endif
#       ifdef PORTR5
            typedef Pin<PortR, 5> PortR5;
#       endif
#       ifdef PORTR6
            typedef Pin<PortR, 6> PortR6;
#       endif
#       ifdef PORTR7
            typedef Pin<PortR, 7> PortR7;
#       endif
#   endif

#   if defined(PORTS) && defined(DDRS) && defined(PINS)
        typedef Port<registers::PortS, registers::DdrS, registers::PinS> PortS;
#       ifdef PORTS0
            typedef Pin<PortS, 0> PortS0;
#       endif
#       ifdef PORTS1
            typedef Pin<PortS, 1> PortS1;
#       endif
#       ifdef PORTS2
            typedef Pin<PortS, 2> PortS2;
#       endif
#       ifdef PORTS3
            typedef Pin<PortS, 3> PortS3;
#       endif
#       ifdef PORTS4
            typedef Pin<PortS, 4> PortS4;
#       endif
#       ifdef PORTS5
            typedef Pin<PortS, 5> PortS5;
#       endif
#       ifdef PORTS6
            typedef Pin<PortS, 6> PortS6;
#       endif
#       ifdef PORTS7
            typedef Pin<PortS, 7> PortS7;
#       endif
#   endif

#   if defined(PORTT) && defined(DDRT) && defined(PINT)
        typedef Port<registers::PortT, registers::DdrT, registers::PinT> PortT;
#       ifdef PORTT0
            typedef Pin<PortT, 0> PortT0;
#       endif
#       ifdef PORTT1
            typedef Pin<PortT, 1> PortT1;
#       endif
#       ifdef PORTT2
            typedef Pin<PortT, 2> PortT2;
#       endif
#       ifdef PORTT3
            typedef Pin<PortT, 3> PortT3;
#       endif
#       ifdef PORTT4
            typedef Pin<PortT, 4> PortT4;
#       endif
#       ifdef PORTT5
            typedef Pin<PortT, 5> PortT5;
#       endif
#       ifdef PORTT6
            typedef Pin<PortT, 6> PortT6;
#       endif
#       ifdef PORTT7
            typedef Pin<PortT, 7> PortT7;
#       endif
#   endif

#   if defined(PORTU) && defined(DDRU) && defined(PINU)
        typedef Port<registers::PortU, registers::DdrU, registers::PinU> PortU;
#       ifdef PORTU0
            typedef Pin<PortU, 0> PortU0;
#       endif
#       ifdef PORTU1
            typedef Pin<PortU, 1> PortU1;
#       endif
#       ifdef PORTU2
            typedef Pin<PortU, 2> PortU2;
#       endif
#       ifdef PORTU3
            typedef Pin<PortU, 3> PortU3;
#       endif
#       ifdef PORTU4
            typedef Pin<PortU, 4> PortU4;
#       endif
#       ifdef PORTU5
            typedef Pin<PortU, 5> PortU5;
#       endif
#       ifdef PORTU6
            typedef Pin<PortU, 6> PortU6;
#       endif
#       ifdef PORTU7
            typedef Pin<PortU, 7> PortU7;
#       endif
#   endif

#   if defined(PORTV) && defined(DDRV) && defined(PINV)
        typedef Port<registers::PortV, registers::DdrV, registers::PinV> PortV;
#       ifdef PORTV0
            typedef Pin<PortV, 0> PortV0;
#       endif
#       ifdef PORTV1
            typedef Pin<PortV, 1> PortV1;
#       endif
#       ifdef PORTV2
            typedef Pin<PortV, 2> PortV2;
#       endif
#       ifdef PORTV3
            typedef Pin<PortV, 3> PortV3;
#       endif
#       ifdef PORTV4
            typedef Pin<PortV, 4> PortV4;
#       endif
#       ifdef PORTV5
            typedef Pin<PortV, 5> PortV5;
#       endif
#       ifdef PORTV6
            typedef Pin<PortV, 6> PortV6;
#       endif
#       ifdef PORTV7
            typedef Pin<PortV, 7> PortV7;
#       endif
#   endif

#   if defined(PORTW) && defined(DDRW) && defined(PINW)
        typedef Port<registers::PortW, registers::DdrW, registers::PinW> PortW;
#       ifdef PORTW0
            typedef Pin<PortW, 0> PortW0;
#       endif
#       ifdef PORTW1
            typedef Pin<PortW, 1> PortW1;
#       endif
#       ifdef PORTW2
            typedef Pin<PortW, 2> PortW2;
#       endif
#       ifdef PORTW3
            typedef Pin<PortW, 3> PortW3;
#       endif
#       ifdef PORTW4
            typedef Pin<PortW, 4> PortW4;
#       endif
#       ifdef PORTW5
            typedef Pin<PortW, 5> PortW5;
#       endif
#       ifdef PORTW6
            typedef Pin<PortW, 6> PortW6;
#       endif
#       ifdef PORTW7
            typedef Pin<PortW, 7> PortW7;
#       endif
#   endif

#   if defined(PORTX) && defined(DDRX) && defined(PINX)
        typedef Port<registers::PortX, registers::DdrX, registers::PinX> PortX;
#       ifdef PORTX0
            typedef Pin<PortX, 0> PortX0;
#       endif
#       ifdef PORTX1
            typedef Pin<PortX, 1> PortX1;
#       endif
#       ifdef PORTX2
            typedef Pin<PortX, 2> PortX2;
#       endif
#       ifdef PORTX3
            typedef Pin<PortX, 3> PortX3;
#       endif
#       ifdef PORTX4
            typedef Pin<PortX, 4> PortX4;
#       endif
#       ifdef PORTX5
            typedef Pin<PortX, 5> PortX5;
#       endif
#       ifdef PORTX6
            typedef Pin<PortX, 6> PortX6;
#       endif
#       ifdef PORTX7
            typedef Pin<PortX, 7> PortX7;
#       endif
#   endif

#   if defined(PORTY) && defined(DDRY) && defined(PINY)
        typedef Port<registers::PortY, registers::DdrY, registers::PinY> PortY;
#       ifdef PORTY0
            typedef Pin<PortY, 0> PortY0;
#       endif
#       ifdef PORTY1
            typedef Pin<PortY, 1> PortY1;
#       endif
#       ifdef PORTY2
            typedef Pin<PortY, 2> PortY2;
#       endif
#       ifdef PORTY3
            typedef Pin<PortY, 3> PortY3;
#       endif
#       ifdef PORTY4
            typedef Pin<PortY, 4> PortY4;
#       endif
#       ifdef PORTY5
            typedef Pin<PortY, 5> PortY5;
#       endif
#       ifdef PORTY6
            typedef Pin<PortY, 6> PortY6;
#       endif
#       ifdef PORTY7
            typedef Pin<PortY, 7> PortY7;
#       endif
#   endif

#   if defined(PORTZ) && defined(DDRZ) && defined(PINZ)
        typedef Port<registers::PortZ, registers::DdrZ, registers::PinZ> PortZ;
#       ifdef PORTZ0
            typedef Pin<PortZ, 0> PortZ0;
#       endif
#       ifdef PORTZ1
            typedef Pin<PortZ, 1> PortZ1;
#       endif
#       ifdef PORTZ2
            typedef Pin<PortZ, 2> PortZ2;
#       endif
#       ifdef PORTZ3
            typedef Pin<PortZ, 3> PortZ3;
#       endif
#       ifdef PORTZ4
            typedef Pin<PortZ, 4> PortZ4;
#       endif
#       ifdef PORTZ5
            typedef Pin<PortZ, 5> PortZ5;
#       endif
#       ifdef PORTZ6
            typedef Pin<PortZ, 6> PortZ6;
#       endif
#       ifdef PORTZ7
            typedef Pin<PortZ, 7> PortZ7;
#       endif
#   endif

}

#endif
