#include "yaal/io.hh"
#include <util/delay.h>

using namespace yaal;


PortB1 button;

int main(void) {

    // setup
    button.mode = INPUT;

    for (;;) {
        // wait for button to be pressed
        if (!button) {
            // create temporary variable led
            auto led = button.reversed().as(OUTPUT);

            // put led on
            led = true;

            //_delay_ms(2000);

            // pin is set back to input here
        }
    }

    return 0;
}
