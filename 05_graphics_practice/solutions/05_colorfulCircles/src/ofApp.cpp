#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

	

}

//--------------------------------------------------------------
void ofApp::draw(){
	//drawCircle(500);

	for (int i = 1; i <= 10; i++) {

		color = 255 - i * 10;
		int maxRadius = 500;
		int decrement = 50;

		int radius = maxRadius - i * decrement;
		drawCircle(radius);


	}
}

void ofApp::drawCircle(int radius) {

	
	int centerX = ofGetWidth() / 2;
	int centerY = ofGetHeight() / 2;
	
	ofSetColor(0, 0, 0);
	//ofNoFill();
	ofSetLineWidth(5);
	
	ofSetColor(255, color, color);
	ofSetCircleResolution(100);
	ofDrawCircle(centerX, centerY, radius);

	
	
	
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
