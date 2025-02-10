#pragma once
#include <string>
#include "ofMain.h"
#include "../gameObjects/player/Player.h"
using namespace std;

class Game_scene {
	public:

		const string nameScene="Game_scene";

		Player player;
		
		void setupScene();
		void drawScene();
		void updateScene();
};
