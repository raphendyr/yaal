#ifndef __YAAL_IO__PORTS__
#define __YAAL_IO__PORTS__ 1
#include "../requirements.hh"
#ifdef __YAAL__
/* Generated using ports.sh */

#include "types/port.hh"
#include "types/pin.hh"
#include "types/adc.hh"
#include "registers/port.hh"
#include "registers/adc.hh"

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
#           ifdef PORTA0_ADC
                typedef PinWithAdc<PortA, PORTA0, __CONCAT(AdcChannel, PORTA0_ADC)> PortA0;
                typedef PortA0 __CONCAT(Adc, PORTA0_ADC);
#               undef PORTA0_ADC
#           else
                typedef Pin<PortA, PORTA0> PortA0;
#           endif
#       endif
#       ifdef PORTA1
#           ifdef PORTA1_ADC
                typedef PinWithAdc<PortA, PORTA1, __CONCAT(AdcChannel, PORTA1_ADC)> PortA1;
                typedef PortA1 __CONCAT(Adc, PORTA1_ADC);
#               undef PORTA1_ADC
#           else
                typedef Pin<PortA, PORTA1> PortA1;
#           endif
#       endif
#       ifdef PORTA2
#           ifdef PORTA2_ADC
                typedef PinWithAdc<PortA, PORTA2, __CONCAT(AdcChannel, PORTA2_ADC)> PortA2;
                typedef PortA2 __CONCAT(Adc, PORTA2_ADC);
#               undef PORTA2_ADC
#           else
                typedef Pin<PortA, PORTA2> PortA2;
#           endif
#       endif
#       ifdef PORTA3
#           ifdef PORTA3_ADC
                typedef PinWithAdc<PortA, PORTA3, __CONCAT(AdcChannel, PORTA3_ADC)> PortA3;
                typedef PortA3 __CONCAT(Adc, PORTA3_ADC);
#               undef PORTA3_ADC
#           else
                typedef Pin<PortA, PORTA3> PortA3;
#           endif
#       endif
#       ifdef PORTA4
#           ifdef PORTA4_ADC
                typedef PinWithAdc<PortA, PORTA4, __CONCAT(AdcChannel, PORTA4_ADC)> PortA4;
                typedef PortA4 __CONCAT(Adc, PORTA4_ADC);
#               undef PORTA4_ADC
#           else
                typedef Pin<PortA, PORTA4> PortA4;
#           endif
#       endif
#       ifdef PORTA5
#           ifdef PORTA5_ADC
                typedef PinWithAdc<PortA, PORTA5, __CONCAT(AdcChannel, PORTA5_ADC)> PortA5;
                typedef PortA5 __CONCAT(Adc, PORTA5_ADC);
#               undef PORTA5_ADC
#           else
                typedef Pin<PortA, PORTA5> PortA5;
#           endif
#       endif
#       ifdef PORTA6
#           ifdef PORTA6_ADC
                typedef PinWithAdc<PortA, PORTA6, __CONCAT(AdcChannel, PORTA6_ADC)> PortA6;
                typedef PortA6 __CONCAT(Adc, PORTA6_ADC);
#               undef PORTA6_ADC
#           else
                typedef Pin<PortA, PORTA6> PortA6;
#           endif
#       endif
#       ifdef PORTA7
#           ifdef PORTA7_ADC
                typedef PinWithAdc<PortA, PORTA7, __CONCAT(AdcChannel, PORTA7_ADC)> PortA7;
                typedef PortA7 __CONCAT(Adc, PORTA7_ADC);
#               undef PORTA7_ADC
#           else
                typedef Pin<PortA, PORTA7> PortA7;
#           endif
#       endif
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
#           ifdef PORTB0_ADC
                typedef PinWithAdc<PortB, PORTB0, __CONCAT(AdcChannel, PORTB0_ADC)> PortB0;
                typedef PortB0 __CONCAT(Adc, PORTB0_ADC);
#               undef PORTB0_ADC
#           else
                typedef Pin<PortB, PORTB0> PortB0;
#           endif
#       endif
#       ifdef PORTB1
#           ifdef PORTB1_ADC
                typedef PinWithAdc<PortB, PORTB1, __CONCAT(AdcChannel, PORTB1_ADC)> PortB1;
                typedef PortB1 __CONCAT(Adc, PORTB1_ADC);
#               undef PORTB1_ADC
#           else
                typedef Pin<PortB, PORTB1> PortB1;
#           endif
#       endif
#       ifdef PORTB2
#           ifdef PORTB2_ADC
                typedef PinWithAdc<PortB, PORTB2, __CONCAT(AdcChannel, PORTB2_ADC)> PortB2;
                typedef PortB2 __CONCAT(Adc, PORTB2_ADC);
#               undef PORTB2_ADC
#           else
                typedef Pin<PortB, PORTB2> PortB2;
#           endif
#       endif
#       ifdef PORTB3
#           ifdef PORTB3_ADC
                typedef PinWithAdc<PortB, PORTB3, __CONCAT(AdcChannel, PORTB3_ADC)> PortB3;
                typedef PortB3 __CONCAT(Adc, PORTB3_ADC);
#               undef PORTB3_ADC
#           else
                typedef Pin<PortB, PORTB3> PortB3;
#           endif
#       endif
#       ifdef PORTB4
#           ifdef PORTB4_ADC
                typedef PinWithAdc<PortB, PORTB4, __CONCAT(AdcChannel, PORTB4_ADC)> PortB4;
                typedef PortB4 __CONCAT(Adc, PORTB4_ADC);
#               undef PORTB4_ADC
#           else
                typedef Pin<PortB, PORTB4> PortB4;
