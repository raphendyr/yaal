#ifndef __YAAL_COMMON_MACROS__
#define __YAAL_COMMON_MACROS__ 1

// src: avr-include/stdint.h
#ifndef __CONCAT
#  define __CONCATenate(left, right) left ## right
#  define __CONCAT(left, right) __CONCATenate(left, right)
#endif

// src: avr-include/avr/interrupt.h
#ifndef __STRINGIFY
#  define __STRINGIFY(x) #x
#endif

#endif
