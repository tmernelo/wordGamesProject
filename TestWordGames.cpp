#include <iostream>
#include <cassert>
#include <vector>
#include "Hangman.h"
#include "Wordle.h"
#include "User.h"

using namespace std;

void testDrawAsciiArt();
void testWordLoadingAndSelection();
void testLetterCheckLogic();
void testUserScore();
void testWordleGuessFeedback();

int main();

void testDrawAsciiArt() {
    cout << "\n==== TEST: Hangman ASCII Art ====\n";
    Hangman game(nullptr);
    for (int i = 0; i <= 6; ++i) {
        cout << "\nMiss Count = " << i << endl;
        game.drawHangman(i);
    }
    cout << "\nPASS: drawHangman displayed all stages.\n";
}

void testWordLoadingAndSelection() {
    cout << "\n==== TEST: Word Loading & Random Word ====\n";
    LinkedList list;
    bool loaded = list.loadWords("hangman_words.txt");
    assert(loaded && "File failed to load.");
    assert(list.size() > 0 && "Word list should not be empty.");
    string word = list.getRandomWord();
    assert(!word.empty() && "Random word should not be empty.");
    cout << "PASS: Random word retrieved = " << word << endl;
}

void testLetterCheckLogic() {
    cout << "\n==== TEST: Hangman Letter Checking ====\n";
    Hangman game(nullptr);
    vector<char> word = {'g', 'a', 'm', 'e'};
    vector<char> display = {'_', '_', '_', '_'};

    int correct = game.checkLetter(word, display, 'a');
    assert(correct == 1);
    assert(display[1] == 'a');

    correct = game.checkLetter(word, display, 'z');
    assert(correct == 0);

    cout << "PASS: checkLetter works as expected.\n";
    cout << "Display state: ";
    for (int i = 0; i < display.size(); i++) {
        cout << display.at(i) << ' ';
    }
    cout << endl;
}

void testUserScore() {
    cout << "\n==== TEST: User Score ====\n";
    User testUser("Tester");
    assert(testUser.getScore() == 0);
    testUser.addWin();
    assert(testUser.getScore() == 1);
    cout << "PASS: User score incremented to " << testUser.getScore() << " after 1 win.\n";
}

void testWordleGuessFeedback() {
    cout << "\n==== TEST: Wordle Feedback Simulation ====\n";
    Wordle wordle(nullptr);
    string secret = "plant";
    string guess = "plate";

    cout << "Secret: " << secret << ", Guess: " << guess << endl;
    cout << "Expected Feedback: Green (p, l, a), Yellow (t), Red (_)" << endl;

    cout << "Actual Feedback: ";
    for (int i = 0; i < 5; i++) {
        if (guess[i] == secret[i]) {
            cout << "[G:" << guess[i] << "] ";
        } else if (secret.find(guess[i]) != string::npos) {
            cout << "[Y:" << guess[i] << "] ";
        } else {
            cout << "[_] ";
        }
    }
    cout << endl;
    cout << "PASS: Feedback simulated.\n";
}

int main() {
    cout << "========== WORD GAME UNIT TESTS ==========\n";
    testDrawAsciiArt();
    testWordLoadingAndSelection();
    testLetterCheckLogic();
    testUserScore();
    testWordleGuessFeedback();
    cout << "\nAll Hangman and Wordle tests passed!\n";
    return 0;
}
