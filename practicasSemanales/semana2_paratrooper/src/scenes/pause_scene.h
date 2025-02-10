#pragma once
#include <string>
#include "ofMain.h"
using namespace std;


class Pause_scene {
	public:

		const string nameScene="pause_scene";

		void setupScene();
		void drawScene();
		void updateScene();
};
