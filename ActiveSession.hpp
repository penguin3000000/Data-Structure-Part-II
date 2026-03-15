#ifndef ACTIVESESSION_HPP
#define ACTIVESESSION_HPP

#include <string>
#include "Learner.hpp"

class ActiveSession {
private:
    static const int MAX_CAPACITY = 5;
    Learner* sessionArray[MAX_CAPACITY];
    int currentCount;

public:
    ActiveSession();
    void joinSession(Learner* newLearner);
    void exitSession(std::string id);
    void displayActiveSession();
    bool isFull();
};

#endif