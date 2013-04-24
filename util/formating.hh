#ifndef __YAAL_UTIL__FORMATING__
#define __YAAL_UTIL__FORMATING__ 1
#include "../requirements.hh"
#ifdef __YAAL__

namespace yaal {

    char * ntoa(int16_t n, char * s, uint8_t b) {
        uint8_t i = 0;

        // PART 1 - create string
        unsigned char sign = 0;

        if (n < 0) {
            n = -n;
            sign = 1;
        }

        do {
            // 'a' - 10 == 'W'
            s[i++] = ((n % b) < 10 ? '0' : 'W') + (n % b);
        } while ((n /= b) > 0);

        if (sign == 1)
            s[i++] = '-';
        s[i] = '\0';


        // PART 2 - reverse
        char *p1, *p2, tmp;
        for (p1 = s, p2 = s + i - 1; p2 > p1; ++p1, --p2) {
            tmp = *p2;
            *p2 = *p1;
            *p1 = tmp;
        }

        return s;
    }

    template< typename T >
    struct FmtHex {
        T value;
        bool prefix;
    };

    template< typename T >
    FmtHex<T> fmt_hex(T data, bool prefix = false) {
        FmtHex<T> hex = {data, prefix};
        return hex;
    }

    constexpr char endl = '\n';
}

#endif
#endif
