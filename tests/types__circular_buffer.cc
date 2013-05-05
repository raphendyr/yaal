#include <yaal/types/circular_buffer.hh>
using namespace yaal;

#include <iostream>

template<typename T>
void print_cb(const T& cb) {
    unsigned int e = cb.size();
    printf("CircularBuffer of size %u ", e);
    if (cb.full())
        printf("is full");
    else if (cb.empty())
        printf("is empty");
    printf("\n");
    for (unsigned int i = 0; i < e; i++) {
        printf("  elem at %u = %u\n", i, cb[i]);
    }
    printf("\n");
}

int main(void) {
    CircularBuffer<5, int> cb;

    cb.push_back(1);
    cb.push_back(2);
    cb.push_back(3);
    print_cb(cb);

    cb.push_back(4);
    cb.push_back(5);
    print_cb(cb);

    cb.push_back(6);
    cb.push_back(7);
    print_cb(cb);

    cb.push_back(8);
    cb.push_back(9);
    print_cb(cb);

    printf("popped f: %u\n", cb.pop_front());
    printf("popped f: %u\n", cb.pop_front());
    print_cb(cb);

    cb.push_front(100);
    cb.push_front(99);
    cb.push_front(98);
    print_cb(cb);

    printf("popped f: %u\n", cb.pop_front());
    printf("popped f: %u\n", cb.pop_front());
    printf("popped b: %u\n", cb.pop_back());
    printf("popped b: %u\n", cb.pop_back());
    print_cb(cb);

    printf("popped f: %u\n", cb.pop_front());
    printf("popped f: %u\n", cb.pop_front());
    print_cb(cb);

}
