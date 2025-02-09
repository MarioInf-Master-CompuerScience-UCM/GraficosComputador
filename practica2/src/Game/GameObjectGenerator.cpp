
#include "GameObjectGenerator.h"
#include "Game.h"
#include "Road.h"
#include "Wall.h"
#include "Goal.h"
#include "Coin.h"
#include "Obstacle.h"
#include "Barrier.h"
#include "Pedestrian.h"
#include "Offroad.h"
#include "Crosswalk.h"
#include "SlipperySpot.h"
#include "CoinArch.h"
#include "Pit.h"
#include "Bombardier.h"
#include "Crane.h"
#include "Boost.h"

GameObjectGenerator::GameObjectGenerator(Game *game): game(game){}

void GameObjectGenerator::generateWorld(){
    int W = game->ROAD_WIDTH;
    int L = game->ROAD_LENGTH;
    
	Road * road;
	glm::vec3 roadPos;

	int ROAD_MAX_LENGTH = 7000;
	int roadSections = L / ROAD_MAX_LENGTH;
	for (int i = 0; i < roadSections; i++) {
		//glm::vec3 roadPos(0, -50, L/2 - 1000);
		glm::vec3 roadPos(0, -50, i * ROAD_MAX_LENGTH);
		road = new Road(game, roadPos, glm::vec3(W, 0, ROAD_MAX_LENGTH));
		game->addGameObject(road);
	}

	roadPos = glm::vec3(0, -50, L/2 - 1000);

	//auto offroad = new Offroad(game, glm::vec3(0, -49, 4000), glm::vec3(W, 0, 1000));
	//game->addGameObject(offroad);

	//auto oilSpot = new SlipperySpot(game, glm::vec3(0, -49, 6000), glm::vec3(W/2, 0, 1000));
	//game->addGameObject(oilSpot);

	//auto pit = new Pit(game, glm::vec3(0, -49, 8000), glm::vec3(W / 4, 0, W / 4));
	//game->addGameObject(pit);

	//auto boost1 = new Boost(game, glm::vec3(-500, -49, 500), glm::vec3(400, 0, 200), 0.5);
	//game->addGameObject(boost1);

	//auto boost2 = new Boost(game, glm::vec3(500, -49, 500), glm::vec3(400, 0, 200), -1);
	//game->addGameObject(boost2);

    int wallSize = 100;
    
//     WALL with parts
//    for(int l = 0; l < L; l += wallSize){
//        auto wall_r = new Wall(game,
//                        glm::vec3(-W/2, roadPos.y, l - 1000 + wallSize/2),
//                        glm::vec3(wallSize));
//
//        wall_r->isFixed = true;
//        game->addGameObject(wall_r);
//
//    }
    
    
    auto wall_r = new Wall(game, glm::vec3(-W/2, roadPos.y, roadPos.z), glm::vec3(wallSize, wallSize, L));
    game->addGameObject(wall_r);


    wall_r = new Wall(game, glm::vec3(-W/2, roadPos.y, roadPos.z - L * 0.8), glm::vec3(wallSize, wallSize, L));
    game->addGameObject(wall_r);


    auto wall_l = new Wall(game, glm::vec3(W/2, roadPos.y, roadPos.z), glm::vec3(wallSize, wallSize, L));
    game->addGameObject(wall_l);


    wall_l = new Wall(game, glm::vec3(W/2, roadPos.y, roadPos.z - L * 0.8), glm::vec3(wallSize, wallSize, L));
    game->addGameObject(wall_l);


    auto goal = new Goal(game, glm::vec3(0, roadPos.y, roadPos.z + L/2), glm::vec3(W, 100, 100));
    goal->isFixed = true;
    game->addGameObject(goal);

	//auto coinArch = new CoinArch(game, glm::vec3(0, roadPos.y, 5000), glm::vec3(W/2, 100, 100));
	//game->addGameObject(coinArch);
 //   

 //   auto coin = new Coin(game, glm::vec3(0, -25, 500), glm::vec3(50));
 //   game->addGameObject(coin);


	//auto obstacle = new Obstacle(game, glm::vec3(0, -25, 1000), glm::vec3(100));
	//game->addGameObject(obstacle);


	//auto barrier = new Barrier(game, glm::vec3(0, -25, 1300), glm::vec3(300, 100, 100));
	//game->addGameObject(barrier);
 //   

	//auto crosswalk = new Crosswalk(game, glm::vec3(0, -48, 1300), glm::vec3(W, 0, 500));
	//game->addGameObject(crosswalk);


	//auto crane = new Crane(game, glm::vec3(game->ROAD_WIDTH/2 + 120, 0, 200), glm::vec3(100, 100, 100));
	//game->addGameObject(crane);


	//auto bombardier = new Bombardier(game, glm::vec3(0, 300, 2000), glm::vec3(100, 50, 200));
	//game->addGameObject(bombardier


	auto w_thirds = W / 3;
	int pos = 2000;
	// 3-way - boost / coins / antiboost
	for (int i = 0; i < 4; i++) {
		auto obstacle = new Obstacle(game, glm::vec3(w_thirds / 3, -25, pos + 150 * i), glm::vec3(100));
		game->addGameObject(obstacle);
	} 

	for (int i = 0; i < 4; i++) {
		auto obstacle = new Obstacle(game, glm::vec3( - w_thirds / 3, -25, pos + 150 * i), glm::vec3(100));
		game->addGameObject(obstacle);
	}

	for (int i = 0; i < 3; i++) {
		auto coin = new Coin(game, glm::vec3(0, -25, pos + 100 * i), glm::vec3(50));
		game->addGameObject(coin);
	}

	auto boost = new Boost(game, glm::vec3(w_thirds/2 - W / 2, -49, pos + 200), glm::vec3(w_thirds * 0.8, 0, 200), 0.5);
	game->addGameObject(boost);

	boost = new Boost(game, glm::vec3(w_thirds / 2 - W / 2, -49, pos + 500), glm::vec3(w_thirds * 0.8, 0, 200), 0.5);
	game->addGameObject(boost);

	auto antiboost = new Boost(game, glm::vec3(w_thirds, -49, pos + 200), glm::vec3(w_thirds * 0.8, 0, 200), -0.5);
	game->addGameObject(antiboost);

	antiboost = new Boost(game, glm::vec3(w_thirds, -49, pos + 500), glm::vec3(w_thirds * 0.8, 0, 200), -0.5);
	game->addGameObject(antiboost);


	pos += 2000;
	// lots of coins
	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 3; i++) {
			auto coin = new Coin(game, glm::vec3(j * w_thirds / 2 - w_thirds, -25, pos + 100 * i), glm::vec3(50));
			game->addGameObject(coin);
		}
	}


	pos += 2000;
	// cranes and construction
	auto crane = new Crane(game, glm::vec3(game->ROAD_WIDTH/2 + 120, 0, pos), glm::vec3(300, 100, 300));
	game->addGameObject(crane);

	auto barrier = new Barrier(game, glm::vec3(- w_thirds, -25, pos + 100), glm::vec3(300, 100, 100));
	game->addGameObject(barrier);

	barrier = new Barrier(game, glm::vec3(w_thirds, -25, pos + 300), glm::vec3(300, 100, 100));
	game->addGameObject(barrier);

	auto offroad = new Offroad(game, glm::vec3(0, -49, pos), glm::vec3(W, 0, 1000));
	game->addGameObject(offroad);

	auto obstacle = new Obstacle(game, glm::vec3(w_thirds / 3, -25, pos + 600), glm::vec3(100));
	game->addGameObject(obstacle);

	obstacle = new Obstacle(game, glm::vec3(-w_thirds / 3, -25, pos + 600), glm::vec3(100));
	game->addGameObject(obstacle);


	pos += 3000;
	// crosswalks
	auto crosswalk = new Crosswalk(game, glm::vec3(0, -48, pos), glm::vec3(W, 0, 500));
	game->addGameObject(crosswalk);

	crosswalk = new Crosswalk(game, glm::vec3(0, -48, pos + 1500), glm::vec3(W, 0, 500));
	game->addGameObject(crosswalk);

	obstacle = new Obstacle(game, glm::vec3(w_thirds / 3, -25, pos + 750), glm::vec3(100));
	game->addGameObject(obstacle);

	obstacle = new Obstacle(game, glm::vec3(-w_thirds / 3, -25, pos + 750), glm::vec3(100));
	game->addGameObject(obstacle);


	pos += 4000;
	// random coinarchs
	auto coinArch = new CoinArch(game, glm::vec3(-w_thirds, roadPos.y, pos), glm::vec3(W/6, 100, 100));
	game->addGameObject(coinArch);

	coinArch = new CoinArch(game, glm::vec3(w_thirds, roadPos.y, pos), glm::vec3(W / 6, 100, 100));
	game->addGameObject(coinArch);

	coinArch = new CoinArch(game, glm::vec3(0, roadPos.y, pos + 600), glm::vec3(W / 6, 100, 100));
	game->addGameObject(coinArch);

	auto bombardier = new Bombardier(game, glm::vec3(0, 400, pos + 1000), glm::vec3(100, 50, 200));
	game->addGameObject(bombardier);


	pos += 2000;
	// 3-way - boost / coins / antiboost
	for (int i = 0; i < 4; i++) {
		auto obstacle = new Obstacle(game, glm::vec3(w_thirds / 3, -25, pos + 150 * i), glm::vec3(100));
		game->addGameObject(obstacle);
	}

	for (int i = 0; i < 4; i++) {
		auto obstacle = new Obstacle(game, glm::vec3(-w_thirds / 3, -25, pos + 150 * i), glm::vec3(100));
		game->addGameObject(obstacle);
	}

	for (int i = 0; i < 3; i++) {
		auto coin = new Coin(game, glm::vec3(0, -25, pos + 100 * i), glm::vec3(50));
		game->addGameObject(coin);
	}

	boost = new Boost(game, glm::vec3(w_thirds / 2 - W / 2, -49, pos + 200), glm::vec3(w_thirds * 0.8, 0, 200), 1);
	game->addGameObject(boost);

	boost = new Boost(game, glm::vec3(w_thirds / 2 - W / 2, -49, pos + 500), glm::vec3(w_thirds * 0.8, 0, 200), 1);
	game->addGameObject(boost);

	antiboost = new Boost(game, glm::vec3(w_thirds, -49, pos + 200), glm::vec3(w_thirds * 0.8, 0, 200), -0.5);
	game->addGameObject(antiboost);

	antiboost = new Boost(game, glm::vec3(w_thirds, -49, pos + 500), glm::vec3(w_thirds * 0.8, 0, 200), -0.5);
	game->addGameObject(antiboost);


	pos += 2000;
	// bombardiers!
	bombardier = new Bombardier(game, glm::vec3(0, 400, pos), glm::vec3(100, 50, 200));
	game->addGameObject(bombardier);


	pos += 1000;
	// foso
	auto pit = new Pit(game, glm::vec3(0, -49, pos), glm::vec3(W / 4, 0, W / 4));
	game->addGameObject(pit);

	auto oilSpot = new SlipperySpot(game, glm::vec3(- 500, -49, pos + 2000), glm::vec3(W/2, 0, 1000));
	game->addGameObject(oilSpot);

	oilSpot = new SlipperySpot(game, glm::vec3(500, -49, pos + 2000), glm::vec3(W / 2, 0, 1000));
	game->addGameObject(oilSpot);


}
