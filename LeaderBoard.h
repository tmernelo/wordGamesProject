#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <vector>
#include "Hangman.h"
#include "User.h"
#include "Wordle.h"

class LeaderBoard {
private:
    std::vector<User*> topPlayers;

public:
    void addPlayer(User* player);
    void showTopPlayers() const;
};

#endif
