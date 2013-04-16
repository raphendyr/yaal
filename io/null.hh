#ifndef __YAAL_IO__NULL__
#define __YAAL_IO__NULL__ 1
#include "../requirements.hh"
#ifdef __YAAL__

#include "port.hh"

namespace yaal {
    namespace internal {

        struct NullRegister {
            typedef uint32_t size_type;
            size_type tmp = 0;

            /* read */
            static YAAL_INLINE("Register operation")
            size_type get(void) { return 0; }

            YAAL_INLINE("Register operation")
            operator size_type (void) const { return 0; }

            /* write */
            static YAAL_INLINE("Register operation")
            void set(size_type) { }

            YAAL_INLINE("Register operation")
            operator size_type& (void) { return tmp; }


            YAAL_INLINE("Register operation")
            NullRegister& operator= (size_type) { return *this; }
        };

    } // internal

    typedef Port<internal::NullRegister,
                 internal::NullRegister,
                 internal::NullRegister> NullPort;

    typedef Pin<NullPort, 0> NullPin;
}

#endif
#endif
