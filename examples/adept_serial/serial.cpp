#include <yaal/core.hh>
#include <yaal/io/serial.hh>

using namespace yaal;

Serial0 serial;

void setup() {
    serial.setup(9600, DATA_EIGHT, STOP_ONE, PARITY_EVEN);
}

void loop() {
    // Transmit one byte.
    serial.put('A');

    // Transmit two bytes using the template transmit function.
    autounion<uint16_t> bytes;
    bytes[0] = 'B';
    bytes[1] = 'C';
    serial.write(bytes);

    // Receive, throw away the result.
    uint8_t reply = serial.get();
    uint16_t data;
    serial.read(data); // read by reference.
    // There is no 'uint16_t data = serial.read();' as it wouldn't work as you
    // expect in 'uint16_t foo = 0xffffffff & serial.read();' you would need
    // to use 'serial.read<uint32_t>();' in above case.

    // Transmit one more byte to indicate success.
    serial.put('D');
}
