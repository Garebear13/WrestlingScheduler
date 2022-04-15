#include "Meet.h"

meet::meet(team team1, team team2) {
    
    this->team1 = team1;
    this->team2 = team2;
    
}

meet::meet(team team1, team team2, team team3) {
    
    this->team1 = team1;
    this->team2 = team2;
    this->team3 = team3;
    
}

team meet::getTeam1() const {
    
    return this->team1;
    
}

team meet::getTeam2() const {
    
    return this->team2;
    
}

team meet::getTeam3() const {
    
    return this->team3;
    
}