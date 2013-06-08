#include <util/delay.h>
#include <yaal.hh>

using namespace yaal;

class Foo {
public:
    PortB1 led;

    void setup() {
        led.mode = OUTPUT;
    }

    void isr()
    {
        led.toggle();
    }
} foo;

// Basic ISR mapping
ISR(INT1_vect) { foo.isr(); }

void setup() {
    foo.setup();
}
