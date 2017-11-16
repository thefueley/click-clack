#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Player.h"

class Game
{
    public:
        Game() = default;
        Game(Player&, Player&);

        void ante(Player &);
        void showScore() const;
        Player& getPlayer(std::string);

    private:
        std::vector<Player> players;
};
#endif // GAME_H
