#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>

struct State
{
    int pointP1;
    int pointP2;
    const struct State *next[2];
};

std::string tennis_score(std::string const &nameP1, std::string const nameP2, std::vector<std::string> const wins)
{
    int pointP1 = 0;
    int pointP2 = 0;
    std::ostringstream stream;
    std::vector<int> score_state({0, 15, 30, 40}); // 0 1 2 3 4
    for (auto it = wins.begin(); it != wins.end(); it++)
    {
        if (nameP1.compare(*it) == 0)
            pointP1++;
        else if (nameP2.compare(*it) == 0)
            pointP2++;
        if (pointP1 == 4 && pointP2 == 4)
        {
            pointP1--;
            pointP2--;
        }
    }
    if (pointP1 == 3 && pointP2 == 3)
        return std::string("DEUCE");
    else if ((pointP1 == 4 && pointP2 < 3) || (pointP1 == 5 && pointP2 ==3))
        return std::string("P1 WINS");
    else if ((pointP2 == 4 && pointP1 < 3) || (pointP2 == 5 && pointP1 ==3))
        return std::string("P2 WINS");
    else if (pointP1 == 4 && pointP2 == 3)
        return std::string("P1 ADVANTAGE");
    else if (pointP2 == 4 && pointP1 == 3)
        return std::string("P2 ADVANTAGE");
    else if ((pointP1 == pointP2) && (pointP1 < 3) && (pointP1 > 0))
    {
        stream.clear();
        stream << score_state[pointP1] <<"a";
        return std::string(stream.str());
    }
    else
    {
        stream.clear();
        stream << "P1 " << score_state[pointP1];
        stream << " - P2 " << score_state[pointP2];
        return std::string(stream.str());
    }
}

int main()
{
    std::string a = "Albert";
    std::string b = "Zac";
    std::vector<std::string> wins{a,b,b,a,a,b};
    std::string result = tennis_score(a, b, wins);
    std::cout << result << std::endl;
}