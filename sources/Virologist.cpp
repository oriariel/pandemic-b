#include "Virologist.hpp"
using namespace std;
using namespace pandemic;

	Player &Virologist::treat(City c){
	 if (this->city != c && !(bool)cards.count(c)){
            throw invalid_argument{"You dont have this card"};
        }
    	if (board[c] == 0){
        throw invalid_argument{"There is no disease"};
    	}
    	if (board.foundCure(Board::get_color(c))){
        board[c] = 0;
        cards.erase(c);
    	}
    	else{    	
   	board[c]--;
   	cards.erase(c);
   	}
    return *this;
};
	string Virologist::role(){
		return "Virologist";
	};

