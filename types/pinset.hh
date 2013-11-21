#ifndef __YAAL_TYPES__PINSET__
#define __YAAL_TYPES__PINSET__ 1
#include "../requirements.hh"
#ifdef __YAAL__

#include "../io/types/pin.hh"
#include "../interface/pintuple.hh"

namespace yaal {

    namespace internal {
        template<typename Pin0, typename Pin1, typename Pin2 = NullPin, typename Pin3 = NullPin,
                 typename Pin4 = NullPin, typename Pin5 = NullPin, typename Pin6 = NullPin, typename Pin7 = NullPin>
        class BasePinset {
            // implements PinTupleInterface

            Pin0 p0;
            Pin1 p1;
            Pin2 p2;
            Pin3 p3;
            Pin4 p4;
            Pin5 p5;
            Pin6 p6;
            Pin7 p7;

        public:
            static constexpr uint8_t mask = (!!Pin7::mask<<7) + (!!Pin6::mask<<6) + (!!Pin5::mask<<5) + (!!Pin4::mask<<4) + \
                                            (!!Pin3::mask<<3) + (!!Pin2::mask<<2) + (!!Pin1::mask<<1) + !!Pin0::mask;

            void set_output() {
                p0.mode.output();
                p1.mode.output();
                p2.mode.output();
                p3.mode.output();
                p4.mode.output();
                p5.mode.output();
                p6.mode.output();
                p7.mode.output();
            }

            void set_input(bool pullup = false) {
                p0.mode.input(pullup);
                p1.mode.input(pullup);
                p2.mode.input(pullup);
                p3.mode.input(pullup);
                p4.mode.input(pullup);
                p5.mode.input(pullup);
                p6.mode.input(pullup);
                p7.mode.input(pullup);
            }

            void set(uint8_t value) {
                p0 = value & 0x01;
                p1 = value & 0x02;
                p2 = value & 0x04;
                p3 = value & 0x08;
                p4 = value & 0x10;
                p5 = value & 0x20;
                p6 = value & 0x40;
                p7 = value & 0x80;
            }

            uint8_t get() const {
                uint8_t value = 0;
                if (p0.mask && p0)
                    value |= 0x01;
                if (p1.mask && p1)
                    value |= 0x02;
                if (p2.mask && p2)
                    value |= 0x04;
                if (p3.mask && p3)
                    value |= 0x08;
                if (p4.mask && p4)
                    value |= 0x10;
                if (p5.mask && p6)
                    value |= 0x20;
                if (p6.mask && p6)
                    value |= 0x40;
                if (p7.mask && p7)
                    value |= 0x80;
                return value;
            }
        };
    }

    template<typename P0, typename P1, typename P2 = NullPin, typename P3 = NullPin,
             typename P4 = NullPin, typename P5 = NullPin, typename P6 = NullPin, typename P7 = NullPin>
    using Pinset = PinTuple<internal::BasePinset<P0, P1, P2, P3, P4, P5, P6, P7>>;
}

#endif
#endif
