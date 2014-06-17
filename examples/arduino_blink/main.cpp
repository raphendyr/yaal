#include <yaal/arduino.hh>
#include <util/delay.h>

D13 led;

void setup() {
    led.mode = OUTPUT;
}

void loop() {
    led = HIGH;
    _delay_ms(800);
    led = LOW;
    _delay_ms(800);
}
