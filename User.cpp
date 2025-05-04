#include "User.h"
using namespace std;

// Constructors + Initilization
User::User() : score(0), name("Player1") {}
User::User(std::string newName) : score(0), name(newName) {}

void User::setName(string username) {
    name = username;
}
std::string User::getName() const {
    return name;
}


void User::setScore(float score){
    score = score;
}
// void User::addWin() {
//     score++;
// }

float User::getScore() const {
    return score;
}
