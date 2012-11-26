#ifndef __YAAL_COMMUNICATION__I2C__
#define __YAAL_COMMUNICATION__I2C__ 1
#include "../requirements.hh"
#ifdef __YAAL__

#include "../io/types/pin.hh"
#include "shift.hh"

namespace {

    /* I2CBus<SDA, SCL, speed, internal_pullup> */
    template< typename SDAPin,
              typename SCLPin,
              uint16_t speed = 100,
              bool internal_pullup = false >
    class I2CBus {
        typedef I2C<SDAPin, SCLPin, speed, internal_pullup> self_type;
        typedef Floating<SDAPin, internal_pullup> SDA;
        typedef Floating<SCLPin, internal_pullup> SCL;

        SDA sda;
        SCL scl;

    public:

        void setup() {
            sda = false;
            scl = false;
        }

        template<typename T>
        void write(uint8_t address, uint8_t address_bits, T data, uint8_t bits = (sizeof(T) * 8)) {
            shiftBitsIf<SCL, SDA>(bits + address_bits + 1, [&address, &address_bits, &data](uint8_t i){
                bool ret;
                if (i < address_bits) {
                    ret = address & 0x80;
                    address <<= 1;
                } else if (i == 7) {
                    // this is allways read/write bit
                    ret = true;
                } else {
                    ret = data & (1 << (8*sizeof(T) - 1));
                    data <<= 1;
                }
                return ret;
            });
        }

    private:
        void delay() {
            _delay_us(4);
        }

        /* State checks */

        /* Clock stretching */
        void clock_strecthing() {
            /* NOTE: be sure that scl is released before this */
            /* release_scl(); */
            while (scl);  /* FIXME: We should add timeout to this loop */
        }

        void check_sda_arbitration() {
            /* NOTE: be sure that sda is released before this */
            if (sda)
                ARBITRATION_LOST();
        }

        /* Single operations */
        void master_start() {
            /* restart */
            if (scl.mode.is_output()) {
                /* Release sda, if not allready */
                sda = false;
                delay();
                scl = false;
                /* Clock stretching */
                clock_strecthing();
            }
            /* SDA and SCL realeased (high) */
            check_sda_arbitration();
            /* SDA 1->0 , then SCL 1->0 */
            sda = true;
            delay();
            scl = true;
        }

        void master_stop() {
            /* pull SDA to 0 */
            sda = true;
            delay();
            /* first release SCL */
            scl = false;
            /* Clock stretching */
            clock_strecthing();
            /* SCL is released, release SDA */
            sda = false;
            delay();
            check_sda_arbitration();
        }

        /* Write a bit to I2C bus */
        void master_write_bit(bool bit) {
            if (bit)
                sda = false;
            else
                sda = true;
            delay();
            scl = false;
            /* Clock stretching */
            clock_strecthing();
            /* SCL is high, now data is valid */
            /* If SDA is high, check that nobody else is driving SDA */
            if (bit)
                check_sda_arbitration();
            delay();
            scl = true;
        }

        /* Read a bit from I2C bus */
        bool master_read_bit() {
            bool bit;
            /* Let the slave drive data */
            sda = false; // FIXME: only for first bit
            delay();
            /* send clock */
            scl = false;
            /* Clock stretching */
            clock_strecthing();
            /* SCL is high, now data is valid */
            bit = sda;
            delay();
            scl = true;
            return bit;
        }

        /* Write a byte to I2C bus. Return 0 if ack by the slave */
        bool master_write_byte(uint8_t byte) {
            for (uint8_t mask = 0x80; mask > 0; mask >>= 1) {
                master_write_bit(byte & mask);
            }
            return master_read_bit();
        }

        /* Read a byte from I2C bus */
        uint8_t master_read_byte() {
            uint8_t byte = 0;
            for (uint8_t bit = 0; bit < 8; bit++)
                byte = (byte << 1) | master_read_bit();
            return byte;
        }

        void master_send_ack() {
            master_write_bit(false);
        }

        void master_send_nack() {
            master_write_bit(true);
        }

        uint8_t master_read_byte_with_nack(bool nack) {
            uint8_t byte = master_read_byte();
            master_write_bit(nack);
            return byte;
        }

        bool master_transmit(
            uint8_t address,
            uint8_t* data,
            uint8_t size,
            uint8_t repeat = 0)
        {
            bool error;
            /* start message */
            master_start();
            /* write address */
            error = master_write_byte(address & ~(0x01));
            if (!error) {
                /* data */
                do {
                    for (uint8_t i = 0; i < size; i++) {
                        error = master_write_byte(data[i]);
                        if (error) break;
                    }
                } while(repeat-- && !error);
            }
            /* the end */
            master_stop();
            return error;
        }

        bool master_receive(
            uint8_t address,
            uint8_t* data,
            uint8_t size,
            uint8_t repeat = 0)
        {
            bool error;
            /* start message */
            master_start();
            /* write address */
            error = master_write_byte(address | 0x01);
            if (!error) {
                /* data */
                data[0] = master_read_byte();
                for (uint8_t i = 1; i < size; i++) {
                    master_send_ack();
                    data[i] = master_read_byte();
                }
                /* validate */
                while(repeat-- && !error) {
                    for (uint8_t i = 1; i < size; i++) {
                        master_send_ack();
                        error = (data[i] == master_read_byte());
                        if (error) break;
                    }
                }
                master_send_nack();
            }
            /* the end */
            master_stop();
            return error;
        }
    };

    /* I2CDevice<I2CBus, address> */
    template< typename I2CBus,
              uint8_t address >
    class I2CDevice {
        I2CBus bus;

    public:
        template<typename T>
        void write(T data) {
            bus.write(address, 7, data);
        }

        template<typename T>
        T read() {
            // FIXME: implement
            return 0;
        }
    };
}

#endif
#endif
