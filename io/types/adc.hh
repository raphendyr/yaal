#ifndef __YAAL_IO__TYPES__ADC__
#define __YAAL_IO__TYPES__ADC__ 1
#include "../../requirements.hh"
#ifdef __YAAL__

/* yaal/io/types/adc.hh
 * Types for adc subsystem
 */

#if !defined(ADC) \
  || !defined(ADMUX) || !defined(REFS0) \
  || !defined(ADCSRA) || !defined(ADEN) || !defined(ADSC) \
  || !defined(ADCSRB)
#   ifndef YAAL_ADC_DISABLED
#       define YAAL_ADC_DISABLED 1
#   endif
#endif

// workaround for chips whitout MUX5 definition (io/registers/adc.hh should give correct channel_muc_bits variable)
#ifndef MUX5
#  define MUX5 0
#endif

#ifdef YAAL_ADC_DISABLED
#  warning "For various reasons you have ADC subsystem disabled. So pin.analog won't work."
#else

#include "../../atomic.hh"
#include "../../bitmask.hh"

namespace yaal {
    // FIXME: relocate
    // FIXME: implement
    namespace internal {
        void sleep();
    }

    // following ablies atleast for atmega32u4

    // 10-bits: read 16 bit word read ADCL then ADCH
    //  8-bits: ident to left and read only ADCH

    // adc analog input path error correction: 24.7.3.

    // ADIF is high on complete

    // single channel, result is: adc = (v_in / V_ref) * 1023
    // diff channel, result is: adc = ((V_pos - V_neg) / V_ref) * Gain * 512
    // diff result is 2's complement, 0x200 (-512d) to 0x1ff (+511d)
    // to check positive/negatie, read only polarity bit

    // ADMUX: (atmega328p doesn't have MUX4, other wise this ablies)
    // REFS1, REFS0, ADLAR, MUX4, MUX3, MUX2, MUX1, MUX0
    // REFSn: 0,0 - AREF, 0,1 - AVcc, 1,0 - reserved, 1,1 - Internal 2.56V (1.1V on m328p)
    //  - put external capacitor on AREF pin (atleast when using internal or AVcc)
    // ADLAR: Left adjust result will effect ADC valua immediately
    // MUXn: Channel selection

    // ADCSRA (ablies for atmega328p)
    // ADEN, ADSC, ADATE, ADIF, ADIE, ADPS2, ADPS1, ADPS0
    // ADEN: ADC enabled
    // ADSC: start conversion
    // ADATE: auto trigger enable
    // ADIF: interrupt flag
    // ADIE: interrupt enable
    // ADPSn: adc prescaler select
    //  - 000 clk/2 (I ques this is really 1)
    //  - 001 clk/2
    //  - 010 clk/4
    //  - 011 clk/8
    //  - 100 clk/16
    //  - 101 clk/32
    //  - 110 clk/64
    //  - 111 clk/128

    // ADCSRB (atmega328p doesn't have ADHSM, MUX5, ADTS3)
    // ADHSM, ACME, MUX5, -, ADTS3, ADTS2, ADTS1, ADTS0
    // ADHSM: high speed mode
    // MUX5: mux bit
    // ADTSn: Autotrigger source

    // DIDR0
    // digital input disable, ADC7D ... ADC4D, ADC1D ... ADC0D

    // DIDR2
    // digital input disable, ADC13D ... ADC8D

    template<uint8_t channel_mux_bits>
    class AnalogDigitalConverter {
        friend void ::yaal::sleep();

        typedef bool sleep_memory;

        YAAL_INLINE("AnalogDigitalConverter::pre_sleep")
        sleep_memory pre_sleep() {
            bool was_on = is_on();
            disable();
            return was_on;
        }

        YAAL_INLINE("AnalogDigitalConverter::post_sleep")
        void post_sleep(sleep_memory was_on) {
            if (was_on)
                enable();
        }

    public:

        class Reference {
        public:
            // POWER and INTERNAL expects that there is capacitor in AREF pin
            enum Source {
                EXTERNAL = 0 << REFS0, // AREF
                POWER    = 1 << REFS0, // AVcc
                RESERVED = 2 << REFS0,
                INTERNAL = 3 << REFS0, // Internal 2.56V (atmega32u4), 1.1V (atmega328p)
                ANY      = 255,
            };

            YAAL_INLINE("AnalogDigitalConverter::Reference::get")
            Source get() {
                Atomic block;
                return static_cast<Source>(ADMUX & BitMask<2, REFS0>::right);
            }

            YAAL_INLINE("AnalogDigitalConverter::Reference::operator Source")
            operator Source() {
                return get();
            }


            YAAL_INLINE("AnalogDigitalConverter::Reference::set")
            void set(Source reference_source) {
                Atomic block;
                ADMUX = reference_source | (ADMUX & ~BitMask<2, REFS0>::right);
            }

            YAAL_INLINE("AnalogDigitalConverter::Reference::operator=")
            Reference& operator=(Source reference_source) {
                set(reference_source);
                return *this;
            }
        } reference;

