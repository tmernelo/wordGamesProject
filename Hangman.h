#ifndef HANGMAN_H
#define HANGMAN_H

#include "WordGame.h"
#include <string>
#include <vector>

class Hangman : public WordGame {
private: 
    std::vector<std::string> asciiVector;
public:
    Hangman(User* u);
    void play();

};

#endif
