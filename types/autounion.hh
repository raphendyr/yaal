#ifndef __YAAL_TYPES__AUTOUNION__
#define __YAAL_TYPES__AUTOUNION__ 1
#include "../requirements.hh"
#ifdef __YAAL__

/* yaal/types/autounion.hh
*/

namespace yaal {

    template<typename T, bool bigendian = false>
    class autounion {

        union data_u {
            T value;
            uint8_t bytes[sizeof(T)];
            data_u(T const& t): value(t) {}
        } data;

    public:
        autounion(): data(T()) {}
        autounion(T const& t): data(t) {}

        T value() const {
            return data.value;
        }

        operator T () const {
            return value();
        }

        T& value() {
            return data.value;
        }

        operator T& () {
            return value();
        }

        uint8_t& operator[] (uint8_t const i) {
            if (bigendian)
                return data.bytes[i];
            else
                return data.bytes[size - 1 - i];
        }

        uint8_t operator[] (uint8_t const i) const {
            if (bigendian)
                return data.bytes[i];
            else
                return data.bytes[size - 1 - i];
        }

        static const uint8_t size = sizeof(T);
    };

}

#if 0
// Example usage.

void fancy(autounion<uint16_t> value) {
    value -= 10;
    std::cout << value << ":" << std::endl;
    for (int i = 0; i < value.size; ++i) {
        std::cout << (int)value[i] << std::endl;
    }
}

int main() {
    fancy(0x00ff);

    std::cout << std::endl;

    autounion<uint16_t, false> foo = 0x00ff;

    for (int i = 0; i < foo.size; ++i) {
        std::cout << (int)foo[i] << std::endl;
    }
}
#endif

#endif
#endif
