#ifndef WORDLE_H
#define WORDLE_H

#include "WordGame.h"
#include "User.h"

class Wordle : public WordGame {
    private: 
        std::vector<std::string> asciiVector;
        LinkedList wordBank;
public:
    Wordle(User* u);
    void play() override;
    bool gameOver();
};

#endif
