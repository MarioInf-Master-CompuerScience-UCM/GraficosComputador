#pragma once
#include <string>
#include "ofMain.h"
#include "../abstractScene.h"
#include "game_colorPalette.h"
using namespace std;


class End_scene : public AbstractScene {
	public:

		const string nameScene="end_scene";

		virtual void setupScene() override;
		virtual void drawScene() override;
		virtual void updateScene() override;

		virtual void loadSounds() override;

		void drawBackground();

		ofTrueTypeFont gameOverFont;
		ofTrueTypeFont gameOverBgFont;
		ofTrueTypeFont subtitleFont;

		int score;
		void setScore(int value);

		ofEvent<int> onRestart;
};