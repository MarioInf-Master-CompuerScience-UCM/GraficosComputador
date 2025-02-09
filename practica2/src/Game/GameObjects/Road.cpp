#include "Player.h"
#include "Road.h"
#include "Bomb.h"
#include "Game.h"

Road::Road(Game *game, glm::vec3 pos, glm::vec3 dim): GameObject(game, pos, dim){
    material.setDiffuseColor(ofColor::darkGray);
    
    plane.setParent(transform);
	plane.rotateDeg(-90, 1, 0, 0);
    plane.set(dim.x, dim.z);
    
	light.setPosition(transform.getGlobalPosition().x, transform.getGlobalPosition().y + 200, transform.getGlobalPosition().z);
    light.setDiffuseColor(ofColor::grey);
}
Road::~Road(){}

void Road::draw(){
    
    light.enable();
    material.begin();
    {
		plane.draw();
    }
    material.end();
}


void Road::drawDebug(){
    plane.drawWireframe();

	collider->drawWireframe();
}


void Road::receiveCarCollision(Player *car) {

}

void Road::receiveBombCollision(Bomb *bomb) {
	bomb->explode();
}