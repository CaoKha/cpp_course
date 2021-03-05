#include <iostream>
#include "../include/surface_calculator.h"

int main()
{
    double surf = surface_calculator(10);
    std::cout << "surface = " << surf << std::endl;
}