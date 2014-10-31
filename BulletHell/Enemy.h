#pragma once
#include <vector>
#include "SDL.h"
#include "Graphics.h"
#include "Bullet.h"

class Enemy{

private:

	static const int HITBOX_SIZE = 10;

	bool isSpawned;

	float spawnTime;
	float passedTime;

	//Position
	int enemyPosX;
	int enemyPosY;

	//Velocity
	float eVelocX;
	float eVelocY;

	//Hitbox
	SDL_Rect eHitBox;
	int boxW;
	int boxH;
	
	void EnemyMove(float deltaTime);

public:
	
	float whenToSpawn;

	Enemy(int, int, float, float, float);
	
	void Draw();
	void Update(GameTimer);
	
	void Shoot(std::vector<Bullet>&, Player&, GameTimer&);

	int GetEnemyCenterX();
	int GetEnemyCenterY();
	
	void Despawn();
	void Spawn(float);

};