#include <string>
#include <iostream>
#include <vector>
#include "Game.h"

Game::Game(Player &a, Player &b)
{
    players.push_back(a);
    players.push_back(b);
}

void Game::ante(Player& chump)
{
    chump.removePlayerCash(1);
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
