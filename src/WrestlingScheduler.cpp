#include <iostream>
#include <vector>

#include "Team.h"
#include "Schedule.h"
#include "Team.h"

using namespace std;

int main() {

    //Get num of teams
    int numTeams;
    cout << "Enter number of teams: ";
    cin >> numTeams;

    team teams[numTeams];

    for(int i = 0; i < numTeams; i++) {
        cout << "Enter team " << i + 1 << " town: ";

        string town;
        cin >> town;
        teams[i].setTown(town);
        teams[i].setSeed(i + 1);
        
    }

    for(int i = 0; i < numTeams; i++) {
        teams[i].printTeamInfo();
    }

    return 0;
}