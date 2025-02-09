
#include "Bullet.h"
#include "Game.h"

Bullet::Bullet(Game *game, ofNode otherTransform)
    :GameObject(game, otherTransform.getGlobalPosition(), glm::vec3(20))
{
        transform.setGlobalOrientation(otherTransform.getGlobalOrientation());
    material.setEmissiveColor(ofColor::red);

	model.loadModel("models/fireball-vfx/source/fireballvfx.fbx");
	model.setScale(0.001, 0.001, 0.001);
}

Bullet::~Bullet(){}

void Bullet::update(){
    transform.move(transform.getZAxis() * 100);
	model.setPosition(transform.getGlobalPosition().x, transform.getGlobalPosition().y, transform.getGlobalPosition().z);
};

void Bullet::draw(){
    
    //material.begin();
    //{
    //    //collider->draw();
    //}
    //material.end();

	model.drawFaces();
    
};

void Bullet::checkCollisions(){
    vector<GameObject*> collisions = game->getCollisions(this);
    for(auto c: collisions){
        c->receiveBulletCollision(this);
    }
}
