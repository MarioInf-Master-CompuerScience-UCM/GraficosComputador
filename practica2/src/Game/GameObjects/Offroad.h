#pragma once
#include "Obstacle.h"
class Offroad :
	public Obstacle
{

public:

	Offroad(Game *game, glm::vec3 pos, glm::vec3 dim);
	~Offroad();

	void draw() override;
	void receiveCarCollision(Player *car) override;
};

