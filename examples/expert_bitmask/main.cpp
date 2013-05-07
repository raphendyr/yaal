#include <yaal/core.hh>
#include <yaal/io.hh>
#include <yaal/bitmask.hh>

using namespace yaal;

PortB row;

void loop() {

    row |= BitMask<1,2>::left;
    row |= BitMask<2,2>::left;
    row |= BitMask<3,2>::left;
    row |= BitMask<4,2>::left;
    row |= BitMask<5,2>::left;
    row |= BitMask<6,2>::left;

}
