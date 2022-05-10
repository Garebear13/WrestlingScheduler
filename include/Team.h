#ifndef _TEAM_H
#define _TEAM_H

#include <string>
#include <vector>

class team {

    public:

        team();

        team(std::string town);

        team(std::string town, int seed);

        bool hasPlayed(team opponent) const;

        std::string getTown() const;
        void setTown(std::string in);

        int getSeed() const;
        void setSeed(int in);
        
        void meet(team team1, team team2);
        void meet(team team1, team team2, team team3);

        void printTeamInfo() const;
        void printPlayedTeams() const;

    
    private:
        std::string town;   //ie Plymouth

        int seed;   //1 to n
        
        std::vector<team> teamsPlayed;   //vector of teams played

};

bool operator == (const team &team1, const team &team2);

#endif