#include <iostream>
#include <fstream>
#include <sstream>

void print(std::ostream &output)
{
    output << "Hello!";
}

struct A
{
    int data;
};

std::ostream &operator<<(std::ostream &os, const A &v)
{
    os << "[" << v.data << "]";
    return os;
}
int main()
{
    print(std::cout);
    std::cout << std::endl;
    std::ofstream my_file("test");
    print(my_file);
    my_file.close();
    std::cout << "saving the file";
    std::ostringstream ss;
    print(ss);
    std::cout << " in string " << ss.str();
    std::cout << std::endl;

    int my_var = 5;
    A my_data{4};
    std::cout << "coucou" << my_var << " "<< my_data <<std::endl;
}