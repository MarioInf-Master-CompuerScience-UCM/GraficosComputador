#pragma once
#include "ofMain.h"
#include "../../gameObjects/gameObject.h"
#include "../../gameObjects/abstractEnemy/RectangleEnemy/rectangleEnemy.h"
#include "../../gameObjects/abstractEnemy/triangleEnemy/triangleEnemy.h"

class BuilderEnemies
{

public:
	enum class EnemyType
	{
		rectangle,
		triangle,
		circle
	};
	enum class SizeType
	{
		small,
		medium,
		large
	};
	enum class SpeedType
	{
		slow,
		normal,
		fast
	};

	BuilderEnemies(ofColor nColor1, ofColor nColor2, int nLimitUp, int nLimitDown,
				   int nLimitLeft, int nLimitRight)
	{
		GameObject::setMainColor(GameObject::ColorType::Color1, nColor1);
		GameObject::setMainColor(GameObject::ColorType::Color2, nColor2);

		setLimitUp(nLimitUp);
		setLimitDown(nLimitDown);
		setLimitRight(nLimitRight);
		setLimitLeft(nLimitLeft);
	}

private:
	int limitUp;
	int limitDown;
	int limitLeft;
	int limitRight;

	// ofColor selectColor(GameObject::ColorType colourType);

	const int squareSize_small_width = 40;
	const int squareSize_medium_width = 60;
	const int squareSize_large_width = 100;
	int selectSquareSize_width(SizeType sizeType);

	const int squareSize_small_height = 20;
	const int squareSize_medium_height = 30;
	const int squareSize_large_height = 50;
	int selectSquareSize_height(SizeType sizeType);

	const int triangleSize_small = 30;
	const int triangleSize_medium = 40;
	const int triangleSize_large = 50;
	int selectTriamgleSize(SizeType sizeType);

	const int speed_slow = 2;
	const int speed_normal = 3;
	const int speed_fast = 4;
	int selectSpeed(SpeedType speedType);

public:
	AbstractEnemy *build();
	AbstractEnemy *build(GameObject::ColorType colourType, EnemyType enemyType, SizeType sizeType,
						 SpeedType speedType);

	int getLimitUp();
	void setLimitUp(int value);
	int getLimitDown();
	void setLimitDown(int value);
	int getLimitLeft();
	void setLimitLeft(int value);
	int getLimitRight();
	void setLimitRight(int value);
};
