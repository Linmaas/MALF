#include "Constellation.h"

Constellation::Constellation(float distanceThreshold, int maxLines) {
    this->distanceThreshold = distanceThreshold;
    this->maxLines = maxLines;
}

void Constellation::update(const vector<Star>& stars) {
    constellationLines.clear();  // Clear old constellation lines

    // Compare each star with every other star, only connect to the closest
    for (size_t i = 0; i < stars.size(); i++) {
        float minDistance = distanceThreshold;
        int closestStarIndex = -1;

        // Find the closest star within the threshold distance
        for (size_t j = 0; j < stars.size(); j++) {
            if (i != j) {  // Don't connect a star to itself
                float distance = stars[i].position.distance(stars[j].position);

                if (distance < minDistance) {
                    minDistance = distance;
                    closestStarIndex = j;  // Remember the closest star index
                }
            }
        }

        // Connect the current star to the closest one found (if any)
        if (closestStarIndex != -1 && constellationLines.size() < maxLines) {
            constellationLines.push_back(make_pair(stars[i], stars[closestStarIndex]));
        }
    }
}

void Constellation::draw() {
    // Draw lines connecting stars
    ofSetLineWidth(5);
    ofSetColor(255, 255, 255);
    for (auto& line : constellationLines) {
        ofDrawLine(line.first.position, line.second.position);  // Draw a line between two stars
    }
}
