#include "yaal/atomic.hh"
#include <util/atomic.h>

#include "yaal/io.hh"

using namespace yaal;

PortB data;

int main(void) {

    sei();

    // C style
    uint8_t local_data;
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        local_data = data;
    }
    data = 0x01;

    // C++ style based on RAII
    {
        Atomic block;
        local_data = data;
    }
    data = 0x02;

    cli();

    return 0;
}
