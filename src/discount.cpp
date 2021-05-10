#include <cmath>
#include <iostream>

int calculate_price(int n, int prices[], int discount)
{
    double sum = 0;
    int max = prices[0];
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (max < prices[i])
        {
            max = prices[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (count != 1)
        {
            if (prices[i] == max)
            {
                sum += (1 - (double)discount / 100) * prices[i];
                count++;
            }
            else
                sum += prices[i];
        }
        else
            sum += prices[i];
    }
    return floor(sum);
}

int main()
{
    int prices[] = {20, 10, 20, 10, 10};
    int discount = 10;
    int result = calculate_price(5, prices, discount);
    std::cout << result << std::endl;
}