#include "machinestates.h"
#include <iostream>

AbstractState::~AbstractState() {
}

void AbstractState::setState(Machine& machine, AbstractState* state) {
    AbstractState* aux = machine.mState;
    machine.mState = state;
    delete aux;
}

void AbstractState::updateBank(Machine& machine, int bank, int quantity)
{
    machine.mBanks[bank] += quantity;
}

void AbstractState::setPoint(Machine& machine, int point)
{
    machine.mPoint = point;
}

int AbstractState::getPoint(Machine& machine)
{
    return machine.mPoint;
}

Ante::~Ante() {
    std::cout << "Exiting Ante State" << std::endl;
}

void Ante::anteUp(Machine& machine, int quantity) {
    std::cout << "anteUp in Ante State; Normal." << std::endl;
    updateBank(machine, 0, -1);
    updateBank(machine, 1, -1);
    setState(machine, new ComeOut());
}

void Ante::rollDice(Machine& machine)
{
    std::cout << "rollDice from Ante. Illegal." << std::endl;
}

ComeOut::~ComeOut() {
    std::cout << "Exiting ComeOut State" << std::endl;
}

void ComeOut::anteUp(Machine& machine, int quantity) {
    std::cout << "anteUp in ComeOut State; No Effect." << std::endl;
}

void ComeOut::rollDice(Machine& machine)
{
    int roll = 5;
    switch(roll)
    {
        case 2 :
        case 3 :
        case 12 :
        std::cout << "Craps!" << std::endl;
        break;
        case 7 :
        case 11 :
        std::cout << "Winner!" << std::endl;
        setState(machine, new Ante());
        case 4 :
        case 5 :
        case 6 :
        case 8 :
        case 9 :
        case 10 :
        std::cout << "Point: " << roll << std::endl;
        setPoint(machine, roll);
        setState(machine, new Point());
        break;
    }
}

Point::~Point() {
    std::cout << "Exiting Point State" << std::endl;
}

void Point::anteUp(Machine& machine, int quantity) {
    std::cout << "anteUp in Point State; No Effect." << std::endl;
}

void Point::rollDice(Machine& machine)
{
    int roll = 5;
    if (roll == getPoint(machine))
    {
        std::cout << "Rolled your point!\n";
        updateBank(machine, 0, 2);
        setState(machine, new Ante());
    }
    else if (roll == 7)
    {
        std::cout << "Craps!" << std::endl;
        updateBank(machine, 1, 2);
        setState(machine, new Ante());
    }
    else
    {
        std::cout << "Rolled: " << roll << std::endl;
    }
}
