#ifndef __YAAL_ARDUINO__PINS__
#define __YAAL_ARDUINO__PINS__ 1
#include "../requirements.hh"
#ifdef __YAAL__

#include "../io/port.hh"

namespace yaal {
    namespace arduino {

        template<typename PinClass>
        class DigitalPin : public PinClass {
            typedef DigitalPin<PinClass> self_type;
            typedef PinClass super;

        public:
            /* assignment operator is not inherited */
            YAAL_INLINE("DigitalPin operation")
            self_type& operator= (bool state) { super::operator=(state); return *this; }
        };

    }
}

#endif
#endif
