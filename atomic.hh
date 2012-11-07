#ifndef __YAAL_ATOMIC__
#define __YAAL_ATOMIC__ 1

#include <inttypes.h>
#include <avr/interrupt.h> // SREG, sei, cli
#include "qualifiers.hh"

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

    public:
        YAAL_INLINE("Atomic")
        Atomic() {
            state = SREG;
            cli();
        }

        YAAL_INLINE("~Atomic")
        ~Atomic() {
            SREG = state;
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
            state = SREG;
            sei();
        }

        YAAL_INLINE("~Interruptable")
        ~Interruptable() {
            SREG = state;
        }
    };

}

#endif
