#ifndef __YAAL_ARDUINO__PINS__
#define __YAAL_ARDUINO__PINS__ 1

#include "../qualifiers.hh"

// TODO: can we use 'namespace yaal::arduino {' ?
namespace yaal {
    namespace arduino {

        template<typename PinClass>
        struct DigitalPin : public PinClass {
            YAAL_INLINE("DigitalPin operation")
            DigitalPin<PinClass>& operator= (bool value) {
                this->set(value);
                return *this;
            }
        };

    }
}

#endif
