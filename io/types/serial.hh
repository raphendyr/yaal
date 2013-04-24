#ifndef __YAAL_IO__TYPES__SERIAL__
#define __YAAL_IO__TYPES__SERIAL__ 1
#include "../../requirements.hh"
#ifdef __YAAL__

// FIXME: should not need avr/io.hh here.
#include <avr/io.h>
#include "register.hh"
#include "../../core/cpu.hh"
#include "../../interface/stream.hh"

// Some bit definitions for the control registers.
// Not all chips have USART0, so we try the USART1-specific constants if needed.
#ifdef UMSEL0
#   define HAVE_SERIAL
#   define UMSELX0 UMSEL0
#   define UMSELX1 UMSEL1
#   define RXENX RXEN
#   define TXENX TXEN
#   define UPMX0 UPM0
#   define UPMX1 UPM1
#   define USBSX USBS
#   define UCSZX0 UCSZ0
#   define UCSZX1 UCSZ1
#   define UCSZX2 UCSZ2
#   define UDREX UDRE
#   define RXCX RXC
#   define U2XX U2X
#elif defined(UMSEL00)
#   define HAVE_SERIAL
#   define UMSELX0 UMSEL00
#   define UMSELX1 UMSEL01
#   define RXENX RXEN0
#   define TXENX TXEN0
#   define UPMX0 UPM00
#   define UPMX1 UPM01
#   define USBSX USBS0
#   define UCSZX0 UCSZ00
#   define UCSZX1 UCSZ01
#   define UCSZX2 UCSZ02
#   define UDREX UDRE0
#   define RXCX RXC0
#   define U2XX U2X0
#elif defined(UMSEL10)
#   define HAVE_SERIAL
#   define UMSELX0 UMSEL10
#   define UMSELX1 UMSEL11
#   define RXENX RXEN1
#   define TXENX TXEN1
#   define UPMX0 UPM10
#   define UPMX1 UPM11
#   define USBSX USBS1
#   define UCSZX0 UCSZ10
#   define UCSZX1 UCSZ11
#   define UCSZX2 UCSZ12
#   define UDREX UDRE1
#   define RXCX RXC1
#   define U2XX U2X1
#else
#       warning "This chip doesn't seem to have an USART. Serial disabled."
#endif

#ifdef HAVE_SERIAL
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
# define yaal__SerialType Serial<dataRegister, controlARegister, controlBRegister, controlCRegister, ubrrRegister>
        template< typename dataRegister,
                  typename controlARegister,
                  typename controlBRegister,
                  typename controlCRegister,
                  typename ubrrRegister >
        class Serial : public interface::ReadWriteBase< yaal__SerialType >,
                       public interface::ReadStream< yaal__SerialType >,
                       public interface::WriteStream< yaal__SerialType > {
 # undef yaal__SerialType

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
                controlC &= ~((1 << UMSELX0) | (1 << UMSELX1));
            }

            YAAL_INLINE("Serial::setBaud")
            static void setBaud(uint32_t baud) {
                uint32_t f_cpu = cpu.clock; // get static or dynamic cpu clock frequency
                bool use_u2x;
                internal::SingleBit<controlARegister, U2XX> u2x;

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
                    ubrr_val = static_cast<uint16_t>(ubrr_tmp);
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
                controlB = (enableRX ? (1<<RXENX) : 0)|
                           (enableTX ? (1<<TXENX) : 0);

                // Set frame format.

                // Parity bits.
                if (parity == PARITY_DISABLED)
                    controlC &= ~((1<<UPMX0)|(1<<UPMX1));
                else if (parity == PARITY_EVEN) {
                    controlC &= ~(1<<UPMX0);
                    controlC |= (1<<UPMX1);
                }
                else
                    controlC |= (1<<UPMX0)|(1<<UPMX1);

                // Stop bits.
                if (stopbits == STOP_ONE)
                    controlC &= ~(1<<USBSX);
                else
                    controlC |= (1<<USBSX);

                // Data bits.
                if (databits == DATA_NINE) {
                    controlC |= (1<<UCSZX0)|(1<<UCSZX1)|(1<<UCSZX2);
                }
                else if (databits == DATA_EIGHT) {
                    controlC &= ~(1<<UCSZX2);
                    controlC |= (1<<UCSZX0)|(1<<UCSZX1);
                }
                else if (databits == DATA_SEVEN) {
                    controlC &= ~((1<<UCSZX0)|(1<<UCSZX2));
                    controlC |= (1<<UCSZX1);
                }
                else if (databits == DATA_SIX) {
                    controlC &= ~((1<<UCSZX1)|(1<<UCSZX2));
                    controlC |= (1<<UCSZX0);
                }
                else if (databits == DATA_FIVE) {
                    controlC &= ~(1<<UCSZX0)|(1<<UCSZX1)|(1<<UCSZX2);
                }
            }

            YAAL_INLINE("Serial::put")
            void put(uint8_t value) {
                while (!(controlA & (1<<UDREX)));
                data = value;
            }

            YAAL_INLINE("Serial::get")
            uint8_t get() {
                while (!(controlA & (1<<RXCX)));
                return data;
            }
        };
    }
}

#endif
#endif
#endif
