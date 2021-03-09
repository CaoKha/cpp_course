#include <iostream>

template <typename T>
class Predicat
{
    T threshold;

public:
    Predicat(T value) : threshold(value) {}
    bool operator()(T value) { return value > threshold; }
};

template <typename F, typename T>
bool find_if(F func, T b)
{
    return func(b);
}

int main()
{
    int thresh = 6;
    int test_num = 10;
    Predicat<int> function(thresh);
    bool result = find_if<Predicat<int>, int>(function(thresh), test_num);
    std::cout << "threshold is: " << thresh << std::endl;
    std::cout << "test_number is: " << test_num << std::endl;
    std::cout << test_num << " > " << thresh << "?: " << std::boolalpha << result << std::endl;
}