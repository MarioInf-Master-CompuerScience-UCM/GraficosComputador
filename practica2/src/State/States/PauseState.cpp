#include "PauseState.h"
#include "PlayState.h"

PauseState::PauseState(Game *game, PlayState *playState) : State(game, "Pause State") {
	gameState = playState;
};

PauseState::~PauseState() {};

void PauseState::update() {
	if (ofGetKeyPressed('q'))
		next();
};

void PauseState::draw() {
	ofBackground(200, 200, 200, 10);
	ofSetColor(0);
	ofDrawBitmapString(name, 10, 20);
};

void PauseState::next() {
	game->exitPause();
	game->setState(gameState);
};
