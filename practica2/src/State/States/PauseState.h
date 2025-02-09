#pragma once
#include "State.h"
#include "PlayState.h"

class PauseState :
	public State
{
	PlayState *gameState;

public:
	PauseState(Game *game, PlayState *playState);

	~PauseState();

	void update();
	void draw();
	void next();
};

