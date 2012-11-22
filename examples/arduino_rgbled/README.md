# RGB LED example

Here is small tested example with rgb led. I also recorded a [video](http://youtu.be/Wlprih0-diM). There is no much in it, but it shows that code works.

I connected RGB LED module to my Teensy 2.0 directly. So the pins I'm using are:

 - D0/PortB0 for blue
 - D1/PortB1 for red
 - D2/PortB2 for green

Template class SimpleRGBLed has methods for all colors whih can be made using digital pins and the led. When PWM is in yaal we can create full color space class for rgb leds.

Look into [main.cc] for the code.
