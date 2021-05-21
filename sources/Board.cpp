
#include "Board.hpp"
#include <map>
#include <iostream>
#include <string>
using namespace std;
namespace pandemic{

    bool Board::is_clean(){
    for(auto &it:mapofCube){
    	if(it.second > 0){
    	return false;
    }
    }
    return true;
    }
    
    int &Board::operator[](City c) {
        return mapofCube[c];
    }
    ostream& operator<<(std::ostream& out, const Board& b){
    return out;
    }
    void Board::remove_cures(){
    if(cures.empty()){ 
    	return;
  	}
  	cures.clear();
  }
 void Board::remove_station(){
 if(stations.empty()){ 
 return;
  }
  stations.clear();
  }
  bool Board::areConnected(City &a, City &b) {
  bool flag = true;
    if(connect_between_cities.at(a).count(b) == 0){
    	flag=false;
    }
    return flag;
    }
    void Board::add_resStation(City c){
    	stations.insert(c);
    }
    
    bool Board::is_resStations(City c)const{ 
    bool flag=false;
    if(stations.count(c) != 0){
    flag=true;
    }
    return flag;
    };
    
    Color Board::get_color(City c){
    return getColor.at(c);
    };
    
    bool Board::foundCure(Color c) const { 
    bool flag = true;
    if(cures.count(c) == 0){
    flag=false;
    }
    return flag;
    }
    void Board::insertCure(Color c) { 
        cures.insert(c); 
    }; 
}
    
    
    
    
    
    
    
    
     
    
