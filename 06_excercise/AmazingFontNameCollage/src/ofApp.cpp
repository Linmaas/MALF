#include "ofApp.h"




//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup("Create Letter Art!");
    
  
    
        gui.setPosition(ofPoint(100, 100));
        gui.setDefaultWidth(300); // Wider elements for better interaction
        gui.setDefaultHeight(18);
        gui.setDefaultBorderColor(ofColor(255, 100, 100)); // Customize border color
    
        gui.setBackgroundColor(ofColor(50, 50, 50)); // Dark grey background
        ofxGuiSetHeaderColor(ofColor(150, 150, 250)); // Light blue header
        ofxGuiSetFillColor(ofColor(200, 200, 250)); // Light blue fill
        

     // Setup text fields and bind to ofParameter<std::string>
     nameInput1.setup(textInput1.set("Write your Name", ""));
     //nameInput2.setup(textInput2.set("Name Input 2", ""));

     // Add parameters to the panel
     gui.add(textInput1);
     //gui.add(textInput2);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
       gui.draw();
       
       // Clear the array
       memset(nameArray1, 0, sizeof(nameArray1));

       // Get the string and copy up to MAX_NAME_LENGTH - 1 characters to ensure null termination
       std::string currentText = textInput1.get();
       size_t copyLength = std::min(currentText.size(), static_cast<size_t>(MAX_NAME_LENGTH - 1));
       strncpy(nameArray1, currentText.c_str(), copyLength);

       // Optionally, display the content of the array for debugging
       ofDrawBitmapString("Debugging Array of Letters: " + std::string(nameArray1), 100, 200);
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

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

// this is a test 
