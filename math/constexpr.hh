#ifndef __YAAL_MATH__CONSTEXPR__
#define __YAAL_MATH__CONSTEXPR__ 1
#include "../requirements.hh"
#ifdef __YAAL__

#include "constants.hh"

namespace yaal {

    /* pow */
    template<typename T>
    constexpr T pow_ce(T const& x, long exp){
        return (exp <= 0) ? 1 : x * pow_ce(x, exp - 1);
    }


    /* log2 */
    /* Calculate log2 in compile time using algorithm from wikipedia:
     * http://en.wikipedia.org/wiki/Binary_logarithm?oldid=584017666#Real_number
     *
     * NOTE: constexpr version of log2 should be implemented as call
     * to real log2 function at compile time instead of duing it
     * here with these hacks
     */
    namespace impl {
        namespace log2_ce {
            /* log2_pow2
             * calculate pow(2, num)
             */
            constexpr unsigned long long log2_pow2(unsigned long long exp) {
                return (exp == 0) ? 1 : ((exp < 64) ? ((unsigned long)1L << exp) : 0xffffffffffffffff);
            }

            /* log2_pow2_arg
             * calculate what would be argument to log2_pow2 if result is x
             * or in other words, x = pow(2, y), return y
             */
            constexpr unsigned long log2_pow2_arg(double x, unsigned long r = 0) {
                return x < (double)(1 << (r + 1)) ? r : log2_pow2_arg(x, r+1);
            }

            /* log2_frag_mul_*
             * calculates y=y^m until y is in range of 2..4
             * _count retyrns m
             * _value returns y
             */
            constexpr unsigned long log2_frag_mul_count(double y, unsigned long m = 0) {
                return (y < 2.0) ? log2_frag_mul_count(y * y, m + 1) : m;
            }
            constexpr double log2_frag_mul_value(double y, unsigned long m = 0) {
                return (y < 2.0) ? log2_frag_mul_value(y * y, m + 1) : y;
            }

            /* log2_frag
             * calculate log2 fragment
             */
            constexpr double log2_frag(double y, unsigned int m = 0) {
                // if abs(y) < 0.0000001: return 0
                // c = log2_frag_mul_count(y)
                // y = log2_frag_mul_value(y)
                // return 1/2^c + 1/2^c * log2_frag(y / 2)
                // return 1/2^c * (1 + log2_frag(y / 2)
                // return (1 + log2_frag(y / 2)) / 2^c
                return ((y<0?-y:y) < 0.0000001 || m > 200) ? 0 : (
                    (log2_frag(log2_frag_mul_value(y) / 2, m + 1) + 1) / log2_pow2(log2_frag_mul_count(y))
                );
            }
        }
    }

    constexpr double log2_ce(double x) {
        /* FIXME: would __builtin_log2() be ok? */
        // n = left_most_bit(x) | integer part
        // y = log2_fragment(x/(2^n)) | decimal part
        // return n + y
        return impl::log2_ce::log2_pow2_arg(x) + impl::log2_ce::log2_frag(x / impl::log2_ce::log2_pow2(impl::log2_ce::log2_pow2_arg(x)));
    }


    /* log */
    /* log implementation as constexpr function
     * based on the log calculation rule log(x) = log(2) * log2(x) and log(2) is constant
     */
    constexpr double log_ce(double x) {
        /* FIXME: would __builtin_log() be ok? */
        return log2_ce(x) * constants::log_2;
    }
}

#endif
#endif
