#include "Schedule.h"
#include "Meet.h"
#include <iostream>
#include <fstream>


schedule::schedule(std::vector<team> teams) {
        
        this->teams = teams;
        this->numOfWeeks = teams.size() - 1;
        
}

schedule::schedule(std::vector<team> teams, int weeks) {

    this->teams = teams;
    this->numOfWeeks = weeks;
}

void schedule::createSchedule() {

    const int NUMTEAMS = this->teams.size();

    const int WEEKS = this->getNumOfWeeks();

    std::vector<meet> m;

    //create last week
    for(int i = 0; i < NUMTEAMS; i++) {
        if((i % 2) == 0) {
            meet temp = meet(this->teams[i], this->teams[i + 1]); //1v2, 3v4...
            
            m.push_back(temp);
        }
    }

    this->meets.push_back(m);
    m.clear();

    //create first week
    for(int i = 0; i < NUMTEAMS; i++) {
        //meet temp = meet(this->teams[i], this->teams[NUMTEAMS - i - 1]);
        //m.push_back(temp);
        


    }

    this->meets.insert(this->meets.begin(), m);
    m.clear();

    //insert subsequent weeks into the schedule, cannot push back or front

    //temporary initialization of arbitrary meets
    for(int i = 0; i < WEEKS - 2; i++) {
        
        for(int j = 0; j < NUMTEAMS / 2; j++) {
            meet temp = meet(team(), team());
            m.push_back(temp);
        }

        this->meets.insert(this->meets.begin() + 1, m);
        m.clear();
    }

    this->scheduleToFile(this);

}

void schedule::setNumOfWeeks(int in) {
    this->numOfWeeks = in;
}

int schedule::getNumOfWeeks() const {
    return this->numOfWeeks;
}

void schedule::scheduleToFile(schedule* s) {

    std::ofstream outFile;

    outFile.open("schedule.txt", std::ofstream::out | std::ofstream::trunc); //clears file before writing
    outFile.close(); //source: https://stackoverflow.com/questions/17032970/clear-data-inside-text-file-in-c 

    outFile.open("schedule.txt");

    for(int i = 0; i < s->getNumOfWeeks(); i++) {

        outFile << "Week " << i + 1 << ": " << std::endl;

        for(int j = 0; j < (int) s->meets[i].size(); j++) {

            outFile << s->meets[i][j].getTeam1().getTown() << " vs " << s->meets[i][j].getTeam2().getTown() << std::endl;

        }

        outFile << std::endl;


    }

    outFile.close();
}