#ifndef LEARNER_HPP
#define LEARNER_HPP

#include <string>

struct Learner {
    std::string studentID;
    std::string name;
    Learner* next = nullptr;
};

#endif