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
    // 200kHz -> 128kHz with 16MHz clock and 156kHz with 20MHz clock
    cpu.clock = khz(200);
#endif
}

void yaal::cpu_init() {
#if defined(F_CLOCK) && defined(F_CPU)
    // Set 'full' speed
    cpu.clock = F_CPU;
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
