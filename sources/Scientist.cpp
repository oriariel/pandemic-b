
#include "Scientist.hpp"

using namespace std;
using namespace pandemic;

Player &Scientist::discover_cure(Color c){
	if(board.foundCure(c)){
		return *this;
	}
	if(board.is_resStations(this->city)){
		int counter=0;
		for(const auto &it:cards){
			if(Board::get_color(it)==c){
			counter++;
			}
			if(counter==n){
			break;
			}
		}
	if(counter==n){
		counter = 0;
		for(auto it=cards.begin();it !=cards.end()|| counter<n;counter++){
			if(Board::get_color(*it)==c){
			it=cards.erase(it);
			}
			else{
			++it;
			}
		}
		board.insertCure(c);
		}
	else{
		throw invalid_argument{"not enough cards"};
	}
	}
	if(!board.is_resStations(this->city)){
		throw invalid_argument{"no reserach station"};
	}
	return *this;
};

    string Scientist::role(){
    	return "Scientist";
    	}

