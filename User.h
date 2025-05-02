#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

// ADDED: User class to track player name and score
class User {
    private:
        string name;
        int score;
    
    public:
        User() {
            score = 0;
        }
    
        void setName(string username) {
            name = username;
        }
    
        string getName() const {
            return name;
        }
    
        void addWin() {
            score++;
        }
    
        int getScore() const {
            return score;
        }
};

#endif
