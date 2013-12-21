#include "testing.hh"
#include <yaal/math/fixed.hh>
#include <yaal/math/log2.hh>

using namespace yaal;
using namespace std;

typedef FixedDecimal<8, int16_t> fixed_t;

#define EQ_FIX(fixed, testf) EQ_F2(fixed.to_float(), testf, 10000, 100)

#define test(val, result) do { \
    fixed_t v = (val); \
    fixed_t l = log2(v); \
    double r = result; \
    EQ_FIX(l, r); \
} while (0)

int main() {
    cout << "test values divisable by 2" << endl;
    {
        test(8, 3);
        test(2, 1);
        test(64, 6);
    }

    cout << "test small values" << endl;
    {
        test(1, 0);
        test(1.1, 0.13750352374993502);
        test(2.4, 1.2630344058337937);
    }

    cout << "test for bit correctness" << endl;
    {
        {
            fixed_t a = typename fixed_t::RawValue(0x01a6); // 1.65 | 1.6484375...
            fixed_t r = log2(a);
            EQ_F2(r.raw_value(), 0xb9, 1, 2); // allow small error as fixed numbers have limited accuracy
        }
    }
}
