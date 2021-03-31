#include <iostream>
#include <cassert>
#include <fstream>
#include <vector>

enum class suit : short
{
    SPADE,
    HEART,
    DIAMOND,
    CLUB
};

inline std::ostream &operator<<(std::ostream &out, const suit &s)
{
    switch (s)
    {
    case suit::SPADE:
        out << "SPADE";
        break;
    case suit::HEART:
        out << "HEART";
        break;
    case suit::DIAMOND:
        out << "DIAMOND";
        break;
    case suit::CLUB:
        out << "CLUB";
    }
    return out;
}

class pips
{
private:
    int v;

public:
    pips(int val) : v(val) { assert(v > 0 && v < 14); } // Jack = 11, Queen = 12, King = 13
    friend std::ostream &operator<<(std::ostream &out, const pips &p);
    int get_pips() { return v; }
};

std::ostream &operator<<(std::ostream &out, const pips &p)
{
    out << p.v;
    return out;
}

class card
{
private:
    suit s;
    pips v;

public:
    card() : s(suit::SPADE), v(1) {}
    card(suit s, pips v) : s(s), v(v) {}
    friend std::ostream &operator<<(std::ostream &out, const card &c);
    suit get_suit() { return s; }
    pips get_pips() { return v; }
};

std::ostream &operator<<(std::ostream &out, const card &c)
{
    out << c.v << c.s; 
    return out;
}

void init_deck(std::vector<card> &d){
    for(int i=1; i<14;++i)
    {
        card c(suit::SPADE, i);
        d[i-1] = c;
    }
}

int main() {

}