#include "testing.hh"
#include <yaal/util/constexpr.hh>

using namespace yaal;
using namespace std;

int main() {
    EQ(ffs_ce(0x1),  1);
    EQ(ffs_ce(0x2),  2);
    EQ(ffs_ce(0x4),  3);
    EQ(ffs_ce(0x8),  4);
    EQ(ffs_ce(0x10), 5);
    EQ(ffs_ce(0x20), 6);
    EQ(ffs_ce(0x40), 7);
    EQ(ffs_ce(0x80), 8);
    EQ(ffs_ce(0),    0);

    return 0;
}
