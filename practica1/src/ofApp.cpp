#include "ofApp.h"


	//Setup function
//*****************************************************
void ofApp::setup(){

	ofSetWindowTitle("Defend Death Star");
	ofSetFrameRate(60);
	
	this->controller = mainMenu;

	this->mainMenu_scene.setupScene();

	// Escuchar eventos de cambio de escena	
	ofAddListener(mainMenu_scene.onStartGame, this, &ofApp::changeScene_eventFunction);
	ofAddListener(game_scene.onDeath, this, &ofApp::changeScene_eventFunction);
	ofAddListener(end_scene.onRestart, this, &ofApp::changeScene_eventFunction);

	return;
}


	//Update function
//*****************************************************
void ofApp::update(){

    if(this->controller == mainMenu){
        this->mainMenu_scene.updateScene();
    }else if(this->controller == game){
        this->game_scene.updateScene();
    }else if(this->controller == endscreen){
        this->end_scene.updateScene();
    }

	return;
}


	//Draw function
//*****************************************************
void ofApp::draw(){

	if(this->controller == mainMenu){
		this->mainMenu_scene.drawScene();
	}else if(this->controller == game){
		this->game_scene.drawScene();
	}else if(this->controller == endscreen){
		this->end_scene.drawScene();
	}

	return;
}


void ofApp::changeScene_eventFunction(int & targetScene){
	this->controller = (ControllerScenes) targetScene;

	switch (this->controller) {
	case mainMenu:
		this->mainMenu_scene.setupScene();
		break;
	case game:
		this->game_scene.setupScene();
		break;
	case endscreen:
		this->end_scene.setupScene();
		this->end_scene.setScore(this->game_scene.getScore());

		break;
	default:
		break;
	}
}
