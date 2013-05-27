#ifndef __YAAL_IO__TYPES__SERIAL__
#define __YAAL_IO__TYPES__SERIAL__ 1
#include "../../requirements.hh"
#ifdef __YAAL__

// FIXME: should not need avr/io.hh here.
#include <avr/io.h>
#include "register.hh"
#include "../../core/cpu.hh"
#include "../../types/autounion.hh"

namespace yaal {

    enum Parity {
        PARITY_DISABLED,
        PARITY_EVEN,
        PARITY_ODD
    };

    enum StopBits {
        STOP_ONE,
        STOP_TWO
    };

    enum DataBits {
        DATA_FIVE = 5,
        DATA_SIX = 6,
        DATA_SEVEN = 7,
        DATA_EIGHT = 8,
        DATA_NINE = 9
    };

    namespace internal {

        // FIXME: no synchronous mode, no MSPIM mode
        template< typename dataRegister,
                  typename controlARegister,
                  typename controlBRegister,
                  typename controlCRegister,
                  typename ubrrRegister >
        class Serial {
            static dataRegister data;
            static controlARegister controlA;
            static controlBRegister controlB;
            static controlCRegister controlC;
            static ubrrRegister ubrr;

        public:
            YAAL_INLINE("Serial::setup")
            static void setup(uint32_t baud = 9600,
                       DataBits databits = DATA_EIGHT,
                       StopBits stopbits = STOP_ONE,
                       Parity parity = PARITY_DISABLED,
                       bool enableRX = true,
                       bool enableTX = true)
            {
                setMode();
                setBaud(baud);
                setFrameFormat(databits, stopbits, parity, enableRX, enableTX);
            }

            YAAL_INLINE("Serial::setMode")
            static void setMode() {
                // FIXME: Only asynchronous mode
                controlC &= ~((1 << UMSEL10) | (1 << UMSEL11));
            }

            YAAL_INLINE("Serial::setBaud")
            static void setBaud(uint32_t baud) {
                uint32_t f_cpu = cpu.clock; // get static or dynamic cpu clock frequency
                bool use_u2x;
// FIXME
#if defined(U2X)
                internal::SingleBit<controlARegister, U2X> u2x;
#elif defined(U2X0)
                internal::SingleBit<controlARegister, U2X0> u2x;
#elif defined(U2X1)
                internal::SingleBit<controlARegister, U2X1> u2x;
#endif

                // from datasheet: UBRR = F_CPU / (16UL * BAUD);
                // from setbaud.h: UBRR = (F_CPU + 8UL * BAUD) / (16UL * BAUD);
                // calculate value for 16(UBRR + 1), which is used later as is
                uint16_t ubrr_val;
                {
                    uint32_t ubrr_tmp = f_cpu / baud;
                    if (ubrr_tmp > 0xffff) {
                        // ERROR: wont fit in 12-bit UBRR register (max value is 4095)
                        return;
                    }
                    ubrr_val = static_cast<uint32_t>(ubrr_tmp);
                }

#if 1
                // Basically baud rate isn't what it's supposed to be
                // if bits lost in division have lot of meaning,
                // So lets have very simple test
                // NOTE: This is tested with common F_CPUs and BAUDs (refer serial_baud_test.py)
                use_u2x = (static_cast<uint8_t>(ubrr_val) & 0xf) > (ubrr_val >> 6);
#else
                // this is left here as another (more accurate) implementation as it should be good enough
                use_u2x = false;
                // if ubrr_val * 2 still fits, so we can try to find out if better tolerance can be archieved using u2x
                if (ubrr_val < (4096/2 * 16)) {
                    // from setbaud.h
                    // check that result is in 2% tolerance margin (BAUD_TOL = 2)
                    // 100 * (F_CPU) > (16 * ((UBRR_VALUE) + 1)) * (100 * (BAUD) + (BAUD) * (BAUD_TOL))
                    // 100 * (F_CPU) < (16 * ((UBRR_VALUE) + 1)) * (100 * (BAUD) - (BAUD) * (BAUD_TOL))

                    // we use 128 as scaler (7-bits), that means that maxinum freq is ~33MHz, so this code should work up to 32MHz clocks
                    // as we use 128, then ~1.56% tolerance is nice as it's 2 (1.56/100*128), which is one bitshift
                    uint32_t scaled_f_cpu = f_cpu << 7; // 128 * f_cpu
                    uint32_t scaled_baud = baud << 7; // 128 * baud
                    uint32_t baud_tol = baud << 1; // 128 * baud * (tolerance% / 100)
                    uint32_t ubrr_filtered = ubrr_val & 0xfff0; // (UBRR/16)*16 aka (UBRR >> 4) << 4
                    // if any of following, then use u2x
                    // 128 * F_CPU  >  16*(UBRR+1) * (128 * baud + 128 * baud * (tolerance%/100))
                    // 128 * F_CPU  <  16*(UBRR+1) * (128 * baud - 128 * baud * (tolerance%/100))
                    use_u2x = (scaled_f_cpu > ubrr_filtered * (scaled_baud + baud_tol)) || \
                              (scaled_f_cpu < ubrr_filtered * (scaled_baud - baud_tol));
#if 0
                    if (use_u2x) {
                        ubrr_filtered = ubrr_val % 0xfff8; // (UBRR/8)*8 aka (UBRR >> 3) << 3;

                        if (scaled_f_cpu > ubrr_filtered * (scaled_baud + baud_tol)) || \
                           (scaled_f_cpu < ubrr_filtered * (scaled_baud - baud_tol))
                        {
                            // ERROR: Baud rate not in tolerance
                            return;
                        }
                    }
#endif
                }
#endif

                // u2x = true;  UBRR = ubrr_val/8 - 1
                // u2x = false; UBRR = ubrr_val/16 - 1
                ubrr_val >>= 3;
                if (!use_u2x)
                    ubrr_val >>= 1;
                ubrr = ubrr_val - 1;
                // set/clear u2x bit in control register
                u2x = use_u2x;
            }

