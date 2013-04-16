#include "yaal/types/autounion.hh"
using namespace yaal;

#include <iostream>
#include <assert.h>
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

    // asserts for automatic testing
    {
        autounion<uint16_t> a = 0xbeaf;
        assert(a[0] == 0xbe);
        assert(a[1] == 0xaf);
    }
    {
        autounion<uint16_t> a = 0xbeaf;
        assert(a == 0xbeaf);
    }
    {
        autounion<uint16_t> a = 0xbeaf;
        a += 10;
        assert(a == (0xbeaf + 10));
        a -= 20;
        assert(a == (0xbeaf - 10));
    }
}
