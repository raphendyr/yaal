#include <yaal/core.hh>
#include <yaal/io.hh>
#include <util/delay.h>

//#define DL _delay_ms(800)
#define DL {}

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
        DL;
        redLed = LOW;
        DL;

        // blink green
        grnLed = true;
        DL;
        grnLed = false;
        DL;

        // blink both
        redLed.set();
        grnLed.set();
        DL;
        redLed.clear();
        grnLed.clear();
        DL;
    }
}
