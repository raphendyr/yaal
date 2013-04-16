#include "yaal/io/serials.hh"

using namespace yaal;

int main() {
    Serial0 serial;

    // Initialization
    serial.setBaud(9600);
    serial.setFrameFormat(DATA_EIGHT, STOP_ONE, PARITY_EVEN);

    // Transmit one byte.
    serial.transmit('A');

    // Transmit two bytes using the template transmit function.
    autounion<uint16_t> bytes = 0;
    bytes[0] = 'B';
    bytes[1] = 'C';
    serial.transmit(bytes);

    // Receive, throw away the result.
    (void) serial.receive();

    // Transmit one more byte to indicate success.
    serial.transmit('D');

    return 0;
}
