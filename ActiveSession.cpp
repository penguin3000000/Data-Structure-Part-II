#include <iostream>
#include "ActiveSession.hpp"

using namespace std;

ActiveSession::ActiveSession() {
    currentCount = 0;
    for (int i = 0; i < MAX_CAPACITY; i++) {
        sessionArray[i] = nullptr;
    }
}

bool ActiveSession::isFull() {
    return currentCount >= MAX_CAPACITY;
}

void ActiveSession::joinSession(Learner* newLearner) {
    if (isFull()) {
        cout << "Session is currently full! " << newLearner->name << " must wait in the queue.\n";
        return;
    }

    for (int i = 0; i < MAX_CAPACITY; i++) {
        if (sessionArray[i] == nullptr) {
            sessionArray[i] = newLearner;
            currentCount++;
            cout << newLearner->name << " has successfully joined the active session.\n";
            return;
        }
    }
}

void ActiveSession::exitSession(string id) {
    for (int i = 0; i < MAX_CAPACITY; i++) {
        if (sessionArray[i] != nullptr && sessionArray[i]->studentID == id) {
            cout << sessionArray[i]->name << " has exited the session. Space freed up!\n";
            delete sessionArray[i];
            sessionArray[i] = nullptr;
            currentCount--;
            return;
        }
    }
    cout << "Learner with ID " << id << " not found in the active session.\n";
}

void ActiveSession::displayActiveSession() {
    if (currentCount == 0) {
        cout << "The active session is currently empty.\n";
        return;
    }
    cout << "\n--- Active Session List (" << currentCount << "/" << MAX_CAPACITY << ") ---\n";
    for (int i = 0; i < MAX_CAPACITY; i++) {
        if (sessionArray[i] != nullptr) {
            cout << "- " << sessionArray[i]->name << " (ID: " << sessionArray[i]->studentID << ")\n";
        }
    }
    cout << "--------------------------------\n";
}