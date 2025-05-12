#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>
#include <fstream>

struct LinkedList {
   private:
      Node* head;
      Node* tail;
      int listSize;
      
      void setSize(int newSize);
      void setTail(Node* newTail);
      void setHead(Node* newHead);
      
   public: 
      LinkedList();
      LinkedList(const std::string& word);
      
      ~LinkedList();
      void clear();
      
      int size() const;
      Node* getTail() const;   
      Node* getHead() const;

      void push_back(const std::string& word);
      bool loadWords(const std::string file);
      std::string getRandomWord() const;

      // leaderboard methods
      void insertPlayer(const User& newPlayer);
      void displayTopFive() const;
      void loadFromFile(const std::string& filename);
      void saveToFile(const std::string& filename) const;
};

#endif

