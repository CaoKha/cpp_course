#include <iostream>
struct month
{
    int num;
    int num_of_day;
};

void show_details(const month &m)
{ // passing by reference, avoid copying object. The "const" here is to remind the developer not to modify the variable inside this function (for colab)
    std::cout << m.num << "," << m.num_of_day << std::endl;
}

month create_month(int n, int n_of_day)
{
    month j;
    j.num = n;
    j.num_of_day = n_of_day;
    return j;
}

int main()
{
    month january;
    january.num = 1;
    january.num_of_day = 32;
    show_details(january);
    month feb = create_month(2, 29);
    show_details(feb);
}