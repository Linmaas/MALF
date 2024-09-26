#pragma once
#include "ofMain.h"

class Particle {
public:
    ofVec3f position;
    float opacity;
    float size;

    Particle(ofVec3f pos, float s) : position(pos), size(s), opacity(255) {}

    // Update the opacity to create a fading effect
    void update() {
        opacity -= 5;  // Decrease opacity to fade out the particle
        if (opacity < 0) opacity = 0;
    }

    // Draw the particle
    void draw() {
        ofSetColor(255, 153, 51, opacity);  // Orange color, fading with opacity
        ofDrawSphere(position, size);
    }

    // Check if the particle has completely faded
    bool isFaded() const {
        return opacity <= 0;
    }
};
