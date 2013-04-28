#ifndef __YAAL_TYPES__TRAITS__
#define __YAAL_TYPES__TRAITS__ 1
#include "../requirements.hh"
#ifdef __YAAL__

namespace yaal {

    namespace internal {
        // base_type_traits contains everything about all types
        // this struct's values should be overwritten when known better
        template<typename T>
        struct base_type_traits {
            typedef T bigger;
            typedef T smaller;
            static constexpr bool biggest = false;
            static constexpr bool smallest = false;
            static constexpr unsigned char bits = sizeof(T) * 8;
        };

        // helps us to define all primitive types
        template<typename T>
        struct primitive_type_traits : public base_type_traits<T> {
            typedef T as_arg;
        };
    }

    // generic base struct for all types.
    template<typename T>
    struct type_traits : public internal::base_type_traits<T> {
        typedef T& as_arg;
    };


#   define YAAL_TRAIT_H(_type) template<> \
        struct type_traits<_type> : \
            public internal::primitive_type_traits<_type>

#   define YAAL_TRAIT(_type, _bigger, _smaller, _bits) \
        YAAL_TRAIT_H(_type) \
        { \
            typedef _bigger bigger; \
            typedef _smaller smaller; \
            static constexpr uint8_t bits = _bits; \
        };

#   define YAAL_TRAIT_S(_type, _bigger, _bits) \
        YAAL_TRAIT_H(_type) \
        { \
            typedef _bigger bigger; \
            static constexpr bool smallest = true; \
            static constexpr uint8_t bits = _bits; \
        };

#   define YAAL_TRAIT_B(_type, _smaller, _bits) \
        YAAL_TRAIT_H(_type) \
        { \
            typedef _smaller smaller; \
            static constexpr bool biggest = true; \
            static constexpr uint8_t bits = _bits; \
        };


    // FIXME: these only applies on 8bit avr when int is 16bit

    YAAL_TRAIT_S(unsigned char, unsigned int, 8);
    YAAL_TRAIT(unsigned int, unsigned long, unsigned char, 16);
    YAAL_TRAIT(unsigned short, unsigned long, unsigned char, 16);
    YAAL_TRAIT(unsigned long, unsigned long long, unsigned int, 32);
    YAAL_TRAIT_B(unsigned long long, unsigned long, 64);

    YAAL_TRAIT_S(signed char, signed int, 8);
    YAAL_TRAIT(signed int, signed long, signed char, 16);
    YAAL_TRAIT(signed short, signed long, signed char, 16);
    YAAL_TRAIT(signed long, signed long long, signed int, 32);
    YAAL_TRAIT_B(signed long long, signed long, 64);

    YAAL_TRAIT_H(double) { };
    YAAL_TRAIT_H(float) { };

#   undef YAAL_TRAIT_H
#   undef YAAL_TRAIT
#   undef YAAL_TRAIT_S
#   undef YAAL_TRAIT_B

}

#endif
#endif
