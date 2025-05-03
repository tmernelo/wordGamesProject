#ifndef NODE_H
#define NODE_H

#include <string>

struct Node {
   private:
      std::string data;
      Node* next;
      Node* prev;
      
   public:
      Node();
      
      Node(const std::string& word);
      
      //getters
      Node* getNext() const;
      Node* getPrev() const;
      
      //setters
      void setNext(Node* n);
      void setPrev(Node* p);
      
      std::string getWord() const;
      void setWord(std::string d);

};

#endif