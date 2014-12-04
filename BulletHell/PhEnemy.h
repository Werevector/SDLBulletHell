#pragma once
#include "Enemy.h"
#include "Player.h"
#include "YSpeedBullet.h"

class PhEnemy : public Enemy{

public:

	PhEnemy(int x ,int y, float vX, float vY , float spawnTime);

	void Update(std::vector<Bullet*>& bulletVectors, Player& player, GameTimer eTime);

protected:

	void Shoot(std::vector<Bullet*>&, GameTimer&);

	float CalcFiringAngle(float X,float Y);

};