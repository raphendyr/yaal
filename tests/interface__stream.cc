#include "testing.hh"

#include "yaal/interface/stream.hh"

#include <sstream>
#include <string>
#include <typeinfo>

using namespace yaal;
using namespace std;

struct StdStream :
public interface::ReadWriteBase< StdStream >,
public interface::Readable< StdStream >,
public interface::Writeable< StdStream > {

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
    test << asdec(125) << yaal::endl;
    test << ashex(0x45) << ashex(0x22);
    test.write("\n", 1);
    {
        string outs = out.str();
        cout << "outs:\n" << outs << std::endl;
        assert(outs.compare("t\nfoobar\n125\n4522\n") == 0);
    }

    // autounion test
    out.str(""); out.clear();
    uint16_t word = 0xc3a4;
    autounion<uint16_t> aword = word;
    test << word << aword << yaal::endl;
    {
        string outs = out.str();
        cout << "outs:\n" << outs << std::endl;
        assert(outs.compare("\xc3\xa4\xc3\xa4\n") == 0);
    }

    // array of uint16_t test
    out.str(""); out.clear();
    uint16_t words[4] = {0xc3a4, 0xc3b6, 0xc3a5, 0};
    test << words << yaal::endl;
    {
        string outs = out.str();
        cout << "outs:\n" << outs << std::endl;
        assert(outs.compare("\xc3\xa4\xc3\xb6\xc3\xa5\n") == 0);
    }

    // input
    in << 'a';
    char a;
    test >> a;
    cout << "read: " << a << std::endl;
    EQ(a, 'a');

    return 0;
}