#           endif
#       endif
#       ifdef PORTB5
#           ifdef PORTB5_ADC
                typedef PinWithAdc<PortB, PORTB5, __CONCAT(AdcChannel, PORTB5_ADC)> PortB5;
                typedef PortB5 __CONCAT(Adc, PORTB5_ADC);
#               undef PORTB5_ADC
#           else
                typedef Pin<PortB, PORTB5> PortB5;
#           endif
#       endif
#       ifdef PORTB6
#           ifdef PORTB6_ADC
                typedef PinWithAdc<PortB, PORTB6, __CONCAT(AdcChannel, PORTB6_ADC)> PortB6;
                typedef PortB6 __CONCAT(Adc, PORTB6_ADC);
#               undef PORTB6_ADC
#           else
                typedef Pin<PortB, PORTB6> PortB6;
#           endif
#       endif
#       ifdef PORTB7
#           ifdef PORTB7_ADC
                typedef PinWithAdc<PortB, PORTB7, __CONCAT(AdcChannel, PORTB7_ADC)> PortB7;
                typedef PortB7 __CONCAT(Adc, PORTB7_ADC);
#               undef PORTB7_ADC
#           else
                typedef Pin<PortB, PORTB7> PortB7;
#           endif
#       endif
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
#           ifdef PORTC0_ADC
                typedef PinWithAdc<PortC, PORTC0, __CONCAT(AdcChannel, PORTC0_ADC)> PortC0;
                typedef PortC0 __CONCAT(Adc, PORTC0_ADC);
#               undef PORTC0_ADC
#           else
                typedef Pin<PortC, PORTC0> PortC0;
#           endif
#       endif
#       ifdef PORTC1
#           ifdef PORTC1_ADC
                typedef PinWithAdc<PortC, PORTC1, __CONCAT(AdcChannel, PORTC1_ADC)> PortC1;
                typedef PortC1 __CONCAT(Adc, PORTC1_ADC);
#               undef PORTC1_ADC
#           else
                typedef Pin<PortC, PORTC1> PortC1;
#           endif
#       endif
#       ifdef PORTC2
#           ifdef PORTC2_ADC
                typedef PinWithAdc<PortC, PORTC2, __CONCAT(AdcChannel, PORTC2_ADC)> PortC2;
                typedef PortC2 __CONCAT(Adc, PORTC2_ADC);
#               undef PORTC2_ADC
#           else
                typedef Pin<PortC, PORTC2> PortC2;
#           endif
#       endif
#       ifdef PORTC3
#           ifdef PORTC3_ADC
                typedef PinWithAdc<PortC, PORTC3, __CONCAT(AdcChannel, PORTC3_ADC)> PortC3;
                typedef PortC3 __CONCAT(Adc, PORTC3_ADC);
#               undef PORTC3_ADC
#           else
                typedef Pin<PortC, PORTC3> PortC3;
#           endif
#       endif
#       ifdef PORTC4
#           ifdef PORTC4_ADC
                typedef PinWithAdc<PortC, PORTC4, __CONCAT(AdcChannel, PORTC4_ADC)> PortC4;
                typedef PortC4 __CONCAT(Adc, PORTC4_ADC);
#               undef PORTC4_ADC
#           else
                typedef Pin<PortC, PORTC4> PortC4;
#           endif
#       endif
#       ifdef PORTC5
#           ifdef PORTC5_ADC
                typedef PinWithAdc<PortC, PORTC5, __CONCAT(AdcChannel, PORTC5_ADC)> PortC5;
                typedef PortC5 __CONCAT(Adc, PORTC5_ADC);
#               undef PORTC5_ADC
#           else
                typedef Pin<PortC, PORTC5> PortC5;
#           endif
#       endif
#       ifdef PORTC6
#           ifdef PORTC6_ADC
                typedef PinWithAdc<PortC, PORTC6, __CONCAT(AdcChannel, PORTC6_ADC)> PortC6;
                typedef PortC6 __CONCAT(Adc, PORTC6_ADC);
#               undef PORTC6_ADC
#           else
                typedef Pin<PortC, PORTC6> PortC6;
#           endif
#       endif
#       ifdef PORTC7
#           ifdef PORTC7_ADC
                typedef PinWithAdc<PortC, PORTC7, __CONCAT(AdcChannel, PORTC7_ADC)> PortC7;
                typedef PortC7 __CONCAT(Adc, PORTC7_ADC);
#               undef PORTC7_ADC
#           else
                typedef Pin<PortC, PORTC7> PortC7;
#           endif
#       endif
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
#           ifdef PORTD0_ADC
                typedef PinWithAdc<PortD, PORTD0, __CONCAT(AdcChannel, PORTD0_ADC)> PortD0;
                typedef PortD0 __CONCAT(Adc, PORTD0_ADC);
#               undef PORTD0_ADC
#           else
                typedef Pin<PortD, PORTD0> PortD0;
#           endif
#       endif
#       ifdef PORTD1
#           ifdef PORTD1_ADC
                typedef PinWithAdc<PortD, PORTD1, __CONCAT(AdcChannel, PORTD1_ADC)> PortD1;
                typedef PortD1 __CONCAT(Adc, PORTD1_ADC);
#               undef PORTD1_ADC
#           else
                typedef Pin<PortD, PORTD1> PortD1;
#           endif
#       endif
#       ifdef PORTD2
#           ifdef PORTD2_ADC
                typedef PinWithAdc<PortD, PORTD2, __CONCAT(AdcChannel, PORTD2_ADC)> PortD2;
                typedef PortD2 __CONCAT(Adc, PORTD2_ADC);
#               undef PORTD2_ADC
#           else
                typedef Pin<PortD, PORTD2> PortD2;
#           endif
#       endif
#       ifdef PORTD3
#           ifdef PORTD3_ADC
                typedef PinWithAdc<PortD, PORTD3, __CONCAT(AdcChannel, PORTD3_ADC)> PortD3;
                typedef PortD3 __CONCAT(Adc, PORTD3_ADC);
