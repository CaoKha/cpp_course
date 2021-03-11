#include <iostream>
#include <type_traits>

double add_all(double *array, int n)
{
    double s{0};

    for (int i = 0; i < n; ++i)
    {

        s = s + array[i];
    }
    return s;
}

// linked list structure
struct Node
{
    Node *next;
    int data;
};

// normal sum function
int sum(Node *first, Node *last)
{
    int s = 0;
    while (first != last)
    {
        s += first->data;
        first = first->next;
    }
    return s;
}

// sum function using template
template <typename It_in, typename V, typename Op>
V template_sum(It_in first, It_in last, V s, Op operateur)
{
    // V s = 0;
    static_assert(std::is_arithmetic<V>::value, "the type is not arithmetic!");

    while (first != last)
    {
        s = operateur(s, *first);
        ++first;
    }
    return s;
}

// template for myplus operator
template <typename T>
T myplus(T a, T b)
{
    return a + b;
}

// template for general operator
template <typename T>
class myOp
{
public:
    T operator()(T a, T b)
    {
        return a + b; // replace this with operator you want
    }
};

//
class Foo
{
    int v1;
    double v2;

public:
    Foo(int n) : v1(n), v2() {}
    Foo(int n, double f) noexcept : v1(n), v2(f) {}
};

int main()
{
    std::cout << std::boolalpha << std::is_constructible<Foo>::value << std::endl;
    std::cout << std::is_nothrow_constructible<Foo, int>::value << std::endl;
    std::cout << std::is_nothrow_constructible<Foo, int, double>::value << std::endl;
    double tab[] = {2, 3, 4, 5};
    double total = add_all(tab, 4);
    std::cout << "the sum of table using add_all is: " << total << std::endl;
    // double total_v2 = template_sum<double *, double>(tab, tab + 4, 0.0);
    double total_v2 = template_sum(tab, tab + 4, 0.0, myplus<double>); // because s = (double) 0.0, template_sum assumes the type is double
    std::cout << "the sum of table using template_sum with myplus function is: " << total_v2 << std::endl;
    double total_v3 = template_sum(tab, tab + 4, 0.0, myOp<double>());
    std::cout << "the sum of table using template_sum with myOp class, operateur() is: " << total_v3 << std::endl;
    double total_v4 = template_sum(tab, tab + 4, 0.0, std::plus<double>()); // in std lib there is also plus function that we can use
    std::cout << "the sum of table using template_sum with std::plus, operator() is: " << total_v4 << std::endl;
}