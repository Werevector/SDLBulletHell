#pragma once
#include <vector>
#include "Bullet.h"

class BulletHandler{

private:


public:

	std::vector<Bullet*> bulletVector;

	BulletHandler();
	void RenderBullets();
	void UpdateBullets(GameTimer&);
	void AddShotBullet(Bullet);
	std::vector<Bullet*>& GetBulletPointers();

};