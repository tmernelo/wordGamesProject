#ifndef LEADERBOARDLIST_H
#define LEADERBOARDLIST_H
#include "LeaderBoardNode.h"

class LeaderBoardList{
    private:
        LeaderBoardNode* head;
        int size;
    public: 
        LeaderBoardList(); 
        ~LeaderBoardList();
        void insertPlayer(const User& newPlayer);
        void displayTopFive() const;
        void loadFromFile(const std::string& filename);
        void saveToFile(const std::string& filename) const;
        void clear();
};

#endif
