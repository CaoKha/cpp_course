#include <iostream>
#include <string>
typedef enum days
{
    SUN,
    MON,
    TUE,
    WED,
    THU,
    FRI,
    SAT
} days;
inline days operator++(days d)
{
    return static_cast<days>((static_cast<int>(d) + 1) % 7);
}

int main()
{
    days d(SUN);
    d = ++d;
    std::cout << d << std::endl;
}