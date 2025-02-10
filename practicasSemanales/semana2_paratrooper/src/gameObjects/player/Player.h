#pragma once
#include "ofMain.h"

class Player {
	public:

		const int color1_R = 253, color1_G = 255, color1_B = 0;
		const int color2_R = 0, color2_G = 0, color2_B = 0;
		const int speed = 5;
		const int speedMouse = 5;
		const int radius = 80;
		const int radiusEye = radius/10;
		const int maxAngleMouse = 60;


		int initialPosX, initialPosY;
		int posX, posY;

		void init(int nInitialCenterX, int nInitialCenterY);
		void draw();
		void update();
		void moveLeft();
		void moveRight();
};
