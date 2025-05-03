#include "Hangman.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <random>
#include <cctype>
using namespace std;

Hangman::Hangman(User* u) : WordGame(u) {
    wordBank.loadWords("hangman_words.txt");
    asciiVector.push_back("+---+\n|   |\n    |\n    |\n    |\n    |\n=========\n");
    asciiVector.push_back("+---+\n|   |\nO   |\n    |\n    |\n    |\n=========\n");
    asciiVector.push_back("+---+\n|   |\nO   |\n|   |\n    |\n    |\n=========\n");
    asciiVector.push_back("+---+\n|   |\nO   |\n/|   |\n    |\n    |\n=========\n");
    asciiVector.push_back("+---+\n|   |\nO   |\n/|\\  |\n    |\n    |\n=========\n");
    asciiVector.push_back("+---+\n|   |\nO   |\n/|\\  |\n/     |\n    |\n=========\n");
    asciiVector.push_back("+---+\n|   |\nO   |\n/|\\  |\n/ \\  |\n    |\n=========\n");
}


void Hangman::drawHangman(int misses) {
    cout << asciiVector.at(misses) ;
  
}

int Hangman::checkLetter(vector<char>& word, vector<char>& toGuess, char guessed) {
    int counter = 0;

    for (int i = 0; i < word.size(); i++) {

        if (word.at(i) == guessed) {
            toGuess.at(i) = guessed;
            counter++;
        }
        
    }

    return counter;
}

char askUserInput(vector<char>& attemptList) {
    char userGuess;

    cout << "give me a letter: " << endl;

    cin >> userGuess;

    if (!isalpha(userGuess)) {
        cout << "input must be a letter!" << endl;
        userGuess = askUserInput(attemptList);
    } else {
        
        for (int i = 0; i < attemptList.size(); i++) { 

            if (attemptList.at(i) == userGuess) {
                cout << "Letter already attempted! Try again.. " << endl;
                userGuess = askUserInput(attemptList);
                break;
            }
            
        }
        attemptList.push_back(userGuess);
    
    }

    return userGuess;

}

void Hangman::play() {
    string randomWord = wordBank.getRandomWord();
    vector<char> answerWord;
    vector<char> displayWord;
    vector<char> attemptList;

    for (int i = 0; i < randomWord.size(); i++) {
        if (isspace(randomWord.at(i))){
            answerWord.push_back(' ');
            displayWord.push_back(' ');
            
        } else if (isalpha(randomWord.at(i))){
            answerWord.push_back(randomWord.at(i));
            displayWord.push_back('_');
            
        }
    }

    int tries = 6;
    int tracker = count_if(answerWord.begin(), answerWord.end(), ::isalpha);
    bool game = true;
    char userGuess;

    while (game) {
        userGuess = askUserInput(attemptList);

        int result = checkLetter(answerWord, displayWord, userGuess);
        if (result == -1) {
            cout << "Invalid input." << endl;
        } else if (result == 0) {
            tries--;
            cout << "Wrong! Tries left: " << tries << endl;
            drawHangman(tries);
        } else {
            tracker -= result;
            cout << "Correct! " << tracker << " letters left." << endl;
        }

        for (char c : displayWord) cout << c << ' ';
        cout << endl;

        if (tries <= 0) {
            cout << "Game Over! Word was: " << randomWord << endl;
            game = false;
        } else if (tracker == 0) {
            cout << "You WIN!" << endl;
            player->addWin();
            game = false;
        }
    }
}