#               undef PORTD3_ADC
#           else
                typedef Pin<PortD, PORTD3> PortD3;
#           endif
#       endif
#       ifdef PORTD4
#           ifdef PORTD4_ADC
                typedef PinWithAdc<PortD, PORTD4, __CONCAT(AdcChannel, PORTD4_ADC)> PortD4;
                typedef PortD4 __CONCAT(Adc, PORTD4_ADC);
#               undef PORTD4_ADC
#           else
                typedef Pin<PortD, PORTD4> PortD4;
#           endif
#       endif
#       ifdef PORTD5
#           ifdef PORTD5_ADC
                typedef PinWithAdc<PortD, PORTD5, __CONCAT(AdcChannel, PORTD5_ADC)> PortD5;
                typedef PortD5 __CONCAT(Adc, PORTD5_ADC);
#               undef PORTD5_ADC
#           else
                typedef Pin<PortD, PORTD5> PortD5;
#           endif
#       endif
#       ifdef PORTD6
#           ifdef PORTD6_ADC
                typedef PinWithAdc<PortD, PORTD6, __CONCAT(AdcChannel, PORTD6_ADC)> PortD6;
                typedef PortD6 __CONCAT(Adc, PORTD6_ADC);
#               undef PORTD6_ADC
#           else
                typedef Pin<PortD, PORTD6> PortD6;
#           endif
#       endif
#       ifdef PORTD7
#           ifdef PORTD7_ADC
                typedef PinWithAdc<PortD, PORTD7, __CONCAT(AdcChannel, PORTD7_ADC)> PortD7;
                typedef PortD7 __CONCAT(Adc, PORTD7_ADC);
#               undef PORTD7_ADC
#           else
                typedef Pin<PortD, PORTD7> PortD7;
#           endif
#       endif
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
#           ifdef PORTE0_ADC
                typedef PinWithAdc<PortE, PORTE0, __CONCAT(AdcChannel, PORTE0_ADC)> PortE0;
                typedef PortE0 __CONCAT(Adc, PORTE0_ADC);
#               undef PORTE0_ADC
#           else
                typedef Pin<PortE, PORTE0> PortE0;
#           endif
#       endif
#       ifdef PORTE1
#           ifdef PORTE1_ADC
                typedef PinWithAdc<PortE, PORTE1, __CONCAT(AdcChannel, PORTE1_ADC)> PortE1;
                typedef PortE1 __CONCAT(Adc, PORTE1_ADC);
#               undef PORTE1_ADC
#           else
                typedef Pin<PortE, PORTE1> PortE1;
#           endif
#       endif
#       ifdef PORTE2
#           ifdef PORTE2_ADC
                typedef PinWithAdc<PortE, PORTE2, __CONCAT(AdcChannel, PORTE2_ADC)> PortE2;
                typedef PortE2 __CONCAT(Adc, PORTE2_ADC);
#               undef PORTE2_ADC
#           else
                typedef Pin<PortE, PORTE2> PortE2;
#           endif
#       endif
#       ifdef PORTE3
#           ifdef PORTE3_ADC
                typedef PinWithAdc<PortE, PORTE3, __CONCAT(AdcChannel, PORTE3_ADC)> PortE3;
                typedef PortE3 __CONCAT(Adc, PORTE3_ADC);
#               undef PORTE3_ADC
#           else
                typedef Pin<PortE, PORTE3> PortE3;
#           endif
#       endif
#       ifdef PORTE4
#           ifdef PORTE4_ADC
                typedef PinWithAdc<PortE, PORTE4, __CONCAT(AdcChannel, PORTE4_ADC)> PortE4;
                typedef PortE4 __CONCAT(Adc, PORTE4_ADC);
#               undef PORTE4_ADC
#           else
                typedef Pin<PortE, PORTE4> PortE4;
#           endif
#       endif
#       ifdef PORTE5
#           ifdef PORTE5_ADC
                typedef PinWithAdc<PortE, PORTE5, __CONCAT(AdcChannel, PORTE5_ADC)> PortE5;
                typedef PortE5 __CONCAT(Adc, PORTE5_ADC);
#               undef PORTE5_ADC
#           else
                typedef Pin<PortE, PORTE5> PortE5;
#           endif
#       endif
#       ifdef PORTE6
#           ifdef PORTE6_ADC
                typedef PinWithAdc<PortE, PORTE6, __CONCAT(AdcChannel, PORTE6_ADC)> PortE6;
                typedef PortE6 __CONCAT(Adc, PORTE6_ADC);
#               undef PORTE6_ADC
#           else
                typedef Pin<PortE, PORTE6> PortE6;
#           endif
#       endif
#       ifdef PORTE7
#           ifdef PORTE7_ADC
                typedef PinWithAdc<PortE, PORTE7, __CONCAT(AdcChannel, PORTE7_ADC)> PortE7;
                typedef PortE7 __CONCAT(Adc, PORTE7_ADC);
#               undef PORTE7_ADC
#           else
                typedef Pin<PortE, PORTE7> PortE7;
#           endif
#       endif
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
#           ifdef PORTF0_ADC
                typedef PinWithAdc<PortF, PORTF0, __CONCAT(AdcChannel, PORTF0_ADC)> PortF0;
                typedef PortF0 __CONCAT(Adc, PORTF0_ADC);
#               undef PORTF0_ADC
#           else
                typedef Pin<PortF, PORTF0> PortF0;
#           endif
#       endif
#       ifdef PORTF1
#           ifdef PORTF1_ADC
                typedef PinWithAdc<PortF, PORTF1, __CONCAT(AdcChannel, PORTF1_ADC)> PortF1;
                typedef PortF1 __CONCAT(Adc, PORTF1_ADC);
