#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <random>
#include <cctype>
#include "User.h"

using namespace std;

enum Actions {QUIT, HANGMAN, WORDLE, LEADERBOARD};


void printWord(vector<char> print){

    // print vector
    for (int i = 0; i < print.size(); i++) {
        cout << print.at(i);       
    }
    cout << endl;
}

int checkLetter(vector<char>& word, vector<char>& toGuess, char guessed) {
    int counter = 0;
    if(!isalpha(guessed)){
        counter = -1;      
    }else{
        for (int i = 0; i < word.size(); i++) {
            if (word.at(i) == guessed) {
                toGuess.at(i) = guessed;
                counter++;
            }      
        }
    }
    return counter; // returns # of right guesses
}

void drawHangman(int attemptsLeft){
    if (attemptsLeft == 5) {
        cout << "   _____" << endl;
        cout << "  |     |" << endl;
        cout << "  |     O" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
    }
    else if (attemptsLeft == 4) {
        cout << "   _____" << endl;
        cout << "  |     |" << endl;
        cout << "  |     O" << endl;
        cout << "  |     |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
    }
    else if (attemptsLeft == 3) {
        cout << "   _____" << endl;
        cout << "  |     |" << endl;
        cout << "  |     O" << endl;
        cout << "  |    /|" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
    }
    else if (attemptsLeft == 2) {
        cout << "   _____" << endl;
        cout << "  |     |" << endl;
        cout << "  |     O" << endl;
        cout << "  |    /|\\" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
    }
    else if (attemptsLeft == 1) {
        cout << "   _____" << endl;
        cout << "  |     |" << endl;
        cout << "  |     O" << endl;
        cout << "  |    /|\\" << endl;
        cout << "  |    /" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
    }
    else if (attemptsLeft == 0) {
        cout << "   _____" << endl;
        cout << "  |     |" << endl;
        cout << "  |     O" << endl;
        cout << "  |    /|\\" << endl;
        cout << "  |    / \\" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
    }
}


///FILE COPY for experiment
// CHANGED: Added User reference parameter to update score
void playHM(User& player) {
    // word bank
    vector<string> words {"computer","science", "coding", "san francisco state", "visual studio code"};
    

    // get random word
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, words.size()-1);

    int randomVal = distrib(gen);
    string randomWord = words.at(randomVal);

    // word to guess
    cout << randomWord << endl;

    // list w/ seperate char
    vector<char> guessWord;

    for (int i = 0; i < randomWord.size(); i++) {
        if (isspace(randomWord.at(i))){
            guessWord.push_back(' ');           
        } else if (isalpha(randomWord.at(i))){
            guessWord.push_back(randomWord.at(i));          
        }
    }

    // another list that prints for the user
    vector<char> solveWord;
    for (int i = 0; i < guessWord.size(); i++) {
        if (isspace(guessWord.at(i))){
            solveWord.push_back(' ');           
        } else if (isalpha(guessWord.at(i))){
            solveWord.push_back('_');            
        }
    }
    cout << setw(44) << setfill('=') << "" <<  endl;

    // game start
    bool game = true;

    int tries = 6;

    int tracker = solveWord.size(); // how many words to solve

    int attempt = 0;

    //print
    cout << "Guess: " << endl;
    printWord(solveWord);


    do {
        char userGuess;

        cout << "give me a letter: " << endl;
        cin >> userGuess;

        // check if userGuess is valid, already attempted

        attempt = checkLetter(guessWord, solveWord, userGuess); // returns # of right guesses

        printWord(solveWord);

        if(attempt == -1){
            cout << "Input is not a letter. Try again." << endl;
        }

        else if (attempt == 0) { // wrong guess
            tries--;
            cout << "You got none :( " << endl;
            drawHangman(tries);
            cout << tries << " more tries!" << endl;
        } else { // right guess
            tracker -= attempt;
            cout << "You got " << attempt << " letter(s) right!" << endl;
            cout << tracker << " more letters to go!" << endl;
        }

        cout << setw(44) << setfill('=') << "" <<  endl;

        if (tries <= 0 ) {
            cout << "No more tries, Game Over..." << endl;
            game = false;
        } else if (tracker <= 0) {
            cout << "You WIN!!!" << endl;
            // ADDED: Increase score if player wins
            player.addWin();
            game = false;
        }

    } while (game);
}

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
                // CHANGED: Pass player to playHM to track score
                playHM(player);
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
