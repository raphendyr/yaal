#ifndef __YAAL_IO__TYPES__SERIAL__
#define __YAAL_IO__TYPES__SERIAL__ 1
#include "../../requirements.hh"
#ifdef __YAAL__

// FIXME: should not need avr/io.hh here.
#include <avr/io.h>
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
        template< typename udrRegister,
                  typename ucsrARegister,
                  typename ucsrBRegister,
                  typename ucsrCRegister,
                  typename ubrrlRegister,
                  typename ubrrhRegister >
        class Serial {
            udrRegister udrReg;
            ucsrARegister ucsrAReg;
            ucsrBRegister ucsrBReg;
            ucsrCRegister ucsrCReg;
            ubrrlRegister ubrrlReg;
            ubrrhRegister ubrrhReg;

        public:
            YAAL_INLINE("Serial set mode")
            void setMode() {
                // FIXME: Only asynchronous mode
                ucsrCReg &= ~((1<<UMSEL10)|(1<<UMSEL11));
            }

            YAAL_INLINE("Serial set baud")
            void setBaud(uint32_t baud, bool U2X = false) {
                autounion<uint16_t, false> ubrr = F_CPU/(baud)/(U2X ? 8UL : 16UL) - 1UL;
                ubrrhReg = ubrr[0];
                ubrrlReg = ubrr[1];
            }

            YAAL_INLINE("Serial set frame format")
            void setFrameFormat(enum DataBits databits = DATA_EIGHT,
                                enum StopBits stopbits = STOP_ONE,
                                enum Parity parity = PARITY_DISABLED,
                                bool enableRX = true,
                                bool enableTX = true) {

                // Enable receiver and transmitter if asked to.
                ucsrBReg = (enableRX ? (1<<RXEN1) : 0)|
                           (enableTX ? (1<<TXEN1) : 0);

                // Set frame format.

                // Parity bits.
                if (parity == PARITY_DISABLED)
                    ucsrCReg &= ~((1<<UPM10)|(1<<UPM11));
                else if (parity == PARITY_EVEN) {
                    ucsrCReg &= ~(1<<UPM10);
                    ucsrCReg |= (1<<UPM11);
                }
                else
                    ucsrCReg |= (1<<UPM10)|(1<<UPM11);

                // Stop bits.
                if (stopbits == STOP_ONE)
                    ucsrCReg &= ~(1<<USBS1);
                else
                    ucsrCReg |= (1<<USBS1);

                // Data bits.
                if (databits == DATA_NINE) {
                    ucsrCReg |= (1<<UCSZ10)|(1<<UCSZ11)|(1<<UCSZ12);
                }
                else if (databits == DATA_EIGHT) {
                    ucsrCReg &= ~(1<<UCSZ12);
                    ucsrCReg |= (1<<UCSZ10)|(1<<UCSZ11);
                }
                else if (databits == DATA_SEVEN) {
                    ucsrCReg &= ~((1<<UCSZ10)|(1<<UCSZ12));
                    ucsrCReg |= (1<<UCSZ11);
                }
                else if (databits == DATA_SIX) {
                    ucsrCReg &= ~((1<<UCSZ11)|(1<<UCSZ12));
                    ucsrCReg |= (1<<UCSZ10);
                }
                else if (databits == DATA_FIVE) {
                    ucsrCReg &= ~(1<<UCSZ10)|(1<<UCSZ11)|(1<<UCSZ12);
                }
            }

            template<typename T>
            YAAL_INLINE("Serial transmit")
            void transmit(T val) {
                autounion<T, false> value = val;
                for (uint8_t i = 0; i < value.size; ++i)
                    transmit(value[i]);
            }

            YAAL_INLINE("Serial transmit byte")
            void transmit(uint8_t value) {
                // XXX: I guess it's OK to use UDRE1 here instead of UDREn?
                while (!(ucsrAReg & (1<<UDRE1)));
                udrReg = value;
            }

            YAAL_INLINE("Serial receive")
            uint8_t receive() {
                // XXX: I guess it's OK to use RXC1 here instead of UDREn?
                while (!(ucsrAReg & (1<<RXC1)));

                return udrReg;
            }
        };
    }
}

#endif
#endif
