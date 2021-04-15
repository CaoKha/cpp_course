#include <iostream>
#include <string>
#include <map>

std::string fizzBuzz(int number, const std::map<int, std::string> &map)
{
    std::string res;
    for (auto it = map.begin(); it != map.end(); it++)
    {
        if (number % it->first == 0)
            res.append(it->second);
    }
    if (!res.empty()) return res;
    return std::to_string(number);
}

int main()
{
    std::map<int,std::string> map;
    map[3] = "FIZZ";
    map[4] = "BUZZ";
    std::cout <<  fizzBuzz(97, map) << std::endl;
    std::cout <<  fizzBuzz(3, map) << std::endl;
    std::cout <<  fizzBuzz(24, map) << std::endl;
    std::cout <<  fizzBuzz(100, map) << std::endl;
}