#include <iostream>
#include "person.h"
#include "car.h"

int person::counter = 0;
//constructor
person::person(std::string s, int a) : name(s), age(a)
{
    std::cout << "constructor call from person named " << name << " with the age of " << age << std::endl;
}
// end of constructor
void person::set_name(std::string n)
{
    name = n;
}

std::string person::get_name()
{
    return name;
}

void person::buy(car &c)
{
    the_car = &c;
    c.set_owner(this);
}

void person::set_counter(int v)
{
    counter = v;
}

void person::show_counter()
{
    std::cout << "The static counter is now " << person::counter << std::endl;
}

void person::add_to_counter(int a)
{
    counter = counter + a;
}

int person::get_age()
{
    return age;
}

//destructors
person::~person()
{
    std::cout << "destructor call from person named " << name << " with the age of " << age << std::endl;
}