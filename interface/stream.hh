#ifndef __YAAL_INTERFACE__STREAM__
#define __YAAL_INTERFACE__STREAM__ 1
#include "../requirements.hh"
#ifdef __YAAL__

#include "../types/autounion.hh"
#include "../util/formating.hh"

namespace yaal {

    typedef uint8_t streamsize;
    typedef uint8_t streamoff;

    namespace interface {

        /*! IOBase
         * ref: std:ios
         */
        template< typename Derived >
        class ReadWriteBase {
        public:
            /*! good
             * Check whether state of stream is good
             * Returns true if none of the stream's error state flags (eofbit, failbit and badbit) is set.
             */
            bool good() const {
                return !static_cast<const Derived*>(this)->fail() && !static_cast<const Derived*>(this)->eof();
            }

            /*! bad
             * Check whether badbit is set
             * Returns true if the badbit error state flag is set for the stream.
             */
            // IMPLEMENT
            bool bad() const {
                return false;
            }

            /*! eof
             * Check whether eofbit is set
             * Returns true if the eofbit error state flag is set for the stream.
             */
            // IMPLEMENT
            bool eof() const {
                return false;
            }

            /*! fail
             * Check whether either failbit or badbit is set
             * Returns true if either (or both) the failbit or the badbit error state flags is set for the stream.
             */
            // IMPLEMENT
            bool fail() const {
                return false;
            }

            /*! operator!
             * Evaluate stream (not)
             * Returns true if either failbit or badbit is set, and false otherwise.
             */
            bool operator! () const {
                return static_cast<const Derived*>(this)->fail();
            }

            /*! operator bool
             * Evaluate stream
             * Returns whether an error flag is set (either failbit or badbit).
             */
            operator bool () const {
                return !static_cast<const Derived*>(this)->fail();
            }
        };

        template< typename Derived >
        class Writeable {
            // ref: std::ostream::sentry
            class Sentry {
                bool failbit;
                Derived* stream;

             public:
                Sentry(Derived* me) : stream(me) {
                    if (stream->good()) {
                        stream->flush();
                    }
                    failbit = stream->fail();
                }
                ~Sentry() {
                    stream->flush();
                }
                operator bool () const {
                    return !failbit;
                }
            };

        public:
            /* maybe TODO:
            tellp(); Get position in output sequence
            seekp(); Set position in output sequence
            */

            /*! flush
             * Flush output stream buffer
             * Synchronizes the associated stream buffer with its controlled output sequence.
             */
            // IMPLEMENT
            Derived& flush() {
                return *static_cast<Derived*>(this);
            }

            //! put
            /*! Write byte
             */
            // IMPLEMENT
            void put(uint8_t);

            /*! Write data
             * This funktion writes sizeof(T) bytes of data from \a data
             * into connection.
             *
             * \param data bytes to be writtend.
             */
            Derived& write(const char c) {
                static_cast<Derived*>(this)->put(c);
                return *static_cast<Derived*>(this);
            }

            Derived& write(const uint8_t c) {
                static_cast<Derived*>(this)->put(c);
                return *static_cast<Derived*>(this);
            }

            // Arrays (pointers) are apected to be null terminated (e.g. strings)
            template< typename T>
            Derived& write(T* array) {
                return static_cast<Derived*>(this)->write(const_cast<const T*>(array));
            }

            template< typename T>
            Derived& write(const T* array) {
                while (*array != 0)
                    static_cast<Derived*>(this)->write(*array++);
                return *static_cast<Derived*>(this);
            }

            // multibyte types are writen using autounion
            template< typename T >
            Derived& write(const T value) {
                const autounion<T> data = value;
                return static_cast<Derived*>(this)->write(data);
            }

            template< typename T >
            Derived& write(const autounion<T>& data) {
                for (uint8_t i = 0; i < data.size; i++)
                    static_cast<Derived*>(this)->put(data[i]);
                return *static_cast<Derived*>(this);
            }

            // any array can be written if size is given
            template< typename T>
            Derived& write(const T* array, streamsize n) {
                for (streamsize i = 0; i < n; i++)
                    static_cast<Derived*>(this)->write(*array++);
                return *static_cast<Derived*>(this);
            }

            // StreamActors expect calling them with stream as parameter
            template< typename T >
            Derived& write(::yaal::internal::StreamActor<T> actor) {
                actor(*static_cast<Derived*>(this));
                return *static_cast<Derived*>(this);
            }

            // Overload operator << to call write
            template< typename T >
            Derived& operator<< (T value) {
                static_cast<Derived*>(this)->write(value);
                return *static_cast<Derived*>(this);
            }
        };


        template< typename Derived >
        class Readable {
        public:
            /* maybe TODO:
            gcount();
            getline(); // I prefer readline();, anycase requires buffer
            peek(); // requires at least memory of size 1 char
            read(char* s, streamsize n);
            tellg();
            seekg();
            sync();
            */

            //! get
            /*! Read byte
             */
            // IMPLEMENT
            uint8_t get();

            Derived& ignore(void) {
                // read one and dump it
                static_cast<Derived*>(this)->get();
                return *static_cast<Derived*>(this);
            }

            /*! Read data
             * This funktion reads sizeof(T) bytes from connection
             * and returns that.
             *
             * \return \a read returns sizeof(T) bytes of data from connection
             */
            template<typename T>
            Derived read(T& data) {
                autounion<T> res;
                static_cast<Derived*>(this)->read(res);
                data = res.value();
                return *static_cast<Derived*>(this);
            }

            template<typename T>
            Derived read(autounion<T>& data) {
                for (uint8_t i = 0; i < data.size; i++)
                    data[i] = static_cast<Derived*>(this)->get();
                return *static_cast<Derived*>(this);
            }

            // operator >>
            Derived& operator>> (char& c) {
                c = static_cast<Derived*>(this)->get();
                return *static_cast<Derived*>(this);
            }
        };

    }

}

#endif
#endif
