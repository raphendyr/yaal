#ifndef __YAAL_MATH__FIXED__
#define __YAAL_MATH__FIXED__ 1
#include "../requirements.hh"
#ifdef __YAAL__

#include "../types/traits.hh"
#include "../bitmask.hh"
#include "constants.hh"

namespace yaal {

    template<uint8_t decimal_bits = 8, typename container_type = int16_t>
    class FixedDecimal {
        typedef FixedDecimal<decimal_bits, container_type> self_type;
        typedef type_traits<container_type> container_traits;

        static constexpr container_type __one__ = 1 << decimal_bits;

    public:
        struct RawValue {
            container_type value;
            constexpr RawValue(const container_type& value) : value(value) {}
        };

    protected:
        container_type value;

    public:
        static constexpr self_type e = constants::e;
        static constexpr self_type pi = constants::pi;

        static constexpr self_type one = 1;
        static constexpr self_type maximum = RawValue(BitMask<container_traits::bits>::right);
        static constexpr self_type minimum = RawValue(1);


        // creators (/setters)
        constexpr FixedDecimal()
            : value(0) {}
        constexpr FixedDecimal(const RawValue& raw)
            : value(raw.value) {}
        constexpr FixedDecimal(const self_type& o)
            : value(o.value) {}
#     ifdef __AVR__
        constexpr FixedDecimal(const int& o)
            : value(static_cast<container_type>(o * __one__)) {}
#     endif
        constexpr FixedDecimal(const uint8_t& o)
            : value(static_cast<container_type>(o * __one__)) {}
        constexpr FixedDecimal(const uint16_t& o)
            : value(static_cast<container_type>(o * __one__)) {}
        constexpr FixedDecimal(const uint32_t& o)
            : value(static_cast<container_type>(o * __one__)) {}
        constexpr FixedDecimal(const int8_t& o)
            : value(static_cast<container_type>(o * __one__)) {}
        constexpr FixedDecimal(const int16_t& o)
            : value(static_cast<container_type>(o * __one__)) {}
        constexpr FixedDecimal(const int32_t& o)
            : value(static_cast<container_type>(o * __one__)) {}
        constexpr FixedDecimal(const float& o)
            : value(static_cast<container_type>(o * __one__)) {}
        constexpr FixedDecimal(const double& o)
            : value(static_cast<container_type>(o * __one__)) {}
        constexpr FixedDecimal(const long double& o)
            : value(static_cast<container_type>(o * __one__)) {}


        // asingment
        self_type& operator= (const self_type& o) {
            value = o.value;
            return *this;
        }
        self_type& operator= (const container_type& o_value) {
            value = o_value * __one__;
            return *this;
        }
        self_type& operator= (const int& o_value) {
            value = o_value * __one__;
            return *this;
        }
        self_type& operator= (const float& o_value) {
            value = static_cast<container_type>(o_value * __one__);
            return *this;
        }
        self_type& operator= (const double& o_value) {
            value = static_cast<container_type>(o_value * __one__);
            return *this;
        }


        // getters
        container_type to_integer() const {
            return value / __one__;
        }

        operator container_type () const {
            return to_integer();
        }

        float to_float() const {
            return static_cast<float>(value) / static_cast<float>(__one__);
        }

        operator float () const {
            return to_float();
        }

        container_type raw_value() const {
            return value;
        }


        // operators
        //   += and +
        self_type& operator += (const self_type& o) {
            value += o.value;
            return *this;
        }

        template<typename T>
        self_type& operator += (const T& o) {
            self_type other = o;
            *this += other;
            return *this;
        }

        template<typename T>
        self_type operator + (const T& o) {
            self_type copy = *this;
            copy += o;
            return copy;
        }


        //   -= and -
        self_type& operator -= (const self_type& o) {
            value -= o.value;
            return *this;
        }

        template<typename T>
        self_type& operator -= (const T& o) {
            self_type other = o;
            *this -= other;
            return *this;
        }

        template<typename T>
        self_type operator - (const T& o) {
            self_type copy = *this;
            copy -= o;
            return copy;
        }


