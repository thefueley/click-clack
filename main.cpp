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
    std::cout << "local human address: " << &me << std::endl;
    std::cout << "local comp address: " << &comp << std::endl;

    Game crapshoot(me, comp);
    std::cout << "crapshoot address: " << &crapshoot << std::endl;
    Player &meme = crapshoot.getPlayer("human");
    std::cout << "local human address: " << &meme << std::endl;

    char mymove;
    do
    {   std::cout << "You may A) ante\tQ) quit\n";
        std::cin >> mymove;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.clear();

        switch(mymove)
        {
            case 'A' :
            case 'a' :
                crapshoot.ante(meme);
                break;
            case 'Q' :
            case 'q' :
                crapshoot.showScore();
                break;
        }
    } while (mymove != 'q' && mymove != 'Q');
    return 0;
}
