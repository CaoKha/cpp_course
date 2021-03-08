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

    //testing with iostream
    int my_var = 5;
    A my_data{4};
    std::cout << "my_var = " << my_var << " and my_data= " << my_data << std::endl;
    char cc = '9';
    std::cout << "this is output using std::cout.put: ";
    std::cout.put(cc);
    std::cout.write("\n", 1); // "a" is const char , 'a' is char
    char tabchar[] = {'f', 'a', 'b', 'i', 'e', 'n'};
    std::cout << "this is output using std::cout.write: ";
    std::cout.write(tabchar, 6);
    std::cout.put('\n');

    //testing with ofstream
    std::ofstream output_file("test");
    output_file << "coucou" << my_var << " " << my_data << std::endl;
    output_file.put(cc);
    output_file.write(tabchar, 6);
    output_file.close();

    //testing with ifstream
    std::ifstream entry("test2");
    std::string line;
    while (std::getline(entry, line))
    {
        std::cout << "this is new line : " << line << '\n';
    }
    entry.close();
}