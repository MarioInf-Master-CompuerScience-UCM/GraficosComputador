#include "Player.h"
#include "Game.h"
#include "Bullet.h"

Player::Player(Game *game):GameObject(game, glm::vec3(100)){
    
    material.setDiffuseColor(ofColor::blue);
    
    faro.setParent(transform);
    faro.setDiffuseColor(ofColor::yellow);
    faro.setSpotlight();
    faro.move(0, 0, 50);
    faro.rotateDeg(-200, 1, 0, 0);

	model.loadModel("models/kart/source/F2_Item_Kart_Mario_S.dae");
	model.setScale(0.3, 0.3, 0.3);
	model.setRotation(0, 180, 0, 0, 1);

	collider->set(100, 100, 100);
}

Player::~Player(){}

void Player::init(){
    transform.setPosition(0, 0, 0);
    speed = 0;
	roadAccel = 0;
    bLight = false;
    
    coins = 0;
}

void Player::update(){
    prevPos = transform.getPosition();

	if (getSpeed() > 0) {
		surfaceSlowDown(0.25);
	}

    transform.move(transform.getZAxis() * speed);

	//model.setPosition(transform.getGlobalPosition().x, transform.getGlobalPosition().y, transform.getGlobalPosition().z);
	//model.setRotation(0, transform.getGlobalOrientation().w, transform.getGlobalOrientation().x, transform.getGlobalOrientation().y, transform.getGlobalOrientation().z);
    
    if(speed > MAX_SPEED) speed = MAX_SPEED;
    if(speed < 0) speed = 0;
}

void Player::draw(){
    
    faro.draw();
    if(bLight)
        faro.enable();
    else
        faro.disable();
    
    //material.begin();
    //{
    //    collider->draw();
    //}
    //material.end();
	transform.transformGL();
	model.drawFaces();
	transform.restoreTransformGL();
}

void Player::drawDebug(){
    collider->drawDebug();
    
    transform.transformGL();
    ofDrawAxis(100);
    transform.restoreTransformGL();
}

void Player::checkCollisions(){
    vector<GameObject*> collisions = game->getCollisions(this);
    for(auto c: collisions){
        c->receiveCarCollision(this);
    }
}

void Player::receiveBombCollision(Bomb *bomb) {
	init();
}

void Player::receiveExplosionWaveCollision(Bomb *bomb) {
	transform.rotateDeg(90, 0, 1, 0);
}


void Player::setPosition(glm::vec3 pos) {
	transform.setPosition(pos);
}

void Player::steerLeft(){
    transform.rotateDeg(1, 0, 2, 0);
}
void Player::steerRight(){
    transform.rotateDeg(-1, 0, 2, 0);
}
void Player::accelerate(){
    speed += 0.7;
}
void Player::brake(){
    speed -= 0.7;
}

void Player::crouch() {
	collider->set(125, 50, 125);
}

void Player::dash() {
	if (coins >= 10) {
		coins -= 10;
		transform.move(transform.getZAxis() * 100);
		game->dashSFX();
	}
}

void Player::surfaceSlowDown(float surf) {
	speed -= surf;
}

void Player::stop(){
    speed = 0;
    transform.setPosition(prevPos);
}

void Player::toggleLight(){
    bLight = !bLight;
}

float Player::getSpeed(){
    return speed;
}

void Player::addCoins(int n){
	if (n > 0) {
		game->coinCollect();
	}
    coins += n;
}

int Player::getCoins(){
    return coins;
}

void Player::shoot(){
	if (coins > 0) {
		game->shootSFX();
		game->addGameObject(new Bullet(game, transform));
		coins--;
	}
}
