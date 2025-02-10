#include "ofApp.h"


	//Setup function
//*****************************************************
void ofApp::setup(){

	ofBackground(0, 0, 0);
	ofSetWindowTitle("Semana 4 - Super Mario");
	ofSetFrameRate(60);

	this->playerInitPos_X = ofGetWidth()/2, playerInitPos_Y = ofGetHeight()/2;
	this->playerPos_X = playerInitPos_X, playerPos_Y = playerInitPos_Y;
	this->playerSpeed=3;
	this->playerSpriteTemp=0;
	this->linkSprites.load(this->imageURL);
	this->playerDirecion = Left;
	ofGetSystemTimeMillis();

	return;
}


	//Update function
//*****************************************************
void ofApp::update(){

	bool move = false;

	if(ofGetKeyPressed('w') ){
		move = true;
		if(this->playerDirecion != Up){
			this->playerDirecion = Up;
			this->playerSpriteTemp = 0;
		}else{
			if( this->playerSpriteTemp >= (int)( sizeof(this->spritesRunUpList) / sizeof(spritesRunUpList[0]) )-1 ){
				this->playerSpriteTemp = 0;
			}else{
				this->playerSpriteTemp++;
			}
		}
		moveUp();
	}
	if(ofGetKeyPressed('s') ){
		move = true;
		if(this->playerDirecion != Down){
			this->playerDirecion = Down;
			this->playerSpriteTemp = 0;
		}else{
			if( this->playerSpriteTemp >= (int)( sizeof(this->spritesRunDownList) / sizeof(spritesRunDownList[0]) )-1 ){
				this->playerSpriteTemp = 0;
			}else{
				this->playerSpriteTemp++;
			}
		}
		moveDown();
	}
	if(ofGetKeyPressed('a') ){
		move = true;
		if(this->playerDirecion != Left){
			this->playerDirecion = Left;
			this->playerSpriteTemp = 0;
		}else{
			if( this->playerSpriteTemp >= (int)( sizeof(this->spritesRunLeftList) / sizeof(spritesRunLeftList[0]) )-1 ){
				this->playerSpriteTemp = 0;
			}else{
				this->playerSpriteTemp++;
			}
		}
		moveLeft();
	}
	if(ofGetKeyPressed('d') ){
		move = true;
		if(this->playerDirecion != Right){
			this->playerDirecion = Right;
			this->playerSpriteTemp = 0;
		}else{
			if( this->playerSpriteTemp >= (int)( sizeof(this->spritesRunRightList) / sizeof(spritesRunRightList[0]) )-1 ){
				this->playerSpriteTemp = 0;
			}else{
				this->playerSpriteTemp++;
			}
		}		
		moveRight();
	}

	if(!move){
		this->playerSpriteTemp=-1;
	}

	return;
}


	//Draw function
//*****************************************************
void ofApp::draw(){

	drawScriptsTest();
	drawPlayer();
	return;
}


void::ofApp::drawPlayer(){

	ofTranslate(this->playerPos_X, this->playerPos_Y);
	ofPushMatrix();
		ofScale(2, 2);

		if(this->playerDirecion==Left){
			if(this->playerSpriteTemp == -1){
				this->linkSprites.drawSubsection(0, 0, this->widthSprite, this->heightSprite, this->sprite_Left_X, this->sprite_Left_Y);
			}else{
				this->linkSprites.drawSubsection(0, 0, this->widthSprite, this->heightSprite, this->spritesRunLeftList[this->playerSpriteTemp][0], this->spritesRunLeftList[this->playerSpriteTemp][1]);
			}

		}else if(this->playerDirecion==Right){
			ofPushMatrix();
				ofScale(-1, 1);
				ofTranslate(-this->widthSprite, 1);
				if(this->playerSpriteTemp == -1){
					this->linkSprites.drawSubsection(0, 0, this->widthSprite, this->heightSprite, this->sprite_Left_X, this->sprite_Left_Y);
				}else{
					this->linkSprites.drawSubsection(0, 0, this->widthSprite, this->heightSprite, this->spritesRunLeftList[this->playerSpriteTemp][0], this->spritesRunLeftList[this->playerSpriteTemp][1]);
				}
			ofPopMatrix();



		}else if(this->playerDirecion==Up){
			if(this->playerSpriteTemp == -1){
				this->linkSprites.drawSubsection(0, 0, this->widthSprite, this->heightSprite, this->sprite_Up_X, this->sprite_Up_Y);
			}else{
				this->linkSprites.drawSubsection(0, 0, this->widthSprite, this->heightSprite, this->spritesRunUpList[this->playerSpriteTemp][0], this->spritesRunUpList[this->playerSpriteTemp][1]);
			}

		}else if(this->playerDirecion==Down){
			if(this->playerSpriteTemp == -1){
				this->linkSprites.drawSubsection(0, 0, this->widthSprite, this->heightSprite, this->sprite_Down_X, this->sprite_Down_Y);
			}else{
				this->linkSprites.drawSubsection(0, 0, this->widthSprite, this->heightSprite, this->spritesRunDownList[this->playerSpriteTemp][0], this->spritesRunDownList[this->playerSpriteTemp][1]);
			}
		}
	ofPopMatrix();
	ofTranslate(0,0);

	return;
}


