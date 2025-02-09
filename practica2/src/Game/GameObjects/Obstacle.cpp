#include "Obstacle.h"
#include "Player.h"
#include "Pedestrian.h"

Obstacle::Obstacle(Game *game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim) {
	material.setEmissiveColor(ofColor::forestGreen);
}
Obstacle::~Obstacle() {}

void Obstacle::draw() {

	material.begin();
	{
		transform.transformGL();
			ofDrawCylinder(glm::vec3(0), 50, 100);

			ofPushMatrix();
				ofTranslate(glm::vec3(0, 70, 0));
				ofDrawCylinder(glm::vec3(0), 60, 30);
			ofPopMatrix();

			//ofPushMatrix();
			//	ofRotate(90, 1, 0, 0);
			//	ofTranslate(glm::vec3(0, 90, 0));
			//	ofDrawCircle(0, 0, 50);
			//ofPopMatrix();
		transform.restoreTransformGL();
		//collider->draw();
	}
	material.end();

	auto prevColor = ofGetStyle().color;
	ofSetColor(ofColor::black);
	transform.transformGL();
		ofPushMatrix();
			ofRotate(90, 1, 0, 0);
			ofTranslate(glm::vec3(0, 0, -87));
			ofDrawCircle(0, 0, 40);
		ofPopMatrix();
	transform.restoreTransformGL();
	ofSetColor(prevColor);
}


void Obstacle::receiveCarCollision(Player *car) {
	car->stop();
}

void Obstacle::receiveBulletCollision(GameObject *bullet) {
	bullet->kill();
	kill();
};

void Obstacle::receivePedestrianCollision(Pedestrian *pedestrian) {

}