#ifndef __YAAL_CORE__CPU__
#define __YAAL_CORE__CPU__ 1

#include <inttypes.h>
#include <avr/io.h>

namespace yaal {

    class Cpu {
    public:
        class Prescaler {
        public:

            enum Devider {
                FULL_SPEED,     // 1
                HALF_SPEED,     // 2
                QUARTER_SPEED,  // 4
                _8TH_SPEED,     // 8
                _16TH_SPEED,    // 16
                _32ND_SPEED,    // 32
                _64TH_SPEED,    // 64
                _128TH_SPEED,   // 128
                _256TH_SPEED,   // 256
                INVALID,
            };

            void set(Devider devider) {
                if (devider < INVALID) {
                    CLKPR = 0x80;
                    CLKPR = (uint8_t)devider;
                }
            }

            Prescaler& operator= (Devider devider) {
                set(devider);
                return *this;
            }
        };

    public:
#if F_CPU == 20000000
        const static Prescaler::Devider CPU_20MHz = Prescaler::FULL_SPEED;
        const static Prescaler::Devider CPU_10MHz = Prescaler::HALF_SPEED;
        const static Prescaler::Devider CPU_5MHz = Prescaler::QUARTER_SPEED;
        const static Prescaler::Devider CPU_2.5MHz = Prescaler::_8TH_SPEED;
        const static Prescaler::Devider CPU_1.25MHz = Prescaler::_16TH_SPEED;
        const static Prescaler::Devider CPU_SLOW = Prescaler::_128TH_SPEED; // 156.25kHz
#elif F_CPU == 16000000
        const static Prescaler::Devider CPU_16MHz = Prescaler::FULL_SPEED;
        const static Prescaler::Devider CPU_8MHz = Prescaler::HALF_SPEED;
        const static Prescaler::Devider CPU_4MHz = Prescaler::QUARTER_SPEED;
        const static Prescaler::Devider CPU_2MHz = Prescaler::_8TH_SPEED;
        const static Prescaler::Devider CPU_1MHz = Prescaler::_16TH_SPEED;
        const static Prescaler::Devider CPU_SLOW = Prescaler::_128TH_SPEED; // 125kHz
#elif F_CPU == 8000000
        const static Prescaler::Devider CPU_8MHz = Prescaler::FULL_SPEED;
        const static Prescaler::Devider CPU_4MHz = Prescaler::HALF_SPEED;
        const static Prescaler::Devider CPU_2MHz = Prescaler::QUARTER_SPEED;
        const static Prescaler::Devider CPU_1MHz = Prescaler::_8TH_SPEED;
        const static Prescaler::Devider CPU_SLOW = Prescaler::_64TH_SPEED; // 125kHz
#elif F_CPU == 4000000
        const static Prescaler::Devider CPU_4MHz = Prescaler::FULL_SPEED;
        const static Prescaler::Devider CPU_2MHz = Prescaler::HALF_SPEED;
        const static Prescaler::Devider CPU_1MHz = Prescaler::QUARTER_SPEED;
        const static Prescaler::Devider CPU_SLOW = Prescaler::_32TH_SPEED; // 125kHz
#elif F_CPU == 2000000
        const static Prescaler::Devider CPU_2MHz = Prescaler::FULL_SPEED;
        const static Prescaler::Devider CPU_1MHz = Prescaler::HALF_SPEED;
        const static Prescaler::Devider CPU_SLOW = Prescaler::_16TH_SPEED; // 125kHz
#elif F_CPU == 1000000
        const static Prescaler::Devider CPU_1MHz = Prescaler::FULL_SPEED;
        const static Prescaler::Devider CPU_SLOW = Prescaler::_8TH_SPEED; // 125kHz
#else
#  warning "Unusual F_CPU. We couldn't define easier names for CPU prescaler devideers."
#endif

        Prescaler prescaler;

    } cpu;

}

#endif
