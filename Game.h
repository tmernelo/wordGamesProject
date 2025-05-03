#ifndef GAME_H
#define GAME_H
#include <string>

class User;  // Forward declaration

class Game {
protected:
    User* player;  // Only a pointer, not the full object

public:
    Game(User* user) : player(user) {}
    virtual void play() = 0;    // At least one virtual function to make it abstract
};

#endif
