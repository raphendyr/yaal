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

    /* source for some of codes:
     * http://graphics.stanford.edu/~seander/bithacks.html
     */

    /* mod:
     * Compute modulus division by 1 << s without a division operator
     * FIXME: check for division instruction
     */
    /*
    mod(
    const unsigned int n;          // numerator
    const unsigned int s;
    const unsigned int d = 1U << s; // So d will be one of: 1, 2, 4, 8, 16, 32, ...
    unsigned int m;                // m will be n % d
    m = n & (d - 1);
    */

    /* log2:
     * Find the log base 2 of an integer with the MSB N set
     * in O(N) operations (the obvious way).
     *
     * The log base 2 of an integer is the same as the
     * position of the highest bit set (or most significant
     * bit set, MSB).
     */
    // FIXME: check that second one is faster
    template<typename T>
    YAAL_INLINE("log2")
    uint8_t log2_(T value) {
        uint8_t result = 0;
        for (; value >>= 1; result++);
        return result;
    }

    template<typename T>
    YAAL_INLINE("log2")
    uint8_t log2(T value) {
        constexpr uint8_t size = sizeof(T);
        uint8_t result = 0;

        if (size >= 4) // uint32_t
            if (value & 0xffff0000) {
                value >>= 16;
                result |= 16;
            }
        if (size >= 2) // uint32_t & uint16_t
            if (value & 0xff00) {
                value >>= 8;
                result |= 8;
            }
        if (value & 0xf0) {
            value >>= 4;
            result |= 4;
        }
        if (value & 0xc) {
            value >>= 2;
            result |= 2;
        }
        if (value & 0x2) {
            //value >>= 1;
            result |= 1;
        }

        return result + value;
    }

}

#endif
#endif
