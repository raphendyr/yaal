#ifndef __YAAL_ARDUINO__COMPATINILITY__
#define __YAAL_ARDUINO__COMPATINILITY__ 1

#include "../qualifiers.hh"

namespace yaal {
    namespace arduino {
        
        /* arduino code uses digitalWrite(pin, value) for pin manipulation
         * that is not required with yaal, but provided for compatibility
         */
        template<typename ClassPin>
        YAAL_DEPRECATED("Funktion digitalWrite() is only for compatibility. Avoid it.")
        void digitalWrite(ClassPin, bool state) {
            ClassPin pin;
            pin = state;
        }
        
        /* arduino code uses value = digitalRead(pin) for pin status
         * that is not required with yaal, but provided for compatibility
         */
        template<typename ClassPin>
        YAAL_DEPRECATED("Funktion digitalRead() is only for compatibility. Avoid it.")
        bool digitalRead(ClassPin) {
            ClassPin pin;
            return pin;
        }

    }
}

#endif
