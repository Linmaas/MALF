#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	name = "Anna";
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

	
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	// ofBackground(255); // Clear background with white color
		
	for (int i = 0; i < name.size(); ++i) {

		char character = name[i];

		int randomIndex = characterFontIndices[i];						// Get the font for this character

		//int randomSize = characterSizes[i];

		ofTrueTypeFont& font = fonts[randomIndex];
		
		
		font.drawString(ofToString(character), x, y);


		
		x += font.stringWidth(ofToString(character)) + 20;		// Move x position to the right for the next character
																		// Adjust as needed based on font size and spacing
		
		
	}

	// Reset x position for the next frame (if needed)
	 x = ofGetWidth()/2 - 250;
	 y = ofGetHeight()/2;


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