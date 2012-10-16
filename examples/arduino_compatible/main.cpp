/*** Don't mide this start crap. Arduino IDE would hide it. ***/

// there is no better infrastructure for this yet
#define ARDUINO_teensy

#include <util/delay.h>

#include "yaal/arduino.hh"
#include "yaal/setup_and_loop.hh"

// FIXME: these should not be needed
using namespace yaal;
using namespace yaal::arduino;


/*** Arduino like code starts here ***/
// FIXME: create delay() based on _delay_ms()

D5 button;
D6 led;


void setup() {
    pinMode(button, INPUT_PULLUP);
    pinMode(led, OUTPUT);
}

void loop() {
    if (digitalRead(button)) {
        digitalWrite(led, HIGH);
        _delay_ms(800);
        digitalWrite(led, LOW);
    }
    _delay_ms(800);
}

