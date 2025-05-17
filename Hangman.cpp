#include "Hangman.h"
#include "LinkedList.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <random>
#include <cctype>
using namespace std;

Hangman::Hangman(User* u) : WordGame(u) {
    wordBank.loadWords("hangman_words.txt");
    asciiVector.push_back(" +---+\n |   |\n     |\n     |\n     |\n     |\n=========\n");
    asciiVector.push_back(" +---+\n |   |\n O   |\n     |\n     |\n     |\n=========\n");
    asciiVector.push_back(" +---+\n |   |\n O   |\n |   |\n     |\n     |\n=========\n");
    asciiVector.push_back(" +---+\n |   |\n O   |\n/|   |\n     |\n     |\n=========\n");
    asciiVector.push_back(" +---+\n |   |\n O   |\n/|\\  |\n     |\n     |\n=========\n");
    asciiVector.push_back(" +---+\n |   |\n O   |\n/|\\  |\n/    |\n     |\n=========\n");
    asciiVector.push_back(" +---+\n |   |\n O   |\n/|\\  |\n/ \\  |\n     |\n=========\n");
}


void Hangman::drawHangman(int misses) {
    if (misses <= asciiVector.size()){ cout << asciiVector.at(misses); }
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

bool containsLetter(vector<char>& guessed, char letter){
    for (int i = 0; i < guessed.size(); i++) {
        if (guessed.at(i) == letter) {
            return true;
        }
    }
    return false;
}

char askUserInput(vector<char>& attemptList) {
    char userGuess;
    while (true){
        cout << "give me a letter: " << endl;    
        cin >> userGuess;
    
        if (!isalpha(userGuess)) {
            cout << "input must be a letter!" << endl;
            continue;
        } else if (containsLetter(attemptList, userGuess)){
            cout << "You've already guessed that letter! Try again..." << endl;
            continue;
        } else {
            attemptList.push_back(userGuess);
        }
        break;
    }

    return userGuess;

}

void Hangman::play() {
    LinkedList * leaderboardLL = new LinkedList();
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

    int misses = 0;
    int correct = 0;
    int tries = 7;
    int tracker = count_if(answerWord.begin(), answerWord.end(), ::isalpha);

    cout << "\n=== HANGMAN START ===\n" << endl;
    while (misses < 7) {
        char guess = askUserInput(attemptList);

        int result = checkLetter(answerWord, displayWord, guess);

        if (result == 0) {
            tries--;
            misses++;
            if (misses == 7){
                misses--; // Did this to allow hangman to print one more time
                drawHangman(misses);
                cout << "Game Over! Word was: " << randomWord << endl;
                return;
            }
            cout << "Wrong! Tries left: " << tries << endl;
            drawHangman(misses);
        } else {
            tracker -= result;
            correct++;
            cout << "Correct! " << tracker << " letters left." << endl;
            
        }

        for (int i = 0; i < displayWord.size(); i++) {
            cout << displayWord.at(i) << ' ';
        }
        cout << endl;
        
        if (tracker == 0) {
            cout << "You WIN!" << endl;
            //float tempScore = static_cast<float> (correct)/(correct+misses); 
            player->addWin();
            // leaderboardLL -> insertUser(*player);
            return;
        }
    }
}
