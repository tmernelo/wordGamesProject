#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "User.h"
#include "LinkedList.h"

int getMenuChoice();
void setupUser(User& player);
LinkedList* loadLeaderboard();
void runMenu(User& player, LinkedList* leaderLL);
void saveResults(LinkedList* leaderLL, const User& player);
void playHangman(User* player);
void playWordle(User* player);

#endif