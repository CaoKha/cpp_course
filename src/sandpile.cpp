#include <iostream>
#include <vector>
#include <stdexcept>

std::vector<std::vector<int>> sandpile(std::vector<std::vector<int>> pile, int n)
{
    int c = (pile.size() - 1) / 2;
    pile[c][c] += 1;
    if (pile[c][c] == 4)
    {
        pile[c][c] -= 4;
        if (pile.size() > 1)
        {
            pile[c][c + 1] += 1;
            pile[c][c - 1] += 1;
            pile[c + 1][c] += 1;
            pile[c - 1][c] += 1;
        }
        for (int k = 1; k < n; k++)
        {
            for (int i = 0; i < pile.size(); i++)
                for (int j = 0; j < pile.size(); j++)
                {
                    if (pile[i][j] >= 4)
                    {
                        pile[i][j] -= 4;
                        if (j + 1 < pile.size())
                            pile[i][j + 1] += 1;
                        if (j - 1 >= 0)
                            pile[i][j - 1] += 1;
                        if (i + 1 < pile.size())
                            pile[i + 1][j] += 1;
                        if (i - 1 >= 0)
                            pile[i - 1][j] += 1;
                    }
                }
        }
    }
    return pile;
}

int main()
{
    std::vector<std::vector<int>> pile{
        std::vector<int>{0, 0, 3, 0, 0},
        std::vector<int>{0, 0, 3, 0, 0},
        std::vector<int>{3, 3, 3, 3, 3},
        std::vector<int>{0, 0, 3, 0, 0},
        std::vector<int>{0, 0, 3, 0, 0}};
    auto res = sandpile(pile, 5);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res.size(); j++)
            std::cout << res[i][j] << " ";
        std::cout << std::endl;
    }
}