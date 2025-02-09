#include "Game.h"
#include "Player.h"

Game::Game(){
    // TODO create settings
    ROAD_WIDTH = 2000;
    ROAD_LENGTH = 30000;

    generator = new GameObjectGenerator(this);
    bDebug = false;
    scream.load("aaa.wav");
	coin.load("coin.mp3");
	shoot.load("piu_edit.mp3");
	coinLoss.load("coin_loss.mp3");
	dash.load("dash.wav");
	bgs.load("smk8_bso.mp3");

	bgs.setLoop(true);
	bgs.setVolume(0.2);
	bgs.play();

	shoot.setVolume(1);
}

Game::~Game(){
    ofLogNotice() << "Deleting game";
    delete gameObjects;
    delete generator;
    delete currentState();
}

void Game::init(){
    
    if(gameObjects != nullptr)
        delete gameObjects;
    
    
    gameObjects = new GameObjectContainer();
    
    player = new Player(this);
    player->init();

    cam.setPosition(0, 300, -600);
    cam.setTarget(player->transform);
    cam.setParent(player->transform);
    //cam.disableMouseInput();
    cam.setFarClip(100000);
    
    gameObjects->add(player);
    generator->generateWorld();
    bPlayerFinish = false;
    initTime = ofGetElapsedTimef();
	pauseTime = 0;
}

void Game::update(){
    gameObjects->update();
}

void Game::draw(){
    ofEnableLighting();
    ofEnableDepthTest();
    
    cam.begin();
    {
        if(bDebug) gameObjects->drawDebug();
        else gameObjects->draw();
    }
    cam.end();
    
    ofDisableLighting();
    ofDisableDepthTest();
}


Player * Game::getPlayer(){
    return player;
}

vector<GameObject *> Game::getCollisions(GameObject *gameObject){
    return gameObjects->getCollisions(gameObject);
}

void  Game::addGameObject(GameObject *gameobject){
    gameObjects->add(gameobject);
}

void Game::finishGame(){
    bPlayerFinish = true;
}

void Game::toggleDebug(){
    bDebug = !bDebug;
}

bool Game::isFinished(){
    return bPlayerFinish;
}

void Game::setFinished(bool v){
    bPlayerFinish = v;
}

float Game::getEllapsedTime(){
    return ofGetElapsedTimef() - initTime - pauseTime;
}

void Game::doScream(){
    scream.play();
}

void Game::coinCollect() {
	coin.play();
}

void Game::coinLossSFX() {
	coinLoss.play();
}

void Game::shootSFX() {
	shoot.play();
}

void Game::dashSFX() {
	dash.play();
}


void Game::pause() {
	lastPauseTime = ofGetElapsedTimef();
}

void Game::exitPause() {
	pauseTime += ofGetElapsedTimef() - lastPauseTime;
}