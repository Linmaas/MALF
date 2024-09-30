#pragma once

#include "ofMain.h"

class ofWord {
public:
    // Constructor
    ofWord();

    // Method to load words into the database
    void loadWords();

    // Method to get three random words
    std::vector<std::string> getThreeRandomWords();

    void drawWords(std::vector<std::string>& words, ofTrueTypeFont& wordsFont);

    void mouseMoved(int x, int y);


    struct BoxInfo{
        float x,y,width,height;
    };
    std::vector<BoxInfo> wordBoxes;
    int hoveredBoxIndex = -1;

private:

    // The word list (database of words)
    std::vector<std::string> wordDatabase;
};
