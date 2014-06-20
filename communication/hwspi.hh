#ifndef __YAAL_COMMUNICATION__HWSPI__
#define __YAAL_COMMUNICATION__HWSPI__ 1
#include "../requirements.hh"
#ifdef __YAAL__

#include "../io/registers/spi.hh"
namespace yaal {

    namespace interface {
        template< typename Derived >
        class ClockPrescaler {
        public:

            // IMPLEMENT
            void set(uint8_t divider);

            YAAL_ASSIGNMENT_OPER(Derived, set, uint8_t);

            // IMPLEMENT
            uint8_t get(void):

            operator uint8_t () {
                return static_cast<Derived*>(this)->get();
            }
        };

        template< typename Derived >
        class Clock {
        public:
            void set(freq_t frequency);

            freq_t get(void);
        };
    }

#define YAAL_CRTP_CLASS SpiClockPrescaler2x<Rate2x, Rate1, Rate0>
    template< typename Rate2x, typename Rate1, typename Rate0 >
    class SpiClockPrescaler2x : public interface::ClockPrescaler<YAAL_CRTP_CLASS> {
        typedef YAAL_CRTP_CLASS self_type;
        typedef interface::ClockPrescaler<self_type> super;
#undef YAAL_CRTP_CLASS

    public:
        void set(uint8_t divider) {
            Rate2x() = divider & 0x4;
            if (internal::TypesMatch<Rate1::Register, Rate0::Register>::value) {
                // Control register
                Rate1::Register reg;
                Rate1::Register::size_type cur = reg & ~(Rate1::mask | Rate0::mask);
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

    public:
    };

    template< typename SpiRegisters,
              typename MisoPin,
              typename MosiPin,
              typename SckPin,
              typename SsPin >
    class HWSPI : public interface::SycronousPointToPoint<Derived> {
        typename SpiRegisters::Data data;

        struct {
            typename SpiRegisters::DataOrser data_order;
            typename SpiRegisters::MasterMode master_mode;
            typename SpiRegisters::InterruptEnable interrupt_enable;
            typename SpiRegisters::InterrputFlag interrupt_flag;
            typename SpiRegisters::WriteCollisionFlag write_collision_flag;
            typename SpiRegisters::ClockPolarity clock_polarity;
            typename SpiRegisters::ClockPhase clock_phase;
            typename SpiRegisters::ClockRate0 clock_rate0;
            typename SpiRegisters::ClockRate1 clock_rate1;
            typename SpiRegisters::ClockRate2x clock_rate2x;
        } controlbits;

    public:
        typename SpiRegisters::Power power;
        typename SpiRegisters::Enable enable;

        enum SpiMode : uint8_t { Master, Slave }
        enum DataMode : uint8_t {
            MSB = 0x01, LSB = 0x00,
            SAMPLE_TRAILING = 0x02, SAMLE_LEADING = 0x00,
            CLOCK_INVERTED = 0x03, CLOCK_NORMAL = 0x00,
        }


        void setup(freq_q speed = foobar,
                   SpiMode spimode = Master,
                   DataMode datamode = SAMPLE_LEADING | CLOCK_NORMAL | LSB) {
            power = true;
            set_clock_speed(speed)
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

        void set_speed(freq_t speed) {
            // TODO
        }

        void teardown(void) {
            enable = false;
            power = false;
        }

        bool transfer_complete(void) {
            return controlbits.interrupt_flag;
        }

        uint8_t transfer(uint8_t data) {
            data = data;
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
