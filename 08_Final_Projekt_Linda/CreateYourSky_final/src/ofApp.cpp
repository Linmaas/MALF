#include "ofApp.h"
#include "ofxPostProcessing.h"


ofApp::ofApp() : constellation(200.0f, 10) {
  
}

//--------------------------------------------------------------
void ofApp::setup(){
    
    startScreen.setup();
    sound.setup();
    postProcessing.createPass<BloomPass>();
    

    ofBackground(0x21124E);
    cam.setupPerspective();
    cam.setPosition(0, 0, 600);
    
    cam.setDrag(0.1);
   
    initialCameraPosition = cam.getPosition();
    initialCameraOrientation = cam.getOrientationQuat();
    
    postProcessing.init(ofGetWidth(), ofGetHeight());
    postProcessing.createPass<BloomPass>()->setEnabled(true);
    
    // Generate background stars with random positions and sizes (these are not saved)
       for (int i = 0; i < 500; i++) {
           float x = ofRandom(-5000, 5000);
           float y = ofRandom(-5000, 5000);
           float z = ofRandom(-5000, 5000);
           
           // Create background stars with no name and random sizes
           backgroundStars.push_back(Star(ofVec3f(x, y, z), ""));  // No name for background stars
       }
    
    loadStars();
    
    constellation = Constellation(200.0f, 5000000);
}

//--------------------------------------------------------------
void ofApp::update(){
    sound.update();
    
    // Only update stars and constellations if the start screen is not active
    if (!startScreen.isActive()) {
        if (isOrbiting) {
            float orbitSpeedX = 0.02f;
            float orbitSpeedY = 0.01f;
            float orbitRadius = 300.0f;

            orbitAngleX += orbitSpeedX;
            orbitAngleY += orbitSpeedY;

            cam.orbit(orbitAngleX, orbitAngleY, orbitRadius, orbitCenter);
        }
        
        
            for (Star& star : backgroundStars) {
                star.update();
            }

        for (Star& star : stars) {
            star.update();
        }

        constellation.update(stars);
    }
    
    if (isZooming) {
        ofVec3f currentPos = cam.getPosition();
        cam.setPosition(currentPos.interpolate(cameraTargetPosition, zoomSpeed));
        if (currentPos.distance(cameraTargetPosition) < 1.0) {
            isZooming = false;
        }
    }
    
    for (Meteor& meteor : meteors) {
                meteor.update();
            }

            // Add a new meteor randomly
            if (ofRandom(1.0) < 0.002) {  // Random chance to add a meteor
                addMeteor();
            }

            // Remove meteors that go off-screen
            meteors.erase(
                std::remove_if(meteors.begin(), meteors.end(), [](Meteor& meteor) {
                    return meteor.isOffScreen();
                }),
                meteors.end()
            );
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (startScreen.isActive()) {
        startScreen.draw();
        return;
    }

    postProcessing.begin(cam);

    ofSetHexColor(0xFF8765);
    ofDrawSphere(0,0,0, 100);
    
    
       for (Star& star : backgroundStars) {
           star.draw();
       }

    for (Star& star : stars) {
        star.draw();
    }

    constellation.draw();
    
    for (Meteor& meteor : meteors) {
            meteor.draw();
        }
    
    postProcessing.end();

    ofSetColor(255);
    ofDrawBitmapString("LEFT CLICK: rotate | SCROLL: zoom | MIDDLE CLICK: pan", 20, ofGetHeight() - 80);
    ofDrawBitmapString("SPACE + CLICK: orbit star | AGAIN: exit orbit mode", 20, ofGetHeight() - 60);
    ofDrawBitmapString("R: reset camera to center | RIGHT CLICK: add star", 20, ofGetHeight() - 40);
    ofDrawBitmapString("SPACE + S: save universe", 20, ofGetHeight() - 20);

    if (isNamingStar) {
        ofSetHexColor(0xA6D7FF);
        ofDrawBitmapString("naming star: " + currentInput, 20, 20);
    }
    
    
        if (showSaveMessage) {
            unsigned long long currentTime = ofGetElapsedTimeMillis();
            if (currentTime - saveMessageStartTime < 3000) {  // Show message for 3 seconds
                
                ofDrawBitmapString("Universe was saved!", ofGetWidth() - 200, 30);
            } else {
                showSaveMessage = false;
            }
        }
}

//--------------------------------------------------------------

void ofApp::zoomToStar(ofVec3f starPosition) {
       
       cam.setTarget(starPosition);
    // Calculate the direction vector from the camera to the star
       ofVec3f cameraPos = cam.getPosition();
       ofVec3f direction = starPosition - cameraPos;
       direction.normalize();  // Normalize the direction vector

       
       float zoomDistance = 200.0;

      
       cameraTargetPosition = starPosition - direction * zoomDistance;

       isZooming = true;
}
//--------------------------------------------------------------


void ofApp::resetCamera() {
    cam.setPosition(initialCameraPosition);
    cam.setOrientation(initialCameraOrientation);
    std::cout << "Camera reset to original position." << std::endl;
}

