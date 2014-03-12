#ifndef __YAAL_TESTING__
#define __YAAL_TESTING__ 1


// yaal stuff
typedef unsigned long long reg_size_t;
#define YAAL_WORD_REGISTER_TYPE reg_size_t
#define YAAL_DWORD_REGISTER_TYPE reg_size_t


// std stuff
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <assert.h>


// helpers...
#define UNSIGNED_NON_CV(var) \
    std::make_unsigned< std::remove_cv< std::remove_reference< decltype(var) >::type >::type >::type
#define ASSERT(left, test, right) do { \
    UNSIGNED_NON_CV(left) l_ = left; \
    UNSIGNED_NON_CV(right) r_ = right; \
    std::cout << "assert("; \
    print_hex(std::cout, l_); \
    std::cout << " " #test " "; \
    print_hex(std::cout, r_); \
    std::cout << ");" << std::endl; \
    assert(l_ test r_); \
} while (0)

#define EQ(left, right) ASSERT(left, ==, right)

#define EQ_F2(left, right, mult, accuracy) do { \
    std::cout << left << " <> " << right << "  ->  "; \
    signed long a_ = (signed long)(left * mult); \
    signed long b_ = (signed long)(right * mult); \
    std::cout << std::dec << a_ << " <> " << std::dec << b_ << std::endl; \
    signed long d_  = a_ - b_; \
    signed long ad_ = d_ < 0 ? -d_ : d_; \
    ASSERT(ad_, < , accuracy); \
} while (0)
#define EQ_F(left, right) EQ_F2(left, right, 100, 30)

#define _s(var) #var
#define OPER(left, ref, oper, value) do { \
    std::cout << _s(left) << " " << _s(oper) << " " << value << std::endl; \
    left oper value; \
    std::cout << _s(ref) << " " << _s(oper) << " " << value << std::endl; \
    ref oper value; \
} while (0)


// memory location
#ifndef REG_START__
#  define REG_START__ 0x0000000000603734
#endif
uint8_t __registers[10];
#define REG(i) (*(((volatile uint8_t*)REG_START__) + (i)))
#define REG0 REG(0)
#define REG1 REG(1)
#define REG2 REG(2)
#define REG3 REG(3)
#define REG4 REG(4)
#define REG5 REG(5)
#define REG6 REG(6)
#define REG7 REG(7)
#define REG8 REG(8)
#define REG9 REG(9)
#define ADDR(r) ((unsigned long long)(&(r)))

static void test_reg_start() __attribute__ ((used));
static void test_reg_start() {
    using std::cout; using std::endl; using std::hex;

    unsigned long long reg_start = REG_START__;
    unsigned long long reg_start_real = reinterpret_cast<unsigned long long>(__registers);

    if (reg_start != reg_start_real) {
        cout << "ERROR: invalid reg_start (0x" << hex << reg_start << ")\n" \
                "Fix build with flag -DREG_START__=0x" << hex << reg_start_real << endl;
        exit(255);
    }
}


// print formatters for different types
template<typename T>
void print_hex(std::ostream& out, const T& value) {
    out << typeid(T).name() << ":" << value;
};
template<>
void print_hex<unsigned char>(std::ostream& out, const unsigned char& value) {
    out << "0x" << std::hex << (unsigned int)value;
};
template<>
void print_hex<unsigned short>(std::ostream& out, const unsigned short& value) {
    out << "0x" << std::hex << (int)value;
};
template<>
void print_hex<unsigned int>(std::ostream& out, const unsigned int& value) {
    out << "0x" << std::hex << value;
};
template<>
void print_hex<unsigned long>(std::ostream& out, const unsigned long& value) {
    out << "0x" << std::hex << value;
};
template<>
void print_hex<double>(std::ostream& out, const double& value) {
    out << "0x" << std::hex << value;
};
template<>
void print_hex<float>(std::ostream& out, const float& value) {
    out << "0x" << std::hex << *(int*)&value << " (" << value << ")";
};

// define yDebugImpl so debug messages are outputted
#ifndef NO_YDEBUG
#  include <yaal/macro/common.h>
#  define yDebugImplPipe std::cout
#  define yDebugImplEndl std::endl
#endif

#endif
