#include <iostream>

int main()
{
    bool cond1 = true, cond2 = false;

    if (cond1 || cond2)
    {
        std::cout << "the condition is true" << std::endl;
    }
    else
    {
        std::cout << "the condition is false" << std::endl;
    }

    int *p = nullptr;
    if (p)
    { // if(p) == if(p!=nullptr), 0 = false, 1 = true, nullptr = 0
        std::cout << "p = 0" << std::endl;
    }
    else
        std::cout << p << std::endl;

    int an_integer = 5;
    if (5 == an_integer)
    {
        std::cout << an_integer << std::endl;
    }
}