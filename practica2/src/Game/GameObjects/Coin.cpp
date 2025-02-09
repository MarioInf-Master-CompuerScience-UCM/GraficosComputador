#include "Coin.h"
#include "Player.h"
#include "Game.h"


Coin::Coin(Game *game, glm::vec3 pos, glm::vec3 dim):
    GameObject(game, pos, dim){
    material.setDiffuseColor(ofColor::yellow);
        
 
    
}
Coin::~Coin(){
    
}


void Coin::update(){
    model.update();
}

void Coin::draw(){
   
    material.begin();
    {
		transform.transformGL();

			ofPushMatrix();
				ofRotate(90, 0, 0, 1);
				ofRotate(game->getEllapsedTime() * 100, 1, 0, 0);
				ofDrawCylinder(25, 10);
			ofPopMatrix();
			
		transform.restoreTransformGL();
        //collider->draw();
    }
    material.end();
}

void Coin::receiveCarCollision(Player *car){
    car->addCoins(5);
    kill();
}

void Coin::receiveBulletCollision(GameObject *bullet){
    bullet->kill();
    kill();
    game->getPlayer()->addCoins(1000);
}
