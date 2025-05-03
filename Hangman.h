#ifndef HANGMAN_H
#define HANGMAN_H

#include "WordGame.h"
#include <string>
#include <vector>

class Hangman : public WordGame {
private: 
    std::vector<std::string> asciiVector;
    LinkedList wordBank;
public:
    Hangman(User* u);
    void drawHangman(int misses);
    int checkLetter(std::vector<char>& word, std::vector<char>& toGuess, char guessed);

    void play();
    
};

#endif
