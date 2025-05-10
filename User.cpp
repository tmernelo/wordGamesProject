#include "User.h"
using namespace std;

// Constructors + Initilization
User::User() : score(0), name("Player1") {}
User::User(std::string newName) : score(0), name(newName) {}
User::User(std::string newName,int newScore): name(newName), score(newScore){}

void User::setName(string username) {
    name = username;
}
std::string User::getName() const {
    return name;
}


void User::setScore(float newScore){
    score = newScore;
}

void User::addWin() {
    score++;
}

float User::getScore() const {
    return score;
}
