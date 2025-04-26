#include <iostream>
#include <iomanip>
using namespace std;

enum Actions {QUIT, HANGMAN, WORDLE, LEADERBOARD};


int getMenuChoice() {
    int userInput;

    cout << "~~WORD GAMES~~" << endl;
    cout << endl << setw(44) << setfill('-') << "" <<  endl;
    cout << "Options menu:" << endl;
    cout << "(" << HANGMAN << ") Play Hangman! " <<  endl;
    cout << "(" << WORDLE  << ") Play Worlde! " <<  endl;
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
                break;
            case WORDLE:
                cout << "Worlde!!" << endl;
                break;
        }

    } while (userInput != QUIT);

    return 0;
}