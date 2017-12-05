#include <string>
#include <iostream>
#include <vector>
#include <limits>
#include <random>
#include "Game.h"

// random number stuff
const int min = 1;
const int max = 6;
//the random device that will seed the generator
std::random_device seeder;
//then make a mersenne twister engine
std::mt19937 engine(seeder());
//then the easy part... the distribution
std::uniform_int_distribution<int> dist(min, max);

Game::Game()
{
    CrapsFSM.initiate();
}

Game::Game(Player &human, Player &computer)
{
    players.push_back(human);
    players.push_back(computer);
    diceroll.first = 0;
    diceroll.second = 0;
    marker = 0;
    bank = 0;
    CrapsFSM.initiate();
}

void Game::ante()
{
    players.at(0).cash -= 1;
    players.at(1).cash -= 1;
    bank += 2;
    CrapsFSM.process_event(EvMoneyUp());
}

void Game::showScore() const
{
    std::cout << "\tGAME SCORE\n";
    std::cout << "############################\n";
    for (const Player& p : players)
    {
        std::cout << p;
    }
    std::cout << "############################\n";
}

void Game::anteMsg() const
{
    showScore();
    std::cout << "You may A) ante\tQ) quit\n";
}

void Game::rollMsg() const
{
    std::cout << "POINT: NOT SET" << std::endl;
    std::cout << "R) to roll.\n";
}

void Game::pointSetMsg() const
{
    std::cout << "POINT: " << marker << std::endl;
    std::cout << "Locked in. Try to hit your point. R) to roll.\n";
}

void Game::rollDice()
{
    diceroll.first = dist(engine);
    diceroll.second = dist(engine);
}

void Game::computeOutcome()
{
    int result = diceroll.first + diceroll.second;
    if (result == marker)
        CrapsFSM.process_event(EvRollPoint());
    // Didn't hit point so process
    switch(result)
    {
        case 2 :
        {
            CrapsFSM.process_event(EvRoll2());
            break;
        }
        case 3 :
        {
            CrapsFSM.process_event(EvRoll3());
            break;
        }
        case 4 :
        {
            CrapsFSM.process_event(EvRoll4());
            break;
        }
        case 5 :
        {
            CrapsFSM.process_event(EvRoll5());
            break;
        }
        case 6 :
        {
            CrapsFSM.process_event(EvRoll6());
            break;
        }
        case 7 :
        {
            CrapsFSM.process_event(EvRoll7());
            break;
        }
        case 8 :
        {
            CrapsFSM.process_event(EvRoll8());
            break;
        }
        case 9 :
        {
            CrapsFSM.process_event(EvRoll9());
            break;
        }
        case 10 :
        {
            CrapsFSM.process_event(EvRoll10());
            break;
        }
        case 11 :
        {
            CrapsFSM.process_event(EvRoll11());
            break;
        }
        case 12 :
        {
            CrapsFSM.process_event(EvRoll12());
            break;
        }
    }
}

void Game::clearInput()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
}