#               undef PORTF1_ADC
#           else
                typedef Pin<PortF, PORTF1> PortF1;
#           endif
#       endif
#       ifdef PORTF2
#           ifdef PORTF2_ADC
                typedef PinWithAdc<PortF, PORTF2, __CONCAT(AdcChannel, PORTF2_ADC)> PortF2;
                typedef PortF2 __CONCAT(Adc, PORTF2_ADC);
#               undef PORTF2_ADC
#           else
                typedef Pin<PortF, PORTF2> PortF2;
#           endif
#       endif
#       ifdef PORTF3
#           ifdef PORTF3_ADC
                typedef PinWithAdc<PortF, PORTF3, __CONCAT(AdcChannel, PORTF3_ADC)> PortF3;
                typedef PortF3 __CONCAT(Adc, PORTF3_ADC);
#               undef PORTF3_ADC
#           else
                typedef Pin<PortF, PORTF3> PortF3;
#           endif
#       endif
#       ifdef PORTF4
#           ifdef PORTF4_ADC
                typedef PinWithAdc<PortF, PORTF4, __CONCAT(AdcChannel, PORTF4_ADC)> PortF4;
                typedef PortF4 __CONCAT(Adc, PORTF4_ADC);
#               undef PORTF4_ADC
#           else
                typedef Pin<PortF, PORTF4> PortF4;
#           endif
#       endif
#       ifdef PORTF5
#           ifdef PORTF5_ADC
                typedef PinWithAdc<PortF, PORTF5, __CONCAT(AdcChannel, PORTF5_ADC)> PortF5;
                typedef PortF5 __CONCAT(Adc, PORTF5_ADC);
#               undef PORTF5_ADC
#           else
                typedef Pin<PortF, PORTF5> PortF5;
#           endif
#       endif
#       ifdef PORTF6
#           ifdef PORTF6_ADC
                typedef PinWithAdc<PortF, PORTF6, __CONCAT(AdcChannel, PORTF6_ADC)> PortF6;
                typedef PortF6 __CONCAT(Adc, PORTF6_ADC);
#               undef PORTF6_ADC
#           else
                typedef Pin<PortF, PORTF6> PortF6;
#           endif
#       endif
#       ifdef PORTF7
#           ifdef PORTF7_ADC
                typedef PinWithAdc<PortF, PORTF7, __CONCAT(AdcChannel, PORTF7_ADC)> PortF7;
                typedef PortF7 __CONCAT(Adc, PORTF7_ADC);
#               undef PORTF7_ADC
#           else
                typedef Pin<PortF, PORTF7> PortF7;
#           endif
#       endif
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
#           ifdef PORTG0_ADC
                typedef PinWithAdc<PortG, PORTG0, __CONCAT(AdcChannel, PORTG0_ADC)> PortG0;
                typedef PortG0 __CONCAT(Adc, PORTG0_ADC);
#               undef PORTG0_ADC
#           else
                typedef Pin<PortG, PORTG0> PortG0;
#           endif
#       endif
#       ifdef PORTG1
#           ifdef PORTG1_ADC
                typedef PinWithAdc<PortG, PORTG1, __CONCAT(AdcChannel, PORTG1_ADC)> PortG1;
                typedef PortG1 __CONCAT(Adc, PORTG1_ADC);
#               undef PORTG1_ADC
#           else
                typedef Pin<PortG, PORTG1> PortG1;
#           endif
#       endif
#       ifdef PORTG2
#           ifdef PORTG2_ADC
                typedef PinWithAdc<PortG, PORTG2, __CONCAT(AdcChannel, PORTG2_ADC)> PortG2;
                typedef PortG2 __CONCAT(Adc, PORTG2_ADC);
#               undef PORTG2_ADC
#           else
                typedef Pin<PortG, PORTG2> PortG2;
#           endif
#       endif
#       ifdef PORTG3
#           ifdef PORTG3_ADC
                typedef PinWithAdc<PortG, PORTG3, __CONCAT(AdcChannel, PORTG3_ADC)> PortG3;
                typedef PortG3 __CONCAT(Adc, PORTG3_ADC);
#               undef PORTG3_ADC
#           else
                typedef Pin<PortG, PORTG3> PortG3;
#           endif
#       endif
#       ifdef PORTG4
#           ifdef PORTG4_ADC
                typedef PinWithAdc<PortG, PORTG4, __CONCAT(AdcChannel, PORTG4_ADC)> PortG4;
                typedef PortG4 __CONCAT(Adc, PORTG4_ADC);
#               undef PORTG4_ADC
#           else
                typedef Pin<PortG, PORTG4> PortG4;
#           endif
#       endif
#       ifdef PORTG5
#           ifdef PORTG5_ADC
                typedef PinWithAdc<PortG, PORTG5, __CONCAT(AdcChannel, PORTG5_ADC)> PortG5;
                typedef PortG5 __CONCAT(Adc, PORTG5_ADC);
#               undef PORTG5_ADC
#           else
                typedef Pin<PortG, PORTG5> PortG5;
#           endif
#       endif
#       ifdef PORTG6
#           ifdef PORTG6_ADC
                typedef PinWithAdc<PortG, PORTG6, __CONCAT(AdcChannel, PORTG6_ADC)> PortG6;
                typedef PortG6 __CONCAT(Adc, PORTG6_ADC);
#               undef PORTG6_ADC
#           else
                typedef Pin<PortG, PORTG6> PortG6;
#           endif
#       endif
#       ifdef PORTG7
#           ifdef PORTG7_ADC
                typedef PinWithAdc<PortG, PORTG7, __CONCAT(AdcChannel, PORTG7_ADC)> PortG7;
                typedef PortG7 __CONCAT(Adc, PORTG7_ADC);
#               undef PORTG7_ADC
#           else
                typedef Pin<PortG, PORTG7> PortG7;
