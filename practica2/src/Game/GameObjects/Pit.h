#pragma once
#include "Obstacle.h"
class Pit :
	public Obstacle
{


public:

	Pit(Game *game, glm::vec3 pos, glm::vec3 dim);
	~Pit();

	void draw() override;
	void receiveCarCollision(Player *car) override;
};

