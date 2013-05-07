#ifndef __YAAL_ARDUINO__PINOUT__LEONARDO__
#define __YAAL_ARDUINO__PINOUT__LEONARDO__ 1
#include "../../requirements.hh"
#ifdef __YAAL__

#ifndef __YAAL_ARDUINO__PINOUT__LOCK
# error "Do not include arduino pinouts for boards directly. Include yaal/arduino/pinout.hh instead."
#else

#include "../../io.hh"

namespace yaal {
    namespace arduino {

        // NUM_DIGITAL_PINS 24
        // NUM_ANALOG_PINS  12

        /** digital, low **/
        typedef DigitalPin<PortD2> D0;  // RXD1/INT2
        typedef DigitalPin<PortD3> D1;  // TXD1/INT3
        typedef DigitalPin<PortD1> D2;  // SDA/INT1
        typedef DigitalPin<PortD0> D3;  // OC0B/SCL/INT0 - pwm8
        typedef DigitalPin<PortD4> D4;  // ADC8 - A6
        typedef DigitalPin<PortC6> D5;  // OC3A/#OC4A - pwm???
        typedef DigitalPin<PortD7> D6;  // #OC4D/ADC10 - A7 - fastpwm
        typedef DigitalPin<PortE6> D7;  // INT6/AIN0

        /** digital, high **/
        typedef DigitalPin<PortB4> D8;  // ADC11/PCINT4 - A8
        typedef DigitalPin<PortB5> D9;  // OC1A/#OC4B/ADC12/PCINT5 - A9 - pwm16
        typedef DigitalPin<PortB6> D10; // OC1B/0c4B/ADC13/PCINT6 - A10 - pwm16
        typedef DigitalPin<PortB7> D11; // 0C0A/OC1C/#RTS/PCINT7 - pwm8/16
        typedef DigitalPin<PortD6> D12; // T1/#OC4D/ADC9 - A 11
        typedef DigitalPin<PortC7> D13; // CLK0/OC4A - pwm10

        /** spi **/
        typedef DigitalPin<PortB3> D14; // MISO,PCINT3
        typedef DigitalPin<PortB1> D15; // SCK,PCINT1
        typedef DigitalPin<PortB2> D16; // MOSI,PCINT2
        typedef DigitalPin<PortB0> D17; // RXLED,SS/PCINT0

        /** analog **/
        typedef DigitalPin<PortF7> D18; // ADC7 - A0
        typedef DigitalPin<PortF6> D19; // ADC6 - A1
        typedef DigitalPin<PortF5> D20; // ADC5 - A2
        typedef DigitalPin<PortF4> D21; // ADC4 - A3
        typedef DigitalPin<PortF1> D22; // ADC1 - A4
        typedef DigitalPin<PortF0> D23; // ADC0 - A5

        // PortD5 - TXLED
        // PortE2 - HWB
    }
}

#endif
#endif
#endif
