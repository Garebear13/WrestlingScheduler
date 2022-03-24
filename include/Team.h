#ifndef _TEAM_H
#define _TEAM_H

#include <string>
#include <vector>

class team {

    public:
        bool hasPlayed(team opponent) const;

        std::string getTown() const;
        void setTown(std::string in);

        int getSeed() const;
        void setSeed(int in);
        
        void meet(team team1, team team2);
        void meet(team team1, team team2, team team3);

        void printTeam() const;

    
    private:
        std::string town;   //Plymouth

        int seed;   //1-n

        //bool homeYear;      //home or away(y/n)

        std::vector<team> teamsPlayed;   //vector of teams played

};

bool operator == (const team &team1, const team &team2);

#endif