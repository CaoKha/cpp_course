#include <iostream>

int main() {
    double d=-6.7;
    int an_integer= d;
    std::cout << an_integer << std::endl;

    unsigned int ui= (unsigned int) an_integer;

    std::cout << ui;
    /* there are 
    static_cast: cast in compile time, if type is not related, provoke error
    dynamic_cast: cast in runtime.
    const_cast: cast a const type to a different type, usually use if static_cast failed
    reinterpret_cast: cast no matter what. unsafe.
    */
}