#include "gameObject.h"

// Las variables estáticas deben definirse fuera de la
// declaración de la clase e ir precedidas por el nombre
// de la clase
ofColor GameObject::mainColor1, GameObject::mainColor2;

// Setup function
//*****************************************************
void GameObject::setup()
{
    return;
}

// Draw function
//*****************************************************
void GameObject::draw()
{
    return;
}

// Update function
//*****************************************************
void GameObject::update()
{
    return;
}

vector<ofRectangle> GameObject::getEnclosingRectangleList() {
    vector<ofRectangle> l;
    ofRectangle box = ofRectangle(this->getRefPointX(), this->getRefPointY(), 1, 1);
    l.insert(l.begin(), box);
    return l;
}


//*****************************************************
// ACCESS FUNCTIONS TO PRIVATE ATRIBUTES
//*****************************************************
string GameObject::getId()
{
    return this->id;
}

void GameObject::setId(string value)
{
    this->id = value;
    return;
}

void GameObject::setRefPoint(ofPoint rp)
{
    this->refPoint = rp;
}

void GameObject::setRefPointX(int x)
{
    this->refPoint.x = x;
}

void GameObject::setRefPointY(int y)
{
    this->refPoint.y = y;
}

ofPoint GameObject::getRefPoint()
{
    return this->refPoint;
}

int GameObject::getRefPointX()
{
    return this->refPoint.x;
}

int GameObject::getRefPointY()
{
    return this->refPoint.y;
}

GameObject::ColorType GameObject::getColorType()
{
    return this->color;
}

void GameObject::setColorType(ColorType value)
{
    this->color = value;
    return;
}

void GameObject::setMainColor(GameObject::ColorType ct, int r, int g, int b)
{
    setMainColor(ct, ofColor(r % 256, g % 256, b % 256));
    return;
}

void GameObject::setMainColor(GameObject::ColorType ct, ofColor ofc)
{
    if (ct == ColorType::Color1)
    {
        GameObject::mainColor1 = ofc;
    }
    else
    {
        GameObject::mainColor2 = ofc;
    }
    return;
}

ofColor GameObject::getMainColor()
{
    return (this->color == ColorType::Color1) ? GameObject::mainColor1 : GameObject::mainColor2;
}

bool GameObject::collidesWith(GameObject go)
{
    vector<ofRectangle> me, other;
    me = this->getEnclosingRectangleList();
    other = go.getEnclosingRectangleList();

    bool result = false;
    for (auto r : me)
    {
        for (auto s : other)
        {
            result = (r.getLeft() < s.getRight() && r.getRight() > s.getLeft() &&
                      r.getTop() < s.getBottom() && r.getBottom() > s.getTop());
            if (result)
            {
                break;
            }
        }
        if (result)
        {
            break;
        }
    }
    return result;
}
