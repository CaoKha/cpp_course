#include <iostream>
#include <array>

int getPosition(int n)
{
    std::array<int, 6> displacement({1, -2, -3, -1, 2, 3});
    int cur_pos = 0;
    int step1 = 1;
    int step2 = -2;
    if (n == 1)
        return step1;
    else if (n == 2)
        return step2;
    // else return (getPosition(n-1) - getPosition(n-2));
    else
    {
        for (int i = 0; i < (n % displacement.size()); i++)
            cur_pos += displacement[i];
        return cur_pos;
    }
}
int main()
{
    std::cout << getPosition(2147483647) << std::endl;
}