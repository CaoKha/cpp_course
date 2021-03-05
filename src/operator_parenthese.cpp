#include <iostream>

class Functor
{
    int _value;

public:
    Functor(int a) : _value(a) {}
    void operator()(int v)
    {
        if (_value > v)
            std::cout << "The input is " << v << std::endl;
        else
            std::cout << "The input " << v << " is bigger than " << _value << std::endl;
    }
};

int main()
{
    Functor f(3);
    f(4);
}