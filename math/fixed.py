total_bits = 32
decimal_bits = 10
integer_bits = total_bits - decimal_bits

class Fixed(object):
    def __init__(self, source):
        if type(source) == Fixed:
            self.value = source.value
        elif type(source) == int:
            # what if signed?
            #self.value = source << decimal_bits
            self.value = source * self.one
        elif type(source) == float:
            self.value = int(source * self.one)
        else:
            raise NotImplementedError

        self.mask = reduce(lambda a, b: a | b, [(1 << i) for i in xrange(total_bits)])
        self._limit()

    @property
    def one(self):
        return 1 << decimal_bits

    @property
    def int(self):
        # what if signed?
        #return sekf.value >> decimal_bits
        return int(self.value / self.one)

    @property
    def float(self):
        return float(self.value) / self.one

    def _limit(self):
        self.value &= self.mask

    def __iadd__(self, o):
        print "iadd"
        if type(o) != Fixed:
            o = Fixed(o)
        self.value += o.value
        self._limit()
        return self

    def __add__(self, o):
        print "add"
        copy = Fixed(self)
        copy += o
        return copy

    def __isub__(self, o):
        print "isub"
        if type(o) != Fixed:
            o = Fixed(o)
        self.value -= o.value
        self._limit()
        return self

    def __sub__(self, o):
        print "sub"
        copy = Fixed(self)
        copy -= o
        return copy

    def __idiv__(self, o):
        print "idiv"
        if type(o) != Fixed:
            o = Fixed(o)
        if o.value < self.one:
            self.value = ((self.value * self.one) / o.value)
        else:
            self.value /= o.value / self.one
        self._limit()
        return self

    def __div__(self, o):
        print "div"
        copy = Fixed(self)
        copy /= o
        return copy

    def __imul__(self, o):
        print "imul"
        if type(o) != Fixed:
            o = Fixed(o)
        if self.value < self.one:
            self.value = (self.value * o.value) / self.one
        else:
            self.value *= o.value / self.one
        self._limit()
        return self

    def __mul__(self, o):
        print "mul"
        copy = Fixed(self)
        copy *= o
        return copy

    def __repr__(self):
        return "<Fixed 0x%x : %f>" % (self.value, self.float)

print Fixed(1), 1
print Fixed(10), 10
print Fixed(1.1), 1.1
print Fixed(-3), -3
print Fixed(-1.1) + Fixed(3.3), 2.2
print Fixed(4.0) - Fixed(2.0), 2.0
print Fixed(2.4) / Fixed(1.2), 2.4 / 1.2
print Fixed(1.1) * Fixed(3.0), 1.1 * 3.0
print Fixed(100), 100
print Fixed(0.1), 0.1
print Fixed(1000) * Fixed(0.1), 1000 * 0.1
print Fixed(1023) / Fixed(200), 1023.0 / 200.0
print Fixed(10000) / (Fixed(1023) / Fixed(200) - 1), 10000 / (1023.0 / 200.0 - 1)
