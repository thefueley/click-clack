#include <string>
#include <iostream>
#include <vector>
#include <limits>
#include <random>
#include "Game.h"

Game::Game(Player &a, Player &b)
{
    players.push_back(a);
    players.push_back(b);
    diceroll.first = 0;
    diceroll.second = 1;
    marker = 0;
}

void Game::ante()
{
    players[0].player_cash -= 1;
    players[1].player_cash -= 1;
}

void Game::showScore() const
{
    std::cout << "\tGAME SCORE\n";
    std::cout << "############################\n";
    for (auto it = players.begin(); it != players.end(); it++)
    {
        std::cout << *it;
    }
    std::cout << "############################\n";
}

Player& Game::getPlayer(std::string player)
{
    if (player == "human")
    {
        std::cout << "players[0] address: " << &players[0] << std::endl;
        //return players[0];
        return this->players[0];
    }
    else
        return players[1];
}

void Game::comeoutMsg() const
{
    showScore();
    std::cout << "You may A) ante\tQ) quit\n";
}

void Game::pointMsg() const
{
    showScore();
    std::cout << "POINT: " << marker << std::endl;
    std::cout << "You may A) ante\tR) roll\n";
}

void Game::comeoutRollMsg() const
{
    std::cout << "POINT: NOT SET" << std::endl;
    std::cout << "R) to roll.\n";
}

void Game::rollMsg() const
{
    std::cout << "POINT: " << marker << std::endl;
    std::cout << "Locked in. Try to hit your point. R) to roll.\n";
}

void Game::rollDice()
{
    const int min = 1;
    const int max = 6;
    //the random device that will seed the generator
    std::random_device seeder;
    //then make a mersenne twister engine
    std::mt19937 engine(seeder());
    //then the easy part... the distribution
    std::uniform_int_distribution<int> dist(min, max);
    //then just generate the integer like this:
    int compGuess = dist(engine);

    diceroll.first = compGuess;

    compGuess = dist(engine);
    diceroll.second = compGuess;
}

void Game::computeOutcome(std::string ph)
{
    int result = diceroll.first + diceroll.second;
    std::string phase = ph;
    if (phase == "comeout")
    {
        switch(result)
        {
            case 2 :
            players[1].player_cash += 2;
            std::cout << "You rolled 2!\nYou lose!\n";
            newGame = true;
            break;
            case 3 :
            players[1].player_cash += 2;
            std::cout << "You rolled 3!\nYou lose!\n";
            newGame = true;
            break;
            case 4 :
            std::cout << "You rolled 4!\n";
            marker = result;
            newGame = false;
            break;
            case 5 :
            std::cout << "You rolled 5!\n";
            marker = result;
            newGame = false;
            break;
            case 6 :
            std::cout << "You rolled 6!\n";
            marker = result;
            newGame = false;
            break;
            case 7 :
            players[0].player_cash += 2;
            std::cout << "You rolled 7!\nYou win!\n";
            newGame = true;
            break;
            case 8 :
            std::cout << "You rolled 8!\n";
            marker = result;
            newGame = false;
            break;
            case 9 :
            std::cout << "You rolled 9!\n";
            marker = result;
            newGame = false;
            break;
            case 10 :
            std::cout << "You rolled 10!\n";
            marker = result;
            newGame = false;
            break;
            case 11 :
            players[0].player_cash += 2;
            std::cout << "You rolled 11!\nYou win!\n";
            newGame = true;
            break;
            case 12 :
            players[1].player_cash += 2;
            std::cout << "You rolled 12!\nYou lose!\n";
            newGame = true;
            break;
        }
    }
    else if (phase == "point")
    {
        if (result == 7)
        {
            std::cout << "You rolled 7!\nCraps!" << std::endl;
            players[1].player_cash += 2;
            newGame = true;
            phase == "comeout";
        }
        else if (result == marker)
        {
            std::cout << "You rolled " << result << "!\nYou win!" << std::endl;
            players[0].player_cash += 2;
            newGame = true;
        }
        else
        {
            std::cout << "You rolled " << result << "!\nKeep going!" << std::endl;
            newGame = false;
        }
    }
}

bool Game::beginNewGame() const
{
    return newGame;
}

void Game::clearInput()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
}
