#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	rotationAngle = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
	rotationAngle += 0.1;
	if (rotationAngle > 360) {
		rotationAngle -= 360;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	ofRotateDeg(rotationAngle);

	int numCircles = 10;
	int maxRadius = 70;
	int decrement = 5;

	
	
	float angleStep = TWO_PI / numCircles;

	for (int i = 1; i <= 10; i++) {

		color = 255 - i * 10;

		int radius = maxRadius - i * decrement;

		float angle = i * angleStep;
		float x =  cos(angle) * 400;
		float y =  sin(angle) * 400;
		
		drawCircles(x, y, radius);
		
	}

	ofPopMatrix();
}



void ofApp::drawCircles(float x, float y, float radius) {

	

	ofSetColor(0, 0, 0);
	//ofNoFill();
	ofSetLineWidth(5);

	ofSetColor(255, color, color);
	ofSetCircleResolution(100);
	ofDrawCircle(x, y, radius);

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
