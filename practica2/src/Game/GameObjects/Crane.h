#pragma once
#include "Obstacle.h"


class Crane : public Obstacle {

	float speed = 4;
	glm::vec3 initPos;

	float const baseDiameter = 80;
	float const baseHeight = 600;
	float const armDiameter = 30;
	float const armHeight = 1000;
	float const cableDiameter = 5;
	float const cableHeight = 600;
	float cableLong = 0;


	public:
		Crane(Game *game, glm::vec3 pos, glm::vec3 dim);
		~Crane();

		void draw() override;
		void update() override;
		void receiveCarCollision(Player *car) override;
		void receiveBulletCollision(GameObject *bullet) override;


};

