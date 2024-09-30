#include "ofUI.h"
#include "ofWord.h"
#include "ofApp.h"

// game start screen function
void ofUI::StartGameScreen(ofTrueTypeFont& titleFont, ofTrueTypeFont& subTitleFont, ofImage titleImage ){
    
    titleImage.draw(0, 0, ofGetWidth(), ofGetHeight());
    ofSetColor(0, 0, 0);
    //title
    std::string title = "SKRIBBL";
    float titleWidth = titleFont.stringWidth(title);
    float titleHeight = titleFont.stringHeight(title);
    // title position
    float titleX = ofGetWidth() / 2 - titleWidth / 2;
    float titleY = 500;
    titleFont.drawString(title, titleX, titleY);

    //subtitle
    std::string subTitle = "LITE";
    float subTitleWidth = subTitleFont.stringWidth(subTitle);
    float subTitleHeight = subTitleFont.stringWidth(subTitle);
    // subtitle position
    float subTitleX = ofGetWidth() / 2 - subTitleWidth / 2;
    float subTitleY = titleY + titleHeight - 150;
    subTitleFont.drawString(subTitle, subTitleX, subTitleY);

}

bool ofUI::isMouseOverButton(int mouseX, int mouseY, float buttonX, float buttonY, float buttonWidth, float buttonHeight) {
    return mouseX >= buttonX && mouseX <= buttonX + buttonWidth &&
           mouseY >= buttonY && mouseY <= buttonY + buttonHeight;
}

void ofUI::PlayButton(ofTrueTypeFont& buttonFont, int mouseX, int mouseY){
    // play button box setup
    float playButtonWidth = 280;
    float playButtonHeight = 130;
    float playButtonX = ofGetWidth() / 2 - playButtonWidth / 2 ;
    float playButtonY = ofGetHeight() / 2 - playButtonHeight / 2 + 200;
    // check if the mouse is over the button
    bool isMouseOver = isMouseOverButton(mouseX, mouseY, playButtonX, playButtonY, playButtonWidth, playButtonHeight);
    // Change color based on mouse position
    if (isMouseOver) {
        ofSetColor(80, 80, 80);  // Light grey color
    } else {
        ofSetColor(0, 0, 0);  // Black color
    }
    ofDrawRectangle(playButtonX, playButtonY, playButtonWidth, playButtonHeight);

    // play button text setup
    ofSetColor(255, 255, 255);
    std::string playButtonText = "Play";
    float playTextWidth = buttonFont.stringWidth(playButtonText);
    float playTextHeight = buttonFont.stringHeight(playButtonText);
    // Center the text inside the button
    float playButtonTextX = playButtonX + (playButtonWidth - playTextWidth) / 2;
    float playButtonTextY = playButtonY + (playButtonHeight + playTextHeight) / 2;
    buttonFont.drawString(playButtonText, playButtonTextX, playButtonTextY);
  
}

void ofUI::playerScreen(ofImage linesImage){
    linesImage.draw(0, 0, ofGetWidth(), ofGetHeight());
}

// Select one random name from the list of players
std::string ofUI::selectRandomPlayer(ofPlayers& playersManager){
    std::vector<string> names = playersManager.getPlayerNames();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, names.size() - 1);
    int randomIndex = dis(gen);
    std::string randomName = names[randomIndex];
    std::cout << "Random player: " << randomName << std::endl;
    return randomName;
}

// Selected game turn screen

void ofUI::gameTurnScreen(ofPlayers& playersManager, ofTrueTypeFont& gameTurnFont, ofImage linesImage){
    
    linesImage.draw(0, 0, ofGetWidth(), ofGetHeight());

    // If no player is selected, select a random player
    if(selectedPlayer.empty()){
        selectedPlayer = selectRandomPlayer(playersManager);
    }
    //ofBackground(255, 255, 255);
    ofSetColor(0, 0, 0);
    // Create a message for the selected player to choose a word
    std::string message = selectedPlayer + " chooses a word!";
    float textWidth = gameTurnFont.stringWidth(message);
    gameTurnFont.drawString(message, ofGetWidth() / 2 - textWidth / 2, ofGetHeight() / 2 - 50);

}

void ofUI::continueButton(ofTrueTypeFont& buttonFont, int mouseX, int mouseY){
    // play button box setup
    float continueButtonWidth = 350;
    float continueButtonHeight = 130;
    float continueButtonX = ofGetWidth() - continueButtonWidth - 150;
    float continueButtonY = ofGetHeight() - 200;
    // check if the mouse is over the button
    bool isMouseOver = isMouseOverButton(mouseX, mouseY, continueButtonX, continueButtonY, continueButtonWidth, continueButtonHeight);
    // Change color based on mouse position
    if (isMouseOver) {
        ofSetColor(80, 80, 80);  // Light grey color
    } else {
        ofSetColor(0, 0, 0);  // Black color
    }
    ofDrawRectangle(continueButtonX, continueButtonY, continueButtonWidth, continueButtonHeight);

    // play button text setup
    ofSetColor(255, 255, 255);
    std::string continueButtonText = "continue";
    float continueTextWidth = buttonFont.stringWidth(continueButtonText);
    float continueTextHeight = buttonFont.stringHeight(continueButtonText);
    // Center the text inside the button
    float continueButtonTextX = continueButtonX + (continueButtonWidth - continueTextWidth) / 2;
    float continueButtonTextY = continueButtonY + (continueButtonHeight + continueTextHeight) / 2;
    buttonFont.drawString(continueButtonText, continueButtonTextX, continueButtonTextY);
  
}

