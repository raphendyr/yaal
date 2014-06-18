#ifndef __YAAL_COMMUNICATION__HWSPI__
#define __YAAL_COMMUNICATION__HWSPI__ 1
#include "../requirements.hh"
#ifdef __YAAL__

#include "../io/registers/spi.hh"
namespace yaal {

    template< typename SpiRegisters,
              typename MisoPin,
              typename MosiPin,
              typename SckPin,
              typename SsPin >
    struct HWSPI : public interface::SycronousPointToPoint<Derived> {
        SpiRegisters regs;

        enum SpiMode : uint8_t { Master, Slave }
        enum DataMode : uint8_t {
            MSB = 0x01, LSB = 0x00,
            SAMPLE_TRAILING = 0x02, SAMLE_LEADING = 0x00,
            CLOCK_INVERTED = 0x03, CLOCK_NORMAL = 0x00,
        }

        void setup(freq_q speed = foobar,
                   SpiMode spimode = Master,
                   DataMode datamode = SAMPLE_LEADING | CLOCK_NORMAL | LSB) {
            set_clock_speed(speed)
            set_spi_mode(spimode);
            set_data_mode(datamode);
            regs.enable = true;
        }

        void set_spi_mode(SpiMode mode) {
            if (mode == Master) {
                regs.master_mode = true;
                MosiPin().mode = OUTPUT;
                SckPin().mode = OUTPUT;
            } else {
                regs.master_mode = false;
                MisoPin().mode = OUTPUT;
                // read: wait for SPIF, then read SPDR
            }
        }

        void set_data_mode(DataMode mode) {
            regs.clock_polarity = (CLOCK_INVERTED & mode);
            regs.clock_phase = (SAMPLE_TRAILING & mode);
            regs.data_order = (MSB & mode);
        }

        void set_speed(freq_t speed) {
            // TODO
        }

        void enable_module(void) {
            PRR0 &= ~_BV(PRSPI); // enable power to SPI
            regs.enable = true;
        }

        void teardown(void) {
            regs.enable = false;
        }

        bool transfer_complete(void) {
            return regs.interrupt_flag;
        }

        uint8_t transfer(uint8_t data) {
            regs.data = data;
            while (!transfer_complete());
            return regs.data;
        }

        void SPIClass::attachInterrupt() {
            regs.interrupt_enable = true;
        }

        void SPIClass::detachInterrupt() {
            regs.interrupt_enable = false;
        }


        uint8_t get(void) {
        }

        void put(uint8_t data) {
        }


        template<typename T>
        static inline
        T transfer(T data) {
        }

        template<typename T>
        static inline
        T transfer(T data, uint8_t bits) {
        }
    };

}

#endif
#endif
