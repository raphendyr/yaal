#ifndef __YAAL_UTIL__FORMATING__
#define __YAAL_UTIL__FORMATING__ 1
#include "../requirements.hh"
#ifdef __YAAL__

// used by StreamPgmString
#ifdef __AVR__
#  include <avr/pgmspace.h>
#endif

namespace yaal {

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

    }


    /* ProgramMemory String */

# ifdef __AVR__
#   define _T(s) (__extension__({ \
        static const char __attribute__ ((__progmem__,used)) __CONCAT(c_,__LINE__)[] = (s); \
        ::yaal::internal::StreamPgmString __CONCAT(p_,__LINE__); \
        __CONCAT(p_,__LINE__).string = __CONCAT(c_,__LINE__); \
        __CONCAT(p_,__LINE__); \
    }))
# else
#   define _T(s) (s)
# endif


    /* Endline */

    constexpr internal::StreamEndline endl;


}

#endif
#endif
