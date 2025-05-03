#ifndef WORDLE_H
#define WORDLE_H

#include "WordGame.h"

class Wordle : public WordGame {
public:
    Wordle(User* u);
    void play() override;
    bool gameOver() override;
};

#endif
