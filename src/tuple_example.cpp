#include <iostream>
#include <tuple>

class threeD
{
    std::tuple<double, double, double> p;

public:
    threeD(){ p = std::make_tuple(0,0,0);}
    threeD(double x, double y, double z) { p = std::make_tuple(x,y,z);}
    friend std::ostream& operator<<(std::ostream& out, threeD& d)
    {
        out << "(" << std::get<0>(d.p) << "," << std::get<1>(d.p) << "," << std::get<2>(d.p) << ")";
        return out;
    }
};

int main()
{
    threeD p1, p2(1.2,2.3,3.4);
    std::cout << "Test tuple" << std::endl;
    std::cout << "p1 is " << p1 << std::endl;
    std::cout << "p2 is " << p2 << std::endl;
    return 0;
}