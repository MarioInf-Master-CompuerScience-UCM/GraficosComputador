#pragma once
#include "ofMain.h"
#include "../gameObject.h"

class Bullet: public GameObject {
    private:
        const int radius = 10;
        float speedX;
        float speedY;
        float floatPosX;
        float floatPosY;
    
    public:
        Bullet(ofPoint initialPos, float speedX, float speedY);

        void setSpeedX(float sx);
        float getSpeedX();
        void setSpeedY(float sy);
        float getSpeedY();
        virtual void draw() override;
        virtual void update() override;
	    virtual vector<ofRectangle> getEnclosingRectangleList() override;
        ofColor getMainColor();
};