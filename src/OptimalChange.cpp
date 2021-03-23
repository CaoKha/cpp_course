#include <cmath>
#include <iostream>

// Do not modify the Change​​​​​​‌​​‌​​​‌​​​​​‌‌‌​​‌​‌​​‌​ structure
typedef struct
{
    long coin2;
    long bill5;
    long bill10;
} Change;

class Answer
{
public:
    static bool optimalChange(long s, Change &c)
    {
        c.coin2 = 0;
        c.bill5 = 0;
        c.bill10 = 0;

        long even_or_odd = s % 2;

        if (even_or_odd != 0) // odd
        {
            if (s >= 5) { // case >== 5, odd
                s -= 5; // make it even
                c.bill5 = 1;
                c.bill10 = s / 10;
                c.coin2 = (s - c.bill10*10) / 2;
                return true;
            }
            else return false;// case < 5, odd
        }
        else if ( even_or_odd == 0 && s != 0 ) //even 
        {
            c.bill10 = s / 10;
            c.coin2 = (s-c.bill10*10) / 2;
            return true;
        }
        return false; // s = 0
    }
};

int main()
{
    // Answer ans;
    // Change c;
    // std::cout << "possible? : " << std::boolalpha << ans.optimalChange(103, c) << std::endl;
    // std::cout << "bill10 = " << c.bill10 << std::endl;
    // std::cout << "bill5 = " << c.bill5 << std::endl;
    // std::cout << "coin2 = " << c.coin2 << std::endl;
    Change c;
    long s = 33; // Change this value to test other cases
    bool found = Answer::optimalChange(s, c);

    std::cout << "Coin(s)  2 : " << c.coin2 << std::endl;
    std::cout << "Bill(s)  5 : " << c.bill5 << std::endl;
    std::cout << "Bill(s) 10 : " << c.bill10 << std::endl;

    long result = c.coin2 * 2 + c.bill5 * 5 + c.bill10 * 10;
    std::cout << "changeable? : "<<std::boolalpha << found << std::endl;
    std::cout << std::endl
              << "Change given = " << result << std::endl;
}

// #include <cmath>

// using namespace std;

// // Do not modify the Change​​​​​​‌​​‌​​​‌​​​‌​​​‌‌​​​‌‌‌‌‌ structure
// typedef struct {
//     long coin2;
//     long bill5;
//     long bill10;
// } Change;

// class Answer
// {
// public:
//     static bool optimalChange(long s, Change &c)
//     {
//         c.coin2 = 0;
//         c.bill5 = 0;
//         c.bill10 = 0;

//         c.bill10 = s / 10;
//         int mod10 = s % 10;
//         if (mod10 != 0)
//         {
//             c.bill5 = mod10 / 5;
//             int mod5 = mod10 % 5;
//             if (mod5 != 0)
//             {
//                 int test = mod10 / 2;
//                 // int test1 = mod5 / 2;
//                 // c.coin2 = mod5 / 2;
//                 int test1 = mod5 % 2;
//                 int test2 = mod10 % 2;
//                 if (test2 != 0 && test1 != 0)
//                     return false;
//                 if (test2 == 0 && test1 != 0) { c.coin2 = test; c.bill5 = 0;}
//                 if (test2 != 0 && test1 == 0) { c.coin2 = mod5/2;}
//                 else return false;

//             }
//         }

//         return true;
//     }
// };