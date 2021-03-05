#include <iostream>
#include <string>
enum months
{
    JAN = 1,
    FEB,
    MAR,
    APRIL,
    MAY,
    JUIN,
    JULLY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVENBER,
    DECEMBER
};

struct month_struct
{
    months month_number;
    int number_of_days;
};

int main()
{

    month_struct January;
    January.month_number = months::JAN;
    January.number_of_days = 31;

    month_struct February;
    February.month_number = months::FEB;
    February.number_of_days = 28;

    std::cout << "Month and number of days in that month: " << January.month_number << ", " << January.number_of_days << std::endl;
}