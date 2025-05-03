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
      
      //getters
      int size() const;
      Node* getTail() const;   
      Node* getHead() const;
      
      void alphaInsert(const std::string& word); // inserts new word

      bool checkDupe(const std::string& word); // check dupe before alpha insert
};

#endif