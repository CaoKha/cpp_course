#include "../include/person.h"
#include "../include/developer.h"
#include <iostream>
int main()
{
    person jojo{"Arthur"};
    developer titi{"Lena"};
    // titi.set_name("bob");
    titi.set_language("Java");
    // std::cout << "Name: "<< titi.get_name() << std::endl;
    // std::cout << "Language: "<< titi.get_language() << std::endl;
    std::cout << titi.dev_show() << std::endl;
    developer *pdev = new developer {"Outsider","Ruby"};
    delete pdev;
}