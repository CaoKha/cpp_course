#ifndef __PILE__
#define __PILE__

#include "to_string.h"
#include <string>
#include <vector>
#include <stdexcept>

class debordement
{
    int indice;

public:
    debordement(int v) : indice(v) {}
    std::string message() { return "the last used indice is " + demo::to_string(indice); }
};

class indice_trop_petit : public debordement
{
public:
    indice_trop_petit(int v) : debordement(v) {}
};

class indice_trop_grand : public debordement
{
public:
    indice_trop_grand(int v) : debordement(v) {}
};

template <typename Type, int length>
class Pile
{
    Type tab[length];
    int indice;
    std::vector<Type> datas{length - 1};

public:
    Pile() : indice(0) {}
    void empile(Type v)
    {
        datas.at(indice) = v;
        if (indice >= length)
            throw indice_trop_grand(length - 1);
        tab[indice++] = v;
    }
    Type depile()
    {
        if (indice <= 0)
            throw indice_trop_petit(indice);
        return tab[indice--];
    }
};

#endif