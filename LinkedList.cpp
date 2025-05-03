#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr), listSize(0) {}

LinkedList::LinkedList(const std::string& word) {
    head = new Node(word);
    tail = head;
    listSize = 1;
}

//destructor
LinkedList::~LinkedList() { clear();   }

//setters
void LinkedList::setSize(int newSize){listSize = newSize; }

void LinkedList::setTail(Node* newTail){tail = newTail;   }

void LinkedList::setHead(Node* newHead){head = newHead;   }

//getters
Node* LinkedList::getTail() const {return tail;   }

Node* LinkedList::getHead() const {return head;   }

int LinkedList::size() const {return listSize;  }

//remove LL
void LinkedList::clear() {
    Node* current = head;
    
    while (current) {
        Node* nextNode = (*current).getNext();
        delete current;
        current = nextNode;
    }
    head = tail = nullptr;
    listSize = 0;
}

void LinkedList::alphaInsert(const string& word) {
    Node* addNode = new Node(word);
    Node* current = head;

    while (current && word > (*current).getWord()) {
        current = (*current).getNext();
    }

    if (current == nullptr) {
        if (!head) {
            head = addNode;
            tail = addNode;
        } else {
            (*tail).setNext(addNode);
            (*addNode).setPrev(tail);
            tail = addNode;
        }
        
    } else {
        if (current == head) {
            (*addNode).setNext(head);
            (*head).setPrev(addNode);
            head = addNode;
        } else {
            Node* prevNode = (*current).getPrev();
            (*addNode).setNext(current);
            (*addNode).setPrev(prevNode);
            (*prevNode).setNext(addNode);
            (*current).setPrev(addNode);
        }
    }

    listSize++;
}
   
   
bool LinkedList::checkDupe(const string& word) {
      Node* current = (*this).head;
      
      while (current) {
           if((*current).getWord() == word) {
               return true;
            }
         current = (*current).getNext();
         
      }
      return false;
      
}

   
