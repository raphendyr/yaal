#include "io.hh"

using namespace yaal;

PortB1 led;

int main(void) {

    while (1) {
        led.set();
        led.clear();
    }

}