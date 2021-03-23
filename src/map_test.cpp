#include <iostream>
#include <map>
#include <string>
int main()
{
    std::map <std::string, int> m;
    std::string k1 = "a";
    std::string k2 = k1;
    m[k1] = 1;
    m[k2] = 2;
    std::cout << m[k1] << std::endl;     


}