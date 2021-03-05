#include <iostream>

int *test_function()
{
    int a_var = 6;
    int *p_to_int = new int(5);
    return p_to_int;
}

int main()
{
    int *p = test_function();
    *p = 56;
    std::cout << "value of pointer: " << *p << std::endl;
    delete p;
    return 0;
    /*
    There are 3 types of object 
        1- automatic object (destroy after out of scope)
        2- dynamic variable (use "new", follow by "delete" if not the object persist, wasted memory)
        3- global object (use "static" or place before "main", avoid using this in cpp cuz cpp is object-oriented language)
    */
}
