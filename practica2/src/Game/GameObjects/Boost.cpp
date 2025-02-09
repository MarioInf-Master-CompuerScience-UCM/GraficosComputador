#include "Boost.h"
#include "Player.h"
#include "Game.h"

Boost::Boost(Game *game, glm::vec3 pos, glm::vec3 dim, float fboost) : Obstacle(game, pos, dim) {
	if (fboost > 0) {
		material.setEmissiveColor(ofColor::yellow);
	}
	else
	{
		material.setEmissiveColor(ofColor::darkBlue);
	}

	width = dim.x;
	height = dim.z;

	boost = fboost;
}
Boost::~Boost() {}

void Boost::draw() {

	material.begin();
	{
		transform.transformGL();
			ofPushMatrix();
				ofRotate(90, 1, 0, 0);
				if (boost > 0) ofDrawTriangle(glm::vec2(-width/2, -height/2), glm::vec2(width/2, -height/2), glm::vec2(0, height/2));
				else ofDrawTriangle(glm::vec2(-width / 2, height / 2), glm::vec2(width / 2, height / 2), glm::vec2(0, -height / 2));
			ofPopMatrix();
		transform.restoreTransformGL();
	}
	material.end();
}


void Boost::receiveCarCollision(Player *car) {
	car->surfaceSlowDown(-boost);
}