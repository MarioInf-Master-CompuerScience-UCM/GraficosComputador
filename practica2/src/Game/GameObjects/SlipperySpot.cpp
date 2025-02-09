#include "SlipperySpot.h"
#include "Player.h"
#include "Game.h"

SlipperySpot::SlipperySpot(Game *game, glm::vec3 pos, glm::vec3 dim) : Obstacle(game, pos, dim) {
	material.setEmissiveColor(ofColor::black);
}
SlipperySpot::~SlipperySpot() {}

void SlipperySpot::draw() {

	material.begin();
	{
		collider->draw();
	}
	material.end();
}


void SlipperySpot::receiveCarCollision(Player *car) {
	if (car->getSpeed() > 3) {
		if (ofRandom(0, 1) <= 0.5) {
			car->steerLeft();
		}
		else
		{
			car->steerRight();
		}
	}
}