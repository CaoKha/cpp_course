#include <iostream>
#include <vector>

void removeElement(std::vector<int> &arr, int index)
{

    for (int i = index; i < arr.size() - 1; i++)
        arr[i] = arr[i+1];
    arr.pop_back();
}
void filter_dub(std::vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        // int temp = arr[i];
        for (auto j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] == arr[j])
            {
                removeElement(arr,j);
                j--;
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
    for (auto v : storage)
    {
        sum+=v;
    }
    return sum;
}

int main(){
    int result = compute_multiples_sum(100);
    std::cout << result << std::endl;
}
