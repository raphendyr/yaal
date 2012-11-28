// there is no better infrastructure for this yet
#define ARDUINO_teensy

#include "yaal/arduino.hh"
#include "yaal/communication/spi.hh"
#include <util/delay.h>

using namespace yaal;
using namespace yaal::arduino;

typedef D21 Latch;
typedef D18 Data;
typedef D15 Clock;

SPI<Clock, Data, NullPin, Latch> spi;

void setup() {
    spi.setup();
}

void loop() {
    uint16_t value = 7;
    for (uint8_t i = 0; i < 26; i++) {
        spi.write(value);
        if (i < 13)
            value <<= 1;
        else
            value >>= 1;
        _delay_ms(50);
    }
}
