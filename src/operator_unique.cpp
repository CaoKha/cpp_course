#include "../include/complexe.h"
#include <iostream>
int main()
{
    complexe c1{3, 4};
    std::cout << "C1 = ";
    c1.print();

    complexe c2{5, 6};
    std::cout << "C2 = ";
    c2.print();

    complexe c3 = c1++;
    std::cout << "C1++ = ";
    c3.print();

    complexe c4 = ++c2;
    std::cout << "++C2 = ";
    c4.print();
}