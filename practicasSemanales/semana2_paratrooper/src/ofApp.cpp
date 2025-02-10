#include "ofApp.h"


	//Setup function
//*****************************************************
void ofApp::setup(){

	ofBackground(0, 0, 0);
	ofSetWindowTitle("Semana 2 - Circulo");
	ofSetFrameRate(60);
	
	ControllerScenes controller = mainMenu;
	this->mainMenu_scene.setupScene();
	this->game_scene.setupScene();
	this->pause_scene.setupScene();
	this->score_scene.setupScene();

	//ofAddListener(redCircle.clickedInside,this,&ofApp::onMouseInCircle);
	return;
}


	//Update function
//*****************************************************
void ofApp::update(){
	return;
}


	//Draw function
//*****************************************************
void ofApp::draw(){

	if(this->controller==mainMenu){
		this->mainMenu_scene.drawScene();
	}else if(this->controller==game){
		this->game_scene.drawScene();
	}else if(this->controller==pause){
		this->pause_scene.drawScene();
	}else if(this->controller==score){
		this->score_scene.drawScene();
	}

	return;
}



void ofApp::changeExcene_eventFunction(){

}
