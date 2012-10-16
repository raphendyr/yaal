#ifndef __YAAL_QUALIFIERS__
#define __YAAL_QUALIFIERS__ 1

#define YAAL_DEPRECATED(msg) \
    __attribute__ ((deprecated(msg)))

#define YAAL_INLINE(title) \
    inline __attribute__ ((always_inline, error(title " not inlined")))

#endif
