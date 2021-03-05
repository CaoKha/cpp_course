#include<iostream>
#include "car.h"
#include "person.h"

void car::show_owner() {
    std::cout <<"The owner is " << the_owner->get_name()<<std::endl;
}

void car::set_owner(person* p){
    the_owner = p;
}