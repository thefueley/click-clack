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
    diceroll[0] = 0;
    diceroll[1] = 1;
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
    std::cout << "You may A) ante\tQ) quit\n";
}

void Game::pointMsg() const
{
    std::cout << "POINT: " << marker << std::endl;
    std::cout << "You may A) ante\tR) roll\n";
}

void Game::rollMsg() const
{
    std::cout << "POINT: " << marker << std::endl;
    std::cout << "You may R) roll\n";
}

void Game::rollDice()
{
    int min = 1;
    int max = 6;
    //the random device that will seed the generator
    std::random_device seeder;
    //then make a mersenne twister engine
    std::mt19937 engine(seeder());
    //then the easy part... the distribution
    std::uniform_int_distribution<int> dist(min, max);
    //then just generate the integer like this:
    int compGuess = dist(engine);

    diceroll[0] = compGuess;

    compGuess = dist(engine);
    diceroll[1] = compGuess;
}

void Game::computeOutcome(std::string phase)
{
    int result = diceroll[0] + diceroll[1];
    if (phase == "comeout")
    {
        switch(result)
        {
            case 2 :
            players[1].player_cash += 2;
            std::cout << "You rolled 2!\nYou lose!\n";
            winner = false;
            break;
            case 3 :
            players[1].player_cash += 2;
            std::cout << "You rolled 3!\nYou lose!\n";
            winner = false;
            break;
            case 4 :
            players[1].player_cash += 2;
            std::cout << "You rolled 4!\n";
            marker = result;
            winner = false;
            break;
            case 5 :
            players[1].player_cash += 2;
            std::cout << "You rolled 5!\n";
            marker = result;
            winner = false;
            break;
            case 6 :
            players[1].player_cash += 2;
            std::cout << "You rolled 6!\n";
            marker = result;
            winner = false;
            break;
            case 7 :
            players[0].player_cash += 2;
            std::cout << "You rolled 7!\nYou win!\n";
            winner = true;
            break;
            case 8 :
            players[1].player_cash += 2;
            std::cout << "You rolled 8!\n";
            marker = result;
            winner = false;
            break;
            case 9 :
            players[1].player_cash += 2;
            std::cout << "You rolled 9!\n";
            marker = result;
            winner = false;
            break;
            case 10 :
            players[1].player_cash += 2;
            std::cout << "You rolled 10!\n";
            marker = result;
            winner = false;
            break;
            case 11 :
            players[0].player_cash += 2;
            std::cout << "You rolled 11!\nYou win!\n";
            winner = true;
            break;
            case 12 :
            players[1].player_cash += 2;
            std::cout << "You rolled 12!\nYou lose!\n";
            winner = false;
            break;
        }
    }
    else if (phase == "point")
    {
        if (result == 7)
        {
            std::cout << "You rolled 7!\nCraps!" << std::endl;
            players[1].player_cash += 2;
            winner = false;
        }
        else if (result == marker)
        {
            std::cout << "You rolled " << result << "!\nYou win!" << std::endl;
            players[0].player_cash += 2;
            winner = true;
        }
        else
        {
            std::cout << "You rolled " << result << "!\nKeep going!" << std::endl;
            winner = false;
        }
    }
}

bool Game::isWinner()
{
    return winner;
}

void Game::clearInput()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
}
