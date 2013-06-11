#ifndef __YAAL_IO__TYPES__MASKEDPORT__
#define __YAAL_IO__TYPES__MASKEDPORT__ 1
#include "../../requirements.hh"
#ifdef __YAAL__

#include "port.hh"
#include "../../interfaces/pintuple.hh"
#include "../../util/constexpr.hh"
#include "../../atomic.hh"

namespace yaal {

    namespace internal {

        template< typename PortClass, uint8_t bitmask, bool shift_it = true >
        class BaseMaskedPort {
        public:
            static_assert(bitmask, "MaskedPort requires effective bitmask");

            static constexpr uint8_t mask = bitmask;
            static constexpr uint8_t shift = ffs_ce(bitmask) - 1;

            PortClass port;

            YAAL_INLINE("MaskedPort::set(value)")
            void set(uint8_t value) {
                value <<= shift;
                value &= mask;
                {
                    Atomic block;
                    uint8_t val = port;
                    val &= mask;
                    val |= value;
                    port = val;
                }
            }

            YAAL_INLINE("MakesPort::get()")
            uint8_t get(void) const {
                uint8_t value = port;
                value &= mask;
                return value >> shift;
            }

            YAAL_INLINE("MaskedPort::set_output()")
            void set_output(void) {
                typename PortClass::direction_type direction;
                typename PortClass::output_type output;

                // Clear pullup if present
                output &= ~mask;
                // Set direction output
                direction |= mask;
            }

            YAAL_INLINE("MaskedPort::set_input(pullup)")
            void set_input(bool pullup = false) {
                typename PortClass::direction_type direction;
                typename PortClass::output_type output;

                // set direction input
                direction &= ~mask;
                // Set pullup if wanted
                if (pullup)
                    output |= mask;
            }
        };

    }

    template< typename PortClass, uint8_t bitmask, bool shift_it = true >
    using MaskedPort = PinTuple<internal::BaseMaskedPort<PortClass, bitmask, shift_it>>;

}

#endif
#endif
