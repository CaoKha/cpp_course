#include <iostream>
#include <string>
#include <algorithm>

std::string encode(std::string plainText)
{
    int count = 1;
    std::string res;
    for (auto i =0; i < plainText.size(); i++)
    {
        if (plainText[i+1] == plainText[i])
            count++;
        else {
            res += std::to_string(count);
            res += plainText[i];
            count = 1;
        }
    }
    return res;
}

int main()
{
    std::string str("aaabbcccada");
    std::string new_str = encode(str);
    std::cout << str.size() << std::endl;
    std::cout << new_str << std::endl;
}