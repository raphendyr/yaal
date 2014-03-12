#ifndef __YAAL_IO__TYPES__PORT__
#define __YAAL_IO__TYPES__PORT__ 1
#include "../../requirements.hh"
#ifdef __YAAL__

/* yaal/io/types/port.hh
 * Port abstration classes
 */

#include "../../types/register.hh"
#include "../../util/constexpr.hh"

namespace yaal {

    // Port<Register port, Register ddr, ReadonlyRegister pin, bit_mask>
    template< typename OutputClass,
              typename DirectionClass,
              typename InputClass,
              uint8_t bitmask = 0xff >
    class Port {
        typedef Port<OutputClass, DirectionClass, InputClass, bitmask> self_type;

    public:
        typedef OutputClass output_type;
        typedef DirectionClass direction_type;
        typedef InputClass input_type;
        static constexpr uint8_t mask = bitmask;
        static constexpr uint8_t size = bits_up_ce(bitmask);

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
            // read: Port<> x; uint8_t value = x;
            return input;
        }

        /* XXX: Removed as above is not used if this exists
        YAAL_INLINE("Port operation")
        operator typename OutputClass::size_type& (void) {
            // write: Port<> x; x = 3; x |= 1 << 4;
            return output;
        }
        */

        YAAL_INLINE("Port |= operation")
        self_type& operator|= (typename OutputClass::size_type value) {
            output |= value;
            return *this;
        }

        YAAL_INLINE("Port &= operation")
        self_type& operator&= (typename OutputClass::size_type value) {
            output &= value;
            return *this;
        }

        YAAL_INLINE("Port operation")
        self_type& operator= (typename OutputClass::size_type value) {
            output = value;
            return *this;
        }
    };

    /* NullPort */
    typedef Port<internal::NullRegister, internal::NullRegister, internal::NullRegister, 0> NullPort;
}

#endif
#endif
