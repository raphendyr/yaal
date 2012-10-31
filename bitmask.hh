#ifndef __YAAL__BITMASK__
#define __YAAL__BITMASK__ 1

#include <inttypes.h>

namespace yaal {

    template<uint8_t bits_on, uint8_t pad = 0>
    struct BitMask {
        static const uint8_t left = BitMask<bits_on - 1, pad>::left | (0x80 >> (bits_on + pad - 1));
        static const uint8_t right = BitMask<bits_on - 1, pad>::right | (0x01 << (bits_on + pad - 1));
    };

    template<uint8_t pad>
    struct BitMask<1, pad> {
        static const uint8_t left = 0x80 >> pad;
        static const uint8_t right = 0x01 << pad;
    };
}

#endif
