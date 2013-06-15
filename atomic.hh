#ifndef __YAAL_ATOMIC__
#define __YAAL_ATOMIC__ 1
#include "requirements.hh"
#ifdef __YAAL__

#ifdef __AVR__

#include <avr/interrupt.h> // SREG, sei, cli

namespace yaal {

    /* Make block atomic, and restore interrupt state after.
       {
         Atomic block;
         ...
       }
       is same as
       ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
         ...
       }

     */
    class Atomic {
        uint8_t state;
        bool required;

    public:
        YAAL_INLINE("Atomic")
        Atomic(bool required = true) : required(required) {
            if (required) {
                state = AVR_STATUS_REG; // SREG
                cli();
            }
        }

        YAAL_INLINE("~Atomic")
        ~Atomic() {
            if (required) {
                AVR_STATUS_REG = state; // SREG
            }
        }
    };

    /* Make block nonatomic/interruptable
       {
         Interruptable block;
         ...
       }
       is same as
       NONATOMIC_BLOCK(NONATOMIC_RESTORESTATE) {
         ...
       }
     */
    class Interruptable {
        uint8_t state;

    public:
        YAAL_INLINE("Interruptable")
        Interruptable() {
            state = AVR_STATUS_REG; // SREG
            sei();
        }

        YAAL_INLINE("~Interruptable")
        ~Interruptable() {
            AVR_STATUS_REG = state; // SREG
        }
    };

}

#else

// Dummy implementation for tests
namespace yaal {
    class Atomic {};
    class Interruptable {};
}

#endif

#endif
#endif
