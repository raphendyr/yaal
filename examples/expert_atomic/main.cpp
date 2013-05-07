#include <yaal/core.hh>
#include <yaal/io.hh>
#include <yaal/atomic.hh>
#include <util/atomic.h>

using namespace yaal;

PortB data;

void setup() {
    sei();
}

void loop() {
    uint8_t local_data;

    // C style
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
}
