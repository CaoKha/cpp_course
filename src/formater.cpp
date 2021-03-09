#include <iostream>
#include <iomanip>

int main()
{
    int a_number = 10;
    std::cout.flags(std::ios_base::hex);
    std::cout << "Number 10 in hex: " << a_number << std::endl;
    std::cout.flags(std::ios_base::oct);
    std::cout << "Number 10 in oct: " << a_number << std::endl;

    bool value = true;
    std::cout << "Boolean in numberic: " << value << std::endl;
    std::cout.flags(std::ios_base::boolalpha);
    std::cout << "Boolean in alpha-numeric: " << value << std::endl;
    double pi = 314151689796535;
    std::cout.flags(std::ios_base::scientific);
    std::cout << "Pi in scientific: " << pi << std::endl;

    std::cout << "Another way to format the output in hex: " << std::hex << a_number << std::endl;
    std::cout << "Another way to format the output in oct: " << std::oct << a_number << std::endl;

    std::cout << "Using setprecision (require iomanip lib) to format the output: " << std::setprecision(3) << pi << std::endl;
}