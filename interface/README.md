YAAL interfaces
===============

Interfaces are documented here.
Some interfaces can have default implementations of some methods.
Remember to implement methods marked with _IMPLEMENT_.

Instead of pure virtual / abstract methods we use [Curiously recurring template pattern](http://en.wikipedia.org/wiki/Curiously_recurring_template_pattern) (CRTP).
More accurately _Static polymorphism_.

This concept allows kind of inheritance without run time virtual tables.
This means that method lookup is done at build time.

For the developer this means that you need to add derived class as template parameter for the parent class:

``c++
class Implementation : public Interface<Implementation> {
    void implemented_method() {}
};
```

With templated classes and deeper intheritances hollowing should help.

macro/crtp.hh
-------------

File contains helper macros to ease deeper inheritances with CRTP.

Follow this example when implementing interface or any other CRTP class.

```c++
#define YAAL_CRTP_CLASS MyClass<Argument1, argument2, YAAL_CRTP_ARGUMENT>
template< typename Argument1, uint8_t argument2, YAAL_CRTP_TEMPLATE_ARG >
class MyClass :
    public interface::Interface<YAAL_CRTP_DERIVED>
{
    typedef YAAL_CRTP_DERIVED derived_type;
    typedef YAAL_CRTP_CLASS self_type;
    typedef interface::Interface<YAAL_CRTP_DERIVED> super_type;
#undef YAAL_CRTP_CLASS

    public:

    YAAL_CRTP_ASSIGNMENTS(derived_type, super_type);
};
```

Read the file for documentation of specific macros.