        //   *= and *
        self_type& operator *= (const container_type& o_value) {
            if (!container_traits::biggest) {
                typename container_traits::bigger tmp = value;
                tmp *= o_value;
                tmp /= __one__;
                value = tmp;
            } else {
                value = (value * o_value) / __one__;
            }
            return *this;
        }

        self_type& operator *= (const self_type& o) {
            *this *= o.value;
            return *this;
        }

        template<typename T>
        self_type& operator *= (const T& o) {
            self_type other = o;
            *this *= other;
            return *this;
        }

        template<typename T>
        self_type operator * (const T& o) {
            self_type copy = *this;
            copy *= o;
            return copy;
        }


        //   /= and /
        self_type& operator /= (const container_type& o_value) {
            if (!container_traits::biggest) {
                typename container_traits::bigger tmp = value;
                tmp *= __one__;
                tmp /= o_value;
                value = tmp;
            } else {
                // this version loses more or less accuracy
                if (o_value < __one__)
                    value = (value * __one__) / o_value;
                else
                    value /= o_value / __one__;
            }
            return *this;
        }

        self_type& operator /= (const self_type& o) {
            *this /= o.value;
            return *this;
        }

        template<typename T>
        self_type& operator /= (const T& o) {
            self_type other = o;
            *this /= other;
            return *this;
        }

        template<typename T>
        self_type operator / (const T& o) {
            self_type copy = *this;
            copy /= o;
            return copy;
        }

        // tests
        //   >
        template<typename T>
        bool operator > (const T& o) {
            self_type other = o;
            return *this > other;
        }

        bool operator > (const self_type& o) {
            return value > o.value;
        }

        template<typename T>
        bool operator >= (const T& o) {
            return *this > o || *this == o;
        }

        //   <
        template<typename T>
        bool operator < (const T& o) {
            self_type other = o;
            return *this < other;
        }

        bool operator < (const self_type& o) {
            return value < o.value;
        }

        template<typename T>
        bool operator <= (const T& o) {
            return *this < o || *this == o;
        }

        //   ==
        template<typename T>
        bool operator == (const T& o) {
            self_type other = o;
            return *this == other;
        }

        bool operator == (const self_type& o) {
            return value == o.value;
        }

        //   >>= and >>
        self_type& operator >>= (const uint8_t steps) {
            if (container_traits::is_signed && value < 0)
                value = -((-value >> steps) | (value & 1));
            else
                value = (value >> steps) | (value & 1);
            return *this;
        }

        self_type operator >> (const uint8_t steps) {
            self_type copy = *this;
            copy >>= steps;
            return copy;
        }

        //   <<= and <<
        self_type& operator <<= (const uint8_t steps) {
            if (container_traits::is_signed && value < 0)
                value = -(-value << steps);
            else
                value <<= steps;
            return *this;
        }

        self_type operator << (const uint8_t steps) {
            self_type copy = *this;
            copy <<= steps;
            return copy;
        }

    };

}


template<uint8_t bits, typename container, typename other_type>
::yaal::FixedDecimal<bits, container> operator + (const ::yaal::FixedDecimal<bits, container>& a, const other_type& b) {
    ::yaal::FixedDecimal<bits, container> copy = a;
    copy += b;
    return copy;
}

template<uint8_t bits, typename container, typename other_type>
::yaal::FixedDecimal<bits, container> operator - (const ::yaal::FixedDecimal<bits, container>& a, const other_type& b) {
    ::yaal::FixedDecimal<bits, container> copy = a;
    copy -= b;
    return copy;
}

template<uint8_t bits, typename container, typename other_type>
::yaal::FixedDecimal<bits, container> operator * (const ::yaal::FixedDecimal<bits, container>& a, const other_type& b) {
    ::yaal::FixedDecimal<bits, container> copy = a;
    copy *= b;
    return copy;
}

template<uint8_t bits, typename container, typename other_type>
::yaal::FixedDecimal<bits, container> operator / (const ::yaal::FixedDecimal<bits, container>& a, const other_type& b) {
    ::yaal::FixedDecimal<bits, container> copy = a;
    copy /= b;
    return copy;
}

#endif
#endif
