#include "../include/square.h"
#include <iostream>
int main()
{
    square obj;
    obj.cote = 10;
    double surf = obj.surface_calcul();
    std::cout<< "surf = " << surf << std::endl;
}