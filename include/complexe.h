#ifndef __COMPLEXE__
#define __COMPLEXE__

class complexe
{
private:
    int real;
    int imag;

public:
    void print();
    void set_real(int);
    void set_imag(int);
    complexe(int a, int b) : real(a), imag(b){};
    complexe &operator+=(const complexe &d);
    complexe &operator++();   // prefix
    complexe operator++(int); //postfix
    explicit complexe (int c) : real(c), imag(0){}; // real to complex conversion
    explicit operator int(); // to real conversion

    complexe() = delete;
    ~complexe() = default;
};

complexe operator+(const complexe &a, const complexe &b);

#endif