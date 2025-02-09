#pragma once
#include "GameObject.h"
class CoinArch :
	public GameObject
{

	int coins;
	bool bCollision;

	float resetTime = 0;
	ofFbo nCoinTexture;
	ofTrueTypeFont nCoinFont;

	void drawCoinTexture();

public:
	CoinArch(Game *game, glm::vec3 pos, glm::vec3 dim);
	~CoinArch();

	void draw() override;
	void drawDebug() override;
	void update() override;
	void receiveCarCollision(Player *car) override;

	void reset();

};

