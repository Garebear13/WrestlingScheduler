#ifndef _SCHEDULE_H
#define _SCHEDULE_H

#include <string>
#include <vector>
#include "Team.h"
#include "Meet.h"

class schedule {

    public:

        schedule(std::vector<team> teams);
        schedule(std::vector<team> teams, int weeks);

        void createSchedule();

        void setNumOfWeeks(int in);
        int getNumOfWeeks() const;

        void scheduleToFile(schedule* s);


    private:
        std::vector<team> teams;

        int numOfWeeks;

        std::vector<std::vector<meet>> meets;
        

};

#endif