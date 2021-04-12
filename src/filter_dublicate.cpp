#include <iostream>
#include <vector>
#include <algorithm>

void removeElement(std::vector<int> &arr, int index)
{
    int i;
    for (i = index; i < arr.size() - 1; i++)
        arr[i] = arr[i + 1];
    arr.pop_back();
}
std::vector<int> filter_dub(std::vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int temp = arr[i];
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (temp == arr[j])
            {
                removeElement(arr,j);
                j--;
            }
        }
    }
    return std::vector<int>(arr);
}

int main()
{
    std::vector<int> arr = {1, 2, 8, 4, 3, 5, 8};
    std::vector<int> new_arr = filter_dub(arr);
    for (auto v : new_arr)
    {
        std::cout << v << ";";
    }
}