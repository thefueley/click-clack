#include "Player.h"
#include <iostream>
#include <string>

Player::Player(std::string nm) : name(nm), cash(10) {}

Player::Player(std::string nm, int dollars) :name(nm), cash(dollars) {}

// take money from player
void Player::removePlayerCash(int diff)
{
    cash -= diff;
}

// print Player object
std::ostream& operator<<(std::ostream& out, const Player& s)
{
    out << "Player:\t" << s.name << " "
        << "\t" << "Cash:\t" << s.cash << "\n";
    return out;
}
