#ifndef __YAAL_IO__TYPES__PIN__
#define __YAAL_IO__TYPES__PIN__ 1
#include "../../requirements.hh"
#ifdef __YAAL__

/* yaal/io/types/pin.hh
 * Pin abstration classes
 */

#include "../../types/register.hh"
#include "port.hh"

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

                /* If output is 1, pullup will we enable first and thus level on pin stays the same
                 * If output is 0, input will be enabled and will start floating from the ground
                 * In either case if pullup is enabled, it will
                 *   a) stay the same, as it remains enabled from the output state
                 *   b) pull up the floating pin (which is probably in ground level)
                 * So this order should not brake any circuits
                 */
                dir = false;
                out = pullup;
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

    /* Pin specializations
     * required here, so we can implement conversion methods in Pin
     */
    template<typename PinClass>
    class Reversed;

    template<typename PinClass, bool pullup = false>
    class Floating;


    /* Pin<Port, bit> */
#define YAAL_CRTP_CLASS Pin<PortClass, bitnumber, YAAL_CRTP_ARGUMENT>
    template< typename PortClass, bit_index_type bitnumber, YAAL_CRTP_TEMPLATE_ARG >
    class Pin : public internal::SingleBit<PortClass, bitnumber, YAAL_CRTP_DERIVED> {
        typedef YAAL_CRTP_DERIVED derived_type;
        typedef YAAL_CRTP_CLASS self_type;
        typedef internal::SingleBit<PortClass, bitnumber, YAAL_CRTP_DERIVED> super;
#undef  YAAL_CRTP_CLASS

    public:
        template< typename SubClass >
        using Inherit = Pin<PortClass, bitnumber, SubClass>;

        PortClass port;
        internal::PinMode<PortClass, bitnumber> mode;
        internal::SingleBit<typename PortClass::input_type, bitnumber> input;
        internal::SingleBit<typename PortClass::output_type, bitnumber> output;
        internal::SingleBit<typename PortClass::direction_type, bitnumber> direction;

        YAAL_CRTP_ASSIGNMENTS(derived_type, super);

        /* Wrappe methods to convert to specialized versionds of a Pin
         * should be used like:
         *  auto reversed = led.reversed();
         */
        YAAL_INLINE("Pin Reversed wrapper")
        Reversed<derived_type> reversed() { return {}; }

        template< bool pullup = false >
        YAAL_INLINE("Pin Floating wrapper")
        Floating<derived_type, pullup> floating() { return {}; }

        YAAL_INLINE("Pin RAII wrapper")
        internal::RAIIPin<derived_type> as(Mode mode) { return mode; }

        /* Hardware pin toggle */
        YAAL_INLINE("Pin::toggle()")
#       ifdef AVR_WITHOUT_PIN_TOGGLE
            YAAL_DERPECATED("Your board doesn't support hardware toggling.")
#       endif
        void toggle() {
#           ifndef AVR_WITHOUT_PIN_TOGGLE
                // 2 clock cycles (2 sbi)
                direction = true;
#           else
                // 4 clock cycles (1 in, 1 ldi, 1 eor, 1 out)
                port ^= this->mask;
                // ~10 clock cycles (2.5 sbic, 2 rjmp, 2 sbi, 2 rjmp, 2 cbi)
                //set(!output.get());
#           endif
        }
    };

    /* NullPin */
    typedef Pin<NullPort, 0xff> NullPin;

    /* PinWithAdc */
#define YAAL_CRTP_CLASS PinWithAdc<PortClass, bitnumber, AdcClass, YAAL_CRTP_ARGUMENT>
    template< typename PortClass, bit_index_type bitnumber, typename AdcClass, YAAL_CRTP_TEMPLATE_ARG >
    class PinWithAdc : public Pin<PortClass, bitnumber, YAAL_CRTP_DERIVED> {
        typedef YAAL_CRTP_DERIVED derived_type;
        typedef YAAL_CRTP_CLASS self_type;
        typedef Pin<PortClass, bitnumber, YAAL_CRTP_DERIVED> super;
#undef  YAAL_CRTP_CLASS

    public:
        typedef AdcClass Analog;
        AdcClass analog;

        YAAL_CRTP_ASSIGNMENTS(derived_type, super);
    };

    /* Reversed<Pin> */
    template< typename PinClass >
    class Reversed : public PinClass::template Inherit<Reversed<PinClass>> {
        typedef Reversed<PinClass> self_type;
        typedef typename PinClass::template Inherit<Reversed<PinClass>> super;

    public:
        YAAL_INLINE("Reversed::set(state)")
        void set(bool state = true) {
            super::set(!state);
        }

        YAAL_INLINE("Reversed::get()")
        bool get() const {
            return !super::get();
        }

        YAAL_CRTP_ASSIGNMENTS(self_type, super);
    };

    /*! Floating<Pin>
     * Floating is specialization of a Pin, which is floating high by external resistor or
     * internal (if pullup) when it reads zero (0) and grounded when it reads one (1).
     * This matches to signaling used in I2C
     * FIXME: should the logic be around? Above logic could then be achieved using Reversed<Floating<Pin>>
     */
    template< typename PinClass, bool pullup >
    class Floating : public PinClass::template Inherit<Floating<PinClass, pullup>> {
        typedef Floating<PinClass, pullup> self_type;
        typedef typename PinClass::template Inherit<Floating<PinClass, pullup>> super;

    public:
        YAAL_INLINE("Floating::set(state)")
        void set(bool state = true) {
            this->mode.set(state, pullup);
        }

        YAAL_INLINE("Floating::get()")
        bool get() const {
            return !super::get();
        }

        YAAL_CRTP_ASSIGNMENTS(self_type, super);
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

#   undef YAAL_PIN_ASSINGMENT_OPER

}

#endif
#endif
