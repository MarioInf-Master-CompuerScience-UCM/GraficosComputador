#pragma once
#include "Obstacle.h"

class Boost :
	public Obstacle
{

	float boost;
	float width;
	float height;

public:

	Boost(Game *game, glm::vec3 pos, glm::vec3 dim, float fboost);
	~Boost();

	void draw() override;
	void receiveCarCollision(Player *car) override;
};

