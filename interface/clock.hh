#ifndef __YAAL_INTERFACE__CLOCK_hh__
#define __YAAL_INTERFACE__CLOCK_hh__ 1
#include "../requirements.hh"
#ifdef __YAAL__

namespace yaal {

    // TODO: use these interfaces in core/cpu.hh
    //typedef unsigned long long freq_t;

    namespace interface {

        template< typename Derived >
        class ClockPrescaler {
        public:

            // IMPLEMENT
            void set(uint8_t divider);

            YAAL_ASSIGNMENT_OPER(Derived, set, uint8_t);

            // IMPLEMENT
            uint8_t get(void);

            operator uint8_t () {
                return static_cast<Derived*>(this)->get();
            }
        };

        template< typename Derived >
        class Clock {
        public:
            // IMPLEMENT
            void set(freq_t frequency);

            YAAL_ASSIGNMENT_OPER(Derived, set, freq_t);

            // IMPLEMENT
            freq_t get(void);

            operator freq_t () {
                return static_cast<Derived*>(this)->get();
            }
        };

    }

}

#endif
#endif
