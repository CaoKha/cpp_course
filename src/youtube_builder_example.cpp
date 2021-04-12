#include <iostream>
#include <string>
#include <memory>

class Person;
class PersonBuilder;
class PersonAddressBuilder;
class PersonJobBuilder;

class Person
{
    std::string street_address, post_code, city;
    std::string company_name, position;
    int annual_income = 0;
    Person() {} // make constructor private
public:
    friend class PersonBuilder;
    friend class PersonAddressBuilder;
    friend class PersonJobBuilder;
    static PersonBuilder create();

};

class PersonBuilder
{
    Person p;

protected:
    Person &person;
    explicit PersonBuilder(Person &person) : person(person) {}

public:
    PersonBuilder() : person(p) {}
    PersonAddressBuilder lives();
    PersonJobBuilder works();
};

PersonBuilder Person::create()
{
    return PersonBuilder();
}

class PersonAddressBuilder: public PersonBuilder {
    typedef PersonAddressBuilder Self;
public:
    explicit PersonAddressBuilder(Person& person) : PersonBuilder(person){}

    Self& at(std::string street_address)
    {
        person.street_address = street_address;
        return *this;
    }

    Self& with_postcode(std::string post_code)
    {
        person.post_code = post_code;
        return *this;
    }

    Self& in(std::string city)
    {
        person.city = city;
        return *this;
    }

};

class PersonJobBuilder : public PersonBuilder
{
    typedef PersonJobBuilder Self;

public:
    PersonJobBuilder(Person &person) : PersonBuilder(person) {}
    Self &at(std::string company_name)
    {
        person.company_name = company_name;
        return *this;
    }
    Self &as_a(std::string position)
    {
        person.position = position;
        return *this;
    }
    Self &earning(int annual_income)
    {
        person.annual_income = annual_income;
        return *this;
    }
};