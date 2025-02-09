#pragma once
#include <string>
#include "ofMain.h"
using namespace std;

class GameObject
{
public:
	enum class ColorType
	{
		Color1,
		Color2
	};

	GameObject()
	{
		this->setId("GameObject");
	}

	virtual void setup();
	virtual void draw();
	virtual void update();
	virtual vector<ofRectangle> getEnclosingRectangleList();

	string getId();
	void setId(string value);

	ofPoint getRefPoint();
	void setRefPoint(ofPoint rp);
	int getRefPointX();
	void setRefPointX(int x);
	int getRefPointY();
	void setRefPointY(int y);

	ColorType getColorType();
	void setColorType(ColorType value);

	static void setMainColor(ColorType ct, int r, int g, int b);
	static void setMainColor(ColorType ct, ofColor ofc);
	ofColor getMainColor();

	bool collidesWith(GameObject go);

private:
	string id;
	ofPoint refPoint;
	GameObject::ColorType color;
	static ofColor mainColor1, mainColor2;
};
