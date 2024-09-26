#pragma once
#include "ofMain.h"

class StartScreen {
public:
    void setup();  // Any initial setup
    void draw();   // Draw the start screen
    bool isActive();  // Check if the start screen is active
    void hide();   // Hide the start screen (when the user starts the app)

private:
    bool show = true;  // Controls whether to show the start screen
};
