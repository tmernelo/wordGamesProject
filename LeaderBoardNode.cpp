#include "LeaderBoardNode.h"
#include "User.h"

LeaderBoardNode::LeaderBoardNode(const User& player): player(player), next(nullptr){}

User LeaderBoardNode::getUser() const{
    return player;
}

LeaderBoardNode* LeaderBoardNode::getNext() const{
    return next;
}

void LeaderBoardNode::setUser(const User& newPlayer){
    player = newPlayer;
}
void LeaderBoardNode::setNext(LeaderBoardNode* newNode){
    next = newNode;
}
