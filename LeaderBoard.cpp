#include "LeaderBoard.h"
#include "User.h"
#include <algorithm>
#include <iostream>
using namespace std;

void LeaderBoard::addPlayer(User* player) {
    topPlayers.push_back(player);
    sort(topPlayers.begin(), topPlayers.end(), [](User* a, const User* b) {
        return a -> getScore() > b -> getScore();
    });
}

void LeaderBoard::showTopPlayers() const {
    cout << "=== Leaderboard ===" << endl;
    for (int i = 0; i < topPlayers.size(); ++i) {
        cout << topPlayers[i] -> getName() << " - " << topPlayers[i] -> getScore() << " win(s)" << endl;    }
}
