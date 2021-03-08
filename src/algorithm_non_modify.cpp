#include <iostream>
#include <vector>
#include <algorithm>

void print(int v)
{
    std::cout << v << " ";
}

bool pred(int v)
{
    return v < 10;
}

int main()
{
    std::vector<int> vec{1, 2, 2, 3, 7, 8, 9, 10};
    //std::for_each: Applies function fn to each of the elements in the range [first,last).
    std::for_each(vec.begin(), vec.end(), print);
    std::cout << std::endl;
    /*  std::all_of: Test condition on all elements in range. 
    Returns true if pred returns true for all the elements in the range [first,last) or if the range is empty, and false otherwise. */
    bool inferieur_than_10 = std::all_of(vec.begin(), vec.end(), pred);
    std::cout << std::boolalpha << inferieur_than_10 << std::endl;
    std::cout << inferieur_than_10 << std::endl;
    /*  std::count: Count appearances of value in range
    Returns the number of elements in the range [first,last) that compare equal to val.*/
    int number_of_value_4 = std::count(vec.begin(), vec.end(), 4);
    std::cout << "Number of value 4 in vec: " << number_of_value_4 << std::endl;
    /*  std::find_first_of: Find element from set in range.
    Returns an iterator to the first element in the range [first1,last1) 
    that matches any of the elements in [first2,last2). 
    If no such element is found, the function returns last1. */
    std::vector<int> vec2{1, 9, 8, 7, 2};
    auto p = std::find_first_of(vec.begin(), vec.end(), vec2.begin(), vec2.end());
    std::cout << "Result of the find_first_of: " << p - vec.begin() << ". That means there is a number in vec2 appearing in vec at position " << p - vec.begin() << std::endl;
    /* std::search:Search range for subsequence
    Searches the range [first1,last1) for the first occurrence of the sequence defined by [first2,last2), 
    and returns an iterator to its first element, or last1 if no occurrences are found.*/
    std::vector<int> vec3{3, 4, 5, 6};
    auto q = std::search(vec.begin(), vec.end(), vec3.begin(), vec3.end());
    std::cout << "Result of search: " << q - vec.begin() << ". That means the sequence of vec3 is found at position " << q - vec.begin() << " of the vec. If the posistion is at the end of vec, the result is not found. " << std::endl;
}