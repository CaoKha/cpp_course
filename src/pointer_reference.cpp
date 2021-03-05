#include <iostream>

int main()
{
    int var = 6;
    int *pointer_to_var; //pointer
    pointer_to_var = &var;
    int &ref_to_var = var; //always init with reference
    ref_to_var = 8;

    std::cout << "Before: " << std::endl;
    std::cout << "var = " << var << std::endl;
    std::cout << "pointer_to_var = " << pointer_to_var << std::endl;
    std::cout << "ref_to_var = " << ref_to_var << std::endl
              << std::endl;

    //try to infuence the var
    ref_to_var = 9;
    *pointer_to_var = 9;

    std::cout << "After: " << std::endl;
    std::cout << "var = " << var << std::endl;
    std::cout << "pointer_to_var = " << pointer_to_var << std::endl;
    std::cout << "ref_to_var = " << ref_to_var << std::endl
              << std::endl;

    //const
    //constant pointer, cant cange pointer: ptr = ...
    int *const ptr = &var;
    //pointer point to constant var, cant change var: *ptr2 = ...
    const int *ptr2 = &var;
    //ref to constant var
    const int &ref = var;

    std::cout << "After adding constant in declaration: " << std::endl;
    std::cout << "var = " << var << std::endl;
    std::cout << "pointer_to_var = " << ptr << std::endl;
    std::cout << "pointer2_to_var = " << ptr2 << std::endl;
    std::cout << "ref_to_var = " << ref << std::endl
              << std::endl;

    int var2 = 12;
    *ptr = var2;
    ptr2 = &var2;

    std::cout << "Trying to modify: " << std::endl;
    std::cout << "modified_var = " << var << std::endl;
    std::cout << "adress of var = " << &var << std::endl;
    std::cout << "adress of var2 = " << &var2 << std::endl;
    std::cout << "pointer_to_var_after = " << ptr << std::endl;
    std::cout << "*pointer_to_var_after = " << *ptr << std::endl;
    std::cout << "*pointer2_to_var_after = " << *ptr2 << std::endl;
    std::cout << "adress of ref = " << &ref << std::endl;

    return 0;
}