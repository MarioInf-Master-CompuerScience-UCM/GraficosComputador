#include "Offroad.h"
#include "Player.h"
#include "Game.h"

Offroad::Offroad(Game *game, glm::vec3 pos, glm::vec3 dim) : Obstacle(game, pos, dim) {
	material.setEmissiveColor(ofColor::sandyBrown);
}
Offroad::~Offroad() {}

void Offroad::draw() {

	material.begin();
	{
		collider->draw();
	}
	material.end();
}


void Offroad::receiveCarCollision(Player *car) {
	if (car->getSpeed() > 8) {
		car->surfaceSlowDown(0.9);
	}
}