#include "ofWord.h"
#include <algorithm>  // For std::shuffle
#include <random>     // For std::default_random_engine

// Constructor
ofWord::ofWord() {
    loadWords();  // Load words into the database when the object is created
}

// Load words into the database (you can also load this from a file if needed)
void ofWord::loadWords() {
    // Load words from a file
    ofBuffer buffer = ofBufferFromFile("words.txt");  // Load words from a file
    for (auto line : buffer.getLines()) {
        wordDatabase.push_back(line);
    }
}

void ofWord::mouseMoved(int x, int y){
    hoveredBoxIndex = -1; // Resent hovered box index

    // Check if the mouse is over any of the word boxes
    for (int i = 0; i < wordBoxes.size(); i++){
        const auto& box = wordBoxes[i];
        if (x >= box.x && x <= box.x + box.width && y >= box.y && y <= box.y + box.height) {
             hoveredBoxIndex = i; // Set the hovered box index
             break;
        }
    } 
} 

std::vector<std::string> ofWord::getThreeRandomWords() {
    // Create a copy of the wordDatabase so we can shuffle it without affecting the original list
    std::vector<std::string> shuffledWords = wordDatabase;
    
    // Shuffle the word list
    std::random_device rd;
    std::mt19937 g(rd());  // Random number generator
    std::shuffle(shuffledWords.begin(), shuffledWords.end(), g);
    
    // Get the first three words
    std::vector<std::string> randomWords;
    for (int i = 0; i < 3 && i < shuffledWords.size(); i++) {
        randomWords.push_back(shuffledWords[i]);
    }

    return randomWords;
}

void ofWord::drawWords(std::vector<std::string>& words, ofTrueTypeFont& wordsFont) {
    float boxWidth = 400;
    float boxHeight = 100;
    float startX = ofGetWidth() / 2 - boxWidth / 2;
    float startY = ofGetHeight() / 4 + 100;  // Starting position for the first word

    wordBoxes.clear(); // Cclear previous box information

    for (int i = 0; i < words.size(); i++) {
        // Calculate box position based on the index
        float boxY = startY + i * (boxHeight + 20);  // Adding spacing between boxes
        
        // Store box information
        wordBoxes.push_back({startX, boxY, boxWidth, boxHeight});
        
        if(i == hoveredBoxIndex){
            ofSetColor(1,0,0);
        } else {
            ofSetColor(0,0,0);
        }
        

        // Draw the box
        ofNoFill();
        ofSetLineWidth(2);
        ofDrawRectangle(startX, boxY, boxWidth, boxHeight);

        // Draw the word inside the box
        ofFill();
        ofSetColor(0, 0, 0);
        float textWidth = wordsFont.stringWidth(words[i]);
        float textHeight = wordsFont.stringHeight(words[i]);

        // Center the text inside the button
        float textX = startX + (boxWidth - textWidth) / 2;
        float textY = boxY + (boxHeight + textHeight) / 2;

        wordsFont.drawString(words[i], textX, textY);
    }
}

 