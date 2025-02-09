#pragma once
#include "Obstacle.h"
class SlipperySpot :
	public Obstacle
{

public:

	SlipperySpot(Game *game, glm::vec3 pos, glm::vec3 dim);
	~SlipperySpot();

	void draw() override;
	void receiveCarCollision(Player *car) override;
};

