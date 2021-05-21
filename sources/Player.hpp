
#include "string"
#include "Board.hpp"
#include "Color.hpp"
#pragma once
using namespace std;

namespace pandemic
{
    class Player
    {
    protected:
    	Board &board;
    	City city;
        string player_role;
        
    public:
    set<City> cards;
        Player(Board &b, City c, string s) : board(b), city(c), player_role(s) {}
        virtual Player &drive(City c);
        virtual Player &fly_direct(City c);
        virtual Player &fly_charter(City c);
        virtual Player &fly_shuttle(City c);
	virtual Player &build();
        virtual Player &discover_cure(Color c);
        virtual Player &treat(City c);
	virtual string role();
	void help_fun(Color c);
	Player &remove_cards();
       Player &take_card(City c);
        virtual void check(){};
    };
}

