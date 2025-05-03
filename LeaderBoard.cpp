#include "LeaderBoard.h"
#include <algorithm>
#include <iostream>
using namespace std;

void LeaderBoard::addPlayer(const User& player) {
    topPlayers.push_back(player);
    sort(topPlayers.begin(), topPlayers.end(), [](const User& a, const User& b) {
        return a.getScore() > b.getScore();
    });
}

void LeaderBoard::showTopPlayers() const {
    cout << "=== Leaderboard ===" << endl;
    for (const auto& player : topPlayers) {
        cout << player.getName() << " - " << player.getScore() << " win(s)" << endl;
    }
}
