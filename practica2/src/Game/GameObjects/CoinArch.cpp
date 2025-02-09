#include "CoinArch.h"
#include "Player.h"
#include "Game.h"

CoinArch::CoinArch(Game *game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim) {
	material.setEmissiveColor(ofColor::yellow);

	//ofDisableArbTex();
	//ofLoadImage(texture, "crosswalkTexture.png");
	//ofEnableArbTex();

	int fontSize = 100;
	nCoinFont.load("pixelmix.ttf", fontSize, true, true);
	nCoinFont.setLineHeight(fontSize * 1.05);
	nCoinFont.setLetterSpacing(1.035);

	coins = (int)ofRandom(1, 10);
	drawCoinTexture();

	ofDisableArbTex();
	nCoinTexture.allocate(200, 200, GL_RGBA);

	nCoinTexture.begin();
	{
		ofClear(255, 255, 255, 0);
	}
	nCoinTexture.end();
	ofEnableArbTex();
}

CoinArch::~CoinArch() {}

void CoinArch::draw() {

	material.begin();
	{
		transform.transformGL();

		ofDrawBox(-collider->getWidth() / 2,
			50, 0, 50, 300, 50);

		ofDrawBox(collider->getWidth() / 2,
			50, 0, 50, 300, 50);

		ofDrawBox(0,
			200, 0, collider->getWidth(), 50, 50);

		transform.restoreTransformGL();
	}
	material.end();

	drawCoinTexture();

	transform.transformGL();
	{
		nCoinTexture.getTexture().bind();
		{
			ofPushMatrix();
				ofRotate(180, 0, 1, 0);
				ofTranslate(100, 0, 0);
				ofDrawBox(0, 400, 0, 200, 200, 0);
			ofPopMatrix();
		}
		nCoinTexture.getTexture().unbind();
	}
	transform.restoreTransformGL();
}

void CoinArch::drawDebug() {
	collider->drawDebug();
}

void CoinArch::update() {
	if (game->getEllapsedTime() - resetTime > 5) {
		material.setEmissiveColor(ofColor::yellow);
	}
}

void CoinArch::reset() {
	resetTime = game->getEllapsedTime();
	coins = (int)ofRandom(1, 10);
	
	drawCoinTexture();
}

void CoinArch::drawCoinTexture() {
	ofDisableArbTex();
	nCoinTexture.begin();
	{
		ofClear(255, 255, 255, 0);

		ofSetColor(255);
		nCoinFont.drawString(ofToString(coins), 0, 0);
	}
	nCoinTexture.end();
	ofEnableArbTex();

}

void CoinArch::receiveCarCollision(Player *car) {
	if (game->getEllapsedTime() - resetTime > 5){
		car->addCoins(coins);
		reset();

		material.setEmissiveColor(ofColor::indianRed);
	}
}
