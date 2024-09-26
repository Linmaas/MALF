#pragma once
#include "ofMain.h"

class Star {
public:
    ofVec3f position;  // 3D position of the star
    std::string name;  // Name of the star (can be empty for decoration)
    float currentSize;  // Current size (used for animation)
    float targetSize;   // Final size


        // Constructor with optional name
    Star(ofVec3f pos, std::string starName = "");

    void update();
        // Function to draw the star
    void draw();
};

