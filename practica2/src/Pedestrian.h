
#ifndef Person_h
#define Person_h

#include "GameObject.h"

class Pedestrian : public GameObject{
    float speed = -5;
    bool bTurned;
public:
    Pedestrian(Game *game, glm::vec3 pos, glm::vec3 dim);
    ~Pedestrian();
    
    void update() override;
    void draw() override;
    void receiveCarCollision(Player *car) override;
    void receiveBulletCollision(GameObject *bullet) override;
    
    void checkCollisions() override;
    void turn();
};


#endif /* Person_h */
