#include <yaal/arduino.hh>
#include <util/delay.h>

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

