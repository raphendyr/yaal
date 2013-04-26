#ifndef __YAAL_TYPES__PINSET__
#define __YAAL_TYPES__PINSET__ 1
#include "../requirements.hh"
#ifdef __YAAL__

#include "../io/types/pin.hh"

namespace yaal {

    // Pinset - 8 pins
    //template<typename Pin7, typename Pin6, typename Pin5, typename Pin4,
    //         typename Pin3, typename Pin2, typename Pin1, typename Pin0>
    // FIXME: I would like this in above order
    template<typename Pin0, typename Pin1, typename Pin2 = NullPin, typename Pin3 = NullPin,
             typename Pin4 = NullPin, typename Pin5 = NullPin, typename Pin6 = NullPin, typename Pin7 = NullPin>
    class Pinset {
        //typedef Pinset<Pin7, Pin6, Pin5, Pin4, Pin3, Pin2, Pin1, Pin0> self_type;
        typedef Pinset<Pin0, Pin1, Pin2, Pin3, Pin4, Pin5, Pin6, Pin7> self_type;

    public:

        static constexpr uint8_t size = !!Pin7::mask + !!Pin6::mask + !!Pin5::mask + !!Pin4::mask + !!Pin3::mask + !!Pin2::mask + !!Pin1::mask + !!Pin0::mask;

        self_type& operator=(uint8_t value) {
            Pin7() = value & 0x80;
            Pin6() = value & 0x40;
            Pin5() = value & 0x20;
            Pin4() = value & 0x10;
            Pin3() = value & 0x08;
            Pin2() = value & 0x04;
            Pin1() = value & 0x02;
            Pin0() = value & 0x01;

            return *this;
        }
    };

    // Pinset - 4 pins
    // FIXME: something like this is needed for reversed order
    //template<typename Pin3, typename Pin2, typename Pin1, typename Pin0>
    //using Pinset = Pinset<NullPin, NullPin, NullPin, NullPin, Pin3, Pin2, Pin1, Pin0>;
}

#endif
#endif
