#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>

class Player
{
    friend std::ostream& operator<<(std::ostream&, const Player&);
public:
        friend class Game;

        Player() = default;
        Player(std::string);
        Player(std::string, int);

        void removePlayerCash(int);

private:
        std::string player_name;
        int player_cash;
};

#endif // PLAYER_H
