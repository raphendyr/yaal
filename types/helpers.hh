#ifndef __YAAL_TYPES__HELPERS__
#define __YAAL_TYPES__HELPERS__ 1
#include "../requirements.hh"
#ifdef __YAAL__

namespace yaal {

    namespace internal {

        /*! TypeIf template struct can be used to select type
         * using boolean expression at compile time
         * result is in member named type
         */
        template<bool, typename true_type, typename false_type>
        struct TypeIf {
            typedef false_type type;
        };
        template<typename true_type, typename false_type>
        struct TypeIf<true, true_type, false_type> {
            typedef true_type type;
        };

        /*! TypesMatch template struct can be used to check
         * if two types are the same
         * ref: std::is_same
         */
        template< typename T, typename U >
        struct TypesMatch {
            constexpr static bool value = false;
        };
        template< typename T >
        struct TypesMatch<T, T> {
            constexpr static bool value = true;
        };

        /*! NoType can be used e.g. with TypesMatch in CRTP inheritance
         * to detect if argument was given to Derived type
         */
        struct NoType {};


        /*! TypeIfValid helps to choose a type if it's not NoType
         * or it will retorn fallback type if it is NoType
         */
        template< typename ok_type, typename fallback_type >
        struct TypeIfValid {
            typedef typename TypeIf<
                !TypesMatch<ok_type, NoType>::value,
                ok_type,
                fallback_type
            >::type type;
        };


    }

}

#endif
#endif
