Yet another AVR Abstraction Library
===================================

Or yet another AVR Library

We are in **experimental** state.

About
-----

Trying to make avr coding super easy. Result should be able to replace arduino library in usability.

    #include <yaal/io.hh>

    PortB3 led;

    void main() {
      led.output();
      
      for (;;) {
        led.on();
        delay_ms(1000);
        led.off();
        delay_ms(1000);
      }
    }

Or in arduino style:

    #include <yaal/arduino.hh>

    D6 led;

    void setup() {
      led.output();
    }

    void loop() {
      led.on();
      delay_ms(1000);
      led.off();
      delay_ms(1000);
    }

Those are mainly for directions, but for working examples look into *examples* directory.

License and using
-----------------

There is no known license in use yet. For now you are allowed to develop, test and contribute to this project.

If you would like to use this project for any commercial use, contact me and we will sort out what type of licensing we are going to use.

Also if you happen to use this project for something, please inform us via email or issue so we can get some feedback how this project worked for you.