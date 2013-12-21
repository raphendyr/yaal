#include "testing.hh"
#include <yaal/math/fixed.hh>
#include <yaal/math/log.hh>

using namespace yaal;
using namespace std;

typedef FixedDecimal<8, int16_t> fixed_t;

#define EQ_FIX(fixed, testf) EQ_F2(fixed.to_float(), testf, 10000, 100)

#define test(val, result) do { \
    fixed_t v = (val); \
    fixed_t l = log(v); \
    double r = result; \
    EQ_FIX(l, r); \
} while (0)

int main() {
    cout << "test small values" << endl;
    {
        test(1, 0);
        test(1.1, 0.09531017980432493);
        test(2.4, 0.8754687373538999);
        test(3.2, 1.1631508098056809);
    }
}
