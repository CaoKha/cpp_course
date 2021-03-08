#include <iostream>
#include <vector>
#include <algorithm>

void print(int v)
{
    std::cout << v << " ";
}

int main()
{
    std::vector<int> vec{1, 2, 3, 4, 4, 5, 6};
    std::vector<int> vec2(10);
    /*std::copy: Copy range of elements
    Copies the elements in the range [first,last) into the range beginning at result.
    The function returns an iterator to the end of the destination range 
    (which points to the element following the last element copied).
    The ranges shall not overlap in such a way that result points to an element in the range [first,last).
    */
    std::cout << "Vec = ";
    std::for_each(vec.begin(), vec.end(), print);
    std::cout << std::endl;
    std::cout << "Vec2 = ";
    std::for_each(vec2.begin(), vec2.end(), print);
    std::cout << std::endl;

    std::copy(vec.begin(), vec.end(), vec2.begin());
    std::cout << "After using std::copy, Vec2 = ";
    std::for_each(vec2.begin(), vec2.end(), print);
    std::cout << std::endl;

    /*std::unique: Remove consecutive duplicates in range.
    Removes all but the first element from every consecutive group of equivalent elements in the range [first,last).*/
    auto p = std::unique(vec.begin(), vec.end());
    vec.erase(p, vec.end()); // erase an element start at position p to position vec.end() which means we erase everything left behind from original vec.
    std::cout << "Vec2 after using std::unique and vec2.erase is: ";
    std::for_each(vec.begin(), vec.end(), print);
    std::cout << std::endl;
    std::cout << "Position of p in vec after using std::unique is: " << p - vec.begin() << std::endl;

    /*std::remove: Transforms the range [first,last) into a range with all the elements that compare equal to val removed, 
    and returns an iterator to the new end of that range.*/
    auto q = std::remove(vec.begin(), vec.end(), 3);
    vec.erase(q, vec.end());
    std::cout << "Vec after using std::remove and vec.erase is: ";
    std::for_each(vec.begin(), vec.end(), print);
    std::cout << std::endl;

    /*std::fill: Assigns val to all the elements in the range [first,last). */
    std::fill(vec.begin(), vec.end(), 3);
    std::cout << "Vec after using std::fill with 3 is: ";
    std::for_each(vec.begin(), vec.end(), print);
    std::cout << std::endl;

    /*std::swap_ranges: Exchange values of two ranges
    Exchanges the values of each of the elements in the range [first1,last1) 
    with those of their respective elements in the range beginning at first2.*/
    std::swap_ranges(vec.begin(), vec.end(), vec2.begin());
    std::cout << "Vec after using std::swap_ranges is: ";
    std::for_each(vec.begin(), vec.end(), print);
    std::cout << std::endl;
}