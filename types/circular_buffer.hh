#ifndef __YAAL_TYPES__CIRCULAR_BUFFER__
#define __YAAL_TYPES__CIRCULAR_BUFFER__ 1

#include <inttypes.h>
#include "traits.hh"
#include "../qualifiers.hh"

// for api: http://www.boost.org/doc/libs/1_52_0/libs/circular_buffer/doc/circular_buffer.html


template< uint8_t buffer_size, typename elem_t = uint8_t >
class CircularBuffer {
    typedef CircularBuffer<buffer_size, elem_t> self_type;
    typedef typename TypeTraits<elem_t>::on_input elem_t_on_input;
    typedef typename TypeTraits<elem_t>::on_input elem_t_on_modify;

public:
    typedef elem_t element_type;
    typedef uint8_t size_type;

private:
    uint8_t tail;
    uint8_t head;
    uint8_t count;
    elem_t buffer[buffer_size];

    inline
    void forward(uint8_t& i) const {
        i++;
        if (i == buffer_size)
            i = 0;
    }

    inline
    void backward(uint8_t& i) const {
        if (i == 0)
            i = buffer_size - 1;
        else
            i--;
        // FIXME: witch one make faster code?
        /*
        if (i == 0)
            i = size;
        i--;
        */
    }

    inline
    uint8_t forward_modulo(uint8_t i, uint8_t n) const {
        uint8_t o = buffer_size - i;
        if (n >= o)
            i = n - o;
        else
            i = i + n;
        return i;
    }

public:
    CircularBuffer() : tail(0), head(0), count(0) {}

    /* Generic operations */

    // FIXME: better function name
    uint8_t freeSpace() const {
        return buffer_size - count;
    }

    bool full() const {
        return count == buffer_size;
    }

    bool empty() const {
        return count == 0;
    }

    uint8_t size() const {
        return count;
    }

    uint8_t capacity() const {
        return buffer_size;
    }

    void clear() {
        head = 0;
        tail = 0;
        count = 0;
    }

    /* opers on front */

    elem_t_on_modify front() {
        return buffer[tail];
    }

    void push_front(elem_t_on_input elem) {
        backward(tail);
        buffer[tail] = elem;
        if (full())
            backward(head);
        else
            count++;
    }

    void erase_front(uint8_t n = 1) {
        while (n-- && !empty()) {
            count--;
            forward(tail);
        }
    }

    elem_t pop_front() {
        elem_t elem = front();
        erase_front();
        return elem;
    }

    /* opers on back */

    elem_t_on_modify back() {
        uint8_t h = head;
        backward(h);
        return buffer[h];
    }

    void push_back(elem_t_on_input elem) {
        buffer[head] = elem;
        forward(head);
        if (full())
            forward(tail);
        else
            count++;
    }

    void erase_back(uint8_t n = 1) {
        while (n-- && !empty()) {
            count--;
            backward(head);
        }
    }

    elem_t pop_back() {
        erase_back();
        return buffer[head];
    }

    /* random access */

    elem_t_on_modify at(uint8_t i) {
        return buffer[forward_modulo(tail, i)];
    }

    const elem_t_on_modify at(uint8_t i) const {
        return buffer[forward_modulo(tail, i)];
    }

    elem_t_on_modify operator[] (uint8_t i) {
        return at(i);
    }

    const elem_t_on_modify operator[] (uint8_t i) const {
        return at(i);
    }

    /* iterators */

    template<typename funktion_t>
    YAAL_INLINE("CircularBuffer::foreach")
    void foreach(funktion_t callback) {
        for (uint8_t c = 0, e = count, i = tail; c < e; c++, forward(i)) {
            callback(c, buffer[i]);
        }
    }

    // NOTE: Iterators might be not so optimal on avr?
    // begin
    // end
    // rbegin
    // rend
};

#endif
