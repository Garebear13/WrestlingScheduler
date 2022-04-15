#ifndef _SCHEDULE_H
#define _SCHEDULE_H

#include <string>
#include <vector>
#include "Team.h"

class schedule {

    public:
        static void createSchedule();

        void setNumOfWeeks(int in);
        int getNumOfWeeks() const;


    private:
        std::vector<team> teams;

        int numOfWeeks;
        

};

#endif