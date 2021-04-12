#include <iostream>
#include <vector>

void removeElement(std::vector<int> &arr, std::vector<int>::iterator index)
{

    for (auto it = index; it != arr.end() - 2; it++)
        *it = *(it + 1);
    arr.pop_back();
}
void filter_dub(std::vector<int> &arr)
{
    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        int temp = *it;
        for (auto jt = it + 1; jt != arr.end(); jt++)
        {
            if (temp == *jt)
            {
                removeElement(arr,jt);
                jt--;
            }
        }
    }
}

int compute_multiples_sum(int n)
{
    int sum = 0;
    int mul3 = (n-1) / 3;
    int mul5 = (n-1) / 5;
    int mul7 = (n-1) / 7;
    std::vector<int> storage;
    for (int i = 1; i <= mul3; i++)
    {
        storage.push_back(3 * i);
    }
    for (int i = 1; i <= mul5; i++)
    {
        storage.push_back(5 * i);
    }
    for (int i = 1; i <= mul7; i++)
    {
        storage.push_back(7 * i);
    }
    filter_dub(storage);
    for (auto& v : storage)
    {
        sum+=v;
    }
    return sum;
}

int main(){
    int result = compute_multiples_sum(15);
    std::cout << result << std::endl;
}
