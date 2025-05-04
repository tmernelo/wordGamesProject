#ifndef WORDGAME_H
#define WORDGAME_H
#include <string>
#include "LinkedList.h"
#include "User.h"

class WordGame {
protected:
    User* player;  // Only a pointer, not the full object
    LinkedList wordBank; 

public:
    WordGame(User* user) : player(user) {}
    virtual void play() = 0;    // At least one virtual function to make it abstract
    virtual ~WordGame() {}
};

#endif
