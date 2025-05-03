#ifndef HANGMAN_H
#define HANGMAN_H

#include "WordGame.h"

class Hangman : public WordGame {
public:
    Hangman(User* u);
    void play() override;
    bool gameOver() override;
};

#endif
