#pragma once
#include "Enemy.h"
#include "YSpeedBullet.h"
#include "Bullet.h"

class SpiralEnemy : public Enemy{

public:

	SpiralEnemy(int,int,float,float,float);
	
	//void Draw();
	void Update(std::vector<Bullet*>&, Player& player, GameTimer);

protected:

	void Shoot(std::vector<Bullet*>&, GameTimer&);


};