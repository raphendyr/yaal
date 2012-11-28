#include "yaal/core.hh"
#include "yaal/io.hh"
#include "yaal/communication/spi.hh"
#include <util/delay.h>

using namespace yaal;

SPI<PortD1, PortD2, PortD3, PortD0> spi;

void main() {

    spi.setup();

    uint8_t value;

    // read
    value = spi.read<uint8_t>();
    // transfer
    value = spi.transfer(value);
    // write
    spi.write(value);

}
