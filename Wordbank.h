#ifndef WORDBANK_H
#define WORDBANK_H

#include "LinkedList.h"

// features binary search, alpha sort, random selection

class Wordbank {
    private:
        LinkedList wordList;

    public:
        Wordbank(); // sets default file (5 letter words for default)
        Wordbank(const std::string& filename); // sets custom file

        void loadWords(const std::string& file); // loads file to LL

        std::string giveWord();  // give random word to guess 

};

#endif
