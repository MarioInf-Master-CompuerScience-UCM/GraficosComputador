#pragma once
#include "Obstacle.h"

class Barrier :
	public Obstacle
{

	float speed = 4;

public:
	Barrier(Game *game, glm::vec3 pos, glm::vec3 dim);
	~Barrier();

	void draw() override;
	void update() override;
	void receiveCarCollision(Player *car) override;
	void receiveBulletCollision(GameObject *bullet) override;
	void receivePedestrianCollision(Pedestrian *pedestrian) override;
};

