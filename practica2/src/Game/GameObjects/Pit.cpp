#include "Pit.h"
#include "Player.h"
#include "Game.h"

Pit::Pit(Game *game, glm::vec3 pos, glm::vec3 dim) : Obstacle(game, pos, dim) {
	material.setEmissiveColor(ofColor::blueViolet);
}
Pit::~Pit() {}

void Pit::draw() {

	material.begin();
	{
		transform.transformGL();
			ofPushMatrix();
				ofRotate(90, 1, 0, 0);
				ofDrawCircle(transform.getGlobalOrientation().x, transform.getGlobalOrientation().y, game->ROAD_WIDTH / (4 * 1.77));
			ofPopMatrix();
		transform.restoreTransformGL();
		//collider->draw();
	}
	material.end();
}


void Pit::receiveCarCollision(Player *car) {
	car->init();
}