#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
class gen
{
public:
    gen(double x_zero, double increment) : x(x_zero), incr(increment) {}
    double operator()()
    {
        x += incr;
        return x * x;
    }

private:
    double x, incr;
};

double integrate(gen g, int n) // integrate on(0,1)
{
    std::vector<double> fx(n);
    std::generate(fx.begin(), fx.end(), g);
    return std::accumulate(fx.begin(), fx.end(), 0.0) / n;
}

int main()
{
    const int n = 10000;
    gen g(0.0,1.0/n);
    std::cout << "integration program x**2 from 0 to 1: " << std::endl;
    std::cout << integrate(g,n) << std::endl;
}