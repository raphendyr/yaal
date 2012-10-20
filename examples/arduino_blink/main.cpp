// there is no better infrastructure for this yet
#define ARDUINO_teensy

#include "yaal/arduino.hh"
#include <util/delay.h>


using namespace yaal;
using namespace yaal::arduino;

D5 button;
D6 led;

int main(void) {

    led.mode = OUTPUT;
    button.mode = INPUT_PULLUP;

    for (;;) {
        if (button) {
            led = HIGH;
            _delay_ms(800);
            led = LOW;
        }
        _delay_ms(800);
    }

    return 0;
}