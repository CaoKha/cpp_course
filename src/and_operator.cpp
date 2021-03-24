#include <iostream>
#include <bitset>
#include <vector>
int main(){
    std::vector<int> v(2);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    int a = 1;
    int b = 1;
    int* pa = &a;
    int* pb = &b;
    std::cout << std::bitset<4>(a & b) <<std::endl;
    std::cout << (pa==pb) << std::endl;
    std::cout << v.size() << std::endl;
    std::cout << v[2] << std::endl;
}