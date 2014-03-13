#ifndef __YAAL_INTERFACE__REGISTER_hh__
#define __YAAL_INTERFACE__REGISTER_hh__ 1
#include "../requirements.hh"
#ifdef __YAAL__

namespace yaal {

    namespace interface {

        template< typename reg_size, typename Derived >
        class NamedRegister {
        public:
            typedef reg_size size_type;

            /* Read */

            // IMPLEMENT
            YAAL_INLINE("NamedRegister::get()")
            size_type get() const;

            YAAL_INLINE("NamedRegister::operator size_type")
            operator size_type () const {
                return static_cast<const Derived*>(this)->get();
            }

            /* Write */

            // IMPLEMENT
            YAAL_INLINE("NamedRegister::reference()")
            size_type& reference();

            YAAL_INLINE("NamedRegister::set(size_type)")
            void set(size_type value) {
                static_cast<Derived*>(this)->reference() = value;
            }


            YAAL_INLINE("Register::operator= (size_type)")
            Derived& operator= (size_type value) {
                static_cast<Derived*>(this)->set(value);
                return *static_cast<Derived*>(this);
            }
        };

        template< typename reg_size, typename Derived >
        class NamedRegisterWithOperators : public NamedRegister<reg_size, Derived> {
            typedef NamedRegister<reg_size, Derived> super_type;

        public:
            typedef reg_size size_type;

            YAAL_CRTP_ASSIGNMENT(size_type, Derived, super_type);

#define     YAAL_NAMEDREGISTER_OPERATOR(_op_) \
            YAAL_INLINE("NamedRegisterWithOperators::operator oper ()") \
            Derived& operator _op_ (const size_type value) { \
                static_cast<Derived*>(this)->reference() _op_ value; \
                return *static_cast<Derived*>(this); \
            }
            YAAL_NAMEDREGISTER_OPERATOR(|=);
            YAAL_NAMEDREGISTER_OPERATOR(&=);
            YAAL_NAMEDREGISTER_OPERATOR(+=);
            YAAL_NAMEDREGISTER_OPERATOR(-=);
#undef      YAAL_NAMEDREGISTER_OPERATOR

        };

        template< typename Derived >
        class NamedBit {
        public:
            // IMPLEMENT
            YAAL_INLINE("NamedBit::set(bool)")
            void set(bool = true);

            // IMPLEMENT
            YAAL_INLINE("NamedBit::get()")
            bool get() const;


            YAAL_INLINE("NamedBit::clear()")
            void clear() {
                static_cast<Derived*>(this)->set(false);
            }

            YAAL_INLINE("NamedBit::operator=(bool)")
            Derived& operator= (bool state) {
                static_cast<Derived*>(this)->set(state);
                return *static_cast<Derived*>(this);
            }

            YAAL_INLINE("NamedBit::operator bool ()")
            operator bool () const {
                return static_cast<const Derived*>(this)->get();
            }
        };

    }

}

#endif
#endif
