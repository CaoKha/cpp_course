#include <iostream>
#include "../include/person.h"
#include "../include/car.h"

int main(){
    person jojo("Fabien");
    std::cout << "The person is called " << jojo.get_name() << " and he/she is " << jojo.get_age() << " years old" << std::endl; 
    person titi("Lena", 3);
    std::cout << "The person is called " << titi.get_name() << " and he/she is " << titi.get_age() << " years old" << std::endl; 
}