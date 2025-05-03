#include "User.h"
using namespace std;

// Constructors + Initilization
User::User() : score(0), name("Player1"), misses(0) {}
User::User(std::string newName) : score(0), name(newName), misses(0) {}

void User::setName(string username) {
    name = username;
}
std::string User::getName() const {
    return name;
}

// If you guess incorrectly
void User::miss() {
    misses++;
}
void User::addWin() {
    score++;
}

int User::getScore() const {
    return score;
}
