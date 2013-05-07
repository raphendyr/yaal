#include <yaal/arduino.hh>
#include <util/delay.h>

D1 clock;
D2 data;

void loop() {

    uint8_t value = shiftIn(clock, data);
    shiftOut(clock, data, value);

}