        class Prescaler {
        public:
            enum Values {
                // Include enumeration from file
                // file is created via script
                // it will define following variables if possible
                // SLOW   50-125 kHz
                // FAST  125-200 kHz
                // SUPER 200-300 kHz
#               define __INTERNAL_INCLUDE_ENUM__ 1
#               include "prescaler_constants.hh"
#               undef __INTERNAL_INCLUDE_ENUM__
                // normally FAST should be ok
                // with SUPER you should enable high speed mode
            };

            YAAL_INLINE("AnalogDigitalConverter::Prescaler::set")
            void set(Values value) {
                Atomic block;
                ADCSRA = (ADCSRA & ~BitMask<3>::right) | (value & BitMask<3>::right);
            }

            YAAL_INLINE("AnalogDigitalConverter::Prescaler::operator=")
            Prescaler& operator= (Values value) {
                set(value);
                return *this;
            }
        } prescaler;

        class Channel {
            static constexpr uint8_t admux_mask = BitMask<(channel_mux_bits>5?5:channel_mux_bits)>::right;

        public:
            YAAL_INLINE("AnalogDigitalConverter::Channel::set")
            void set(uint8_t mux) {
                Atomic block;
                if (channel_mux_bits > 5) {
                    if (mux & (1 << MUX5))
                        ADCSRB |= (1 << MUX5);
                    else
                        ADCSRB &= ~(1 << MUX5);
                }
                // MUX0 .. MUX4 (or less)
                ADMUX = (ADMUX & ~admux_mask) | (mux & admux_mask);
            }

            YAAL_INLINE("AnalogDigitalConverter::Channel::set")
            uint8_t get() {
                Atomic block;
                uint8_t mux = ADMUX & admux_mask;
                if (channel_mux_bits > 5) {
                    if (ADCSRB & (1 << MUX5))
                        mux |= (1 << MUX5);
                }
                return mux;
            }

            template<typename AdcSingleChannelClass>
            YAAL_INLINE("AnalogDigitalConverter::Channel::operator= template")
            Channel& operator= (AdcSingleChannelClass adc) {
                set(adc.mux);
                return *this;
            }

            YAAL_INLINE("AnalogDigitalConverter::Channel::operator=")
            Channel& operator= (uint8_t mux) {
                set(mux);
                return *this;
            }
        } channel;

        YAAL_INLINE("AnalogDigitalConverter::enable")
        void enable() {
            Atomic block; // FIXME: should be done on register if needed
            ADCSRA |= (1 << ADEN);
        }

        YAAL_INLINE("AnalogDigitalConverter::disable")
        void disable() {
            Atomic block; // FIXME: should be done on register if needed
            ADCSRA &= ~(1 << ADEN);
        }

        YAAL_INLINE("AnalogDigitalConverter::on")
        bool is_on() const {
            return ADCSRA & (1 << ADEN);
        }

        YAAL_INLINE("AnalogDigitalConverter::start_conversion")
        void start_conversion() {
            Atomic block;
            ADCSRA |= (1 << ADSC);
        }

        YAAL_INLINE("AnalogDigitalConverter::converting")
        bool is_converting() const {
            return ADCSRA & (1 << ADSC);
        }

        YAAL_INLINE("AnalogDigitalConverter::single_conversion")
        uint16_t single_conversion() {
            // should we instead use concept:
            // adc.enable();
            // adc.request_single_conversion(0);
            // while(adc.converting();
            // utin16_t value = adc.get();
            //enable(); // FIXME: should this be done only in safe mode?
            while (is_converting());
            start_conversion();
            // FIXME: this will never return if adc is not enabled.
            while (is_converting());
            // FIXME: is this atomic useless?
            {
                Atomic block;
                return ADC;
            }
        }

        YAAL_INLINE("AnalogDigitalConverter::single_conversion with mux")
        uint16_t single_conversion(uint8_t mux) {
            channel = mux;
            return single_conversion();
        }

        template<typename AdcSingleChannelClass>
        YAAL_INLINE("AnalogDigitalConverter::single_conversion with class")
        uint16_t single_conversion(AdcSingleChannelClass adc) {
            channel = adc.mux;
            if (adc.aref == Reference::ANY) {
                return single_conversion();
            } else {
                // When adc has special reference, apply it
                typename Reference::Source old = reference;
                reference = adc.aref;
                uint16_t result = single_conversion();
                reference = old;
                return result;
            }
        }

    };

    /*
    void sleep() {
        Adc0 adc;
        typename AnalogDigitalConverter::sleep_memory adc_memory = adc.pre_sleep();
        internal::sleep();
        adc.post_sleep(adc_memory);
    }
    */

    template<uint8_t adc_mux, typename AdcUnitClass,
            typename AdcUnitClass::Reference::Source aref_src = AdcUnitClass::Reference::ANY>
    class AdcSingleChannel {
    public:
        typedef AdcUnitClass Unit;

        static constexpr uint8_t mux = adc_mux;
        static constexpr typename AdcUnitClass::Reference::Source aref = aref_src;
        AdcUnitClass unit;

        YAAL_INLINE("AdcSingleChannel::get")
        uint16_t read() {
            return unit.single_conversion(*this);
        }
    };
}

#endif // YAAL_ADC_DISABLED

#endif
#endif
