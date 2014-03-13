#ifndef __YAAL_TYPES__REGISTER_hh__
#define __YAAL_TYPES__REGISTER_hh__ 1
#include "../requirements.hh"
#ifdef __YAAL__

/* yaal/types/register.hh
 * Register abstraction classes
 */

#include "../interface/register.hh"
#include "helpers.hh"


/*! YAAL_ADDR
 * Get address from avr-libc register names
 * usage: register_address_type address = YAAL_ADDR(SREG);
 */
#define YAAL_ADDR(reg) (reinterpret_cast<::yaal::register_address_type>(&(reg)))


// Test programs need to redefine register types on host platform
#ifndef YAAL_WORD_REGISTER_TYPE
#  define YAAL_WORD_REGISTER_TYPE uint8_t
#endif
#ifndef YAAL_DWORD_REGISTER_TYPE
#  define YAAL_DWORD_REGISTER_TYPE uint16_t
#endif


namespace yaal {

    // register related types
    typedef YAAL_DWORD_REGISTER_TYPE register_address_type;
    typedef uint8_t bit_index_type;
    typedef volatile YAAL_WORD_REGISTER_TYPE word_register_type;
    typedef volatile YAAL_DWORD_REGISTER_TYPE dword_register_type;

    // Backward compatibility:
    typedef bit_index_type bit_t;
    typedef word_register_type reg8_t;
    typedef dword_register_type reg16_t;


    namespace internal {
        //! Mask for Bit
        /*! Generates valid mask for a bit.
         *  Similar to _BV but is a function and doesn't
         *  create warning when called with too big number.
         */
        template<typename T>
        constexpr T mask_for_bit(T bit) {
            return (bit < sizeof(T)*8) ? (1 << bit) : 0;
        }


        /*! Register
         * Register represents a single logical register on AVR
         * These registers are commonly one or two words (8 ot 16 bit)
         */
#define YAAL_CRTP_CLASS Register<address, reg_size, read_only, YAAL_CRTP_ARGUMENT>
        template< register_address_type address, typename reg_size = word_register_type, bool read_only = false, YAAL_CRTP_TEMPLATE_ARG >
        class Register : public interface::NamedRegister<reg_size, YAAL_CRTP_DERIVED> {
            typedef YAAL_CRTP_DERIVED derived_type;
            typedef YAAL_CRTP_CLASS self_type;
            typedef interface::NamedRegister<reg_size, YAAL_CRTP_DERIVED> super;
#undef      YAAL_CRTP_CLASS

        public:
            typedef typename super::size_type size_type;

            YAAL_INLINE("Register::get()")
            size_type get() const {
                return *reinterpret_cast<size_type*>(address);
            }

            YAAL_INLINE("Register::reference()")
            size_type& reference() {
                return *reinterpret_cast<size_type*>(address);
            }

            YAAL_INLINE("Register::operator size_type& ()")
            operator size_type& () {
                return static_cast<derived_type*>(this)->reference();
            }

            // FIXME: why example/adept_touchscreen4d fails, if we use assignment redirect?
            //YAAL_CRTP_ASSIGNMENTS(derived_type, super)
            derived_type& operator= (size_type value) {
                static_cast<derived_type*>(this)->set(value);
                return *static_cast<derived_type*>(this);
            }
        };


        /*! NullRegister
         * NullRegister is used to create dummy register to be used
         * other dummy types, which require register
         */
        class NullRegister : public interface::NamedRegister<uint32_t, NullRegister> {
            typedef interface::NamedRegister<uint32_t, NullRegister> super;

        public:
            typedef uint32_t size_type;
            size_type tmp = 0;

            YAAL_INLINE("NullRegister::get()")
            size_type get() const {
                return 0;
            }

            YAAL_INLINE("NullRegister::reference()")
            size_type& reference() {
                return tmp;
            }

            YAAL_INLINE("NullRegister::operator size_type& ()")
            operator size_type& () {
                return tmp;
            }

            YAAL_CRTP_ASSIGNMENTS(NullRegister, super)
        };


        /*! SingleBit
         * SingleBit represents a single bit in a register
         * On AVR most of the hardware is configured using bits in registers
         */
#define YAAL_CRTP_CLASS SingleBit<RegisterClass, bitnumber, YAAL_CRTP_ARGUMENT>
        template< typename RegisterClass, bit_index_type bitnumber, YAAL_CRTP_TEMPLATE_ARG>
        class SingleBit : public interface::NamedBit<YAAL_CRTP_DERIVED> {
            typedef YAAL_CRTP_DERIVED derived_type;
            typedef YAAL_CRTP_CLASS self_type;
            typedef interface::NamedBit<YAAL_CRTP_DERIVED> super;
#undef      YAAL_CRTP_CLASS

        public:
            constexpr static uint8_t mask = mask_for_bit<uint8_t>(bitnumber);

            YAAL_INLINE("SingleBit::set(bool)")
            void set(bool state = true) {
                RegisterClass reg;
                if (state)
                    reg |= mask;
                else
                    reg &= static_cast<uint8_t>(~mask);
            }

            YAAL_INLINE("RegisterBit::get()")
            bool get() const {
                const RegisterClass reg;
                return reg & mask;
            }

            YAAL_CRTP_ASSIGNMENTS(derived_type, super)
        };
    }

}


// undefine types not used in other places
#undef YAAL_WORD_REGISTER_TYPE
#undef YAAL_DWORD_REGISTER_TYPE

#endif
#endif