#           endif
#       endif
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
#           ifdef PORTH0_ADC
                typedef PinWithAdc<PortH, PORTH0, __CONCAT(AdcChannel, PORTH0_ADC)> PortH0;
                typedef PortH0 __CONCAT(Adc, PORTH0_ADC);
#               undef PORTH0_ADC
#           else
                typedef Pin<PortH, PORTH0> PortH0;
#           endif
#       endif
#       ifdef PORTH1
#           ifdef PORTH1_ADC
                typedef PinWithAdc<PortH, PORTH1, __CONCAT(AdcChannel, PORTH1_ADC)> PortH1;
                typedef PortH1 __CONCAT(Adc, PORTH1_ADC);
#               undef PORTH1_ADC
#           else
                typedef Pin<PortH, PORTH1> PortH1;
#           endif
#       endif
#       ifdef PORTH2
#           ifdef PORTH2_ADC
                typedef PinWithAdc<PortH, PORTH2, __CONCAT(AdcChannel, PORTH2_ADC)> PortH2;
                typedef PortH2 __CONCAT(Adc, PORTH2_ADC);
#               undef PORTH2_ADC
#           else
                typedef Pin<PortH, PORTH2> PortH2;
#           endif
#       endif
#       ifdef PORTH3
#           ifdef PORTH3_ADC
                typedef PinWithAdc<PortH, PORTH3, __CONCAT(AdcChannel, PORTH3_ADC)> PortH3;
                typedef PortH3 __CONCAT(Adc, PORTH3_ADC);
#               undef PORTH3_ADC
#           else
                typedef Pin<PortH, PORTH3> PortH3;
#           endif
#       endif
#       ifdef PORTH4
#           ifdef PORTH4_ADC
                typedef PinWithAdc<PortH, PORTH4, __CONCAT(AdcChannel, PORTH4_ADC)> PortH4;
                typedef PortH4 __CONCAT(Adc, PORTH4_ADC);
#               undef PORTH4_ADC
#           else
                typedef Pin<PortH, PORTH4> PortH4;
#           endif
#       endif
#       ifdef PORTH5
#           ifdef PORTH5_ADC
                typedef PinWithAdc<PortH, PORTH5, __CONCAT(AdcChannel, PORTH5_ADC)> PortH5;
                typedef PortH5 __CONCAT(Adc, PORTH5_ADC);
#               undef PORTH5_ADC
#           else
                typedef Pin<PortH, PORTH5> PortH5;
#           endif
#       endif
#       ifdef PORTH6
#           ifdef PORTH6_ADC
                typedef PinWithAdc<PortH, PORTH6, __CONCAT(AdcChannel, PORTH6_ADC)> PortH6;
                typedef PortH6 __CONCAT(Adc, PORTH6_ADC);
#               undef PORTH6_ADC
#           else
                typedef Pin<PortH, PORTH6> PortH6;
#           endif
#       endif
#       ifdef PORTH7
#           ifdef PORTH7_ADC
                typedef PinWithAdc<PortH, PORTH7, __CONCAT(AdcChannel, PORTH7_ADC)> PortH7;
                typedef PortH7 __CONCAT(Adc, PORTH7_ADC);
#               undef PORTH7_ADC
#           else
                typedef Pin<PortH, PORTH7> PortH7;
#           endif
#       endif
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
#           ifdef PORTI0_ADC
                typedef PinWithAdc<PortI, PORTI0, __CONCAT(AdcChannel, PORTI0_ADC)> PortI0;
                typedef PortI0 __CONCAT(Adc, PORTI0_ADC);
#               undef PORTI0_ADC
#           else
                typedef Pin<PortI, PORTI0> PortI0;
#           endif
#       endif
#       ifdef PORTI1
#           ifdef PORTI1_ADC
                typedef PinWithAdc<PortI, PORTI1, __CONCAT(AdcChannel, PORTI1_ADC)> PortI1;
                typedef PortI1 __CONCAT(Adc, PORTI1_ADC);
#               undef PORTI1_ADC
#           else
                typedef Pin<PortI, PORTI1> PortI1;
#           endif
#       endif
#       ifdef PORTI2
#           ifdef PORTI2_ADC
                typedef PinWithAdc<PortI, PORTI2, __CONCAT(AdcChannel, PORTI2_ADC)> PortI2;
                typedef PortI2 __CONCAT(Adc, PORTI2_ADC);
#               undef PORTI2_ADC
#           else
                typedef Pin<PortI, PORTI2> PortI2;
#           endif
#       endif
#       ifdef PORTI3
#           ifdef PORTI3_ADC
                typedef PinWithAdc<PortI, PORTI3, __CONCAT(AdcChannel, PORTI3_ADC)> PortI3;
                typedef PortI3 __CONCAT(Adc, PORTI3_ADC);
#               undef PORTI3_ADC
#           else
                typedef Pin<PortI, PORTI3> PortI3;
#           endif
#       endif
#       ifdef PORTI4
#           ifdef PORTI4_ADC
                typedef PinWithAdc<PortI, PORTI4, __CONCAT(AdcChannel, PORTI4_ADC)> PortI4;
                typedef PortI4 __CONCAT(Adc, PORTI4_ADC);
#               undef PORTI4_ADC
#           else
                typedef Pin<PortI, PORTI4> PortI4;
#           endif
#       endif
#       ifdef PORTI5
#           ifdef PORTI5_ADC
                typedef PinWithAdc<PortI, PORTI5, __CONCAT(AdcChannel, PORTI5_ADC)> PortI5;
                typedef PortI5 __CONCAT(Adc, PORTI5_ADC);
#               undef PORTI5_ADC
#           else
                typedef Pin<PortI, PORTI5> PortI5;
