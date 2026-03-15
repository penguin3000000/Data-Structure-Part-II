#include <iostream>
#include <string>
#include "RegistrationQueue.hpp"
#include "ActiveSession.hpp"

using namespace std;

int main() {
    RegistrationQueue queue;
    ActiveSession session;
    int choice;
    string id, name;

    cout << "Initializing APU PLAPS - Task 1 Module...\n";

    while (true) {
        cout << "\n=== Learner Registration & Session Management ===\n";
        cout << "1. Register a Learner (Join Queue)\n";
        cout << "2. View Registration Queue\n";
        cout << "3. Move Next Learner to Active Session\n";
        cout << "4. View Active Session\n";
        cout << "5. Exit Learner from Session (Free up space)\n";
        cout << "6. Quit Prototype\n";
        cout << "Select an action (1-6): ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            choice = 0;
        }
        else {
            // This specifically clears the 'Enter' key press so getline works!
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
            cout << "\n";
            queue.displayQueue();
            break;
        case 3:
            if (session.isFull()) {
                cout << "\nAction Denied: The Active Session is currently full!\n";
                cout << "Someone must exit the session before moving the next learner.\n";
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
        case 6:
            cout << "Exiting PLAPS Task 1 Prototype. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Please select a number from 1 to 6.\n";
        }
    }
}