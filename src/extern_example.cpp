#include <iostream>

extern double surface_calculator(double);
extern "C" void cfunc();

int main()
{
    cfunc();
    double surf = surface_calculator(10);
}