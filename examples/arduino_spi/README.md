# Software SPI usage example

Here is small tested example with software spi. I also recorded a [video](http://www.youtu.be/JA36vrK20GQ).

I have 2 shift registers (HEF4794B) connecting 16 leds. I send 16 bit int over spi to those.

Look into [main.cpp](https://github.com/raphendyr/yaal/blob/master/examples/arduino_spi/main.cpp) for the code.

Code will compile to size of 322 bytes on flash and 0 bytes on RAM.
