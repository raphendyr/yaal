#ifndef __YAAL_IO__TYPES__SPI_hh__
#define __YAAL_IO__TYPES__SPI_hh__ 1
#include "../../requirements.hh"
#ifdef __YAAL__

#include "../../interface/clock.hh"
#include "../../interface/communication.hh"

namespace yaal {

    namespace internal {

#define YAAL_CRTP_CLASS SpiClockPrescaler2x<Rate2x, Rate1, Rate0>
        template< typename Rate2x, typename Rate1, typename Rate0 >
        class SpiClockPrescaler2x : public interface::ClockPrescaler<YAAL_CRTP_CLASS> {
            typedef YAAL_CRTP_CLASS self_type;
            typedef interface::ClockPrescaler<self_type> super;
#undef YAAL_CRTP_CLASS

        public:
            void set(uint8_t divider) {
                Rate2x() = divider & 0x4;
                if (internal::TypesMatch<typename Rate1::Register, typename Rate0::Register>::value) {
                    // Control register
                    typename Rate1::Register reg;
                    typename Rate1::Register::size_type cur = reg & ~(Rate1::mask | Rate0::mask);
                    cur |= ((divider & 0x2)?Rate1::mask:0)|((divider & 0x1)?Rate0::mask:0);
                    reg = cur;
                } else {
                    // Don't knoe how to optimize
                    Rate1() = divider & 0x2;
                    Rate0() = divider & 0x1;
                }
            }

            YAAL_CRTP_ASSIGNMENTS(self_type, super);
        };

#define YAAL_CRTP_CLASS SpiClock<Prescaler>
        template< typename Prescaler >
        class SpiClock : public interface::Clock<YAAL_CRTP_CLASS> {
            typedef YAAL_CRTP_CLASS self_type;
            typedef interface::Clock<self_type> super;
#undef YAAL_CRTP_CLASS

            constexpr static freq_t f_osc = F_CLOCK;

        public:
            Prescaler prescaler;

            void set(freq_t frequency) {
                /* map:
                 *  0 = F_OSC / 4
                 *  1 = F_OSC / 16
                 *  2 = F_OSC / 64
                 *  3 = F_OSC / 128
                 *  4 = F_OSC / 2
                 *  5 = F_OSC / 8
                 *  6 = F_OSC / 32
                 *  7 = F_OSC / 64
                 */
                if (frequency >= (f_osc / 2)) {
                    prescaler = 4;
                } else if (frequency >= (f_osc / 4)) {
                    prescaler = 0;
                } else if (frequency >= (f_osc / 8)) {
                    prescaler = 5;
                } else if (frequency >= (f_osc / 16)) {
                    prescaler = 1;
                } else if (frequency >= (f_osc / 32)) {
                    prescaler = 6;
                } else if (frequency >= (f_osc / 64)) {
                    prescaler = 2;
                } else if (frequency >= (f_osc / 128)) {
                    prescaler = 3;
                }
            }

            YAAL_CRTP_ASSIGNMENTS(self_type, super);
        };

#define YAAL_CRTP_CLASS SpiBus<SpiRegisters, SckPin, MosiPin, MisoPin, SsPin>
        template< typename SpiRegisters,
                  typename SckPin,
                  typename MosiPin,
                  typename MisoPin,
                  typename SsPin >
        class SpiBus : public interface::SyncronousPointToPoint<YAAL_CRTP_CLASS> {
            typedef YAAL_CRTP_CLASS self_type;
            typedef interface::SyncronousPointToPoint<self_type> super;
#undef YAAL_CRTP_CLASS

            typename SpiRegisters::Data data;

            struct {
                typename SpiRegisters::DataOrder data_order;
                typename SpiRegisters::MasterMode master_mode;
                typename SpiRegisters::InterruptEnable interrupt_enable;
                typename SpiRegisters::InterruptFlag interrupt_flag;
                typename SpiRegisters::WriteCollisionFlag write_collision_flag;
                typename SpiRegisters::ClockPolarity clock_polarity;
                typename SpiRegisters::ClockPhase clock_phase;
            } controlbits;

        public:
            typename SpiRegisters::Power power;
            typename SpiRegisters::Enable enable;
            typename SpiRegisters::Clock clock;

            enum SpiMode : uint8_t { Master, Slave };
            enum DataMode : uint8_t {
                MSB = 0x01, LSB = 0x00,
                SAMPLE_TRAILING = 0x02, SAMPLE_LEADING = 0x00,
                CLOCK_INVERTED = 0x03, CLOCK_NORMAL = 0x00,
            };


            void setup(freq_t speed = F_CLOCK / 4,
                       SpiMode spimode = Master,
                       DataMode datamode = static_cast<DataMode>(SAMPLE_LEADING | CLOCK_NORMAL | LSB)) {
                power = true;
                clock = speed;
                set_spi_mode(spimode);
                set_data_mode(datamode);
                enable = true;
            }

            bool fail(void) {
                return controlbits.write_collision_flag;
            }

            void set_spi_mode(SpiMode mode) {
                if (mode == Master) {
                    controlbits.master_mode = true;
                    MosiPin().mode = OUTPUT;
                    SckPin().mode = OUTPUT;
                } else {
                    controlbits.master_mode = false;
                    MisoPin().mode = OUTPUT;
                    // read: wait for SPIF, then read SPDR
                }
            }

            void set_data_mode(DataMode mode) {
                controlbits.clock_polarity = (CLOCK_INVERTED & mode);
                controlbits.clock_phase = (SAMPLE_TRAILING & mode);
                controlbits.data_order = (MSB & mode);
            }

            void teardown(void) {
                enable = false;
                power = false;
            }

            bool transfer_complete(void) {
                return controlbits.interrupt_flag;
            }

            uint8_t transfer(uint8_t value) {
                data = value;
                while (!transfer_complete());
                return data;
            }

            void attachInterrupt() {
                controlbits.interrupt_enable = true;
            }

            void detachInterrupt() {
                controlbits.interrupt_enable = false;
            }


            uint8_t get(void) {
                return transfer(0);
            }

            void put(uint8_t data) {
                transfer(data);
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

}

#endif
#endif
