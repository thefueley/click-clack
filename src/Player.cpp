#include "Player.h"
#include <iostream>
#include <string>

Player::Player(std::string nm) : player_name(nm), player_cash(10) {}

Player::Player(std::string nm, int dollars) :player_name(nm), player_cash(dollars) {}

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
