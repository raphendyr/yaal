#ifndef __YAAL_INTERFACE__COMMUNICATION_hh__
#define __YAAL_INTERFACE__COMMUNICATION_hh__ 1
#include "../requirements.hh"
#ifdef __YAAL__

#include "stream.hh"

namespace yaal {

    namespace interface {

        /*! Synchronous point-to-point communication interface
         *
         * All this kind of communication connections should implement
         * this interface.
         *
         * User of this kind of class can presume that at least
         * required methods are implemented
         *
         * FIXME: implement a way to know that is implemented.
         */
        template< typename Derived >
        class SynchronousPointToPoint : public ReadWriteBase<Derived>,
                                        public Writeable<Derived>,
                                        public Readable<Derived>
        {
        public:

            /*! Setup connection
             */
            // IMPLEMENT
            void setup(void);

     
            /** Optional methods **/

            //template<typename T>
            //T read(uint8_t amount_of_bits);

            //template<typename T>
            //void write(const T data_to_be_written, uint8_t amount_of_bits);

            /** Protocol specific **/

            template<typename T>
            T transfer(const T data) {
                static_cast<Derived*>(this)->put(data);
                return static_cast<Derived*>(this)->get();
            }

            template<typename T>
            T transfer(const T data, uint8_t amount);

            template<typename T>
            void exchange(T& data) {
                data = static_cast<Derived*>(this)->transfer(data);
            }

            template<typename T>
            void exchange(T& data, uint8_t amount_of_bits) {
                data = static_cast<Derived*>(this)->transfer(data, amount_of_bits);
            }

        };


        // Sequence represents one communication sequnce
        // Sequence implements streamable interface (readable + writeable)
#define YAAL_CRTP_CLASS SynchronousPointToPointSequence<Derived>
        template< typename SynchronousPointToPointDevice, typename Derived >
        class SynchronousPointToPointSequence : public ReadWriteBase<Derived>,
                                                public Writeable<Derived>,
                                                public Readable<Derived>
        {
            typedef YAAL_CRTP_CLASS self_type;
#undef YAAL_CRTP_CLASS

        public:
            typedef SynchronousPointToPointDevice Device;
            Device device;

            SynchronousPointToPointSequence() {
                device.begin_sequence();
            }

            ~SynchronousPointToPointSequence() {
                device.end_sequence();
            }

            void put(uint8_t value) {
                device.put(value);
            }

            uint8_t get(void) {
                return device.get();
            }
        };


        template< typename Derived >
        class SynchronousBus
        {
        public:
            /*! Setup bus
             */
            // IMPLEMENT
            void setup();
        };

        template< typename SynchronousBus >
        class SynchronousBusDevice
        {
        public:
            typedef SynchronousBus Bus;
            Bus bus;

            /*! Begin communication sequence
             */
            // IMPLEMENT
            void begin_sequence(void);

            /*! End communication sequence
             */
            // IMPLEMENT
            void end_sequence(void);

            void put(uint8_t value) {
                bus.put(value);
            }

            uint8_t get(void) {
                return bus.get();
            }
        };

        template< typename Sequence >
        class BusDevice
        {
        public:
            Sequence sequence(void) {
                return {};
            } 
        }


    }

}

#endif
#endif
