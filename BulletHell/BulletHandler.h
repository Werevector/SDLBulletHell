#pragma once
#include "BulletColl.h"

class BulletHandler{

private:

	BulletColl bColl;

public:

	BulletHandler();
	void RenderBullets();
	void UpdateBullets(GameTimer&);
	void AddShotBullet(Bullet);
	std::vector<Bullet*>& GetBulletPointers();

};