#ifndef ACTIVITYLOG_HPP
#define ACTIVITYLOG_HPP

#include <string>
#include "Learner.hpp"

struct Activity {
    std::string learnerID;
    std::string activityName;
    int score;
    std::string difficulty;
};

class ActivityLog {
private:
    static const int MAX_LOG = 10; 
    Activity log[MAX_LOG];
    int nextIndex;
    int currentCount;

public:
    ActivityLog();
    void addActivity(const std::string& learnerID, const std::string& activityName, int score, const std::string& difficulty);
    void displayAll();
    void displayByLearner(const std::string& learnerID);
    int getCount() const;
    Activity* getLogArray();
};

#endif#pragma once
