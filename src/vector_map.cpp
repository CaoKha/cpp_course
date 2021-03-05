#include <vector>
#include <map>
#include <string>
#include <iostream>

int main()
{
    std::map<std::string, int> dict;
    dict["Fabien"] = 45;
    dict["Lena"] = 3;
    dict["Corinne"] = 44;

    dict.insert(std::make_pair("paulin", 15));
    for (std::map<std::string, int>::iterator it = dict.begin(); it != dict.end(); ++it)
    {
        std::cout << (*it).first << "->" << (*it).second << " ";
    }
    std::cout << std::endl;

    // another way to do for loop in C++
    for (auto v : dict)
    {
        std::cout << v.first << "->" << v.second << " ";
    }
    std::cout << std::endl;

    //find Fabien
    auto p = dict.find("Fabien");
    if (p != dict.end())
        std::cout << (*p).second << std::endl;

    //find someone not existed
    //auto v = dict["toto"]; // this will create toto in dict, so avoid doing this
    auto v = dict.find("Toto");
    if (v != dict.end())
        std::cout << (*v).second << std::endl;
    else
        std::cout << "Not found!" << std::endl;

    //illustration of vector
    std::vector<int> vec;

    for (int i = 0; i < 10; i++)
    {
        vec.push_back(i);
    }

    // show value
    for (int v : vec)
    {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    //another way to do it
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}