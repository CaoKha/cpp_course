#include "../include/person.h"
#include "../include/car.h"
#include<iostream>
int main()
{
    person::set_counter(1);
    person jojo;
    jojo.set_name("Fabien");
    car tintine;
    jojo.buy(tintine);
    tintine.show_owner();
    jojo.show_counter();
    jojo.add_to_counter(2);
    jojo.show_counter();
}