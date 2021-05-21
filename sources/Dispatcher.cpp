#include "Dispatcher.hpp"

using namespace std;
using namespace pandemic;
    Player &Dispatcher::fly_direct(City c){
    bool flag=true;
    if (this->city == c){
        throw invalid_argument{"You are already in this city"};
    }
    if (board.is_resStations(this->city)==flag){
        this->city = c;
    }
    else if ((bool)cards.count(c)){
        cards.erase(c);
        this->city = c;
    }
    else{
        throw invalid_argument{"The card doesnt match or there is no reseach station"};
    }
    return *this;
}
	string Dispatcher::role(){
	return "Dispatcher";
	}
