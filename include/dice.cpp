#include "dice.h"
#include <random>
#include <iostream>

std::uniform_int_distribution<int> dist(1, 7); //random distribution between 1 and 7
std::default_random_engine gen;                //random generator

dice::dice()
{
    std::cout << "Dice is constructed! " << std::endl;
}

dice_normal::dice_normal()
{
    std::cout << "Dice normal is constructed! " << std::endl;
}

int dice_normal::roll()
{
    set_face(dist(gen));
    return get_face();
}

int dice_pipe::roll()
{
    set_face(_value);
    return get_face();
}

dice::~dice()
{
    std::cout << "Dice is destroyed! " << std::endl;
}

dice_normal::~dice_normal()
{
    std::cout << "Dice normal is destroyed! " << std::endl;
}

dice_pipe::~dice_pipe()
{
    std::cout << "Dice pipe is destroyed! " << std::endl;
}