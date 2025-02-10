#include "ofApp.h"


	//Setup function
//*****************************************************
void ofApp::setup(){

	ofBackground(0, 0, 0);
	ofSetWindowTitle("Semana 3 - Dron");
	ofSetFrameRate(60);

	this->dronWidth = 100;
	this->dronHeight = 100;
	this->wingWidth = 40;
	this->wingHeight = 5;
	this->rotation = 0;

	return;
}


	//Update function
//*****************************************************
void ofApp::update(){

	this->rotation ++;
	if(this->rotation>=360){
		this->rotation = 0;
	}

	return;
}


	//Draw function
//*****************************************************
void ofApp::draw(){

	ofNoFill();

	ofPushMatrix();

		ofSetColor(255, 255, 255);
		ofTranslate(ofGetMouseX()-this->dronWidth/2, ofGetMouseY()-this->dronHeight/2);
		ofDrawRectangle(0, 0, this->dronWidth, this->dronHeight);
		ofSetColor(255, 0, 0);

		//Dibujamos ala superior izquierda
		ofPushMatrix();
			ofTranslate(0, 0);
			ofRotateDeg(this->rotation, 0, 0, 1);
			ofTranslate(-this->wingWidth/2, -this->wingHeight/2);
			ofDrawRectangle(0, 0, this->wingWidth, this->wingHeight);	
		ofPopMatrix();

		//Dibujamos ala superior derecha
		ofPushMatrix();
			ofTranslate(this->dronWidth, 0);
			ofRotateDeg(this->rotation, 0, 0, 1);
			ofTranslate(-this->wingWidth/2, -this->wingHeight/2);
			ofDrawRectangle(0 , 0, this->wingWidth, this->wingHeight);
		ofPopMatrix();

		//Dibujamos ala inferior izquierda
		ofPushMatrix();
			ofTranslate(0, this->dronHeight);
			ofRotateDeg(this->rotation, 0, 0, 1);
			ofTranslate(-this->wingWidth/2, -this->wingHeight/2);
			ofDrawRectangle(0 , 0, this->wingWidth, this->wingHeight);
		ofPopMatrix();
 
		//Dibujamos ala inferior derecha
		ofPushMatrix();
			ofTranslate(this->dronWidth, this->dronHeight);
			ofRotateDeg(this->rotation, 0, 0, 1);
			ofTranslate(-this->wingWidth/2, -this->wingHeight/2);
			ofDrawRectangle(0 , 0, this->wingWidth, this->wingHeight);
		ofPopMatrix();
 
	ofPopMatrix();
	
	



	return;
}

