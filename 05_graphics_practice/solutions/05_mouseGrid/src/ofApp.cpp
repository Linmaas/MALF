#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	//float rectSize = 5 * dist;  // Size of each rectangle
	int spacing = 10;

	
	
	for (int i = 0; i < ofGetWidth(); i += (maxRectSize + spacing)) {
		
		for (int j = 0; j < ofGetHeight(); j += (maxRectSize + spacing)) {
			
			float dist = ofDist(mouseXPos, mouseYPos, i, j);
			float rectSize = ofMap(dist, 0, ofGetWidth(), maxRectSize, minRectSize, true);
			//int xPosRect = i * (rectSize + spacing);
			//int yPosRect = j * (rectSize + spacing);

			ofSetColor(0, 0, 0);
			ofDrawRectangle(i, j, rectSize, rectSize);
		}
	}
	
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	mouseXPos = x;
	mouseYPos = y;

	//float dist = ofDist(x, y, xPosRect, yPosRect) / 1000;
	//float rectSize = 25 * dist;
	//std::cout << dist << std::endl;
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
