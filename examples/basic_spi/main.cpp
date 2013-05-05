#include <yaal/core.hh>
#include <yaal/io.hh>
#include <yaal/communication/spi.hh>

using namespace yaal;

SPI<PortD1, PortD2, PortD3, PortD0> spi;

void setup() {
    spi.setup();
}

void loop() {
    uint8_t value;

    // read
    value = spi.read<uint8_t>();
    // transfer
    value = spi.transfer(value);
    // write
    spi.write(value);
}
