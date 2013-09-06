#ifndef __YAAL_UTIL__BITOPERS__
#define __YAAL_UTIL__BITOPERS__ 1
#include "../requirements.hh"
#ifdef __YAAL__

namespace yaal {

    // NOTE: check std::ffs for first bit up

    YAAL_INLINE("bits_up")
    template<typename T>
    uint8_t bits_up(T value) {
        uint8_t count = 0;
        for (; value > 0; count++) {
            value = value & (value - 1);
        }
        return count;
    }

}

#endif
#endif
