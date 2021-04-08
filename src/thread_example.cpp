// -pthread flag needed for gcc4.8
#include <iostream>
#include <string>
#include <thread>

void message1() { std::cout << "Write a Message!\n"; }

int main(int argc, char **argv)
{
    std::thread foo([]() { std::cout << "Hello World!\n"; });
    std::thread thr1(message1);
    thr1.join();
    foo.join();
}
