#include <iostream>
#include <stdexcept>
#include "machine.h"
#include "machinestates.h"

int main()
{
    Machine m;

    m.anteUp(1);
    m.rollDice();
    m.rollDice();

    return 0;
}
