#pragma once

#include "ofxGui.h"
#include "ofMain.h"
#include "gameObjects/player/Player.h"
#include "scenes/game_scene.h"
#include "scenes/mainMenu_scene.h"
#include "scenes/pause_scene.h"
#include "scenes/score_scene.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		void changeExcene_eventFunction();

		
		MainMenu_scene mainMenu_scene;
		Game_scene game_scene;
		Pause_scene pause_scene;
		Score_scene score_scene;

		enum ControllerScenes {
			mainMenu,
			game,
			pause,
			score
		};
		ControllerScenes controller;


		
};
