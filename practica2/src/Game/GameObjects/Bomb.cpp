#include "Bomb.h"
#include "Game.h"

Bomb::Bomb(Game *game, ofNode otherTransform)
	:GameObject(game, otherTransform.getGlobalPosition(), glm::vec3(30))
{
	transform.setGlobalOrientation(otherTransform.getGlobalOrientation());
	transform.rotateDeg(180, transform.getZAxis());

	material.setEmissiveColor(ofColor::darkRed);

	model.loadModel("models/spiny/source/SpinyEgg.fbx");
	model.setScale(0.15, 0.15, 0.15);
}

Bomb::~Bomb() {}

void Bomb::update() {
	if (!bExploded) {
		transform.move(transform.getYAxis() * 4);
		model.setPosition(transform.getGlobalPosition().x, transform.getGlobalPosition().y, transform.getGlobalPosition().z);
	}
};

void Bomb::draw() {

	material.begin();
	{
		if(bExploded) explosionWave.draw();
	}
	material.end();

	model.drawFaces();

	if (bExploded && game->getEllapsedTime() - explosionTime > 1) {
		kill();
	}

};

void Bomb::checkCollisions() {
	vector<GameObject*> collisions = game->getCollisions(this);
	for (auto c : collisions) {
		if(!bExploded) c->receiveBombCollision(this);
		else c->receiveExplosionWaveCollision(this);
	}
}

void Bomb::explode() {
	explosionTime = game->getEllapsedTime();

	ofColor explosionColor;
	explosionColor.setHex(0xFF8000, 0.2f);

	int explosionSize = 500;

	collider->set(explosionSize);
	explosionWave.setRadius(explosionSize/1.77);
	explosionWave.setGlobalPosition(transform.getGlobalPosition());

	material.setEmissiveColor(explosionColor);

	bExploded = true;
}