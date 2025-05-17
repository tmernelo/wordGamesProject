#include "GameManager.h"

int main() {
    User player;
    setupUser(player);

    LinkedList* leaderLL = loadLeaderboard();
    runMenu(player, leaderLL);
    saveResults(leaderLL, player);

    return 0;
}
