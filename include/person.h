#ifndef __PERSON__
#define __PERSON__

#include <string>
class car;

class person
{
    std::string name;
    int age;
    car *the_car;
    static int counter;
    

public:
    void buy(car &);
    void set_name(std::string);
    std::string get_name();
    int get_age();
    static void set_counter(int);
    void show_counter();
    void add_to_counter(int);
    person(std::string = "Bob", int = 0);
    ~person();
    
};

#endif