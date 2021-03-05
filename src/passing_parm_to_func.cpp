#include <iostream>

//definition
int tab_sum(int *tab, int length)
{
    int result = 0;
    for (int i = 0; i < length; ++i)
    {
        result += tab[i];
    }
    return result;
}

void exchanger(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int tab[] = {3, 5, 6, 4, 7, 8};
    int sum = tab_sum(tab, sizeof(tab) / sizeof(tab[0]));
    std::cout << "sum of the array = " << sum << std::endl;

    int i = 1;
    int j = 2;

    exchanger(i, j);
    std::cout << "i = " << i << "; j = " << j << std::endl;
}