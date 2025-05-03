#ifndef USER_H
#define USER_H
#include <string>


// ADDED: User class to track player name and score
class User {
    private:
        std::string name;
        int score;
        int misses;
    
    public:
        User();
        User(std::string name);
        
        void setName(std::string name);
    
        std::string getName() const;
    
        void miss();

        void addWin();
    
        int getScore() const;
};

#endif
