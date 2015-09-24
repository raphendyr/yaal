#include <yaal.hh>
#include <yaal/io/spi.hh>

using namespace yaal;

//SPI<PortD1, PortD2, PortD3, PortD0> spi;
HWSPI spi;
HWSPI.Device<PortC1> dev;

void setup() {
    //spi.setup();
    hwspi.setup();
}

void loop() {
    uint8_t value1 = 1, value2;

    // read
    //value = spi.read<uint8_t>();
    // transfer
    //value = spi.transfer(value);
    // write
    //spi.write(value);

    hwspi.sequence() << (uint8_t)0x01 >> value1 >> value2;
    hwspi.sequence() << (value1 + value2);
}
