#ifndef GAME_H
#define GAME_H

#include <vector>
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/custom_reaction.hpp>
#include <boost/statechart/transition.hpp>
#include <boost/mpl/list.hpp>
#include "Player.h"
#include <iostream>


// Events
struct EvMoneyUp : boost::statechart::event< EvMoneyUp > {};
struct EvRoll2 : boost::statechart::event< EvRoll2 > {};
struct EvRoll3 : boost::statechart::event< EvRoll3 > {};
struct EvRoll4 : boost::statechart::event< EvRoll4 > {};
struct EvRoll5 : boost::statechart::event< EvRoll5 > {};
struct EvRoll6 : boost::statechart::event< EvRoll6 > {};
struct EvRoll7 : boost::statechart::event< EvRoll7 > {};
struct EvRoll8 : boost::statechart::event< EvRoll8 > {};
struct EvRoll9 : boost::statechart::event< EvRoll9 > {};
struct EvRoll10 : boost::statechart::event< EvRoll10 > {};
struct EvRoll11 : boost::statechart::event< EvRoll11 > {};
struct EvRoll12 : boost::statechart::event< EvRoll12 > {};
struct EvRollPoint : boost::statechart::event< EvRollPoint > {};

// States
struct ST_Ante;
struct ST_Comeout;
struct ST_Point;

// State Machine
struct SM_Craps : boost::statechart::state_machine< SM_Craps, ST_Ante >
{
};

// States
struct ST_Ante : boost::statechart::simple_state< ST_Ante, SM_Craps >
{
    //ST_Ante() { std::cout << "Entered ST_Ante state\n"; }
    //~ST_Ante() { std::cout << "Exited ST_Ante state\n"; }

    typedef boost::statechart::custom_reaction< EvMoneyUp > reactions;

    boost::statechart::result react(const EvMoneyUp &)
    {
        std::cout << "Transit to ST_Comeout!\n";
        return transit< ST_Comeout >();
    }
};

struct ST_Comeout : boost::statechart::simple_state< ST_Comeout, SM_Craps >
{
    //ST_Comeout() { std::cout << "Entered ST_Comeout state\n"; }
    //~ST_Comeout() { std::cout << "Exited ST_Comeout state\n"; }
    typedef boost::mpl::list<
    boost::statechart::custom_reaction< EvRoll2 >,
    boost::statechart::custom_reaction< EvRoll3 >,
    boost::statechart::custom_reaction< EvRoll4 >,
    boost::statechart::custom_reaction< EvRoll5 >,
    boost::statechart::custom_reaction< EvRoll6 >,
    boost::statechart::custom_reaction< EvRoll7 >,
    boost::statechart::custom_reaction< EvRoll8 >,
    boost::statechart::custom_reaction< EvRoll9 >,
    boost::statechart::custom_reaction< EvRoll10 >,
    boost::statechart::custom_reaction< EvRoll11 >,
    boost::statechart::custom_reaction< EvRoll12 >,
    boost::statechart::custom_reaction< EvRollPoint >
    > reactions;

    boost::statechart::result react(const EvRoll2 &)
    {
        std::cout << "You rolled a 2, Transit to ST_Ante!\n";
        return transit< ST_Ante >();
    }

    boost::statechart::result react(const EvRoll3 &)
    {
        std::cout << "You rolled a 3, Transit to ST_Ante!\n";
        return transit< ST_Ante >();
    }

    boost::statechart::result react(const EvRoll4 &)
    {
        std::cout << "You rolled a 4, Transit to ST_Point!\n";
        return transit< ST_Point >();
    }

    boost::statechart::result react(const EvRoll5 &)
    {
        std::cout << "You rolled a 5, Transit to ST_Point!\n";
        return transit< ST_Point >();
    }

    boost::statechart::result react(const EvRoll6 &)
    {
        std::cout << "You rolled a 7, Transit to ST_Ante!\n";
        return transit< ST_Ante >();
    }

    boost::statechart::result react(const EvRoll7 &)
    {
        std::cout << "You rolled a 7, Transit to ST_Ante!\n";
        return transit< ST_Ante >();
    }

    boost::statechart::result react(const EvRoll8 &)
    {
        std::cout << "You rolled a 8, Transit to ST_Point!\n";
        return transit< ST_Point >();
    }