#           endif
#       endif
#       ifdef PORTI6
#           ifdef PORTI6_ADC
                typedef PinWithAdc<PortI, PORTI6, __CONCAT(AdcChannel, PORTI6_ADC)> PortI6;
                typedef PortI6 __CONCAT(Adc, PORTI6_ADC);
#               undef PORTI6_ADC
#           else
                typedef Pin<PortI, PORTI6> PortI6;
#           endif
#       endif
#       ifdef PORTI7
#           ifdef PORTI7_ADC
                typedef PinWithAdc<PortI, PORTI7, __CONCAT(AdcChannel, PORTI7_ADC)> PortI7;
                typedef PortI7 __CONCAT(Adc, PORTI7_ADC);
#               undef PORTI7_ADC
#           else
                typedef Pin<PortI, PORTI7> PortI7;
#           endif
#       endif
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
#           ifdef PORTJ0_ADC
                typedef PinWithAdc<PortJ, PORTJ0, __CONCAT(AdcChannel, PORTJ0_ADC)> PortJ0;
                typedef PortJ0 __CONCAT(Adc, PORTJ0_ADC);
#               undef PORTJ0_ADC
#           else
                typedef Pin<PortJ, PORTJ0> PortJ0;
#           endif
#       endif
#       ifdef PORTJ1
#           ifdef PORTJ1_ADC
                typedef PinWithAdc<PortJ, PORTJ1, __CONCAT(AdcChannel, PORTJ1_ADC)> PortJ1;
                typedef PortJ1 __CONCAT(Adc, PORTJ1_ADC);
#               undef PORTJ1_ADC
#           else
                typedef Pin<PortJ, PORTJ1> PortJ1;
#           endif
#       endif
#       ifdef PORTJ2
#           ifdef PORTJ2_ADC
                typedef PinWithAdc<PortJ, PORTJ2, __CONCAT(AdcChannel, PORTJ2_ADC)> PortJ2;
                typedef PortJ2 __CONCAT(Adc, PORTJ2_ADC);
#               undef PORTJ2_ADC
#           else
                typedef Pin<PortJ, PORTJ2> PortJ2;
#           endif
#       endif
#       ifdef PORTJ3
#           ifdef PORTJ3_ADC
                typedef PinWithAdc<PortJ, PORTJ3, __CONCAT(AdcChannel, PORTJ3_ADC)> PortJ3;
                typedef PortJ3 __CONCAT(Adc, PORTJ3_ADC);
#               undef PORTJ3_ADC
#           else
                typedef Pin<PortJ, PORTJ3> PortJ3;
#           endif
#       endif
#       ifdef PORTJ4
#           ifdef PORTJ4_ADC
                typedef PinWithAdc<PortJ, PORTJ4, __CONCAT(AdcChannel, PORTJ4_ADC)> PortJ4;
                typedef PortJ4 __CONCAT(Adc, PORTJ4_ADC);
#               undef PORTJ4_ADC
#           else
                typedef Pin<PortJ, PORTJ4> PortJ4;
#           endif
#       endif
#       ifdef PORTJ5
#           ifdef PORTJ5_ADC
                typedef PinWithAdc<PortJ, PORTJ5, __CONCAT(AdcChannel, PORTJ5_ADC)> PortJ5;
                typedef PortJ5 __CONCAT(Adc, PORTJ5_ADC);
#               undef PORTJ5_ADC
#           else
                typedef Pin<PortJ, PORTJ5> PortJ5;
#           endif
#       endif
#       ifdef PORTJ6
#           ifdef PORTJ6_ADC
                typedef PinWithAdc<PortJ, PORTJ6, __CONCAT(AdcChannel, PORTJ6_ADC)> PortJ6;
                typedef PortJ6 __CONCAT(Adc, PORTJ6_ADC);
#               undef PORTJ6_ADC
#           else
                typedef Pin<PortJ, PORTJ6> PortJ6;
#           endif
#       endif
#       ifdef PORTJ7
#           ifdef PORTJ7_ADC
                typedef PinWithAdc<PortJ, PORTJ7, __CONCAT(AdcChannel, PORTJ7_ADC)> PortJ7;
                typedef PortJ7 __CONCAT(Adc, PORTJ7_ADC);
#               undef PORTJ7_ADC
#           else
                typedef Pin<PortJ, PORTJ7> PortJ7;
#           endif
#       endif
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
#           ifdef PORTK0_ADC
                typedef PinWithAdc<PortK, PORTK0, __CONCAT(AdcChannel, PORTK0_ADC)> PortK0;
                typedef PortK0 __CONCAT(Adc, PORTK0_ADC);
#               undef PORTK0_ADC
#           else
                typedef Pin<PortK, PORTK0> PortK0;
#           endif
#       endif
#       ifdef PORTK1
#           ifdef PORTK1_ADC
                typedef PinWithAdc<PortK, PORTK1, __CONCAT(AdcChannel, PORTK1_ADC)> PortK1;
                typedef PortK1 __CONCAT(Adc, PORTK1_ADC);
#               undef PORTK1_ADC
#           else
                typedef Pin<PortK, PORTK1> PortK1;
#           endif
#       endif
#       ifdef PORTK2
#           ifdef PORTK2_ADC
                typedef PinWithAdc<PortK, PORTK2, __CONCAT(AdcChannel, PORTK2_ADC)> PortK2;
                typedef PortK2 __CONCAT(Adc, PORTK2_ADC);
#               undef PORTK2_ADC
#           else
                typedef Pin<PortK, PORTK2> PortK2;
#           endif
#       endif
#       ifdef PORTK3
#           ifdef PORTK3_ADC
                typedef PinWithAdc<PortK, PORTK3, __CONCAT(AdcChannel, PORTK3_ADC)> PortK3;
                typedef PortK3 __CONCAT(Adc, PORTK3_ADC);
