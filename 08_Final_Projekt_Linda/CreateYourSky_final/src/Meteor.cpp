#include "Meteor.h"

// Constructor
Meteor::Meteor(ofVec3f pos, ofVec3f vel, float size)
    : position(pos), velocity(vel), size(size) {}

// Update meteor position and trail
void Meteor::update() {
    position += velocity;

    // Add a new particle to the trail at the meteor's current position
    addTrailParticle();

    // Update all trail particles
    for (auto& particle : trail) {
        particle.update();
    }

    // Remove faded particles from the trail
    trail.erase(std::remove_if(trail.begin(), trail.end(), [](Particle& p) {
        return p.isFaded();
    }), trail.end());
}

// Draw the meteor and its trail
void Meteor::draw() {
    // Draw the meteor itself
    ofSetHexColor(0xFFF5D0);
    ofDrawSphere(position, size);

    // Draw the trail particles
    for (auto& particle : trail) {
        particle.draw();
    }
}

// Add a new particle to the trail
void Meteor::addTrailParticle() {
    trail.push_back(Particle(position, size * 0.3f));  // Smaller size for trail particles
}

// Check if the meteor is off-screen
bool Meteor::isOffScreen(float boundary) {
    return position.x > boundary || position.x < -boundary ||
           position.y > boundary || position.y < -boundary ||
           position.z > boundary || position.z < -boundary;
}
