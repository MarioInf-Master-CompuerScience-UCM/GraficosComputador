#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		void drawScriptsTest();
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
		void drawPlayer();


		int playerInitPos_X, playerInitPos_Y;
		int playerPos_X, playerPos_Y;
		int playerSpeed;
		int playerSpriteTemp;
		enum direction { Up, Down, Left, Right }; 
			direction playerDirecion;

		string imageURL = "linkSprites.png";
		ofImage linkSprites;
		int widthSprite = 20;
		int heightSprite = 25;

		const int sprite_Up_X = 60,	sprite_Up_Y = 0;
		const int sprite_RunUp1_X = 0, 		sprite_RunUp1_Y = 120;
		const int sprite_RunUp2_X = 30, 	sprite_RunUp2_Y = 120;
		const int sprite_RunUp3_X = 60, 	sprite_RunUp3_Y = 120;
		const int sprite_RunUp4_X = 90, 	sprite_RunUp4_Y = 120;
		const int sprite_RunUp5_X = 120, 	sprite_RunUp5_Y = 120;
		const int sprite_RunUp6_X = 150, 	sprite_RunUp6_Y = 120;
		const int spritesRunUpList[6][2] = {	{sprite_RunUp1_X, sprite_RunUp1_Y}, 
												{sprite_RunUp2_X, sprite_RunUp2_Y},
												{sprite_RunUp3_X, sprite_RunUp3_Y},
												{sprite_RunUp4_X, sprite_RunUp4_Y},
												{sprite_RunUp5_X, sprite_RunUp5_Y},
												{sprite_RunUp6_X, sprite_RunUp6_Y}};
		const int sprite_JumpUp_X = 90, 		sprite_JumpUp_Y = 120;


		const int sprite_Down_X = 30,	sprite_Down_Y = 0;
		const int sprite_RunDown1_X = 0, 	sprite_RunDown1_Y = 30;
		const int sprite_RunDown2_X = 30, 	sprite_RunDown2_Y = 30;
		const int sprite_RunDown3_X = 60, 	sprite_RunDown3_Y = 30;
		const int sprite_RunDown4_X = 90, 	sprite_RunDown4_Y = 30;
		const int sprite_RunDown5_X = 120, 	sprite_RunDown5_Y = 30;
		const int sprite_RunDown6_X = 150, 	sprite_RunDown6_Y = 30;
		const int spritesRunDownList[6][2] = {	{sprite_RunDown1_X, sprite_RunDown1_Y}, 
												{sprite_RunDown2_X, sprite_RunDown2_Y},
												{sprite_RunDown3_X, sprite_RunDown3_Y},
												{sprite_RunDown4_X, sprite_RunDown4_Y},
												{sprite_RunDown5_X, sprite_RunDown5_Y},
												{sprite_RunDown6_X, sprite_RunDown6_Y}};
		const int sprite_JumpDown_X = 90, 		sprite_JumpDown_Y = 30;


		const int sprite_Left_X = 150,	sprite_Left_Y = 0;
		const int sprite_RunLeft1_X = 240, sprite_RunLeft1_Y = 30;
		const int sprite_RunLeft2_X = 270, sprite_RunLeft2_Y = 30;
		const int sprite_RunLeft3_X = 300, sprite_RunLeft3_Y = 30;
		const int sprite_RunLeft4_X = 330, sprite_RunLeft4_Y = 30;
		const int sprite_RunLeft5_X = 360, sprite_RunLeft5_Y = 30;
		const int sprite_RunLeft6_X = 390, sprite_RunLeft6_Y = 30;
		const int spritesRunLeftList[6][2] = {	{sprite_RunLeft1_X, sprite_RunLeft1_Y}, 
												{sprite_RunLeft2_X, sprite_RunLeft2_Y},
												{sprite_RunLeft3_X, sprite_RunLeft3_Y},
												{sprite_RunLeft4_X, sprite_RunLeft4_Y},
												{sprite_RunLeft5_X, sprite_RunLeft5_Y},
												{sprite_RunLeft6_X, sprite_RunLeft6_Y}};
		const int sprite_JumpLeft_X = 330, 		sprite_JumpLeft_Y = 30;


		const int sprite_RunRight1_X = 240, sprite_RunRight1_Y = 120;
		const int sprite_RunRight2_X = 270, sprite_RunRight2_Y = 120;
		const int sprite_RunRight3_X = 300, sprite_RunRight3_Y = 120;
		const int sprite_RunRight4_X = 330, sprite_RunRight4_Y = 120;
		const int sprite_RunRight5_X = 360, sprite_RunRight5_Y = 120;
		const int sprite_RunRight6_X = 390, sprite_RunRight6_Y = 120;
		const int spritesRunRightList[6][2] = {	{sprite_RunRight1_X, sprite_RunRight1_Y}, 
												{sprite_RunRight2_X, sprite_RunRight2_Y},
												{sprite_RunRight3_X, sprite_RunRight3_Y},
												{sprite_RunRight4_X, sprite_RunRight4_Y},
												{sprite_RunRight5_X, sprite_RunRight5_Y},
												{sprite_RunRight6_X, sprite_RunRight6_Y}};
		const int sprite_JumpRight_X = 270, 	sprite_JumpRight_Y = 120;




		
};