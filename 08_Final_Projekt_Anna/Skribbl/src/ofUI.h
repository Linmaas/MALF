#pragma once

#include "ofMain.h"
#include "ofWord.h"
#include "ofPlayers.h"

class ofUI
{
    public:

        // Functions
        // Screens
        void StartGameScreen(ofTrueTypeFont& titleFont, ofTrueTypeFont& subTitleFont,  ofImage titleImage );
        void playerScreen(ofImage linesImage);
        void gameTurnScreen(ofPlayers& playersManager, ofTrueTypeFont& gameTurnFont, ofImage linesImage);
        void closeEyesScreen(ofImage closeEyesImage);
        void WordScreen(std::vector<std::string>& words, ofTrueTypeFont& wordsFont, ofTrueTypeFont subTitleFont, ofImage messageImage);
        void openEyesScreen(ofImage openEyesImage);
        void DrawScreen();
        void GuessedScreen(const std::string& playerName, ofTrueTypeFont& subTitleFont, ofTrueTypeFont& subSubTitleFont, ofImage titleImage); 

        //Buttons
        void PlayButton(ofTrueTypeFont& buttonFont, int mouseX, int mouseY);
        void continueButton(ofTrueTypeFont& buttonFont, int mouseX, int mouseY);
        void DrawGuessedButton(const std::vector<std::string>& names, ofTrueTypeFont& guessedButtonFont);  // New guessed button
        void PlayAgainButton(ofTrueTypeFont& buttonFont, int mouseX, int mouseY);
        
        //UI Elements
        void PlayerBox(ofTrueTypeFont& playerFont, string userInput);
        void DrawUnderscores(const std::vector<std::string>& underscores, ofTrueTypeFont& buttonFont);
        
        // Helper functions
        void getPlayersNames(ofPlayers& playersManager);  // Get all players names
        std::string selectRandomPlayer(ofPlayers& playersManager);  // Select a random player
        bool isMouseOverButton(int mouseX, int mouseY, float buttonX, float buttonY, float buttonWidth, float buttonHeight);

        //Instances
        ofWord wordManager{};  // Create an instance of the word manager
        ofPlayers playersManager{};  // Create an instance of the player manager

        //Strings
        std::string randomPlayer;
        std::string selectedPlayer;


        // Struct to store button information
        struct ButtonInfo { 
            float x, y, width, height;
        };

        
        //Vectors
        std::vector<ButtonInfo> guessedButtons;

};