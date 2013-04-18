#define YAAL_SMALL_REG_SIZE unsigned long long
#define YAAL_BIG_REG_SIZE unsigned long long

#include "yaal/io/types/port.hh"
using namespace yaal;

#include <cstdint>
#include <iostream>
#include <assert.h>
using namespace std;

volatile uint8_t port;
volatile uint8_t ddr;
volatile uint8_t pin;

/* XXX: when ever you edit this code, set reg_start to printed reg_start */
constexpr unsigned long long reg_start = 0x6015b4;

typedef Register<reg_start, uint8_t> port_reg;
typedef Register<reg_start + 1, uint8_t> ddr_reg;
typedef Register<reg_start + 2, uint8_t> pin_reg;

int main(void) {
    if (reg_start != (unsigned long long)&port)
        cout << "FIXME: ";
    cout << "reg_start = 0x" << hex << (long long)&port << endl;

    Port<port_reg, ddr_reg, pin_reg, 0xff> the_port;

    port = 0x01;
    ddr = 0x02;
    pin = 0x03;

    // set
    the_port = 0x40;
    cout << "assert(0x" << hex << (int)port << " == 0x40);" << endl;
    assert(port == 0x40);

    // get
    uint8_t get_in = static_cast<uint8_t>(the_port);
    cout << "assert(0x" << hex << (int)get_in << " == 0x" << hex << (int)pin << ");" << endl;
    assert(get_in == pin);
}
