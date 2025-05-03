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

void LinkedList::push_back(const std::string& word){
    Node* newNode = new Node(word);
    
    if (!head) {
       head = newNode; 
       tail = newNode; 
    } else {
       (*tail).setNext(newNode);
       (*newNode).setPrev(tail);
       tail = newNode;
    }
    
    listSize++;
 }
bool LinkedList::loadWords(const string& filename){
   ifstream file(filename);
   if (!file) {
      return false;
   }

   clear();
   string word;
   while (file >> word) {
      push_back(word);
   }
   file.close();
   return true;
}
   
