#ifndef __YAAL_CORE__CPU__
#define __YAAL_CORE__CPU__ 1
#include "../requirements.hh"
#ifdef __YAAL__

#include <avr/io.h>

#include "../util/constexpr.hh"

namespace yaal {

    typedef unsigned long long freq_t;

    constexpr freq_t mhz(freq_t m) {
        return m * 1000000UL;
    }

    constexpr freq_t khz(freq_t k) {
        return k * 1000UL;
    }

    class Cpu {
        template<freq_t f_clock_, freq_t f_cpu_>
        class Clock {
            class Prescaler {
            public:
                YAAL_INLINE("Cpu::Clock::Prescaler::set")
                void set(uint8_t divider) {
#  ifdef CLKPR
                    if (divider <= 0x08) { // 0b00001000
                        // f_clk = f_src / 2^divider
                        CLKPR = 0x80;
                        CLKPR = divider;
                    }
#  elif defined(XDIV)
                    if (divider <= 0x80) { // 0x10000000
                        // f_clk = f_src / (129 - divider)
                        XDIV = 0;
                        if (divider < 0x80) {
                            XDIV = 0x80 | divider;
                        }
                    }
#  else
#    error "No known cpu prescaler register defined"
#  endif
                }

                YAAL_INLINE("Cpu::Clock::Prescaler::operator=")
                Prescaler& operator= (uint8_t divider) {
                    set(divider);
                    return *this;
                }

                YAAL_INLINE("Cpu::Clock::Prescaler::get")
                uint8_t get() {
#  ifdef CLKPR
                    return CLKPR;
#  elif defined(XDIV)
                    uint8_t value = XDIV;
                    return (value == 0) ? 0x80 : value & 0x7f;
#  else
#    error "No known cpu prescaler register defined"
#  endif
                }

                YAAL_INLINE("Cpu::Clock::Prescaler::operator uint8_t")
                operator uint8_t () {
                    return get();
                }
            };

        public:
            constexpr static freq_t f_clock = f_clock_;
            constexpr static freq_t f_cpu = f_cpu_;

            constexpr static freq_t NO_DIVIDER = f_clock;
            constexpr static freq_t FULL = f_clock;
            constexpr static freq_t HALF = f_clock / 2;
            constexpr static freq_t QUARTER = f_clock / 4;
            constexpr static freq_t EIGHTH = f_clock / 8;

            Prescaler prescaler;


            YAAL_INLINE("Cpu::Clock::set")
            void set(freq_t frequency) {
#  ifdef CLKPR
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
#  elif defined(XDIV)
                if (__builtin_constant_p(frequency)) {
                    prescaler = constrain_ce<int>(129 - f_clock / frequency, 0, 0x80);
                }
#  else
#    error "No known cpu prescaler register defined"
#  endif
            }

            YAAL_INLINE("Cpu::Clock::operator=")
            Clock& operator= (freq_t frequency) {
                set(frequency);
                return *this;
            }

            YAAL_INLINE("Cpu::Clock::get")
            freq_t get() {
#ifdef YAAL_UNSTABLE_F_CPU
#  ifdef CLKPR
                return f_clock >> prescaler;
#  elif defined(XDIV)
                return f_clock / (129 - prescaler);
#  else
#    error "No known cpu prescaler register defined"
#  endif
#else
                return f_cpu;
#endif
            }

            YAAL_INLINE("Cpu::Clock::operator freq_t")
            operator freq_t () {
                return get();
            }
        };
    public:

#if defined(F_CLOCK)
#  if defined(F_CPU)
        Clock<F_CLOCK, F_CPU> clock;
#  else
        Clock<F_CLOCK, F_CLOCK> clock;
#  endif
#elif defined(F_CPU)
        Clock<F_CPU, F_CPU> clock;
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
