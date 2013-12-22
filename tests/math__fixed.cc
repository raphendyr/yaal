#include "testing.hh"
#include <yaal/math/fixed.hh>

using namespace yaal;
using namespace std;

typedef FixedDecimal<8, int16_t> fixed_t;


#define EQ_I(i, test) EQ(i.to_integer(), test)

#define O_I(tst, ref, opr, val) do { \
    OPER(tst, ref, opr, val); \
    EQ_I(tst, ref); \
} while (0)

#define EQ_FIX(fixed, testf) EQ_F(fixed.to_float(), testf)

#define O_FIX(tst, ref, opr, val) do { \
    OPER(tst, ref, opr, val); \
    EQ_FIX(tst, ref); \
} while (0)


int main() {
    cout << "test constructors" << endl;
    {
        fixed_t a = 10;
        EQ_I(a, 10);
        fixed_t b = a;
        EQ_I(b, 10);

        fixed_t f = 2.2f;
        EQ_FIX(f, 2.2f);
    }

    cout << "test assingment" << endl;
    {
        fixed_t a = 11.1;
        EQ_FIX(a, 11.1);
        fixed_t b = 33.3;
        EQ_FIX(b, 33.3);
        a = b;
        EQ_FIX(a, 33.3);
    }

    cout << "test addition & substraction" << endl;
    {
        fixed_t a; int ra;
        O_I(a, ra, =, 100);
        O_I(a, ra, +=, 10);
        O_I(a, ra, -=, 10);

        fixed_t b; float rb;
        O_FIX(b, rb, =, 45.7);
        O_FIX(b, rb, +=, 3.3);
        O_FIX(b, rb, -=, 11.1);
    }

    cout << "test multiplication" << endl;
    {
        fixed_t a; float ra;
        O_FIX(a, ra, =, 6);
        O_FIX(a, ra, *=, 1.7);
        O_FIX(a, ra, *=, 0.1);

        fixed_t b; float rb;
        O_FIX(b, rb, =, 100);
        O_FIX(b, rb, *=, 0.1);
    }

    cout << "test division" << endl;
    {
        fixed_t a; float ra;
        O_FIX(a, ra, =, 77.7);
        O_FIX(a, ra, /=, 7);

        O_FIX(a, ra, =, 1.0);
        O_FIX(a, ra, /=, 0.1);
    }
}
