#ifndef RISKENGINE_HPP
#define RISKENGINE_HPP

#include "ActivityLog.hpp"

struct RiskLearner {
    std::string learnerID;
    int riskScore; 
    std::string recommendation;
};

class RiskEngine {
private:
    static const int MAX_LEARNERS = 50; 
    RiskLearner riskList[MAX_LEARNERS];
    int learnerCount;

public:
    RiskEngine();
    void calculateRisk(ActivityLog& log);
    void displayRiskList();
};

#endif