    boost::statechart::result react(const EvRoll9 &)
    {
        std::cout << "You rolled a 9, Transit to ST_Point!\n";
        return transit< ST_Point >();
    }

    boost::statechart::result react(const EvRoll10 &)
    {
        std::cout << "You rolled a 10, Transit to ST_Point!\n";
        return transit< ST_Point >();
    }

    boost::statechart::result react(const EvRoll11 &)
    {
        std::cout << "You rolled a 11, Transit to ST_Ante!\n";
        return transit< ST_Ante >();
    }

    boost::statechart::result react(const EvRoll12 &)
    {
        std::cout << "You rolled a 12, Transit to ST_Ante!\n";
        return transit< ST_Ante >();
    }

    boost::statechart::result react(const EvRollPoint &)
    {
        std::cout << "You rolled your point, Transit to ST_Ante!\n";
        return transit< ST_Ante >();
    }
};

struct ST_Point : boost::statechart::simple_state< ST_Point, SM_Craps >
{
    //ST_Point() { std::cout << "Entered ST_Point state\n"; }
    //~ST_Point() { std::cout << "Exited ST_Point state\n"; }
    typedef boost::mpl::list<
    boost::statechart::custom_reaction< EvRoll2 >,
    boost::statechart::custom_reaction< EvRoll3 >,
    boost::statechart::custom_reaction< EvRoll4 >,
    boost::statechart::custom_reaction< EvRoll5 >,
    boost::statechart::custom_reaction< EvRoll6 >,
    boost::statechart::custom_reaction< EvRoll7 >,
    boost::statechart::custom_reaction< EvRoll8 >,
    boost::statechart::custom_reaction< EvRoll9 >,
    boost::statechart::custom_reaction< EvRoll10 >,
    boost::statechart::custom_reaction< EvRoll11 >,
    boost::statechart::custom_reaction< EvRoll12 >,
    boost::statechart::custom_reaction< EvRollPoint >
    > reactions;

    boost::statechart::result react(const EvRoll2 &)
    {
        std::cout << "You rolled a 2, keep going!\n";
        return transit< ST_Point >();
    }

    boost::statechart::result react(const EvRoll3 &)
    {
        std::cout << "You rolled a 3, keep going!\n";
        return transit< ST_Point >();
    }

    boost::statechart::result react(const EvRoll4 &)
    {
        std::cout << "You rolled a 4, keep going!\n";
        return transit< ST_Point >();
    }

    boost::statechart::result react(const EvRoll5 &)
    {
        std::cout << "You rolled a 5, keep going!\n";
        return transit< ST_Point >();
    }

    boost::statechart::result react(const EvRoll6 &)
    {
        std::cout << "You rolled a 6, keep going!\n";
        return transit< ST_Point >();
    }

    boost::statechart::result react(const EvRoll7 &)
    {
        std::cout << "You rolled a 7, Craps! Transition to ST_Ante!\n";
        return transit< ST_Ante >();
    }

    boost::statechart::result react(const EvRoll8 &)
    {
        std::cout << "You rolled a 8, keep going!\n";
        return transit< ST_Point >();
    }

    boost::statechart::result react(const EvRoll9 &)
    {
        std::cout << "You rolled a 9, keep going!\n";
        return transit< ST_Point >();
    }

    boost::statechart::result react(const EvRoll10 &)
    {
        std::cout << "You rolled a 10, keep going!\n";
        return transit< ST_Point >();
    }

    boost::statechart::result react(const EvRoll11 &)
    {
        std::cout << "You rolled a 11, keep going!\n";
        return transit< ST_Point >();
    }

    boost::statechart::result react(const EvRoll12 &)
    {
        std::cout << "You rolled a 12, keep going!\n";
        return transit< ST_Point >();
    }

    boost::statechart::result react(const EvRollPoint &)
    {
        std::cout << "You rolled your point, Transit to ST_Ante!\n";
        return transit< ST_Ante >();
    }
};

class Game
{
public:
        Game();
        Game(Player&, Player&);

        void ante();
        void showScore() const;

        void anteMsg() const;
        void rollMsg() const;
        void pointSetMsg() const;

        void rollDice();
        void computeOutcome();

        void clearInput();

private:
        std::vector<Player> players;
        std::pair<int, int> diceroll;
        int marker;
        int bank;
        SM_Craps CrapsFSM;
};

#endif // GAME_H
