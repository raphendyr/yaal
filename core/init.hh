#ifndef __YAAL_CORE__INIT__
#define __YAAL_CORE__INIT__ 1
#include "../requirements.hh"
#ifdef __YAAL__

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

#ifdef __YAAL_CORE__INIT_C__
#  define EXTERN
#  define SECTION(s) __attribute__ ((naked, section(s), used, weak))
#  define NORETURN __attribute__ ((noreturn, used, weak))
#  define WEAK __attribute__ ((weak))
#else
#  define EXTERN extern
#  define SECTION(s) __attribute__ ((naked, section(s), used))
#  define NORETURN __attribute__ ((noreturn, used))
#  define WEAK
#endif


#ifndef YAAL_NO_INIT

namespace yaal {

    EXTERN void pre_init() SECTION(".init3");

    EXTERN void cpu_init() SECTION(".init5");

    EXTERN void hardware_init() SECTION(".init7");

}

// dummy implementations of setup and loop in init.cc
EXTERN void setup() SECTION(".init8");

EXTERN void loop() WEAK;

#endif // !defined(YAAL_NO_INIT)

// dummy implementation of main in init.cc, but it's ok to be left here anycase
EXTERN void main() NORETURN;



#undef EXTERN
#undef SECTION
#undef NORETURN
#undef WEAK

#endif
#endif
