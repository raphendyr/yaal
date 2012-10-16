// there is no better infrastructure for this yet
#define ARDUINO_teensy

#include "yaal/arduino.hh"
#include <util/delay.h>


using namespace yaal::arduino;

D5 button;
D6 led;

int main(void) {

    led.output();
    button.input();

    for (;;) {
        if (button) {
            led.set();
            _delay_ms(800);
            led.clear();
        }
        _delay_ms(800);

        // arduino compatibility

        if (digitalRead(button)) {
            digitalWrite(led, true);
            _delay_ms(800);
            digitalWrite(led, false);
        }
        _delay_ms(800);
    }

    return 0;
}
