#ifndef __YAAL_TIMERS__TIMERTYPES__
#define __YAAL_TIMERS__TIMERTYPES__ 1

#include <inttypes.h>
#include "../bitmask.hh"

namespace yaal {

    /* NOTES:
       Most optimal would be assining timer control values as bytes:
         TCCR0A = control_bits_a;
         TCCR0B = control_bits_b & ~clock_select_bits;
       FIXME: Is it possible to write code chuck taht would be possible?

       Meanwhile we toggle bits up/down by feature.
     */


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


    template<typename PrescalerClass>
    class Timer {
    public:
        typedef PrescalerClass prescaler;
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
    template<typename PrescalerClass>
    class Timer8 : public Timer<PrescalerClass> {
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

    template<typename PrescalerClass>
    class Timer10 : public Timer<PrescalerClass> {
    
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
    template<typename PrescalerClass>
    class Timer16 : public Timer<PrescalerClass> {
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


    template<typename TimerClass>
    class AsyncronousTimer : public TimerClass {
    
    };




    /* 10-bit async timer's prescaler:
    Mode, CS43 CS42 CS41 CS40, Asynchronous Clocking Mode, Synchronous Clocking Mode
    0, 0 0 0 0, T/C4 stopped   T/C4 stopped
    1, 0 0 0 1, PCK            CK
    2, 0 0 1 0, PCK/2          CK/2
    3, 0 0 1 1, PCK/4          CK/4
    4, 0 1 0 0, PCK/8          CK/8
    5, 0 1 0 1, PCK/16         CK/16
    6, 0 1 1 0, PCK/32         CK/32
    7, 0 1 1 1, PCK/64         CK/64
    8, 1 0 0 0, PCK/128        CK/128
    9, 1 0 0 1, PCK/256        CK/256
    a, 1 0 1 0, PCK/512        CK/512
    b, 1 0 1 1, PCK/1024       CK/1024
    c, 1 1 0 0, PCK/2048       CK/2048
    d, 1 1 0 1, PCK/4096       CK/4096
    e, 1 1 1 0, PCK/8192       CK/8192
    f, 1 1 1 1, PCK/16384      CK/16384
    */

    /* 8 and 16-bit timer's prescaler:
    Mode, CSn2 CSn1 CSn0, clocking mode
    0, 0 0 0, no clock - stopped
    1, 0 0 1, clk_io - no prescaler
    2, 0 1 0, clk_io/8
    3, 0 1 1, clk_io/64
    4, 1 0 0, clk_io/256
    5, 1 0 1, clk_io/1024
    6, 1 1 0, extern on Tn, Falling edge
    7, 1 1 1, extern on Tn, Rising edge
    */

    namespace internal {
        template<uint8_t mode_bits>
        class _Prescaler {
        public:
            enum ClockMode;
            // TODO: prescaler control, ks. atmega32u4 12.4.

            // FIXME: is Control allways TCCRnB?
            template<typename Control>
            void start(ClockMode mode) {
                Control cntrl;
                if (mode_bits > 3)
                    if (mode & 0x8)
                        cntrl |= 0x8;
                if (mode_bits > 2)
                    if (mode & 0x4)
                        cntrl |= 0x4;
                if (mode_bits > 1)
                    if (mode & 0x2)
                        cntrl |= 0x2;
                if (mode_bits > 0)
                    if (mode & 0x1)
                        cntrl |= 0x1;
            }

            template<typename Control>
            void stop() {
                Control cntrl;
                // For 2 or fewer bits this is slower
                // For 3 bits this is as fast as using cbi
                // For 4 or more bits this is faster
                cntrl &= ~BitMask<mode_bits>;
                // in rN, port      ; 1 cycle
                // ori rN, bitmask  ; 1 cycle
                // out port, rN     ; 1 cycle
            }
        }
    };

    template<uint8_t mode_bits = 3
    class Prescaler : public internal::_Prescaler<mode_bits> { };

    template<>
    class Prescaler<3> : public internal::_Prescaler<3> {
    public:
        enum ClockMode {
            STOPPED,
            CLK,
            CLK_8,
            CLK_64,
            CLK_256,
            CLK_1024,
            EXTERN_FALLING,
            EXTERN_RISING
        };
    };

    template<>
    class Prescaler<4> : public internal::_Prescaler<4> {
        enum ClockMode {
            STOPPED,
            CLK,
            CLK_2,
            CLK_4,
            CLK_8,
            CLK_16,
            CLK_32,
            CLK_64,
            CLK_128,
            CLK_256,
            CLK_512,
            CLK_1024,
            CLK_2048,
            CLK_4096,
            CLK_8192,
            CLK_16384
        };
    };



    // Teensy 2


    // timers 0, 1, 3 share same prescaler, but has own clock sources.
    // this means that we can syncronize timers 0, 1, 3
    typedef Timer8<
        Prescaler<3>,
        TimerControl<
            Tcnt0, // counter
            Tifr0, TOV0,
            Timsk0, TOIE0,
            TimerMode<Tccr0a, WGM00, Tccr0a, WGM01, Tccr0b, WGM02>,
            OutputCompare<Ocr0a, Tccr0a, COM0A0, Tccr0a, COM0A1, Tccr0b, FOC0A, Tifr0, OCF0A, Timsk0, OCIE0A>,
            OutputCompare<Ocr0b, Tccr0a, COM0B0, Tccr0a, COM0B1, Tccr0b, FOC0B, Tifr0, OCF0B, Timsk0, OCIE0B>,
            PrescaleSelect<Tccr0b, CS02, Tccr0b, CS01, Tccr0b, CS00>,
        >,
    > timer0;

    typedef Timer16<
        Prescaler<3>,
    > timer1;

    typedef Timer16<
        Prescaler<3>,
    > timer3;

    typedef AsyncronousTimer<Timer10<
        Prescaler<4>,
    >> timer4;
}

#endif
