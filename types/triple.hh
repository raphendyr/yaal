#ifndef __YAAL_TYPES__TRIPLE__
#define __YAAL_TYPES__TRIPLE__ 1
#include "../requirements.hh"
#ifdef __YAAL__

#include "traits.hh"

namespace yaal {

    template<typename T1, typename T2 = T1, typename T3 = T2>
    class Triple {
        typedef Triple<T1, T2, T3> self_type;

        typedef typename ::yaal::internal::TypeTraits<T1>::on_input T1_on_input;
        typedef typename ::yaal::internal::TypeTraits<T1>::on_modify T1_on_modify;
        typedef typename ::yaal::internal::TypeTraits<T2>::on_input T2_on_input;
        typedef typename ::yaal::internal::TypeTraits<T2>::on_modify T2_on_modify;
        typedef typename ::yaal::internal::TypeTraits<T3>::on_input T3_on_input;
        typedef typename ::yaal::internal::TypeTraits<T3>::on_modify T3_on_modify;

        T1 val1;
        T2 val2;
        T3 val3;

    public:
        Triple(const T1_on_input v1,
               const T2_on_input v2,
               const T3_on_input v3)
        : val1(v1), val2(v2), val3(v3)
        { }

        Triple() {}

        Triple(const self_type& other) {
            *this = other;
        }

        self_type& operator=(const self_type& other) {
            val1 = other.val1;
            val2 = other.val2;
            val3 = other.val3;
            return *this;
        }

        T1_on_modify first() {
            return val1;
        }

        const T1_on_modify first() const {
            return val1;
        }

        T2_on_modify second() {
            return val2;
        }

        const T2_on_modify second() const {
            return val2;
        }

        T3_on_modify third() {
            return val3;
        }

        const T3_on_modify third() const {
            return val3;
        }
    };

    template<typename T1, typename T2 = T1, typename T3 = T2>
    Triple<T1, T2, T3> make_triple(const typename TypeTraits<T1>::on_input v1,
                                   const typename TypeTraits<T2>::on_input v2,
                                   const typename TypeTraits<T3>::on_input v3)
    {
        return Triple<T1, T2, T3>(v1, v2, v3);
    }

}

#endif
#endif
