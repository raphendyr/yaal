#include "testing.hh"
#include <yaal/io/types/port.hh>

using namespace yaal;
using namespace std;

#define pin  REG0
#define ddr  REG1
#define port REG2

typedef Register<ADDR(port), uint8_t> port_reg;
typedef Register<ADDR(ddr), uint8_t> ddr_reg;
typedef Register<ADDR(pin), uint8_t> pin_reg;

int main() {
    test_reg_start();

    Port<port_reg, ddr_reg, pin_reg, 0xff> the_port;
    uint8_t port_ref, ddr_ref, pin_ref;

    OPER(port, port_ref, =, 0x01);
    OPER(ddr,  ddr_ref,  =, 0x00);
    OPER(pin,  pin_ref,  =, 0x02);

    // set
    OPER(port, port_ref, =, 0x44);
    EQ(port, port_ref);

    // |=
    OPER(the_port, port_ref, |=, 0x80);
    EQ(port, port_ref);

    // &=
    OPER(the_port, port_ref, &=, 0x0f);
    EQ(port, port_ref);

    // get
    uint8_t get_in = the_port;
    EQ(get_in, pin_ref);

    // direction
    the_port.set_output(); ddr_ref = 0xff;
    EQ(ddr, ddr_ref);
    the_port.set_input();  ddr_ref = 0;
    EQ(ddr, ddr_ref);


    return 0;
}
