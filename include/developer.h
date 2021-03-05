#ifndef __DEV__
#define __DEV__

#include "person.h"
class developer : public person
{
    std::string language;

public:
    void set_language(std::string l) { language = l; }
    std::string get_language(){ return language;}
    // using person::person;
    developer(std::string = "Bob", std::string = "Cpp");
    // developer(std::string n) : person(n), language("Cpp"){}
    // developer() : person("unknown"), language("Cpp"){}
    std::string dev_show();
};

#endif