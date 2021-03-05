#include <iostream>

int main()
{
    int tab[10];
    for (int i = 0; i < 10; ++i)
    {
        std::cout << "i = " << i << std::endl;
        tab[i] = 0;
    }
    for (int i = 0; i < 10; ++i)
    {
        std::cout << "tab[" << i << "] = " << tab[i] << std::endl;
    }

    for (int v : tab)
    {
        std::cout << v << ". ";
    }
}