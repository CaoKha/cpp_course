#include <iostream>
#include <algorithm>
#include <string>

class Answer
{
public:
    template <typename Bidirectional>
    static bool isPalindrome(Bidirectional first, Bidirectional last)
    {
        while (true)
        {
            last--; // end of a string is null so the last character must be at [string.end()-1]
            if (first == last) // check if the two iterators are pointing at the same position
                break;
            if (*first != *last)
                return false;
            first++;
            if (first == last)
                break;
        }
        return true;
    }
};

int main()
{
    std::string string_1;
    std::cout << "Enter your string: ";
    std::cin >> string_1;
    std::for_each(string_1.begin(), string_1.end(), [](char &c) { c = ::tolower(c); });
    std::cout << std::boolalpha << Answer::isPalindrome<std::string::iterator>(string_1.begin(), string_1.end()) << std::endl;
}