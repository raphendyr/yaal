#include "yaal/io.hh"
#include <util/delay.h>

using namespace yaal;

PortB1 led;

int main(void) {

    while (1) {
        led.set();
        _delay_ms(800);
        led.clear();
        _delay_ms(800);
    }

    return 0;
}
