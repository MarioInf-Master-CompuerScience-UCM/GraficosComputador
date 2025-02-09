#ifndef Crosswalk_h
#define Crosswalk_h
#pragma once
#include "GameObject.h"
#include "Pedestrian.h"

class Crosswalk : public GameObject{

	private:
		Pedestrian *pedestrian = nullptr;

	public:
		Crosswalk(Game *game, glm::vec3 pos);
		Crosswalk(Game *game, glm::vec3 pos, glm::vec3 dim);
		virtual ~Crosswalk();

		void update() override;
		void draw() override;

};

#endif
