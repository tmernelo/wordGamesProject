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
bool LinkedList::loadWords(const string filename){
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

string LinkedList::getRandomWord() const {

   // Generate a random number within the range [min, max]
   srand(time(0));
   int randomNumber =  (rand() % (size()));
   Node* current = getHead();
   for (int i = 0; i < randomNumber; i++){
      current = current->getNext();
   }
   return current->getWord();
}
   

void LinkedList::insertPlayer(const User& newPlayer){
   // Check if there is an existing player with the same name
   Node* current = head;
   Node* previous = nullptr;

   while(current != nullptr){
       // if there is, replace the lower score with the higher score
       if(current -> getUser().getName() == newPlayer.getName()){
           if(newPlayer.getScore() > current -> getUser().getScore()){
               current -> setUser(newPlayer);
           }
           return;
       }
       previous = current;
       current = current -> getNext();
   }

   // insert the user in the correct order
   Node* newNode = new Node(newPlayer);
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
   if(listSize >= 5){
       Node* temp = head; 
       for(int i = 1; i < 5; i++){
           temp = temp -> getNext();
       }
       Node* nodeToDelete = temp -> getNext(); 
       temp -> setNext(nullptr);
       delete nodeToDelete;
       listSize--;
   }else{
      listSize++;
   }
}

void LinkedList::displayTopFive() const{
   cout << "=== Leaderboard ===" << endl;
   Node* current = head;
   int rank = 1; 
   while(current && rank <= 5){
       int currentScore = current -> getUser().getScore();
       cout << rank << ". " << current -> getUser().getName() << " - " << currentScore << endl;
       current = current -> getNext(); 
       ++rank; 
   }
}

void LinkedList::loadFromFile(const string& filename){
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

void LinkedList::saveToFile(const string& filename) const{
   ofstream outFS(filename);
   if(!outFS){
       cout << "Cannot open file to write" << endl;
       return;
   }
   Node* current = head;
   while(current){
       outFS << current -> getUser().getName() << " " << current -> getUser().getScore() << endl;
       current = current -> getNext();
   }
   outFS.close();
}
