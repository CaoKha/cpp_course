#include <iostream>
#include "../include/player.h"
#include "../include/dice.h"
int main()
{
    dice *pnormal = new dice_normal;
    dice_pipe *ppipe = new dice_pipe{6};
    player fabien{"Fabien"};
    player pierre{"Pierre"};

    for (int i = 0; i < 5; ++i)
    {
        int result_of_fabien = fabien.launch(*pnormal);
        std::cout << "Fabien rolled " << result_of_fabien << std::endl;

        int result_of_pierre = pierre.launch(*ppipe);
        std::cout << "Pierre rolled " << result_of_pierre << std::endl;

        if (result_of_fabien > result_of_pierre)
        {
            std::cout << "Result: Fabien won!"
                      << std::endl;
        }
        else if (result_of_fabien < result_of_pierre)
        {
            std::cout << "Result: Pierre won!"
                      << std::endl;
        }
        else
            std::cout << "Result: Deuce!"
                      << std::endl;
    }

    delete ppipe;
    delete pnormal;
}