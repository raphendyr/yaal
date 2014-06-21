#include <yaal.hh>
#include <yaal/io/spi.hh>

using namespace yaal;

//SPI<PortD1, PortD2, PortD3, PortD0> spi;
HWSPI hwspi;

void setup() {
    //spi.setup();
    hwspi.setup();
}

void loop() {
    uint8_t value;

    // read
    //value = spi.read<uint8_t>();
    // transfer
    //value = spi.transfer(value);
    // write
    //spi.write(value);


    value = hwspi.transfer(value);
}
