#include "..\\include\\Team.h"
#include <iostream>

bool team::hasPlayed(team opponent) const {
    
    bool played = false;
    
    for(int i = 0; i < this->teamsPlayed.size(); i++) {
        if(this->teamsPlayed[i] == opponent) {
            played = true;
        }
    }
    
    return played;
    
}

void team::setTown(std::string in) {
    
    this->town = in;
    
}
void team::setSeed(int in) {
    
    this->seed = in;
    
}

void team::meet(team team1, team team2) {
    
    team1.teamsPlayed.push_back(team2);
    team2.teamsPlayed.push_back(team1);
    
}

void team::meet(team team1, team team2, team team3) {
    
    team1.teamsPlayed.push_back(team2);
    team1.teamsPlayed.push_back(team3);

    team2.teamsPlayed.push_back(team1);
    team2.teamsPlayed.push_back(team3);
    
    team3.teamsPlayed.push_back(team1);
    team3.teamsPlayed.push_back(team2);
    
}

void team::printTeam() const {
    
    std::cout << this->getTown() << " " << this->getSeed() << std::endl;
    std::cout << "Teams Played: " << std::endl;
    for(int i = 0; i < this->teamsPlayed.size(); i++) {
        std::cout << '\t' << this->teamsPlayed[i].town << " " << this->teamsPlayed[i].seed << std::endl;
    }
    
}

bool operator == (const team &team1, const team &team2) {
    
    bool equal = false;
    
    if(team1.getTown() == team2.getTown() && team1.getSeed() == team2.getSeed()) {
        equal = true;
    }
    
    return equal;
    
}