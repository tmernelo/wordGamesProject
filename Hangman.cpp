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
    if (!isalpha(guessed)) return -1;
    for (int i = 0; i < word.size(); i++) {
        if (word[i] == guessed) {
            toGuess[i] = guessed;
            counter++;
        }
    }
    return counter;
}

void Hangman::play() {
    string randomWord = wordBank.getRandomWord();
    vector<char> answerWord;
    vector<char> displayWord;

    for (char c : randomWord) {
        if (isspace(c)) {
            answerWord.push_back(' ');
            displayWord.push_back(' ');
        } else {
            answerWord.push_back(c);
            displayWord.push_back('_');
        }
    }

    int tries = 6;
    int tracker = count_if(answerWord.begin(), answerWord.end(), ::isalpha);
    bool game = true;

    while (game) {
        char guess;
        cout << "Guess a letter: ";
        cin >> guess;

        int result = checkLetter(answerWord, displayWord, guess);
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
