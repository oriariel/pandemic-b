
#include "Medic.hpp"
using namespace std;
using namespace pandemic;
    Player &Medic::treat(City c){
    if(board[c]==0){
    throw invalid_argument{"There is no disease"};
      if (this->city != c){
        throw invalid_argument{"Error"};
    }
	}
	board[c] = 0;
	return *this;
    }
      
    void Medic::check(){
    if(board.foundCure(Board::get_color(this->city))){
    	board[this->city]=0;
}
}
   string Medic::role(){
   return "Medic";
   };
