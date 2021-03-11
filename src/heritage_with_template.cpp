#include <vector>
#include <iostream>

// A normal class
class StackInt : public std::vector<int>
{
public:
    void stack_up(int v)
    {
        this->push_back(v);
    }
};

// Class using template
template <typename T>
class StackHP : public std::vector<T>
{
public:
    void stack_up(T v)
    {
        this->push_back(v);
    }
};

// Class using template but cannot use any attributes or method outside of inherited class
template <typename T>
class StackHPP : std::vector<T>
{
public:
    void stack_up(T v)
    {
        this->push_back(v);
    }
};

// Instant a class object inside a class
template <typename T>
class StackC
{
    std::vector<T> data;

public:
    void statck_up(T v)
    {
        data.push_back(v);
    }

    std::vector<T> get_vector()
    {
        return data;
    }
};

// print function to print out the vector except for StackHPP
template <typename T>
void print_vector(std::vector<T> const &input_vec)
{
    for (auto const &i : input_vec)
        std::cout << i << " ";
}

int main()
{
    // every method works
    StackInt s1;
    s1.stack_up(5);
    s1.stack_up(10);
    print_vector<int>(s1);
    std::cout << std::endl;

    StackHP<int> s2;
    s2.stack_up(6);
    s2.stack_up(12);
    print_vector<int>(s2);
    std::cout << std::endl;

    StackHPP<int> s3;
    s3.stack_up(7);
    s3.stack_up(14);
    // print_vector<int>(s3); //cant do this because the object is hidden (private)
    // std::cout << std::endl;

    StackC<int> s4;
    s4.statck_up(8);
    s4.statck_up(16);
    print_vector<int>(s4.get_vector());
    std::cout << std::endl;
}