#ifndef __YAAL_UTIL__MATH__
#define __YAAL_UTIL__MATH__ 1
#include "../requirements.hh"
#ifdef __YAAL__

namespace yaal {

    /* max */
    template<typename T>
    YAAL_INLINE("max")
    T max(T left, T right) {
        return (left > right) ? left : right;
    }

    /* min */
    template<typename T>
    YAAL_INLINE("min")
    T min(T left, T right) {
        return (left < right) ? left : right;
    }

}

#endif
#endif

