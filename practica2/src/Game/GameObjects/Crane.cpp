#include "Crane.h"
#include "Player.h"
#include "Game.h"
#include "Obstacle.h"

Crane::Crane(Game *game, glm::vec3 pos, glm::vec3 dim) : Obstacle(game, pos, dim) {
	material.setEmissiveColor(ofColor::purple);
	initPos = transform.getGlobalPosition();
	transform.move(glm::vec3(-armHeight, 0, 0));

	//model.loadModel("tnt/obj.mtl");
}
Crane::~Crane() {}

void Crane::draw() {

	material.begin();
		ofPushMatrix();
			ofTranslate(initPos);
			ofTranslate(glm::vec3(0, baseHeight/2, 0));
			ofDrawCylinder(glm::vec3(0, 0, 0), baseDiameter, baseHeight);

			ofTranslate(glm::vec3(-armHeight/2, baseHeight/2, 0));
			ofRotate(90, 0, 0, 1);
			ofDrawCylinder(glm::vec3(0, 0, 0), armDiameter, armHeight);
			ofRotate(-90, 0, 0, 1);
			
			ofTranslate(glm::vec3(-armHeight/2, - cableLong/2, 0));
			ofDrawCylinder(glm::vec3(0, 0, 0), cableDiameter, cableLong);
		ofPopMatrix();

		collider->draw();
		
	material.end();

	//model.drawFaces();

}

void Crane::update() {
	
	transform.move(transform.getYAxis() * -speed);
	auto yPos = transform.getGlobalPosition().y;
	if ((speed < 0 && yPos > 200) || (speed > 0 && yPos < 0)) {
		speed *= -1;
	}
	cableLong = cableHeight - yPos;

	//model.setPosition(transform.getGlobalPosition().x, transform.getGlobalPosition().y, transform.getGlobalPosition().z);

}

void Crane::receiveCarCollision(Player *car) {
	if(car->getCoins() > 0)
		game->coinLossSFX();
	car->addCoins(-car->getCoins());
	car->stop();
}

void Crane::receiveBulletCollision(GameObject *bullet) {
	bullet->kill();
	// kill();
};