void ofApp::moveUp(){
	this->playerPos_Y = this->playerPos_Y - this-> playerSpeed;
	return;
}
void ofApp::moveDown(){
	this->playerPos_Y = this->playerPos_Y + this-> playerSpeed;
	return;
}
void ofApp::moveLeft(){
	this->playerPos_X = this->playerPos_X - this-> playerSpeed;
	this->playerPos_X--;
	return;
}
void ofApp::moveRight(){
	this->playerPos_X = this->playerPos_X + this-> playerSpeed;
	this->playerPos_X++;
	return;
}





void ofApp::drawScriptsTest(){

	int staticPos = 50;
	int stepSize = 30;
	unsigned long rows = 0;

	ofDrawBitmapString("Static and Run Up (w)", 0, 10);
	rows = sizeof(this->spritesRunUpList) / sizeof(spritesRunUpList[0]);
	this->linkSprites.drawSubsection(0, 15, this->widthSprite, this->heightSprite, this->sprite_Up_X, this->sprite_Up_Y);
	for(unsigned long i=0 ; i<rows ; i++){
		this->linkSprites.drawSubsection(staticPos+i*stepSize, 15, this->widthSprite, this->heightSprite, this->spritesRunUpList[i][0], this->spritesRunUpList[i][1]);
	}

	ofDrawBitmapString("Static and Run Down (s)", 0, 60);
	rows = sizeof(this->spritesRunDownList) / sizeof(spritesRunUpList[0]);
	this->linkSprites.drawSubsection(0, 65, this->widthSprite, this->heightSprite, this->sprite_Down_X, this->sprite_Down_Y);
	for(unsigned long i=0 ; i<rows ; i++){
		this->linkSprites.drawSubsection(staticPos+i*stepSize, 65, this->widthSprite, this->heightSprite, this->spritesRunDownList[i][0], this->spritesRunDownList[i][1]);
	}

	ofDrawBitmapString("Static and Run left (a)", 0, 110);
	this->linkSprites.drawSubsection(0, 115, this->widthSprite, this->heightSprite, this->sprite_Left_X, this->sprite_Left_Y);
	rows = sizeof(this->spritesRunLeftList) / sizeof(spritesRunLeftList[0]);
	for(unsigned long i=0 ; i<rows ; i++){
		this->linkSprites.drawSubsection(staticPos+i*stepSize, 115, this->widthSprite, this->heightSprite, this->spritesRunLeftList[i][0], this->spritesRunLeftList[i][1]);
	}

	ofDrawBitmapString("Static and Run right (d)", 0, 160);
	ofPushMatrix();
		ofScale(-1, 1);
		this->linkSprites.drawSubsection(-this->widthSprite, 165, this->widthSprite, this->heightSprite, this->sprite_Left_X, this->sprite_Left_Y);
	ofPopMatrix();
	rows = sizeof(this->spritesRunRightList) / sizeof(spritesRunRightList[0]);
	for(unsigned long i=0 ; i<rows ; i++){
		this->linkSprites.drawSubsection(staticPos+i*stepSize, 165, this->widthSprite, this->heightSprite, this->spritesRunRightList[i][0], this->spritesRunRightList[i][1]);
	}

	ofDrawBitmapString("Jump (w|a|s|d + space)", 0, 210);

	return;
}