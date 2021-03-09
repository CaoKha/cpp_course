#ifndef __MYCOMPLEX__
#define __MYCOMPLEX__

#include <iostream>

class A
{
public:
    A(int) {}
};

// discriminator class template
template <typename T>
class discriminator
{
    bool value;

public:
    discriminator() : value(true){};
    bool get_value() { return value; }
};

// discriminator class template redefine in special case
template <>
class discriminator<A>
{
    int value;

public:
    discriminator() : value(0){};
    int get_value() { return value; }
};

// complex class template
template <typename R = int, typename I = int, char SEPARATOR = ','>
class Complex
{
    R real;
    I img;
    discriminator<R> *d;

public:
    Complex(R a, I b) : real(a), img(b) {}
    void print(bool) { std::cout << "[" << real << SEPARATOR << img << "]" << std::endl; }
    void print(int) { std::cout << "unshowable! " << std::endl; }
    void print() { print(d->get_value()); }
};

#endif