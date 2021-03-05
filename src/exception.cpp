#include <iostream>
#include "../include/pile.h"
#include <exception>

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

    catch (std::out_of_range &exp)
    {
        std::cout << "Out of range: " << exp.what() << std::endl;
    }

    catch (indice_trop_grand &exp)
    {
        std::cout << "depassement: " << exp.message() << std::endl;
    }

    catch (indice_trop_petit &exp)
    {
        std::cout << "petit: " << exp.message() << std::endl;
    }

    catch (std::exception &exp)
    {
        std::cout << "exception standard " << exp.what() << std::endl;
    }

    catch (...)
    {
        std::cout << "default exception! " << std::endl;
    }
}