#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Player.h"

class Game
{
    public:
        Game() = default;
        Game(Player&, Player&);

        void ante();
        void showScore() const;
        Player& getPlayer(std::string);

        void comeoutMsg() const;
        void pointMsg() const;
        void comeoutRollMsg() const;
        void rollMsg() const;
        void rollDice();
        void computeOutcome(std::string);
        bool isWinner();
        bool beginNewGame() const;

        void clearInput();

    private:
        std::vector<Player> players;
        int diceroll[2];
        int marker;
        bool winner;
        bool newGame;
};
#endif // GAME_H
