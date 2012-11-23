// there is no better infrastructure for this yet
#define ARDUINO_teensy

#include "yaal/arduino.hh"
#include "yaal/devices/rgbled.hh"
#include "yaal/communication/spi.hh"
#include <util/delay.h>

using namespace yaal;
using namespace yaal::arduino;

union uint16_u {
    uint16_t value;
    uint8_t arr[2];
};


BasicRGBLed<D1, D2, D0> rgb;

typedef D21 Latch;
typedef D18 Data;
typedef D15 Clock;

SPI<Clock, Data, NullPin, Latch> spi;

Latch latch;
Data data;
Clock clock;

void write(uint16_t value) {
    uint16_u v;
    v.value = value;
    rgb.red();
    latch = true;
    spi.write(v.arr[0]);
    spi.write(v.arr[1]);
    latch = false;
    rgb.off();
}



int main(void) {

    // initialize
    rgb.setup();
    spi.setup();


    // loop
    for (;;) {
        uint16_t v = 7;
        uint16_t d = 400;
        for (uint8_t i = 0; i < 16; i++) {
            write(v);
            _delay_ms(d);
            d -= 20;
            v <<= 1;
        }
    }

    return 0;
}
