#ifndef MACHINESTATES_H
#define MACHINESTATES_H

#include "machine.h"

class Machine;

class AbstractState {
public:
    virtual void anteUp(Machine& machine, int quantity) = 0;
    virtual void rollDice(Machine&) = 0;
    virtual ~AbstractState();

protected:
    void setState(Machine& machine, AbstractState* st);
    void updateBank(Machine& machine, int bank, int quantity);
    void setPoint(Machine& machine, int point);
    int getPoint(Machine& machine);
};

class Ante : public AbstractState {
public:
    virtual ~Ante();
    virtual void anteUp(Machine& machine, int quantity);
    virtual void rollDice(Machine&);
};

class ComeOut : public AbstractState {
public:
    virtual ~ComeOut();
    virtual void anteUp(Machine& machine, int quantity);
    virtual void rollDice(Machine&);
};

class Point : public AbstractState {
public:
    virtual ~Point();
    virtual void anteUp(Machine& machine, int quantity);
    virtual void rollDice(Machine&);
};

#endif // MACHINESTATES_H
