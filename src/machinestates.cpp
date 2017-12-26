#include "machinestates.h"
#include <iostream>
#include <limits>
#include <random>

// random number stuff
const int min = 1;
const int max = 6;
//the random device that will seed the generator
std::random_device seeder;
//then make a mersenne twister engine
static std::mt19937 engine(seeder());
//then the easy part... the distribution
static std::uniform_int_distribution<int> dist(min, max);

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

int AbstractState::getBank(Machine& machine, int bank)
{
    return machine.mBanks[bank];
}

Ante::~Ante() {}

void Ante::anteUp(Machine& machine, int quantity)
{
    updateBank(machine, 0, -1);
    updateBank(machine, 1, -1);
    setState(machine, new ComeOut());
}

void Ante::rollDice(Machine& machine)
{
    std::cout << "rollDice from Ante. Illegal." << std::endl;
}

void Ante::printMenu(Machine& machine) const
{
    std::cout << "You may A) Ante or Q) Quit" << std::endl;
}

ComeOut::~ComeOut() {}

void ComeOut::anteUp(Machine& machine, int quantity) {
    std::cout << "anteUp from ComeOut State; No Effect." << std::endl;
}

void ComeOut::rollDice(Machine& machine)
{
    int roll = dist(engine) + dist(engine);
    switch(roll)
    {
        case 2 :
        case 3 :
        case 12 :
        std::cout << "Rolled " << roll << " ... Craps!" << std::endl;
        break;
        case 7 :
        case 11 :
        std::cout << "Rolled " << roll << " ... Winner!" << std::endl;
        setState(machine, new Ante());
        break;
        case 4 :
        case 5 :
        case 6 :
        case 8 :
        case 9 :
        case 10 :
        std::cout << "Rolled " << roll << std::endl;
        setPoint(machine, roll);
        setState(machine, new Point());
        break;
    }
}

void ComeOut::printMenu(Machine& machine) const
{
    std::cout << "Ante set." << std::endl;
    std::cout << "Human: " << machine.getBank(0) << " CPU: " << machine.getBank(1) << std::endl;
    std::cout << "Point: Not Set" << std::endl;
    std::cout << "R) to roll" << std::endl;
}

Point::~Point() {}

void Point::anteUp(Machine& machine, int quantity) {
    std::cout << "anteUp in Point State; No Effect." << std::endl;
}

void Point::rollDice(Machine& machine)
{
    int roll = dist(engine) + dist(engine);
    if (roll == getPoint(machine))
    {
        std::cout << "Rolled your point!\n";
        updateBank(machine, 0, 2);
        setState(machine, new Ante());
    }
    else if (roll == 7)
    {
        std::cout << "Rolled " << roll << " ... Craps!" << std::endl;
        updateBank(machine, 1, 2);
        setState(machine, new Ante());
    }
    else
    {
        std::cout << "Rolled: " << roll << std::endl;
    }
}

void Point::printMenu(Machine& machine) const
{
    std::cout << "Point: " << machine.getPoint() << std::endl;
    std::cout << "R) to roll" << std::endl;
}
