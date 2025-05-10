#ifndef LEADERBOARD_H 
#define LEADERBOARD_H
#include "User.h"

class LeaderBoardNode{
    private: 
        User player;
        LeaderBoardNode* next;
    public: 
        LeaderBoardNode(const User& player);
        User getUser() const;
        LeaderBoardNode* getNext() const;

        void setUser(const User& newPlayer);
        void setNext(LeaderBoardNode* newNode);
};

#endif
