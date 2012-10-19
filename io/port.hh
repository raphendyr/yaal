#ifndef __YAAL_IO__PORT__
#define __YAAL_IO__PORT__ 1

/* yaal/io/port.hh
 * Port and Pin abstration classes
 */

#include "../requirements.hh"
#include "../qualifiers.hh"
#include "register.hh"

#define LOW false
#define HIGH true

namespace yaal {

    enum Mode {
        INPUT,
        OUTPUT,
        INPUT_PULLUP,
    };

    // Register port, Register ddr, ReadonlyRegister pin
    template<typename OutputClass, typename DirectionClass, typename InputClass>
    struct Port {
        typedef Port<OutputClass, DirectionClass, InputClass> self_type;
        typedef OutputClass output_type;
        typedef DirectionClass direction_type;
        typedef InputClass input_type;

        OutputClass output;
        DirectionClass direction;
        InputClass input;

        // there is no protection if port is in input state
        YAAL_INLINE("Port operation")
        void set(typename OutputClass::size_type value) {
            output = value;
        }

        YAAL_INLINE("Port operation")
        typename InputClass::size_type get(void) const {
            return input;
        }

        // FIXME: name collision with this function and output type
        YAAL_INLINE("Port operation")
        void set_output(void) {
            // TODO: is this enough?
            direction = ~(typename DirectionClass::size_type)0;
        }

        // FIXME: name collision with this function and input type
        YAAL_INLINE("Port operation")
        void set_input(void) {
            // TODO: is this enough?
            direction = 0;
        }

        YAAL_INLINE("Port operation")
        operator typename InputClass::size_type (void) const {
            /* read: Port<> x; uint8_t value = x; */
            return input;
        }

        YAAL_INLINE("Port operation")
        operator typename OutputClass::size_type& (void) {
            /* write: Register x; x = 3; x |= 1 << 4; */
            return output;
        }

        YAAL_INLINE("Port operation")
        self_type& operator= (typename OutputClass::size_type value) {
            output = value;
            return *this;
        }
    };

    namespace internal {
        template<typename PortClass, bit_t bit>
        struct PinMode {
            typedef PinMode<PortClass, bit> self_type;
            typedef RegisterBit<typename PortClass::output_type, bit> output_type;
            typedef RegisterBit<typename PortClass::direction_type, bit> direction_type;

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
                Mode mode = pin_mode;
                return *this = mode;
            }
        };
    }

    template<typename PortClass, bit_t bit>
    struct Pin {
        typedef Pin<PortClass, bit> self_type;
        typedef internal::RegisterBit<typename PortClass::output_type, bit> output_type;
        typedef internal::RegisterBit<typename PortClass::input_type, bit> input_type;

        PortClass port;
        internal::PinMode<PortClass, bit> mode;

        // manipulator methods

        /* default set() with booleans */
        YAAL_INLINE("Pin operation")
        void set(bool state = true) {
            output_type out;
            out = state;
        }

        /* alias for set(false) */
        YAAL_INLINE("Pin operation")
        void clear(void) {
            set(false);
        }

        /* get pin value */
        YAAL_INLINE("Pin operation")
        bool get(void) const {
            input_type in;
            return in;
        }

        // manipulator operators

        /* operator for if(pin) */
        YAAL_INLINE("Pin operation")
        operator bool (void) const {
            return get();
        }

        /* assignment operator with booleans */
        YAAL_INLINE("Pin operation")
        self_type& operator= (bool state) {
            set(state);
            return *this;
        }
    };

    template<typename PinClass>
    class OutputPin : public PinClass {
        Mode mode;

    public:
        OutputPin() {
            PinClass pin;
            mode = pin.mode;
            pin.mode = OUTPUT;
        }

        OutputPin(const PinClass&) {
            PinClass pin;
            mode = pin.mode;
            pin.mode = OUTPUT;
        }

        ~OutputPin() {
            PinClass pin;
            pin.mode = mode;
        }

        template<typename value_type>
        OutputPin<PinClass>& operator= (value_type value) {
            PinClass::operator=(value);
            return *this;
        }
    };

    #define _OutputPin(var) OutputPin<decltype(var)>

    template<typename PinClass>
    OutputPin<PinClass> as_output(const PinClass& pin) {
        OutputPin<PinClass> as(pin);
        return as;
    }
}

#endif
