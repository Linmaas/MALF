#include "ofPlayers.h"

ofPlayer::ofPlayer(float x, float y, float width, float height, std::string playerName, int number) {
    float inputBoxY = y + height/2 + 280;
    float inputBoxHeight = height + 50;
    float inputBoxWidth = width + 150;
    inputBox.set(x, inputBoxY, inputBoxWidth, inputBoxHeight); // position and size of the input box
    playerNumber = number; // e.g. Player1, Player2, etc.
    name = playerName; // Start with an empty name
    active = false; // Initially the input box is not active
}

void ofPlayer::draw(ofTrueTypeFont& playerFont, ofTrueTypeFont& userInputFont) {
    ofSetColor(0,0,0);
    ofNoFill();
    ofSetLineWidth(2);
    ofDrawRectangle(inputBox);

    // Draw "Player X" label
    ofFill();
    ofSetColor(0, 0, 0);
    string label = "Player " + ofToString(playerNumber);
    playerFont.drawString(label, inputBox.getX() - 250, inputBox.getY() + inputBox.getHeight() / 2 + 40);

    // Draw the player's name inside the input box
    ofSetColor(0,0,0);
    userInputFont.drawString(name, inputBox.getX() + 50, inputBox.getY() + inputBox.getHeight() / 2 + 40);
}

bool ofPlayer::isMouseOver(float mouseX, float mouseY) {
    return inputBox.inside(mouseX, mouseY);
}

// --- ofPlayers class ---

ofPlayers::ofPlayers() : isMouseOverAddPlayerButton(false) {
}

void ofPlayers::setup() {
    // Setup "Add Player" button (centered at the bottom)
    float buttonWidth = 350;
    float buttonHeight = 130;
    float buttonX = ofGetWidth() / 2 - buttonWidth / 2;
    float buttonY = 200;
    addPlayerButton.set(buttonX, buttonY, buttonWidth, buttonHeight);
}

// Draw the "Add Player" button and all the player input boxes
void ofPlayers::draw(ofTrueTypeFont& buttonFont, ofTrueTypeFont& userInputFont) {
    // Draw the "Add Player" button
    if(isMouseOverAddPlayerButton){
        ofSetColor(80, 80, 80);  // Light grey color
    } else {
        ofSetColor(0, 0, 0);  // Black color
    }
    ofDrawRectangle(addPlayerButton);
    ofSetColor(255,255,255);
    buttonFont.drawString("Add Player", addPlayerButton.getX() + 30, addPlayerButton.getY() + addPlayerButton.getHeight()/2 + 30);

    // Draw all the players and their input boxes
    for (int i = 0; i < players.size(); i++) {
        players[i].draw(buttonFont, userInputFont);
    }
    
    
}

// Add a new player
void ofPlayers::addPlayer() {
    float playerBoxY = players.size() * 100 + 100; // Vertical spacing
    players.emplace_back(ofGetWidth() / 2 - 100, playerBoxY, 200, 30, "", players.size() + 1); 
    players.back().playerNumber = players.size(); // PLayer Number
    setActivePlayer(players.size() - 1); // Set the new player as active
}

// Check if the button was pressed or if a player input box was clicked
void ofPlayers::mousePressed(int x, int y) {
    // Check if the "Add Player" button was pressed
    if (addPlayerButton.inside(x, y)) {
        addPlayer();
    }

    for (int i = 0; i < players.size(); i++) {
        if (players[i].isMouseOver(x, y)) {
            setActivePlayer(i);
            return; 
        }
    }
}

// Check if the mouse is over the "Add Player" button
void ofPlayers::mouseMoved(int x, int y) {
    isMouseOverAddPlayerButton = addPlayerButton.inside(x, y);
}

// Set the active player based on the index
void ofPlayers::setActivePlayer(int index) { 
    for (int i = 0; i < players.size(); i++) {
        players[i].active = (i == index); 
    }
}

// Handle text input for the player input box
void ofPlayers::keyPressed(int key) {
   for (auto& player : players) {
       if (player.active) {
           if (key == OF_KEY_BACKSPACE && !player.name.empty()) {
               player.name.pop_back(); 
           } else if (key >= 32 && key <= 126) {
               player.name += (char)key; 
           }
        }
   }
}

vector<string> ofPlayers::getPlayerNames() {
    vector<string> playerNames;
    for (const auto& player : players) {
        playerNames.push_back(player.name);
    }
    return playerNames;
}