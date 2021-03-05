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

    complexe c3 = c1 + c2;
    std::cout << "C1 + C2 = ";
    c3.print();

    c1 += c3;
    std::cout << "2*C1 + C2 = ";
    c1.print();
}