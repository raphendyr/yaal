#define __YAAL_CORE__INIT_C__ 1

#include "cpu.hh"
#include "../qualifiers.hh"
#include "init.hh"


void yaal::pre_init() {
    cpu.prescaler = Cpu::CPU_SLOW;
}

void yaal::cpu_init() {
    cpu.prescaler = Cpu::Prescaler::FULL_SPEED;
}

void yaal::hardware_init() { }


void setup() { }

void loop() { }

void main() {
    for (;;) {
        loop();
    }
}
