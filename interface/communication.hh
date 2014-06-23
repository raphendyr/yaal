#ifndef __YAAL_INTERFACE__COMMUNICATION_hh__
#define __YAAL_INTERFACE__COMMUNICATION_hh__ 1
#include "../requirements.hh"
#ifdef __YAAL__

#include "stream.hh"

namespace yaal {

    namespace interface {

        template< typename SynchronousPointToPointInterface >
        class SynchronousPointToPointSequence : public ReadWriteBase<Derived>,
                                                public Writeable<Derived>,
                                                public Readable<Derived>
        {
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
            T transfer(const T data_to_be_written);

            template<typename T>
            T transfer(const T data_to_be_written, uint8_t amount_of_bits);

            template<typename T>
            void exchange(T& data);

            template<typename T>
            void exchange(T& data, uint8_t amount_of_bits);

        };

        template< typename Derived >
        class SynchronousBus : public ReadWriteBase<Derived>,
                               public Writeable<Derived>,
                               public Readable<Derived>
        {
            /*! Setup bus
             */
            // IMPLEMENT
            void setup();
        };

        template< typename Bus, typename Activator, typename Derived >
        class SynchronousBusDevice : public SynchronousPointToPoint<Derived> {
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
