#include <iostream>
#include "../include/pile.h"
// #include "../include/to_string.h"

int main()
{
    Pile<int, 5> my_pile;
    try
    {
        for (int i = 0; i <= 15; i++)
        {
            my_pile.empile(i);
        }
    }

    catch (debordement &exp)
    {
        std::cout << "error: " << exp.message() << std::endl;
    }
}