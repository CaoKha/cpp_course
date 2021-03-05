#include <iostream>
#include "../include/person.h"

int main()
{
    person jojo("Lena");
    std::cout << "the person name is " << jojo.get_name() << std::endl;
}