#include "GameObject.h"
#include "Bomb.h"

class Bombardier :
	public GameObject
{

	float speed = -5;
	bool bTurned;
	bool bReleasedBomb = false;

	int bombs = 0;

public:
	Bombardier(Game *game, glm::vec3 pos, glm::vec3 dim);
	~Bombardier();

	void update() override;
	void draw() override;

	void turn();
	
	void releaseBomb();
};

