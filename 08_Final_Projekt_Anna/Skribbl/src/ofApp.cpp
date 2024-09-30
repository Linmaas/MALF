#include "ofApp.h"
#include <random>

//--------------------------------------------------------------
void ofApp::setup(){

// font loaders
titleFont.load("Amatic-Bold.ttf", 300);
subTitleFont.load("Amatic-Bold.ttf", 100);
subSubTitleFont.load("Amatic-Bold.ttf", 80);
gameTurnFont.load("Amatic-Bold.ttf", 100);
playerFont.load("Amatic-Bold.ttf", 24);
userInputFont.load("Amatic-Bold.ttf", 75);
buttonFont.load("Amatic-Bold.ttf", 80);
wordsFont.load("Amatic-Bold.ttf", 40);
underscoreFont.load("Roboto-Medium.ttf", 30);
guessedButtonFont.load("Amatic-Bold.ttf", 40);

// background images loaders
titleImage.load("title.jpg");
linesImage.load("lines.jpg");
closeEyesImage.load("closeEyes.jpg");
openEyesImage.load("openEyes.jpg");
messageImage.load("message.jpg");

userInput = "";
currentState = START_SCREEN;

players.setup(); // Setup the players screen
guessedPlayerIndex = -1;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofSetColor(255);

	if(currentState == START_SCREEN){
		myUI.StartGameScreen(titleFont, subTitleFont, titleImage);
		myUI.PlayButton(buttonFont, mouseX, mouseY);
	}
	else if(currentState == PLAYERS_SCREEN){
		//ofBackground(255, 255, 255);
		myUI.playerScreen(linesImage);
		players.draw(buttonFont, userInputFont);
		myUI.continueButton(buttonFont, mouseX, mouseY);
	}
	else if(currentState == GAME_TURN_SCREEN){
		myUI.gameTurnScreen(players, gameTurnFont, linesImage);
		myUI.continueButton(buttonFont, mouseX, mouseY);
	}
	else if (currentState == CLOSE_EYES_SCREEN) {
		myUI.closeEyesScreen(closeEyesImage);
		myUI.continueButton(buttonFont, mouseX, mouseY);
	}
	else if(currentState == WORD_SCREEN){
		myUI.WordScreen(randomWords, wordsFont, subTitleFont, messageImage);
	}
	else if(currentState == OPEN_EYES_SCREEN){
		myUI.openEyesScreen(openEyesImage);
		myUI.continueButton(buttonFont, mouseX, mouseY);
	}
	else if(currentState == DRAW_SCREEN){
		myUI.DrawScreen();
		for (const auto& stroke : strokes) {
			stroke.draw();  // Draw all the strokes
		}
		currentStroke.draw();  // Draw the current stroke

		myUI.DrawUnderscores(underscores, underscoreFont);  // Draw the underscores
		myUI.DrawGuessedButton(players.getPlayerNames(), guessedButtonFont);  
	}

	else if(currentState == GUESSED_SCREEN){
        if(guessedPlayerIndex != -1){
			myUI.GuessedScreen(players.getPlayerNames()[guessedPlayerIndex], subTitleFont, subSubTitleFont, titleImage); 
		}
		     
        myUI.PlayAgainButton(buttonFont, mouseX, mouseY);  
    }


}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(currentState == PLAYERS_SCREEN){
		players.keyPressed(key);
	} 
	else if (key == OF_KEY_BACKSPACE && !userInput.empty()) {
        userInput.pop_back();  // Handle backspace
    }  else {
        userInput += (char)key;  // Add the character to the input
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	players.mouseMoved(x, y);
	 mouseX = x;
	 mouseY = y;

	wordManager.mouseMoved(x,y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

	if (currentState == DRAW_SCREEN) {
        currentStroke.addVertex(x, y);  // Add the current mouse position to the stroke
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (currentState == START_SCREEN){
		float playButtonWidth = 280;
    	float playButtonHeight = 130;
    	float playButtonX = ofGetWidth() / 2 - playButtonWidth / 2 ;
    	float playButtonY = ofGetHeight() / 2 - playButtonHeight / 2 + 200;

		if(isMouseOver(x, y, playButtonX, playButtonY, playButtonWidth, playButtonHeight)){
			cout << "Button Pressed" << endl;
			currentState = PLAYERS_SCREEN;
		}
	}
	else if(currentState == PLAYERS_SCREEN){
		players.mousePressed(x, y);

		// Handle the "Continue" button on the close eyes screen
		float continueButtonWidth = 350;
    	float continueButtonHeight = 130;
    	float continueButtonX = ofGetWidth() - continueButtonWidth - 150;
    	float continueButtonY = ofGetHeight() - 200;

		if (isMouseOver(x, y, continueButtonX, continueButtonY, continueButtonWidth, continueButtonHeight)) {
			cout << "Continue Button Pressed" << endl;
			currentState = GAME_TURN_SCREEN;
		}
	}
	else if(currentState == GAME_TURN_SCREEN){
		// Handle the "Continue" button on the close eyes screen
		float continueButtonWidth = 350;
    	float continueButtonHeight = 130;
    	float continueButtonX = ofGetWidth() - continueButtonWidth - 150;
    	float continueButtonY = ofGetHeight() - 200;

		if(isMouseOver(x, y, continueButtonX, continueButtonY, continueButtonWidth, continueButtonHeight)){
			cout << "Continue Button Pressed" << endl;
			currentState = CLOSE_EYES_SCREEN;
			myUI.selectedPlayer.clear();
		}
	}
	else if( currentState == CLOSE_EYES_SCREEN){
		// Handle the "Continue" button on the close eyes screen
		float continueButtonWidth = 350;
    	float continueButtonHeight = 130;
    	float continueButtonX = ofGetWidth() - continueButtonWidth - 150;
    	float continueButtonY = ofGetHeight() - 200;

		if(isMouseOver(x, y, continueButtonX, continueButtonY, continueButtonWidth, continueButtonHeight)){
			cout << "Continue Button Pressed" << endl;
			randomWords = wordManager.getThreeRandomWords();  // Get new random words
			currentState = WORD_SCREEN;
		}
	}
	else if (currentState == WORD_SCREEN){
		// Handle word selection
		float boxWidth = 400;
		float boxHeight = 100;
		float startX = ofGetWidth() / 2 - boxWidth / 2;
		float startY = ofGetHeight() / 4 + 100;  // Starting position for the first word

		for (int i = 0; i < randomWords.size(); i++) {
			// Calculate box position based on the index
			float boxY = startY + i * (boxHeight + 20);  // Adding spacing between boxes

			// Check if the mouse is over the box
			if (isMouseOver(x, y, startX, boxY, boxWidth, boxHeight)) {
				cout << "Word selected: " << randomWords[i] << endl;
				selectedWord = randomWords[i];
				currentState = OPEN_EYES_SCREEN;  // Move to the open eyes screen

				break;
			}
		}
	}
	else if( currentState == OPEN_EYES_SCREEN){
		// Handle the "Continue" button on the close eyes screen
		float continueButtonWidth = 350;
    	float continueButtonHeight = 130;
    	float continueButtonX = ofGetWidth() - continueButtonWidth - 150;
    	float continueButtonY = ofGetHeight() - 200;

		if(isMouseOver(x, y, continueButtonX, continueButtonY, continueButtonWidth, continueButtonHeight)){
			cout << "Continue Button Pressed" << endl;
			currentState = DRAW_SCREEN;  // Move to the drawing screen
			strokes.clear();
			currentStroke.clear();

			updateUnderscores();  // Update the underscores after a word is selected
			
		}
	}
	else if (currentState == DRAW_SCREEN) {
        currentStroke.clear();  // Clear the current stroke when a new one starts

		for (size_t i = 0; i < myUI.guessedButtons.size(); ++i) {
            const auto& btn = myUI.guessedButtons[i];
            if (isMouseOver(x, y, btn.x, btn.y, btn.width, btn.height)) {
                currentState = GUESSED_SCREEN;
                guessedPlayerIndex = i; // Pass the player's name
                break;
            }
        }
	}

	else if(currentState == GUESSED_SCREEN){
        // Handle Play Again Button
        float playAgainButtonWidth = 330;
    	float playAgainButtonHeight = 130;
    	float playAgainButtonX = ofGetWidth() / 2 - playAgainButtonWidth / 2 ;
    	float playAgainButtonY = ofGetHeight() / 2 - playAgainButtonHeight / 2 + 200;

        if(isMouseOver(x, y, playAgainButtonX, playAgainButtonY, playAgainButtonWidth, playAgainButtonHeight)){
            currentState = GAME_TURN_SCREEN;  // Go back to the word selection screen
			resetGame();  // Reset the game
        }
    }
}



//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if (currentState == DRAW_SCREEN) {
        strokes.push_back(currentStroke);  // Add the current stroke to the strokes vector
        currentStroke.clear();  // Clear the current stroke
    }
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

bool ofApp::isMouseOver(float mouseX, float mouseY, float x, float y, float width, float height) {
    return mouseX > x && mouseX < x + width && mouseY > y && mouseY < y + height;
}



void ofApp::resetGame() {
    // Reset the state
    currentState = GAME_TURN_SCREEN;  // Go back to word selection screen

    // Fetch new random words
    randomWords = wordManager.getThreeRandomWords();  // Get new random words
    selectedWord = "";  // Reset selected word

    // Reset the drawing board
	strokes.clear();  // Clear any strokes
    currentStroke.clear();  // Clear any strokes on the drawing board
    
    // Clear hint and underscores
    underscores.clear();

    // Update the underscores after a word is selected (in the future)
    updateUnderscores();
}

void ofApp::updateUnderscores() {
    if (!selectedWord.empty()) {
        underscores.clear();
        for (char c : selectedWord) {
            underscores.push_back("_");
        }
    }
}