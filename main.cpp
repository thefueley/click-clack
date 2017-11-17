#include <iostream>
#include <string>
#include <limits>
#include "Game.h"
#include "Player.h"

int main()
{
    std::cout << "Welcome to Click-Clack, a version of street craps\n";
    std::string (human);
    std::cout << "What is your name?\n";
    std::cin >> human;
    std::cout << "Okay, " << human << ", let's get started\n";

    Player me(human, 5);
    Player comp("CPU", 5);

    Game crapshoot(me, comp);

    char mymove;
    std::string phase("comeout");
    do
    {
        if (phase == "comeout")
        {
            crapshoot.comeoutMsg();
            std::cin >> mymove;
            crapshoot.clearInput();

            switch(mymove)
            {
                case 'A' :
                case 'a' :
                    crapshoot.ante();

                    crapshoot.rollMsg();
                    std::cin >> mymove;
                    crapshoot.clearInput();
                    crapshoot.rollDice();
                    crapshoot.computeOutcome("comeout");
                    if (crapshoot.isWinner())
                        phase = "comeout";
                    else
                        phase = "point";
                    break;
                case 'Q' :
                case 'q' :
                    crapshoot.showScore();
                    break;
            }
        }
        else // phase = point
        {
            crapshoot.pointMsg();
            std::cin >> mymove;
            crapshoot.clearInput();

            switch(mymove)
            {
                case 'A' :
                case 'a' :
                    crapshoot.ante();
                    break;
                case 'R' :
                case 'r' :
                    crapshoot.rollDice();
                    crapshoot.computeOutcome("point");
                    if (crapshoot.isWinner())
                        phase = "comeout";
                    else
                        phase = "point";
                    break;
            }
        }
    } while (mymove != 'q' && mymove != 'Q');
    return 0;
}
