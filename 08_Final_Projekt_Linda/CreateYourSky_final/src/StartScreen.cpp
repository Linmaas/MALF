#include "StartScreen.h"

void StartScreen::setup() {
   
}

void StartScreen::draw() {
    if (!show) return;

    
    ofBackground(0, 0, 0);

   
    
    
    
    
     string asciiArt = R"(
   *    .  *       .             *
                          *
  *   .        *       .       .       *
    .     *
            .     .  *        *
        .                .        .
 .  *           *                     *
                              .
          *          .   *
     )";
    
   
    ofSetColor(255);
    
    ofDrawBitmapString(asciiArt, ofGetWidth() / 2 - 200 , ofGetHeight() / 2 - 200);
    ofDrawBitmapString("the universe seems a bit empty right now...\n"
                       "maybe you can help!\n\n"
                       
                       "1. RIGHT-CLICK to add stars to the sky.\n"
                       "2. name your stars.\n"
                       "3. hit S + SPACE to become forever part of this universe.\n\n"
                      
                       
                       "press any key to start!",
                       ofGetWidth() / 2 - 200, ofGetHeight() / 2);
}

bool StartScreen::isActive() {
    return show;
}

void StartScreen::hide() {
    show = false;  
}
