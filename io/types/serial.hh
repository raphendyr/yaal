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
        template< typename dataister,
                  typename controlAister,
                  typename controlBister,
                  typename controlCister,
                  typename ubrrRegister >
        class Serial {
            static dataister data;
            static controlAister controlA;
            static controlBister controlB;
            static controlCister controlC;
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
            static void setBaud(uint32_t baud, bool U2X = false) {
                ubrr = F_CPU/(baud)/(U2X ? 8UL : 16UL) - 1UL;
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
