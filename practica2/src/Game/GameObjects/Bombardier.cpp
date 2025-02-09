#include "Bombardier.h"
#include "Player.h"
#include "Bomb.h"
#include "Game.h"

Bombardier::Bombardier(Game *game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim) {

	material.setEmissiveColor(ofColor::aliceBlue);
	collider->move(0, dim.y / 2 - 25, 0);

	transform.rotateDeg(90, 0, 1, 0);
	speed = 5;
	bTurned = false;

	transform.move(glm::vec3(ofRandom(-game->ROAD_WIDTH/3, game->ROAD_WIDTH / 3), 0, 0));

	//model.loadModel("models/lakitu/lakitu.gltf");
	//model.setScale(0.25, 0.25, 0.25);
}

Bombardier::~Bombardier() {

}

void Bombardier::update() {
	transform.move(transform.getZAxis() * -speed);

	auto xPos = transform.getGlobalPosition().x;
	if (xPos < -game->ROAD_WIDTH/2 || xPos > game->ROAD_WIDTH/2) {
		turn();
	}

	if (int(ofRandom(100)) == 42) {
		releaseBomb();
	}

	//model.setPosition(transform.getGlobalPosition().x, transform.getGlobalPosition().y, transform.getGlobalPosition().z);

	bTurned = false;
};

void Bombardier::draw() {

	material.begin();
	{
		collider->draw();
	}
	material.end();

	//model.drawFaces();

};

void Bombardier::turn() {
	if (!bTurned) {
		transform.rotateDeg(180, 0, 1, 0);
		transform.move(transform.getZAxis() * -speed);
		bTurned = true;
	}
}

void Bombardier::releaseBomb() {
	game->addGameObject(new Bomb(game, transform));
}