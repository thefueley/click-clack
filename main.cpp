#include <iostream>
#include <stdexcept>
#include "machine.h"
#include "machinestates.h"

int main()
{
    Machine m;

    char input;
    do
    {
        m.printMenu();
        std::cin >> input;

        switch(input)
        {
            case 'a' :
            case 'A' :
                m.anteUp(1);
                break;
            case 'r' :
            case 'R' :
                //m.printMenu();
                m.rollDice();
                break;
        }
        m.clearInput();
    } while (input != 'q' && input != 'Q');

    return 0;
}
