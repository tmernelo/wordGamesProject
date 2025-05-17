#include <iostream>
#include <iomanip>
#include <string>
#include "GameManager.h"
#include "Hangman.h"
#include "Wordle.h"
#include "LinkedList.h"
using namespace std;

enum Actions {QUIT, HANGMAN, WORDLE, LEADERBOARD};

int getMenuChoice() {
    int userInput;

    cout << setw(44) << setfill('=') << "" <<  endl;
    cout << "              ~~WORD GAMES~~              " << endl;
    cout << setw(44) << setfill('=') << "" <<  endl;
    cout << "Options menu:" << endl;
    cout << "(" << HANGMAN << ") Play Hangman! " <<  endl;
    cout << "(" << WORDLE  << ") Play Wordle! " <<  endl;
    cout << "(" << LEADERBOARD  << ") Show the Leaderboard" <<  endl;
    cout << "(" << QUIT  << ") Exit Game" <<  endl;

    cin >> userInput;

    if (userInput < QUIT  || userInput > LEADERBOARD) {
        cout << endl;
        cout << "Error! Input must be a number between " << QUIT << " and " << LEADERBOARD
        << ", or " << QUIT << " to exit. " << endl;
        return getMenuChoice();
    } else {
        return userInput;
    }
}

void playHangman(User* player) {
    WordGame* hangman = new Hangman(player);
    hangman->play();
    delete hangman;
}

void playWordle(User* player) {
    WordGame* wordle = new Wordle(player);
    wordle->play();
    delete wordle;
}

void setupUser(User& player) {
    string name;
    cout << "Welcome! Please enter your name: ";
    cin >> name;
    player.setName(name);
}

LinkedList* loadLeaderboard() {
    LinkedList* leaderLL = new LinkedList();
    leaderLL->loadFromFile("leaderboard.txt");
    return leaderLL;
}

void runMenu(User& player, LinkedList* leaderLL) {
    int userInput;

    do {
        userInput = getMenuChoice();

        switch(userInput) {
            case QUIT:
                cout << "Thank you! Bye!" << endl;
                break;
            case LEADERBOARD:
                leaderLL->displayTopFive();
                leaderLL->insertPlayer(player);
                break;
            case HANGMAN:
                cout << "Hangman!!" << endl;
                playHangman(&player);
                break;
            case WORDLE:
                cout << "Wordle!!" << endl;
                playWordle(&player);
                break;
            default:
                cout << "Enter correct number" << endl;
                break;
        }

    } while (userInput != QUIT);
}

void saveResults(LinkedList* leaderLL, const User& player) {
    leaderLL->saveToFile("LeaderBoard.txt");
    cout << "Final score for " << player.getName() << ": "
         << player.getScore() << " win(s)." << endl;
}