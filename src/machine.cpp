#include "machine.h"

Machine::Machine() :
    mState(new Ante())
{
    mBanks[0] = 5;
    mBanks[1] = 5;
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
