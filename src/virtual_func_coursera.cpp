#include <cmath>
#include <iostream>

template <class T>
class duo
{
protected:
    T first, second;

public:
    duo() : first(0.0), second(0.0) {}
    duo(T x, T y) : first(x), second(y) {}
    void set_first(T d) { first = d; }
    void set_second(T d) { second = d; }
    T get_first() { return first; }
    T get_second() { return second; }
};

class point : public duo<double>
{
public:
    point() : duo() {}
    point(double x, double y = 0.0) : duo<double>(x, y) {}
    virtual double length() { return sqrt(first * first + second * second); } // virtual function
};

class point3d final: public point // final = no further inheritance
{
private:
    double z;

public:
    point3d() : point(), z(0.0) {}
    double length() { return sqrt(first * first + second * second + z * z); } // overidden the virtual function in point class
    void set_z(double d) { z = d; }
};

int main()
{
    point q;
    q.set_first(3.0);
    q.set_second(4.0);
    std::cout << q.get_first() << "," << q.get_second() << std::endl;
    std::cout << q.length() << std::endl;

    point3d q3;
    q3.set_first(3.0);
    q3.set_second(4.0);
    q3.set_z(5.0);
    std::cout << q3.length() << std::endl;
    return 0;
}