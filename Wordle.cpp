#include "Wordle.h"
#include <iostream>
#include <algorithm>
using namespace std;

Wordle::Wordle(User* u) : WordGame(u) {
    wordBank.loadWordsFromFile("wordle_words.txt");
}

bool Wordle::gameOver() {
    return false;
}

void Wordle::play() {
    string target = wordBank.getRandomWord();
    transform(target.begin(), target.end(), target.begin(), ::tolower);

    int attempts = 6;
    string guess;

    cout << "\n=== WORDLE START ===\n";
    while (attempts > 0) {
        cout << "Enter a 5-letter guess (" << attempts << " tries left): ";
        cin >> guess;
        transform(guess.begin(), guess.end(), guess.begin(), ::tolower);

        if (guess.length() != 5) {
            cout << "Guess must be exactly 5 letters.\n";
            continue;
        }

        cout << "Feedback: ";
        for (int i = 0; i < 5; i++) {
            if (guess[i] == target[i]) {
                cout << (char)toupper(guess[i]); // correct position
            } else if (target.find(guess[i]) != string::npos) {
                cout << guess[i]; // wrong position
            } else {
                cout << '_'; // not in word
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