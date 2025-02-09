#pragma once
#include <string>
#include "ofMain.h"
#include "../gameObject.h"
using namespace std;

class AbstractEnemy : public GameObject
{

private:
	int speed;

	int posX;
	int posY;
	int limitUp;
	int limitDown;
	int limitLeft;
	int limitRight;

public:
	AbstractEnemy() : GameObject(){
		this->setId("AbstractEnemy");
	};

	AbstractEnemy(int nLimitUp, int nLimitDown, int nLimitLeft, int nLimitRight,
				  GameObject::ColorType nColor, int nSpeed) : GameObject()
	{

		this->setId("AbstractEnemy");
		this->setColorType(nColor);
		this->setSpeed(nSpeed);

		this->setLimitUp(nLimitUp);
		this->setLimitDown(nLimitDown);
		this->setLimitRight(nLimitRight);
		this->setLimitLeft(nLimitLeft);
	}

	virtual void setup() override;
	virtual void draw() override;
	virtual void update() override;

	int getSpeed();
	void setSpeed(int value);

	int getPosX();
	void setPosX(int value);
	int getPosY();
	void setPosY(int value);
	int getLimitUp();
	void setLimitUp(int value);
	int getLimitDown();
	void setLimitDown(int value);
	int getLimitLeft();
	void setLimitLeft(int value);
	int getLimitRight();
	void setLimitRight(int value);
};
