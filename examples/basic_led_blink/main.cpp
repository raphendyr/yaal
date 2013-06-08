#include <yaal.hh>
#include <util/delay.h>

// simple delay method
void delay() { _delay_ms(800); }

using namespace yaal;


// For plain pin HIGH/true means 5V in pin
PortB1 redLed;

// For reversed pin HIGH/true means 0V in pin
Reversed<PortB2> grnLed;


void main() {

    // set pins in output mode
    redLed.mode = OUTPUT;
    grnLed.mode.output();

    for (;;) {
        // blink red
        redLed = HIGH;
        delay();
        redLed = LOW;
        delay();

        // blink green
        grnLed = true;
        delay();
        grnLed = false;
        delay();

        // blink both
        redLed.set();
        grnLed.set();
        delay();
        redLed.clear();
        grnLed.clear();
        delay();
    }
}
