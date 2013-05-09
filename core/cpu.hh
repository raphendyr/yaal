#ifndef __YAAL_CORE__CPU__
#define __YAAL_CORE__CPU__ 1
#include "../requirements.hh"
#ifdef __YAAL__

#include <avr/io.h>

namespace yaal {

    class Cpu {
    public:
        enum Divider {
            _1ST_SPEED,
            _2ND_SPEED,
            _4TH_SPEED,
            _8TH_SPEED,
            _16TH_SPEED,
            _32ND_SPEED,
            _64TH_SPEED,
            _128TH_SPEED,
            _256TH_SPEED,
            INVALID_SPEED
        };

        constexpr static Divider NO_DIVIDER = _1ST_SPEED;
        constexpr static Divider FULL_SPEED = _1ST_SPEED;
        constexpr static Divider HALF_SPEED = _2ND_SPEED;
        constexpr static Divider QUARTER_SPEED = _4TH_SPEED;
        constexpr static Divider EIGHTH_SPEED = _8TH_SPEED;

        class Prescaler {
        public:
            YAAL_INLINE("Cpu::Prescaler::set")
            void set(Divider divider) {
                if (divider < INVALID_SPEED) {
                    CLKPR = 0x80;
                    CLKPR = (uint8_t)divider;
                }
            }

            YAAL_INLINE("Cpu::Prescaler::operator=")
            Prescaler& operator= (Divider divider) {
                set(divider);
                return *this;
            }
        };

        template<typename PrescalerClass, unsigned long long f_clock>
        class Speed {
            PrescalerClass prescaler;

        public:
            YAAL_INLINE("Cpu::Speed::set")
            void set(unsigned long long frequency) {
                if (__builtin_constant_p(frequency)) {
                    if (frequency >= (f_clock >> 0)) {
                        prescaler = _1ST_SPEED;
                    } else if (frequency >= (f_clock >> 1)) {
                        prescaler = _2ND_SPEED;
                    } else if (frequency >= (f_clock >> 2)) {
                        prescaler = _4TH_SPEED;
                    } else if (frequency >= (f_clock >> 3)) {
                        prescaler = _8TH_SPEED;
                    } else if (frequency >= (f_clock >> 4)) {
                        prescaler = _16TH_SPEED;
                    } else if (frequency >= (f_clock >> 5)) {
                        prescaler = _32ND_SPEED;
                    } else if (frequency >= (f_clock >> 6)) {
                        prescaler = _64TH_SPEED;
                    } else if (frequency >= (f_clock >> 7)) {
                        prescaler = _128TH_SPEED;
                    } else {
                        prescaler = _256TH_SPEED;
                    }
                }
                // TODO: else throw error
            }

            YAAL_INLINE("Cpu::Speed::operator=")
            Speed& operator= (unsigned long long frequency) {
                set(frequency);
                return *this;
            }
        };

#ifdef F_CLOCK
#  if F_CLOCK == 20000000
        constexpr static Divider CPU_20MHz = _1ST_SPEED;
        constexpr static Divider CPU_10MHz = _2ND_SPEED;
        constexpr static Divider CPU_5MHz = _4TH_SPEED;
        constexpr static Divider CPU_2500kHz = _8TH_SPEED;
        constexpr static Divider CPU_1250kHz = _16TH_SPEED;
        constexpr static Divider CPU_SLOW = _128TH_SPEED; // 156.25kHz
#  elif F_CLOCK == 16000000
        constexpr static Divider CPU_16MHz = _1ST_SPEED;
        constexpr static Divider CPU_8MHz = _2ND_SPEED;
        constexpr static Divider CPU_4MHz = _4TH_SPEED;
        constexpr static Divider CPU_2MHz = _8TH_SPEED;
        constexpr static Divider CPU_1MHz = _16TH_SPEED;
        constexpr static Divider CPU_SLOW = _128TH_SPEED; // 125kHz
#  elif F_CLOCK == 8000000
        constexpr static Divider CPU_8MHz = _1ST_SPEED;
        constexpr static Divider CPU_4MHz = _2ND_SPEED;
        constexpr static Divider CPU_2MHz = _4TH_SPEED;
        constexpr static Divider CPU_1MHz = _8TH_SPEED;
        constexpr static Divider CPU_SLOW = _64TH_SPEED; // 125kHz
#  elif F_CLOCK == 4000000
        constexpr static Divider CPU_4MHz = _1ST_SPEED;
        constexpr static Divider CPU_2MHz = _2ND_SPEED;
        constexpr static Divider CPU_1MHz = _4TH_SPEED;
        constexpr static Divider CPU_SLOW = _32TH_SPEED; // 125kHz
#  elif F_CLOCK == 2000000
        constexpr static Divider CPU_2MHz = _1ST_SPEED;
        constexpr static Divider CPU_1MHz = _2ND_SPEED;
        constexpr static Divider CPU_SLOW = _16TH_SPEED; // 125kHz
#  elif F_CLOCK == 1000000
        constexpr static Divider CPU_1MHz = _1ST_SPEED;
        constexpr static Divider CPU_SLOW = _8TH_SPEED; // 125kHz
#  else
#    warning "Unusual F_CLOCK, so I couldn't define easier names for cpu.prescaler devideers."
#  endif

#  else
#  warning "You have not defined F_CLOCK, so I couldn't define Cpu::CPU_*Hz to be used as cpu.prescaler devideers."
#endif


        Prescaler prescaler;
#if defined(F_CLOCK)
        Speed<Prescaler, F_CLOCK> speed;
#elif defined(F_CPU)
        Speed<Prescaler, F_CPU> speed;
#else
#  warning "No F_CLOCK nor F_CPU, so I couldn't define cpu.speed"
#endif

    };

    // initialize cpu
    static Cpu cpu __attribute__ ((unused));
}

#endif
#endif
