#ifndef Road_h
#define Road_h

#include "GameObject.h"

class Road : public GameObject{
    
    ofLight light;
    ofPlanePrimitive plane;
public:
    Road(Game *game, glm::vec3 pos, glm::vec3 dim);
    ~Road();
    
    void draw() override;
    void drawDebug() override;

	void receiveCarCollision(Player *car) override;
	void receiveBombCollision(Bomb *bomb) override;

};

#endif /* Road_h */
