#ifndef __YAAL_IO__NULL__
#define __YAAL_IO__NULL__ 1

namespace yaal {
    namespace internal {

        struct NullRegister {
            typedef uint32_t size_type;
            size_type tmp;

            /* read */
            static inline __attribute__ ((always_inline, error ("Register operation not inlined")))
            size_type get(void) { return 0; }

            inline __attribute__ ((always_inline, error ("Register operation not inlined")))
            operator size_type (void) const { return 0; }

            /* write */
            static inline __attribute__ ((always_inline, error ("Register operation not inlined")))
            void set(size_type) { }

            inline __attribute__ ((always_inline, error ("Register operation not inlined")))
            operator size_type& (void) { return tmp; }


            inline __attribute__ ((always_inline, error ("Register operation not inlined")))
            NullRegister& operator= (size_type) { return *this; }
        };

    } // internal

    typedef Port<internal::NullRegister,
                 internal::NullRegister,
                 internal::NullRegister> NullPort;

    typedef Pin<NullPort, 0> NullPin;
}

#endif
