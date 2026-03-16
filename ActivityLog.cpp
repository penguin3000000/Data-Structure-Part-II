#include <iostream>
#include "ActivityLog.hpp"

using namespace std;

ActivityLog::ActivityLog() {
    nextIndex = 0;
    currentCount = 0;
}

void ActivityLog::addActivity(const string& learnerID, const string& activityName, int score, const string& difficulty) {
    log[nextIndex].learnerID = learnerID;
    log[nextIndex].activityName = activityName;
    log[nextIndex].score = score;
    log[nextIndex].difficulty = difficulty;

    nextIndex = (nextIndex + 1) % MAX_LOG;
    if (currentCount < MAX_LOG) currentCount++;
}

void ActivityLog::displayAll() {
    cout << "\n--- Recent Activity Log (" << currentCount << "/" << MAX_LOG << ") ---\n";

    int start = (currentCount < MAX_LOG) ? 0 : nextIndex;

    for (int i = 0; i < currentCount; i++) {
        int idx = (start + i) % MAX_LOG;
        cout << i + 1 << ". " << log[idx].learnerID << " | " << log[idx].activityName
            << " | Score: " << log[idx].score << " | Difficulty: " << log[idx].difficulty << "\n";
    }
    cout << "--------------------------------\n";
}

void ActivityLog::displayByLearner(const string& learnerID) {
    cout << "\n--- Activity Log for [" << learnerID << "] ---\n";
    bool found = false;

    int start = (currentCount < MAX_LOG) ? 0 : nextIndex;

    for (int i = 0; i < currentCount; i++) {
        int idx = (start + i) % MAX_LOG;

        if (log[idx].learnerID == learnerID) {
            cout << "- " << log[idx].activityName
                << " | Score: " << log[idx].score
                << " | Difficulty: " << log[idx].difficulty << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No records found for this Learner ID.\n";
    }
    cout << "--------------------------------\n";
}

int ActivityLog::getCount() const {
    return currentCount;
}

Activity* ActivityLog::getLogArray() {
    return log;
}