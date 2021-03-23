#include <vector>
#include <random>
#include <iostream>
#include <cmath>
#include <map>
// using namespace std;
// #define INTERVAL 1000
// do not modify this​​​​​​‌​​‌​​​‌​​​​​‌‌‌​​‌​‌​​‌​ structure
typedef struct
{
    double x;
    double y;
} Point;

class Pi
{
public:
    // approximate pi using the given points
    double approx(std::vector<Point> &pts)
    {
        int count = 0;
        int total = 0;
        double pi;
        for (int i = 0; i < pts.size(); i++)
        {
            if (pow(pts[i].x, 2) + pow(pts[i].y, 2) <= 1)
            {
                count++;
            }
            total++;
        }
        pi = double(4 * count) / total;
        return pi;
    }
};

int main()
{
    // Pi my_pi;
    // std::vector<Point> vec;

    // for (int i = 0; i < INTERVAL*INTERVAL; i++)
    // {
    //     double rand_x = double(rand() % (INTERVAL + 1)) / INTERVAL;
    //     double rand_y = double(rand() % (INTERVAL + 1)) / INTERVAL;
    //     vec.push_back({rand_x, rand_y});
    // }
    // std::cout << vec.at(0).x << std::endl;
    // std::cout << vec.size() << std::endl;
    // std::cout << my_pi.approx(vec) << std::endl;

    std::vector<Point> rands;
    for (int i = 0; i < 100000; i++)
    {
        Point p;
        p.x = rand() / (double)RAND_MAX; // 0 <= x <= 1
        p.y = rand() / (double)RAND_MAX; // 0 <= y <= 1
        rands.push_back(p);
    }

    Pi my_pi;

    std::cout << my_pi.approx(rands) << std::endl; // ~3.14
    std::cout << rands.size() << std::endl;
}