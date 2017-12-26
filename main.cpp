#include <iostream>
#include <stdexcept>
#include "machine.h"
#include "machinestates.h"

int main()
{
    Machine m;

    m.printMenu();
    m.anteUp(1);

    m.printMenu();
    m.rollDice();

    m.printMenu();
    m.rollDice();

    return 0;
}
