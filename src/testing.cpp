#include <iostream>

class A
{
    public:
    int value() { return 1;}
    int value() const {return 2;}  
};

int main() {
    const A *a = new A();
    int val = a->value();
    std::cout << val<< std::endl;
}