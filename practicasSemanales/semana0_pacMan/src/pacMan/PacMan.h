#pragma once

#include "ofMain.h"

class PacMan {
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
		int posEyeX, posEyeY;
		int angleDirection;
		int stepResolutionPer;
		int angleMouse;
		bool stateMouse;

		void pmInit(int nInitialCenterX, int nInitialCenterY);
		void pmUpdate();
		void pmDraw();
		void pmDrawLeft();
		void pmDrawRight();
		void pmDrawUp();
		void pmDrawDown();


		void MoveLeft();
		void MoveRight();
		void MoveUp();
		void MoveDown();
};
