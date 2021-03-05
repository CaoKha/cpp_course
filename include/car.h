#ifndef __CAR__
#define __CAR__

#include <string>
#include <iostream>
class person;

class grey_card
{
    std::string card_name;
};

class car
{
    std::string name;
    grey_card *card;
    person *the_owner;

public:
    car(std::string n) : name(n)
    {
        card = new grey_card();
        std::cout << "A car is created! ";
    }

    void show_owner();
    void set_owner(person *);
    std::string get_car_name() { return name; }
    void show_car_name() { std::cout << "Car: " << get_car_name() << std::endl; }

    ~car()
    {
        delete card;
        std::cout << "A car is destroyed! " << std::endl;
    }

    car(const car &d) //copy using operator()
    {
        name = d.name;
        card = new grey_card(*(d.card));
        std::cout << "A car is copied with operator() " << std::endl;
    }

    void operator=(const car &d) //copy using operator=
    {
        if (this != &d)
        {
            name = d.name;
            delete card;
            card = new grey_card(*(d.card));
            std::cout << "A car is copied with operator= " << std::endl;
        }
    }
};

#endif