#include "Team.h"
#include <iostream>

team::team() {
    this->town = "EMPTY";
    this->seed = -1;
}

team::team(std::string town) {
    this->town = town;
    this->seed = 0;
}

team::team(std::string town, int seed) {
    this->town = town;
    this->seed = seed;
}

bool team::hasPlayed(team opponent) const {
    
    bool played = false;

    int numTeams = this->teamsPlayed.size();
    
    for(int i = 0; i < numTeams; i++) {
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

int team::getSeed() const {
    
    return this->seed;
    
}

std::string team::getTown() const {
    
    return this->town;
    
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

void team::printTeamInfo() const {
    
    std::cout << this->getTown() << "\tSeed: " << this->getSeed() << std::endl;
    
}

void team::printPlayedTeams() const {
    
    std::cout << "Teams Played: " << std::endl;
    for(int i = 0; i < (int) this->teamsPlayed.size(); i++) {
        std::cout << '\t' << this->teamsPlayed[i].town << "\tSeed: " << this->teamsPlayed[i].seed << std::endl;
    }
    
}

bool operator == (const team &team1, const team &team2) {
    
    bool equal = false;
    
    if(team1.getTown() == team2.getTown() && team1.getSeed() == team2.getSeed()) {
        equal = true;
    }
    
    return equal;
    
}