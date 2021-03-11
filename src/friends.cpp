#include <iostream>

template <typename T>
class Complex
{
    T real;
    T imag;

public:
    Complex(T a, T b) : real(a), imag(b) {}
    friend Complex<T> operator+(const Complex<T> &g, const Complex<T> &d)
    //operator+ is belong to a different class so we have to use "friend" here
    //in order for operator+ function to access to our class
    {
        return Complex<T>(g.real + d.real, g.imag + d.imag);
    }

    T &get_real()
    {
        return real;
    }

    T &get_imag()
    {
        return imag;
    }
};

int main()
{
    Complex<int> v1(1, 2);
    Complex<int> v2(3, 5);
    Complex<int> res = v1 + v2;
    std::cout << "The result is: [" << res.get_real() << ", " << res.get_imag() << "]" << std::endl;
}