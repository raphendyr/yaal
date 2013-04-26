#ifndef __YAAL_IO__TYPES__REGISTER__
#define __YAAL_IO__TYPES__REGISTER__ 1
#include "../../requirements.hh"
#ifdef __YAAL__

/* yaal/io/types/register.hh
 * Register abstraction classes
 */


// wrapper and unwrapper
#define YAAL_REG(reg_t, addr) (*reinterpret_cast<reg_t*>(addr))
#define YAAL_ADDR(reg) (reinterpret_cast<reg_a_t>(&(reg)))

#ifndef YAAL_SMALL_REG_SIZE
#  define YAAL_SMALL_REG_SIZE uint8_t
#endif
#ifndef YAAL_BIG_REG_SIZE
#  define YAAL_BIG_REG_SIZE uint16_t
#endif

namespace yaal {

    typedef YAAL_BIG_REG_SIZE reg_a_t;
    typedef uint8_t bit_t;
    typedef volatile YAAL_SMALL_REG_SIZE reg8_t;
    typedef volatile YAAL_BIG_REG_SIZE reg16_t;

    namespace internal {

        //! Mask for Bit
        /*! Generates valid mask for a bit.
         *  Similar to _BV but doesn't trow warning when
         *  called with too big number.
         */
        template<typename T>
        constexpr uint8_t mask_for_bit(T bit) {
            return (bit < sizeof(T)*8) ? (1 << bit) : 0;
        }


        template <reg_a_t reg, typename reg_size = reg8_t>
        struct ReadableRegister {
            static YAAL_INLINE("Register operation")
            reg_size get(void) {
                return YAAL_REG(reg_size, reg);
            }

            YAAL_INLINE("Register operation")
            operator reg_size (void) const {
                // read: Register x; y = x;
                return YAAL_REG(reg_size, reg);
            }
        };

        template<reg_a_t reg, typename reg_size = reg8_t>
        struct WriteableRegister {
            static YAAL_INLINE("Register operation")
            void set(reg_size value) {
                YAAL_REG(reg_size, reg) = value;
            }

            YAAL_INLINE("Register operation")
            operator reg_size& (void) {
                // write: Register x; x = 3; x |= 1 << 4;
                return YAAL_REG(reg_size, reg);
            }
        };

        template<typename RegisterClass, bit_t bit>
        class SingleBit {
            typedef SingleBit<RegisterClass, bit> self_type;

        public:

            static constexpr uint8_t mask = mask_for_bit(bit);

            YAAL_INLINE("RegisterBit operation")
            void set(bool state = true) {
                RegisterClass reg;
                if (state)
                    reg |= mask;
                else
                    reg &= ~mask;
            }

            YAAL_INLINE("RegisterBit operation")
            void clear() {
                set(false);
            }

            YAAL_INLINE("RegisterBit operation")
            self_type& operator= (bool state) {
                set(state);
                return *this;
            }

            YAAL_INLINE("RegisterBit operation")
            bool get() const {
                const RegisterClass reg;
                return reg & (1 << bit);
            }

            YAAL_INLINE("RegisterBit operation")
            operator bool () const {
                return get();
            }
        };
    }

    template <reg_a_t reg, typename reg_size = reg8_t>
    struct ReadonlyRegister :
        public internal::ReadableRegister<reg, reg_size>,
        private internal::WriteableRegister<reg, reg_size>
    {
        typedef reg_size size_type;
    };

    template<reg_a_t reg, typename reg_size = reg8_t>
    struct WriteonlyRegister :
        public internal::WriteableRegister<reg, reg_size>,
        private internal::ReadableRegister<reg, reg_size>
    {
        typedef reg_size size_type;

        YAAL_INLINE("WriteonlyRegister operation")
        WriteonlyRegister<reg, reg_size>& operator=(reg_size value) {
            this->set(value);
            return *this;
        }
    };

    template<reg_a_t reg, typename reg_size = reg8_t>
    struct Register :
        public internal::ReadableRegister<reg, reg_size>,
        public internal::WriteableRegister<reg, reg_size>
    {
        typedef reg_size size_type;

        YAAL_INLINE("Register operation")
        Register<reg, reg_size>& operator=(reg_size value) {
            this->set(value);
            return *this;
        }
    };

    struct NullRegister {
        typedef uint32_t size_type;
        size_type tmp = 0;

        /* read */
        static YAAL_INLINE("Register operation")
        size_type get(void) { return 0; }

        YAAL_INLINE("Register operation")
        operator size_type (void) const { return 0; }

        /* write */
        static YAAL_INLINE("Register operation")
        void set(size_type) { }

        YAAL_INLINE("Register operation")
        operator size_type& (void) { return tmp; }


        YAAL_INLINE("Register operation")
        NullRegister& operator= (size_type) { return *this; }
    };
}

#undef YAAL_SMALL_REG_SIZE
#undef YAAL_BIG_REG_SIZE

#endif
#endif