#               undef PORTK3_ADC
#           else
                typedef Pin<PortK, PORTK3> PortK3;
#           endif
#       endif
#       ifdef PORTK4
#           ifdef PORTK4_ADC
                typedef PinWithAdc<PortK, PORTK4, __CONCAT(AdcChannel, PORTK4_ADC)> PortK4;
                typedef PortK4 __CONCAT(Adc, PORTK4_ADC);
#               undef PORTK4_ADC
#           else
                typedef Pin<PortK, PORTK4> PortK4;
#           endif
#       endif
#       ifdef PORTK5
#           ifdef PORTK5_ADC
                typedef PinWithAdc<PortK, PORTK5, __CONCAT(AdcChannel, PORTK5_ADC)> PortK5;
                typedef PortK5 __CONCAT(Adc, PORTK5_ADC);
#               undef PORTK5_ADC
#           else
                typedef Pin<PortK, PORTK5> PortK5;
#           endif
#       endif
#       ifdef PORTK6
#           ifdef PORTK6_ADC
                typedef PinWithAdc<PortK, PORTK6, __CONCAT(AdcChannel, PORTK6_ADC)> PortK6;
                typedef PortK6 __CONCAT(Adc, PORTK6_ADC);
#               undef PORTK6_ADC
#           else
                typedef Pin<PortK, PORTK6> PortK6;
#           endif
#       endif
#       ifdef PORTK7
#           ifdef PORTK7_ADC
                typedef PinWithAdc<PortK, PORTK7, __CONCAT(AdcChannel, PORTK7_ADC)> PortK7;
                typedef PortK7 __CONCAT(Adc, PORTK7_ADC);
#               undef PORTK7_ADC
#           else
                typedef Pin<PortK, PORTK7> PortK7;
#           endif
#       endif
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
#           ifdef PORTL0_ADC
                typedef PinWithAdc<PortL, PORTL0, __CONCAT(AdcChannel, PORTL0_ADC)> PortL0;
                typedef PortL0 __CONCAT(Adc, PORTL0_ADC);
#               undef PORTL0_ADC
#           else
                typedef Pin<PortL, PORTL0> PortL0;
#           endif
#       endif
#       ifdef PORTL1
#           ifdef PORTL1_ADC
                typedef PinWithAdc<PortL, PORTL1, __CONCAT(AdcChannel, PORTL1_ADC)> PortL1;
                typedef PortL1 __CONCAT(Adc, PORTL1_ADC);
#               undef PORTL1_ADC
#           else
                typedef Pin<PortL, PORTL1> PortL1;
#           endif
#       endif
#       ifdef PORTL2
#           ifdef PORTL2_ADC
                typedef PinWithAdc<PortL, PORTL2, __CONCAT(AdcChannel, PORTL2_ADC)> PortL2;
                typedef PortL2 __CONCAT(Adc, PORTL2_ADC);
#               undef PORTL2_ADC
#           else
                typedef Pin<PortL, PORTL2> PortL2;
#           endif
#       endif
#       ifdef PORTL3
#           ifdef PORTL3_ADC
                typedef PinWithAdc<PortL, PORTL3, __CONCAT(AdcChannel, PORTL3_ADC)> PortL3;
                typedef PortL3 __CONCAT(Adc, PORTL3_ADC);
#               undef PORTL3_ADC
#           else
                typedef Pin<PortL, PORTL3> PortL3;
#           endif
#       endif
#       ifdef PORTL4
#           ifdef PORTL4_ADC
                typedef PinWithAdc<PortL, PORTL4, __CONCAT(AdcChannel, PORTL4_ADC)> PortL4;
                typedef PortL4 __CONCAT(Adc, PORTL4_ADC);
#               undef PORTL4_ADC
#           else
                typedef Pin<PortL, PORTL4> PortL4;
#           endif
#       endif
#       ifdef PORTL5
#           ifdef PORTL5_ADC
                typedef PinWithAdc<PortL, PORTL5, __CONCAT(AdcChannel, PORTL5_ADC)> PortL5;
                typedef PortL5 __CONCAT(Adc, PORTL5_ADC);
#               undef PORTL5_ADC
#           else
                typedef Pin<PortL, PORTL5> PortL5;
#           endif
#       endif
#       ifdef PORTL6
#           ifdef PORTL6_ADC
                typedef PinWithAdc<PortL, PORTL6, __CONCAT(AdcChannel, PORTL6_ADC)> PortL6;
                typedef PortL6 __CONCAT(Adc, PORTL6_ADC);
#               undef PORTL6_ADC
#           else
                typedef Pin<PortL, PORTL6> PortL6;
#           endif
#       endif
#       ifdef PORTL7
#           ifdef PORTL7_ADC
                typedef PinWithAdc<PortL, PORTL7, __CONCAT(AdcChannel, PORTL7_ADC)> PortL7;
                typedef PortL7 __CONCAT(Adc, PORTL7_ADC);
#               undef PORTL7_ADC
#           else
                typedef Pin<PortL, PORTL7> PortL7;
#           endif
#       endif
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
#           ifdef PORTM0_ADC
                typedef PinWithAdc<PortM, PORTM0, __CONCAT(AdcChannel, PORTM0_ADC)> PortM0;
                typedef PortM0 __CONCAT(Adc, PORTM0_ADC);
#               undef PORTM0_ADC
#           else
                typedef Pin<PortM, PORTM0> PortM0;
#           endif
#       endif
#       ifdef PORTM1
#           ifdef PORTM1_ADC
                typedef PinWithAdc<PortM, PORTM1, __CONCAT(AdcChannel, PORTM1_ADC)> PortM1;
                typedef PortM1 __CONCAT(Adc, PORTM1_ADC);
#               undef PORTM1_ADC
#           else
                typedef Pin<PortM, PORTM1> PortM1;
