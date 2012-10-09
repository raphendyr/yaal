#ifndef __YAAL_ARDUINO__PINS__
#define __YAAL_ARDUINO__PINS__ 1

// TODO: can we use 'namespace yaal::arduino {' ?
namespace yaal {
    namespace arduino {

        template<typename PinClass>
        struct DigitalPin : public PinClass {
        };

    }
}

#endif
