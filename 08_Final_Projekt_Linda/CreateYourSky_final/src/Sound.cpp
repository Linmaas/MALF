#include "Sound.h"

void Sound::setup() {
    // Load the background music
    backgroundMusic.load("ES_A World Behind - Hanna Lindgren.wav");
    backgroundMusic.setLoop(false);
    backgroundMusic.setVolume(0.5f);

    // Load all four star creation sounds
    vector<string> soundFiles = {
        "Star_spawn.wav",
        "Star_spawn_2.wav",
        "Star_spawn_3.wav",
        "Star_spawn_4.wav"
    };

    // Load the sounds into the array
    for (const string& file : soundFiles) {
        ofSoundPlayer sound;
        sound.load(file);
        sound.setMultiPlay(true);
        sound.setVolume(0.1);
        starCreationSounds.push_back(sound);
    }

    
    lastTime = ofGetElapsedTimeMillis();
}

void Sound::update() {
    unsigned long long currentTime = ofGetElapsedTimeMillis();
    
    if (state == 0) {
        if (currentTime - lastTime > 10000) {  // 10 seconds delay
            backgroundMusic.play();  // Play the music
            musicPlaying = true;  // Mark the music as playing
            state = 1;  // Move to the next state
        }
    } else if (state == 1) {
        if (!backgroundMusic.isPlaying() && musicPlaying) {
            musicPlaying = false;  // Mark the music as not playing
            lastTime = currentTime;  // Reset the timer
            state = 2;  // Move to the waiting state
        }
    } else if (state == 2) {
        if (currentTime - lastTime > 30000) {  // 30 seconds delay
            backgroundMusic.play();  // Play the music again
            musicPlaying = true;  // Mark the music as playing
            state = 1;  // Return to the playing state
        }
    }
}

void Sound::playStarCreationSound() {
    // Randomly select one of the star creation sounds to play
    int randomIndex = (int)ofRandom(0, starCreationSounds.size());
    starCreationSounds[randomIndex].play();  // Play the randomly selected sound
}
