#include "testing.hh"

#include "yaal/interface/stream.hh"

#include <sstream>
#include <string>
#include <typeinfo>

using namespace yaal;
using namespace std;

struct StdStream :
public interface::ReadWriteBase< StdStream >,
public interface::ReadStream< StdStream >,
public interface::WriteStream< StdStream > {

    static ostream* out;
    static istream* in;

    StdStream() { }

    static void setup(ostream* nout, istream* nin) {
        out = nout;
        in = nin;
    }

    char get() {
        char c;
        *in >> c;
        cout << "Called get() -> " << c << std::endl;
        return c;
    }

    void put(char c) {
        cout << "Called put(" << c << ");" << std::endl;
        *out << c;
    }
};
ostream* StdStream::out = &cout;
istream* StdStream::in = &cin;



int main(void) {
    stringstream out;
    stringstream in;

    StdStream test;
    test.setup(&out, &in);

    // output
    test << 't';
    test << yaal::endl;
    test << "foobar" << yaal::endl;
    test << 125 << yaal::endl;
    test << fmt_hex(0x45, true) << fmt_hex(0x22);
    test.write("\n", 1);
    //out << 0.1;
    string outs = out.str();
    assert(outs.compare("t\nfoobar\n125\n0x4522\n") == 0);
    cout << "output assert ok:\n" << outs << std::endl;

    // input
    in << 'a';
    char a;
    test >> a;
    cout << "read: " << a << std::endl;
    EQ(a, 'a');

    return 0;
}
