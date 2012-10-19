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
            // OutputPin initializes pin as output, and resets it back when block ends
            // FIXME: These are posibilities I found out
            _OutputPin(button) led;
            auto led(as_output(button));
            auto led = as_output(button);
            // FIXME: is this possible in any way?
            OutputPin led(button);

            // put led on
            led = LOW;

            _delay_ms(2000);

            // pin is set back to input here
        }

    }

    return 0;
}
