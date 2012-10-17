#ifndef __YAAL_ARDUINO__PINS__
#define __YAAL_ARDUINO__PINS__ 1

#include "../qualifiers.hh"
#include "../io/port.hh"

// TODO: can we use 'namespace yaal::arduino {' ?
namespace yaal {
    namespace arduino {

        template<typename PinClass>
        struct DigitalPin : public PinClass {
            YAAL_INLINE("DigitalPin operation")
            DigitalPin<PinClass>& operator= (bool state) {
                this->set(state);
                return *this;
            }
        };

    }
}

#endif
