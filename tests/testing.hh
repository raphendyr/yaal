#ifndef __YAAL_TESTING__
#define __YAAL_TESTING__ 1


// yaal stuff
typedef unsigned long long reg_size_t;
#define YAAL_SMALL_REG_SIZE reg_size_t
#define YAAL_BIG_REG_SIZE reg_size_t


// std stuff
#include <cstdint>
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


#endif
