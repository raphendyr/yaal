#ifndef __YAAL_MACRO__COMMON_h__
#define __YAAL_MACRO__COMMON_h__ 1

// orginally from: avr-include/stdint.h
#ifndef __CONCAT
#  define __CONCATenate(left, right) left ## right
#  define __CONCAT(left, right) __CONCATenate(left, right)
#endif

// orginally from: avr-include/avr/interrupt.h
#ifndef __STRINGIFY
#  define __STRINGIFY2(x) #x
#  define __STRINGIFY(x) __STRINGIFY2(x)
#endif

#endif
