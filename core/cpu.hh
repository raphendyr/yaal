#ifndef __YAAL_CORE__CPU__
#define __YAAL_CORE__CPU__ 1
#include "../requirements.hh"
#ifdef __YAAL__

#include <avr/io.h>

namespace yaal {

    typedef unsigned long long freq_t;

    constexpr freq_t mhz(freq_t m) {
        return m * 1000000UL;
    }

    constexpr freq_t khz(freq_t k) {
        return k * 1000UL;
    }

    class Cpu {
        template<freq_t f_clock>
        class Clock {
            class Prescaler {
            public:
                YAAL_INLINE("Cpu::Clock::Prescaler::set")
                void set(uint8_t divider) {
                    if (divider <= 0x08) { // 0x00001000
                        CLKPR = 0x80;
                        CLKPR = divider;
                    }
                }

                YAAL_INLINE("Cpu::Clock::Prescaler::operator=")
                Prescaler& operator= (uint8_t divider) {
                    set(divider);
                    return *this;
                }
            };

        public:
            constexpr static freq_t NO_DIVIDER = f_clock;
            constexpr static freq_t FULL = f_clock;
            constexpr static freq_t HALF = f_clock / 2;
            constexpr static freq_t QUARTER = f_clock / 4;
            constexpr static freq_t EIGHTH = f_clock / 8;

            Prescaler prescaler;

            YAAL_INLINE("Cpu::Clock::set")
            void set(freq_t frequency) {
                if (__builtin_constant_p(frequency)) {
                    if (frequency >= (f_clock >> 0)) {
                        prescaler = 0;
                    } else if (frequency >= (f_clock >> 1)) {
                        prescaler = 1;
                    } else if (frequency >= (f_clock >> 2)) {
                        prescaler = 2;
                    } else if (frequency >= (f_clock >> 3)) {
                        prescaler = 3;
                    } else if (frequency >= (f_clock >> 4)) {
                        prescaler = 4;
                    } else if (frequency >= (f_clock >> 5)) {
                        prescaler = 5;
                    } else if (frequency >= (f_clock >> 6)) {
                        prescaler = 6;
                    } else if (frequency >= (f_clock >> 7)) {
                        prescaler = 7;
                    } else {
                        prescaler = 8;
                    }
                }
                // TODO: else throw error
            }

            YAAL_INLINE("Cpu::Clock::operator=")
            Clock& operator= (freq_t frequency) {
                set(frequency);
                return *this;
            }
        };
    public:

#if defined(F_CLOCK)
        Clock<F_CLOCK> clock;
#elif defined(F_CPU)
        Clock<F_CPU> clock;
#  warning "No F_CLOCK, so I set cpu.clock to base on F_CPU value instead. YOUR CODE MAY MISS BEHAVE!"
#else
#  warning "No F_CLOCK nor F_CPU, so I couldn't define cpu.speed"
#endif

    };

    // Create singleton instance of cpu
    static Cpu cpu __attribute__ ((unused));
}

#endif
#endif
