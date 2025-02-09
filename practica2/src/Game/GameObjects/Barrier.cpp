#include "Barrier.h"
#include "Player.h"
#include "Pedestrian.h"
#include "Game.h"

Barrier::Barrier(Game *game, glm::vec3 pos, glm::vec3 dim) : Obstacle(game, pos, dim) {
	material.setEmissiveColor(ofColor::green);

	transform.move(glm::vec3(0, ofRandom(0, 300), 0));
}
Barrier::~Barrier() {}

void Barrier::draw() {

	material.begin();
	{
		collider->draw();
	}
	material.end();
}

void Barrier::update() {
	transform.move(transform.getYAxis() * -speed);

	auto yPos = transform.getGlobalPosition().y;

	if ((speed < 0 && yPos > 400) || (speed > 0 && yPos < 0)) {
		speed *= -1;
	}

}

void Barrier::receiveCarCollision(Player *car) {
	car->stop();
	//speed *= -1;
}

void Barrier::receiveBulletCollision(GameObject *bullet) {
	bullet->kill();
	kill();
};

void Barrier::receivePedestrianCollision(Pedestrian *pedestrian) {

}