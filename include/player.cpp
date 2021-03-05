#include "player.h"
#include "dice.h"


player::player(std::string n): _name(n), _score(0){}

int player::launch(dice& d){
    int value = d.roll();

    _score += value;
    return value;
}