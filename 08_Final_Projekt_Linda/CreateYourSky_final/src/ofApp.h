#pragma once

#include "ofMain.h"
#include "ofEasyCam.h"
#include "Star.h"
#include "ofxPostProcessing.h"
#include "Constellation.h"
#include "Sound.h"
#include "StartScreen.h"
#include "json.hpp"
#include "Meteor.h"


class ofApp : public ofBaseApp{

	public:
		void setup() override;
		void update() override;
		void draw() override;
		void exit() override;

		void keyPressed(int key) override;
		void keyReleased(int key) override;
		void mouseMoved(int x, int y ) override;
		void mouseDragged(int x, int y, int button) override;
		void mousePressed(int x, int y, int button) override;
		void mouseReleased(int x, int y, int button) override;
		void mouseScrolled(int x, int y, float scrollX, float scrollY) override;
		void mouseEntered(int x, int y) override;
		void mouseExited(int x, int y) override;
		void windowResized(int w, int h) override;
		void dragEvent(ofDragInfo dragInfo) override;
		void gotMessage(ofMessage msg) override;
        void resetCamera();
    
        void saveStars();
        void loadStars();
    
    bool isSpacePressed = false;
    bool isSKeyPressed = false;
    
    bool isOrbiting = false;  // To check if the camera is currently orbiting
    ofVec3f orbitCenter;  // The point around which the camera will orbit
    float orbitAngleX = 0.0f;  // Angle for the camera orbit around the X axis
    float orbitAngleY = 0.0f;  // Angle for the camera orbit around the Y axis
    float orbitSpeed = 0.5f;  // Speed of the orbit (adjust as needed)
		
    ofEasyCam cam;
    Sound sound; 
    StartScreen startScreen;
    std::vector<Star> stars;  // Vector to store Star objects
    vector<Star> backgroundStars;
    Constellation constellation;
    
    ofxPostProcessing postProcessing;  // Post-processing object
    ofVec3f initialCameraPosition;  // Store the initial camera position
    ofQuaternion initialCameraOrientation;

    ofTrueTypeFont font;
    
   
    void zoomToStar(ofVec3f targetPosition);

    ofVec3f cameraTargetPosition;  // Target position for the camera to zoom into
    bool isZooming = false;        // Flag to control if zooming is happening
    bool isResettingOrientation = false;  // Flag to trigger the orientation reset
    float zoomSpeed = 0.05;        // Speed of the zoom
    float resetSpeed = 0.05;  // Speed of the smooth transition (between 0 and 1)
    
    // Variables for naming stars
        
    bool isNamingStar = false;  // Whether we are naming a star
    std::string currentInput = "";  // Current input being typed
    int namingStarIndex = -1;  // Index of the star being named
    
    bool showSaveMessage = false;
    unsigned long long saveMessageStartTime = 0;
    
    std::vector<Meteor> meteors;  // List of meteors
    void addMeteor();
 
    
    ofApp();
    
    
};
