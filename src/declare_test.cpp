#include<iostream>

int main() {
    const int buffer_length=0;
    auto variable=6;
    decltype(variable) other_variable=8;
    std::cout << other_variable << std::endl; 
}