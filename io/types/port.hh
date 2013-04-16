#ifndef __YAAL_IO__TYPES__PORT__
#define __YAAL_IO__TYPES__PORT__ 1
#include "../../requirements.hh"
#ifdef __YAAL__

/* yaal/io/types/port.hh
 * Port abstration classes
 */

// For some magical reason this needs to be included before following classes
// FIXME: find out why
#include "register.hh"

namespace yaal {

    // Register port, Register ddr, ReadonlyRegister pin
    template<typename OutputClass, typename DirectionClass, typename InputClass>
    class Port {
        typedef Port<OutputClass, DirectionClass, InputClass> self_type;

    public:
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
}

#endif
#endif
