#include <sstream>
#include <iostream>

namespace demo
{
    std::string to_string(int v)
    {
        std::stringstream ss;
        ss << v;
        return ss.str();
    }
}