#ifndef __YAAL_COMMUNICATION__I2C_HW__
#define __YAAL_COMMUNICATION__I2C_HW__ 1
#include "../requirements.hh"
#ifdef __YAAL__

#include <avr/interrupt.h>
#include <compat/twi.h>

namespace yaal {

    class HWI2CBus {
        typedef HWI2CBus self_type;

        volatile uint8_t databyte;
        volatile uint8_t addressbyte;

        volatile bool sending;
        volatile bool receiving;
    public:

        void setup(uint16_t speed = 100) {
            // 1. Set bitrate
            // TWBR = ((F_CPU / F_SCL) - 16)/(2 * Prescaler)
            // FIXME: select prescaler dynamically instead of just using 1.
            const uint8_t prescaler = 1;
            TWSR &= ~(1 << TWPS0);
            TWSR &= ~(1 << TWPS1);

            TWBR = ((F_CPU/speed/1000UL) - 16UL)/prescaler/2UL;

            // 2. Enable TWI acknowledge, enable TWI, enable TWI interrupt
            TWCR = (1 << TWEA) | (1 << TWEN) | (1 << TWIE);
        }

        void write(uint8_t address, uint8_t data) {
            databyte = data;
            addressbyte = address;
            sending = true;
            TWCR |= (1 << TWSTA);

            while (sending);
        }

        uint8_t read(uint8_t address) {
            addressbyte = address;
            databyte = 0x00;
            receiving = true;
            TWCR |= (1 << TWSTA);
            while (receiving);

            return databyte;
        }

        void isr() {
            uint8_t status = TW_STATUS;
            switch (status) {
                case TW_START:
                case TW_REP_START:
                    if (receiving)
                        TWDR = (addressbyte << 1) | 0x01;
                    else
                        TWDR = (addressbyte << 1) & 0xFE;
                    TWCR = (1 << TWEA) | (1 << TWEN) | (1 << TWIE) | (1 << TWINT);
                    break;
                case TW_MT_SLA_ACK:
                    // Should send data byte.
                    TWDR = databyte;
                    TWCR = (1 << TWEA) | (1 << TWEN) | (1 << TWIE) | (1 << TWINT);
                    break;
                case TW_MR_DATA_NACK:
                    // Should get byte and then stop.
                    databyte = TWDR;
                    // Intentional fall-through.
                case TW_MT_DATA_ACK:
                    // All went well. Send stop.
                    // Intentional fall-through.
                case TW_MR_SLA_NACK:
                case TW_MT_SLA_NACK:
                case TW_MT_DATA_NACK:
                    // Send stop.
                    TWCR = (1 << TWEA) | (1 << TWSTO) | (1 << TWEN) | (1 << TWIE) | (1 << TWINT); 
                    sending = false;
                    receiving = false;
                    break;
                case TW_MR_SLA_ACK:
                    // Should get data byte. Need to NACK.
                    TWCR = (1 << TWEN) | (1 << TWIE) | (1 << TWINT);
                    break;
            }
        }
        
    };


    HWI2CBus I2c_HW;
}


SIGNAL(TWI_vect) {
    yaal::I2c_HW.isr();
}
#endif
#endif
