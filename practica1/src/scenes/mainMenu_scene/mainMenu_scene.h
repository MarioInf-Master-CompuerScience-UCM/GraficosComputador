#pragma once
#include <string>
#include "ofMath.h"
#include "ofMain.h"
#include "ofxGui.h"
#include "../abstractScene.h"
#include "game_colorPalette.h"
using namespace std;

//typedef void (ofApp::*changeScene)();

class MainMenu_scene : public AbstractScene {
	public:

		const string nameScene = "mainMenu_scene";

		ofEvent<int> onStartGame;

		virtual void setupScene() override;
		virtual void drawScene() override;
		virtual void updateScene() override;

		virtual void loadSounds() override;

		void drawBackground();
		void drawTitle();

		string title;
		ofTrueTypeFont titleFont;
		ofTrueTypeFont startTextFont;
};
