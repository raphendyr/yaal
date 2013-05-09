#include "../requirements.hh"
#ifdef __YAAL__

#define __YAAL_CORE__INIT_C__ 1
#include "cpu.hh"
#include "init.hh"

#if !( defined(F_CLOCK) && defined(F_CPU) )
#  warning yaal/core/init.o does NOT set cpu prescaler as one or both of F_CLOCK, F_CPU is not defined.
#endif

void yaal::pre_init() {
#if defined(F_CLOCK) && defined(F_CPU)
    cpu.prescaler = Cpu::CPU_SLOW;
#endif
}

void yaal::cpu_init() {
#if defined(F_CLOCK) && defined(F_CPU)
    cpu.speed = F_CPU;
#endif
}

void yaal::hardware_init() { }


void setup() { }

void loop() { }

void main() {
    for (;;) {
        loop();
    }
}

#endif
