
#include "FieldDoctor.hpp"
using namespace std;
using namespace pandemic;

Player &FieldDoctor::treat(City c){
	bool flag = false;
	if (board[c] == 0){
        throw invalid_argument{"there is no disease"};
    	}
	if ((board.areConnected(this->city, c)==flag) && this->city != c){
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
    string FieldDoctor::role(){
    return "FieldDoctor";
    };
