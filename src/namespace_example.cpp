#include <iostream>

using namespace std;

namespace my_namespace
{
    void my_function()
    {
        //do nothing
    }
}
int main()
{
    cout << "hello world" << endl;
    my_namespace::my_function();
}