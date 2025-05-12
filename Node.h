#ifndef NODE_H
#define NODE_H
#include "User.h"

#include <string>

struct Node {
   private:
      User player;
      std::string data;
      Node* next;
      Node* prev;
      
   public:
      Node();  
      Node(const std::string& word);
      Node(const User& player);

      
      //getters
      Node* getNext() const;
      Node* getPrev() const;
      User getUser() const;
      
      //setters
      void setNext(Node* n);
      void setPrev(Node* p);
      void setUser(const User& newPlayer);

      std::string getWord() const;
      void setWord(std::string d);

};

#endif
