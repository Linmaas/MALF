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
	name = currentText;
	std::cout << name << endl;

	// Load fonts with a consistent size (90 in this case)
	ofTrueTypeFont font1, font2, font3, font4, font5, font6, font7;
	font1.load("Pilowlava-Regular.otf", 150);
	font2.load("Fungal-Grow600Thickness1000.ttf", 150);
	font3.load("Lithops-Regular.ttf", 150);
	font4.load("Mess-Light_web.ttf", 150);
	font5.load("Ouvrieres-exploratrices.ttf", 150);
	font6.load("Ouvrieres-rassasiees.ttf", 150);
	font7.load("PicNic-Regular.otf", 150);
	


	fonts.push_back(font1);
	fonts.push_back(font2);
	fonts.push_back(font3);
	fonts.push_back(font4);
	fonts.push_back(font5);
	fonts.push_back(font6);
	fonts.push_back(font7);

	for (int i = 0; i < name.size(); ++i) {									
		int randomIndex = static_cast<int>(ofRandom(0, fonts.size()));			// Select a random font for each character in 'name' and store them
		characterFontIndices.push_back(randomIndex);

	}
    
        x = 100;
        y = ofGetHeight() / 2;
	
}

//--------------------------------------------------------------
void ofApp::update(){
    // Check if the current text has changed
    if (currentText != textInput1.get()) {
        currentText = textInput1.get();
        name = currentText;  // Update the name to be drawn
        updateFontIndices(); // Update font indices for new name
    }
}

//--------------------------------------------------------------

void ofApp::updateFontIndices() {
    characterFontIndices.clear(); // Clear previous indices
    for (size_t i = 0; i < name.size(); ++i) {
        int randomIndex = static_cast<int>(ofRandom(0, fonts.size()));
        characterFontIndices.push_back(randomIndex);
    }
}



//--------------------------------------------------------------
void ofApp::draw(){
    
    
    

    gui.draw();
     int localX = x; // Start position for drawing name

     for (size_t i = 0; i < name.size(); ++i) {
         char character = name[i];
         ofTrueTypeFont& font = fonts[characterFontIndices[i]];
         font.drawString(ofToString(character), localX, y);
         localX += font.stringWidth(ofToString(character)) + 20; // Increment x position
     }
       
       
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
