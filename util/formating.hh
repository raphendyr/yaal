#ifndef __YAAL_UTIL__FORMATING__
#define __YAAL_UTIL__FORMATING__ 1
#include "../requirements.hh"
#ifdef __YAAL__

// used by StreamPgmString
#ifdef __AVR__
#  include <avr/pgmspace.h>
#endif

namespace yaal {

    // TODO: use template to optimize for different cases
    // Also give function to put chars directly into stream, instead of reversing
    // That also allows using internal buffer only
    // This might cause performance impact if not inlined
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


    namespace internal {

        template< typename T >
        struct StreamActor : public T {};

#     ifdef __AVR__
        struct _StreamPgmString {
            const char* string;

            template< typename Stream >
            void operator() (Stream& stream) {
                const char* s = string;
                char c;
                while ( (c = pgm_read_byte(s++)) ) {
                    // if (c == '\n') *stream << '\r';
                    stream << c;
                }
            }
        };
        using StreamPgmString = StreamActor<_StreamPgmString>;
#     endif

        struct _StreamEndline {
            template< typename Stream >
            void operator() (Stream& stream) {
#             ifdef YAAL_WIN_STYLE_ENDL
                stream << '\r';
#             endif
                stream << '\n';
                stream.flush();
            }
        };
        using StreamEndline = StreamActor<_StreamEndline>;

        template< typename T, uint8_t base = 10>
        struct _StreamIntAsString {
            T value;

            template< typename Stream >
            void operator() (Stream& stream) {
                char buf[11];
                ntoa(value, buf, base);
                // TODO: prefix hex with 0x
                stream << buf;
            }
        };
        template< typename T, uint8_t base = 10>
        using StreamIntAsString = StreamActor<_StreamIntAsString<T, base>>;

    }


    /* Program Memory String */

# ifdef __AVR__
//  _T is defined in debug.hh as pass-through macro, so undefine it first
#   ifdef _T
#     undef _T
#   endif
#   define _T(s) (__extension__({ \
        static const char __attribute__ ((__progmem__,used)) __CONCAT(c_,__LINE__)[] = (s); \
        ::yaal::internal::StreamPgmString __CONCAT(p_,__LINE__); \
        __CONCAT(p_,__LINE__).string = __CONCAT(c_,__LINE__); \
        __CONCAT(p_,__LINE__); \
    }))
# endif


    /* Endline */

    constexpr internal::StreamEndline endl;


    /* IntAsString */

    template< typename T>
    YAAL_INLINE("ashex")
    internal::StreamIntAsString<T, 16> ashex(T value) {
        internal::StreamIntAsString<T, 16> hex;
        hex.value = value;
        return hex;
    }

    template< typename T>
    YAAL_INLINE("asdec")
    internal::StreamIntAsString<T, 10> asdec(T value) {
        internal::StreamIntAsString<T, 10> dec;
        dec.value = value;
        return dec;
    }

    template< typename T>
    YAAL_INLINE("asoct")
    internal::StreamIntAsString<T, 8> asoct(T value) {
        internal::StreamIntAsString<T, 8> oct;
        oct.value = value;
        return oct;
    }

}

#endif
#endif
