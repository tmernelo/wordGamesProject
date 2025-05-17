#include "Wordle.h"
#include "LinkedList.h"
#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

Wordle::Wordle(User* u) : WordGame(u) {
    wordBank.loadWords("wordle_words.txt");
}

bool Wordle::gameOver() {
    return false;
}

void Wordle::play() { 
    LinkedList * leaderboardLL = new LinkedList();
    string target = wordBank.getRandomWord();
    transform(target.begin(), target.end(), target.begin(), ::tolower);

    int attempts = 6;
    string guess;
    cout << GREEN << "GREEN: " << RESET << "correct place" << endl;//added
    cout << YELLOW << "YELLOW: " << RESET << "letter in wrong place" << endl;//added
    cout << RED << "RED: " << RESET << "letter is not in word" << endl << endl;//added
    cout << "\n=== WORDLE START ===\n";
    while (attempts > 0) {
        cout << "Enter a 5-letter guess (" << attempts << " tries left): ";
        cin >> guess;
        transform(guess.begin(), guess.end(), guess.begin(), ::tolower);

        bool isLetter = true;

        for(int i = 0; i < guess.length(); i++){
            if (!isalpha(guess.at(i))) {
                isLetter = false;
            }
        } 

        if(isLetter == false){
            cout << "input must be a letter!" << endl;
            continue;
        }

        if (guess.length() != 5) {
            cout << "Guess must be exactly 5 letters.\n";
            continue;
        }

        cout << "Feedback: ";
        for (int i = 0; i < 5; i++) {
            if (guess[i] == target[i]) {
                cout << GREEN << (char)toupper(guess[i]) << RESET; // correct position
            } else if (target.find(guess[i]) != string::npos) {
                cout << YELLOW << guess[i] << RESET; // wrong position
            } else {
                cout << RED << '_' << RESET; // not in word
            }
        }
        cout << endl;

        if (guess == target) {
            cout << "You guessed it! The word was: " << target << endl;
            player->addWin();
            return;
        }

        attempts--;
    }

    cout << "Out of tries. The word was: " << target << endl;
}
