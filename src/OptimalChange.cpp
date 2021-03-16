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

        c.bill10 = s / 10;
        int mod10 = s % 10;
        if (mod10 != 0)
        {
            c.bill5 = mod10 / 5;
            int mod5 = mod10 % 5;
            if (mod5 != 0)
            {
                c.coin2 = mod5 / 2;
                int mod2 = mod5 % 2;
                if (mod2 != 0)
                    return false;
            }
        }

        return true;
    }
};

int main()
{
    Answer ans;
    Change c;
    std::cout << "possible? : " << std::boolalpha << ans.optimalChange(103, c) << std::endl;
    std::cout << "bill10 = " << c.bill10 << std::endl;
    std::cout << "bill5 = " << c.bill5 << std::endl;
    std::cout << "coin2 = " << c.coin2 << std::endl;
}