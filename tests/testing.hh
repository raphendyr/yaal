#ifndef __YAAL_TESTING__
#define __YAAL_TESTING__ 1


// yaal stuff
typedef unsigned long long reg_size_t;
#define YAAL_SMALL_REG_SIZE reg_size_t
#define YAAL_BIG_REG_SIZE reg_size_t


// std stuff
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <assert.h>


// helpers...
#define ASSERT(left, test, right) do { \
    std::cout << "assert(0x" << std::hex << (int)(left) << " " #test " 0x" << std::hex << (int)right << ");" << std::endl; \
    assert(left test right); \
} while (0)

#define EQ(left, right) ASSERT(left, ==, right)

#define OPER(left, ref, oper, value) do { \
    left oper value; \
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

#endif
