#ifndef __YAAL_MACRO__CRTP_hh__
#define __YAAL_MACRO__CRTP_hh__ 1

/* macro/crtp.hh
 * Macro to ease Curiously recurring template pattern (CRTP).
 * This pattern is used to create static polymorphism.
 * More information and usage example in interface/README.md
 */

/* Helpers to map assignment operator to method calls */
#define YAAL_ASSIGNMENT_OPER(derived_type, method, argument_type) \
    derived_type& operator= (argument_type value) { \
        static_cast<derived_type*>(this)->method(value); \
        return *static_cast<derived_type*>(this); \
    }

#define YAAL_ASSIGNMENT_OPERS(derived_type, method) \
    template< typename T > \
    derived_type& operator= (T value) { \
        static_cast<derived_type*>(this)->method(value); \
        return *static_cast<derived_type*>(this); \
    }

/* Assignment operators are not inherited as they relate to constructors
 * Use these two to easily use parent assignment operators
 */
#define YAAL_CRTP_ASSIGNMENT(argument_type, derived_type, super_type) \
    derived_type& operator= (argument_type value) { \
        super_type::operator=(value); \
        return *static_cast<derived_type*>(this); \
    }

#define YAAL_CRTP_ASSIGNMENTS(derived_type, super_type) \
    template< typename T > \
    derived_type& operator= (T value) { \
        super_type::operator=(value); \
        return *static_cast<derived_type*>(this); \
    }

/* CRTP class signature
 * NOTE: Define per CRTP templated class */
//#define YAAL_CRTP_CLASS

/* Template argument name for the CRTP */
#define YAAL_CRTP_ARGUMENT Derived

/* Template argument to be used in template argument list */
#define YAAL_CRTP_TEMPLATE_ARG typename YAAL_CRTP_ARGUMENT = ::yaal::internal::NoType

/* Select Derived if it is not NoType else use class it self */
#define YAAL_CRTP_DERIVED typename ::yaal::internal::TypeIfValid<YAAL_CRTP_ARGUMENT, YAAL_CRTP_CLASS>::type


#endif
