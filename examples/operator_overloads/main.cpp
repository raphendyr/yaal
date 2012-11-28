#include "yaal/core.hh"
#include "yaal/io.hh"
#include <util/delay.h>

using namespace yaal;

PortB ledMatrixRow;
PortB1 led;

void main() {

    ledMatrixRow = 0xff;
    ledMatrixRow &= 0xf0;
    ledMatrixRow |= 0x0f;
    ledMatrixRow += 1;
    ledMatrixRow -= 2;
    ledMatrixRow *= 2;

    uint8_t value = ledMatrixRow;

    for (;;) {
        led = true;
        //_delay_ms(800);
        led = false;
        //_delay_ms(800);
    }

}
