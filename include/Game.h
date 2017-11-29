#ifndef GAME_H
#define GAME_H

#include <vector>
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/transition.hpp>
#include "Player.h"

// Events
struct EvMoneyUp : boost::statechart::event< EvMoneyUp > {};
struct EvRoll2 : boost::statechart::event< EvRoll2 > {};

// States
struct ST_Ante;
struct ST_Comeout;
struct ST_Point;

// State Machine
struct SM_Craps : boost::statechart::state_machine< SM_Craps, ST_Ante >
{
    //
};

// States
struct ST_Ante : boost::statechart::simple_state< ST_Ante, SM_Craps >
{
    ST_Ante() { std::cout << "Entered ST_Ante state\n"; }
    ~ST_Ante() { std::cout << "Exited ST_Ante state\n"; }
};

struct ST_Comeout : boost::statechart::simple_state< ST_Comeout, SM_Craps >
{
    ST_Comeout() { std::cout << "Entered ST_Comeout state\n"; }
    ~ST_Comeout() { std::cout << "Exited ST_Comeout state\n"; }
};

struct ST_Point : boost::statechart::simple_state< ST_Point, SM_Craps >
{
    ST_Point() { std::cout << "Entered ST_Point state\n"; }
    ~ST_Point() { std::cout << "Exited ST_Point state\n"; }
};

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
        bool beginNewGame() const;

        void clearInput();

private:
        std::vector<Player> players;
        std::pair<int, int> diceroll;
        int marker;
        bool newGame;
};
#endif // GAME_H
