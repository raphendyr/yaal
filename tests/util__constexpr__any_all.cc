#include "testing.hh"
#include <yaal/util/constexpr.hh>

using namespace yaal;
using namespace std;

int main() {
    EQ(all_ce(true, true, true),  true);
    EQ(all_ce(true, false, true),  false);
    EQ(any_ce(false, true, false),  true);
    EQ(any_ce(false, false),  false);

    return 0;
}
