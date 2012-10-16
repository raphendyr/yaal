#ifndef __YAAL_IO__PORT__
#define __YAAL_IO__PORT__ 1

/* yaal/io/port.hh
 * Port and Pin abstration classes
 */

#include "../requirements.hh"
#include "../qualifiers.hh"
#include "register.hh"


namespace yaal {

    // Register port, Register ddr, ReadonlyRegister pin
    template<typename OutputClass, typename DirectionClass, typename InputClass>
    struct Port {
        typedef Port<OutputClass, DirectionClass, InputClass> self_type;

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


    template<typename PortClass, bit_t bit>
    struct Pin {
        typedef Pin<PortClass, bit> self_type;

        PortClass port;

        YAAL_INLINE("Pin operation")
        void set(bool state = true) {
            if (state)
                port |= (1 << bit);
            else
                port &= ~(1 << bit);
        }

        YAAL_INLINE("Pin operation")
        void clear(void) {
            set(false);
        }

        YAAL_INLINE("Pin operation")
        bool get(void) const {
            return port & (1 << bit);
        }

        YAAL_INLINE("Pin operation")
        void output(void) {
            // TODO: should we clear output state?
            clear();
            port.direction |= (1 << bit);
        }

        YAAL_INLINE("Pin operation")
        void input(bool pullup = false) {
            // TODO: order of operations? order by variable? should we even touch on output bit?
            if (!pullup)
                clear();
            port.direction &= ~(1 << bit);
            if (pullup)
                set();
        }

        YAAL_INLINE("Pin operation")
        operator bool (void) const {
            return get();
        }

        YAAL_INLINE("Pin operation")
        self_type& operator= (bool state) {
            set(state);
            return *this;
        }
    };

}

#endif
