#include "testing.hh"
#include <yaal/io/types/port.hh>
#include <yaal/io/types/maskedport.hh>

using namespace yaal;
using namespace std;

#define pin  REG0
#define ddr  REG1
#define port REG2

typedef Register<ADDR(port), uint8_t> port_reg;
typedef Register<ADDR(ddr), uint8_t> ddr_reg;
typedef Register<ADDR(pin), uint8_t> pin_reg;
typedef Port<port_reg, ddr_reg, pin_reg, 0xff> TestPort;
MaskedPort<TestPort, 0xf0> maskedport;

int main() {
    test_reg_start();

    uint8_t port_ref, ddr_ref;

    // set
    port = 0;
    port_ref = 7 << 4;
    maskedport = 7;
    EQ(port, port_ref);

    // get
    pin = 9 << 4;
    uint8_t get_in = maskedport;
    EQ(get_in, 9);

    // direction
    ddr = 0;
    ddr_ref = 0xf0;
    maskedport.set_output();
    EQ(ddr, ddr_ref);

    ddr = 0xff;
    ddr_ref = 0x0f;
    maskedport.set_input();
    EQ(ddr, ddr_ref);

    return 0;
}
