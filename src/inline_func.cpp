#define PI 3.1415
#ifdef _DEBUG
#include <iostream>
#endif //_DEBUG

inline double surface_calculator_inline(double r)
{
    return PI * r * r;
}

int main()
{
    double surf = surface_calculator_inline(10);
#ifdef _DEBUG
    std::cout << "surface = " << surf << std::endl;
#endif
}