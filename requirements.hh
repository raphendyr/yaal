#ifndef __YAAL_REQUIREMENTS_H__
#define __YAAL_REQUIREMENTS_H__ 1

// This is c++ code, need c++ compiler
#if !defined(__cplusplus)
#  error  "This is c++ header. gnu c++ is required."

// require gnu gcc
#elif !defined(__GNUC__)
#  error  "GNU gcc is required. If this source can be build using other tools, please submit pull request."

// check gcc is atleast 4.6.0
#elif __GNUC__ < 4 || ( __GNUC__ == 4 && __GNUC_MINOR__ < 6 )
#  error  "GNU 4.6+ is required."

// requirements are ok
#else
#  define __YAAL__ 1

// common includes
#  include <stdint.h>
#  include "common_macros.hh"
#  include "qualifiers.hh"

// Fixes for avr gcc library
//  Allow debrecated macros (Some debrecated macros are used inside #ifdef in io/registers)
#define __AVR_LIBC_DEPRECATED_ENABLE__ 1

// end requirements block
#endif

#endif
