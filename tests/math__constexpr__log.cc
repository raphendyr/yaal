#include "testing.hh"
#include <yaal/math/constexpr.hh>

using namespace yaal;
using namespace std;
using namespace yaal::impl::log2_ce;

#define TEST(func, arg, expect) \
    cout << #func "(" << dec << arg << ")  "; \
    EQ_F2(func(arg), expect, 10000000L, 100)

int main() {
    TEST(log2_pow2, 0, 1);
    TEST(log2_pow2, 10, 1024);
    cout << endl;

    TEST(log2_pow2_arg, 0, 0);
    TEST(log2_pow2_arg, 0.5, 0);
    TEST(log2_pow2_arg, 2, 1);
    TEST(log2_pow2_arg, 3.7, 1);
    TEST(log2_pow2_arg, 10, 3);
    cout << endl;

    TEST(log2_frag, 1.2, 0.263034405834);
    cout << endl;

    TEST(log2_ce, 10, 3.32192809489);
    TEST(log2_ce, 1000, 9.96578428466);
    TEST(log2_ce, 1000000, 19.9315685693);
    cout << endl;

    TEST(log_ce, 10, 2.3025850929940455);
    TEST(log_ce, 1000, 6.907755278982137);
    TEST(log_ce, 1000000, 13.815510557964274);
    cout << endl;

    return 0;
}
