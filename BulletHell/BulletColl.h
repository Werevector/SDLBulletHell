#pragma once
#include "Bullet.h"
#include <vector>

class BulletColl{

private:
	
	std::vector<Bullet*> bulletVectors;

public:

	std::vector<Bullet*> GetBulletsAsVector();
	std::vector<Bullet*>& GetBulletsAsPointer();
	void addBullet(Bullet);

};