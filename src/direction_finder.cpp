#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> solve(std::string direction, int x, int y, int width, int height)
{
    int dx = 0, dy = 0;
    for (auto i = 0; i < direction.size(); i++)
    {
        if (direction[i] == 'U')
            // y-=1;
            dy--;
        if (direction[i] == 'R')
            // x+=1;
            dx++;
        if (direction[i] == 'D')
            // y+=1;
            dy++;
        if (direction[i] == 'L')
            // x-=1;
            dx++;
    }
    x += dx;
    y += dy;

    return std::vector<int>({x, y});
}

int main()
{
    std::string direction = "RD";
    std::vector<int> coor = solve(direction, 0, 0, 4, 4);
    for (int i = 0; i < 2; i++)
    {
        std::cout << coor[i] << std::endl;
    }
}