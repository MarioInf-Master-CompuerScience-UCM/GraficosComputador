#ifndef Player_h
#define Player_h

#include "ofMain.h"
#include "GameObject.h"
class Game;

// TODO add speed settings
#define MAX_SPEED 60

class Player : public GameObject{
    
    ofLight faro;
    float speed;
	float roadAccel;
    bool bLight;
    glm::vec3 prevPos;
    int coins;
    
public:
    
    Player(Game *game);
    ~Player();
    
    void init();
    void update() override;
    void draw() override;
    void drawDebug() override;
    void checkCollisions() override;
	void receiveBombCollision(Bomb *bomb) override;
	void receiveExplosionWaveCollision(Bomb *bomb) override;

    float getSpeed();
    
	void setPosition(glm::vec3 pos);
    void steerLeft();
    void steerRight();
    void accelerate();
    void toggleLight();
    void shoot();
    void brake();
	void crouch();
	void dash();
	void surfaceSlowDown(float surf);
    void stop();
    void addCoins(int n = 1);
    int getCoins();
};

#endif 
