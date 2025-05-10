#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <random>
#include <cctype>
#include "Hangman.h"
#include "User.h"
#include "WordGame.h"
#include "LinkedList.h"
#include "Wordle.h"
#include "LeaderBoardList.h"

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

// Bundled up hangman calls to avoid initialization error in our switch statement
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



int main() {
    // ADDED: Create a User and ask for their name
    User player;
    string name;
    
    cout << "Welcome! Please enter your name: ";
    cin >> name;
    player.setName(name);
    LeaderBoardList* leaderLL = new LeaderBoardList();
    leaderLL->loadFromFile("leaderboard.txt");

    int userInput;

    do {

        userInput = getMenuChoice();

        switch(userInput) {
            case QUIT:
                cout << "Thank you! Bye!" << endl;
                break;
            case LEADERBOARD:
                leaderLL -> displayTopFive();
                leaderLL -> insertPlayer(player);
                break;
            case HANGMAN:
                cout << "Hangman!!" << endl;
                playHangman(&player); // fixed error w/ initializing at when jumping to case @runtime 
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
    leaderLL->saveToFile("LeaderBoard.txt");
     // ADDED: Show the player's final score on exit
    cout << "Final score for " << player.getName() << ": " << player.getScore() << " win(s)." << endl;

    return 0;
}
