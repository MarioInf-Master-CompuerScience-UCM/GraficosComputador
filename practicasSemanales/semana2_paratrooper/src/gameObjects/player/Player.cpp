#include "Player.h"


// pmInit Function
//*************************************************************
void Player::init(int nInitialPosX, int nInitialPosY){

	this->initialPosX = nInitialPosX;
	this->initialPosY = nInitialPosY;
	this->posX = nInitialPosX;
	this->posY = nInitialPosY;

    return;
}


// pmUpdate Function
//*************************************************************
void Player::update(){
	

	return;
}


// pmDraw Function
//*************************************************************
void Player::draw(){
	
	ofSetColor(200, 200, 200);
	ofFill();
	ofDrawRectangle(this->posX, this->posY, 100, 100);
	return;
}


// MoveLeft Function
//*************************************************************
void Player::moveLeft(){
    this->posX = this->posX - this->speed;
	return;
}


// MoveRight Function
//*************************************************************
void Player::moveRight(){
	this->posX = this->posX + this->speed;
	return;
};
