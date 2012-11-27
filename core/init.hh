#ifndef __YAAL_CORE__INIT__
#define __YAAL_CORE__INIT__ 1

#include "../qualifiers.hh"

/* Sections:
 * src: http://www.nongnu.org/avr-libc/user-manual/mem_sections.html
 *
 * The .initN sections are executed in order from 0 to 9.
 *
 * .init0:
 *   Weakly bound to __init(). If user defines __init(),
 *   it will be jumped into immediately after a reset.
 *
 * .init1:
 *   Unused. User definable.
 *
 * .init2:
 *   In C programs, weakly bound to initialize the stack,
 *   and to clear __zero_reg__ (r1).
 *
 * .init3:
 *   Unused. User definable.
 *
 * .init4:
 *   For devices with > 64 KB of ROM, .init4 defines the
 *   code which takes care of copying the contents of .data
 *   from the flash to SRAM. For all other devices, this
 *   code as well as the code to zero out the .bss section
 *   is loaded from libgcc.a.
 *
 * .init5:
 *   Unused. User definable.
 *
 * .init6:
 *   Unused for C programs, but used for constructors
 *   in C++ programs.
 *
 * .init7:
 *   Unused. User definable.
 *
 * .init8:
 *   Unused. User definable.
 *
 * .init9:
 *   Jumps into main().
 */

namespace yaal {

    extern void pre_init() __attribute__ ((naked, section(".init3")));

    extern void cpu_init() __attribute__ ((naked, section(".init5")));

    extern void hardware_init() __attribute__ ((naked, section(".init7")));

    // FIXME: no need if weak setup / loop does't work
    //extern void init() __attribute__ ((naked, section(".init8")));

}

// FIXME: no idea howto get weak setup / loop to inline into main

//extern void setup();

//extern void loop();

//extern void main() __attribute__((noreturn));

#endif
