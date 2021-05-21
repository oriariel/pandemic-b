#include "OperationsExpert.hpp"

using namespace std;
using namespace pandemic;

	Player& OperationsExpert::build(){
	bool flag=false;
        if(board.is_resStations(this->city)==flag){
        	board.add_resStation(this->city);
        	}
        	return *this;
    }
    string OperationsExpert::role(){
    return "OperationsExpert";
    }
    
