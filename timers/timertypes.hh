#ifndef __YAAL_TIMERS__TIMERTYPES__
#define __YAAL_TIMERS__TIMERTYPES__ 1

namespace yaal {

    // FIXME: should we order these: wgm0, wgm1, wgm2
    template<typename Wgm2Class, typename Wgm1Class, typename Wgm0Class>
    class __TimerMode {
        enum Mode {
            // name, top, update of OCRx at, TOV Flag Set on
            _NORMAL = 0, // 0xff, Immediate, MAX
            _PHASE_CORRECT_TOP = 1, // 0xff, TOP, BOTTOM
            _CTC = 2, // OCRA, Immediate, MAX
            _FAST_PWM_TOP = 3, // 0xff, TOP, MAX
            // reserved
            _PHASE_CORRECT_OCR = 5, // OCRA, TOP, BOTTOM
            // reserved
            _FAST_PWM_OCR = 7, // OCRA, TOP, TOP
        };

        void set(Mode mode) {
            Wgm2Class = (bool)(mode & 0x04);
            Wgm1Class = (bool)(mode & 0x02);
            Wgm0Class = (bool)(mode & 0x01);
        }
    };

    template<uint8_t wgm0, uint8_t wgm1, uint8_t wgm2, uint8_t wgm3 = 0>
    struct TimerMode {
        static uint8_t A = wgm0 | wgm1;
        static uint8_t B = wgm2 | wgm3;
    };

    template<typename TimerMode_s, uint8_t CompareModeA, uint8_t CompareModeB>
    struct TimerControl {
        static uint8_t control_a_mask = TimerMode_s::A | CompareModeA | CompareModeB;
        static uint8_t control_b_mask = TimerMode_s::B;
    };

    template<typename TimerMode_s, uint8_t CompareModeA, uint8_t CompareModeB, uint8_t CompareModeC>
    struct TimerControl {
        static uint8_t control_a_mask = TimerMode_s::A | CompareModeA | CompareModeB | CompareModeC;
        static uint8_t control_b_mask = TimerMode_s::B;
    };


    /* Timer/Counter0 is a general purpose 8-bit Timer/Counter module,
       with two independent Output Compare Units, and with PWM support.
       It allows accurate program execution timing (event management)
       and wave generation. The main features are:
       - Two Independent Output Compare Units
       - Double Buffered Output Compare Registers
       - Clear Timer on Compare Match (Auto Reload) (CTC)
       - Glitch Free, Phase Correct Pulse Width Modulator (PWM)
       - Variable PWM Period
       - Frequency Generator
       - Three Independent Interrupt Sources (TOV0, OCF0A, and OCF0B)
     */
    class Timer8 {
        typedef Tcnt0 counter;
        // 8 bit unsigned
        typedef Ocr0a out_a;
        // 8 bit unsigned
        typedef Ocr0b out_b;
        // 8 bit unsigned
        typedef Tccr0a ctrl_a;
        // COM0A1, COM0A0, COM0B1, COM0B0, -, -, WGM01, WGM00
        typedef Tccr0b ctrl_b;
        // W:FOC0A, W:FOC0B, -, -, WGM02, CS02, CS01, CS00
        typedef Tifr0 interrupt_register;
        // -, -, -, -, -, OCF0B, OCF0A, TOV0
        typedef Timsk0 interrupt_mask;
        // -, -, -, -, -, OCIE0B, OCIE0A, TOIE0
        uint8_t max = 0xff;
        // top == max or top == ocr0a

        void setup() {
            ctrl_a = TimerControl::control_a_mask;
            ctrl_b = TimerControl::control_b_mask;
        }

        void start() {
            if (Prescaler::value & 0x04)
                ctrl_b |= Prescaler::CS2;
            if (Prescaler::value & 0x02)
                ctrl_b |= Prescaler::CS1;
            if (Prescaler::value & 0x01)
                ctrl_b |= Prescaler::CS0;
        }

        void stop() {
            ctrl_b = TimerControl::control_b_mask;
        }
    };

    class Timer10 {
    
    };

    /* The 16-bit Timer/Counter unit allows accurate
       program execution timing (event management),
       wave generation, and signal timing measurement.
       The main features are:
       - True 16-bit Design (i.e., Allows 16-bit PWM)
       - Three independent Output Compare Units
       - Double Buffered Output Compare Registers
       - One Input Capture Unit
       - Input Capture Noise Canceler
       - Clear Timer on Compare Match (Auto Reload)
       - Glitch-free, Phase Correct Pulse Width Modulator (PWM)
       - Variable PWM Period
       - Frequency Generator
       - External Event Counter
       - Ten independent interrupt sources
         (TOV1, OCF1A, OCF1B, OCF1C, ICF1, TOV3,
          OCF3A, OCF3B, OCF3C and ICF3)
     */
    /* To do a 16-bit write, the high byte must be written
       before the low byte. For a 16-bit read, the low
       byte must be read before the high byte.
       NOTE: avr-gcc should handle this when using *(volatile uint16_t*) = value
     */
    class Timer16 {
        typedef Tccr1a ctrl_a;
        // COM1A1, COM1A0, COM1B1, COM1B0, COM1C1, COM1C0, WGM11, WGM10
        typedef Tccr1b ctrl_b;
        // ICNC1, ICES1, -, WGM13, WGM12, CS12, CS11, CS10
        typedef Tccr1C ctrl_c;
        // W:FOC1A, W:FOC1B, W:FOC1C
        typedef Tcnt1 counter;
        // 16 bit unsigned
        typedef Ocr1a out_a;
        // 16 bit unsigned
        typedef Ocr1b out_b;
        // 16 bit unsigned
        typedef Ocr1c out_c;
        // 16 bit unsigned
        typedef Icr1 capture;
        // 16 bit unsigned, updated by value of TCNT1 when ICP pin triggers
        typedef Timsk1 interrupt_mask;
        // -, -, ICIE1, -, OCIE1C, OCIE1B, OCIE1A, TOIE1
        typedef Tifr1 interrupt_register;
        // -, -, ICF1, -, OCF1C, OCF1B, OCF1A, TOV1
        
        
    };

    class AsyncronousTimer {
    
    };
}

#endif
