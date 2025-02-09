#include <math.h>
#include "Player.h"
#include "ofMain.h"
#include "../bullet/Bullet.h"
#ifndef M_PI
#define M_PI 3.141592653589
#endif

void Player::initMembers(int ca) {
	this->rotationSpeed = 2;
	this->radius = 80;
    this->cannonLength = 60;
    this->cannonWidth = 20;
    this->cannonAngle = ca;
	ofColor ac = ofColor(this->getMainColor());
	ac.setBrightness(ac.getBrightness() * 0.8);
	this->setAltColor(ac);

	// La posición de la forma ofPath influye en su dibujo
	// this->cannonBase.lineTo(0, 0);
	// ofPoint point2(radius * 2, 0);
	this->cannonBase.lineTo(0 - radius * 2, 0);
	ofPoint point2(0, 0);
	this->cannonBase.arc(point2, radius, radius, 0, 180);
	this->cannonBase.setColor(this->getMainColor());
}

// Constructor vacío
Player::Player() {
}

// Constructor con tipos simples
//*************************************************************
Player::Player(int xCenter, int yCenter, int cannonAngle, ColorType ct, Orientation initFacing) {
	this->facing = initFacing;
	this->setRefPointX(xCenter);
	this->setRefPointY(yCenter);
	this->setColorType(ct);
	initMembers(cannonAngle);
}

// Constructor con tipos reales
//*************************************************************
Player::Player(ofPoint playerPos, int cannonAngle, ColorType ct, Orientation initFacing) {
	this->facing = initFacing;
	this->setRefPoint(playerPos);
    this->setColorType(ct);
	initMembers(cannonAngle);
}

/**
 * Sets the rotation speed (to a maximum of 5)
*/
void Player::setRotationSpeed(int rs) {
	this->rotationSpeed = min(5, rs);
}

int Player::getRotationSpeed() {
	return this->rotationSpeed;
};

/**
 * Sets radius (to a minimum of 0 and a maximum of 359)
*/
void Player::setRadius(int r) {
	this->radius = min(359, max(0, r));
}

int Player::getRadius() {
	return this->radius;
}

void Player::setAltColor(ofColor ac) {
	this->altColor = ac;
}

ofColor Player::getAltColor() {
	return this->altColor;
}

/**
 * Sets cannon length to a minimum of 30 and a maximum of 100
*/
void Player::setCannonLength(int cl) {
	this->cannonLength = max(30, min(100, cl));
}

int Player::getCannonLength() {
	return this->cannonLength;
}

/**
 * Sets cannon width to a minimum of 8 and a maximum of 30
*/
void Player::setCannonWidth(int cw) {
	this->cannonWidth = max(8, min(30, cw));
}

int Player::getCannonWidth() {
	return this->cannonWidth;
}

/**
 * Sets cannon angle
*/
void Player::setCannonAngle(int ca) {
	this->cannonAngle = ca;
}

int Player::getCannonAngle() {
	return this->cannonAngle;
}

[[deprecated]]
void Player::setCanyonLength(int cl) {
	this->setCannonLength(cl);
}

[[deprecated]]
int Player::getCanyonLength() {
	return this->getCannonLength();
}

[[deprecated]]
void Player::setCanyonWidth(int cw) {
	this->setCannonWidth(cw);
}

[[deprecated]]
int Player::getCanyonWidth() {
	return this->getCannonWidth();
}

[[deprecated]]
void Player::setCanyonAngle(int ca) {
	this->setCannonAngle(ca);
}

[[deprecated]]
int Player::getCanyonAngle() {
	return this->getCannonAngle();
}


// pmDraw Function
//*************************************************************
void Player::draw() {
	ofPushMatrix();
	{ // Desplazamiento de la base del cañón, el nuevo 0, 0 es el centro
		ofTranslate(this->getRefPointX(), this->getRefPointY(), 0);
		// Descomentar líneas siguientes para ver el punto de referencia
		// de la matriz
		// ofSetColor(ofColor::lightYellow);
		// ofDrawCircle(0, 0, 15);

		// Por defecto dibujamos hacia abajo. La orientación norte gira 180º
		if (this->facing == Orientation::NORTH) {
			ofRotateDeg(180);
		}

		ofPushMatrix();
		{ // Desplazamiento del cañón en sí
			ofTranslate(0, radius - 10, 0);
			ofRotateDeg(this->cannonAngle, 0, 0, 1);
			ofSetColor(this->altColor);
			ofFill();
			ofDrawRectangle(0 - (cannonWidth / 2), 0, cannonWidth, cannonLength);
		}
		ofPopMatrix();

		ofSetColor(this->getMainColor());
		this->cannonBase.draw();
	}
	ofPopMatrix();
}


// pmUpdate Function
//*************************************************************
void Player::update(){

}


// MoveLeft Function
//*************************************************************
void Player::moveLeft(){
    this->cannonAngle =  max(-80, this->cannonAngle - this->getRotationSpeed());
}


// MoveRight Function
//*************************************************************
void Player::moveRight(){
    this->cannonAngle =  min(80, this->cannonAngle + this->getRotationSpeed());
};

vector<ofRectangle> Player::getEnclosingRectangleList() {
    vector<ofRectangle> l;
	int signX = (facing == Orientation::NORTH) ? 1 : -1;
	int signY = (facing == Orientation::NORTH) ? -1 : 1;
	float sx = sin(cannonAngle * M_PI / 180);
	float sy = cos(cannonAngle * M_PI / 180);
	int x, y, w, h;
	
	// Rectángulo de la base del cañón
	y = this->getRefPointY() - ((this->facing == Orientation::NORTH) ? this->radius : 0);
    ofRectangle baseBox = ofRectangle(this->getRefPointX() - this->radius, y,
                                  	  this->radius * 2, this->radius);

	// Punta del cañón
	ofPoint cannonTip = ofPoint(this->getRefPointX() + (signX * sx * cannonLength),
								this->getRefPointY() + (signY * radius) + (signY * sy * cannonLength), 0);
	x = (this->getRefPointX() < cannonTip.x) ? this->getRefPointX() - cannonWidth :
											   cannonTip.x;
	w = sx * cannonLength + cannonWidth; // No es exacto, pero suficiente
	y = (this->getRefPointY() < cannonTip.y) ? this->getRefPointY() + radius - 5 :
											   cannonTip.y;
	h = sy * cannonLength;

	ofRectangle cannonBox = ofRectangle(x, y, w, h);
    l.insert(l.begin(), baseBox);
    l.insert(l.begin() + 1, cannonBox);
	return l;
}

Bullet * Player::shoot() {
	int signX = (facing == Orientation::NORTH) ? 1 : -1;
	int signY = (facing == Orientation::NORTH) ? -1 : 1;
	float sx = sin(cannonAngle * M_PI / 180);
	float sy = cos(cannonAngle * M_PI / 180);
	ofPoint bulletInitial = ofPoint(this->getRefPointX() + (signX * sx * cannonLength),
									this->getRefPointY() + (signY * (radius - 10)) + (signY * sy * cannonLength), 0);

	// Velocidad horizontal y vertical de la bala
	int speedMult = 4;
	sx = signX * sx * 2 * speedMult;
	sy = signY * sy * 2 * speedMult;

	Bullet *b = new Bullet(bulletInitial, sx, sy);
	b->setColorType(this->getColorType());
	return b;
}
