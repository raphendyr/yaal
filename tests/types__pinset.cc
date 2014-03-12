#include "testing.hh"
#include <yaal/types/pinset.hh>

using namespace yaal;
using namespace std;

#define pin  REG0
#define ddr  REG1
#define port REG2

typedef internal::Register<ADDR(port), uint8_t> port_reg;
typedef internal::Register<ADDR(ddr), uint8_t> ddr_reg;
typedef internal::Register<ADDR(pin), uint8_t> pin_reg;

typedef Port<port_reg, ddr_reg, pin_reg> TPort;
typedef Pin<TPort, 0> TPin0;
typedef Pin<TPort, 1> TPin1;
typedef Pin<TPort, 2> TPin2;
typedef Pin<TPort, 3> TPin3;
typedef Pinset<TPin3, TPin2, TPin1, TPin0> TPinsetR;
typedef Pinset<TPin0, TPin1, TPin2, TPin3> TPinset;


int main() {
    test_reg_start();

    TPinset test;
    TPinsetR test2;
    uint8_t port_ref, ddr_ref/*, pin_ref*/;

    // size
    cout << "size" << endl;
    EQ(TPinset::size, 4);
    EQ(test.size, 4);


    // set
    cout << "set" << endl;
    OPER(test, port_ref, =, 0x0f);
    EQ(port, port_ref);

    OPER(test2, port_ref, =, 0x01);
    port_ref = 0x08;
    EQ(port, port_ref);

    // get
    cout << "get" << endl;
    pin = 0x08;
    uint8_t val = test;
    EQ(val, 0x08);

    // output
    cout << "output" << endl;
    test.set_output();
    ddr_ref = 0xf;
    EQ(ddr, ddr_ref);

    // input
    cout << "input" << endl;
    test.set_input();
    ddr_ref = 0;
    EQ(ddr, ddr_ref);

    return 0;
}
