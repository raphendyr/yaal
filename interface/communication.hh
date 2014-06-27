#ifndef __YAAL_INTERFACE__COMMUNICATION_hh__
#define __YAAL_INTERFACE__COMMUNICATION_hh__ 1
#include "../requirements.hh"
#ifdef __YAAL__

#include "stream.hh"

namespace yaal {

    namespace interface {

        template< typename SynchronousPointToPointInterface >
        class SynchronousPointToPointSequence : public ReadWriteBase<SynchronousPointToPointInterface>,
                                                public Writeable<SynchronousPointToPointInterface>,
                                                public Readable<SynchronousPointToPointInterface>
        {
        public:
            SynchronousPointToPointInterface interface;

            SynchronousPointToPointSequence() {
                interface.begin();
            }

            ~SynchronousPointToPointSequence() {
                interface.end();
            }
        };

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
            typedef SynchronousPointToPointSequence<Derived> Sequence;

            /*! Setup connection
             */
            // IMPLEMENT
            void setup(void);

            /*! Begin communication sequence
             */
            // IMPLEMENT if needed
            void begin(void) {}

            /*! End communication sequence
             */
            // IMPLEMENT if needed
            void end(void) {}

            Sequence sequence(void) {
                return {};
            }


            /** Optional methods **/

            template<typename T>
            T read(uint8_t amount_of_bits);

            template<typename T>
            void write(const T data_to_be_written, uint8_t amount_of_bits);



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

        template< typename Derived >
        class SynchronousBus : public ReadWriteBase<Derived>,
                               public Writeable<Derived>,
                               public Readable<Derived>
        {
        public:
            /*! Setup bus
             */
            // IMPLEMENT
            void setup();
        };

        template< typename Bus, typename Activator, typename Derived >
        class SynchronousBusDevice : public SynchronousPointToPoint<Derived> {
        public:
            Activator activator;

            void begin(void) {
                activator = true;
            }

            void end(void) {
                activator = false;
            }
        };


    }

}

#endif
#endif
