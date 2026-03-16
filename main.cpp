#include <iostream>
#include <string>
#include "RegistrationQueue.hpp"
#include "ActiveSession.hpp"
#include "ActivityLog.hpp"
#include "RiskEngine.hpp"
#include "Learner.hpp"

using namespace std;

int main() {
    RegistrationQueue queue;
    ActiveSession session; 
    int choice;
    string id, name;
    ActivityLog activityLog;
    RiskEngine riskEngine;

    cout << "Initializing APU PLAPS - Task 1 Module...\n";

    while (true) {
        cout << "\n=== Learner Registration & Session Management ===\n";
        cout << "1. Register a Learner (Join Queue)\n";
        cout << "2. View Registration Queue\n";
        cout << "3. Move Next Learner to Active Session\n";
        cout << "4. View Active Session\n";
        cout << "5. Exit Learner from Session (Free up space)\n";
        cout << "6. Record Activity Attempt\n";
        cout << "7. View All Recent Activity Logs\n";
        cout << "8. View Activity Logs by Learner\n";
        cout << "9. View At-Risk Learners & Recommendations\n";
        cout << "10. Quit Prototype\n";
        cout << "Select an action (1-10): ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            choice = 0;
        }
        else {
            cin.ignore(10000, '\n');
        }

        switch (choice) {
        case 1:
            cout << "Enter Learner ID (e.g., TP012345): ";
            getline(cin, id);
            cout << "Enter Learner Name: ";
            getline(cin, name);
            queue.registerLearner(id, name);
            break;
        case 2:
            queue.displayQueue();
            break;
        case 3:
            if (session.isFull()) {
                cout << "\nAction Denied: The Active Session is currently full!\n";
            }
            else if (queue.isEmpty()) {
                cout << "\nNo learners are currently waiting in the queue.\n";
            }
            else {
                Learner* nextLearner = queue.popNextLearner();
                if (nextLearner != nullptr) {
                    session.joinSession(nextLearner);
                }
            }
            break;
        case 4:
            session.displayActiveSession();
            break;
        case 5:
            cout << "Enter the ID of the learner exiting the session: ";
            getline(cin, id);
            session.exitSession(id);
            break;
        case 6: {
            string learnerID;
            cout << "Enter Learner ID: ";
            getline(cin, learnerID); 

            if (!session.isLearnerActive(learnerID)) {
                cout << "\n[ERROR] This learner is NOT in an active session!" << endl;
                cout << "Please move the learner to active session first (Option 3)." << endl;
                break;
            }

            string activity, diff;
            int score;
            cout << "Enter Activity Name: ";
            getline(cin, activity);
            cout << "Enter Score (0-100): ";
            cin >> score;
            cin.ignore(10000, '\n');
            cout << "Enter Difficulty (Easy/Medium/Hard): ";
            getline(cin, diff);

            activityLog.addActivity(learnerID, activity, score, diff);
            cout << "\nActivity recorded successfully!" << endl;
            break;
        }
        case 7:
            activityLog.displayAll();
            break;
        case 8:
            cout << "Enter Learner ID: ";
            getline(cin, id);
            activityLog.displayByLearner(id);
            break;
        case 9:
            riskEngine.calculateRisk(activityLog);
            riskEngine.displayRiskList();
            break;
        case 10:
            cout << "Exiting PLAPS Task 1 Prototype. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice.\n";
        }
    }
}