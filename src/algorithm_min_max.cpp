#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vec{1, 13, 3, 8, 5, 21, 34};
    std::cout << "Vec = ";
    for (int v : vec)
    {
        std::cout << v << " ";
    }
    std::cout << std::endl;
    int mini = std::min(4, 5); // minimum between 2 inputs
    std::cout << "mini between 4 and 5 is " << mini << std::endl;
    mini = std::min({5, 7, 2}); // minimum in a list
    std::cout << "mini of {5, 7, 2} is " << mini << std::endl;

    std::pair<int, int> p = std::minmax(4, 5); // determines min and max at once as an ordered pair.
    std::cout << "min of (4,5) is: " << p.first << ", max of (4,5) is: " << p.second << std::endl;

    auto m = std::min_element(vec.begin(), vec.end()); // return min element in range
    std::cout << "mini of vec is: " << *m << std::endl;

    auto q = std::minmax_element(vec.begin(), vec.end());
    std::cout << "min of vec is: " << *q.first << ", max of vec is: " << *q.second << std::endl;
}