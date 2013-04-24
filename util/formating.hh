#ifndef __YAAL_UTIL__FORMATING__
#define __YAAL_UTIL__FORMATING__ 1
#include "../requirements.hh"
#ifdef __YAAL__

namespace yaal {

    namespace internal {

        template< typename T >
        struct StreamActor : public T {};

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


    /* Endline */

    constexpr internal::StreamEndline endl;


}

#endif
#endif
