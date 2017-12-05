#include <iostream>
#include <string>
#include <limits>
#include "Game.h"
#include "Player.h"

int main()
{
    //std::cout << "Welcome to Click-Clack, a version of street craps\n";
    //std::string human;
    //std::cout << "What is your name?\n";
    //std::cin >> human;
    //std::cout << "Okay, " << human << ", let's get started\n";

    Player me("KCR", 5);
    Player comp("CPU", 5);

    Game crapshoot(me, comp);

    crapshoot.ante();
    crapshoot.rollDice();
    crapshoot.computeOutcome();

    return 0;
}
