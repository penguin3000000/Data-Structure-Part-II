#ifndef REGISTRATIONQUEUE_HPP
#define REGISTRATIONQUEUE_HPP

#include <string>
#include "Learner.hpp"

class RegistrationQueue {
private:
    Learner* front;
    Learner* rear;

public:
    RegistrationQueue();
    void registerLearner(std::string id, std::string name);
    Learner* popNextLearner();
    void displayQueue();
    bool isEmpty();
};

#endif