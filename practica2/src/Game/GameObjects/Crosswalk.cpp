#include "Crosswalk.h"
#include "Game.h"


Crosswalk::Crosswalk(Game *game, glm::vec3 pos) : 
	GameObject(game, pos) {

}

Crosswalk::Crosswalk(Game *game, glm::vec3 pos, glm::vec3 dim) : 
	GameObject(game, pos, dim) {

	ofDisableArbTex();
	ofLoadImage(texture, "crosswalkTexture.png");
	ofEnableArbTex();
}

Crosswalk::~Crosswalk() {

}


void Crosswalk::update() {

	if (pedestrian == nullptr) {
		pedestrian = new Pedestrian(game,	glm::vec3(transform.getGlobalPosition().x + (game->ROAD_WIDTH / 2 - 100), 
													transform.getGlobalPosition().y + 25,
													transform.getGlobalPosition().z),
											glm::vec3(50, 150, 50));
		game->addGameObject(pedestrian);
	}

}

void Crosswalk::draw() {
	
		texture.bind();
		{
			collider->draw();
		}
		texture.unbind();

}