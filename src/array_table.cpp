#include <iostream>
#include <array>

void print_array(int *array)
{
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "tab[" << i << "] = " << *(array + i) << std::endl;
    }
}
int main()
{
    int tab[5];
    for (int i = 0; i < 5; ++i)
        tab[i] = i;

    std::cout << "Normal for loop: " << std::endl;
    for (int i = 0; i < 5; ++i)
        std::cout << "tab[" << i << "] = " << tab[i] << std::endl;

    std::cout << "Special for loop: " << std::endl;
    int i = 0;
    for (int v : tab)
    {
        std::cout << "tab[" << i << "] = " << v << std::endl;
        i++;
    }

    std::cout << "Test print array funtion: " << std::endl;
    print_array(tab);
    //we can use a pointer to access the values of the array
    int *ptab = &tab[0]; // point to the first element of the array
    //change the third value of the array (tab[2] = 5)
    *(ptab + 2) = 5;
    std::cout << "After changing the third value: " << std::endl;
    print_array(tab);

    std::cout << "Test value of tab = " << tab << std::endl;
    std::cout << "Tab is a pointer to the first element to the array" << std::endl;
    // std::cout << "adress of tab = " << &tab << std::endl; // adress of a pointer is its value

    std::cout << "Declare array with 'std::array': " << std::endl;

    std::array<int, 5> arr;
    // print_array(arr); //cant do this becuz cannot convert std array to pointer
    for (int v : arr)
        std::cout << v << std::endl;
}