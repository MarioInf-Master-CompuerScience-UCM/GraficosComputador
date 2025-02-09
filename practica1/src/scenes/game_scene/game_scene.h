#pragma once
#include <string>
#include <list>
#include "ofMain.h"
#include "../../gameObjects/gameObject.h"
#include "../../gameObjects/abstractEnemy/abstractEnemy.h"
#include "../../gameObjects/abstractEnemy/RectangleEnemy/rectangleEnemy.h"
#include "../../gameObjects/player/Player.h"
#include "../abstractScene.h"
#include "../../builders/builderEnemies/BuilderEnemies.h"
#include "game_colorPalette.h"
#include "../home/Home.h"
using namespace std;

class Game_scene: public AbstractScene {
	private:
		unsigned limitGameUp;
		unsigned limitGameDown;
		unsigned limitGameLeft;
		unsigned limitGameRight;

		int score;

        Player playerUp;
        Player playerDown;

		BuilderEnemies spawner{ BuilderEnemies(ofColor::blueViolet, ofColor::yellowGreen, ofGetHeight()*0.2, ofGetHeight()*0.8, 0, ofGetWidth()) };
		vector<GameObject*> bulletList;
		vector<GameObject*> enemyList;
		Home home;

		bool shootingPlayerUp;
		int lastPressedShootUp;

		bool shootingPlayerDown;
		int lastPressedShootDown;

		int lastEnemyWave;

		const int boundsMargin{ 20 };
		const int nMaxEnemy{ 5 };

		ofTrueTypeFont uiFont;

	public:
		const string nameScene{ "Game_scene" };

		ofEvent<int> onDeath;

		virtual void setupScene() override;
		virtual void drawScene() override;
		virtual void updateScene() override;

		virtual void loadSounds() override;

        void drawPlayers();
        void drawUI();

		unsigned getLimitGameUp();
		void setLimitGameUp(unsigned value);
		unsigned getLimitGameDown();
		void setLimitGameDown(unsigned value);
		unsigned getLimitGameLeft();
		void setLimitGameLeft(unsigned value);
		unsigned getLimitGameRight();
		void setLimitGameRight(unsigned value);

		int getScore();

		bool checkOutOfBounds(GameObject* object);

		void updateGameObjectVector(vector<GameObject*>* objList);
		void drawGameObjectVector(vector<GameObject*>* objList);

		void drawBackground();

};
