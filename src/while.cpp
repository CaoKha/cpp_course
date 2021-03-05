#include <iostream>

int main()
{
    int index = 0;
    const int max = 10;
    int tab[max];
    while (index < max)
    {
        tab[index] = index;
        index++;
    }
    for (int v : tab)
    {
        std::cout << v << std::endl;
    }
    int *p = new int(5);
    while (p && *p != 5)
    { // if first condition is false then the follow condition wont be excuted
        std::cout << "its not ok" << std::endl;
    }
    std::cout << "its ok" << std::endl;
    delete p;
}