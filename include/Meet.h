#ifndef _MEET_H
#define _MEET_H

#include "Team.h"

class meet {

    public:

        meet(team team1, team team2);
        meet(team team1, team team2, team team3);

        team getTeam1() const;
        team getTeam2() const;

    private:
        team team1;
        team team2;

};

#endif