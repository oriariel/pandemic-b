#include "Researcher.hpp"

using namespace pandemic;

    Player &Researcher::discover_cure(Color c){
    const int num=5;
    int counter = 0;
    bool flag = true;
    for (const auto &it : cards){
        if (Board::get_color(it) == c){
            counter++;
        }
    }
    if (counter < num){
        throw invalid_argument{"Not enough cards"};
    }
    if (board.foundCure(c)==flag){
        return *this;
    }
    counter=0;
    for(auto it = cards.begin();it != cards.end() && counter < num ;counter++){

            if (Board::get_color(*it) == c)
            {
                it=cards.erase(it);
            }
            else{
                ++it;
            }
    }
    board.insertCure(c);
    return *this;
    };
    string Researcher::role(){
    return "Researcher";
    };
