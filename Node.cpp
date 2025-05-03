#include "Node.h"

// set node
Node::Node() : data(""), next(nullptr), prev(nullptr) {}

Node::Node(const std::string& word) : data(word), next(nullptr), prev(nullptr) {}

//getters
Node* Node::getNext() const {return next; }
Node* Node::getPrev() const {return prev; }

//setters
void Node::setNext(Node* n) {next = n; }
void Node::setPrev(Node* p) {prev = p; }

std::string Node::getWord() const {return data; }

void Node::setWord(std::string d) {data = d; }