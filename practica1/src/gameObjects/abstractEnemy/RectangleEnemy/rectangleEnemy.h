#pragma once
#include <string>
#include "ofMain.h"
#include "../abstractEnemy.h"
using namespace std;

class RectangleEnemy : public AbstractEnemy
{

private:
	float width;
	float heigth;

public:
	RectangleEnemy() : AbstractEnemy(){};

	RectangleEnemy(int nLimitUp, int nLimitDown, int nLimitLeft, int nLimitRight,
					GameObject::ColorType nColor, int nSpeed, float nWidth, float nHeight) :
					AbstractEnemy(nLimitUp, nLimitDown, nLimitLeft, nLimitRight, nColor, nSpeed)
	{
		this->setId("RectangleEnemy");
		this->setHeight(nHeight);
		this->setWidth(nWidth);
	}

	virtual void setup() override;
	virtual void draw() override;
	virtual void update() override;
	virtual vector<ofRectangle> getEnclosingRectangleList() override;

	float getWidth();
	void setWidth(float value);
	float getHeight();
	void setHeight(float value);
};
