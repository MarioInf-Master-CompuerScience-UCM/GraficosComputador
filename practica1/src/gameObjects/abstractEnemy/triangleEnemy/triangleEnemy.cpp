#include "triangleEnemy.h"

// Setup function
//*****************************************************
void TriangleEnemy::setup(){}

// Draw function
//*****************************************************
void TriangleEnemy::draw()
{
    ofSetColor(this->getMainColor());
    ofFill();

    ofPushMatrix();
        ofTranslate(this->getPosX(), this->getPosY());
        ofDrawTriangle(0, 0, this->height, -this->height/2, this->height, this->height/2);
    ofPopMatrix();

    return;
}

// Update function
//*****************************************************
void TriangleEnemy::update()
{
    AbstractEnemy::update();
    return;
}

vector<ofRectangle> TriangleEnemy::getEnclosingRectangleList() {
    vector<ofRectangle> l;
    ofRectangle box = ofRectangle(this->getRefPointX(), this->getRefPointY(),
                                  this->getLongSide(), this->getLongSide());
    l.insert(l.begin(), box);
    return l;
}


//*****************************************************
// ACCESS FUNCTIONS TO PRIVATE ATRIBUTES
//*****************************************************
long TriangleEnemy::getLongSide()
{
    return this->height;
}

void TriangleEnemy::setLongSide(long value)
{
    this->height = value;
    return;
}
