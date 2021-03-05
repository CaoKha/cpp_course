#include "complexe.h"
#include <iostream>

void complexe::print()
{
    std::cout << "[" << real << ", " << imag << "]" << std::endl;
};

void complexe::set_real(int v)
{
    real = v;
}
void complexe::set_imag(int v)
{
    imag = v;
}

complexe &complexe::operator+=(const complexe &d)
{
    real += d.real;
    imag += d.imag;
    return *this;
}

complexe &complexe::operator++()
{
    ++real;
    ++imag;
    return *this;
}

complexe complexe::operator++(int)
{
    complexe ret = *this;
    real++;
    imag++;
    return ret;
}

complexe::operator int()
{
    return int(real);
}

//non-member function
complexe operator+(const complexe &a, const complexe &b)
{
    complexe ret = a;
    ret += b;
    return ret;
}
