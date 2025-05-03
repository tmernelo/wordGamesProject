#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <random>
#include <cctype>
#include "User.h"

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


int main() {
    // ADDED: Create a User and ask for their name
    User player;
    string name;
    WordGame* hangman = new Hangman();
    WordGame* wordle = new Wordle();

    cout << "Welcome! Please enter your name: ";
    cin >> name;
    player.setName(name);

    
    int userInput;

    do {

        userInput = getMenuChoice();

        switch(userInput) {
            case QUIT:
                cout << "Thank you! Bye!" << endl;
                break;
            case LEADERBOARD:
                cout << "Leaderboard: " << endl;
                break;
            case HANGMAN:
                cout << "HangMan!!" << endl;
                hangman->run();
                delete hangman;
                break;
            case WORDLE:
                cout << "Wordle!!" << endl;
                break;
        }

    } while (userInput != QUIT);

     // ADDED: Show the player's final score on exit
    cout << "Final score for " << player.getName() << ": " << player.getScore() << " win(s)." << endl;

    return 0;
}
