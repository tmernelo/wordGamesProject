#ifndef USER_H
#define USER_H
#include <string>


// ADDED: User class to track player name and score
class User {
    private:
        std::string name;
        int score;
        //float score;
        
    
    public:
        User();
        User(std::string name);
        User(std::string name,int score);
        
        void setName(std::string name);
    
        std::string getName() const;
    
    

        void addWin();
        void setScore(float score);
        float getScore() const;
};

#endif
