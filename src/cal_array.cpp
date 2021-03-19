#include <vector>
#include <iostream>

// using namespace std;
class Answer
{
public:
    /** @return the sum of integers whose index is between n1 and n2​​​​​​‌​​‌​​​‌​​​​​‌‌‌​​‌​‌​​‌​ */
    static int calc(const std::vector<int> &array, int n1, int n2)
    {
        int sum = 0;
        for (int i = n1; i <= n2; i++)
        {
            sum += array[i];
        }
        return sum;
    }
};

int main()
{
    // std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    // Answer sum;
    // std::cout << sum.calc(vec, 0, 6) << std::endl;
    // std::cout << vec.size() << std::endl;
    // std::cout << sizeof(char) << std::endl;

    std::vector<int> array{0, 1, 2, 3, 4, 5, 3};
    std::cout << Answer::calc(array, 0, 1) << std::endl; // 1
    std::cout << Answer::calc(array, 0, 5) << std::endl; // 15
    std::cout << Answer::calc(array, 0, 0) << std::endl; // 0
    std::cout << Answer::calc(array, 0, 6) << std::endl; // 18
}