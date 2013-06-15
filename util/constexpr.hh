#ifndef __YAAL_UTIL__CONSTEXPR__
#define __YAAL_UTIL__CONSTEXPR__ 1
#include "../requirements.hh"
#ifdef __YAAL__

#include "../types/traits.hh"

namespace yaal {

    /* count bits up */
    template<typename T>
    constexpr uint8_t bits_up_ce(T value) {
        return bits_up_ce<typename type_traits<T>::smaller>(value >> (type_traits<T>::bits/2)) +
               bits_up_ce<typename type_traits<T>::smaller>(value);
    }

    template<>
    constexpr uint8_t bits_up_ce<uint8_t>(uint8_t value) {
        return !!(value & 0x80) + !!(value & 0x40) + !!(value & 0x20) + !!(value & 0x10) +
               !!(value & 0x08) + !!(value & 0x04) + !!(value & 0x02) + !!(value & 0x01);
    }


    /* find first set */
    template<typename T>
    constexpr uint8_t ffs_ce(T value, uint8_t bit = 1) {
        return !value ? 0 : ( value & (1 << (bit-1)) ? bit : ffs_ce(value, bit + 1) );
    }


    /* max */
    template<typename T>
    constexpr T max_ce(T left, T right) {
        return (left > right) ? left : right;
    }

    /* min */
    template<typename T>
    constexpr T min_ce(T left, T right) {
        return (left < right) ? left : right;
    }

    /* all */
    template< typename T >
    constexpr bool all_ce(T t) {
        return bool(t);
    }

    template< typename T, typename... Types >
    constexpr bool all_ce(T t, Types... types) {
        return t && all_ce(types...);
    }

    /* any */
    template< typename T >
    constexpr bool any_ce(T t) {
        return bool(t);
    }

    template< typename T, typename... Types >
    constexpr bool any_ce(T t, Types... types) {
        return t || any_ce(types...);
    }

}

#endif
#endif

