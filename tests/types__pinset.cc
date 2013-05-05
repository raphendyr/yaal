#include "testing.hh"
#include <yaal/types/pinset.hh>

using namespace yaal;
using namespace std;


/* XXX: when ever you edit this code, set reg_start to printed reg_start */
constexpr unsigned long long reg_start = 0x6023f4;

volatile uint8_t port;
volatile uint8_t ddr;
volatile uint8_t pin;

typedef Register<reg_start, uint8_t> port_reg;
typedef Register<reg_start + 1, uint8_t> ddr_reg;
typedef Register<reg_start + 2, uint8_t> pin_reg;

typedef Port<port_reg, ddr_reg, pin_reg> TPort;
typedef Pin<TPort, 0> TPin0;
typedef Pin<TPort, 1> TPin1;
typedef Pin<TPort, 2> TPin2;
typedef Pin<TPort, 3> TPin3;
typedef Pinset<TPin3, TPin2, TPin1, TPin0> TPinsetR;
typedef Pinset<TPin0, TPin1, TPin2, TPin3> TPinset;


int main(void) {
    if (reg_start != (unsigned long long)&port) {
        cout << "FIXME: reg_start = 0x" << hex << (long long)&port << endl;
        return 255;
    }

    TPinset test;
    TPinsetR test2;
    uint8_t port_ref/*, ddr_ref, pin_ref*/;

    EQ(TPinset::size, 4);
    EQ(test.size, 4);


    OPER(test, port_ref, =, 0x0f);
    EQ(port, port_ref);

    OPER(test2, port_ref, =, 0x01);
    port_ref = 0x08;
    EQ(port, port_ref);

    return 0;
}
