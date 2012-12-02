#ifndef __YAAL_ARDUINO__COMPATINILITY__
#define __YAAL_ARDUINO__COMPATINILITY__ 1

#include "../qualifiers.hh"
#include "../io/port.hh"

namespace yaal {
    namespace arduino {
        
        /* arduino code uses pinMode(pin, value) for pin mode manipulation
         * that is not required with yaal, but provided for compatibility
         * use this instead:
         *   D1 led;
         *   led = OUTPUT;
         */
        template<typename ClassPin>
        YAAL_DEPRECATED("Funktion pinMode() is only for compatibility. Avoid it.")
        void pinMode(ClassPin, Mode state) {
            ClassPin pin;
            pin.mode = state;
        }

        /* arduino code uses digitalWrite(pin, value) for pin manipulation
         * that is not required with yaal, but provided for compatibility
         * use this instead:
         *   D1 led;
         *   led = HIGH;
         */
        template<typename ClassPin>
        YAAL_DEPRECATED("Funktion digitalWrite() is only for compatibility. Avoid it.")
        void digitalWrite(ClassPin, bool state) {
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
