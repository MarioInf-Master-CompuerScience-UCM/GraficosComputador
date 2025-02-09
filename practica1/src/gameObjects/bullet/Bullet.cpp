#include "Bullet.h"
#include "ofMain.h"

Bullet::Bullet(ofPoint initialPos, float speedX, float speedY) {
    this->setRefPointX(initialPos.x);
    this->setRefPointY(initialPos.y);
    this->floatPosX = initialPos.x;
    this->floatPosY = initialPos.y;
    this->setSpeedX(speedX);
    this->setSpeedY(speedY);

	// cout << "Bullet ID: " << this->getId() << "\n";
	// cout << "xCenter, yCenter: " << this->getRefPointX()<< ", " << this->getRefPointY() << "\n";
	// cout << "Color r, g, b: " << this->getColor().r << ", " << this->getColor().g << ", " << this->getColor().b << "\n";
    // cout << "Speed x, y: " << this->getSpeedX() << ", " << this->getSpeedY() << "\n";
}

void Bullet::setSpeedX(float sx) {
    this->speedX = sx;
}

float Bullet::getSpeedX() {
    return this->speedX;
};

void Bullet::setSpeedY(float sy) {
    this->speedY = sy;
}

float Bullet::getSpeedY() {
    return this->speedY;
};

void Bullet::update() {
    this->floatPosX += this->speedX;
    this->floatPosY += this->speedY;

    this->setRefPointX((int) this->floatPosX);
    this->setRefPointY((int) this->floatPosY);
}

ofColor Bullet::getMainColor() {
    ofColor mc = GameObject::getMainColor();
    mc.setBrightness(mc.getBrightness() * 0.8);
    return mc;
}

void Bullet::draw() {
	ofPushMatrix();
	ofTranslate(this->getRefPointX(), this->getRefPointY(), 0);

	ofSetColor(this->getMainColor());
	ofFill();
    // Please keep in mind that drawing circle with different outline color and fill
    // requires calling ofNoFill and ofSetColor for drawing stroke and ofFill and
    // again ofSetColor for filled solid color circle.
    ofDrawCircle(0, 0 , this->radius);
	ofPopMatrix();
}

vector<ofRectangle> Bullet::getEnclosingRectangleList() {
    vector<ofRectangle> l;
    ofRectangle box = ofRectangle(this->getRefPointX() - this->radius, this->getRefPointY() - this->radius,
                                  this->radius * 2, this->radius * 2);
    l.insert(l.begin(), box);
    return l;
}
