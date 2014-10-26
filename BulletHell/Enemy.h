#pragma once
#include <vector>
#include "SDL.h"
#include "Graphics.h"

class Enemy{

private:

	bool isSpawned;

	int spawnPosX;
	int spawnPosY;

	//Velocity
	float eVelocX;
	float eVelocY;

	int EnemyPosX;
	int EnemyPosY;

	void enemyMove(float deltaTime);

	std::vector<int> calcPath();

	SDL_Rect eHitBox;
	int boxW;
	int boxH;

	void renderEnemy();
	
	void despawn();
	

public:

	float spawnTimeSec;
	Enemy(int, int, float, float, float);
	void draw();
	void update(float deltaTime);
	void spawn();

};