#include "machine.h"

Machine::Machine() :
    mState(new Ante())
{
    mBank = {
        {"KCR", 5},
        {"CPU", 5}
    };
}

Machine::~Machine() {
    delete mState;
}

void Machine::anteUp(int quantity)
{
    mState->anteUp(*this, quantity);
}

void Machine::rollDice()
{
    mState->rollDice(*this);
}

void Machine::printMenu()
{
    mState->printMenu(*this);
}

int Machine::getPoint()
{
    return mPoint;
}

int Machine::getBank(Machine& machine, std::string player)
{
    auto search =  machine.mBank.find(player);
    return search->second;
}
