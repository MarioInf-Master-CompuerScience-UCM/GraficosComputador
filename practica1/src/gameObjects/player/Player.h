#pragma once
#include "ofMain.h"
#include "../gameObject.h"
#include "../bullet/Bullet.h"

class Player : public GameObject
{
    void initMembers(int ca);
    ofPath cannonBase;
    int rotationSpeed = 2;
    int radius = 50;
    int cannonLength = 50;
    int cannonWidth = 8;

    ofColor altColor;
    int cannonAngle;

public:
    enum class Orientation
    {
        NORTH,
        SOUTH
    } facing;

    Player();
    Player(int xCenter, int yCenter, int cannonAngle, ColorType ct, Orientation initFacing = Orientation::NORTH);
    Player(ofPoint playerPos, int cannonAngle, ColorType ct, Orientation initFacing = Orientation::NORTH);

    void setRotationSpeed(int rs);
    int getRotationSpeed();
    void setRadius(int r);
    int getRadius();
    void setAltColor(ofColor ac);
    ofColor getAltColor();
    void setCannonLength(int cl);
    int getCannonLength();
    void setCannonWidth(int cw);
    int getCannonWidth();
    void setCannonAngle(int ca);
    int getCannonAngle();
    [[deprecated]] void setCanyonLength(int cl);
    [[deprecated]] int getCanyonLength();
    [[deprecated]] void setCanyonWidth(int cw);
    [[deprecated]] int getCanyonWidth();
    [[deprecated]] void setCanyonAngle(int ca);
    [[deprecated]] int getCanyonAngle();

    virtual void draw() override;
    virtual void update() override;
    void moveLeft();
    void moveRight();
    virtual vector<ofRectangle> getEnclosingRectangleList() override;
    Bullet *shoot();
};
