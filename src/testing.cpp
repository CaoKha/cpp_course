#include <iostream>
#include <string>
#include <list>
#define MAX 100;

class A
{
public:
    int value() { return 1; }
    int value() const { return 2; }
    // static void print(int a){ std::cout <<"int";}
    // static void print(float a){ std::cout <<"float";}
    // static void print(double a){ std::cout <<"double";}
    // static void print(bool a){ std::cout <<"bool";}
    A() : a(0) {}
    A(int val) : a(val) {}
    int get() { return a; }

private:
    int a;
};

class B : public virtual A
{
public:
    B() : A(1) {}
};

class C : public virtual A
{
public:
    C() : A(2) {}
};

class D : public B, public C
{
public:
    D() : B(), C() {}
};

int a()
{
    std::cout << "a";
    return 0;
}

int b()
{
    std::cout << "b";
    return 0;
}

typedef union {
    char a;
    char b;
} myUnion;
int main()
{
    // std::list<int> l(2);
    // l.push_back(1);
    // const A *a = new A();
    // int val = a->value();
    // std::cout << val << std::endl;
    // char *str = "hello";
    // std::cout << l.size() << std::endl;
    // int s = 0;
    
    // switch (s)
    // {
    // case 1:
    // std::cout << "1";
    // case 0:
    // std::cout << "0";
    // case 2:
    // std::cout << "2";
    // }
    
    // int b = 1;
    // A::print(b*0.1);

    // D d;
    // int val = d.get();
    // std::cout << val << std::endl;
    
    // if (a() | b()){
    //     std::cout << "main";
    //     return 0;
    // }

    // int a = 1;
    // int b = 1;
    // int *pa = &a;
    // int *pb = &b;
    // std::cout<< (pa == pb);
    int a = 1 ^ 11;
    std::cout << a;
    return 0;
}