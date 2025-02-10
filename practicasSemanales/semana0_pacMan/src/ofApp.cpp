#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(0, 0, 0);
	ofSetWindowTitle("Semana 0 - PacMan");
	ofSetFrameRate(60);

	this->pacMan.pmInit(ofGetWidth()/2, ofGetHeight()/2);
}

//--------------------------------------------------------------
void ofApp::update(){
	this->pacMan.pmUpdate();
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(255, 255, 255);
	ofDrawBitmapString("fps: " + ofToString(ofGetFrameRate()), 20, 20);
	this->pacMan.pmDraw();



}









//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
	
	if (key == 'd' && pacMan.posX < ofGetWidth() - pacMan.radius){
		pacMan.MoveRight();
	}
	else if (key == 'a' && pacMan.posX > pacMan.radius){
		pacMan.MoveLeft();
	}
	else if (key == 'w' && pacMan.posY > pacMan.radius){
		pacMan.MoveUp();
	}
	else if (key == 's' && pacMan.posY < ofGetHeight() - pacMan.radius){
		pacMan.MoveDown();
	}


	return;
}





//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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