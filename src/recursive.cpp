#include <iostream>

int getPosition(int n) {
    int step1 = 1; 
    int step2 = -2;
    if (n == 1) return step1;
    else if (n == 2) return step2;
    else return (getPosition(n-1) - getPosition(n-2));
}

int main()
{
    std::cout << getPosition(100) << std::endl;
}