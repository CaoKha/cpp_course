#include <iostream>
#include <vector>
#include <algorithm>

void print(int v)
{
    std::cout << v << " ";
}

int main()
{
    std::vector<int> vec{1, 13, 3, 8, 5, 21, 34};
    std::vector<int> vec2{19, 233, 144, 89, 55};
    /*std::sort: Sorts the elements in the range [first,last) into ascending order.*/

    std::cout << "Vec = ";
    std::for_each(vec.begin(), vec.end(), print);
    std::cout << std::endl;
    std::cout << "Vec2 = ";
    std::for_each(vec2.begin(), vec2.end(), print);
    std::cout << std::endl;

    std::sort(vec.begin(), vec.end());
    std::sort(vec2.begin(), vec2.end());

    std::cout << "Vec after using std::sort is:" << std::endl;
    std::for_each(vec.begin(), vec.end(), print);
    std::cout << std::endl;

    /*std::binary_search: Test if value exists in sorted sequence
    Returns true if any element in the range [first,last) is equivalent to val, and false otherwise.
    On average, logarithmic in the distance between first and last: Performs approximately log2(N)+2 element comparisons 
    (where N is this distance).*/
    bool is13 = std::binary_search(vec.begin(), vec.end(), 13);
    if (is13)
        std::cout << "number 13 is found!" << std::endl;

    /*std::merge: Merge sorted ranges
    Combines the elements in the sorted ranges [first1,last1) and [first2,last2), 
    into a new range beginning at result with all its elements sorted.*/
    std::vector<int> vec3(20);
    std::cout << "Vec3 = " << std::endl;
    std::for_each(vec3.begin(), vec3.end(), print);
    std::cout << std::endl;

    std::merge(vec.begin(), vec.end(), vec2.begin(), vec2.end(), vec3.begin());
    std::cout << "Vec3 after using std::merge of Vec and Vec2 is:" << std::endl;
    std::for_each(vec3.begin(), vec3.end(), print);
    std::cout << std::endl;
}