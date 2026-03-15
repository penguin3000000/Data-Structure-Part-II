#include <iostream>
#include "RegistrationQueue.hpp"

using namespace std;

RegistrationQueue::RegistrationQueue() {
    front = nullptr;
    rear = nullptr;
}

void RegistrationQueue::registerLearner(string id, string name) {
    Learner* newLearner = new Learner;
    newLearner->studentID = id;
    newLearner->name = name;
    newLearner->next = nullptr;

    if (isEmpty()) {
        front = newLearner;
        rear = newLearner;
    }
    else {
        rear->next = newLearner;
        rear = newLearner;
    }
    cout << name << " has successfully registered and is waiting in the queue.\n";
}

Learner* RegistrationQueue::popNextLearner() {
    if (isEmpty()) {
        cout << "The registration queue is currently empty.\n";
        return nullptr;
    }

    Learner* learnerToMove = front;
    front = front->next;

    if (front == nullptr) {
        rear = nullptr;
    }

    learnerToMove->next = nullptr;
    return learnerToMove;
}

void RegistrationQueue::displayQueue() {
    Learner* current = front;
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Current Registration Queue:\n";
    while (current != nullptr) {
        cout << "- " << current->name << " (" << current->studentID << ")\n";
        current = current->next;
    }
}

bool RegistrationQueue::isEmpty() {
    return front == nullptr;
}