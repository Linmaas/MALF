#pragma once

#include "ofMain.h"
#include "ofUI.h"
#include "ofWord.h"
#include "ofPlayers.h"

#include "ofPolyline.h"

enum GameState {
    START_SCREEN,
    PLAYERS_SCREEN,
	GAME_TURN_SCREEN,
	CLOSE_EYES_SCREEN,
	WORD_SCREEN,
	OPEN_EYES_SCREEN,
	DRAW_SCREEN,
	GUESSED_SCREEN 
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		// Object instances
		ofUI myUI{}; // Create an instance of the UI
		ofWord wordManager{};  // Create an instance of the word manager
		ofPlayers players; // Manage players

		// Fonts
		ofTrueTypeFont titleFont;  
		ofTrueTypeFont subTitleFont;
		ofTrueTypeFont subSubTitleFont;
		ofTrueTypeFont buttonFont;
		ofTrueTypeFont wordsFont;
		ofTrueTypeFont playerFont;
		ofTrueTypeFont userInputFont;
		ofTrueTypeFont gameTurnFont;
		ofTrueTypeFont underscoreFont;
		ofTrueTypeFont guessedButtonFont;

		// Images
		ofImage titleImage;
		ofImage closeEyesImage;
		ofImage openEyesImage;
		ofImage messageImage;
		ofImage linesImage;

		GameState currentState;  // Add a variable to store the current state

		// Drawinng variables
		std::vector<ofPolyline> strokes;  // To store the user's drawn strokes
		ofPolyline currentStroke;		// To store the current stroke
		std::vector<ofPoint> drawnStrokes;  // Tracks points the user has drawn


		// Strings
		std::string userInput;
		std::vector<std::string> randomWords;  // To store the three random words
		std::string selectedWord;  // Store the word the user selected
		std::vector<std::string> underscores;  // To store underscores for the hint display
		std::vector<std::string> names; // To store the player names
		std::vector<std::string> wordsToChooseFrom;  // Vector to store the 3 random words

		// Integers
		int guessedPlayerIndex; 
		int mouseX;
		int mouseY;

		// Functions
		bool isMouseOver(float mouseX, float mouseY, float x, float y, float width, float height);
		void resetGame();
		void updateUnderscores();
};