#include "Star.h"

Star::Star(ofVec3f pos, std::string starName) {
    position = pos;
    name = starName;
    currentSize = 0.0f;
    targetSize = ofRandom(1.0f, 5.0f);
}


void Star::update() {
    float growthSpeed = 0.15f;
    if (currentSize < targetSize) {
        currentSize += growthSpeed;
        if (currentSize > targetSize) {
            currentSize = targetSize;
        }
    }
}
// Draw method implementation
void Star::draw() {
    
    //ofSetColor(255, 100);  // Set a transparent color
    //ofDrawSphere(position, 50);  // Draw the hitbox (50 is the clickRadius)
    
    ofSetColor(255);
    ofDrawSphere(position, currentSize);  // Draw the star as a sphere at the given position
    
    // Only draw the name if it's not empty
    if (!name.empty()) {
        ofDrawBitmapString(name, position + ofVec3f(10, 10, 0));  // Draw the name next to the star
    }
}

