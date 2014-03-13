#ifndef __YAAL_IO__TYPES__PORT__
#define __YAAL_IO__TYPES__PORT__ 1
#include "../../requirements.hh"
#ifdef __YAAL__

/* yaal/io/types/port.hh
 * Port abstration classes
 */

#include "../../interface/register.hh"
#include "../../types/register.hh"
#include "../../util/constexpr.hh"

namespace yaal {

    // Port<Register port, Register ddr, ReadonlyRegister pin, bitmask>
#define YAAL_CRTP_CLASS Port<OutputRegister, DirectionRegister, InputRegister, bitmask, YAAL_CRTP_ARGUMENT>
    template< typename OutputRegister, typename DirectionRegister, typename InputRegister, uint32_t bitmask = 0xffffffff, YAAL_CRTP_TEMPLATE_ARG >
    class Port : public interface::NamedRegisterWithOperators<typename OutputRegister::size_type, YAAL_CRTP_DERIVED> {
        typedef YAAL_CRTP_DERIVED derived_type;
        typedef YAAL_CRTP_CLASS self_type;
        typedef interface::NamedRegisterWithOperators<typename OutputRegister::size_type, YAAL_CRTP_DERIVED> super;
#undef  YAAL_CRTP_CLASS

    public:
        typedef OutputRegister output_type;
        typedef DirectionRegister direction_type;
        typedef InputRegister input_type;
        typedef typename OutputRegister::size_type size_type;

        static constexpr size_type mask = static_cast<size_type>(bitmask);
        static constexpr uint8_t size = bits_up_ce(mask);

        output_type output;
        direction_type direction;
        input_type input;

        // there is no protection if port is in input state
        YAAL_INLINE("Port::reference()")
        size_type& reference() {
            return output.reference();
        }

        // note that Register implements operator,
        // so use this: Port<> x; uint8_t value = x;
        YAAL_INLINE("Port::get()")
        size_type get() const {
            return input;
        }

        YAAL_CRTP_ASSIGNMENTS(derived_type, super);

        /* Mode changing */

        // FIXME: name collision with this function and output type
        YAAL_INLINE("Port operation")
        void set_output(void) {
            // TODO: is this enough?
            direction = ~(size_type)0;
        }

        // FIXME: name collision with this function and input type
        YAAL_INLINE("Port operation")
        void set_input(void) {
            // TODO: is this enough?
            direction = 0;
        }
    };

    /* NullPort */
    typedef Port<internal::NullRegister, internal::NullRegister, internal::NullRegister, 0> NullPort;
}

#endif
#endif
