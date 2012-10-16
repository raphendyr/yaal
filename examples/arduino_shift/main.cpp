// there is no better infrastructure for this yet
#define ARDUINO_teensy

#include "yaal/arduino.hh"
#include <util/delay.h>


using namespace yaal::arduino;

D1 clock;
D2 data;

int main(void) {

    uint8_t value = shiftIn(clock, data);
    shiftOut(clock, data, value);

    return 0;
}
