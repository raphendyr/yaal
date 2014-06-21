#ifndef __YAAL_INTERFACE__COMMUNICATION__
#define __YAAL_INTERFACE__COMMUNICATION__ 1
#include "../requirements.hh"
#ifdef __YAAL__

#include "stream.hh"

namespace yaal {

    namespace interface {

        /*! Syncronous point-to-point communication interface
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
        class SyncronousPointToPoint : public ReadWriteBase<Derived>,
                                       public Writeable<Derived>,
                                       public Readable<Derived>
        {
            /*! Setup connection
             */
            // IMPLEMENT
            void setup();


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

    }

}

#endif
#endif
