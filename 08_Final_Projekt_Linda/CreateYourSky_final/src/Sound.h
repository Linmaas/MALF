#pragma once
#include "ofMain.h"

class Sound {
public:
    void setup();  // Load and setup sounds
    void update();  // Manage delay and looping logic
    void playStarCreationSound();  // Play sound when a star is created

private:
    ofSoundPlayer backgroundMusic;  // Background music
    vector<ofSoundPlayer> starCreationSounds;  // Array of star creation sounds

    bool musicPlaying = false;  // Is the music currently playing?
    unsigned long long lastTime = 0;  // Last timestamp
    int state = 0;  // 0: Waiting for initial delay, 1: Playing music, 2: Waiting between loops
};
