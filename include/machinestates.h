#ifndef MACHINESTATES_H
#define MACHINESTATES_H

#include "machine.h"
#include <string>

class Machine;

class AbstractState {
public:
    virtual void anteUp(Machine& machine, int quantity) = 0;
    virtual void rollDice(Machine&) = 0;
    virtual void printMenu(Machine&) const = 0;
    virtual ~AbstractState();

protected:
    void setState(Machine& machine, AbstractState* st);
    void updateBank(Machine& machine, std::string player, int quantity);
    void setPoint(Machine& machine, int point);
    int getPoint(Machine& machine);
    int getBank(Machine& machine, std::string player);
};

class Idle : public AbstractState {
public:
    virtual ~Idle();
    virtual void anteUp(Machine& machine, int quantity);
    virtual void rollDice(Machine&);
    virtual void printMenu(Machine&) const;
};

class Ante : public AbstractState {
public:
    virtual ~Ante();
    virtual void anteUp(Machine& machine, int quantity);
    virtual void rollDice(Machine&);
    virtual void printMenu(Machine&) const;
};

class ComeOut : public AbstractState {
public:
    virtual ~ComeOut();
    virtual void anteUp(Machine& machine, int quantity);
    virtual void rollDice(Machine&);
    virtual void printMenu(Machine&) const;
};

class Point : public AbstractState {
public:
    virtual ~Point();
    virtual void anteUp(Machine& machine, int quantity);
    virtual void rollDice(Machine&);
    virtual void printMenu(Machine&) const;
};

#endif // MACHINESTATES_H
