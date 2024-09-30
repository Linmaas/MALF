#pragma once 

#include "ofMain.h"


class ofPlayer {
    public:
        // Constructor
        ofPlayer(float x, float y, float width, float height, std::string playerName, int number); 

        // Methods
        void draw(ofTrueTypeFont& playerFont, ofTrueTypeFont& userInputFont);
        bool isMouseOver(float mouseX, float mouseY);

        // Variables
        ofRectangle inputBox; // Input box for the player's name

        // String
        std::string name; // Player's name

        // Int
        int playerNumber; // Player number

        // Bool
        bool active;   // Is the input box active? 

};

class ofPlayers {
    public:
        // Constructor
        ofPlayers(); 

        // Functions
        void setup();
        void draw(ofTrueTypeFont& buttonFont, ofTrueTypeFont& userInputFont);
        void addPlayer();
        void mousePressed( int x, int y);
        void mouseMoved(int x, int y); // Add this method
        void keyPressed(int key);
        void setActivePlayer(int index);

        std::vector<std::string> getPlayerNames(); // Method to get all players names

    private:

        std::vector<ofPlayer> players; // Vector to store all players
        ofRectangle addPlayerButton; // Add player button
        bool isMouseOverAddPlayerButton; // Is the mouse over the add player button?
};