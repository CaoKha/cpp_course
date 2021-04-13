#include <iostream>
#include <vector>
#include <algorithm>

int find_smallest_interval(std::vector<int> numbers)
{
    std::vector<int> sorted_numbers(numbers);
    std::vector<int> interval_table;
    std::sort(sorted_numbers.begin(),sorted_numbers.end());
    for (auto it = sorted_numbers.begin()+1; it != sorted_numbers.end(); it++)
    {
        int interval = *it - *(it-1); 
        interval_table.push_back(interval);
    }
    return *std::min_element(interval_table.begin(),interval_table.end());
}

int main()
{
    std::vector<int> arr{1,100,5,88,120};
    int res = find_smallest_interval(arr);
    std::cout << res << std::endl;   
}