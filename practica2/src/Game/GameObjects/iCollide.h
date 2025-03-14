#ifndef iColllide_h
#define iColllide_h

#include "ofMain.h"
#include "BoxCollider.h"

class Player;
class Pedestrian;
class Bomb;

class iCollide{
    
    protected:
        BoxCollider *collider;

    public:
    
    virtual void receiveCarCollision(Player *car) {};
    virtual void receiveBulletCollision(GameObject *bullet) {};
    virtual void receivePedestrianCollision(Pedestrian *pedestrian) {};
	virtual void receiveBombCollision(Bomb *bomb) {};
	virtual void receiveExplosionWaveCollision(Bomb *bomb) {};
        
    BoxCollider* getCollider(){
        return collider;
    }
        
    bool collide(iCollide *other){
        return collider->collide(other->getCollider());
    }
};

#endif /* iColllide_h */
