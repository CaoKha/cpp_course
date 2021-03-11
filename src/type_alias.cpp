#include <vector>
#include <iostream>

template <typename R>
class MyConteneur
{
    std::vector<R> data;

public:
    //constructor
    MyConteneur(R v)
    {
        data.push_back(v);
    }

    //type alias
    using iterator = std::vector<R>;

    std::vector<R> begin()
    {
        return data;
    }
};

template <typename T>
typename T::iterator return_item0(T conteneur)
{
    return conteneur.begin();
}

int main()
{
    std::vector<int> v1(2, 3);
    std::cout << return_item0(v1)[0] << std::endl;

    MyConteneur<int> mc(6);
    std::cout << return_item0(mc)[0] << std::endl;
}