#pragma once
#include "ofMain.h"
#include "Star.h"

class Constellation {
public:
    Constellation(float distanceThreshold, int maxLines);  // Constructor
    void update(const vector<Star>& stars);  // Update constellation logic (distance checks)
    void draw();  // Draw the constellation lines

private:
    vector<pair<Star, Star>> constellationLines;  // Lines forming constellations
    float distanceThreshold;  // Maximum distance between stars to connect
    int maxLines;  // Maximum number of lines in a constellation
};
