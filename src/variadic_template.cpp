#include <iostream>
#include <string>

// base function
template <typename T>
T concat(T v)
{
    return v;
}

// recursive function
template <typename T, typename... Args> // (typename... Args) = (typename Arg1, typename Arg2, ...)
T concat(T first, Args... args)         // (Args... args) = (Arg1 arg1, Arg2 arg2, ...)
{
    return first + concat(args...);
}

int main()
{
    int res = concat(2, 3);
    std::cout << res << std::endl;

    std::string s1 = "a", s2 = "b", s3 = "c";
    std::string str = concat(s1, s2, s3);
    std::cout << str << std::endl;
}