//--------------------------------------------------------------
void ofApp::addMeteor() {
    // Generate random position and velocity for the meteor
    ofVec3f position(ofRandom(-5000, 5000), ofRandom(-5000, 5000), ofRandom(-5000, 5000));
    ofVec3f velocity(ofRandom(-1, 1), ofRandom(-1, 1), ofRandom(-1, 1));
    float size = ofRandom(5, 10);  // Random size for the meteor

    meteors.push_back(Meteor(position, velocity, size));
}
    
    //--------------------------------------------------------------

void ofApp::saveStars() {
    ofJson json;

    // Loop through all stars and save their data
    for (const Star& star : stars) {
        ofJson starJson;
        starJson["position"] = { star.position.x, star.position.y, star.position.z };
        starJson["name"] = star.name;
        starJson["targetSize"] = star.targetSize;

        json.push_back(starJson);  // Add each star's data to the JSON array
    }

    // Save the JSON data to a file
    ofSaveJson("stars.json", json);
    std::cout << "Stars saved to stars.json" << std::endl;
    
    showSaveMessage = true;
    saveMessageStartTime = ofGetElapsedTimeMillis();
}

//--------------------------------------------------------------

void ofApp::loadStars() {
    // Clear any existing stars
    stars.clear();

    // Load the JSON data from the file
    ofJson json = ofLoadJson("stars.json");

    // Loop through the JSON array and recreate stars
    for (const auto& starJson : json) {
        ofVec3f position(starJson["position"][0], starJson["position"][1], starJson["position"][2]);
        std::string name = starJson["name"];
        float targetSize = starJson["targetSize"];

        // Recreate the star with the saved data
        stars.push_back(Star(position, name));
    }

    std::cout << "Stars loaded from stars.json" << std::endl;
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (startScreen.isActive()) {
            startScreen.hide();
            return;
        }
    
    if (isNamingStar) {
            if (key == OF_KEY_RETURN) {
                
                if (!currentInput.empty()) {
                    stars[namingStarIndex].name = currentInput;
                }
                
                isNamingStar = false;
                currentInput = "";
            }
            else if (key == OF_KEY_BACKSPACE) {
                if (!currentInput.empty()) {
                    currentInput.pop_back();
                }
            }
            else {
               
                currentInput += (char)key;
            }
        }
        else if (key == 'r' || key == 'R') {
            resetCamera();
        }
    
    if (key == ' ') {
            isSpacePressed = true;
        }
    
    if (key == 's' || key == 'S') {
        isSKeyPressed = true;
    }
    
    if (isSKeyPressed && isSpacePressed) {
           saveStars();
       }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

    if (key == ' ') {
            isSpacePressed = false;
        }
    
    if (key == 's' || key == 'S') {
           isSKeyPressed = false;
       }
}


//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    
    
    if (button == OF_MOUSE_BUTTON_LEFT && isSpacePressed) {
          ofVec2f mousePos(x, y);

          float closestDistance = std::numeric_limits<float>::max();
          int closestStarIndex = -1;
          float clickRadius = 50.0;

          // Iterate through all stars and check their screen positions
          for (int i = 0; i < stars.size(); i++) {
              ofVec3f starScreenPos = cam.worldToScreen(stars[i].position);
              float distance = mousePos.distance(ofVec2f(starScreenPos.x, starScreenPos.y));

              // Check if the mouse click is within the radius of the star's screen position
              if (distance < closestDistance && distance < clickRadius) {
                  closestDistance = distance;
                  closestStarIndex = i;
              }
            }

           
            if (closestStarIndex != -1) {
                std::cout << "Zooming to star " << closestStarIndex << std::endl;
                zoomToStar(stars[closestStarIndex].position);
            }
        
        
               if (closestStarIndex != -1) {
                   ofVec3f starPosition = stars[closestStarIndex].position;
                   std::cout << "Zooming to star " << closestStarIndex << std::endl;
                   zoomToStar(starPosition);  // Zoom to the star

                   // Start orbiting around the clicked star
                   orbitCenter = starPosition;
                   isOrbiting = true;
                   orbitAngleX = 0.0f;
                   orbitAngleY = 0.0f;
               } else {
                 
                   if (isOrbiting) {
                       isOrbiting = false;
                       std::cout << "Stopped orbiting." << std::endl;
                   }
               }
        }
    
    if (button == OF_MOUSE_BUTTON_RIGHT) {
        sound.playStarCreationSound();
        
            if (isNamingStar && namingStarIndex >= 0 && namingStarIndex < stars.size()) {
                if (stars[namingStarIndex].name.empty()) {
                    stars[namingStarIndex].name = "Star " + std::to_string(namingStarIndex + 1);
                }
                isNamingStar = false;
            }

            
            ofVec3f starPos = cam.screenToWorld(ofVec3f(x, y, 0));
            stars.push_back(Star(starPos, ""));  // Target size is 5.0f

            
            isNamingStar = true;
            namingStarIndex = stars.size() - 1;
            currentInput = "";
        
        }
       
}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
