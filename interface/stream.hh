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
        public:
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
            template<typename T>
            void write(const T& value) {
                const autounion<T> data = value;
                static_cast<Derived*>(this)->write(data);
            }

            template< typename T >
            void write(const autounion<T>& data) {
                for (uint8_t i = 0; i < data.size; i++)
                    static_cast<Derived*>(this)->put(data[i]);
            }
        };

        template< typename Derived >
        class Readable {
        public:
            //! get
            /*! Read byte
             */
            // IMPLEMENT
            uint8_t get();

            /*! Read data
             * This funktion reads sizeof(T) bytes from connection
             * and returns that.
             *
             * \return \a read returns sizeof(T) bytes of data from connection
             */
            template<typename T>
            void read(T& data) {
                autounion<T> res;
                static_cast<Derived*>(this)->read(res);
                data = res.value();
            }

            template<typename T>
            void read(autounion<T>& data) {
                for (uint8_t i = 0; i < data.size; i++)
                    data[i] = static_cast<Derived*>(this)->get();
            }
        };


        template< typename Derived >
        class WriteStream : public Writeable< Derived > {
            typedef WriteStream< Derived > self_type;

            // ref: std::ostream::sentry
            class Sentry {
                bool failbit;
                Derived* stream;

             public:
                Sentry(self_type* me) : stream(static_cast<Derived*>(me)) {
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
            self_type& flush() {
                return *this;
            }

            self_type& write(const char* str, streamsize n) {
                Sentry sentry(this);
                if (sentry) {
                    for (streamsize i = 0; i < n; i++) {
                        static_cast<Derived*>(this)->put(*str++);
                    }
                }
                return *this;
            }

            template< typename T >
            void write(const T& value) {
                Writeable<Derived>::write(value);
            }

            // operator <<
            self_type& operator<< (const char c) {
                static_cast<Derived*>(this)->put(c);
                return *this;
            }

            self_type& operator<< (const uint8_t c) {
                static_cast<Derived*>(this)->put(c);
                return *this;
            }

            template< typename T >
            self_type& operator<< (const T& val) {
                static_cast<Derived*>(this)->write(val);
                return *this;
            }

            self_type& operator<< (const char* str) {
                while (*str != '\0')
                    static_cast<Derived*>(this)->put(*str++);
                return *this;
            }

            self_type& operator<< (char* str) {
                *this << const_cast<const char*>(str);
                return *this;
            }

            self_type& operator<< (int value) {
                char buf[11];
                ntoa(value, buf, 10);
                *this << buf;
                return *this;
            }

            template< typename T >
            self_type& operator<< (FmtHex<T> fmt) {
                char buf[10];
                ntoa(fmt.value, buf, 16);
                if (fmt.prefix)
                    *this << '0' << 'x';
                *this << buf;
                return *this;
            }

            template< typename T >
            self_type& operator<< (::yaal::internal::StreamActor<T> actor) {
                actor.runfor(*static_cast<Derived*>(this));
                return *this;
            }
        };

        template< typename Derived >
        struct ReadStream : public Readable< Derived > {
            typedef ReadStream< Derived > self_type;

        public:
            void ignore() {
                // read one and dump it
                static_cast<Derived*>(this)->get();
            }

            /* maybe TODO:
            gcount();
            getline(); // I prefer readline();, anycase requires buffer
            peek(); // requires at least memory of size 1 char
            read();
            tellg();
            seekg();
            sync();
            */

            // operator >>
            self_type& operator>> (char& c) {
                c = static_cast<Derived*>(this)->get();
                return *this;
            }

            // requires peek();
            self_type& operator>> (int& i) = delete; /* {
                char c;
                int r = 0;
                while (isnum(c = peek())) {
                    ignore(); // advance in stream
                    r *= 10;
                    r += c - '0';
                }
                return c;
            } */
        };

        template< typename Communicable >
        class Communication : public ReadWriteBase<Communication<Communicable>>,
                              public ReadStream<Communication<Communicable>>,
                              public WriteStream<Communication<Communicable>> {
            typedef Communication<Communicable> self_type;

        protected:
            Communicable* comm;

        public:
            Communication(Communicable* comm) : comm(comm) {
                comm->begin();
            }

            ~Communication() {
                comm->end();
            }

            /* Proxy ReadWriteBase methods */

            bool good() const { return comm->good(); }
            bool bad() const { return comm->bad(); }
            bool eof() const { return comm->eof(); }
            bool fail() const { return comm->fail(); }
            bool operator! () const { return !(*comm); }
            operator bool () const { return static_cast<bool>(*comm); }

            /* Proxy Writeable methods */

            void put(uint8_t byte) { comm->put(byte); }

            template< typename T >
            self_type& write(T value) {
                comm->write(value);
                return *this;
            }

            template< typename T, typename Y>
            self_type& write(T value1, Y value2) {
                comm->write(value1, value2);
                return *this;
            }

            template< typename T>
            self_type& writebits(T data, uint8_t bits) {
                comm->writebits(data, bits);
                return *this;
            }

            /* Proxy Readable methods */

            uint8_t get() { return comm->get(); }

            template< typename T >
            self_type& read(T result) {
                comm->read(result);
                return *this;
            }

            template< typename T, typename Y>
            self_type& read(T result, Y value) {
                comm->read(result, value);
                return *this;
            }

            template< typename T>
            self_type& readbits(T data, uint8_t bits) {
                comm->readbits(data, bits);
                return *this;
            }

            /* Proxy Transfer methods */
            template<typename T>
            T transfer(T data) {
                return comm->transfer(data);
            }

            template<typename T>
            T transferbits(T data, uint8_t bits) {
                return comm->transferbits(data, bits);
            }
        };

        template< typename Derived >
        class Communicable : protected ReadWriteBase< Derived >,
                             protected Readable< Derived >,
                             protected Writeable< Derived > {
            /* Most of the methods are public, so the user
             * can't call them directly, but needs to use
             * the communication proxy
             *
             * This enforces use of begin() and end().
             * Though this doesn't protect from the miss use of the proxy
             * Following example is the WRONG use:
             *   { auto chat1 = spi.chat(); // calls begin()
             *     spi.chat() << "foobar";  // calls begin(), write(), end()
             *     chat1 << "baz";          // calls write() while line is not in use
             *   }                          // calls end() for the second time
             */
            friend class ReadWriteBase<Derived>;
            friend class Readable<Derived>;
            friend class Writeable<Derived>;
            friend class interface::Communication<Derived>;

        public:
            /*! chat
             * Create communication object.
             * Communication object calls begin() on constructor and
             * end() on descruction.
             *
             * Use following pattern:
             *   device.chat() << byte1 << byte2;
             * Or
             *   { auto chat = device.chat(); chat.write(bytes1); chat.bytes(bytes2); }
             */
            Communication<Derived> chat() {
                Communication<Derived> chat(static_cast<Derived*>(this));
                return chat;
            }

        protected:
            /*! begin
             * Begin communication (eg. latch SPI)
             */
            void begin();

            /*! end
             * End communication (eg. delatch SPI)
             */
            void end();
        };

    }

}

#endif
#endif
