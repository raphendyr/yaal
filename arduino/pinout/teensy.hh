#ifndef __YAAL_ARDUINO__PINOUT__TEENSY__
#define __YAAL_ARDUINO__PINOUT__TEENSY__ 1

#ifndef __YAAL_ARDUINO__PINOUT__
# error "Do not include arduino pinouts for boards directly. Include yaal/arduino/pinout.hh instead."
#else

#include "../../io.hh"

namespace yaal {
    namespace arduino {


// MCU=atmega32u4 -- Teensy 2.0
#if defined(__AVR_ATmega32U4__)

// left side (top to bottom)
typedef DigitalPin<PortB0> D0;
typedef DigitalPin<PortB1> D1;
typedef DigitalPin<PortB2> D2;
typedef DigitalPin<PortB3> D3;
typedef DigitalPin<PortB7> D4;  // pwm
typedef DigitalPin<PortD0> D5;  // pwm
typedef DigitalPin<PortD1> D6;
typedef DigitalPin<PortD2> D7;  // rx
typedef DigitalPin<PortD3> D8;  // tx
typedef DigitalPin<PortC6> D9;  // pwm
typedef DigitalPin<PortC7> D10; // pwm

// right side (top to bottom)
typedef DigitalPin<PortF0> D21;
typedef DigitalPin<PortF1> D20;
typedef DigitalPin<PortF4> D19;
typedef DigitalPin<PortF5> D18;
typedef DigitalPin<PortF6> D17;
typedef DigitalPin<PortF7> D16;
typedef DigitalPin<PortB6> D15; // pwm
typedef DigitalPin<PortB5> D14; // pwm
typedef DigitalPin<PortB4> D13;
typedef DigitalPin<PortD7> D12; // pwm
typedef DigitalPin<PortD6> D11; // led

// bottom and interior
typedef DigitalPin<PortD4> D22;
typedef DigitalPin<PortD5> D23;
typedef DigitalPin<PortE6> D24;

// analog (right side)
/* TODO:
typedef AnalogPin<Adc0>  A0;
typedef AnalogPin<Adc1>  A1;
typedef AnalogPin<Adc4>  A2;
typedef AnalogPin<Adc5>  A3;
typedef AnalogPin<Adc6>  A4;
typedef AnalogPin<Adc7>  A5;
typedef AnalogPin<Adc13> A6;
typedef AnalogPin<Adc12> A7;
typedef AnalogPin<Adc11> A8;
typedef AnalogPin<Adc10> A9;
typedef AnalogPin<Adc9>  A10;
typedef AnalogPin<Adc8>  A11;
*/



// MCU=at90usb1286 -- Teensy++ 2.0
#elif defined(__AVR_AT90USB1286__)

// left side (top to bottom)
typedef DigitalPin<PortB7> D27; // pwm
typedef DigitalPin<PortD0> D0;  // pwm
typedef DigitalPin<PortD1> D1;  // pwm
typedef DigitalPin<PortD2> D2;  // rx
typedef DigitalPin<PortD3> D3;  // tx
typedef DigitalPin<PortD4> D4;
typedef DigitalPin<PortD5> D5;
typedef DigitalPin<PortD6> D6;  // led
typedef DigitalPin<PortD7> D7;
typedef DigitalPin<PortE0> D8;
typedef DigitalPin<PortE1> D9;
typedef DigitalPin<PortC0> D10;
typedef DigitalPin<PortC1> D11;
typedef DigitalPin<PortC2> D12;
typedef DigitalPin<PortC3> D13;
typedef DigitalPin<PortC4> D14; // pwm
typedef DigitalPin<PortC5> D15; // pwm
typedef DigitalPin<PortC6> D16; // pwm
typedef DigitalPin<PortC7> D17;

// right side (top to bottom)
typedef DigitalPin<PortB6> D26; // pwm
typedef DigitalPin<PortB5> D25; // pwm
typedef DigitalPin<PortB4> D24; // pwm
typedef DigitalPin<PortB3> D23;
typedef DigitalPin<PortB2> D22;
typedef DigitalPin<PortB1> D21;
typedef DigitalPin<PortB0> D20;
typedef DigitalPin<PortE7> D19;
typedef DigitalPin<PortE6> D18;
// GND
// AREF
typedef DigitalPin<PortF0> D38;
typedef DigitalPin<PortF1> D39;
typedef DigitalPin<PortF2> D40;
typedef DigitalPin<PortF3> D41;
typedef DigitalPin<PortF4> D42;
typedef DigitalPin<PortF5> D43;
typedef DigitalPin<PortF6> D44;
typedef DigitalPin<PortF7> D45;

// interior (top to bottom, right to left)
typedef DigitalPin<PortA0> D28;
typedef DigitalPin<PortA1> D29;
typedef DigitalPin<PortA2> D30;
typedef DigitalPin<PortA3> D31;
typedef DigitalPin<PortA4> D32;
typedef DigitalPin<PortA5> D33;
typedef DigitalPin<PortA6> D34;
typedef DigitalPin<PortA7> D35;

// analog (right side)
/* TODO:
typedef AnalogPin<Adc0> A0;
typedef AnalogPin<Adc1> A1;
typedef AnalogPin<Adc2> A2;
typedef AnalogPin<Adc3> A3;
typedef AnalogPin<Adc4> A4;
typedef AnalogPin<Adc5> A5;
typedef AnalogPin<Adc6> A6;
typedef AnalogPin<Adc7> A7;
*/



// MCU=at90usb162 -- Teensy 1.0
#elif defined(__AVR_AT90USB162__)
# error "Teensy 1.0 is not yet supported"



// MCU=at90usb646 -- Teensy++ 1.0
#elif defined(__AVR_AT90USB646__)
# error "Teensy++ 1.0 is not yet supported"



#endif


    }
}

#endif
#endif
