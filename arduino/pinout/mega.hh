#ifndef __YAAL_ARDUINO__PINOUT__MEGA__
#define __YAAL_ARDUINO__PINOUT__MEGA__ 1
#include "../../requirements.hh"
#ifdef __YAAL__

#ifndef __YAAL_ARDUINO__PINOUT__LOCK
# error "Do not include arduino pinouts for boards directly. Include yaal/arduino/pinout.hh instead."
#else

#include "../../io.hh"

namespace yaal {
    namespace arduino {

        // NUM_DIGITAL_PINS 70
        // NUM_ANALOG_PINS  16
        // pcints in: 10, 11, 12, 13,  50, 51, 52, 53,  62, 63, 64, 65, 66, 67, 68, 69
        // some usart pins has also

        /** digitals in default location **/
        typedef DigitalPin<PortE0> D0;  // RXD0
        typedef DigitalPin<PortE1> D1;  // TXD0
        typedef DigitalPin<PortE4> D2;  // TIMER3B
        typedef DigitalPin<PortE5> D3;  // TIMER3C
        typedef DigitalPin<PortG5> D4;  // TIMER0B
        typedef DigitalPin<PortE3> D5;  // TIMER3A
        typedef DigitalPin<PortH3> D6;  // TIMER4A
        typedef DigitalPin<PortH4> D7;  // TIMER4B
        typedef DigitalPin<PortH5> D8;  // TIMER4C
        typedef DigitalPin<PortH6> D9;  // TIMER2B
        typedef DigitalPin<PortH6> D10; // TIMER2A
        typedef DigitalPin<PortB4> D11; // TIMER1A
        typedef DigitalPin<PortB5> D12; // TIMER1B
        typedef DigitalPin<PortB7> D13; // TIMER0A, led

        /** serial pins **/
        typedef DigitalPin<PortJ1> D14; // TX3
        typedef DigitalPin<PortJ0> D15; // RX3
        typedef DigitalPin<PortH1> D16; // TX2
        typedef DigitalPin<PortH0> D17; // RX2
        typedef DigitalPin<PortD3> D18; // TX1
        typedef DigitalPin<PortD2> D19; // RX1
        typedef DigitalPin<PortD1> D20; // SDA
        typedef DigitalPin<PortD0> D21; // SCL

        /** rest of digital **/
        typedef DigitalPin<PortA0> D22;
        typedef DigitalPin<PortA1> D23;
        typedef DigitalPin<PortA2> D24;
        typedef DigitalPin<PortA3> D25;
        typedef DigitalPin<PortA4> D26;
        typedef DigitalPin<PortA5> D27;
        typedef DigitalPin<PortA6> D28;
        typedef DigitalPin<PortA7> D29;
        typedef DigitalPin<PortC7> D30;
        typedef DigitalPin<PortC6> D31;
        typedef DigitalPin<PortC5> D32;
        typedef DigitalPin<PortC4> D33;
        typedef DigitalPin<PortC3> D34;
        typedef DigitalPin<PortC2> D35;
        typedef DigitalPin<PortC1> D36;
        typedef DigitalPin<PortC0> D37;
        typedef DigitalPin<PortD7> D38;
        typedef DigitalPin<PortG2> D39;
        typedef DigitalPin<PortG1> D40;
        typedef DigitalPin<PortG0> D41;
        typedef DigitalPin<PortL7> D42;
        typedef DigitalPin<PortL6> D43;
        typedef DigitalPin<PortL5> D44; // TIMER5C
        typedef DigitalPin<PortL4> D45; // TIMER5B
        typedef DigitalPin<PortL3> D46; // TIMER5A
        typedef DigitalPin<PortL2> D47;
        typedef DigitalPin<PortL1> D48;
        typedef DigitalPin<PortL0> D49;

        /** spi **/
        typedef DigitalPin<PortB3> D50; // miso
        typedef DigitalPin<PortB2> D51; // mosi
        typedef DigitalPin<PortB1> D52; // sck
        typedef DigitalPin<PortB0> D53; // ss

        /** analog **/
        typedef DigitalPin<PortF0> D54; // A0
        typedef DigitalPin<PortF1> D55; // A1
        typedef DigitalPin<PortF2> D56; // A2
        typedef DigitalPin<PortF3> D57; // A3
        typedef DigitalPin<PortF4> D58; // A4
        typedef DigitalPin<PortF5> D59; // A5
        typedef DigitalPin<PortF6> D60; // A6
        typedef DigitalPin<PortF7> D61; // A7
        typedef DigitalPin<PortK0> D62; // A8
        typedef DigitalPin<PortK1> D63; // A9
        typedef DigitalPin<PortK2> D64; // A10
        typedef DigitalPin<PortK3> D65; // A11
        typedef DigitalPin<PortK4> D66; // A12
        typedef DigitalPin<PortK5> D67; // A13
        typedef DigitalPin<PortK6> D68; // A14
        typedef DigitalPin<PortK7> D69; // A15

    }
}

#endif
#endif
#endif
