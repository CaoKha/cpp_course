#include <iostream>
#include <fstream>

int main()
{
    std::fstream myfile("test/test3.txt", std::ios::out);
    myfile << "Olala!\n";
    myfile.close();

    std::ofstream outputfile("test/test3.txt", std::ios::app);
    outputfile << "Heyo!\n";
    outputfile.close();

    std::ifstream inputfile("test/test4.txt", std::ios::in);
    if (!inputfile)
    {
        std::cout << "Failed to open the file!\n";
    }
    else
        std::cout << "Successfully open the file!\n";

    std::string str;
    while (std::getline(inputfile, str))
    {
        std::cout << str << "\n";
    }
    inputfile.close();
}