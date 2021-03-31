#include <iostream>
#include <vector> // vector is a template and is a random access container
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>

int main(void)
{
    // // example 1
    // std::vector<int> v(100); //allocate space
    // // iterator C style
    // for (int i = 0; i < 100; ++i)
    //     v[i] = i;

    // // iterator C++ style, safer
    // for (std::vector<int>::iterator p = v.begin(); p != v.end(); ++p)
    //     std::cout << *p << " ";
    // std::cout << std::endl;

    // // save to file
    // std::ofstream myfile("test/data.txt");
    // for (std::vector<int>::iterator p = v.begin(); p != v.end(); ++p)
    //     myfile << *p << " ";
    // myfile.close();
    // // example 2
    // std::ifstream data_file("test/data.txt");
    // std::istream_iterator<int> start(data_file), end;
    // std::vector<int> data(start, end);

    // int sum = 0;
    // for (auto it = data.begin(); it != data.end(); ++it)
    //     sum += *it;
    // std::cout << "sum = " << sum << std::endl;
    // std::cout << "average is = " << 1.0 * sum / data.size() << std::endl;

    // // example 3, for range expression
    // for (auto &element : data)
    // {
    //     element = element + 2;
    //     std::cout << element << " ";
    // }
    // std::cout << std::endl;

    // example 4, iterator with string
    std::ifstream word_file("test/word.txt");
    std::istream_iterator<std::string> start(word_file), end;
    std::vector<std::string> words(start, end);
    std::cout << "words as read\n";
    for (auto str : words)
        std::cout << str << " ";
    sort(words.begin(), words.end());
    std::cout << "\n\nwords as sorted\n";
    for (auto str : words)
        std::cout << str << " ";
    std::cout << std::endl;
}