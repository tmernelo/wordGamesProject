#include "LeaderBoardList.h"
#include <iostream> 
#include <fstream> 
using namespace std; 

LeaderBoardList::LeaderBoardList(): head(nullptr), size(0) {}

LeaderBoardList::~LeaderBoardList(){
    clear();
}

void LeaderBoardList::insertPlayer(const User& newPlayer){
    // Check if there is an existing player with the same name
    LeaderBoardNode* current = head;
    LeaderBoardNode* prev = nullptr;

    while(current != nullptr){
        // if there is, replace the lower score with the higher score
        if(current -> getUser().getName() == newPlayer.getName()){
            if(newPlayer.getScore() > current -> getUser().getScore()){
                current -> setUser(newPlayer);
            }
            return;
        }
        prev = current;
        current = current -> getNext();
    }

    // insert the user in the correct order
    LeaderBoardNode* newNode = new LeaderBoardNode(newPlayer);
    if(!head || newPlayer.getScore() > head -> getUser().getScore()){
        newNode -> setNext(head);
        head = newNode; 
    }else{
        current = head; 
        while(current -> getNext() && current -> getNext() -> getUser().getScore() >= newPlayer.getScore()){
            current = current -> getNext();
        }
        newNode -> setNext(current -> getNext());
        current -> setNext(newNode);
    }
    // we only want to keep the top 5 players with the highest scores
    if(size++ > 5){
        LeaderBoardNode* temp = head; 
        for(int i = 1; i < 5; i++){
            temp = temp -> getNext();
        }
        LeaderBoardNode* nodeToDelete = temp -> getNext(); 
        temp -> setNext(nullptr);
        delete nodeToDelete;
        size--;
    }
}

void LeaderBoardList::displayTopFive() const{
    cout << "=== Leaderboard ===" << endl;
    LeaderBoardNode* current = head;
    int rank = 1; 
    while(current && rank <= 5){
        int currentScore = current -> getUser().getScore() + 1;
        cout << rank << ". " << current -> getUser().getName() << " - " << currentScore << endl;
        current = current -> getNext(); 
        ++rank; 
    }
}

void LeaderBoardList::loadFromFile(const string& filename){
    ifstream file(filename);
    if(!file){
        cout << "Cannot open file to read" << endl;
        return;
    }
    clear(); 

    string name; 
    int score;
    
    while(file >> name >> score){
        User user(name, score);
        insertPlayer(user);
    }
    file.close();
}

void LeaderBoardList::saveToFile(const string& filename) const{
    ofstream outFS(filename);
    if(!outFS){
        cout << "Cannot open file to write" << endl;
        return;
    }
    LeaderBoardNode* current = head;
    while(current){
        outFS << current -> getUser().getName() << " " << current -> getUser().getScore() << endl;
        current = current -> getNext();
    }
    outFS.close();
}


void LeaderBoardList::clear(){
    while(head != nullptr){
        LeaderBoardNode* temp = head; 
        head = head -> getNext(); 
        delete temp;
    }
    size = 0;
}
