#include <iostream>

class MyClass
{
private:
    int var;

public:
    MyClass() {}
    void SetVar(int var) { this->var = var; }
    ~MyClass() { std::cout << var; }
};

int main()
{
    MyClass array[5];

    for (int i = 0; i < 5; i++)
        array[i].SetVar(i);
    return 0;
}