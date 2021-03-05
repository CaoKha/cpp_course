#ifndef __PILE__
#define __PILE__

#include "to_string.h"

class debordement
{
    int indice;

public:
    debordement(int v) : indice(v) {}
    std::string message() { return "the last used indice is " + demo::to_string(indice); }
};

template <typename Type, int length>
class Pile
{
    Type tab[length];
    int indice;

public:
    Pile() : indice(0) {}
    void empile(Type v)
    {
        if (indice >= length)
            throw debordement(length - 1);
        tab[indice++] = v;
    }
    Type depile()
    {
        return tab[indice--];
    }
};

#endif