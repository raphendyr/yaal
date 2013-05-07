#include <yaal/arduino.hh>
#include <util/delay.h>

D5 button;
D6 led;

void setup() {
    led.mode = OUTPUT;
    button.mode = INPUT_PULLUP;
}

void loop() {
    if (button) {
        led = HIGH;
        _delay_ms(800);
        led = LOW;
    }
    _delay_ms(800);
}
