#include <yaal.hh>

using namespace yaal;

Serial0 serial;

void setup() {
    serial.setup(9600, DATA_EIGHT, STOP_ONE, PARITY_EVEN);
}

void loop() {
    // Transmit one byte.
    serial << 'A' << endl;

    // Transmit two bytes using uint16_t
    uint16_t bytes1 = 16963;
    serial << bytes1 << endl;
    // Same using autounion
    autounion<uint16_t> bytes2;
    bytes2[0] = 'B';
    bytes2[1] = 'C';
    serial << bytes2 << endl;
    // When you use autounion, give the parameter as is without calling value()

    // Receive, throw away the result.
    uint8_t reply;
    serial >> reply;
    uint16_t data;
    serial >> data;

    // Transmit one more byte to indicate success.
    serial << 'D' << endl;

    serial << "foobar" << endl;
}
