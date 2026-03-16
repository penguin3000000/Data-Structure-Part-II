#include <iostream>
#include "RiskEngine.hpp"

using namespace std;

RiskEngine::RiskEngine() {
    learnerCount = 0;
}

void RiskEngine::calculateRisk(ActivityLog& log) {
    learnerCount = 0;
    Activity* activities = log.getLogArray();
    int totalLogs = log.getCount();


    for (int i = 0; i < totalLogs; i++) {

        string id = activities[i].learnerID;
        int score = activities[i].score;

        if (id.empty()) continue;

        int idx = -1;
        for (int j = 0; j < learnerCount; j++) {
            if (riskList[j].learnerID == id) {
                idx = j;
                break;
            }
        }

        if (idx == -1) {
            idx = learnerCount++;
            riskList[idx].learnerID = id;
            riskList[idx].riskScore = 0;
        }

        if (score < 50) {
            riskList[idx].riskScore += 10;
        }
    }

    for (int i = 0; i < learnerCount; i++) {
        if (riskList[i].riskScore >= 20)
            riskList[i].recommendation = "Repeat topic / Try easier activity";
        else
            riskList[i].recommendation = "No immediate action";
    }
}

void RiskEngine::displayRiskList() {
    cout << "\n--- At-Risk Learners ---\n";
    for (int i = 0; i < learnerCount; i++) {
        cout << riskList[i].learnerID
            << " | Risk Score: " << riskList[i].riskScore
            << " | Recommendation: " << riskList[i].recommendation << "\n";
    }
    cout << "--------------------------------\n";
}