#include "../include/complex_template.h"

int main()
{
    Complex<int, int> c1(5, 6);
    c1.print();

    Complex<A, A> c2(A(3), A(5));
    c2.print();
    return 0;
}