#include <iostream>
#include <cassert>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>

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

void init_deck(std::vector<card> &d)
{
    for (int i = 1; i < 14; ++i)
    {
        card c(suit::SPADE, i);
        d[i - 1] = c;
    }
    for (int i = 1; i < 14; ++i)
    {
        card c(suit::HEART, i);
        d[i + 12] = c;
    }
    for (int i = 1; i < 14; ++i)
    {
        card c(suit::DIAMOND, i);
        d[i + 25] = c;
    }
    for (int i = 1; i < 14; ++i)
    {
        card c(suit::CLUB, i);
        d[i + 38] = c;
    }
}

void print(std::vector<card> &deck)
{
    // for (auto p = deck.begin(); p != deck.end(); ++p)
    //     std::cout << *p;
    // std::cout << std::endl;

    for (auto cardval : deck)
        std::cout << cardval;
    std::cout << std::endl;
}

bool is_flush(std::vector<card> &hand)
{
    suit s = hand[0].get_suit();
    for (auto p = hand.begin() + 1; p != hand.end(); ++p)
        if (s != p->get_suit())
            return false;
    return true;
}

bool is_straight(std::vector<card> &hand)
{
    int pips_v[5], i = 0;
    for (auto p = hand.begin(); p != hand.end(); ++p)
        pips_v[i++] = (p->get_pips()).get_pips();
    std::sort(pips_v, pips_v + 5);
    if (pips_v[0] != 1) // non-Aces
        return (pips_v[0] == pips_v[1] - 1 && pips_v[1] == pips_v[2] - 1) && (pips_v[2] == pips_v[3] - 1 && pips_v[3] == pips_v[4] - 1);
    else
        return (pips_v[0] == pips_v[1] - 1 && pips_v[1] == pips_v[2] - 1) && (pips_v[2] == pips_v[3] - 1 && pips_v[3] == pips_v[4] - 1) || (pips_v[1] == 10) && (pips_v[2] == 11) && (pips_v[3] == 12) && (pips_v[4] == 13);
}

bool is_straight_flush(std::vector<card> &hand)
{
    return is_flush(hand) && is_straight(hand);
}

int main()
{
    std::vector<card> deck(52);
    srand(time(0));
    init_deck(deck);
    int how_many;
    int flush_count = 0;
    int str_count = 0;
    int str_flush_count = 0;
    std::cout << "How many shuffles? ";
    std::cin >> how_many;

    for (int loop = 0; loop < how_many; ++loop)
    {
        std::random_shuffle(deck.begin(), deck.end());
        std::vector<card> hand(5);
        int i = 0;
        for (auto p = deck.begin(); i < 5; ++p)
            hand[i++] = *p;
        if (is_flush(hand))
            flush_count++;
        if (is_straight(hand))
            str_count++;
        if (is_straight_flush(hand))
            str_flush_count++;
    }

    std::cout << "FLushes " << flush_count << " out of " << how_many << std::endl;
    std::cout << "Straights " << str_count << " out of " << how_many << std::endl;
    std::cout << "Straight Flushes " << str_flush_count << " out of " << how_many << std::endl;
}