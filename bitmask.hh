#ifndef __YAAL__BITMASK__
#define __YAAL__BITMASK__ 1
#include "requirements.hh"
#ifdef __YAAL__

namespace yaal {

    // FIXME: left works only for uint8_t

    template<uint8_t bits_on, uint8_t pad = 0, typename T = uint8_t>
    struct BitMask {
        static constexpr T left = BitMask<bits_on - 1, pad, T>::left | (0x80 >> (bits_on + pad - 1));
        static constexpr T right = BitMask<bits_on - 1, pad, T>::right | (0x01 << (bits_on + pad - 1));
    };

    template<uint8_t pad, typename T>
    struct BitMask<1, pad, T> {
        static constexpr T left = 0x80 >> pad;
        static constexpr T right = 0x01 << pad;
    };
}

#endif
#endif
