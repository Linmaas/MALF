// Meteors.h
#pragma once
#include "ofMain.h"

#include "Particle.h"

class Meteor {
public:
    Meteor(ofVec3f pos, ofVec3f vel, float size);

    void update();
    void draw();

    bool isOffScreen(float boundary = 6000.0f);

private:
    ofVec3f position;
    ofVec3f velocity;
    float size;

    // Trail-related
    std::vector<Particle> trail;  // The trail of particles

    void addTrailParticle();
};
