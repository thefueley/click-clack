#include "Player.h"
#include <iostream>
#include <string>

Player::Player(std::string nm) : player_name(nm), player_cash(10) {}

Player::Player(std::string nm, int dollars) :player_name(nm), player_cash(dollars) {}

// copy ctor
Player::Player(const Player& other) : player_name(other.player_name), player_cash(other.player_cash)
{
    //std::cout << "Player copy constructor was called" << std::endl;
}

// copy-assignment ctor
Player& Player::operator=(const Player& rhs)
{
    //std::cout << "Player copy-assignment constructor was called" << std::endl;
    player_name = rhs.player_name;
    player_cash = rhs.player_cash;
    return *this;
}

// take money from player
void Player::removePlayerCash(int diff)
{
    player_cash -= diff;
}

// print Player object
std::ostream& operator<<(std::ostream& out, const Player& s)
{
    out << "Player:\t" << s.player_name << " "
        << "\t" << "Cash:\t" << s.player_cash << "\n";
    return out;
}
