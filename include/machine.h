#ifndef MACHINE_H
#define MACHINE_H
#include "machinestates.h"
#include <tuple>

class AbstractState;

class Machine {
friend class AbstractState;
public:
    Machine();
    ~Machine();
    void anteUp(int quantity);
    void rollDice();

private:
    int mBanks[2];
    int mPoint;
    AbstractState* mState;
};

#endif // MACHINE_H
