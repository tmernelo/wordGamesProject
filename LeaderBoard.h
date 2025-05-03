#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <vector>
#include "User.h"

class LeaderBoard {
private:
    vector<User> topPlayers;

public:
    void addPlayer(const User& player);
    void showTopPlayers() const;
};

#endif
