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
}

#endif
