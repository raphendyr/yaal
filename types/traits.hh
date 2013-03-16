#ifndef __YAAL_TYPES__TRAITS__
#define __YAAL_TYPES__TRAITS__ 1

template<typename T>
struct TypeTraits {
    typedef T& on_input;
    typedef T& on_modify;
};

template<typename T>
struct PrimitiveTypeTraits {
    typedef T on_input;
    typedef T& on_modify;
};

template<> struct TypeTraits<unsigned char> : public PrimitiveTypeTraits<unsigned char> { };
template<> struct TypeTraits<unsigned short> : public PrimitiveTypeTraits<unsigned short> { };
template<> struct TypeTraits<unsigned int> : public PrimitiveTypeTraits<unsigned int> { };
template<> struct TypeTraits<unsigned long> : public PrimitiveTypeTraits<unsigned long> { };
template<> struct TypeTraits<signed char> : public PrimitiveTypeTraits<signed char> { };
template<> struct TypeTraits<signed short> : public PrimitiveTypeTraits<signed short> { };
template<> struct TypeTraits<signed int> : public PrimitiveTypeTraits<signed int> { };
template<> struct TypeTraits<signed long> : public PrimitiveTypeTraits<signed long> { };
template<> struct TypeTraits<double> : public PrimitiveTypeTraits<double> { };
template<> struct TypeTraits<float> : public PrimitiveTypeTraits<float> { };

#endif
