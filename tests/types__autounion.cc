#include "testing.hh"
#include <yaal/types/autounion.hh>

using namespace yaal;
using namespace std;


void fancy(autounion<uint16_t> value) {
    cout << hex;
    cout << "0x" << value << ":";
    for (int i = 0; i < value.size; ++i) {
        cout << " 0x" << (int)value[i];
    }
    cout << endl;
}

int main(void) {
    // some visual tests
    fancy(0xffff);
    fancy(0xff00);
    fancy(0xbeaf);

    // read bytes
    {
        autounion<uint16_t> a = 0xbeaf;
        EQ(a[0], 0xbe);
        EQ(a[1], 0xaf);
    }
    // read as int
    {
        autounion<uint16_t> a = 0xbeaf;
        EQ(a, 0xbeaf);
    }
    // editing as int
    {
        autounion<uint16_t> a = 0xbeaf;
        a += 10;
        EQ(a, (0xbeaf + 10));
        a -= 20;
        EQ(a, (0xbeaf - 10));
    }
    // building a new
    {
        autounion<uint16_t> a;
        a[1] = 0xaf;
        a[0] = 0xbe;
        EQ(a, 0xbeaf);
    }
}
