YAAL interfaces
===============

Interfaces are documented here.
Some interfaces can have default implementations of some methods.
Remember to implement methods marked with _IMPLEMENT_.

Instead of pure virtual / abstract methods we use [Curiously recurring template pattern](http://en.wikipedia.org/wiki/Curiously_recurring_template_pattern) (CRTP).
More accurately _Static polymorphism_.

This concept allows kind of inheritance without build time virtual tables.
This means that inheritance is done on build time.

Developer this means that you need to add you class as template parameter to interface:

``c++
class Implementation : public Interface<Implementation> {
    void implemented_method();
};
```
