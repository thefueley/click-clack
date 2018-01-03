#include "machinestates.h"
#include <iostream>
#include <limits>
#include <random>

// random number stuff
const int min = 2;
const int max = 12;
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

void AbstractState::updateBank(Machine& machine, std::string player, int quantity)
{
    auto search = machine.mBank.find(player);
    search->second += quantity;
}

void AbstractState::setPoint(Machine& machine, int point)
{
    machine.mPoint = point;
}

int AbstractState::getPoint(Machine& machine)
{
    return machine.mPoint;
}

int AbstractState::getBank(Machine& machine, std::string player)
{
    auto search = machine.mBank.find(player);
    return search->second;
}

Ante::~Ante() {}

void Ante::anteUp(Machine& machine, int quantity)
{
    updateBank(machine, "KCR", -1);
    updateBank(machine, "CPU", -1);
    setState(machine, new ComeOut());
}

void Ante::rollDice(Machine& machine)
{
    std::cout << "rollDice from Ante. Illegal." << std::endl;
}

void Ante::printMenu(Machine& machine) const
{
    std::cout << "Human: " << machine.getBank(machine, "KCR") << "\tCPU: " << machine.getBank(machine, "CPU") << std::endl;
    std::cout << "You may A) Ante or Q) Quit" << std::endl;
}

ComeOut::~ComeOut() {}

void ComeOut::anteUp(Machine& machine, int quantity) {
    std::cout << "anteUp from ComeOut State; No Effect." << std::endl;
}

void ComeOut::rollDice(Machine& machine)
{
    int roll = dist(engine);
    switch(roll)
    {
        case 2 :
        case 3 :
        case 12 :
            std::cout << "Rolled " << roll << " ... Craps!" << std::endl;
            updateBank(machine, "CPU", 2);
            setState(machine, new Ante());
            break;
        case 7 :
        case 11 :
            std::cout << "Rolled " << roll << " ... Winner!" << std::endl;
            updateBank(machine, "KCR", 2);
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
    std::cout << "Ante set.\tPoint: Not Set." << std::endl;
    std::cout << "Human: " << machine.getBank(machine, "KCR") << "\tCPU: " << machine.getBank(machine, "CPU") << std::endl;
    std::cout << "R) to roll" << std::endl;
}

Point::~Point() {}

void Point::anteUp(Machine& machine, int quantity) {
    std::cout << "anteUp in Point State; No Effect." << std::endl;
}

void Point::rollDice(Machine& machine)
{
    int roll = dist(engine);
    if (roll == getPoint(machine))
    {
        std::cout << "Rolled your point!\n";
        updateBank(machine, "KCR", 2);
        setState(machine, new Ante());
    }
    else if (roll == 7)
    {
        std::cout << "Rolled " << roll << " ... Craps!" << std::endl;
        updateBank(machine, "CPU", 2);
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
