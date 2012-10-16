// there is no better infrastructure for this yet
#define ARDUINO_teensy

#include "yaal/arduino.hh"
#include <util/delay.h>


using namespace yaal::arduino;

D6 led;

int main(void) {

    for (;;) {
        led.set();
        _delay_ms(800);
        led.clear();
        _delay_ms(800);
    }

}
