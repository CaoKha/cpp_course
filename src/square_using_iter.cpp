#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>

template <typename ForwardIterator>
void square(ForwardIterator first, ForwardIterator last)
{
    for (; first != last; first++)
        *first = (*first) * (*first);
}

int main() {
    std::vector<int> w({3,2,1});
    square(w.begin(),w.end());
    for (auto i:w)
    std::cout << i << "\t";
    std::cout << std::endl;
}