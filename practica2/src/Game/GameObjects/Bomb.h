#ifndef Bullet_h
#define Bullet_h

#include "GameObject.h"

class Bomb :
	public GameObject
{

	float explosionTime;
	ofNode explosionWaveHitbox;
	ofSpherePrimitive explosionWave;
	bool bExploded = false;

public:
	Bomb(Game *game, ofNode transform);
	~Bomb();

	void update() override;
	void draw() override;
	void checkCollisions() override;

	void explode();
};

#endif