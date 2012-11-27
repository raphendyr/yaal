#include "cpu.hh"
#include "../qualifiers.hh"

    /* Prototypes */

namespace yaal {

    void pre_init() __attribute__ ((naked, section(".init3"), weak));

    void cpu_init() __attribute__ ((naked, section(".init5"), weak));

    void hardware_init() __attribute__ ((naked, section(".init7"), weak));

    // FIXME: not working. see init.hh
    //void init() __attribute__ ((naked, section(".init8")));

}

// FIXME: not working. see init.hh

//void setup() __attribute__ ((weak));

//void loop() __attribute__ ((weak));

//void main() __attribute__((noreturn, weak));


    /* Implementation */

void yaal::pre_init() {
    cpu.prescaler = Cpu::CPU_SLOW;
}

void yaal::cpu_init() {
    cpu.prescaler = Cpu::Prescaler::FULL_SPEED;
}

void yaal::hardware_init() { }

/* FIXME: not workin. see init.hh
void yaal::init() {
    setup();
}
*/

//void setup() { }

//void loop() { }

/*
void main() {
    for (;;) {
        loop();
    }
}
*/
