#ifndef __YAAL_IO__TYPES__PIN__
#define __YAAL_IO__TYPES__PIN__ 1
#include "../../requirements.hh"
#ifdef __YAAL__

/* yaal/io/types/pin.hh
 * Pin abstration classes
 */

// FIXME: why we need this include?
#include "port.hh"
#include "register.hh"

namespace yaal {

    static const bool LOW = false;
    static const bool HIGH = true;

    enum Mode {
        INPUT,
        OUTPUT,
        INPUT_PULLUP,
    };

    namespace internal {

        template<typename PortClass, bit_t bit>
        class PinMode {
            typedef PinMode<PortClass, bit> self_type;
            typedef SingleBit<typename PortClass::output_type, bit> output_type;
            typedef SingleBit<typename PortClass::direction_type, bit> direction_type;

        public:
            YAAL_INLINE("PinMode operation")
            void output() {
                output_type out;
                direction_type dir;

                out = false;
                dir = true;
            }

            YAAL_INLINE("PinMode operation")
            void input(bool pullup = false) {
                output_type out;
                direction_type dir;
                // TODO: order of operations? order by variable? should we even touch on output bit?
                if (!pullup)
                    out = false;
                dir = false;
                if (pullup)
                    out = true;
            }

            YAAL_INLINE("PinMode operation")
            void set(bool output_mode, bool pullup = false) {
                if (output_mode)
                    output();
                else
                    input(pullup);
            }

            YAAL_INLINE("PinMode operation")
            void set(Mode mode) {
                switch (mode) {
                    case INPUT:
                        input(false);
                        return;
                    case OUTPUT:
                        output();
                        return;
                    case INPUT_PULLUP:
                        input(true);
                        return;
                }
            }

            YAAL_INLINE("PinMode operation")
            bool is_output() const {
                direction_type dir;
                return dir;
            }

            YAAL_INLINE("PinMode operation")
            Mode get() const {
                output_type out;
                direction_type dir;

                if (dir)
                    return OUTPUT;
                else if (out)
                    return INPUT_PULLUP;
                else
                    return INPUT;
            }

            YAAL_INLINE("PinMode operation")
            operator bool () const {
                return is_output();
            }

            YAAL_INLINE("PinMode operation")
            operator Mode () const {
                return get();
            }

            YAAL_INLINE("PinMode operation")
            self_type& operator= (bool output_mode) {
                set(output_mode);
                return *this;
            }

            YAAL_INLINE("PinMode operation")
            self_type& operator= (Mode mode) {
                set(mode);
                return *this;
            }

            template<typename OtherPin, bit_t other_bit>
            YAAL_INLINE("PinMode operation")
            self_type& operator= (const PinMode<OtherPin, other_bit>& pin_mode) {
                /* D1 led1; D2 led2; led1.mode = led2.mode; */
                Mode mode = pin_mode;
                return *this = mode;
            }
        };

        template<typename PinClass>
        class RAIIPin : public PinClass {
            typedef RAIIPin<PinClass> self_type;
            typedef PinClass super;

            Mode mode;

        public:
            RAIIPin(Mode the_mode) {
                PinClass pin;
                mode = pin.mode;
                pin.mode = the_mode;
            }

            ~RAIIPin() {
                PinClass pin;
                pin.mode = mode;
            }

            template<typename value_type>
            self_type& operator=(value_type value) {
                super::operator=(value);
                return *this;
            }

        private:
            RAIIPin();
            //RAIIPin(const self_type&);
            self_type& operator=(const self_type&);
        };
    }

    template<typename PinClass>
    class Reversed;

    /* Pin<Port, bit> */
    template<typename PortClass, bit_t bit>
    class Pin : public internal::SingleBit<PortClass, bit> {
        typedef Pin<PortClass, bit> self_type;
        typedef internal::SingleBit<PortClass, bit> super;

        internal::SingleBit<typename PortClass::input_type, bit> pin_reg;

    public:
        PortClass port;
        internal::PinMode<PortClass, bit> mode;
        internal::SingleBit<typename PortClass::input_type, bit> input;
        internal::SingleBit<typename PortClass::output_type, bit> output;
        internal::SingleBit<typename PortClass::direction_type, bit> direction;

        /* assignment operator is not inherited */
        YAAL_INLINE("Pin operation")
        self_type& operator= (bool state) {
            this->set(state);
            return *this;
        }

        YAAL_INLINE("Pin Reversed wrapper")
        Reversed<self_type> reversed() {
            return Reversed<self_type>();
        }

        YAAL_INLINE("Pin RAII wrapper")
        internal::RAIIPin<self_type> as(Mode mode) {
            return internal::RAIIPin<self_type>(mode);
        }

        /* Hardware pin toggle */
        YAAL_INLINE("Pin operation")
#       ifdef AVR_WITHOUT_PIN_TOGGLE
            __attribute__ ((deprecated ("Your board doesn't support hardware toggling.")))
#       endif
        void toggle() {
#           ifndef AVR_WITHOUT_PIN_TOGGLE
                pin_reg = true;
#           else
                set(!get());
#           endif
        }
    };

    /* NullPin */
    typedef Pin<NullPort, 0xff> NullPin;

    /* Reversed<Pin> */
    template<typename PinClass>
    class Reversed : public PinClass {
        typedef Reversed<PinClass> self_type;
        typedef PinClass super;

    public:
        YAAL_INLINE("Reversed pin operation")
        void set(bool state = true) {
            super::set(!state);
        }

        YAAL_INLINE("Reversed pin operation")
        void clear() {
            set(false);
        }

        YAAL_INLINE("Reversed pin operation")
        bool get() const {
            return !super::get();
        }

        YAAL_INLINE("Reversed pin operation")
        self_type& operator= (bool state) {
            set(state);
            return *this;
        }

        YAAL_INLINE("Reversed pin operation")
        operator bool () {
            return get();
        }

        YAAL_INLINE("Reversed pin reversed wrapper")
        PinClass reversed() {
            return PinClass();
        }

        YAAL_INLINE("Reversed pin RAII wrapper")
        internal::RAIIPin<self_type> as(Mode mode) {
            return internal::RAIIPin<self_type>(mode);
        }
    };

    /* Floating<Pin> */
    template< typename Pin,
              bool pullup = false >
    class Floating {
        typedef Floating<Pin> self_type;
        typedef Pin super;

    public:
        YAAL_INLINE("Floating pin operation")
        void set(bool state = true) {
            if (state)
                super::mode = OUTPUT;
            else
                super::mode = pullup ? INPUT_PULLUP : INPUT;
        }

        YAAL_INLINE("Floating pin operation")
        void clear() {
            set(false);
        }

        YAAL_INLINE("Floating pin operation")
        bool get() const {
            return !super::get();
        }

        YAAL_INLINE("Floating pin operation")
        self_type& operator= (bool state) {
            set(state);
            return *this;
        }

        YAAL_INLINE("Floating pin operation")
        operator bool () {
            return get();
        }
    };

    template<typename Pin>
    class LowPeriod {
    public:
        YAAL_INLINE("LowPeriod")
        LowPeriod() {
            Pin p;
            p = false;
        }

        YAAL_INLINE("~LowPeriod")
        ~LowPeriod() {
            Pin p;
            p = true;
        }
    };

    template<typename Pin>
    class HighPeriod {
    public:
        YAAL_INLINE("HighPeriod")
        HighPeriod() {
            Pin p;
            p = true;
        }

        YAAL_INLINE("~HighPeriod")
        ~HighPeriod() {
            Pin p;
            p = false;
        }
    };
}

#endif
#endif
