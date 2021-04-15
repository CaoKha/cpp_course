#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
int closest_to_zero(int ints[], int size)
{
    std::vector<int> neg;
    std::vector<int> pos;
    int max_neg = INT32_MIN;
    int min_pos = INT32_MAX;
    for (int i = 0; i < size; i++)
    {
        if (ints[i] < 0)
            neg.push_back(ints[i]);
        else
            pos.push_back(ints[i]);
    }
    if (!neg.empty())
        max_neg = *std::max_element(neg.begin(), neg.end());
    
    if (!pos.empty())
        min_pos = *std::min_element(pos.begin(), pos.end());
    int res;
    (-max_neg < min_pos) ? res = max_neg : res = min_pos;
    return res;
}

int main()
{
    int ints[] = {-9, -8, -7, -7, 6, -3, -5, 2};
    std::cout << closest_to_zero(ints, 8) << std::endl;
}