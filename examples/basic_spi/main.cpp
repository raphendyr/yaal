#include <yaal.hh>

using namespace yaal;

SPI<PortD1, PortD2, PortD3, PortD0> spi;

void setup() {
    spi.setup();
}

void loop() {
    uint8_t value = 0;

    // read
    spi.chat() >> value;

    // write
    spi.chat() << value;

    // transfer
    {
        auto communication = spi.chat();
        value = communication.transfer(value);
    }
}
