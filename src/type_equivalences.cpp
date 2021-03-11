#include <iostream>
#include <random>

//buffer class
template <typename T>
class Buffer
{
    T *data;
    int tab_length;

public:
    Buffer(int length)
    {
        tab_length = length;
        data = new T[tab_length];
        std::cout << "A buffer is created!" << std::endl;
    }
    ~Buffer()
    {
        std::cout << "The Buffer is destroyed!" << std::endl;
    }

    void random_assign_data()
    {
        for (int i = 0; i < tab_length; i++)
        {
            data[i] = rand() % 10;
        }
    }
    void print_data()
    {
        std::cout << "[ ";
        for (int i = 0; i < tab_length; i++)
        {
            std::cout << data[i] << " ";
        }
        std::cout << "]" << std::endl;
    }
};

//another way to create buffer class with template
template <typename T, int sz>
class BufferSized
{
    T data[sz];

public:
    BufferSized(){};
};

int main()
{
    //Buffer
    Buffer<int> buf1(10);
    Buffer<int> buf2(12);
    std::cout << "buf1 = ";
    buf1.print_data();
    std::cout << "buf2 = ";
    buf2.print_data();
    buf1.random_assign_data();
    buf2.random_assign_data();
    std::cout << "buf1 after assigned = ";
    buf1.print_data();
    std::cout << "buf2 after assigned = ";
    buf2.print_data();
    buf2 = buf1;
    std::cout << "buf2 after assigned with buf1 = ";
    buf2.print_data();

    //BufferSized
    BufferSized<int, 10> bufsz1;
    BufferSized<int, 5 * 2> bufsz2;
    BufferSized<double, 5 * 2> bufsz3;
    BufferSized<int, 15> bufsz4;
    bufsz1 = bufsz2;
}