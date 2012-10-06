Yet another AVR Abstraction Library
===================================

Or yet another AVR Library

We are in **experimental** state.

About
-----

Trying to make avr coding super easy. Result should be able to replace arduino library in usability.

     #include <yaal/io>

     PortB3 led;

     loop() {
       led.on();
     }

Or:

     #include <yaal/arduino>

     D1 led;

    loop() {
      led.on();
    }