#           endif
#       endif
#       ifdef PORTM2
#           ifdef PORTM2_ADC
                typedef PinWithAdc<PortM, PORTM2, __CONCAT(AdcChannel, PORTM2_ADC)> PortM2;
                typedef PortM2 __CONCAT(Adc, PORTM2_ADC);
#               undef PORTM2_ADC
#           else
                typedef Pin<PortM, PORTM2> PortM2;
#           endif
#       endif
#       ifdef PORTM3
#           ifdef PORTM3_ADC
                typedef PinWithAdc<PortM, PORTM3, __CONCAT(AdcChannel, PORTM3_ADC)> PortM3;
                typedef PortM3 __CONCAT(Adc, PORTM3_ADC);
#               undef PORTM3_ADC
#           else
                typedef Pin<PortM, PORTM3> PortM3;
#           endif
#       endif
#       ifdef PORTM4
#           ifdef PORTM4_ADC
                typedef PinWithAdc<PortM, PORTM4, __CONCAT(AdcChannel, PORTM4_ADC)> PortM4;
                typedef PortM4 __CONCAT(Adc, PORTM4_ADC);
#               undef PORTM4_ADC
#           else
                typedef Pin<PortM, PORTM4> PortM4;
#           endif
#       endif
#       ifdef PORTM5
#           ifdef PORTM5_ADC
                typedef PinWithAdc<PortM, PORTM5, __CONCAT(AdcChannel, PORTM5_ADC)> PortM5;
                typedef PortM5 __CONCAT(Adc, PORTM5_ADC);
#               undef PORTM5_ADC
#           else
                typedef Pin<PortM, PORTM5> PortM5;
#           endif
#       endif
#       ifdef PORTM6
#           ifdef PORTM6_ADC
                typedef PinWithAdc<PortM, PORTM6, __CONCAT(AdcChannel, PORTM6_ADC)> PortM6;
                typedef PortM6 __CONCAT(Adc, PORTM6_ADC);
#               undef PORTM6_ADC
#           else
                typedef Pin<PortM, PORTM6> PortM6;
#           endif
#       endif
#       ifdef PORTM7
#           ifdef PORTM7_ADC
                typedef PinWithAdc<PortM, PORTM7, __CONCAT(AdcChannel, PORTM7_ADC)> PortM7;
                typedef PortM7 __CONCAT(Adc, PORTM7_ADC);
#               undef PORTM7_ADC
#           else
                typedef Pin<PortM, PORTM7> PortM7;
#           endif
#       endif
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
#           ifdef PORTN0_ADC
                typedef PinWithAdc<PortN, PORTN0, __CONCAT(AdcChannel, PORTN0_ADC)> PortN0;
                typedef PortN0 __CONCAT(Adc, PORTN0_ADC);
#               undef PORTN0_ADC
#           else
                typedef Pin<PortN, PORTN0> PortN0;
#           endif
#       endif
#       ifdef PORTN1
#           ifdef PORTN1_ADC
                typedef PinWithAdc<PortN, PORTN1, __CONCAT(AdcChannel, PORTN1_ADC)> PortN1;
                typedef PortN1 __CONCAT(Adc, PORTN1_ADC);
#               undef PORTN1_ADC
#           else
                typedef Pin<PortN, PORTN1> PortN1;
#           endif
#       endif
#       ifdef PORTN2
#           ifdef PORTN2_ADC
                typedef PinWithAdc<PortN, PORTN2, __CONCAT(AdcChannel, PORTN2_ADC)> PortN2;
                typedef PortN2 __CONCAT(Adc, PORTN2_ADC);
#               undef PORTN2_ADC
#           else
                typedef Pin<PortN, PORTN2> PortN2;
#           endif
#       endif
#       ifdef PORTN3
#           ifdef PORTN3_ADC
                typedef PinWithAdc<PortN, PORTN3, __CONCAT(AdcChannel, PORTN3_ADC)> PortN3;
                typedef PortN3 __CONCAT(Adc, PORTN3_ADC);
#               undef PORTN3_ADC
#           else
                typedef Pin<PortN, PORTN3> PortN3;
#           endif
#       endif
#       ifdef PORTN4
#           ifdef PORTN4_ADC
                typedef PinWithAdc<PortN, PORTN4, __CONCAT(AdcChannel, PORTN4_ADC)> PortN4;
                typedef PortN4 __CONCAT(Adc, PORTN4_ADC);
#               undef PORTN4_ADC
#           else
                typedef Pin<PortN, PORTN4> PortN4;
#           endif
#       endif
#       ifdef PORTN5
#           ifdef PORTN5_ADC
                typedef PinWithAdc<PortN, PORTN5, __CONCAT(AdcChannel, PORTN5_ADC)> PortN5;
                typedef PortN5 __CONCAT(Adc, PORTN5_ADC);
#               undef PORTN5_ADC
#           else
                typedef Pin<PortN, PORTN5> PortN5;
#           endif
#       endif
#       ifdef PORTN6
#           ifdef PORTN6_ADC
                typedef PinWithAdc<PortN, PORTN6, __CONCAT(AdcChannel, PORTN6_ADC)> PortN6;
                typedef PortN6 __CONCAT(Adc, PORTN6_ADC);
#               undef PORTN6_ADC
#           else
                typedef Pin<PortN, PORTN6> PortN6;
#           endif
#       endif
#       ifdef PORTN7
#           ifdef PORTN7_ADC
                typedef PinWithAdc<PortN, PORTN7, __CONCAT(AdcChannel, PORTN7_ADC)> PortN7;
                typedef PortN7 __CONCAT(Adc, PORTN7_ADC);
#               undef PORTN7_ADC
#           else
                typedef Pin<PortN, PORTN7> PortN7;
#           endif
#       endif
#   endif
}

#endif
#endif