void ofUI::closeEyesScreen(ofImage closeEyesImage){
    closeEyesImage.draw(0, 0, ofGetWidth(), ofGetHeight());
}

void ofUI::WordScreen(std::vector<std::string>& words, ofTrueTypeFont& wordsFont, ofTrueTypeFont subTitleFont, ofImage messageImage){
    //ofBackground(255, 255, 255);
    messageImage.draw(0, 0, ofGetWidth(), ofGetHeight());

    ofSetColor(0, 0, 0);

    wordManager.drawWords(words, wordsFont);

    // instructions
    std::string title = "Choose one word";
    float titleWidth = subTitleFont.stringWidth(title);
    float titleHeight = subTitleFont.stringHeight(title);
    // title position
    float titleX = ofGetWidth() / 2 - titleWidth / 2;
    float titleY = 225;
    subTitleFont.drawString(title, titleX, titleY);


}

void ofUI::openEyesScreen(ofImage openEyesImage){
    openEyesImage.draw(0, 0, ofGetWidth(), ofGetHeight());
}

void ofUI::DrawScreen() {
    ofBackground(255, 255, 255);  // White background
    ofSetColor(0, 0, 0);  // Black color for drawing
}

// Draw underscores corresponding to the number of letters in the word
void ofUI::DrawUnderscores(const std::vector<std::string>& underscores, ofTrueTypeFont& underscoreFont ) {
    ofSetColor(0, 0, 0);  // Set color to black
    float spacing = 30;  // Space between underscores
    float startX = ofGetWidth() / 2 - (underscores.size() * spacing) / 2;
    float yPosition = 150;  // Position of underscores from the top of the screen

    // Draw one underscore per letter in the word
    for (const auto& underscore : underscores) {
        underscoreFont.drawString(underscore, startX, yPosition);
        startX += spacing;  // Move to the next position
    }
}


void ofUI::DrawGuessedButton(const std::vector<string>& names, ofTrueTypeFont& guessedButtonFont) {
    float buttonWidth = 300;
    float buttonHeight = 100;
    float spacing = 150;
    float startY = 50;

    guessedButtons.clear();

    // Loop through each player name and create a button for them
    for (size_t i = 0; i < names.size(); i++) {
        float buttonX = ofGetWidth() - buttonWidth - 50;
        float buttonY = startY + i * spacing;

        ofSetColor(0, 0, 0);
        ofDrawRectangle(buttonX, buttonY, buttonWidth, buttonHeight);

        ofSetColor(255, 255, 255);
        std::string buttonText = names[i] + " guessed";
        
        ofRectangle bounds = guessedButtonFont.getStringBoundingBox(buttonText, 0, 0);
        float textX = buttonX + (buttonWidth - bounds.getWidth()) / 2;
        float textY = buttonY + (buttonHeight + bounds.getHeight()) / 2;
        guessedButtonFont.drawString(buttonText, textX, textY);

        // Store button information
        guessedButtons.push_back({buttonX, buttonY, buttonWidth, buttonHeight});
    }
}

void ofUI::GuessedScreen(const std::string& playerName, ofTrueTypeFont& subTitleFont, ofTrueTypeFont& subSubTitleFont, ofImage titleImage) {
    //ofBackground(255, 255, 255);

    titleImage.draw(0, 0, ofGetWidth(), ofGetHeight());
    ofSetColor(0, 0, 0);
    
    std::string message = playerName + " guessed the word!";
    float textWidth = subTitleFont.stringWidth(message);
    subTitleFont.drawString(message, ofGetWidth() / 2 - textWidth / 2, ofGetHeight() / 2 - 200);

    
    std::string question = "Do you want to play again?";
    textWidth = subSubTitleFont.stringWidth(question);
    subSubTitleFont.drawString(question, ofGetWidth() / 2 - textWidth / 2, ofGetHeight() / 2 + 30);

    std::string instructions = "To finish the game, press Esc";
    textWidth = subSubTitleFont.stringWidth(instructions);
    subSubTitleFont.drawString(instructions, ofGetWidth() / 2 + 450 , ofGetHeight() / 2 + 750);
}

void ofUI::PlayAgainButton(ofTrueTypeFont& buttonFont, int mouseX, int mouseY) {
    float playAgainButtonWidth = 330;
    float playAgainButtonHeight = 130;
    float playAgainButtonX = ofGetWidth() / 2 - playAgainButtonWidth / 2 ;
    float playAgainButtonY = ofGetHeight() / 2 - playAgainButtonHeight / 2 + 200;
    
    // check if the mouse is over the button
    bool isMouseOver = isMouseOverButton(mouseX, mouseY, playAgainButtonX, playAgainButtonY, playAgainButtonWidth, playAgainButtonHeight);
    // Change color based on mouse position
    if (isMouseOver) {
        ofSetColor(80, 80, 80);  // Light grey color
    } else {
        ofSetColor(0, 0, 0);  // Black color
    }
    ofDrawRectangle(playAgainButtonX, playAgainButtonY, playAgainButtonWidth, playAgainButtonHeight);
    
    ofSetColor(255, 255, 255);
    std::string playAgainButtonText = "Play Again";
    float playAgainTextWidth = buttonFont.stringWidth(playAgainButtonText);
    float playAgainTextHeight = buttonFont.stringHeight(playAgainButtonText);
    // Center the text inside the button
    float playAgainButtonTextX = playAgainButtonX + (playAgainButtonWidth - playAgainTextWidth) / 2;
    float playAgainButtonTextY = playAgainButtonY + (playAgainButtonHeight + playAgainTextHeight) / 2;
    buttonFont.drawString(playAgainButtonText, playAgainButtonTextX, playAgainButtonTextY);
}

