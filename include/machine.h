#ifndef MACHINE_H
#define MACHINE_H
#include "machinestates.h"
#include <map>

class AbstractState;

class Machine {
friend class AbstractState;
public:
    Machine();
    ~Machine();
    void anteUp(int quantity);
    void rollDice();
    void printMenu();
    int getPoint();
    int getBank(Machine& machine, std::string);

private:
    std::map<std::string, int> mBank;
    int mPoint;
    AbstractState* mState;
};

#endif // MACHINE_H
