#pragma once

//#include "ofxGui.h"
#include "ofMain.h"
#include "gameObjects/player/Player.h"
#include "scenes/game_scene/game_scene.h"
#include "scenes/mainMenu_scene/mainMenu_scene.h"
#include "scenes/end_scene/end_scene.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		void changeScene_eventFunction(int & targetScene);
		
		MainMenu_scene mainMenu_scene;
		Game_scene game_scene;
		End_scene end_scene;

		enum ControllerScenes {
			mainMenu,		// Menú principal
			game,			// Juego
			endscreen		// Game over
		};

		ControllerScenes controller;
		
};
