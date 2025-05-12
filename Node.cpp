#include "Node.h"
#include "User.h"

// set node
Node::Node() : data(""), next(nullptr), prev(nullptr) {}

Node::Node(const std::string& word) : data(word), next(nullptr), prev(nullptr) {}

Node::Node(const User& player): player(player), next(nullptr){}


//getters
Node* Node::getNext() const {return next; }
Node* Node::getPrev() const {return prev; }
User Node::getUser() const{ return player;}

//setters
void Node::setNext(Node* n) {next = n; }
void Node::setPrev(Node* p) {prev = p; }
void Node::setUser(const User& newPlayer){player = newPlayer;}

std::string Node::getWord() const {return data; }

void Node::setWord(std::string d) {data = d; }
