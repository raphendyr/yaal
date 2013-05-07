#include "testing.hh"
#include <yaal/util/constexpr.hh>

using namespace yaal;
using namespace std;

constexpr unsigned char size1 = bits_up_ce((unsigned char)0xba);
constexpr unsigned char size2 = bits_up_ce((unsigned int)0xffff);
constexpr unsigned char size3 = bits_up_ce((unsigned int)0x00af);
constexpr unsigned char size4 = bits_up_ce((unsigned int)0xbf00);

int main() {
    EQ(size1, 5);
    EQ(size2, 16);
    EQ(size3, 6);
    EQ(size4, 7);

    return 0;
}
