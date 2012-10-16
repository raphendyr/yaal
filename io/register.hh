#ifndef __YAAL_IO__REGISTER__
#define __YAAL_IO__REGISTER__ 1

/* yaal/io/register.hh
 * Register abstraction classes
 */

#include "../requirements.hh"
#include "../qualifiers.hh"

#include <inttypes.h>

// wrapper and unwrapper
#define YAAL_REG(reg_t, addr) (*reinterpret_cast<reg_t*>(addr))
#define YAAL_ADDR(reg) (reinterpret_cast<reg_a_t>(&(reg)))


namespace yaal {

    typedef uint16_t reg_a_t;
    typedef uint8_t bit_t;
    typedef volatile uint8_t reg8_t;
    typedef volatile uint16_t reg16_t;

    namespace internal {

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
    };

    template<reg_a_t reg, typename reg_size = reg8_t>
    struct Register :
        public internal::ReadableRegister<reg, reg_size>,
        public internal::WriteableRegister<reg, reg_size>
    {
        typedef reg_size size_type;
    };

}

#endif
