#ifndef __YAAL_MACRO__FUNCTION_ATTRIBUTES_h__
#define __YAAL_MACRO__FUNCTION_ATTRIBUTES_h__ 1

#define YAAL_DEPRECATED(msg) \
    __attribute__ (( __deprecated__(msg) ))

#define YAAL_INLINE(title) \
    __inline__ __attribute__ (( __always_inline__, __error__(title " not inlined") ))

#endif
