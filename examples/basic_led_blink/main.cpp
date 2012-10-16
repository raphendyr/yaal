#include "yaal/io.hh"
#include <util/delay.h>

using namespace yaal;

PortB1 led;

#define dl _delay_ms(800)

int main(void) {

    led = OUTPUT;
    // or
    led.output();

    for (;;) {
        led = HIGH;
        dl;
        led = LOW;
        dl;

        // or

        led = true;
        dl;
        led = false;
        dl;

        // or

        led.set();
        dl;
        led.clear();
        dl;
    }

    return 0;
}
