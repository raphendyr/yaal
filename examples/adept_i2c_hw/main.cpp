#include <yaal/core.hh>
#include <yaal/communication/i2c_hw.hh>
#include <yaal/io/ports.hh>
#include <avr/delay.h>

using namespace yaal;

PortC4 sda;
PortC5 scl;

void main() {
        sda.mode = INPUT_PULLUP;
        scl.mode = INPUT_PULLUP;
        sei();

        _delay_ms(1000);

        I2c_HW.setup();
        I2c_HW.write(0x27, 0xf0);
        uint8_t c = I2c_HW.read(0x27);
}
