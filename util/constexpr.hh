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

}

#endif
#endif

