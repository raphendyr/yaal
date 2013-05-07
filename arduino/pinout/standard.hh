#ifndef __YAAL_ARDUINO__PINOUT__STANDARD__
#define __YAAL_ARDUINO__PINOUT__STANDARD__ 1
#include "../../requirements.hh"
#ifdef __YAAL__

#ifndef __YAAL_ARDUINO__PINOUT__LOCK
# error "Do not include arduino pinouts for boards directly. Include yaal/arduino/pinout.hh instead."
#else

#include "../../io.hh"

namespace yaal {
    namespace arduino {

        // NUM_DIGITAL_PINS 20
        // NUM_ANALOG_PINS  6
        // all pins have PCINT

        /** left side (top to bottom) **/
        // PortC6 - reset
        typedef DigitalPin<PortD0> D0;
        typedef DigitalPin<PortD1> D1;
        typedef DigitalPin<PortD2> D2;
        typedef DigitalPin<PortD3> D3;  // pwm (not on atmega8)
        typedef DigitalPin<PortD4> D4;  // sda on fio (328p)
        // Vcc
        // GND
        // PortB6 - xtal1
        // PortB7 - xtal2
        typedef DigitalPin<PortD5> D5;  // pwm (not on atmega8), scl on fio (328p)
        typedef DigitalPin<PortD6> D6;  // pwm (not on atmega8)
        typedef DigitalPin<PortD7> D7;
        typedef DigitalPin<PortB0> D8;

        /** right side (top to bottom) **/
        typedef DigitalPin<PortC5> D19; // A5, SCL
        typedef DigitalPin<PortC4> D18; // A4, SDA
        typedef DigitalPin<PortC3> D17; // A3
        typedef DigitalPin<PortC2> D16; // A2
        typedef DigitalPin<PortC1> D15; // A1
        typedef DigitalPin<PortC0> D14; // A0
        // GND
        // Aref
        // AVcc
        typedef DigitalPin<PortB5> D13; // sck, led
        typedef DigitalPin<PortB4> D12; // miso
        typedef DigitalPin<PortB3> D11; // pwm, mosi
        typedef DigitalPin<PortB2> D10; // pwm, ss
        typedef DigitalPin<PortB1> D9;  // pwm

        /** extra analogs in eight analog versions **/
#       if defined(ARDUINO_eightanaloginputs)
        //typedef DigitalPin<Port> D20; // ADC6 - A6, there is no digital pin for ADC6
        //typedef DigitalPin<Port> D21; // ADC7 - A7, there is no digital pin for ADC7
#       endif

    }
}

#endif
#endif
#endif
