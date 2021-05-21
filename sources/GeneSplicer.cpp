
#include "GeneSplicer.hpp"
using namespace std;
using namespace pandemic;

    Player& GeneSplicer::discover_cure(Color c){
    const int number=5;
    int counter=0;
    int a = cards.size();
    bool flag = false;
    if (board.is_resStations(this->city)==flag){
    	throw invalid_argument{"The is no research station in this city"};
    	}
    if(a >= number){
     for(auto it = cards.begin(); it != cards.end() || counter<number; counter++){
           it=cards.erase(it);
            }
            board.insertCure(c);
    }
    else{
    	throw invalid_argument{"the are no cards"};
    }
    return *this;
}
    string GeneSplicer::role(){
    return "GeneSplicer";
    };
