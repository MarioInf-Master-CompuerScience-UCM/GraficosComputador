#include "ofApp.h"
#include "MenuState.h"
#include "PlayState.h"
#include "Player.h"

#include <Windows.h>
#include <Xinput.h>

//--------------------------------------------------------------
void ofApp::setup(){
    game = new Game();
    game->setState(new PlayState(game));
    ofSetFrameRate(60);
}

ofApp::~ofApp(){
    delete game;
}

//--------------------------------------------------------------
void ofApp::update(){
    game->currentState()->update();
    
    if(game->isFinished()){
        game->currentState()->next();
        game->setFinished(false);
    }

	int controllerId = -1;

	for (DWORD i = 0; i < XUSER_MAX_COUNT && controllerId == -1; i++)
	{
		XINPUT_STATE state;
		ZeroMemory(&state, sizeof(XINPUT_STATE));

		if (XInputGetState(i, &state) == ERROR_SUCCESS) controllerId = i;
		
		// Triggers
		float leftTrigger = (float)state.Gamepad.bLeftTrigger / 255;
		float rightTrigger = (float)state.Gamepad.bRightTrigger / 255;

		// JoyStick
		float normLX = fmaxf(-1, (float)state.Gamepad.sThumbLX / 32767);
		float normLY = fmaxf(-1, (float)state.Gamepad.sThumbLY / 32767);

		if (state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {
			game->currentState()->keyPressed(' ');
		}

		if (state.Gamepad.wButtons & XINPUT_GAMEPAD_B) {
			game->currentState()->keyPressed('c');
		}

		if (state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {
			game->currentState()->keyPressed('s');
		}

		if (state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {
			//cout << "Y" << endl;
		}

		if (rightTrigger > 0.1) game->currentState()->keyPressed(OF_KEY_UP);
		if (leftTrigger > 0.1) game->currentState()->keyPressed(OF_KEY_DOWN);

		if (normLX < -0.4) game->currentState()->keyPressed(OF_KEY_LEFT);
		if (normLX > 0.4) game->currentState()->keyPressed(OF_KEY_RIGHT);

		if (normLY < -0.4) game->currentState()->keyPressed('c');
		//if (normLY > 0.4) game->currentState()->keyPressed(OF_KEY_RIGHT);
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
    game->currentState()->draw();
}


void ofApp::keyPressed(int key){
    if(key == ']')
        game->currentState()->next();
    
    game->currentState()->keyPressed(key);
}


void ofApp::keyReleased(int key){
    game->currentState()->keyReleased(key);
}
