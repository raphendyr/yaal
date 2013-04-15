#ifndef __YAAL_CORE__FINISH__
#define __YAAL_CORE__FINISH__ 1
#include "../requirements.hh"
#ifdef __YAAL__

/* Sections:
 * src: http://www.nongnu.org/avr-libc/user-manual/mem_sections.html
 *
 * The .finiN sections are executed in descending order from 9 to 0.
 *
 * .fini9:
 *   Unused. User definable. This is effectively where _exit() starts.
 *
 * .fini8:
 *   Unused. User definable.
 *
 * .fini7:
 *  Unused. User definable.
 *
 * .fini6:
 *   Unused for C programs, but used for destructors in C++ programs.
 *
 * .fini5:
 *   Unused. User definable.
 *
 * .fini4:
 *   Unused. User definable.
 *
 * .fini3:
 *   Unused. User definable.
 *
 * .fini2:
 *   Unused. User definable.
 *
 * .fini1:
 *   Unused. User definable.
 *
 * .fini0:
 *   Goes into an infinite loop after program termination and completion
 *   of any _exit() code (execution of code in ithe .fini9 -> .fini1 sections).
 */

namespace yaal {
}

#endif
#endif
