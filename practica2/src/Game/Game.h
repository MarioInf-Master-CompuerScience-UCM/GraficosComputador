#ifndef Game_h
#define Game_h

#include "ofMain.h"
#include "StateMachine.h"
#include "GameObjectContainer.h"
#include "GameObjectGenerator.h"

class Player;

class Game : public StateMachine{


    ofEasyCam cam;
    Player *player;
    GameObjectContainer *gameObjects = nullptr;
    GameObjectGenerator *generator  = nullptr;
    bool bDebug;
    bool bPlayerFinish;
    float initTime;
	float lastPauseTime;
	float pauseTime;
    
    ofSoundPlayer scream;
	ofSoundPlayer coin;
	ofSoundPlayer shoot;
	ofSoundPlayer coinLoss;
	ofSoundPlayer bgs;
	ofSoundPlayer dash;

    
public:
    int ROAD_LENGTH;
    int ROAD_WIDTH;
    
    Game();
    ~Game();
    void init();
    void update();
    void draw();
    void finishGame();
    void toggleDebug();
    bool isFinished();
    void setFinished(bool v);

	void pause();
	void exitPause();
    
    Player *getPlayer();
    vector<GameObject *> getCollisions(GameObject *gameObject);
    void addGameObject(GameObject *gameobject);
    
    float getEllapsedTime();
    void doScream();
	void coinCollect();
	void coinLossSFX();
	void shootSFX();
	void dashSFX();
    
};
#endif
