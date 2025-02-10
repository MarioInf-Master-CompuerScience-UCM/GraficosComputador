#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(0, 0, 0);
	ofSetWindowTitle("Semana 0 - Espiral");
	ofSetFrameRate(60);
    initialAngle=0;
    incrementAngleSpire=3;
    stepResolution=10;
    centerX=ofGetWidth()/2;
    centerY=ofGetHeight()/2;
}

//--------------------------------------------------------------
void ofApp::update(){
    if(initialAngle>=360){
        initialAngle=1;
    }else{
        initialAngle++;
    }

    if(centerY>=ofGetHeight()+ incrementAngleSpire){
        centerY=0 - ofGetHeight()/5;
    }else{
        centerY++;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

	int radius = 10;
	int perX=0, perY=0;
    int centerX_circle1=centerX, centerY_circle1=centerY;
    int centerX_circle2=0, centerY_circle2=0;

    ofDrawBitmapString( ofToString(ofGetFrameRate()), 20, 20);
    ofFill();
	ofSetColor(255,130,0);
	ofBeginShape();
		for (int i=0 ; i<=360 ; i=i+10){
			perX = centerX_circle1 + radius * sin( ofDegToRad(i));
			perY = centerY_circle1 + radius * cos( ofDegToRad(i));
    		ofVertex(perX, perY);
		}
	ofEndShape();


    ofNoFill();
	ofSetColor(255,130,0);
	ofBeginShape();
		for (int i=initialAngle ; i<=initialAngle+360 ; i=i+stepResolution){
			perX = centerX_circle1 + radius * sin( ofDegToRad(i));
			perY = centerY_circle1 + radius * cos( ofDegToRad(i));
    		ofVertex(perX, perY);
            radius = radius+incrementAngleSpire;
		}
	ofEndShape();
	
    ofFill();
	ofSetColor(255,130,0);
	ofBeginShape();
        centerX_circle2 = perX;
        centerY_circle2 = perY;
        radius=10;
		for (int i=0 ; i<=360 ; i=i+10){
			perX = centerX_circle2 + radius * sin( ofDegToRad(i));
			perY = centerY_circle2 + radius * cos( ofDegToRad(i));
    		ofVertex(perX, perY);
		}
	ofEndShape();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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