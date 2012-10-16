#ifndef __YAAL_ARDUINO__COMPATINILITY__
#define __YAAL_ARDUINO__COMPATINILITY__ 1

#include "../qualifiers.hh"
#include "../io/port.hh"

namespace yaal {
    namespace arduino {
        
        #define INPUT_PULLUP PULLUP

        /* arduino code uses pinMode(pin, value) for pin mode manipulation
         * that is not required with yaal, but provided for compatibility
         * use this instead:
         *   D1 led;
         *   led = OUTPUT;
         */
        template<typename ClassPin>
        YAAL_DEPRECATED("Funktion pinMode() is only for compatibility. Avoid it.")
        void pinMode(ClassPin, States state) {
            ClassPin pin;
            pin = state;
        }

        /* arduino code uses digitalWrite(pin, value) for pin manipulation
         * that is not required with yaal, but provided for compatibility
         * use this instead:
         *   D1 led;
         *   led = HIGH;
         */
        template<typename ClassPin, typename state_type>
        YAAL_DEPRECATED("Funktion digitalWrite() is only for compatibility. Avoid it.")
        void digitalWrite(ClassPin, state_type state) {
            ClassPin pin;
            pin = state;
        }
        
        /* arduino code uses value = digitalRead(pin) for pin status
         * that is not required with yaal, but provided for compatibility
         * use this instead:
         *   D1 button;
         *   if (button)
         *     ...
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
