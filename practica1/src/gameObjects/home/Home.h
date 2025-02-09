#pragma once
#include "ofMain.h"
#include "gameObject.h"

class Home : public GameObject
{
	private:
		const ofColor baseColor{ ofColor::orangeRed };
		const ofColor altColor{ ofColor::red };

		const double homeWidth{ ofGetWidth()*0.1 };

		int health;

	public:
		Home() : GameObject() {
			this->setHealth(100);
		};

		virtual void draw() override;

		virtual vector<ofRectangle> getEnclosingRectangleList() override;

		void reset();

		void setHealth(int hp);
		int getHealth();

		void drawHPBar();

		void takeDamage(int dmg);

};