            YAAL_INLINE("Serial::setFrameFormat")
            static void setFrameFormat(DataBits databits = DATA_EIGHT,
                                StopBits stopbits = STOP_ONE,
                                Parity parity = PARITY_DISABLED,
                                bool enableRX = true,
                                bool enableTX = true)
            {
                // Enable receiver and transmitter if asked to.
                controlB = (enableRX ? (1<<RXEN1) : 0)|
                           (enableTX ? (1<<TXEN1) : 0);

                // Set frame format.

                // Parity bits.
                if (parity == PARITY_DISABLED)
                    controlC &= ~((1<<UPM10)|(1<<UPM11));
                else if (parity == PARITY_EVEN) {
                    controlC &= ~(1<<UPM10);
                    controlC |= (1<<UPM11);
                }
                else
                    controlC |= (1<<UPM10)|(1<<UPM11);

                // Stop bits.
                if (stopbits == STOP_ONE)
                    controlC &= ~(1<<USBS1);
                else
                    controlC |= (1<<USBS1);

                // Data bits.
                if (databits == DATA_NINE) {
                    controlC |= (1<<UCSZ10)|(1<<UCSZ11)|(1<<UCSZ12);
                }
                else if (databits == DATA_EIGHT) {
                    controlC &= ~(1<<UCSZ12);
                    controlC |= (1<<UCSZ10)|(1<<UCSZ11);
                }
                else if (databits == DATA_SEVEN) {
                    controlC &= ~((1<<UCSZ10)|(1<<UCSZ12));
                    controlC |= (1<<UCSZ11);
                }
                else if (databits == DATA_SIX) {
                    controlC &= ~((1<<UCSZ11)|(1<<UCSZ12));
                    controlC |= (1<<UCSZ10);
                }
                else if (databits == DATA_FIVE) {
                    controlC &= ~(1<<UCSZ10)|(1<<UCSZ11)|(1<<UCSZ12);
                }
            }

            YAAL_INLINE("Serial::put")
            void put(uint8_t value) {
                // XXX: I guess it's OK to use UDRE1 here instead of UDREn?
                while (!(controlA & (1<<UDRE1)));
                data = value;
            }

            YAAL_INLINE("Serial::get")
            uint8_t get() {
                // XXX: I guess it's OK to use RXC1 here instead of UDREn?
                while (!(controlA & (1<<RXC1)));
                return data;
            }

            template<typename T>
            YAAL_INLINE("Serial::write")
            void write(const T value) {
                autounion<T> data = value;
                for (uint8_t i = 0; i < data.size; ++i)
                    put(data[i]);
            }

            template<typename T>
            YAAL_INLINE("Serial::read")
            void read(T& data) {
                autounion<T> res;
                for (uint8_t i = 0; i < res.size; i++)
                    res[i] = get();
                data = res;
            }

        };
    }
}

#endif
#endif
