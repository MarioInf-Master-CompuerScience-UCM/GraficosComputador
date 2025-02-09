#include "Home.h"


void Home::draw() {
	float shift = abs(sin(ofGetElapsedTimeMillis() / 200.0));
	auto hue = baseColor.getHue()*shift + altColor.getHue()*(1 - shift);
	ofColor drawColor = baseColor;

	drawColor.setHue(hue);

	ofSetColor(drawColor);
	ofDrawRectangle(0, 0, homeWidth, ofGetHeight());

	drawHPBar();
}

vector<ofRectangle> Home::getEnclosingRectangleList() {
	vector<ofRectangle> vRect;

	ofRectangle homeHurtbox = ofRectangle(0, 0, homeWidth, ofGetHeight());
	vRect.push_back(homeHurtbox);

	return vRect;
}


void Home::reset() {
	this->setHealth(100);

	return;
}


void Home::setHealth(int hp) {
	this->health = hp;

	return;
}

int Home::getHealth() {
	return this->health;
}

void Home::drawHPBar() {
	float percentageHP = health / 100.0;

	// Barra de vida
	ofRectangle bgRect = ofRectangle(homeWidth / 2, ofGetHeight() / 4, homeWidth / 4, ofGetHeight() / 2);

	ofSetColor(ofColor::black);
	//int offset = 10; // Por si fuese necesario en un futuro
	ofDrawRectRounded(bgRect, homeWidth / 16);

	if (health < 20) {
		ofSetColor(ofColor::red);
	}
	else {
		ofSetColor(ofColor::green);
	}

	ofRectangle hpRect = ofRectangle(homeWidth / 2, 3 * ofGetHeight() / 4, homeWidth / 4, - (health / 100.0) * ofGetHeight() / 2);
	ofDrawRectRounded(hpRect, homeWidth / 16);

	ofSetColor(ofColor::white);
	ofSetLineWidth(5);
	ofNoFill();
	ofDrawRectRounded(bgRect, homeWidth / 16);
	ofFill();

}


void Home::takeDamage(int dmg) {
	this->setHealth(max(0, this->getHealth() - dmg));

	return;
}