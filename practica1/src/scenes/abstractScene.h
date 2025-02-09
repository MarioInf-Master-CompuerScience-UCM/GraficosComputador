#pragma once
#include <string>
#include "ofMain.h"
#include "../gameObjects/gameObject.h"


using namespace std;

class AbstractScene {
	
	private: 

	public:
		vector<ofSoundPlayer*> soundPlayer;

		virtual void setupScene();
		virtual void drawScene();
		virtual void updateScene();

		virtual void loadSounds();


	public:


};
