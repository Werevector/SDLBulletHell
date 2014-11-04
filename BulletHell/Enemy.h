#pragma once
#include <vector>
#include "SDL.h"
#include "Graphics.h"
#include "Bullet.h"

class Enemy{

protected:

	static const int HITBOX_SIZE = 20;

	int healthPoints;

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

	float firingAngle;
	
	void EnemyMove(float deltaTime);

	float CalcFiringAngle(float,float);

	virtual void Shoot(std::vector<Bullet*>&, GameTimer&);

public:
	
	float whenToSpawn;

	Enemy(int, int, float, float, float);
	
	virtual void Draw();
	virtual void Update(std::vector<Bullet*>&, GameTimer);
	
	

	int GetEnemyCenterX();
	int GetEnemyCenterY();
	
	void Despawn();
	void Spawn(float);

	int GetHealth();
	void Damage(int);
	bool IsDead();

};