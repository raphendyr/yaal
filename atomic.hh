#ifndef __YAAL_ATOMIC__
#define __YAAL_ATOMIC__ 1

#include <inttypes.h>

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

    public:
        Atomic() {
            state = SREG;
            cli();
        }

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
        Interruptable() {
            state = SREG;
            sei();
        }

        ~Interruptable() {
            SREG = state;
        }
    };

}

#endif
