#ifndef __PLAYER__
#define __PLAYER__

#include <string>

class dice;

class player
{
    std::string _name;
    int _score;

public:
    //constructor
    player(std::string);
    //services
    int launch(dice &);
};

#endif