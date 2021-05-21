#include "Player.hpp"
#include <string>

using namespace pandemic;

    Player &Player::drive(City c){
    bool flag = false;
    if(board.areConnected(this->city,c)==flag){
    	throw invalid_argument{"these two cities aren't connected"};
    	}
    if(this->city == c){
    	throw invalid_argument{"You are already in this city"};
    }
    	this->city=c;
    	check();
        return *this;
    }
    Player &Player::fly_direct(City c){
    bool flag = false;
    if(this->city == c || cards.count(c)==0){
    	throw invalid_argument{"Error"};
    }
    cards.erase(c);
    this->city = c;
    check();
    return *this;
}   
    Player &Player::fly_charter(City c){
    bool flag = false;
    if(this->city == c || cards.count(this->city) == 0){
    	throw invalid_argument{"Error"};
    	}
    cards.erase(this->city);
    this->city = c;
    check();
    return *this;
    }
    
    Player &Player::fly_shuttle(City c){
    bool flag =false;
    if (this->city == c){
            throw invalid_argument{"It is the same city"};
       }
    if (board.is_resStations(this->city)==flag || board.is_resStations(c)==flag){
            throw invalid_argument{"There is no research station in this city"};
       }
       this->city = c;
       check();
        return *this;
    }
    Player &Player::build(){
    bool flag = true;
    if (board.is_resStations(this->city)){
        return *this;
    }
    if (cards.count(this->city) !=0){
        cards.erase(this->city);
        board.add_resStation(this->city);
    }
    else{
    throw invalid_argument{"You don't have this card"};
    }
    return *this;
}
    Player &Player::discover_cure(Color c){
    const int number=5;
    bool flag=false;
    int counter=0;
    if (board.foundCure(c)){
        return *this;
    }
    if (board.is_resStations(this->city)){
    int counter = 0;
    for (const auto &it : cards){
        if (Board::get_color(it) == c){
            counter++;
        }
        if(counter==number){
        break;
        }
        }
    if (counter == number){
    	counter=0;
    for(auto it = cards.begin(); it != cards.end() || counter<number;counter++ ){
            if (Board::get_color(*it) == c){
                it=cards.erase(it);
            }
            else{
                it--;
            }
    }
    board.insertCure(c);
    }
    else{
    	throw invalid_argument{"Not enough cards"};
    	}
    }
    if (board.is_resStations(this->city)==flag){   throw invalid_argument{"There is no research station"};
    }
    return *this;
}	


    Player &Player::treat(City c){
    if (this->city != c || board[c]==0){
        throw invalid_argument{"Error"};
    }
    if (board.foundCure(Board::get_color(c))){
        board[c]=0;
    }
    else{
        board[c]--;
    }
    return *this;
}
    string Player::role(){
       return "";
    }
    Player &Player::take_card(City c){
        cards.insert(c);
    return *this;
    }
    Player &Player::remove_cards(){
    bool flag =false;
    if(cards.empty()==flag){
        cards.clear();
        }
        return *this;
    };
