#include "Wordbank.h"
#include <iostream>
#include <fstream>
#include <random>

using namespace std;

Wordbank::Wordbank(){ // sets default file (5 letter words for default)
    loadWords("default.txt");
} 

Wordbank::Wordbank(const std::string& filename){ // sets custom file
    loadWords(filename);
}  

void Wordbank::loadWords(const string& file){ // loads file to LL
    ifstream inFile(file);
    string word;
    
    while (inFile >> word) {
        wordList.push_back(word);  // Assuming wordList is your LinkedList instance
    }
    inFile.close();
} 

string Wordbank::giveWord(){ // give random word to guess 
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, wordList.size()-1);
    int randomVal = distrib(gen);

    if (wordList.size() == 0 || wordList.getHead() == nullptr) {
        return "";
    }

    // traverse thru LL using randomVal
    Node* current = wordList.getHead();

    for (unsigned int i = 0; i < randomVal; i++) { 
        current = (*current).getNext(); 

    }

    return (*current).getWord();

}   
